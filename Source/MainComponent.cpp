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

    btn_autorelease.reset (new juce::ToggleButton ("btn_autorelease"));
    addAndMakeVisible (btn_autorelease.get());
    btn_autorelease->setButtonText (TRANS("Autorelease"));

    btn_autorelease->setBounds (120, 40, 112, 24);

    btn_testtone.reset (new juce::TextButton ("btn_testtone"));
    addAndMakeVisible (btn_testtone.get());
    btn_testtone->setButtonText (TRANS("Test Tone"));

    btn_testtone->setBounds (8, 40, 96, 24);

    text_synthdef_name.reset (new juce::TextEditor ("text_synthdef_name"));
    addAndMakeVisible (text_synthdef_name.get());
    text_synthdef_name->setMultiLine (false);
    text_synthdef_name->setReturnKeyStartsNewLine (false);
    text_synthdef_name->setReadOnly (false);
    text_synthdef_name->setScrollbarsShown (true);
    text_synthdef_name->setCaretVisible (true);
    text_synthdef_name->setPopupMenuEnabled (true);
    text_synthdef_name->setText (TRANS("Synth1"));

    text_synthdef_name->setBounds (80, 8, 120, 24);

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

    text_scsynth_port.reset (new juce::TextEditor ("text_scsynth_port"));
    addAndMakeVisible (text_scsynth_port.get());
    text_scsynth_port->setMultiLine (false);
    text_scsynth_port->setReturnKeyStartsNewLine (false);
    text_scsynth_port->setReadOnly (false);
    text_scsynth_port->setScrollbarsShown (false);
    text_scsynth_port->setCaretVisible (true);
    text_scsynth_port->setPopupMenuEnabled (true);
    text_scsynth_port->setText (TRANS("57110"));

    text_scsynth_port->setBounds (272, 8, 48, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("sclang:")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (328, 8, 56, 24);

    text_sclang_port.reset (new juce::TextEditor ("text_sclang_port"));
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

    label_client_id.reset (new juce::Label ("label_client_id",
                                            TRANS("ClientID: -1")));
    addAndMakeVisible (label_client_id.get());
    label_client_id->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label_client_id->setJustificationType (juce::Justification::centredLeft);
    label_client_id->setEditable (false, false, false);
    label_client_id->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label_client_id->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label_client_id->setBounds (440, 8, 88, 24);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("# Arguments")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (8, 72, 150, 24);

    arg1.reset (new ParameterComponent());
    addAndMakeVisible (arg1.get());
    arg1->setName ("arg1");

    arg1->setBounds (8, 96, 584, 24);

    arg2.reset (new ParameterComponent());
    addAndMakeVisible (arg2.get());
    arg2->setName ("arg2");

    arg2->setBounds (8, 128, 584, 24);

    arg3.reset (new ParameterComponent());
    addAndMakeVisible (arg3.get());
    arg3->setName ("arg3");

    arg3->setBounds (8, 160, 584, 24);

    arg4.reset (new ParameterComponent());
    addAndMakeVisible (arg4.get());
    arg4->setName ("arg4");

    arg4->setBounds (8, 192, 584, 24);

    arg5.reset (new ParameterComponent());
    addAndMakeVisible (arg5.get());
    arg5->setName ("arg5");

    arg5->setBounds (8, 224, 584, 24);

    arg6.reset (new ParameterComponent());
    addAndMakeVisible (arg6.get());
    arg6->setName ("arg6");

    arg6->setBounds (8, 256, 584, 24);

    arg7.reset (new ParameterComponent());
    addAndMakeVisible (arg7.get());
    arg7->setName ("arg7");

    arg7->setBounds (8, 288, 584, 24);

    arg8.reset (new ParameterComponent());
    addAndMakeVisible (arg8.get());
    arg8->setName ("arg8");

    arg8->setBounds (8, 320, 584, 24);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("# Code")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (8, 352, 150, 24);

    text_code.reset (new juce::TextEditor ("text_code"));
    addAndMakeVisible (text_code.get());
    text_code->setMultiLine (true);
    text_code->setReturnKeyStartsNewLine (true);
    text_code->setReadOnly (false);
    text_code->setScrollbarsShown (true);
    text_code->setCaretVisible (true);
    text_code->setPopupMenuEnabled (true);
    text_code->setText (juce::String());

    text_code->setBounds (8, 376, 584, 200);

    btn_send_on_load.reset (new juce::ToggleButton ("btn_send_on_load"));
    addAndMakeVisible (btn_send_on_load.get());
    btn_send_on_load->setButtonText (TRANS("Send on Load"));

    btn_send_on_load->setBounds (8, 584, 112, 24);

    btn_send.reset (new juce::TextButton ("btn_send"));
    addAndMakeVisible (btn_send.get());
    btn_send->setButtonText (TRANS("Send"));

    btn_send->setBounds (136, 584, 456, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 616);

    //[Constructor] You can add your own custom stuff here..
    text_synthdef_name->setInputRestrictions(0, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_");
    text_synthdef_name->onReturnKey = [this] {
        synthdef_name = text_synthdef_name->getText().toStdString();
    };

    text_scsynth_port->setInputRestrictions(5, "01234567890");
    text_scsynth_port->onReturnKey = [this] {
        int port = text_scsynth_port->getText().getIntValue();
        if (port > 0 && port < 65536) {
            scsynth_port = port;
            
            if (onClientUpdated)
                onClientUpdated(scsynth_port, sclang_port);
        }
    };

    text_sclang_port->setInputRestrictions(5, "01234567890");
    text_sclang_port->onReturnKey = [this] {
        int port = text_sclang_port->getText().getIntValue();
        if (port > 0 && port < 65536) {
            sclang_port = port;
            
            if (onClientUpdated)
                onClientUpdated(scsynth_port, sclang_port);
        }
    };

    btn_autorelease->onClick = [this] {
        autorelease = btn_autorelease->getToggleState();
    };

    btn_liveargs->onClick = [this] {
        liveargs = btn_liveargs->getToggleState();
    };

    btn_send_on_load->onClick = [this] {
        send_on_load = btn_send_on_load->getToggleState();
    };

    text_code->onTextChange = [this] {
        code = text_code->getText().toStdString();
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
    text_code = nullptr;
    btn_send_on_load = nullptr;
    btn_send = nullptr;


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
    client_id = newid;
    label_client_id->setText("Client ID: " + juce::String(client_id), juce::dontSendNotification);
}

void MainComponent::getStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    if (!xml)
        return;
    
    xml->setAttribute("synthdef_name", synthdef_name);
    xml->setAttribute("scsynth_port", scsynth_port);
    xml->setAttribute("sclang_port", sclang_port);
    xml->setAttribute("autorelease", autorelease);
    xml->setAttribute("liveargs", liveargs);
    xml->setAttribute("send_on_load", send_on_load);
    xml->setAttribute("code", code);

    arg1->getStateInformation(xml);
    arg2->getStateInformation(xml);
    arg3->getStateInformation(xml);
    arg4->getStateInformation(xml);
    arg5->getStateInformation(xml);
    arg6->getStateInformation(xml);
    arg7->getStateInformation(xml);
    arg8->getStateInformation(xml);
}

void MainComponent::setStateInformation(std::unique_ptr<juce::XmlElement>& xml)
{
    if (!xml)
        return;
    
    synthdef_name = xml->getStringAttribute("synthdef_name", "Synth1").toStdString();
    scsynth_port = xml->getIntAttribute("scsynth_port", 57110);
    sclang_port = xml->getIntAttribute("sclang_port", 57120);
    autorelease = xml->getBoolAttribute("autorelease", true);
    liveargs = xml->getBoolAttribute("liveargs", true);
    send_on_load = xml->getBoolAttribute("send_on_load", true);
    code = xml->getStringAttribute("code", "").toStdString();

    text_synthdef_name->setText(synthdef_name);
    text_scsynth_port->setText(juce::String(scsynth_port));
    text_sclang_port->setText(juce::String(sclang_port));
    btn_autorelease->setToggleState(autorelease, juce::sendNotification);
    btn_liveargs->setToggleState(liveargs, juce::sendNotification);
    btn_send_on_load->setToggleState(send_on_load, juce::sendNotification);
    text_code->setText(code);

    arg1->setStateInformation(xml);
    arg2->setStateInformation(xml);
    arg3->setStateInformation(xml);
    arg4->setStateInformation(xml);
    arg5->setStateInformation(xml);
    arg6->setStateInformation(xml);
    arg7->setStateInformation(xml);
    arg8->setStateInformation(xml);
    
    if (onClientUpdated)
        onClientUpdated(scsynth_port, sclang_port);
}

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
                 fixedSize="0" initialWidth="600" initialHeight="616">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 600 616" fill="solid: 808080" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="btn_autorelease" id="b8558110aca6148e" memberName="btn_autorelease"
                virtualName="" explicitFocusOrder="0" pos="120 40 112 24" buttonText="Autorelease"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="btn_testtone" id="985d3b3152aa2800" memberName="btn_testtone"
              virtualName="" explicitFocusOrder="0" pos="8 40 96 24" buttonText="Test Tone"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <TEXTEDITOR name="text_synthdef_name" id="4f37a4b3cc260d15" memberName="text_synthdef_name"
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
  <TEXTEDITOR name="text_scsynth_port" id="c39ef4a68bff3ab1" memberName="text_scsynth_port"
              virtualName="" explicitFocusOrder="0" pos="272 8 48 24" initialText="57110"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="ab30b1eed95c682" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="328 8 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="sclang:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="text_sclang_port" id="4644a9ac46618f5e" memberName="text_sclang_port"
              virtualName="" explicitFocusOrder="0" pos="384 8 48 24" initialText="57120"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="btn_liveargs" id="cac3c8de46c4287c" memberName="btn_liveargs"
                virtualName="" explicitFocusOrder="0" pos="232 40 88 24" buttonText="Live Args"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <LABEL name="label_client_id" id="e228f0569f8dd0b3" memberName="label_client_id"
         virtualName="" explicitFocusOrder="0" pos="440 8 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ClientID: -1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="70d631c03ece97bf" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="8 72 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="# Arguments" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="arg1" id="59f2633427c1cc23" memberName="arg1" virtualName=""
                    explicitFocusOrder="0" pos="8 96 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg2" id="469df798ec63f356" memberName="arg2" virtualName=""
                    explicitFocusOrder="0" pos="8 128 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg3" id="c9562bcceb5da19f" memberName="arg3" virtualName=""
                    explicitFocusOrder="0" pos="8 160 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg4" id="93f1a7fb66c16fe8" memberName="arg4" virtualName=""
                    explicitFocusOrder="0" pos="8 192 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg5" id="59433b16b0769023" memberName="arg5" virtualName=""
                    explicitFocusOrder="0" pos="8 224 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg6" id="64933755da142ae4" memberName="arg6" virtualName=""
                    explicitFocusOrder="0" pos="8 256 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg7" id="4ada125e95dc25e5" memberName="arg7" virtualName=""
                    explicitFocusOrder="0" pos="8 288 584 24" class="ParameterComponent"
                    params=""/>
  <GENERICCOMPONENT name="arg8" id="d64d023030bec916" memberName="arg8" virtualName=""
                    explicitFocusOrder="0" pos="8 320 584 24" class="ParameterComponent"
                    params=""/>
  <LABEL name="new label" id="cc1d0442324b20f8" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="8 352 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="# Code" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="text_code" id="6278dc77606b7098" memberName="text_code"
              virtualName="" explicitFocusOrder="0" pos="8 376 584 200" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="btn_send_on_load" id="63638d04d75c5245" memberName="btn_send_on_load"
                virtualName="" explicitFocusOrder="0" pos="8 584 112 24" buttonText="Send on Load"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="btn_send" id="6ebb09209c230c6d" memberName="btn_send" virtualName=""
              explicitFocusOrder="0" pos="136 584 456 24" buttonText="Send"
              connectedEdges="0" needsCallback="0" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

