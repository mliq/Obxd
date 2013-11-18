/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Engine\Params.h"
//==============================================================================
#define S(T) (juce::String(T))
Random rnd;
ObxdAudioProcessor::ObxdAudioProcessor()
{
	parameters = ObxdParams();
	synth = new SynthEngine();
	initAllParams();
	rnd = Random();
}

ObxdAudioProcessor::~ObxdAudioProcessor()
{
	delete synth;
}
//==============================================================================
void ObxdAudioProcessor::initAllParams()
{
	for(int i = 0 ; i < PARAM_COUNT;i++)
		setParameter(i,parameters.values[i]);
}
//==============================================================================
const String ObxdAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

int ObxdAudioProcessor::getNumParameters()
{
	return PARAM_COUNT;
}

float ObxdAudioProcessor::getParameter (int index)
{
	return parameters.values[index];
}

void ObxdAudioProcessor::setParameter (int index, float newValue)
{
	parameters.values[index] = newValue;
	switch(index)
	{
	case OSCQuantize:
		synth->processPitchQuantization(newValue);
		break;
	case VOICE_COUNT:
		synth->setVoiceCount(newValue);
		break;
	case FILTER_DRIVE:
		synth->processFilterDrive(newValue);
		break;
	case FILTER_WARM:
		synth->processOversampling(newValue);
		break;
	case BENDOSC2:
		synth->procPitchWheelOsc2Only(newValue);
		break;
	case BENDRANGE:
		synth->procPitchWheelAmount(newValue);
		break;
	case NOISEMIX:
		synth->processNoiseMix(newValue);
		break;
	case OCTAVE:
		synth->processOctave(newValue);
		break;
	case TUNE:
		synth->processTune(newValue);
		break;
	case BRIGHTNESS:
		synth->processBrightness(newValue);
		break;
	case MULTIMODE:
		synth->processMultimode(newValue);
		break;
	case LFOFREQ:
		synth->processLfoFrequency(newValue);
		break;
	case LFO1AMT:
		synth->processLfoAmt1(newValue);
		break;
	case LFO2AMT:
		synth->processLfoAmt2(newValue);
		break;
	case LFOSINWAVE:
		synth->processLfoSine(newValue);
		break;
	case LFOSQUAREWAVE:
		synth->processLfoSquare(newValue);
		break;
	case LFOSHWAVE:
		synth->processLfoSH(newValue);
		break;
	case LFOFILTER:
		synth->processLfoFilter(newValue);
		break;
	case LFOOSC1:
		synth->processLfoOsc1(newValue);
		break;
	case LFOOSC2:
		synth->processLfoOsc2(newValue);
		break;
	case LFOPW1:
		synth->processLfoPw1(newValue);
		break;
	case LFOPW2:
		synth->processLfoPw2(newValue);
		break;
	case PORTADER:
		synth->processPortamentoDetune(newValue);
		break;
	case FILTERDER:
		synth->processFilterDetune(newValue);
		break;
	case ENVDER:
		synth->processEnvelopeDetune(newValue);
		break;
	case XMOD:
		synth->processOsc2Xmod(newValue);
		break;
	case OSC2HS:
		synth->processOsc2HardSync(newValue);
		break;
	case OSC2P:
		synth->processOsc2Pitch(newValue);
		break;
	case OSC1P:
		synth->processOsc1Pitch(newValue);
		break;
	case PORTAMENTO:
		synth->processPortamento(newValue);
		break;
	case UNISON:
		synth->processUnison(newValue);
		break;
	case FLT_KF:
		synth->processFilterKeyFollow(newValue);
		break;
	case OSC1MIX:
		synth->processOsc1Mix(newValue);
		break;
	case OSC2MIX:
		synth->processOsc2Mix(newValue);
		break;
	case PW:
		synth->processPulseWidth(newValue);
		break;
	case OSC1W:
		synth->processOsc1Waveform(newValue);
		break;
	case OSC2W:
		synth->processOsc2Waveform(newValue);
		break;
	case VOLUME:
		synth->processVolume(newValue);
		break;
	case UDET:
		synth->processDetune(newValue);
		break;
	case OSC2_DET:
		synth->processOsc2Det(newValue);
		break;
	case CUTOFF:
		synth->processCutoff(newValue);
		break;
	case RESONANCE:
		synth->processResonance(newValue);
		break;
	case ENVELOPE_AMT:
		synth->processFilterEnvelopeAmt(newValue);
		break;
	case LATK:
		synth->processLoudnessEnvelopeAttack(newValue);
		break;
	case LDEC:
		synth->processLoudnessEnvelopeDecay(newValue);
		break;
	case LSUS:
		synth->processLoudnessEnvelopeSustain(newValue);
		break;
	case LREL:
		synth->processLoudnessEnvelopeRelease(newValue);
		break;
	case FATK:
		synth->processFilterEnvelopeAttack(newValue);
		break;
	case FDEC:
		synth->processFilterEnvelopeDecay(newValue);
		break;
	case FSUS:
		synth->processFilterEnvelopeSustain(newValue);
		break;
	case FREL:
		synth->processFilterEnvelopeRelease(newValue);
		break;
	case PAN1:
		synth->processPan(newValue,1);
		break;
	case PAN2:
		synth->processPan(newValue,2);
		break;
	case PAN3:
		synth->processPan(newValue,3);
		break;
	case PAN4:
		synth->processPan(newValue,4);
		break;
	case PAN5:
		synth->processPan(newValue,5);
		break;
	case PAN6:
		synth->processPan(newValue,6);
		break;
	case PAN7:
		synth->processPan(newValue,7);
		break;
	case PAN8:
		synth->processPan(newValue,8);
		break;
	}
}
const String ObxdAudioProcessor::getParameterName (int index)
{
	switch(index)
	{
	case OSCQuantize:
		return S("PitchQuant");
	case VOICE_COUNT:
		return S("VoiceCount");
	case FILTER_DRIVE:
		return S("FilterDrive");
	case FILTER_WARM:
		return S("Filter_Warm");
	case BENDRANGE:
		return S("BendRange");
	case BENDOSC2:
		return S("BendOsc2Only");
	case OCTAVE:
		return S("Octave");
	case TUNE:
		return S("Tune");
	case BRIGHTNESS:
		return S("Brightness");
	case NOISEMIX:
		return S("NoiseMix");
	case OSC1MIX:
		return S("Osc1Mix");
	case OSC2MIX:
		return S("Osc2Mix");
	case MULTIMODE:
		return S("Multimode");
	case LFOSHWAVE:
		return S("LfoSampleHoldWave");
	case LFOSINWAVE:
		return S("LfoSineWave");
	case LFOSQUAREWAVE:
		return S("LfoSquareWave");
	case LFO1AMT:
		return S("LfoAmount1");
	case LFO2AMT:
		return S("LfoAmount2");
	case LFOFILTER:
		return S("LfoFilter");
	case LFOOSC1:
		return S("LfoOsc1");
	case LFOOSC2:
		return S("LfoOsc2");
	case LFOFREQ:
		return S("LfoFrequency");
	case LFOPW1:
		return S("LfoPw1");
	case LFOPW2:
		return S("LfoPw2");
	case PORTADER:
		return S("PortamentoDetune");
	case FILTERDER:
		return S("FilterDetune");
	case ENVDER:
		return S("EnvelopeDetune");
	case PAN1:
		return S("Pan1");
	case PAN2:
		return S("Pan2");
	case PAN3:
		return S("Pan3");
	case PAN4:
		return S("Pan4");
	case PAN5:
		return S("Pan5");
	case PAN6:
		return S("Pan6");
	case PAN7:
		return S("Pan7");
	case PAN8:
		return S("Pan8");
	case XMOD:
		return S("Xmod");
	case OSC2HS:
		return S("Osc2HardSync");
	case OSC1P:
		return S("Osc1Pitch");
	case OSC2P:
		return S("Osc2Pitch");
	case PORTAMENTO:
		return S("Portamento");
	case UNISON:
		return S("Unison");
	case FLT_KF:
		return S("FilterKeyFollow");
	case PW:
		return S("PulseWidth");
	case OSC2W:
		return S("Osc2Wave");
	case OSC1W:
		return S("Osc1Wave");
	case VOLUME:
		return S("Volume");
	case UDET:
		return S("VoiceDetune");
	case OSC2_DET:
		return S("Oscillator2detune");
	case CUTOFF:
		return S("Cutoff");
	case RESONANCE:
		return S("Resonance");
	case ENVELOPE_AMT:
		return S("FilterEnvAmount");
	case LATK:
		return S("Attack");
	case LDEC:
		return S("Decay");
	case LSUS:
		return S("Sustain");
	case LREL:
		return S("Release");
	case FATK:
		return S("FilterAttack");
	case FDEC:
		return S("FilterDecay");
	case FSUS:
		return S("FilterSustain");
	case FREL:
		return S("FilterRelease");
	}
	return String::empty;
}

const String ObxdAudioProcessor::getParameterText (int index)
{
	return String(parameters.values[index],2);
}

const String ObxdAudioProcessor::getInputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

const String ObxdAudioProcessor::getOutputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

bool ObxdAudioProcessor::isInputChannelStereoPair (int index) const
{
	return true;
}

bool ObxdAudioProcessor::isOutputChannelStereoPair (int index) const
{
	return true;
}

bool ObxdAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool ObxdAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool ObxdAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double ObxdAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}
int ObxdAudioProcessor::getNumPrograms()
{
	return 0;
}

int ObxdAudioProcessor::getCurrentProgram()
{
	return 0;
}

void ObxdAudioProcessor::setCurrentProgram (int index)
{

}

const String ObxdAudioProcessor::getProgramName (int index)
{
	return String::empty;
}

void ObxdAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ObxdAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..
	nextMidi= new MidiMessage(0xF0);
	midiMsg = new MidiMessage(0xF0);
	synth->setSampleRate(sampleRate);

}

void ObxdAudioProcessor::releaseResources()
{

}
void ObxdAudioProcessor::processMidiPerSample(MidiBuffer::Iterator* iter,const int samplePos)
{
	while (getNextEvent(iter, samplePos))
	{
		if(midiMsg->isNoteOn())
		{
			synth->procNoteOn(midiMsg->getNoteNumber());
		}
		if (midiMsg->isNoteOff())
		{
			synth->procNoteOff(midiMsg->getNoteNumber());
		}
		if(midiMsg->isPitchWheel())
		{
			// [0..16383] center = 8192;
			synth->procPitchWheel((midiMsg->getPitchWheelValue()-8192) / 8192.0);
		}
	}
}
bool ObxdAudioProcessor::getNextEvent(MidiBuffer::Iterator* iter,const int samplePos)
{
	if (hasMidiMessage && midiEventPos <= samplePos)
	{
		*midiMsg = *nextMidi;
		hasMidiMessage = iter->getNextEvent(*nextMidi, midiEventPos);
		return true;
	} 
	return false;
}
void ObxdAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	MidiBuffer::Iterator ppp(midiMessages);
	hasMidiMessage = ppp.getNextEvent(*nextMidi,midiEventPos);
	int samplePos = 0;
	int numSamples = buffer.getNumSamples();
	float* channelData1 = buffer.getSampleData(0);
	float* channelData2 = buffer.getSampleData(1);
	while (samplePos < numSamples)
	{
		processMidiPerSample(&ppp,samplePos);

		synth->processSample(channelData1+samplePos,channelData2+samplePos);

		samplePos++;
	}
}

//==============================================================================
bool ObxdAudioProcessor::hasEditor() const
{
	return false; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ObxdAudioProcessor::createEditor()
{
	// return new ObxdAudioProcessorEditor (this);
	return NULL;
}

//==============================================================================
void ObxdAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	//XmlElement* const xmlState = getXmlFromBinary(;
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
	XmlElement xmlState = XmlElement("Datsounds");
		 for(int i = 0 ; i < PARAM_COUNT;i++)
		 {
			 xmlState.setAttribute(String(i), parameters.values[i]);
		 }
		 copyXmlToBinary(xmlState,destData);
}

void ObxdAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
	XmlElement* const xmlState = getXmlFromBinary(data,sizeInBytes);
	for(int i = 0 ; i <PARAM_COUNT;i++)
	{
		setParameter(i,xmlState->getDoubleAttribute(String(i),0.0));
	}
	delete xmlState;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new ObxdAudioProcessor();
}
