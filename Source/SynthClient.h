#pragma once

#include <JuceHeader.h>
#include "OSCClient.h"

class SynthClient
    : public juce::MPEInstrument::Listener
{
    const int NODES_PAR_CLIENT = 1000;
    const int NODE_START_INDEX = 10000;

    int note_id = 0;

    std::shared_ptr<OSCClient> oscClient;
    juce::MPEInstrument instrument;

public:

    SynthClient(int pitchbendRange = 48);
    ~SynthClient() override;

    void connect(int scsynth_port, int sclang_port)
    {
        oscClient = std::make_shared<OSCClient>(scsynth_port, sclang_port);
    }

    int getNextNodeID()
    {
        int nid = note_id;
        note_id += 1;
        note_id %= NODES_PAR_CLIENT;

        return NODE_START_INDEX + nid + oscClient->getClientID() * NODES_PAR_CLIENT;
    }

    int sendSynthNew(int note, uint8_t velocity)
    {
        return -1;
    }

    int sendSynthFree(int note)
    {
        return -1;
    }

    void processMidiBuffer(const juce::MidiBuffer& midiMessages);

    void noteAdded(juce::MPENote newNote) override;
    void notePressureChanged(juce::MPENote changedNote) override;
    void notePitchbendChanged(juce::MPENote changedNote) override;
    void noteTimbreChanged(juce::MPENote changedNote) override;
    void noteKeyStateChanged(juce::MPENote changedNote) override;
    void noteReleased(juce::MPENote finishedNote) override;
    void zoneLayoutChanged() override;
};
