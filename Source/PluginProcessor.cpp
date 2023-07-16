/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

void ScsynthclientAudioProcessor::initPlugin()
{
    if (!inited)
    {
        struct Callback
        {
            static void* callback(void* userData)
            {
                auto self = static_cast<ScsynthclientAudioProcessor*>(userData);

                auto editor = dynamic_cast<ScsynthclientAudioProcessorEditor*>(self->getActiveEditor());
                if (editor)
                {
                    auto ret = self->appController.initPlugin(editor);
                    if (ret)
                        self->inited = true;
                }

                return nullptr;
            }
        };

        juce::MessageManager* mm = juce::MessageManager::getInstance();
        mm->callFunctionOnMessageThread(Callback::callback, this);
    }
}

//==============================================================================
ScsynthclientAudioProcessor::ScsynthclientAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
        )
      , valueTreeState(*this, nullptr, juce::Identifier("scsynth-client"),
                       {
                           std::make_unique<juce::AudioParameterFloat>(
                               "master_vel", "Master Velocity", 0.0f, 2.0f, 1.0f),
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
                           std::make_unique<juce::AudioParameterFloat>(
                               "arg9", "Arg9", 0.0f, 1.0f, 0.0f),
                       })
{
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
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int ScsynthclientAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ScsynthclientAudioProcessor::setCurrentProgram(int index)
{
}

const juce::String ScsynthclientAudioProcessor::getProgramName(int index)
{
    return {};
}

void ScsynthclientAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

//==============================================================================
void ScsynthclientAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void ScsynthclientAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ScsynthclientAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    return true;
}
#endif

void ScsynthclientAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    initPlugin();    
    appController.processMidiBuffer(midiMessages);

    const int nout = getTotalNumOutputChannels();
    for (int i = 0; i < nout; ++i)
    {
        float* ptr = buffer.getWritePointer(i);

        for (int x = 0; x < buffer.getNumSamples(); x++)
        {
            *ptr++ = 0.0f;
        }
    }
}

//==============================================================================

bool ScsynthclientAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ScsynthclientAudioProcessor::createEditor()
{
    return new ScsynthclientAudioProcessorEditor(*this);
}

//==============================================================================

void ScsynthclientAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    auto state = valueTreeState.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());

    appController.getStateInformation(xml);

    copyXmlToBinary(*xml, destData);
}

void ScsynthclientAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (!xml) return;

    if (xml->hasTagName(valueTreeState.state.getType()))
        valueTreeState.replaceState(juce::ValueTree::fromXml(*xml));

    appController.setStateInformation(xml);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ScsynthclientAudioProcessor();
}
