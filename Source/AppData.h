#pragma once

#include <string>
#include <array>
#include <memory>

#include <JuceHeader.h>

struct AppData
{
    struct Parameter
    {
        std::string name;
        float value_min, value_max;
        float value;
    };
    
    std::string synthdef_name = "Synth1";
    int scsynth_port = 57110;
    int sclang_port = 57120;
    int client_id = -1;

    bool autorelease;
    bool liveargs;
    bool send_on_load;

    std::string code;

    std::array<Parameter, 8> params;

    void getStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    void setStateInformation(std::unique_ptr<juce::XmlElement>& xml);
};
