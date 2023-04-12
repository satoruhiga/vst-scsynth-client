#include "OSCClient.h"

#include "oscpkt.hh"

int OSCClient::requestClientID()
{
    juce::OSCMessage message(juce::String("/notify"), 1);
    scsynthSender.send(message);
    
    int cid = -1;
    
    if (scsynthSocket.waitUntilReady(true, 1000))
    {
        static uint8_t data[4096];
        while (int num_read = scsynthSocket.read(data, 4096, false))
        {
            oscpkt::PacketReader pr;
            pr.init(data, num_read);

            if (pr.isOk())
            {
                oscpkt::Message* msg = pr.popMessage();

                if (msg->match("/done").isOk())
                {
                    std::string v0;
                    int v1;

                    msg->arg()
                       .popStr(v0)
                       .popInt32(v1);

                    if (v0 == "/notify")
                    {
                        cid = v1;
                        break;
                    }
                }
            }
        }
    }

    return cid;
}
