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
ParameterComponent::ParameterComponent (ScsynthclientAudioProcessor& processor, int index)
    : processor(processor),
      appData(processor.appData)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    text_param_name.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_param_name.get());
    text_param_name->setTooltip (TRANS("Argument name"));
    text_param_name->setMultiLine (false);
    text_param_name->setReturnKeyStartsNewLine (false);
    text_param_name->setReadOnly (false);
    text_param_name->setScrollbarsShown (true);
    text_param_name->setCaretVisible (true);
    text_param_name->setPopupMenuEnabled (true);
    text_param_name->setText (juce::String());

    text_param_name->setBounds (0, 0, 128, 24);

    text_param_min.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_param_min.get());
    text_param_min->setTooltip (TRANS("Min value range"));
    text_param_min->setMultiLine (false);
    text_param_min->setReturnKeyStartsNewLine (false);
    text_param_min->setReadOnly (false);
    text_param_min->setScrollbarsShown (true);
    text_param_min->setCaretVisible (true);
    text_param_min->setPopupMenuEnabled (true);
    text_param_min->setText (TRANS("0.0"));

    text_param_min->setBounds (136, 0, 80, 24);

    text_param_max.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_param_max.get());
    text_param_max->setTooltip (TRANS("Max value range"));
    text_param_max->setMultiLine (false);
    text_param_max->setReturnKeyStartsNewLine (false);
    text_param_max->setReadOnly (false);
    text_param_max->setScrollbarsShown (true);
    text_param_max->setCaretVisible (true);
    text_param_max->setPopupMenuEnabled (true);
    text_param_max->setText (TRANS("1.0"));

    text_param_max->setBounds (224, 0, 80, 24);

    slider_param_value.reset (new juce::Slider (juce::String()));
    addAndMakeVisible (slider_param_value.get());
    slider_param_value->setRange (0, 10, 0);
    slider_param_value->setSliderStyle (juce::Slider::LinearHorizontal);
    slider_param_value->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);

    slider_param_value->setBounds (304, 0, 280, 24);


    //[UserPreSize]
    this->index = index;
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    LookAndFeel::apply(text_param_name.get());
    LookAndFeel::apply(text_param_min.get());
    LookAndFeel::apply(text_param_max.get());
    
    auto& param = appData.params[index];

    text_param_name->setInputRestrictions(32, "01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    text_param_name->onTextChange = [this, &param]()
    {
        param.name = text_param_name->getText().toStdString();
    };

    text_param_min->setInputRestrictions(10, "01234567890.-");
    text_param_min->onTextChange = [this, &param]()
    {
        param.value_min = text_param_min->getText().getFloatValue();
    };

    text_param_max->setInputRestrictions(10, "01234567890.-");
    text_param_max->onTextChange = [this, &param]()
    {
        param.value_max = text_param_max->getText().getFloatValue();
    };

    slider_param_value->onValueChange = [this, &param, index]()
    {
        param.value = slider_param_value->getValue();

        if (appData.onArgumentChanged)
            appData.onArgumentChanged(index);
    };

    auto par_name = "arg" + juce::String(index + 1);
    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.valueTreeState, par_name, *slider_param_value);
    //[/Constructor]
}

ParameterComponent::~ParameterComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    attachment = nullptr;
    //[/Destructor_pre]

    text_param_name = nullptr;
    text_param_min = nullptr;
    text_param_max = nullptr;
    slider_param_value = nullptr;


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
    auto& param = appData.params[index];
    text_param_name->setText(param.name);
    text_param_min->setText(juce::String(param.value_min));
    text_param_max->setText(juce::String(param.value_max));
    slider_param_value->setValue(param.value);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="ScsynthclientAudioProcessor&amp; processor, int index"
                 variableInitialisers="processor(processor)&#10;appData(processor.appData)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 584 24" fill="solid: 8b2aa5" hasStroke="0"/>
  </BACKGROUND>
  <TEXTEDITOR name="" id="20aaa871892307fd" memberName="text_param_name" virtualName=""
              explicitFocusOrder="0" pos="0 0 128 24" tooltip="Argument name"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="" id="126fa62bc3ff7f3a" memberName="text_param_min" virtualName=""
              explicitFocusOrder="0" pos="136 0 80 24" tooltip="Min value range"
              initialText="0.0" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="" id="2e6b0906ac09253b" memberName="text_param_max" virtualName=""
              explicitFocusOrder="0" pos="224 0 80 24" tooltip="Max value range"
              initialText="1.0" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <SLIDER name="" id="b4aeb0742a045c75" memberName="slider_param_value"
          virtualName="" explicitFocusOrder="0" pos="304 0 280 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

