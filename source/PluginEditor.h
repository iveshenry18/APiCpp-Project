/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"
#include <juce_audio_processors/juce_audio_processors.h>

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

//==============================================================================
/**
*/
class PluginEditor : public juce::AudioProcessorEditor, public juce::AudioProcessorValueTreeState::Listener
{
public:
    PluginEditor (PluginProcessor&);
    ~PluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void parameterChanged (const juce::String& parameterID, float newValue) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor& audioProcessor;
    void updateTimeBaseAttachment();

    juce::Slider mBasisNoteSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mBasisNoteSliderAttachment;
    juce::Label mBasisNoteLabel;
    juce::Slider mTimeBaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mTimeBaseSliderAttachment;
    juce::Label mTimeBaseLabel;
    juce::ToggleButton mSyncTimeToggle;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> mSyncTimeToggleAttachment;
    juce::ToggleButton mLearnBasisNoteToggle;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> mLearnBasisNoteToggleAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
