#pragma once

#include <JuceHeader.h>

class OSCClient
{
    const std::string targetHost = "127.0.0.1";
    
    juce::DatagramSocket scsynthSocket;
    juce::OSCSender scsynthSender;
    juce::OSCSender sclangSender;

    int client_id = -1;

    int requestClientID();
    
public:
    
    OSCClient(int scsynth_port, int sclang_port)
    {
        scsynthSocket.bindToPort(0);
        scsynthSocket.setEnablePortReuse(true);

        scsynthSender.connectToSocket(scsynthSocket, targetHost, scsynth_port);
        sclangSender.connect(targetHost, sclang_port);

        client_id = requestClientID();
    }
    
    virtual ~OSCClient()
    {
        {
            juce::OSCMessage message(juce::String("/notify"), 0);
            scsynthSender.send(message);
            scsynthSocket.waitUntilReady(true, 3000);
        }

        sclangSender.disconnect();
        scsynthSender.disconnect();
        scsynthSocket.shutdown();
    }

    int getClientID() const { return client_id; }
    
    void sendToSCSynth(juce::OSCMessage& message)
    {
        scsynthSender.send(message);
    }
    void sendToSCSynth(juce::OSCBundle& bundle)
    {
        scsynthSender.send(bundle);
    }

    void sendToSCLang(juce::OSCMessage& message)
    {
        sclangSender.send(message);
    }
    void sendToSCLang(juce::OSCBundle& bundle)
    {
        sclangSender.send(bundle);
    }
};