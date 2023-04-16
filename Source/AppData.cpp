#include "AppData.h"

void AppData::getStateInformation(std::unique_ptr<juce::XmlElement>& xml)
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

void AppData::setStateInformation(std::unique_ptr<juce::XmlElement>& xml)
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

bool AppData::hasTempSCD() const
{
    return temp_scd_watch != nullptr;
}

void AppData::createTempSCD()
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
                     AppData* appData = static_cast<AppData*>(userData);
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

void AppData::destroyTempSCD()
{
    if (!hasTempSCD())
        return;

    temp_scd_watch.reset();
    std::remove(temp_scd_path.c_str());
}

void AppData::openTempSCD()
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
