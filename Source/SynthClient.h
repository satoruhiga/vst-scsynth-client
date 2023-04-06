#pragma once

#include <JuceHeader.h>
#include "OSCClient.h"

class SynthClient
{
    const int NODES_PAR_CLIENT = 1000;
    const int NODE_START_INDEX = 10000;

    int note_id = 0;
    
    std::shared_ptr<OSCClient> oscClient;
    
public:

    SynthClient(int scsynth_port, int sclang_port)
    {
        oscClient = std::make_shared<OSCClient>(scsynth_port, sclang_port);
    }
    
    virtual ~SynthClient()
    {
        oscClient.reset();
    }

    int getNextNodeID()
    {
        int nid = note_id;
        note_id += 1;
        note_id %= NODES_PAR_CLIENT;

        return NODE_START_INDEX + nid + oscClient->getClientID() * NODES_PAR_CLIENT;
    }
};