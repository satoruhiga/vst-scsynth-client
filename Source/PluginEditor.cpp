/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ScsynthclientAudioProcessorEditor::ScsynthclientAudioProcessorEditor (ScsynthclientAudioProcessor& p)
    : AudioProcessorEditor (p)
    , mainComponent(p.valueTreeState, p.appController)
{
    setSize (mainComponent.getWidth() + 4, mainComponent.getHeight() + 4);
    addAndMakeVisible(mainComponent);
}

ScsynthclientAudioProcessorEditor::~ScsynthclientAudioProcessorEditor()
{
}

//==============================================================================
void ScsynthclientAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void ScsynthclientAudioProcessorEditor::resized()
{
}
