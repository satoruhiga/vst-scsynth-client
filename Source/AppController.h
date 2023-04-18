#pragma once

#include <string>
#include <array>
#include <memory>

#include <JuceHeader.h>
#include "FileWatch.hpp"

#define SYNTHNAME_STR "{{SYNTH_NAME}}"

class SynthClient;
class ScsynthclientAudioProcessorEditor;

struct AppController
{
    bool initPlugin(ScsynthclientAudioProcessorEditor* editor);
    
    /////////////////////////////////////////////////
    
    std::shared_ptr<SynthClient> synthClient;
    void connectToServer();
    void processMidiBuffer(const juce::MidiBuffer& midiMessages);

    /////////////////////////////////////////////////
    
    struct Parameter
    {
        std::string name;
        float value_min = 0, value_max = 1;
        float value = 0;
    };

    struct AppData
    {
        std::string synthdef_name = "Synth1";
        int scsynth_port = 57110;
        int sclang_port = 57120;
        int client_id = -1;

        float master_velocity = 1;
        bool liveargs = false;
        bool send_on_load = true;

        int pitchbend_range = 48;

        std::string code;

        std::array<Parameter, 8> params;
    } appData;

    void getStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    void setStateInformation(std::unique_ptr<juce::XmlElement>& xml);

    /////////////////////////////////////////////////
    
    std::function<void()> onClientIDUpdated;
    std::function<void()> onPortChanged;
    std::function<void(const std::string&)> onSendCode;
    std::function<void(bool)> onTestTone;
    std::function<void(int)> onArgumentChanged;
    std::function<void(int)> onPitchbendRangeChanged;

    /////////////////////////////////////////////////
    // scd 
    
    // Load scd string
    void loadSCD(const std::string& scd);

    // External scd file
    std::string temp_scd_path;
    std::unique_ptr<filewatch::FileWatch<std::string>> temp_scd_watch;
    
    std::function<void()> onTempSCDModified;
    
    bool hasTempSCD() const;
    void createTempSCD();
    void destroyTempSCD();
    void openTempSCD();
};
