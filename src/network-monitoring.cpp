#include <signal.h>
#include <iostream>
#include "tins/tins.h"
#include "packet-counter.hpp"

using namespace Tins;
using namespace std;

PacketCounter packet_counter;

void signal_handler(int s)
{
  cout << packet_counter;
  exit(1);
}

bool callback(const PDU &pdu) {

    packet_counter.AddNewPacket(pdu);
    return true;
}
 
int main(int argc, char * argv[]) {
    if (argc != 2)
    {
        cout << "./test interface_name" << endl;
        return 0;
    }

    signal (SIGINT,signal_handler);

    Sniffer sniffer(argv[1]);
    sniffer.sniff_loop(callback);
}
