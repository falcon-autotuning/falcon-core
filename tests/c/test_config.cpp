#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/config/core/Adjacency_c_api.h"
#include "falcon-core/physics/config/core/Config_c_api.h"
#include "falcon-core/physics/config/core/Group_c_api.h"
#include "falcon-core/physics/device_structures//Impedances_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/device_structures/Connections_c_api.h"
#include "falcon-core/physics/device_structures/Impedance_c_api.h"

class ConfigTest : public ::testing::Test {
protected:
  ConnectionsHandle screening_gates;
  ConnectionsHandle plunger_gates;
  ConnectionsHandle ohmics;
  ConnectionsHandle barrier_gates;
  ConnectionsHandle reservoir_gates;
  MapGnameGroupHandle groups;
  ImpedancesHandle wiring_DC;
  AdjacencyHandle adjacency;
  ConfigHandle handle;

  void SetUp() override {
    screening_gates = Connections_create_empty();
    Connections_push_back(screening_gates,
                          Connection_create_screening_gate(String_wrap("SG1")));
    Connections_push_back(screening_gates,
                          Connection_create_screening_gate(String_wrap("SG2")));

    plunger_gates = Connections_create_empty();
    Connections_push_back(plunger_gates,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(plunger_gates,
                          Connection_create_plunger_gate(String_wrap("P2")));

    ohmics = Connections_create_empty();
    Connections_push_back(ohmics, Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(ohmics, Connection_create_ohmic(String_wrap("O2")));

    barrier_gates = Connections_create_empty();
    Connections_push_back(barrier_gates,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(barrier_gates,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(barrier_gates,
                          Connection_create_barrier_gate(String_wrap("B3")));

    reservoir_gates = Connections_create_empty();
    Connections_push_back(reservoir_gates,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(reservoir_gates,
                          Connection_create_reservoir_gate(String_wrap("R2")));

    // Create a group and map
    ChannelHandle channel = Channel_create(String_wrap("CH1"));
    ConnectionsHandle group_screening = Connections_create_empty();
    Connections_push_back(group_screening,
                          Connection_create_screening_gate(String_wrap("SG1")));
    Connections_push_back(group_screening,
                          Connection_create_screening_gate(String_wrap("SG2")));
    ConnectionsHandle group_reservoir = Connections_create_empty();
    Connections_push_back(group_reservoir,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(group_reservoir,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    ConnectionsHandle group_plunger = Connections_create_empty();
    Connections_push_back(group_plunger,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(group_plunger,
                          Connection_create_plunger_gate(String_wrap("P2")));
    ConnectionsHandle group_barrier = Connections_create_empty();
    Connections_push_back(group_barrier,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(group_barrier,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(group_barrier,
                          Connection_create_barrier_gate(String_wrap("B3")));
    ConnectionsHandle group_order = Connections_create_empty();
    Connections_push_back(group_order,
                          Connection_create_ohmic(String_wrap("O1")));
    Connections_push_back(group_order,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(group_order,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(group_order,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(group_order,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(group_order,
                          Connection_create_plunger_gate(String_wrap("P2")));
    Connections_push_back(group_order,
                          Connection_create_barrier_gate(String_wrap("B3")));
    Connections_push_back(group_order,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    Connections_push_back(group_order,
                          Connection_create_ohmic(String_wrap("O2")));
    GroupHandle group =
        Group_create(channel, 2, group_screening, group_reservoir,
                     group_plunger, group_barrier, group_order);
    GnameHandle gname = Gname_create(String_wrap("group1"));
    groups = MapGnameGroup_create_empty();
    MapGnameGroup_insert(groups, gname, group);

    // Impedances
    wiring_DC = Impedances_create_empty();
    Impedances_push_back(
        wiring_DC, Impedance_create(Connection_create_ohmic(String_wrap("O1")),
                                    1000.0, 1e-12));
    Impedances_push_back(
        wiring_DC, Impedance_create(Connection_create_ohmic(String_wrap("O2")),
                                    1000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_barrier_gate(String_wrap("B1")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_barrier_gate(String_wrap("B2")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_barrier_gate(String_wrap("B3")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_plunger_gate(String_wrap("P1")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_plunger_gate(String_wrap("P2")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_reservoir_gate(String_wrap("R1")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_reservoir_gate(String_wrap("R2")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_screening_gate(String_wrap("SG1")),
                         10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_screening_gate(String_wrap("SG2")),
                         10000.0, 1e-12));

    // Adjacency
    ConnectionsHandle adj_indexes = Connections_create_empty();
    Connections_push_back(adj_indexes,
                          Connection_create_screening_gate(String_wrap("SG1")));
    Connections_push_back(adj_indexes,
                          Connection_create_screening_gate(String_wrap("SG2")));
    Connections_push_back(adj_indexes,
                          Connection_create_plunger_gate(String_wrap("P1")));
    Connections_push_back(adj_indexes,
                          Connection_create_plunger_gate(String_wrap("P2")));
    Connections_push_back(adj_indexes,
                          Connection_create_barrier_gate(String_wrap("B1")));
    Connections_push_back(adj_indexes,
                          Connection_create_barrier_gate(String_wrap("B2")));
    Connections_push_back(adj_indexes,
                          Connection_create_barrier_gate(String_wrap("B3")));
    Connections_push_back(adj_indexes,
                          Connection_create_reservoir_gate(String_wrap("R1")));
    Connections_push_back(adj_indexes,
                          Connection_create_reservoir_gate(String_wrap("R2")));
    int adj_data[81];
    for (int i = 0; i < 81; ++i)
      adj_data[i] = (i % 10 == 0 ? 1 : 0);
    size_t adj_shape[2] = {9, 9};
    adjacency = Adjacency_create(adj_data, adj_shape, 2, adj_indexes);

    handle = Config_create(screening_gates, plunger_gates, ohmics,
                           barrier_gates, reservoir_gates, groups, wiring_DC,
                           adjacency, 0.5, -1.0, 1.0);

    // Clean up handles not owned by the fixture
    Channel_destroy(channel);
    Connections_destroy(group_screening);
    Connections_destroy(group_reservoir);
    Connections_destroy(group_plunger);
    Connections_destroy(group_barrier);
    Connections_destroy(group_order);
    Group_destroy(group);
    Gname_destroy(gname);
    Connections_destroy(adj_indexes);
  }

  void TearDown() override {
    Config_destroy(handle);
    Connections_destroy(screening_gates);
    Connections_destroy(plunger_gates);
    Connections_destroy(ohmics);
    Connections_destroy(barrier_gates);
    Connections_destroy(reservoir_gates);
    MapGnameGroup_destroy(groups);
    Impedances_destroy(wiring_DC);
    Adjacency_destroy(adjacency);
  }
};

TEST_F(ConfigTest, NumUniqueChannels) {
  EXPECT_EQ(Config_num_unique_channels(handle), 1);
}

TEST_F(ConfigTest, GroupsGetter) {
  MapGnameGroupHandle grps = Config_groups(handle);
  EXPECT_EQ(MapGnameGroup_size(grps), 1);
  MapGnameGroup_destroy(grps);
}

TEST_F(ConfigTest, WiringDCGetter) {
  ImpedancesHandle imp = Config_wiring_DC(handle);
  EXPECT_EQ(Impedances_size(imp), 11);
  Impedances_destroy(imp);
}

TEST_F(ConfigTest, ChannelsGetter) {
  ChannelsHandle chs = Config_channels(handle);
  EXPECT_EQ(Channels_size(chs), 1);
  Channels_destroy(chs);
}

TEST_F(ConfigTest, AdjacencyGetter) {
  AdjacencyHandle adj = Config_adjacency(handle);
  EXPECT_EQ(Adjacency_size(adj), 81);
  Adjacency_destroy(adj);
}

TEST_F(ConfigTest, MaxSafeDiffGetter) {
  EXPECT_DOUBLE_EQ(Config_max_safe_diff(handle), 0.5);
}

TEST_F(ConfigTest, MinBoundGetter) {
  EXPECT_DOUBLE_EQ(Config_min_bound(handle), -1.0);
}

TEST_F(ConfigTest, MaxBoundGetter) {
  EXPECT_DOUBLE_EQ(Config_max_bound(handle), 1.0);
}

TEST_F(ConfigTest, SerializationRoundTrip) {
  StringHandle json = Config_to_json_string(handle);
  ConfigHandle loaded = Config_from_json_string(json);
  EXPECT_TRUE(Config_equal(handle, loaded));
  Config_destroy(loaded);
  String_destroy(json);
}

TEST_F(ConfigTest, GetSharedChannelBarrierGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_shared_channel_barrier_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetSharedChannelPlungerGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_shared_channel_plunger_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetSharedChannelReservoirGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_shared_channel_reservoir_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetSharedChannelScreeningGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_shared_channel_screening_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetSharedChannelDotGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_shared_channel_dot_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetSharedBarrierGates) {
  ConnectionsHandle gates = Config_get_shared_barrier_gates(handle);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
}

TEST_F(ConfigTest, GetSharedChannelGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates = Config_get_shared_channel_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 0);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelBarrierGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_isolated_channel_barrier_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 3);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelPlungerGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_isolated_channel_plunger_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelReservoirGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_isolated_channel_reservoir_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelScreeningGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_isolated_channel_screening_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 2);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelDotGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates =
      Config_get_isolated_channel_dot_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 5);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedChannelGates) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  ConnectionsHandle gates = Config_get_isolated_channel_gates(handle, channel);
  EXPECT_EQ(Connections_size(gates), 9);
  Connections_destroy(gates);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, EqualityAndInEqual) {
  ConfigHandle handle2 = Config_create(screening_gates, plunger_gates, ohmics,
                                       barrier_gates, reservoir_gates, groups,
                                       wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_TRUE(Config_equal(handle, handle2));
  EXPECT_FALSE(Config_not_equal(handle, handle2));
  Config_destroy(handle2);
}

TEST_F(ConfigTest, CreateThrowsOnNullArgs) {
  set_last_error(0, nullptr);
  Config_create(nullptr, plunger_gates, ohmics, barrier_gates, reservoir_gates,
                groups, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, nullptr, ohmics, barrier_gates,
                reservoir_gates, groups, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, nullptr, barrier_gates,
                reservoir_gates, groups, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, ohmics, nullptr,
                reservoir_gates, groups, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, ohmics, barrier_gates, nullptr,
                groups, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, ohmics, barrier_gates,
                reservoir_gates, nullptr, wiring_DC, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, ohmics, barrier_gates,
                reservoir_gates, groups, nullptr, adjacency, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_create(screening_gates, plunger_gates, ohmics, barrier_gates,
                reservoir_gates, groups, wiring_DC, nullptr, 0.5, -1.0, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, DestroyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, NumUniqueChannelsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_num_unique_channels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GroupsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_groups(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetAllGroupsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_all_groups(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, SelectGroupThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_select_group(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_select_group(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetDotNumberThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_dot_number(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_dot_number(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetChargeSenseGroupsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_charge_sense_groups(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, OhmicInChargeSensorThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  set_last_error(0, nullptr);
  Config_ohmic_in_charge_sensor(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_ohmic_in_charge_sensor(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, GetAssociatedOhmicThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_reservoir_gate(String_wrap("R1"));
  set_last_error(0, nullptr);
  Config_get_associated_ohmic(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_associated_ohmic(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetCurrentChannelsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_current_channels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetGnameThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_gname(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_gname(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetGroupBarrierGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_barrier_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_barrier_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupPlungerGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_plunger_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_plunger_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupReservoirGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_reservoir_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_reservoir_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupScreeningGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_screening_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_screening_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupDotGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_dot_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_dot_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_get_group_gates(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_group_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetChannelBarrierGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_barrier_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_barrier_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelPlungerGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_plunger_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_plunger_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelReservoirGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_reservoir_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_reservoir_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelScreeningGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_screening_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_screening_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelDotGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_dot_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_dot_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelOhmicsThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_ohmics(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_ohmics(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelOrderNoOhmicsThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_channel_order_no_ohmics(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_channel_order_no_ohmics(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetNumUniqueChannelsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_num_unique_channels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, ReturnChannelsFromGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  set_last_error(0, nullptr);
  Config_return_channels_from_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_return_channels_from_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, ReturnChannelFromGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  set_last_error(0, nullptr);
  Config_return_channel_from_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_return_channel_from_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, OhmicInChannelThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  ChannelHandle ch = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_ohmic_in_channel(nullptr, conn, ch);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_ohmic_in_channel(handle, nullptr, ch);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_ohmic_in_channel(handle, conn, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
  Channel_destroy(ch);
}
TEST_F(ConfigTest, GetDotChannelNeighborsThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_dot_channel_neighbors(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_dot_channel_neighbors(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetBarrierGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_barrier_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetPlungerGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_plunger_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetReservoirGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_reservoir_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetScreeningGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_screening_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetDotGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_dot_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetGateDictThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_gate_dict(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedBarrierGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_barrier_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedPlungerGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_plunger_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedReservoirGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_reservoir_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedScreeningGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_screening_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedDotGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_dot_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedBarrierGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_barrier_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedPlungerGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_plunger_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedReservoirGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_reservoir_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedScreeningGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_screening_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedDotGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_dot_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_shared_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetSharedChannelBarrierGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_barrier_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_barrier_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetSharedChannelPlungerGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_plunger_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_plunger_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetSharedChannelReservoirGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_reservoir_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_reservoir_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetSharedChannelScreeningGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_screening_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_screening_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetSharedChannelDotGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_dot_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_dot_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetSharedChannelGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_shared_channel_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_shared_channel_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelBarrierGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_barrier_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_barrier_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelPlungerGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_plunger_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_plunger_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelReservoirGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_reservoir_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_reservoir_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelScreeningGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_screening_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_screening_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelDotGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_dot_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_dot_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetIsolatedChannelGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_get_isolated_channel_gates(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_isolated_channel_gates(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}

TEST_F(ConfigTest, GetIsolatedBarrierGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_barrier_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedPlungerGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_plunger_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedReservoirGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_reservoir_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedScreeningGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_screening_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedDotGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_dot_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetIsolatedGatesByChannelThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_isolated_gates_by_channel(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GenerateGateRelationsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_generate_gate_relations(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, ScreeningGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_screening_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, PlungerGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_plunger_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, OhmicsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_ohmics(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, BarrierGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_barrier_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, ReservoirGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_reservoir_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, DotGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_dot_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetOhmicThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_ohmic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetBarrierGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_barrier_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetPlungerGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_plunger_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetReservoirGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_reservoir_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetScreeningGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_screening_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetDotGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_dot_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetGateThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_gate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetAllGatesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_all_gates(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, GetAllConnectionsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_all_connections(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, WiringDCThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_wiring_DC(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, ChannelsThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_channels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, AdjacencyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_adjacency(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, MaxSafeDiffThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_max_safe_diff(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, MinBoundThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_min_bound(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, MaxBoundThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_max_bound(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, EqualThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, NotEqualThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_not_equal(nullptr, handle);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_not_equal(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, ToJsonStringThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, FromJsonStringThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
TEST_F(ConfigTest, HasReservoirGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_reservoir_gate(String_wrap("R1"));
  set_last_error(0, nullptr);
  Config_has_reservoir_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_reservoir_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasPlungerGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  set_last_error(0, nullptr);
  Config_has_plunger_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_plunger_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasScreeningGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_screening_gate(String_wrap("SG1"));
  set_last_error(0, nullptr);
  Config_has_screening_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_screening_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasBarrierGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_barrier_gate(String_wrap("B1"));
  set_last_error(0, nullptr);
  Config_has_barrier_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_barrier_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasOhmicThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  set_last_error(0, nullptr);
  Config_has_ohmic(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_ohmic(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  set_last_error(0, nullptr);
  Config_has_gate(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_gate(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasGnameThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  set_last_error(0, nullptr);
  Config_has_gname(nullptr, gname);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_gname(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, HasChannelThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  set_last_error(0, nullptr);
  Config_has_channel(nullptr, channel);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_has_channel(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetImpedanceThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  set_last_error(0, nullptr);
  Config_get_impedance(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Config_get_impedance(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, GetAllGnamesThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Config_get_all_gnames(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

// Happy path for all "getter" and "has_*" functions
TEST_F(ConfigTest, GettersAndHasFunctionsWork) {
  // Use valid handles from the fixture
  // Get a channel, gname, and connection from the group
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  GnameHandle gname = Gname_create(String_wrap("group1"));
  ConnectionHandle gate = Connection_create_barrier_gate(String_wrap("B1"));
  ConnectionHandle ohmic = Connection_create_ohmic(String_wrap("O1"));
  ConnectionHandle reservoir =
      Connection_create_reservoir_gate(String_wrap("R1"));
  ConnectionHandle screening =
      Connection_create_screening_gate(String_wrap("SG1"));
  ConnectionHandle plunger = Connection_create_plunger_gate(String_wrap("P1"));

  // Test all "has_*" functions
  EXPECT_TRUE(Config_has_channel(handle, channel));
  EXPECT_TRUE(Config_has_gname(handle, gname));
  EXPECT_TRUE(Config_has_ohmic(handle, ohmic));
  EXPECT_TRUE(Config_has_gate(handle, gate));
  EXPECT_TRUE(Config_has_barrier_gate(handle, gate));
  EXPECT_TRUE(Config_has_plunger_gate(handle, plunger));
  EXPECT_TRUE(Config_has_reservoir_gate(handle, reservoir));
  EXPECT_TRUE(Config_has_screening_gate(handle, screening));

  // Test all "get_*" functions that return handles
  EXPECT_NE(Config_get_impedance(handle, ohmic), nullptr);
  EXPECT_NE(Config_get_all_gnames(handle), nullptr);
  EXPECT_NE(Config_get_all_groups(handle), nullptr);
  EXPECT_NE(Config_select_group(handle, gname), nullptr);
  EXPECT_NO_THROW(Config_get_dot_number(handle, channel));
  EXPECT_NE(Config_get_charge_sense_groups(handle), nullptr);
  EXPECT_NO_THROW(Config_ohmic_in_charge_sensor(handle, ohmic));
  EXPECT_NE(Config_get_associated_ohmic(handle, reservoir), nullptr);
  EXPECT_NE(Config_get_current_channels(handle), nullptr);
  EXPECT_NE(Config_get_gname(handle, channel), nullptr);
  EXPECT_NE(Config_get_group_barrier_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_group_plunger_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_group_reservoir_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_group_screening_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_group_dot_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_group_gates(handle, gname), nullptr);
  EXPECT_NE(Config_get_channel_barrier_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_plunger_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_reservoir_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_screening_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_dot_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_gates(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_ohmics(handle, channel), nullptr);
  EXPECT_NE(Config_get_channel_order_no_ohmics(handle, channel), nullptr);
  EXPECT_NO_THROW(Config_get_num_unique_channels(handle));
  EXPECT_NE(Config_return_channels_from_gate(handle, gate), nullptr);
  EXPECT_NE(Config_return_channel_from_gate(handle, gate), nullptr);
  EXPECT_NO_THROW(Config_ohmic_in_channel(handle, ohmic, channel));
  EXPECT_NE(Config_get_dot_channel_neighbors(handle, gate), nullptr);
  EXPECT_NE(Config_get_barrier_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_plunger_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_reservoir_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_screening_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_dot_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_gate_dict(handle), nullptr);
  EXPECT_NE(Config_get_isolated_barrier_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_plunger_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_reservoir_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_screening_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_dot_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_barrier_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_plunger_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_reservoir_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_screening_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_dot_gates(handle), nullptr);
  EXPECT_NE(Config_get_shared_gates(handle), nullptr);
  EXPECT_NE(Config_get_isolated_barrier_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_get_isolated_plunger_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_get_isolated_reservoir_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_get_isolated_screening_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_get_isolated_dot_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_get_isolated_gates_by_channel(handle), nullptr);
  EXPECT_NE(Config_generate_gate_relations(handle), nullptr);
  EXPECT_NE(Config_screening_gates(handle), nullptr);
  EXPECT_NE(Config_reservoir_gates(handle), nullptr);
  EXPECT_NE(Config_plunger_gates(handle), nullptr);
  EXPECT_NE(Config_barrier_gates(handle), nullptr);
  EXPECT_NE(Config_ohmics(handle), nullptr);
  EXPECT_NE(Config_dot_gates(handle), nullptr);
  EXPECT_NE(Config_get_ohmic(handle), nullptr);
  EXPECT_NE(Config_get_barrier_gate(handle), nullptr);
  EXPECT_NE(Config_get_plunger_gate(handle), nullptr);
  EXPECT_NE(Config_get_reservoir_gate(handle), nullptr);
  EXPECT_NE(Config_get_screening_gate(handle), nullptr);
  EXPECT_NE(Config_get_dot_gate(handle), nullptr);
  EXPECT_NE(Config_get_gate(handle), nullptr);
  EXPECT_NE(Config_get_all_gates(handle), nullptr);
  EXPECT_NE(Config_get_all_connections(handle), nullptr);

  // Clean up
  Channel_destroy(channel);
  Gname_destroy(gname);
  Connection_destroy(gate);
  Connection_destroy(ohmic);
  Connection_destroy(reservoir);
  Connection_destroy(screening);
  Connection_destroy(plunger);
}
