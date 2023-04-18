#include "AppController.h"
#include <regex>
#include "json.hpp"
#include "SynthClient.h"
#include "PluginEditor.h"

bool AppController::initPlugin(ScsynthclientAudioProcessorEditor* editor)
{
    editor->loadFromAppData();
    connectToServer();

    return true;
}

void AppController::connectToServer()
{
    synthClient = std::make_shared<SynthClient>(*this);
}

void AppController::processMidiBuffer(const juce::MidiBuffer& midiMessages)
{
    if (synthClient)
        synthClient->processMidiBuffer(midiMessages);
}

void AppController::getStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    xml->setAttribute("synthdef_name", appData.synthdef_name);
    xml->setAttribute("scsynth_port", appData.scsynth_port);
    xml->setAttribute("sclang_port", appData.sclang_port);
    xml->setAttribute("master_velocity", appData.master_velocity);
    xml->setAttribute("liveargs", appData.liveargs);
    xml->setAttribute("send_on_load", appData.send_on_load);
    xml->setAttribute("code", appData.code);
    xml->setAttribute("pitchbend_range", appData.pitchbend_range);

    for (int i = 0; i < 8; i++)
    {
        auto& p = appData.params[i];
        const auto n = juce::String("arg") + std::to_string(i + 1);

        xml->setAttribute(n + "_name", p.name);
        xml->setAttribute(n + "_value_min", p.value_min);
        xml->setAttribute(n + "_value_max", p.value_max);
        xml->setAttribute(n + "_value", p.value);
    }
}

void AppController::setStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    appData.synthdef_name = xml->getStringAttribute("synthdef_name", "Synth1").toStdString();
    appData.scsynth_port = xml->getIntAttribute("scsynth_port", 57110);
    appData.sclang_port = xml->getIntAttribute("sclang_port", 57120);
    appData.master_velocity = xml->getDoubleAttribute("master_velocity", 1);
    appData.liveargs = xml->getBoolAttribute("liveargs", true);
    appData.send_on_load = xml->getBoolAttribute("send_on_load", true);
    appData.code = xml->getStringAttribute("code", "").toStdString();
    appData.pitchbend_range = xml->getIntAttribute("pitchbend_range", 48);

    for (int i = 0; i < 8; i++)
    {
        auto& p = appData.params[i];
        const auto n = std::string("arg") + std::to_string(i + 1);

        p.name = xml->getStringAttribute(n + "_name", "").toStdString();
        p.value_min = xml->getDoubleAttribute(n + "_value_min", 0);
        p.value_max = xml->getDoubleAttribute(n + "_value_max", 1);
        p.value = xml->getDoubleAttribute(n + "_value", 0);
    }
}

//////////////////////////////////////////////////////////////////////////

void AppController::loadSCD(const std::string& scd)
{
    appData.code = scd;

    std::string meta_json_str;

    // Parse metadata block
    {
        std::regex re(R"(\/\*(\{[\s\S]*\})\*\/)");
        std::smatch m;
        if (std::regex_search(appData.code, m, re))
        {
            if (m.size() == 2)
            {
                meta_json_str = m[1].str();
            }
        }
    }

    // Load metadata json
    {
        using json = nlohmann::json;
        json meta_json = json::parse(meta_json_str);

        // Load synthdef name
        appData.synthdef_name = meta_json["name"].get<std::string>();

        // TODO: Load arguments
    }
}

//////////////////////////////////////////////////////////////////////////

bool AppController::hasTempSCD() const
{
    return temp_scd_watch != nullptr;
}

void AppController::createTempSCD()
{
    std::string name = std::tmpnam(nullptr);
    name += "_" + appData.synthdef_name + ".scd";
    temp_scd_path = name;

    {
        std::ofstream ofs(name.c_str());
        ofs << appData.code;
    }

    temp_scd_watch = std::make_unique<filewatch::FileWatch<std::string>>
    (name,
     [this](const std::string& _, filewatch::Event change_type)
     {
         if (change_type == filewatch::Event::modified)
         {
             std::ifstream ifs(temp_scd_path.c_str());
             std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
             appData.code = str;

             struct Callback
             {
                 static void* callback(void* userData)
                 {
                     AppController* appData = static_cast<AppController*>(userData);
                     if (appData->onTempSCDModified)
                         appData->onTempSCDModified();

                     return nullptr;
                 }
             };
             
             juce::MessageManager* mm = juce::MessageManager::getInstance();
             mm->callFunctionOnMessageThread(Callback::callback, this);
         }
     });
}

void AppController::destroyTempSCD()
{
    if (!hasTempSCD())
        return;

    temp_scd_watch.reset();
    std::remove(temp_scd_path.c_str());
}

void AppController::openTempSCD()
{
    if (!hasTempSCD())
        return;

    std::string cmd;

#if WIN32
    cmd = "start " + temp_scd_path;
#elif __APPLE__
    cmd = "open " + temp_scd_path;
#else
    #error
# endif
    
    system(cmd.c_str());
}
