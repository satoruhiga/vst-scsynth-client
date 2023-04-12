/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ScsynthclientAudioProcessor::ScsynthclientAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
//                     #if ! JucePlugin_IsMidiEffect
//                      #if ! JucePlugin_IsSynth
//                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
//                      #endif
//                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
//                     #endif
                       )
    , valueTreeState(*this, nullptr, juce::Identifier("scsynth-client"),
                     {
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg1", "Arg1", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg2", "Arg2", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg3", "Arg3", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg4", "Arg4", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg5", "Arg5", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg6", "Arg6", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg7", "Arg7", 0.0f, 1.0f, 0.0f),
                       std::make_unique<juce::AudioParameterFloat>(
                         "arg8", "Arg8", 0.0f, 1.0f, 0.0f),
                     })
#endif
{
//    instrument.addListener(<#Listener *listenerToAdd#>)
    instrument.enableLegacyMode(24);
}

ScsynthclientAudioProcessor::~ScsynthclientAudioProcessor()
{
}

//==============================================================================
const juce::String ScsynthclientAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ScsynthclientAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ScsynthclientAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ScsynthclientAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ScsynthclientAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ScsynthclientAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ScsynthclientAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ScsynthclientAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ScsynthclientAudioProcessor::getProgramName (int index)
{
    return {};
}

void ScsynthclientAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ScsynthclientAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ScsynthclientAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ScsynthclientAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ScsynthclientAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (const auto& m : midiMessages)
    {
        instrument.processNextMidiEvent(m.getMessage());
    }
}

//==============================================================================
bool ScsynthclientAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ScsynthclientAudioProcessor::createEditor()
{
    return new ScsynthclientAudioProcessorEditor (*this);
}

//==============================================================================
void ScsynthclientAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    auto state = valueTreeState.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());

    appData.getStateInformation(xml);

    // ScsynthclientAudioProcessorEditor* editor = (ScsynthclientAudioProcessorEditor*)createEditorIfNeeded();
    // editor->mainComponent.getStateInformation(xml);

    copyXmlToBinary(*xml, destData);
}

void ScsynthclientAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (!xml) return;

    if (xml->hasTagName(valueTreeState.state.getType()))
        valueTreeState.replaceState(juce::ValueTree::fromXml(*xml));

    appData.setStateInformation(xml);

    // ScsynthclientAudioProcessorEditor* editor = (ScsynthclientAudioProcessorEditor*)createEditorIfNeeded();
    // if (editor)
    //     editor->mainComponent.setStateInformation(xml);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ScsynthclientAudioProcessor();
}


void ScsynthclientAudioProcessor::onClientUpdated(int scsynth_port, int sclang_port)
{
    synthClient = std::make_shared<SynthClient>(scsynth_port, sclang_port);
}
