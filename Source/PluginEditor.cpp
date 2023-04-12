/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ScsynthclientAudioProcessorEditor::ScsynthclientAudioProcessorEditor (ScsynthclientAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (mainComponent.getWidth(), mainComponent.getHeight());
    addAndMakeVisible(mainComponent);
    
    mainComponent.setOnClientUpdated(std::bind(&ScsynthclientAudioProcessor::onClientUpdated, &p, std::placeholders::_1, std::placeholders::_2));
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
