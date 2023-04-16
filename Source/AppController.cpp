#include "AppController.h"
#include <regex>
#include "json.hpp"

void AppController::getStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    xml->setAttribute("synthdef_name", synthdef_name);
    xml->setAttribute("scsynth_port", scsynth_port);
    xml->setAttribute("sclang_port", sclang_port);
    // xml->setAttribute("autorelease", autorelease);
    xml->setAttribute("master_velocity", master_velocity);
    xml->setAttribute("liveargs", liveargs);
    xml->setAttribute("send_on_load", send_on_load);
    xml->setAttribute("code", code);
    xml->setAttribute("pitchbend_range", pitchbend_range);

    for (int i = 0; i < 8; i++)
    {
        auto& p = params[i];
        const auto n = juce::String("arg") + std::to_string(i + 1);

        xml->setAttribute(n + "_name", p.name);
        xml->setAttribute(n + "_value_min", p.value_min);
        xml->setAttribute(n + "_value_max", p.value_max);
        xml->setAttribute(n + "_value", p.value);
    }
}

void AppController::setStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    synthdef_name = xml->getStringAttribute("synthdef_name", "Synth1").toStdString();
    scsynth_port = xml->getIntAttribute("scsynth_port", 57110);
    sclang_port = xml->getIntAttribute("sclang_port", 57120);
    // autorelease = xml->getBoolAttribute("autorelease", true);
    master_velocity = xml->getDoubleAttribute("master_velocity", 1);
    liveargs = xml->getBoolAttribute("liveargs", true);
    send_on_load = xml->getBoolAttribute("send_on_load", true);
    code = xml->getStringAttribute("code", "").toStdString();
    pitchbend_range = xml->getIntAttribute("pitchbend_range", 48);

    for (int i = 0; i < 8; i++)
    {
        auto& p = params[i];
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
    code = scd;

    std::string meta_json_str;

    {
        std::regex re(R"(\/\*(\{[\s\S]*\})\*\/)");
        std::smatch m;
        if (std::regex_search(code, m, re))
        {
            if (m.size() == 2)
            {
                meta_json_str = m[1].str();
            }
        }
    }

    using json = nlohmann::json;
    json meta_json = json::parse(meta_json_str);

    // Load synthdef name from metadata
    synthdef_name = meta_json["name"].get<std::string>();
}

//////////////////////////////////////////////////////////////////////////

bool AppController::hasTempSCD() const
{
    return temp_scd_watch != nullptr;
}

void AppController::createTempSCD()
{
    std::string name = std::tmpnam(nullptr);
    name += "_" + synthdef_name + ".scd";
    temp_scd_path = name;

    {
        std::ofstream ofs(name.c_str());
        ofs << code;
    }

    temp_scd_watch = std::make_unique<filewatch::FileWatch<std::string>>
    (name,
     [this](const std::string& _, filewatch::Event change_type)
     {
         if (change_type == filewatch::Event::modified)
         {
             std::ifstream ifs(temp_scd_path.c_str());
             std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
             code = str;

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
