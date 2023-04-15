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
        float value_min = 0, value_max = 1;
        float value = 0;
    };
    
    std::string synthdef_name = "Synth1";
    int scsynth_port = 57110;
    int sclang_port = 57120;
    int client_id = -1;

    // bool autorelease;
    float master_velocity = 1;
    bool liveargs = false;
    bool send_on_load = true;

    int pitchbend_range = 48;

    std::string code;

    std::array<Parameter, 8> params;

    void getStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    void setStateInformation(std::unique_ptr<juce::XmlElement>& xml);

    std::function<void()> onClientIDUpdated;
    std::function<void()> onPortChanged;
    std::function<void()> onSendCode;
    std::function<void(bool)> onTestTone;
    std::function<void(int)> onArgumentChanged;
    std::function<void(int)> onPitchbendRangeChanged;
};
