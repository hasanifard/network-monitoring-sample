#include "tins/tins.h"
#include "gtest/gtest.h"
#include "packet-counter.hpp"

#define TCP_PROTOCOL_NUMBER 6

using namespace std;

class PacketCounterTest : public testing::Test {
protected:
  PacketCounter *packet_counter;
  IP ip_layer;
  void SetUp() override
  {
    packet_counter = new PacketCounter();
    ip_layer = IP("172.16.0.1", "192.168.0.1");
  }

  void TearDown() override
  {
    delete packet_counter;
  }
};

TEST_F(PacketCounterTest, AddNewUDPPacket)
{
  ip_layer.protocol(UDP_PROTOCOL_NUMBER);
  EthernetII pkt = EthernetII() / ip_layer;
  
  packet_counter->AddNewPacket(pkt);
  ASSERT_EQ(packet_counter->number_of_udp_packet, 1);

  packet_counter->AddNewPacket(pkt);
  ASSERT_EQ(packet_counter->number_of_udp_packet, 2);
}

TEST_F(PacketCounterTest, AddNewTCPPacket)
{
  ip_layer.protocol(TCP_PROTOCOL_NUMBER);
  EthernetII pkt = EthernetII() / ip_layer;
  
  packet_counter->AddNewPacket(pkt);
  ASSERT_EQ(packet_counter->number_of_udp_packet, 0);
}

TEST_F(PacketCounterTest, PrintPacketCounter)
{
  ip_layer.protocol(UDP_PROTOCOL_NUMBER);
  EthernetII pkt = EthernetII() / ip_layer;

  packet_counter->AddNewPacket(pkt);

  ostringstream os;
  os << *packet_counter;
  ASSERT_STREQ(os.str().c_str(),
               "number of udp packet: 1\n");
}

