#pragma once

#include <JuceHeader.h>

#include "AppData.h"
#include "OSCClient.h"

class SynthClient
    : public juce::MPEInstrument::Listener
{
    const int NODES_PAR_CLIENT = 1000;
    const int NODE_START_INDEX = 10000;

    int currentNoteID = 0;

    std::shared_ptr<OSCClient> oscClient;
    juce::MPEInstrument instrument;
    AppData& appData;

    juce::OSCBundle bundle;
    
public:

    SynthClient(AppData& appData);
    ~SynthClient() override;

    int getNextNodeID()
    {
        int nid = currentNoteID;
        currentNoteID += 1;
        currentNoteID %= NODES_PAR_CLIENT;

        return NODE_START_INDEX + nid + oscClient->getClientID() * NODES_PAR_CLIENT;
    }

    /////////////////////////////////////////////////

    struct SynthNote
    {
        int note_id = -1;
        float freq = 440;
        float release_time = 0;
    };
    void sendSynthNew(SynthNote& note);
    void sendSynthFree(SynthNote& note);

    /////////////////////////////////////////////////

    void sendCode();
    void sendTestTone(bool state);
    void portChanged();
    void argumentChanged(int index);
    
    /////////////////////////////////////////////////
    
    void processMidiBuffer(const juce::MidiBuffer& midiMessages);

    void noteAdded(juce::MPENote newNote) override;
    void notePressureChanged(juce::MPENote changedNote) override;
    void notePitchbendChanged(juce::MPENote changedNote) override;
    void noteTimbreChanged(juce::MPENote changedNote) override;
    void noteKeyStateChanged(juce::MPENote changedNote) override;
    void noteReleased(juce::MPENote finishedNote) override;
    void zoneLayoutChanged() override;
};
