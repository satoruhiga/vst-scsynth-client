#include "SynthClient.h"

SynthClient::SynthClient(AppData& appData)
    : appData(appData)
{
    instrument.addListener(this);
    instrument.enableLegacyMode(appData.pitchbend_range);

    oscClient = std::make_shared<OSCClient>(appData.scsynth_port, appData.sclang_port);
    if (oscClient->getClientID() != -1)
    {
        appData.client_id = oscClient->getClientID();
        if (appData.onClientIDUpdated)
            appData.onClientIDUpdated();
    }

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
    if (!oscClient) return;

    note.note_id = getNextNodeID();

    int add_action = 0;
    int target_node_id = 1;

    juce::OSCMessage message(
        "/s_new",
        juce::OSCArgument(appData.synthdef_name),
        note.note_id, add_action, target_node_id,
        juce::OSCArgument("freq"), juce::OSCArgument(note.freq),
        juce::OSCArgument("amp"), juce::OSCArgument(note.amp)
    );

    for (auto& p : appData.params)
    {
        if (p.name.empty())
            continue;

        float v = p.value * (p.value_max - p.value_min) + p.value_min;
        message.addArgument(juce::OSCArgument(p.name.c_str()));
        message.addArgument(juce::OSCArgument(v));
    }

    oscClient->sendToSCSynth(message);
}

void SynthClient::sendSynthFree(SynthNote& note)
{
    if (!oscClient) return;
    if (!appData.autorelease) return;

    float gate = -1 - note.release_time;
    juce::OSCMessage message(
        "/n_set", note.note_id,
        juce::String("gate"), gate
    );

    oscClient->sendToSCSynth(message);
}

/////////////////////////////////////////////////

void SynthClient::portChanged()
{
    oscClient = std::make_shared<OSCClient>(appData.scsynth_port, appData.sclang_port);
    if (appData.onClientIDUpdated)
        appData.onClientIDUpdated();
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

    static SynthNote note;
    if (state)
        sendSynthNew(note);
    else
        sendSynthFree(note);
}

void SynthClient::argumentChanged(int index)
{
    if (!oscClient) return;
}

/////////////////////////////////////////////////

void SynthClient::processMidiBuffer(const juce::MidiBuffer& midiMessages)
{
    for (const auto& m : midiMessages)
    {
        instrument.processNextMidiEvent(m.getMessage());
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
