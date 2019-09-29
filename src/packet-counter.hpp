#ifndef _PACKET_COUNTER_HH
#define _PACKET_COUNTER_HH

#include <iostream>
#include "gtest/gtest.h"
#include "tins/tins.h"

#define UDP_PROTOCOL_NUMBER 17

using namespace std;
using namespace Tins;

class PacketCounter {
  size_t number_of_udp_packet;

  FRIEND_TEST(PacketCounterTest, AddNewUDPPacket);
  FRIEND_TEST(PacketCounterTest, AddNewTCPPacket);

public:
  PacketCounter(): number_of_udp_packet(0) {}

  void AddNewPacket(const PDU &pdu)
  {
    const IP &ip_layer = pdu.rfind_pdu<IP>();
    if (ip_layer.protocol() == UDP_PROTOCOL_NUMBER)
      this->number_of_udp_packet++;
  }

  friend ostream& operator << (ostream& os, const PacketCounter& packet_counter);

};

ostream& operator<< (ostream& os, const PacketCounter& packet_counter) {
  os << "number of udp packet: " << packet_counter.number_of_udp_packet << '\n';
  return os;
}

#endif
