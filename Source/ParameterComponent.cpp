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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ParameterComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterComponent::ParameterComponent (juce::AudioProcessorValueTreeState& valueTreeState, AppController& appController, int index)
    : appController(appController)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    slider_param_value.reset (new juce::Slider (juce::String()));
    addAndMakeVisible (slider_param_value.get());
    slider_param_value->setRange (0, 10, 0);
    slider_param_value->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    slider_param_value->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    slider_param_value->setBounds (0, 0, 64, 64);

    label_name.reset (new juce::Label (juce::String(),
                                       TRANS("-")));
    addAndMakeVisible (label_name.get());
    label_name->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label_name->setJustificationType (juce::Justification::centred);
    label_name->setEditable (false, false, false);
    label_name->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label_name->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label_name->setBounds (0, 56, 64, 24);


    //[UserPreSize]
    this->index = index;
    //[/UserPreSize]

    setSize (64, 80);


    //[Constructor] You can add your own custom stuff here..
    auto& appData = appController.appData;
    auto& param = appData.params[index];

    slider_param_value->onValueChange = [this, &param, index]()
    {
        param.value = slider_param_value->getValue();

        if (this->appController.onArgumentChanged)
            this->appController.onArgumentChanged(index);
    };

    auto par_name = "arg" + juce::String(index + 1);
    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(valueTreeState, par_name, *slider_param_value);
    //[/Constructor]
}

ParameterComponent::~ParameterComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    attachment = nullptr;
    //[/Destructor_pre]

    slider_param_value = nullptr;
    label_name = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ParameterComponent::loadFromAppData()
{
    auto& appData = appController.appData;
    auto& param = appData.params[index];

    if (!param.name.empty())
    {
        label_name->setText(param.name, juce::dontSendNotification);
        label_name->setColour(juce::Label::textColourId, juce::Colours::white);
        slider_param_value->setEnabled(true);
        slider_param_value->setValue(param.value);
    }
    else
    {
        label_name->setText("-", juce::dontSendNotification);
        label_name->setColour(juce::Label::textColourId, juce::Colours::grey);
        slider_param_value->setEnabled(false);
        slider_param_value->setValue(0);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="juce::AudioProcessorValueTreeState&amp; valueTreeState, AppController&amp; appController, int index"
                 variableInitialisers="appController(appController)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="64" initialHeight="80">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 64 80" fill="solid: 8b2aa5" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="" id="b4aeb0742a045c75" memberName="slider_param_value"
          virtualName="" explicitFocusOrder="0" pos="0 0 64 64" min="0.0"
          max="10.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="" id="8ab37eb5afc949f" memberName="label_name" virtualName=""
         explicitFocusOrder="0" pos="0 56 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="-" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

