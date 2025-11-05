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

TEST_F(GroupTest, GetOhmic) {
  ConnectionHandle ohmic = Group_get_ohmic(handle);
  EXPECT_TRUE(Connection_is_ohmic(ohmic));
  EXPECT_STREQ(Connection_name(ohmic)->raw, "O1");
  Connection_destroy(ohmic);
}

TEST_F(GroupTest, GetPlunger) {
  ConnectionHandle plunger = Group_get_plunger_gate(handle);
  EXPECT_TRUE(Connection_is_plunger_gate(plunger));
  EXPECT_STREQ(Connection_name(plunger)->raw, "P1");
  Connection_destroy(plunger);
}

TEST_F(GroupTest, GetReservoir) {
  ConnectionHandle reservoir = Group_get_reservoir_gate(handle);
  EXPECT_TRUE(Connection_is_reservoir_gate(reservoir));
  EXPECT_STREQ(Connection_name(reservoir)->raw, "R1");
  Connection_destroy(reservoir);
}

TEST_F(GroupTest, GetBarrier) {
  ConnectionHandle barrier = Group_get_barrier_gate(handle);
  EXPECT_TRUE(Connection_is_barrier_gate(barrier));
  EXPECT_STREQ(Connection_name(barrier)->raw, "B1");
  Connection_destroy(barrier);
}

TEST_F(GroupTest, GetScreening) {
  ConnectionHandle screening = Group_get_screening_gate(handle);
  EXPECT_TRUE(Connection_is_screening_gate(screening));
  EXPECT_STREQ(Connection_name(screening)->raw, "s1");
  Connection_destroy(screening);
}

TEST_F(GroupTest, GetDot) {
  ConnectionHandle dot = Group_get_dot_gate(handle);
  EXPECT_TRUE(Connection_is_dot_gate(dot));
  EXPECT_STREQ(Connection_name(dot)->raw, "P1");
  Connection_destroy(dot);
}

TEST_F(GroupTest, GetGate) {
  ConnectionHandle gate = Group_get_gate(handle);
  EXPECT_TRUE(Connection_is_gate(gate));
  EXPECT_STREQ(Connection_name(gate)->raw, "P1");
  Connection_destroy(gate);
}

TEST_F(GroupTest, GetAllGates) {
  ConnectionsHandle gates = Group_get_all_gates(handle);
  EXPECT_EQ(Connections_size(gates), 7);
  Connections_destroy(gates);
}

TEST_F(GroupTest, GetAllConnections) {
  ConnectionsHandle conns = Group_get_all_connections(handle);
  EXPECT_EQ(Connections_size(conns), 9);
  Connections_destroy(conns);
}

TEST_F(GroupTest, HasOhmic) {
  EXPECT_TRUE(
      Group_has_ohmic(handle, Connection_create_ohmic(String_wrap("O1"))));
}

TEST_F(GroupTest, HasGate) {
  EXPECT_TRUE(Group_has_gate(
      handle, Connection_create_barrier_gate(String_wrap("B2"))));
}

TEST_F(GroupTest, HasBarrier) {
  EXPECT_TRUE(Group_has_barrier_gate(
      handle, Connection_create_barrier_gate(String_wrap("B1"))));
}

TEST_F(GroupTest, HasPlunger) {
  EXPECT_TRUE(Group_has_plunger_gate(
      handle, Connection_create_plunger_gate(String_wrap("P1"))));
}

TEST_F(GroupTest, HasReservoir) {
  EXPECT_TRUE(Group_has_reservoir_gate(
      handle, Connection_create_reservoir_gate(String_wrap("R2"))));
}

TEST_F(GroupTest, HasScreening) {
  EXPECT_TRUE(Group_has_screening_gate(
      handle, Connection_create_screening_gate(String_wrap("s2"))));
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

TEST_F(GroupTest, CreateThrowsOnNullArguments) {
  EXPECT_THROW(
      Group_create(
          nullptr, num_dots, screening, reservoir, plunger, barrier, order),
      std::invalid_argument);
  EXPECT_THROW(
      Group_create(
          channel, num_dots, nullptr, reservoir, plunger, barrier, order),
      std::invalid_argument);
  EXPECT_THROW(
      Group_create(
          channel, num_dots, screening, nullptr, plunger, barrier, order),
      std::invalid_argument);
  EXPECT_THROW(
      Group_create(
          channel, num_dots, screening, reservoir, nullptr, barrier, order),
      std::invalid_argument);
  EXPECT_THROW(
      Group_create(
          channel, num_dots, screening, reservoir, plunger, nullptr, order),
      std::invalid_argument);
  EXPECT_THROW(
      Group_create(
          channel, num_dots, screening, reservoir, plunger, barrier, nullptr),
      std::invalid_argument);
}

TEST_F(GroupTest, DestroyThrowsOnNullHandle) {
  EXPECT_THROW(Group_destroy(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, NameThrowsOnNullHandle) {
  EXPECT_THROW(Group_name(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, NumDotsThrowsOnNullHandle) {
  EXPECT_THROW(Group_num_dots(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, OrderThrowsOnNullHandle) {
  EXPECT_THROW(Group_order(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasChannelThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_channel(nullptr, channel), std::invalid_argument);
  EXPECT_THROW(Group_has_channel(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, IsChargeSensorThrowsOnNullHandle) {
  EXPECT_THROW(Group_is_charge_sensor(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, GetAllChannelGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_all_channel_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, ScreeningGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_screening_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, ReservoirGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_reservoir_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, PlungerGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_plunger_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, BarrierGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_barrier_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, OhmicsThrowsOnNullHandle) {
  EXPECT_THROW(Group_ohmics(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, DotGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_dot_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, OhmicThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_ohmic(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, BarrierGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_barrier_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, PlungerGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_plunger_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, ReservoirGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_reservoir_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, ScreeningGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_screening_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, DotGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_dot_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, GateThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_gate(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, AllGatesThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_all_gates(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, AllConnectionsThrowsOnNullHandle) {
  EXPECT_THROW(Group_get_all_connections(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasOhmicThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_ohmic(nullptr, String_wrap("O1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_ohmic(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_gate(nullptr, String_wrap("G1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_gate(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasBarrierGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_barrier_gate(nullptr, String_wrap("B1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_barrier_gate(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasPlungerGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_plunger_gate(nullptr, String_wrap("P1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_plunger_gate(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, HasReservoirGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_reservoir_gate(nullptr, String_wrap("R1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_reservoir_gate(handle, nullptr),
               std::invalid_argument);
}

TEST_F(GroupTest, HasScreeningGateThrowsOnNullHandle) {
  EXPECT_THROW(Group_has_screening_gate(nullptr, String_wrap("S1")),
               std::invalid_argument);
  EXPECT_THROW(Group_has_screening_gate(handle, nullptr),
               std::invalid_argument);
}

TEST_F(GroupTest, EqualityThrowsOnNullHandle) {
  EXPECT_THROW(Group_equal(nullptr, handle), std::invalid_argument);
  EXPECT_THROW(Group_equal(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, InequalityThrowsOnNullHandle) {
  EXPECT_THROW(Group_not_equal(nullptr, handle), std::invalid_argument);
  EXPECT_THROW(Group_not_equal(handle, nullptr), std::invalid_argument);
}

TEST_F(GroupTest, ToJsonStringThrowsOnNullHandle) {
  EXPECT_THROW(Group_to_json_string(nullptr), std::invalid_argument);
}

TEST_F(GroupTest, FromJsonStringThrowsOnNullJson) {
  EXPECT_THROW(Group_from_json_string(nullptr), std::invalid_argument);
}
