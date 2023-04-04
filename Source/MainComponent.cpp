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

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__toggleButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (juce__toggleButton.get());
    juce__toggleButton->setButtonText (TRANS("Autorelease"));
    juce__toggleButton->addListener (this);

    juce__toggleButton->setBounds (128, 48, 112, 24);

    juce__textButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton.get());
    juce__textButton->setButtonText (TRANS("Test Tone"));
    juce__textButton->addListener (this);

    juce__textButton->setBounds (16, 48, 96, 24);

    juce__textEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor.get());
    juce__textEditor->setMultiLine (false);
    juce__textEditor->setReturnKeyStartsNewLine (false);
    juce__textEditor->setReadOnly (false);
    juce__textEditor->setScrollbarsShown (true);
    juce__textEditor->setCaretVisible (true);
    juce__textEditor->setPopupMenuEnabled (true);
    juce__textEditor->setText (TRANS("Synth1"));

    juce__textEditor->setBounds (80, 8, 120, 24);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("SynthDef:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (8, 8, 72, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("scsynth:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (208, 8, 63, 24);

    juce__textEditor2.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor2.get());
    juce__textEditor2->setMultiLine (false);
    juce__textEditor2->setReturnKeyStartsNewLine (false);
    juce__textEditor2->setReadOnly (false);
    juce__textEditor2->setScrollbarsShown (false);
    juce__textEditor2->setCaretVisible (true);
    juce__textEditor2->setPopupMenuEnabled (true);
    juce__textEditor2->setText (TRANS("57110"));

    juce__textEditor2->setBounds (272, 8, 48, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("sclang:")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (328, 8, 56, 24);

    juce__textEditor3.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor3.get());
    juce__textEditor3->setMultiLine (false);
    juce__textEditor3->setReturnKeyStartsNewLine (false);
    juce__textEditor3->setReadOnly (false);
    juce__textEditor3->setScrollbarsShown (false);
    juce__textEditor3->setCaretVisible (true);
    juce__textEditor3->setPopupMenuEnabled (true);
    juce__textEditor3->setText (TRANS("57120"));

    juce__textEditor3->setBounds (384, 8, 48, 24);

    juce__toggleButton2.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (juce__toggleButton2.get());
    juce__toggleButton2->setButtonText (TRANS("Live Args"));
    juce__toggleButton2->addListener (this);

    juce__toggleButton2->setBounds (240, 48, 88, 24);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("ClientID: -1")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (440, 8, 88, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__toggleButton = nullptr;
    juce__textButton = nullptr;
    juce__textEditor = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__textEditor2 = nullptr;
    juce__label3 = nullptr;
    juce__textEditor3 = nullptr;
    juce__toggleButton2 = nullptr;
    juce__label4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 0, y = 0, width = 600, height = 400;
        juce::Colour strokeColour = juce::Colours::grey;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__toggleButton.get())
    {
        //[UserButtonCode_juce__toggleButton] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton]
    }
    else if (buttonThatWasClicked == juce__textButton.get())
    {
        //[UserButtonCode_juce__textButton] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton]
    }
    else if (buttonThatWasClicked == juce__toggleButton2.get())
    {
        //[UserButtonCode_juce__toggleButton2] -- add your button handler code here..
        //[/UserButtonCode_juce__toggleButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 600 400" fill="solid: 808080" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff808080"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="b8558110aca6148e" memberName="juce__toggleButton"
                virtualName="" explicitFocusOrder="0" pos="128 48 112 24" buttonText="Autorelease"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="985d3b3152aa2800" memberName="juce__textButton"
              virtualName="" explicitFocusOrder="0" pos="16 48 96 24" buttonText="Test Tone"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="4f37a4b3cc260d15" memberName="juce__textEditor"
              virtualName="" explicitFocusOrder="0" pos="80 8 120 24" initialText="Synth1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="87e96af479401f16" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="8 8 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="SynthDef:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5eb3100c59612fcf" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="208 8 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="scsynth:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="c39ef4a68bff3ab1" memberName="juce__textEditor2"
              virtualName="" explicitFocusOrder="0" pos="272 8 48 24" initialText="57110"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="ab30b1eed95c682" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="328 8 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="sclang:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="4644a9ac46618f5e" memberName="juce__textEditor3"
              virtualName="" explicitFocusOrder="0" pos="384 8 48 24" initialText="57120"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="new toggle button" id="cac3c8de46c4287c" memberName="juce__toggleButton2"
                virtualName="" explicitFocusOrder="0" pos="240 48 88 24" buttonText="Live Args"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="e228f0569f8dd0b3" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="440 8 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ClientID: -1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

