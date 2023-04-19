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
#include "PluginProcessor.h"
#include "LookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ParameterComponent  : public juce::Component
{
public:
    //==============================================================================
    ParameterComponent (juce::AudioProcessorValueTreeState& valueTreeState, AppController& appController, int index);
    ~ParameterComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void loadFromAppData();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AppController& appController;
    std::shared_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attachment;
    int index;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> slider_param_value;
    std::unique_ptr<juce::Label> label_name;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

