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
MainComponent::MainComponent (ScsynthclientAudioProcessor& processor)
    : processor(processor),
      appData(processor.appData)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    btn_autorelease.reset (new juce::ToggleButton (juce::String()));
    addAndMakeVisible (btn_autorelease.get());
    btn_autorelease->setButtonText (TRANS("Autorelease"));

    btn_autorelease->setBounds (120, 40, 112, 24);

    btn_testtone.reset (new juce::TextButton (juce::String()));
    addAndMakeVisible (btn_testtone.get());
    btn_testtone->setButtonText (TRANS("Test Tone"));

    btn_testtone->setBounds (8, 40, 96, 24);

    text_synthdef_name.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_synthdef_name.get());
    text_synthdef_name->setMultiLine (false);
    text_synthdef_name->setReturnKeyStartsNewLine (false);
    text_synthdef_name->setReadOnly (false);
    text_synthdef_name->setScrollbarsShown (true);
    text_synthdef_name->setCaretVisible (true);
    text_synthdef_name->setPopupMenuEnabled (true);
    text_synthdef_name->setText (TRANS("Synth1"));

    text_synthdef_name->setBounds (80, 8, 120, 24);

    juce__label.reset (new juce::Label (juce::String(),
                                        TRANS("SynthDef:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (8, 8, 72, 24);

    juce__label2.reset (new juce::Label (juce::String(),
                                         TRANS("scsynth:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (208, 8, 63, 24);

    text_scsynth_port.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_scsynth_port.get());
    text_scsynth_port->setMultiLine (false);
    text_scsynth_port->setReturnKeyStartsNewLine (false);
    text_scsynth_port->setReadOnly (false);
    text_scsynth_port->setScrollbarsShown (false);
    text_scsynth_port->setCaretVisible (true);
    text_scsynth_port->setPopupMenuEnabled (true);
    text_scsynth_port->setText (TRANS("57110"));

    text_scsynth_port->setBounds (272, 8, 48, 24);

    juce__label3.reset (new juce::Label (juce::String(),
                                         TRANS("sclang:")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (328, 8, 56, 24);

    text_sclang_port.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_sclang_port.get());
    text_sclang_port->setMultiLine (false);
    text_sclang_port->setReturnKeyStartsNewLine (false);
    text_sclang_port->setReadOnly (false);
    text_sclang_port->setScrollbarsShown (false);
    text_sclang_port->setCaretVisible (true);
    text_sclang_port->setPopupMenuEnabled (true);
    text_sclang_port->setText (TRANS("57120"));

    text_sclang_port->setBounds (384, 8, 48, 24);

    btn_liveargs.reset (new juce::ToggleButton ("btn_liveargs"));
    addAndMakeVisible (btn_liveargs.get());
    btn_liveargs->setButtonText (TRANS("Live Args"));

    btn_liveargs->setBounds (232, 40, 88, 24);

    label_client_id.reset (new juce::Label (juce::String(),
                                            TRANS("ClientID: -1")));
    addAndMakeVisible (label_client_id.get());
    label_client_id->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label_client_id->setJustificationType (juce::Justification::centredLeft);
    label_client_id->setEditable (false, false, false);
    label_client_id->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label_client_id->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label_client_id->setBounds (504, 8, 88, 24);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("# Arguments")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (8, 72, 150, 24);

    arg1.reset (new ParameterComponent (processor, 0));
    addAndMakeVisible (arg1.get());

    arg1->setBounds (8, 96, 584, 24);

    arg2.reset (new ParameterComponent (processor, 1));
    addAndMakeVisible (arg2.get());

    arg2->setBounds (8, 128, 584, 24);

    arg3.reset (new ParameterComponent (processor, 2));
    addAndMakeVisible (arg3.get());

    arg3->setBounds (8, 160, 584, 24);

    arg4.reset (new ParameterComponent (processor, 3));
    addAndMakeVisible (arg4.get());

    arg4->setBounds (8, 192, 584, 24);

    arg5.reset (new ParameterComponent (processor, 4));
    addAndMakeVisible (arg5.get());

    arg5->setBounds (8, 224, 584, 24);

    arg6.reset (new ParameterComponent (processor, 5));
    addAndMakeVisible (arg6.get());

    arg6->setBounds (8, 256, 584, 24);

    arg7.reset (new ParameterComponent (processor, 6));
    addAndMakeVisible (arg7.get());

    arg7->setBounds (8, 288, 584, 24);

    arg8.reset (new ParameterComponent (processor, 7));
    addAndMakeVisible (arg8.get());

    arg8->setBounds (8, 320, 584, 24);

    juce__label6.reset (new juce::Label (juce::String(),
                                         TRANS("# Code")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (8, 352, 150, 24);

    btn_send_on_load.reset (new juce::ToggleButton (juce::String()));
    addAndMakeVisible (btn_send_on_load.get());
    btn_send_on_load->setButtonText (TRANS("Send on Load"));

    btn_send_on_load->setBounds (312, 584, 112, 24);

    btn_send.reset (new juce::TextButton (juce::String()));
    addAndMakeVisible (btn_send.get());
    btn_send->setButtonText (TRANS("Send"));

    btn_send->setBounds (440, 584, 152, 24);

    juce__label4.reset (new juce::Label (juce::String(),
                                         TRANS("Pitchbend Range:")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (440, 40, 120, 24);

    text_pitchbend_range.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_pitchbend_range.get());
    text_pitchbend_range->setMultiLine (false);
    text_pitchbend_range->setReturnKeyStartsNewLine (false);
    text_pitchbend_range->setReadOnly (false);
    text_pitchbend_range->setScrollbarsShown (false);
    text_pitchbend_range->setCaretVisible (true);
    text_pitchbend_range->setPopupMenuEnabled (true);
    text_pitchbend_range->setText (TRANS("48"));

    text_pitchbend_range->setBounds (560, 40, 32, 24);

    text_code.reset (new CodeEditor());
    addAndMakeVisible (text_code.get());

    text_code->setBounds (8, 376, 584, 200);

    combo_presets.reset (new juce::ComboBox());
    addAndMakeVisible (combo_presets.get());

    combo_presets->setBounds (8, 584, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 616);


    //[Constructor] You can add your own custom stuff here..

    // Synthdef name
    text_synthdef_name->setInputRestrictions(0, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_");
    text_synthdef_name->onTextChange = [this] {
        appData.synthdef_name = text_synthdef_name->getText().toStdString();
    };
    text_synthdef_name->setText(appData.synthdef_name);

    // Ports
    text_scsynth_port->setInputRestrictions(5, "01234567890");
    text_scsynth_port->onReturnKey = [this] {
        int port = text_scsynth_port->getText().getIntValue();
        if (port > 0 && port < 65536) {
            appData.scsynth_port = port;

            if (appData.onPortChanged)
                appData.onPortChanged();
        }
    };
    text_scsynth_port->onFocusLost = text_scsynth_port->onReturnKey;
    text_scsynth_port->setText(juce::String(appData.scsynth_port));

    text_sclang_port->setInputRestrictions(5, "01234567890");
    text_sclang_port->onReturnKey = [this] {
        int port = text_sclang_port->getText().getIntValue();
        if (port > 0 && port < 65536) {
            appData.sclang_port = port;

            if (appData.onPortChanged)
                appData.onPortChanged();
        }
    };
    text_sclang_port->onFocusLost = text_sclang_port->onReturnKey;
    text_sclang_port->setText(juce::String(appData.sclang_port));

    // Pitchbend range
    text_pitchbend_range->setInputRestrictions(2, "01234567890");
    text_pitchbend_range->onReturnKey = [this] {
        int v = text_pitchbend_range->getText().getIntValue();
        if (v > 0 && v < 96)
        {
            appData.pitchbend_range = v;

            if (appData.onPitchbendRangeChanged)
                appData.onPitchbendRangeChanged(v);
        }
    };
    text_pitchbend_range->setText(juce::String(appData.pitchbend_range));

    // Autorelease
    btn_autorelease->onClick = [this] {
        appData.autorelease = btn_autorelease->getToggleState();
    };
    btn_autorelease->setToggleState(appData.autorelease, juce::dontSendNotification);

    // Live args
    btn_liveargs->onClick = [this] {
        appData.liveargs = btn_liveargs->getToggleState();
    };
    btn_liveargs->setToggleState(appData.liveargs, juce::dontSendNotification);

    // Code editor
    text_code->onDocumentChanged = [this] {
        appData.code = text_code->getText();
    };

    text_code->setText(appData.code);
    text_code->onCtrlEnter = [this]
    {
        if (appData.onSendCode)
            appData.onSendCode();
    };

    // Send button
    btn_send->onClick = [this] {
        if (appData.onSendCode)
            appData.onSendCode();
    };
    
    // Send on load
    btn_send_on_load->onClick = [this] {
        appData.send_on_load = btn_send_on_load->getToggleState();
    };
    btn_send_on_load->setToggleState(appData.send_on_load, juce::dontSendNotification);

    if (appData.send_on_load)
    {
        if (appData.onSendCode)
            appData.onSendCode();
    }
    
    // Test tone
    btn_testtone->onStateChange = [this] {
        bool s = btn_testtone->getState() == 2;
        static bool ss = s;

        if (ss != s)
        {
            ss = s;

            if (appData.onTestTone)
            {
                if (ss)
                {
                    appData.onTestTone(true);
                }
                else
                {
                    appData.onTestTone(false);
                }
            }
        }
    };

    // Client ID
    appData.onClientIDUpdated = [this]()
    {
        label_client_id->setText(
            "ClientID: " + juce::String(appData.client_id),
            juce::dontSendNotification);
    };

    label_client_id->setText(
        "ClientID: " + juce::String(appData.client_id),
        juce::dontSendNotification);

    // Preset Combo box
    combo_presets->addItem("Empty", 1);
    combo_presets->addItem("Simple", 2);
    combo_presets->addItem("MPE", 3);

    combo_presets->onChange = [this]
    {
        auto index = combo_presets->getSelectedItemIndex();
        juce::String code;
        
        if (index == 0)
        {
            code = "";
        }
        else if (index == 1)
        {
            code = "SynthDef(\\{SYNTHNAME}, {| freq=440, amp=1, gate=1 |\n"
"\tvar sig = SinOsc.ar(freq);\n"
"\tvar env = EnvGen.kr(Env.adsr(), gate, doneAction: Done.freeSelf);\n"
"\tOut.ar(0, Pan2.ar(sig * env, 0.5, amp));\n"
"}).add;\n";
            
        }
        else if (index == 2)
        {
            code = "SynthDef(\\{SYNTHNAME}, {| freq=440, amp=1, gate=1, pressure=0.5, timbre=0.5, release_vel=0 |\n"
"\tvar sig = SinOsc.ar(freq);\n"
"\tvar env = EnvGen.kr(Env.adsr(), gate, doneAction: Done.freeSelf);\n"
"\tOut.ar(0, Pan2.ar(sig * env, 0.5, amp));\n"
"}).add;\n";
        }

        code = code.replace("{SYNTHNAME}", appData.synthdef_name);
        
        appData.code = code.toStdString();
        text_code->setText(code.toStdString());
    };
    
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    btn_autorelease = nullptr;
    btn_testtone = nullptr;
    text_synthdef_name = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    text_scsynth_port = nullptr;
    juce__label3 = nullptr;
    text_sclang_port = nullptr;
    btn_liveargs = nullptr;
    label_client_id = nullptr;
    juce__label5 = nullptr;
    arg1 = nullptr;
    arg2 = nullptr;
    arg3 = nullptr;
    arg4 = nullptr;
    arg5 = nullptr;
    arg6 = nullptr;
    arg7 = nullptr;
    arg8 = nullptr;
    juce__label6 = nullptr;
    btn_send_on_load = nullptr;
    btn_send = nullptr;
    juce__label4 = nullptr;
    text_pitchbend_range = nullptr;
    text_code = nullptr;
    combo_presets = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

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



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainComponent::updateClientID(int newid)
{
    // appData.client_id = newid;
    // label_client_id->setText("Client ID: " + juce::String(appData.client_id), juce::dontSendNotification);
}

void MainComponent::loadFromAppData()
{
    text_synthdef_name->setText(appData.synthdef_name);
    text_scsynth_port->setText(juce::String(appData.scsynth_port));
    text_sclang_port->setText(juce::String(appData.sclang_port));
    text_pitchbend_range->setText(juce::String(appData.pitchbend_range));
    btn_autorelease->setToggleState(appData.autorelease, juce::dontSendNotification);
    btn_liveargs->setToggleState(appData.liveargs, juce::dontSendNotification);
    btn_send_on_load->setToggleState(appData.send_on_load, juce::dontSendNotification);
    text_code->setText(appData.code);

    arg1->loadFromAppData();
    arg2->loadFromAppData();
    arg3->loadFromAppData();
    arg4->loadFromAppData();
    arg5->loadFromAppData();
    arg6->loadFromAppData();
    arg7->loadFromAppData();
    arg8->loadFromAppData();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="ScsynthclientAudioProcessor&amp; processor"
                 variableInitialisers="processor(processor)&#10;appData(processor.appData)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="616">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 600 616" fill="solid: 808080" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="" id="b8558110aca6148e" memberName="btn_autorelease" virtualName=""
                explicitFocusOrder="0" pos="120 40 112 24" buttonText="Autorelease"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="985d3b3152aa2800" memberName="btn_testtone" virtualName=""
              explicitFocusOrder="0" pos="8 40 96 24" buttonText="Test Tone"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTEDITOR name="" id="4f37a4b3cc260d15" memberName="text_synthdef_name"
              virtualName="" explicitFocusOrder="0" pos="80 8 120 24" initialText="Synth1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="" id="87e96af479401f16" memberName="juce__label" virtualName=""
         explicitFocusOrder="0" pos="8 8 72 24" edTextCol="ff000000" edBkgCol="0"
         labelText="SynthDef:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="5eb3100c59612fcf" memberName="juce__label2" virtualName=""
         explicitFocusOrder="0" pos="208 8 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="scsynth:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="" id="c39ef4a68bff3ab1" memberName="text_scsynth_port"
              virtualName="" explicitFocusOrder="0" pos="272 8 48 24" initialText="57110"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="" id="ab30b1eed95c682" memberName="juce__label3" virtualName=""
         explicitFocusOrder="0" pos="328 8 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="sclang:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="" id="4644a9ac46618f5e" memberName="text_sclang_port" virtualName=""
              explicitFocusOrder="0" pos="384 8 48 24" initialText="57120"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="btn_liveargs" id="cac3c8de46c4287c" memberName="btn_liveargs"
                virtualName="" explicitFocusOrder="0" pos="232 40 88 24" buttonText="Live Args"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <LABEL name="" id="e228f0569f8dd0b3" memberName="label_client_id" virtualName=""
         explicitFocusOrder="0" pos="504 8 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ClientID: -1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="70d631c03ece97bf" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="8 72 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="# Arguments" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="" id="59f2633427c1cc23" memberName="arg1" virtualName=""
                    explicitFocusOrder="0" pos="8 96 584 24" class="ParameterComponent"
                    params="processor, 0"/>
  <GENERICCOMPONENT name="" id="469df798ec63f356" memberName="arg2" virtualName=""
                    explicitFocusOrder="0" pos="8 128 584 24" class="ParameterComponent"
                    params="processor, 1"/>
  <GENERICCOMPONENT name="" id="c9562bcceb5da19f" memberName="arg3" virtualName=""
                    explicitFocusOrder="0" pos="8 160 584 24" class="ParameterComponent"
                    params="processor, 2"/>
  <GENERICCOMPONENT name="" id="93f1a7fb66c16fe8" memberName="arg4" virtualName=""
                    explicitFocusOrder="0" pos="8 192 584 24" class="ParameterComponent"
                    params="processor, 3"/>
  <GENERICCOMPONENT name="" id="59433b16b0769023" memberName="arg5" virtualName=""
                    explicitFocusOrder="0" pos="8 224 584 24" class="ParameterComponent"
                    params="processor, 4"/>
  <GENERICCOMPONENT name="" id="64933755da142ae4" memberName="arg6" virtualName=""
                    explicitFocusOrder="0" pos="8 256 584 24" class="ParameterComponent"
                    params="processor, 5"/>
  <GENERICCOMPONENT name="" id="4ada125e95dc25e5" memberName="arg7" virtualName=""
                    explicitFocusOrder="0" pos="8 288 584 24" class="ParameterComponent"
                    params="processor, 6"/>
  <GENERICCOMPONENT name="" id="d64d023030bec916" memberName="arg8" virtualName=""
                    explicitFocusOrder="0" pos="8 320 584 24" class="ParameterComponent"
                    params="processor, 7"/>
  <LABEL name="" id="cc1d0442324b20f8" memberName="juce__label6" virtualName=""
         explicitFocusOrder="0" pos="8 352 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="# Code" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="" id="63638d04d75c5245" memberName="btn_send_on_load" virtualName=""
                explicitFocusOrder="0" pos="312 584 112 24" buttonText="Send on Load"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="6ebb09209c230c6d" memberName="btn_send" virtualName=""
              explicitFocusOrder="0" pos="440 584 152 24" buttonText="Send"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <LABEL name="" id="587bceb5cc5d0a4c" memberName="juce__label4" virtualName=""
         explicitFocusOrder="0" pos="440 40 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitchbend Range:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="" id="d908d4bb2849129f" memberName="text_pitchbend_range"
              virtualName="" explicitFocusOrder="0" pos="560 40 32 24" initialText="48"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="78d3c9f532f57857" memberName="text_code" virtualName=""
                    explicitFocusOrder="0" pos="8 376 584 200" class="CodeEditor"
                    params=""/>
  <GENERICCOMPONENT name="" id="661e682533365b59" memberName="combo_presets" virtualName=""
                    explicitFocusOrder="0" pos="8 584 150 24" class="juce::ComboBox"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

