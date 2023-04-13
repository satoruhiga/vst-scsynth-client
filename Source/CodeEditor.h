#pragma once

#include <JuceHeader.h>

class CodeEditor
    : public juce::Component
      , public juce::KeyListener
    , public juce::CodeDocument::Listener
{
    juce::CodeDocument codeDocument;
    juce::CPlusPlusCodeTokeniser cppTokeniser;
    std::unique_ptr<juce::CodeEditorComponent> codeEditor;

    bool keyPressed(const juce::KeyPress& key, Component* originatingComponent) override
    {
        if (key.getKeyCode() == 13 && key.getModifiers() == juce::ModifierKeys::ctrlModifier)
        {
            if (onCtrlEnter)
                onCtrlEnter();
            return true;
        }

        return false;
    }

public:
    
    std::function<void(void)> onDocumentChanged;
    std::function<void(void)> onCtrlEnter;

    CodeEditor()
        : juce::Component()
    {
        codeDocument.setNewLineCharacters("\n");
        codeDocument.applyChanges("");
        
        codeEditor = std::make_unique<juce::CodeEditorComponent>(codeDocument, &cppTokeniser);

        codeEditor->setSize(getWidth(), getHeight());
        addAndMakeVisible(codeEditor.get());

        codeEditor->setLineNumbersShown(false);
        codeEditor->setColourScheme(getDarkCodeEditorColourScheme());
        codeEditor->setFont(juce::Font(
            juce::Font::getDefaultMonospacedFontName(),
            16,
            juce::Font::plain));
        codeEditor->addKeyListener(this);

        codeDocument.addListener(this);
    }

    void resized() override
    {
        codeEditor->setSize(getWidth(), getHeight());
    }

    void setText(const std::string& code)
    {
        codeDocument.applyChanges(code);
    }

    std::string getText() const
    {
        return codeDocument.getAllContent().toStdString();
    }

    juce::CodeEditorComponent::ColourScheme getDarkCodeEditorColourScheme()
    {
        struct Type
        {
            const char* name;
            juce::uint32 colour;
        };

        const Type types[] =
        {
            {"Error", 0xffe60000},
            {"Comment", 0xff72d20c},
            {"Keyword", 0xffee6f6f},
            {"Operator", 0xffc4eb19},
            {"Identifier", 0xffcfcfcf},
            {"Integer", 0xff42c8c4},
            {"Float", 0xff885500},
            {"String", 0xffbc45dd},
            {"Bracket", 0xff058202},
            {"Punctuation", 0xffcfbeff},
            {"Preprocessor Text", 0xfff8f631}
        };

        juce::CodeEditorComponent::ColourScheme cs;

        for (auto& t : types)
            cs.set(t.name, juce::Colour(t.colour));

        return cs;
    }

    void codeDocumentTextInserted (const juce::String& newText, int insertIndex) override
    {
        if (onDocumentChanged)
            onDocumentChanged();
    }
    
    void codeDocumentTextDeleted (int startIndex, int endIndex) override
    {
        if (onDocumentChanged)
            onDocumentChanged();
    }
};
