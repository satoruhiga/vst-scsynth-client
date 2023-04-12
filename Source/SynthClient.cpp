#include "SynthClient.h"

SynthClient::SynthClient(AppData& appData)
    : appData(appData)
{
    instrument.addListener(this);
    instrument.enableLegacyMode(appData.pitchbend_range);

    oscClient = std::make_shared<OSCClient>(appData.scsynth_port, appData.sclang_port);

    appData.onSendCode = std::bind(&SynthClient::sendCode, this);
    appData.onTestTone = std::bind(&SynthClient::sendTestTone, this, std::placeholders::_1);
    appData.onPortChanged = std::bind(&SynthClient::portChanged, this);
    appData.onArgumentChanged = std::bind(&SynthClient::argumentChanged, this, std::placeholders::_1);
}

SynthClient::~SynthClient()
{
    instrument.removeListener(this);
    oscClient.reset();
}

/////////////////////////////////////////////////

void SynthClient::sendSynthNew(SynthNote& note)
{
}

void SynthClient::sendSynthFree(SynthNote& note)
{
}

/////////////////////////////////////////////////

void SynthClient::portChanged()
{
    oscClient = std::make_shared<OSCClient>(appData.scsynth_port, appData.sclang_port);
}

void SynthClient::sendCode()
{
    if (!oscClient) return;

    juce::OSCMessage message("/eval", juce::String(appData.code));
    oscClient->sendToSCLang(message);
}

void SynthClient::sendTestTone(bool state)
{
    if (!oscClient) return;
    DBG("sendTestTone " << (int)state);
}

void SynthClient::argumentChanged(int index)
{
    if (!oscClient) return;
}

/////////////////////////////////////////////////

void SynthClient::processMidiBuffer(const juce::MidiBuffer& midiMessages)
{
    bundle = juce::OSCBundle();
    
    for (const auto& m : midiMessages)
    {
        instrument.processNextMidiEvent(m.getMessage());
    }

    if (!bundle.isEmpty() && oscClient)
    {
        oscClient->sendToSCSynth(bundle);
    }
}

/////////////////////////////////////////////////

void SynthClient::noteAdded(juce::MPENote note)
{
    // sendSynthNew(newNote.getNoteNumber(), newNote.getVelocity());
    // DBG("noteAdded " << (int)note.noteID);

    note.getFrequencyInHertz();
}

void SynthClient::notePressureChanged(juce::MPENote note)
{
    DBG("notePressureChanged " << (int)note.noteID);
}

void SynthClient::notePitchbendChanged(juce::MPENote note)
{
    DBG("notePitchbendChanged " << (int)note.noteID);
}

void SynthClient::noteTimbreChanged(juce::MPENote note)
{
    DBG("noteTimbreChanged " << (int)note.noteID);
}

void SynthClient::noteKeyStateChanged(juce::MPENote note)
{
    // DBG("noteKeyStateChanged " << (int)note.noteID);
}

void SynthClient::noteReleased(juce::MPENote note)
{
    // sendSynthFree(finishedNote.getNoteNumber());
    DBG("noteReleased " << (int)note.noteID);
}

void SynthClient::zoneLayoutChanged()
{
}
 
