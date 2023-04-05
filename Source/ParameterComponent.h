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
    ParameterComponent ();
    ~ParameterComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void getStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    void setStateInformation(std::unique_ptr<juce::XmlElement>& xml);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::string name;
    float value_min, value_max;
    float value;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> text_param_name;
    std::unique_ptr<juce::TextEditor> text_param_min;
    std::unique_ptr<juce::TextEditor> text_param_max;
    std::unique_ptr<juce::Slider> slider_param_value;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

