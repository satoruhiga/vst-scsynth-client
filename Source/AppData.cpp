#include "AppData.h"

void AppData::getStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    xml->setAttribute("synthdef_name", synthdef_name);
    xml->setAttribute("scsynth_port", scsynth_port);
    xml->setAttribute("sclang_port", sclang_port);
    xml->setAttribute("autorelease", autorelease);
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
    autorelease = xml->getBoolAttribute("autorelease", true);
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
