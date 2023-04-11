/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "MainComponent.h"

//==============================================================================
/**
*/
class ScsynthclientAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    MainComponent mainComponent;
    
    ScsynthclientAudioProcessorEditor (ScsynthclientAudioProcessor&);
    ~ScsynthclientAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    ScsynthclientAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScsynthclientAudioProcessorEditor)
};
