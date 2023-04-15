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
#include "BinaryData.h"
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

    juce__groupComponent3.reset (new juce::GroupComponent ("new group",
                                                           juce::String()));
    addAndMakeVisible (juce__groupComponent3.get());
    juce__groupComponent3->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff525759));

    juce__groupComponent3->setBounds (8, 0, 600, 80);

    juce__label5.reset (new juce::Label (juce::String(),
                                         TRANS("Vel")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centred);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (536, 33, 32, 24);

    slider_master_velocity.reset (new juce::Slider (juce::String()));
    addAndMakeVisible (slider_master_velocity.get());
    slider_master_velocity->setTooltip (TRANS("Master Velocity"));
    slider_master_velocity->setRange (0, 2, 0.01);
    slider_master_velocity->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    slider_master_velocity->setTextBoxStyle (juce::Slider::NoTextBox, false, 32, 20);

    slider_master_velocity->setBounds (512, 8, 80, 72);

    juce__groupComponent.reset (new juce::GroupComponent (juce::String(),
                                                          TRANS("Arguments")));
    addAndMakeVisible (juce__groupComponent.get());
    juce__groupComponent->setTextLabelPosition (juce::Justification::centredLeft);
    juce__groupComponent->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff525759));

    juce__groupComponent->setBounds (8, 96, 600, 296);

    btn_testtone.reset (new juce::TextButton (juce::String()));
    addAndMakeVisible (btn_testtone.get());
    btn_testtone->setButtonText (TRANS("Test Tone"));
    btn_testtone->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff42a2c8));

    btn_testtone->setBounds (16, 48, 96, 24);

    text_synthdef_name.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_synthdef_name.get());
    text_synthdef_name->setMultiLine (false);
    text_synthdef_name->setReturnKeyStartsNewLine (false);
    text_synthdef_name->setReadOnly (false);
    text_synthdef_name->setScrollbarsShown (true);
    text_synthdef_name->setCaretVisible (true);
    text_synthdef_name->setPopupMenuEnabled (true);
    text_synthdef_name->setText (TRANS("Synth1"));

    text_synthdef_name->setBounds (88, 16, 120, 24);

    juce__label.reset (new juce::Label (juce::String(),
                                        TRANS("SynthDef:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredRight);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (16, 16, 72, 24);

    juce__label2.reset (new juce::Label (juce::String(),
                                         TRANS("scsynth:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredRight);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (120, 48, 63, 24);

    text_scsynth_port.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_scsynth_port.get());
    text_scsynth_port->setMultiLine (false);
    text_scsynth_port->setReturnKeyStartsNewLine (false);
    text_scsynth_port->setReadOnly (false);
    text_scsynth_port->setScrollbarsShown (false);
    text_scsynth_port->setCaretVisible (true);
    text_scsynth_port->setPopupMenuEnabled (true);
    text_scsynth_port->setText (TRANS("57110"));

    text_scsynth_port->setBounds (184, 48, 48, 24);

    juce__label3.reset (new juce::Label (juce::String(),
                                         TRANS("sclang:")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredRight);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (240, 48, 56, 24);

    text_sclang_port.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_sclang_port.get());
    text_sclang_port->setMultiLine (false);
    text_sclang_port->setReturnKeyStartsNewLine (false);
    text_sclang_port->setReadOnly (false);
    text_sclang_port->setScrollbarsShown (false);
    text_sclang_port->setCaretVisible (true);
    text_sclang_port->setPopupMenuEnabled (true);
    text_sclang_port->setText (TRANS("57120"));

    text_sclang_port->setBounds (296, 48, 48, 24);

    btn_liveargs.reset (new juce::ToggleButton ("btn_liveargs"));
    addAndMakeVisible (btn_liveargs.get());
    btn_liveargs->setButtonText (TRANS("Live Args"));

    btn_liveargs->setBounds (504, 112, 88, 24);

    label_client_id.reset (new juce::Label (juce::String(),
                                            TRANS("Disconnected")));
    addAndMakeVisible (label_client_id.get());
    label_client_id->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    label_client_id->setJustificationType (juce::Justification::centredLeft);
    label_client_id->setEditable (false, false, false);
    label_client_id->setColour (juce::Label::textColourId, juce::Colours::red);
    label_client_id->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label_client_id->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label_client_id->setBounds (264, 16, 248, 24);

    arg1.reset (new ParameterComponent (processor, 0));
    addAndMakeVisible (arg1.get());

    arg1->setBounds (16, 136, 584, 24);

    arg2.reset (new ParameterComponent (processor, 1));
    addAndMakeVisible (arg2.get());

    arg2->setBounds (16, 168, 584, 24);

    arg3.reset (new ParameterComponent (processor, 2));
    addAndMakeVisible (arg3.get());

    arg3->setBounds (16, 200, 584, 24);

    arg4.reset (new ParameterComponent (processor, 3));
    addAndMakeVisible (arg4.get());

    arg4->setBounds (16, 232, 584, 24);

    arg5.reset (new ParameterComponent (processor, 4));
    addAndMakeVisible (arg5.get());

    arg5->setBounds (16, 264, 584, 24);

    arg6.reset (new ParameterComponent (processor, 5));
    addAndMakeVisible (arg6.get());

    arg6->setBounds (16, 296, 584, 24);

    arg7.reset (new ParameterComponent (processor, 6));
    addAndMakeVisible (arg7.get());

    arg7->setBounds (16, 328, 584, 24);

    arg8.reset (new ParameterComponent (processor, 7));
    addAndMakeVisible (arg8.get());

    arg8->setBounds (16, 360, 584, 24);

    btn_send_on_load.reset (new juce::ToggleButton (juce::String()));
    addAndMakeVisible (btn_send_on_load.get());
    btn_send_on_load->setButtonText (TRANS("Send on Load"));

    btn_send_on_load->setBounds (320, 632, 112, 24);

    btn_send.reset (new juce::TextButton (juce::String()));
    addAndMakeVisible (btn_send.get());
    btn_send->setButtonText (TRANS("Send"));

    btn_send->setBounds (448, 632, 152, 24);

    juce__label4.reset (new juce::Label (juce::String(),
                                         TRANS("PB Range:")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setTooltip (TRANS("MPE Petchbend Range"));
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredRight);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (344, 48, 80, 24);

    text_pitchbend_range.reset (new juce::TextEditor (juce::String()));
    addAndMakeVisible (text_pitchbend_range.get());
    text_pitchbend_range->setMultiLine (false);
    text_pitchbend_range->setReturnKeyStartsNewLine (false);
    text_pitchbend_range->setReadOnly (false);
    text_pitchbend_range->setScrollbarsShown (false);
    text_pitchbend_range->setCaretVisible (true);
    text_pitchbend_range->setPopupMenuEnabled (true);
    text_pitchbend_range->setText (TRANS("48"));

    text_pitchbend_range->setBounds (424, 48, 32, 24);

    text_code.reset (new CodeEditor());
    addAndMakeVisible (text_code.get());

    text_code->setBounds (16, 424, 584, 200);

    combo_presets.reset (new juce::ComboBox());
    addAndMakeVisible (combo_presets.get());

    combo_presets->setBounds (16, 632, 150, 24);

    juce__label7.reset (new juce::Label (juce::String(),
                                         TRANS("Name")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (16, 112, 72, 24);

    juce__label8.reset (new juce::Label (juce::String(),
                                         TRANS("Min")));
    addAndMakeVisible (juce__label8.get());
    juce__label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label8->setJustificationType (juce::Justification::centredLeft);
    juce__label8->setEditable (false, false, false);
    juce__label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label8->setBounds (152, 112, 72, 24);

    juce__label9.reset (new juce::Label (juce::String(),
                                         TRANS("Max")));
    addAndMakeVisible (juce__label9.get());
    juce__label9->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label9->setJustificationType (juce::Justification::centredLeft);
    juce__label9->setEditable (false, false, false);
    juce__label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label9->setBounds (240, 112, 72, 24);

    juce__label10.reset (new juce::Label (juce::String(),
                                          TRANS("Value")));
    addAndMakeVisible (juce__label10.get());
    juce__label10->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label10->setJustificationType (juce::Justification::centredLeft);
    juce__label10->setEditable (false, false, false);
    juce__label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label10->setBounds (328, 112, 72, 24);

    juce__groupComponent2.reset (new juce::GroupComponent (juce::String(),
                                                           TRANS("Code")));
    addAndMakeVisible (juce__groupComponent2.get());
    juce__groupComponent2->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff525759));

    juce__groupComponent2->setBounds (8, 408, 600, 256);

    juce__label6.reset (new juce::Label (juce::String(),
                                         TRANS("Status:")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredRight);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (208, 16, 62, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (612, 668);


    //[Constructor] You can add your own custom stuff here..

    // Synthdef name
    {
        text_synthdef_name->setInputRestrictions(0, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_");
        text_synthdef_name->onTextChange = [this]
        {
            appData.synthdef_name = text_synthdef_name->getText().toStdString();
        };
    }

    // Ports
    {
        text_scsynth_port->setInputRestrictions(5, "01234567890");
        text_scsynth_port->onReturnKey = [this]
        {
            int port = text_scsynth_port->getText().getIntValue();
            if (port > 0 && port < 65536)
            {
                appData.scsynth_port = port;

                if (appData.onPortChanged)
                    appData.onPortChanged();
            }
        };
        text_scsynth_port->onFocusLost = text_scsynth_port->onReturnKey;

        text_sclang_port->setInputRestrictions(5, "01234567890");
        text_sclang_port->onReturnKey = [this]
        {
            int port = text_sclang_port->getText().getIntValue();
            if (port > 0 && port < 65536)
            {
                appData.sclang_port = port;

                if (appData.onPortChanged)
                    appData.onPortChanged();
            }
        };
        text_sclang_port->onFocusLost = text_sclang_port->onReturnKey;
    }

    // Pitchbend range
    {
        text_pitchbend_range->setInputRestrictions(2, "01234567890");
        text_pitchbend_range->onReturnKey = [this]
        {
            int v = text_pitchbend_range->getText().getIntValue();
            if (v > 0 && v < 96)
            {
                appData.pitchbend_range = v;

                if (appData.onPitchbendRangeChanged)
                    appData.onPitchbendRangeChanged(v);
            }
        };
    }

    // Autorelease
    // {
    //     btn_autorelease->onClick = [this]
    //     {
    //         appData.autorelease = btn_autorelease->getToggleState();
    //     };
    //     btn_autorelease->setToggleState(appData.autorelease, juce::dontSendNotification);
    // }

    // Live args
    {
        btn_liveargs->onClick = [this]
        {
            appData.liveargs = btn_liveargs->getToggleState();
        };
    }

    // Code editor
    {
        text_code->onDocumentChanged = [this]
        {
            appData.code = text_code->getText();
        };

        text_code->onCtrlEnter = [this]
        {
            if (appData.onSendCode)
                appData.onSendCode();
        };
    }

    // Send button
    {
        btn_send->onClick = [this]
        {
            if (appData.onSendCode)
                appData.onSendCode();
        };
    }

    // Send on load
    {
        btn_send_on_load->onClick = [this]
        {
            appData.send_on_load = btn_send_on_load->getToggleState();
        };

        if (appData.send_on_load)
        {
            if (appData.onSendCode)
                appData.onSendCode();
        }
    }

    // Test tone
    {
        btn_testtone->onStateChange = [this]
        {
            bool s = btn_testtone->getState() == 2;
            static bool ss = s;

            if (ss != s)
            {
                ss = s;

                if (appData.onTestTone)
                {
                    if (ss)
                        appData.onTestTone(true);
                    else
                        appData.onTestTone(false);
                }
            }
        };
    }

    // Client ID
    {
        appData.onClientIDUpdated = [this]()
        {
            if (appData.client_id == -1)
            {
                label_client_id->setText(juce::String("Disconnected"), juce::dontSendNotification);
                label_client_id->setColour(juce::Label::textColourId, juce::Colours::red);
            }
            else
            {
                label_client_id->setText(
                    "Connected (id:" + juce::String(appData.client_id) + ")",
                    juce::dontSendNotification);
                label_client_id->setColour(juce::Label::textColourId, juce::Colours::green);
            }
        };
    }

    // Presets
    {
        presets.push_back({"Empty", ""});
        presets.push_back({"Simple", juce::String(BinaryData::_Simple_scd, BinaryData::_Simple_scdSize)});
        presets.push_back({"MPE", juce::String(BinaryData::_MPE_scd, BinaryData::_MPE_scdSize)});
    }

    // Preset Combo box
    {
        int itemid = 1;
        for (auto it : presets)
        {
            combo_presets->addItem(it.first, itemid);
            itemid += 1;
        }

        combo_presets->onChange = [this]
        {
            auto index = combo_presets->getSelectedItemIndex();
            if (index == -1)
                return;

            try
            {
                auto p = presets.at(index);
                auto code = p.second;
                code = code.replace("{NAME}", appData.synthdef_name);

                appData.code = code.toStdString();
                text_code->setText(code.toStdString());
            }
            catch (std::range_error&)
            {
                return;
            }
        };
        combo_presets->setText("Presets");
    }

    // Master volume
    {
        slider_master_velocity->onValueChange = [this]
        {
            appData.master_velocity = slider_master_velocity->getValue();
        };
        attachment_master_vel.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(
            processor.valueTreeState, "master_vel", *slider_master_velocity));
    }

    loadFromAppData();

    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    attachment_master_vel.reset();
    //[/Destructor_pre]

    juce__groupComponent3 = nullptr;
    juce__label5 = nullptr;
    slider_master_velocity = nullptr;
    juce__groupComponent = nullptr;
    btn_testtone = nullptr;
    text_synthdef_name = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    text_scsynth_port = nullptr;
    juce__label3 = nullptr;
    text_sclang_port = nullptr;
    btn_liveargs = nullptr;
    label_client_id = nullptr;
    arg1 = nullptr;
    arg2 = nullptr;
    arg3 = nullptr;
    arg4 = nullptr;
    arg5 = nullptr;
    arg6 = nullptr;
    arg7 = nullptr;
    arg8 = nullptr;
    btn_send_on_load = nullptr;
    btn_send = nullptr;
    juce__label4 = nullptr;
    text_pitchbend_range = nullptr;
    text_code = nullptr;
    combo_presets = nullptr;
    juce__label7 = nullptr;
    juce__label8 = nullptr;
    juce__label9 = nullptr;
    juce__label10 = nullptr;
    juce__groupComponent2 = nullptr;
    juce__label6 = nullptr;


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
void MainComponent::loadFromAppData()
{
    if (appData.onClientIDUpdated)
        appData.onClientIDUpdated();

    text_synthdef_name->setText(appData.synthdef_name);
    text_scsynth_port->setText(juce::String(appData.scsynth_port));
    text_sclang_port->setText(juce::String(appData.sclang_port));
    text_pitchbend_range->setText(juce::String(appData.pitchbend_range));
    slider_master_velocity->setValue(appData.master_velocity);
    // btn_autorelease->setToggleState(appData.autorelease, juce::dontSendNotification);
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
                 fixedSize="0" initialWidth="612" initialHeight="668">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="4 4 612 668" fill="solid: 808080" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="1cee116018ec2ad1" memberName="juce__groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="8 0 600 80" outlinecol="ff525759"
                  title=""/>
  <LABEL name="" id="5518d6d94fb45dcb" memberName="juce__label5" virtualName=""
         explicitFocusOrder="0" pos="536 33 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Vel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="bbd99749b8846ffb" memberName="slider_master_velocity"
          virtualName="" explicitFocusOrder="0" pos="512 8 80 72" tooltip="Master Velocity"
          min="0.0" max="2.0" int="0.01" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="32"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="" id="8542c8695e9a17e3" memberName="juce__groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 96 600 296" outlinecol="ff525759"
                  title="Arguments" textpos="33"/>
  <TEXTBUTTON name="" id="985d3b3152aa2800" memberName="btn_testtone" virtualName=""
              explicitFocusOrder="0" pos="16 48 96 24" bgColOff="ff42a2c8"
              buttonText="Test Tone" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTEDITOR name="" id="4f37a4b3cc260d15" memberName="text_synthdef_name"
              virtualName="" explicitFocusOrder="0" pos="88 16 120 24" initialText="Synth1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="" id="87e96af479401f16" memberName="juce__label" virtualName=""
         explicitFocusOrder="0" pos="16 16 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="SynthDef:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <LABEL name="" id="5eb3100c59612fcf" memberName="juce__label2" virtualName=""
         explicitFocusOrder="0" pos="120 48 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="scsynth:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="c39ef4a68bff3ab1" memberName="text_scsynth_port"
              virtualName="" explicitFocusOrder="0" pos="184 48 48 24" initialText="57110"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="" id="ab30b1eed95c682" memberName="juce__label3" virtualName=""
         explicitFocusOrder="0" pos="240 48 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="sclang:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="4644a9ac46618f5e" memberName="text_sclang_port" virtualName=""
              explicitFocusOrder="0" pos="296 48 48 24" initialText="57120"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="btn_liveargs" id="cac3c8de46c4287c" memberName="btn_liveargs"
                virtualName="" explicitFocusOrder="0" pos="504 112 88 24" buttonText="Live Args"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <LABEL name="" id="e228f0569f8dd0b3" memberName="label_client_id" virtualName=""
         explicitFocusOrder="0" pos="264 16 248 24" textCol="ffff0000"
         edTextCol="ff000000" edBkgCol="0" labelText="Disconnected" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <GENERICCOMPONENT name="" id="59f2633427c1cc23" memberName="arg1" virtualName=""
                    explicitFocusOrder="0" pos="16 136 584 24" class="ParameterComponent"
                    params="processor, 0"/>
  <GENERICCOMPONENT name="" id="469df798ec63f356" memberName="arg2" virtualName=""
                    explicitFocusOrder="0" pos="16 168 584 24" class="ParameterComponent"
                    params="processor, 1"/>
  <GENERICCOMPONENT name="" id="c9562bcceb5da19f" memberName="arg3" virtualName=""
                    explicitFocusOrder="0" pos="16 200 584 24" class="ParameterComponent"
                    params="processor, 2"/>
  <GENERICCOMPONENT name="" id="93f1a7fb66c16fe8" memberName="arg4" virtualName=""
                    explicitFocusOrder="0" pos="16 232 584 24" class="ParameterComponent"
                    params="processor, 3"/>
  <GENERICCOMPONENT name="" id="59433b16b0769023" memberName="arg5" virtualName=""
                    explicitFocusOrder="0" pos="16 264 584 24" class="ParameterComponent"
                    params="processor, 4"/>
  <GENERICCOMPONENT name="" id="64933755da142ae4" memberName="arg6" virtualName=""
                    explicitFocusOrder="0" pos="16 296 584 24" class="ParameterComponent"
                    params="processor, 5"/>
  <GENERICCOMPONENT name="" id="4ada125e95dc25e5" memberName="arg7" virtualName=""
                    explicitFocusOrder="0" pos="16 328 584 24" class="ParameterComponent"
                    params="processor, 6"/>
  <GENERICCOMPONENT name="" id="d64d023030bec916" memberName="arg8" virtualName=""
                    explicitFocusOrder="0" pos="16 360 584 24" class="ParameterComponent"
                    params="processor, 7"/>
  <TOGGLEBUTTON name="" id="63638d04d75c5245" memberName="btn_send_on_load" virtualName=""
                explicitFocusOrder="0" pos="320 632 112 24" buttonText="Send on Load"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="6ebb09209c230c6d" memberName="btn_send" virtualName=""
              explicitFocusOrder="0" pos="448 632 152 24" buttonText="Send"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <LABEL name="" id="587bceb5cc5d0a4c" memberName="juce__label4" virtualName=""
         explicitFocusOrder="0" pos="344 48 80 24" tooltip="MPE Petchbend Range"
         edTextCol="ff000000" edBkgCol="0" labelText="PB Range:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="" id="d908d4bb2849129f" memberName="text_pitchbend_range"
              virtualName="" explicitFocusOrder="0" pos="424 48 32 24" initialText="48"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="78d3c9f532f57857" memberName="text_code" virtualName=""
                    explicitFocusOrder="0" pos="16 424 584 200" class="CodeEditor"
                    params=""/>
  <GENERICCOMPONENT name="" id="661e682533365b59" memberName="combo_presets" virtualName=""
                    explicitFocusOrder="0" pos="16 632 150 24" class="juce::ComboBox"
                    params=""/>
  <LABEL name="" id="ec9075f576256a91" memberName="juce__label7" virtualName=""
         explicitFocusOrder="0" pos="16 112 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Name" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="8c53561b1ba522f5" memberName="juce__label8" virtualName=""
         explicitFocusOrder="0" pos="152 112 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Min" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="a439eae3ce29ecbe" memberName="juce__label9" virtualName=""
         explicitFocusOrder="0" pos="240 112 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Max" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="370864365f18c485" memberName="juce__label10" virtualName=""
         explicitFocusOrder="0" pos="328 112 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="" id="5e31d7cf9b5c1658" memberName="juce__groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 408 600 256" outlinecol="ff525759"
                  title="Code"/>
  <LABEL name="" id="22b0f44b26d011d3" memberName="juce__label6" virtualName=""
         explicitFocusOrder="0" pos="208 16 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Status:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

