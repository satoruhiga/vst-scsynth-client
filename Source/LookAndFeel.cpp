#include "LookAndFeel.h"

void LookAndFeel::apply(juce::TextEditor* o)
{
    o->setColour(juce::TextEditor::outlineColourId,
                         juce::Colour(0x00000000));
    o->setColour(juce::TextEditor::focusedOutlineColourId,
                         juce::Colour(0x00000000));
    o->setColour(juce::TextEditor::shadowColourId,
                         juce::Colour(0x00000000));
}

void LookAndFeel::apply(juce::TextButton* o)
{
    o->setColour(juce::TextButton::buttonColourId,
                         juce::Colour(0xff42a2c8));
    o->setColour(juce::TextButton::textColourOffId,
                     juce::Colour(0xff000000));

    o->setColour(juce::ComboBox::outlineColourId,
                         juce::Colour(0x00000000));
    o->setColour(juce::ComboBox::focusedOutlineColourId,
                         juce::Colour(0x00000000));
}

void LookAndFeel::apply(juce::ComboBox* o)
{
    o->setColour(juce::ComboBox::outlineColourId,
                     juce::Colour(0x00000000));
    o->setColour(juce::ComboBox::focusedOutlineColourId,
                         juce::Colour(0x00000000));
}
