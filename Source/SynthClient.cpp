#include "SynthClient.h"

SynthClient::SynthClient(int pitchbendRange)
{
    instrument.addListener(this);
    instrument.enableLegacyMode(pitchbendRange);
}

SynthClient::~SynthClient()
{
    instrument.removeListener(this);
    oscClient.reset();
}

void SynthClient::processMidiBuffer(const juce::MidiBuffer& midiMessages)
{
    for (const auto& m : midiMessages)
    {
        instrument.processNextMidiEvent(m.getMessage());
    }
}

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
 
