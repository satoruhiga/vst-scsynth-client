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
ParameterComponent::ParameterComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    param_name.reset (new juce::TextEditor ("Name"));
    addAndMakeVisible (param_name.get());
    param_name->setMultiLine (false);
    param_name->setReturnKeyStartsNewLine (false);
    param_name->setReadOnly (false);
    param_name->setScrollbarsShown (true);
    param_name->setCaretVisible (true);
    param_name->setPopupMenuEnabled (true);
    param_name->setText (juce::String());

    param_name->setBounds (0, 0, 128, 24);

    param_min.reset (new juce::TextEditor ("Min"));
    addAndMakeVisible (param_min.get());
    param_min->setMultiLine (false);
    param_min->setReturnKeyStartsNewLine (false);
    param_min->setReadOnly (false);
    param_min->setScrollbarsShown (true);
    param_min->setCaretVisible (true);
    param_min->setPopupMenuEnabled (true);
    param_min->setText (TRANS("0.0"));

    param_min->setBounds (136, 0, 80, 24);

    param_max.reset (new juce::TextEditor ("Max"));
    addAndMakeVisible (param_max.get());
    param_max->setMultiLine (false);
    param_max->setReturnKeyStartsNewLine (false);
    param_max->setReadOnly (false);
    param_max->setScrollbarsShown (true);
    param_max->setCaretVisible (true);
    param_max->setPopupMenuEnabled (true);
    param_max->setText (TRANS("1.0"));

    param_max->setBounds (224, 0, 80, 24);

    param_slider.reset (new juce::Slider ("Slider"));
    addAndMakeVisible (param_slider.get());
    param_slider->setRange (0, 10, 0);
    param_slider->setSliderStyle (juce::Slider::LinearHorizontal);
    param_slider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    param_slider->addListener (this);

    param_slider->setBounds (304, 0, 280, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterComponent::~ParameterComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    param_name = nullptr;
    param_min = nullptr;
    param_max = nullptr;
    param_slider = nullptr;


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

void ParameterComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == param_slider.get())
    {
        //[UserSliderCode_param_slider] -- add your slider handling code here..
        //[/UserSliderCode_param_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 584 24" fill="solid: 8b2aa5" hasStroke="0"/>
  </BACKGROUND>
  <TEXTEDITOR name="Name" id="20aaa871892307fd" memberName="param_name" virtualName=""
              explicitFocusOrder="0" pos="0 0 128 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Min" id="126fa62bc3ff7f3a" memberName="param_min" virtualName=""
              explicitFocusOrder="0" pos="136 0 80 24" initialText="0.0" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Max" id="2e6b0906ac09253b" memberName="param_max" virtualName=""
              explicitFocusOrder="0" pos="224 0 80 24" initialText="1.0" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <SLIDER name="Slider" id="b4aeb0742a045c75" memberName="param_slider"
          virtualName="" explicitFocusOrder="0" pos="304 0 280 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

