#include "SynthClient.h"

SynthClient::SynthClient(AppController& appController)
    : appController(appController)
{
    instrument.addListener(this);
    instrument.enableLegacyMode(appController.pitchbend_range);

    oscClient = std::make_shared<OSCClient>(appController.scsynth_port, appController.sclang_port);
    if (oscClient->getClientID() != -1)
    {
        appController.client_id = oscClient->getClientID();
        if (appController.onClientIDUpdated)
            appController.onClientIDUpdated();
    }

    appController.onSendCode = std::bind(&SynthClient::sendCode, this);
    appController.onTestTone = std::bind(&SynthClient::sendTestTone, this, std::placeholders::_1);
    appController.onPortChanged = std::bind(&SynthClient::portChanged, this);
    appController.onArgumentChanged = std::bind(&SynthClient::argumentChanged, this, std::placeholders::_1);
    appController.onPitchbendRangeChanged = [this](int v)
    {
        instrument.enableLegacyMode(v);
    };
}

SynthClient::~SynthClient()
{
    instrument.removeListener(this);
    oscClient.reset();
}

/////////////////////////////////////////////////

int SynthClient::sendSynthNew(SynthNote& note)
{
    if (!oscClient) return -1;

    note.note_id = getNextNodeID();

    int add_action = 0;
    int target_node_id = 1;

    juce::OSCMessage message(
        "/s_new",
        juce::OSCArgument(appController.synthdef_name),
        note.note_id, add_action, target_node_id,
        juce::String("freq"), note.freq,
        juce::String("amp"), note.velocity,
        juce::String("pressure"), note.pressure,
        juce::String("timbre"), note.timbre
    );

    for (auto& p : appController.params)
    {
        if (p.name.empty())
            continue;

        float v = p.value * (p.value_max - p.value_min) + p.value_min;
        message.addArgument(juce::OSCArgument(p.name.c_str()));
        message.addArgument(juce::OSCArgument(v));
    }

    oscClient->sendToSCSynth(message);

    return note.note_id;
}

void SynthClient::sendSynthFree(SynthNote& note)
{
    if (!oscClient) return;
    // if (!appData.autorelease) return;

    float gate = -note.release_time;
    juce::OSCMessage message(
        "/n_set", note.note_id,
        juce::String("gate"), gate,
        juce::String("release_vel"), note.note_off_velocity
    );

    oscClient->sendToSCSynth(message);
}

/////////////////////////////////////////////////

void SynthClient::portChanged()
{
    oscClient = std::make_shared<OSCClient>(appController.scsynth_port, appController.sclang_port);
    if (appController.onClientIDUpdated)
        appController.onClientIDUpdated();
}

void SynthClient::sendCode()
{
    if (!oscClient) return;

    juce::String code = appController.code;
    code = code.replace(SYNTHNAME_STR, appController.synthdef_name);
    juce::OSCMessage message("/eval", code.trim());
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
    if (!appController.liveargs) return;

    for (auto n : synthNotes)
    {
        SynthNote& note = n.second;
        if (note.note_id == -1)
            continue;

        auto& p = appController.params[index];
        float v = p.value * (p.value_max - p.value_min) + p.value_min;

        juce::OSCMessage message(
            "/n_set", note.note_id,
            juce::String(p.name.c_str()), v
        );

        oscClient->sendToSCSynth(message);
    }
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
    SynthNote s;
    s.freq = note.getFrequencyInHertz();
    s.velocity = note.noteOnVelocity.asUnsignedFloat() * appController.master_velocity;
    s.pressure = note.pressure.asUnsignedFloat();
    s.timbre = note.timbre.asUnsignedFloat();

    int synth_id = sendSynthNew(s);
    if (synth_id)
    {
        synthNotes[note.noteID] = s;
    }
}

void SynthClient::notePitchbendChanged(juce::MPENote note)
{
    auto it = synthNotes.find(note.noteID);
    if (it == synthNotes.end())
        return;

    SynthNote& s = it->second;
    s.freq = note.getFrequencyInHertz();

    juce::OSCMessage message(
        "/n_set", s.note_id,
        juce::String("freq"), s.freq
    );

    oscClient->sendToSCSynth(message);
}

void SynthClient::notePressureChanged(juce::MPENote note)
{
    auto it = synthNotes.find(note.noteID);
    if (it == synthNotes.end())
        return;

    SynthNote& s = it->second;
    s.pressure = note.pressure.asUnsignedFloat();

    juce::OSCMessage message(
        "/n_set", s.note_id,
        juce::String("pressure"), s.pressure
    );

    oscClient->sendToSCSynth(message);
}

void SynthClient::noteTimbreChanged(juce::MPENote note)
{
    auto it = synthNotes.find(note.noteID);
    if (it == synthNotes.end())
        return;

    SynthNote& s = it->second;
    s.timbre = note.timbre.asUnsignedFloat();

    juce::OSCMessage message(
        "/n_set", s.note_id,
        juce::String("timbre"), s.timbre
    );

    oscClient->sendToSCSynth(message);
}

void SynthClient::noteKeyStateChanged(juce::MPENote note)
{
    // DBG("noteKeyStateChanged " << (int)note.noteID);
}

void SynthClient::noteReleased(juce::MPENote note)
{
    auto it = synthNotes.find(note.noteID);
    if (it == synthNotes.end())
        return;

    SynthNote& s = it->second;
    s.note_off_velocity = note.noteOffVelocity.asUnsignedFloat() * appController.master_velocity;

    sendSynthFree(s);

    synthNotes.erase(it);
}

void SynthClient::zoneLayoutChanged()
{
}
