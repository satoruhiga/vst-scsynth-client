#pragma once

#include <JuceHeader.h>

#include "AppController.h"
#include "OSCClient.h"

class SynthClient
    : public juce::MPEInstrument::Listener
{
    const int NODES_PAR_CLIENT = 1000;
    const int NODE_START_INDEX = 10000;

    int currentNoteID = 0;

    std::shared_ptr<OSCClient> oscClient;
    juce::MPEInstrument instrument;
    AppController& appController;
    
public:

    struct SynthNote
    {
        int note_id = -1;
        float freq = 440;
        float velocity = 1;
        float pressure = 0.5;
        float timbre = 0.5;
        float note_off_velocity = 0;
        float release_time = 0;
    };

    SynthClient(AppController& appController);
    ~SynthClient() override;

    void connectToServer(int scsynth_port, int osc_port);
    int getNextNodeID();

    /////////////////////////////////////////////////

    int sendSynthNew(SynthNote& note);
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
    
private:
    
    std::map<int, SynthNote> synthNotes;
};
