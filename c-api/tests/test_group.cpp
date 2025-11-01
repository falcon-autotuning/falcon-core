#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"

class GroupTest : public ::testing::Test {
 protected:
  ChannelHandle     channel;
  int               num_dots;
  ConnectionsHandle screening;
  ConnectionsHandle reservoir;
  ConnectionsHandle plunger;
  ConnectionsHandle barrier;
  ConnectionsHandle order;
  GroupHandle       handle;

  void SetUp() override {
    channel   = Channel_create(String_wrap("test"));
    num_dots  = 2;
    screening = Connections_create_empty();
    Connections_push_back(screening,
                          Connection_create_screening_gate(String_wrap("s1")));
    Connections_push_back(screening,
                          Connection_create_screening_gate(String_wrap("s2")));
    reservoir = Connections_create_empty();
    Connections_push_back(reservoir,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(reservoir,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    plunger = Connections_create_empty();
    Connections_push_back(plunger,
                          Connection_create_plunger_gate(String_wrap("P1")));
    barrier = Connections_create_empty();
    Connections_push_back(barrier,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(barrier,
                          Connection_create_barrier_gate(String_wrap("B2")));
    order = Connections_create_empty();
    Connections_push_back(order, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(order,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(order,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(order,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(order,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(order,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    Connections_push_back(order, Connection_create_ohmic(String_wrap("O2")));
    handle = Group_create(
        channel, num_dots, screening, reservoir, plunger, barrier, order);
  }

  void TearDown() override {
    Group_destroy(handle);
    Channel_destroy(channel);
    Connections_destroy(screening);
    Connections_destroy(reservoir);
    Connections_destroy(plunger);
    Connections_destroy(barrier);
    Connections_destroy(order);
  }
};

TEST_F(GroupTest, NameAndNumDots) {
  ChannelHandle name = Group_name(handle);
  EXPECT_STREQ(Channel_name(name)->raw, "test");
  EXPECT_EQ(Group_num_dots(handle), num_dots);
  Channel_destroy(name);
}

TEST_F(GroupTest, ScreeningGatesGetter) {
  ConnectionsHandle gates = Group_screening_gates(handle);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
}

TEST_F(GroupTest, ReservoirGatesGetter) {
  ConnectionsHandle gates = Group_reservoir_gates(handle);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
}

TEST_F(GroupTest, PlungerGatesGetter) {
  ConnectionsHandle gates = Group_plunger_gates(handle);
  EXPECT_EQ(Connections_size(gates), 1);
  Connections_destroy(gates);
}

TEST_F(GroupTest, BarrierGatesGetter) {
  ConnectionsHandle gates = Group_barrier_gates(handle);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
}

TEST_F(GroupTest, OrderGetter) {
  GateGeometryArray1DHandle ord = Group_order(handle);
  EXPECT_FALSE(ord == nullptr);
  GateGeometryArray1D_destroy(ord);
}

TEST_F(GroupTest, OhmicsGetter) {
  ConnectionsHandle ohmics = Group_ohmics(handle);
  EXPECT_EQ(Connections_size(ohmics), 2);
  Connections_destroy(ohmics);
}

TEST_F(GroupTest, DotGatesGetter) {
  ConnectionsHandle dots = Group_dot_gates(handle);
  EXPECT_EQ(Connections_size(dots), 3);
  Connections_destroy(dots);
}

TEST_F(GroupTest, HasChannel) {
  EXPECT_TRUE(Group_has_channel(handle, channel));
  ChannelHandle other = Channel_create(String_wrap("other"));
  EXPECT_FALSE(Group_has_channel(handle, other));
  Channel_destroy(other);
}

TEST_F(GroupTest, IsChargeSensor) {
  EXPECT_FALSE(Group_is_charge_sensor(handle));
  GroupHandle handle2 =
      Group_create(channel, 1, screening, reservoir, plunger, barrier, order);
  EXPECT_TRUE(Group_is_charge_sensor(handle2));
  Group_destroy(handle2);
}

TEST_F(GroupTest, GetAllChannelGates) {
  ConnectionsHandle gates = Group_get_all_channel_gates(handle);
  EXPECT_GT(Connections_size(gates), 0);
  Connections_destroy(gates);
}

TEST_F(GroupTest, SerializationRoundTrip) {
  StringHandle json   = Group_to_json_string(handle);
  GroupHandle  loaded = Group_from_json_string(json);
  EXPECT_TRUE(Group_equal(handle, loaded));
  Group_destroy(loaded);
  String_destroy(json);
}

TEST_F(GroupTest, EqualityAndInequality) {
  GroupHandle handle2 = Group_create(
      channel, num_dots, screening, reservoir, plunger, barrier, order);
  EXPECT_TRUE(Group_equal(handle, handle2));
  EXPECT_FALSE(Group_not_equal(handle, handle2));
  Group_destroy(handle2);
}
