/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "ParameterComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updateClientID(int newid);
    void getStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    void setStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::string synthdef_name = "Synth1";
    int scsynth_port = 57110;
    int sclang_port = 57120;
    int client_id = -1;

    bool autorelease;
    bool liveargs;
    bool send_on_load;

    std::string code;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ToggleButton> btn_autorelease;
    std::unique_ptr<juce::TextButton> btn_testtone;
    std::unique_ptr<juce::TextEditor> text_synthdef_name;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::TextEditor> text_scsynth_port;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::TextEditor> text_sclang_port;
    std::unique_ptr<juce::ToggleButton> btn_liveargs;
    std::unique_ptr<juce::Label> label_client_id;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<ParameterComponent> arg1;
    std::unique_ptr<ParameterComponent> arg2;
    std::unique_ptr<ParameterComponent> arg3;
    std::unique_ptr<ParameterComponent> arg4;
    std::unique_ptr<ParameterComponent> arg5;
    std::unique_ptr<ParameterComponent> arg6;
    std::unique_ptr<ParameterComponent> arg7;
    std::unique_ptr<ParameterComponent> arg8;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::TextEditor> text_code;
    std::unique_ptr<juce::ToggleButton> btn_send_on_load;
    std::unique_ptr<juce::TextButton> btn_send;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

