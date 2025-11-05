#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"
#include "falcon_core/physics/config/core/Config_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"
#include "falcon_core/physics/device_structures//Impedances_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/physics/device_structures/Impedance_c_api.h"

class ConfigTest : public ::testing::Test {
 protected:
  ConnectionsHandle        screening_gates;
  ConnectionsHandle        plunger_gates;
  ConnectionsHandle        ohmics;
  ConnectionsHandle        barrier_gates;
  ConnectionsHandle        reservoir_gates;
  MapGnameGroupHandle      groups;
  ImpedancesHandle         wiring_DC;
  VoltageConstraintsHandle constraints;
  ConfigHandle             handle;

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
    ChannelHandle     channel         = Channel_create(String_wrap("CH1"));
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
    GroupHandle group = Group_create(channel,
                                     2,
                                     group_screening,
                                     group_reservoir,
                                     group_plunger,
                                     group_barrier,
                                     group_order);
    GnameHandle gname = Gname_create(String_wrap("group1"));
    groups            = MapGnameGroup_create_empty();
    MapGnameGroup_insert(groups, gname, group);

    // Impedances
    wiring_DC = Impedances_create_empty();
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_ohmic(String_wrap("O1")), 1000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_ohmic(String_wrap("O2")), 1000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_barrier_gate(String_wrap("B1")), 10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_barrier_gate(String_wrap("B2")), 10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_barrier_gate(String_wrap("B3")), 10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_plunger_gate(String_wrap("P1")), 10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(
            Connection_create_plunger_gate(String_wrap("P2")), 10000.0, 1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_reservoir_gate(String_wrap("R1")),
                         10000.0,
                         1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_reservoir_gate(String_wrap("R2")),
                         10000.0,
                         1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_screening_gate(String_wrap("SG1")),
                         10000.0,
                         1e-12));
    Impedances_push_back(
        wiring_DC,
        Impedance_create(Connection_create_screening_gate(String_wrap("SG2")),
                         10000.0,
                         1e-12));

    // VoltageConstraints
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
    for (int i = 0; i < 81; ++i) adj_data[i] = (i % 10 == 0 ? 1 : 0);
    size_t          adj_shape[2] = {9, 9};
    AdjacencyHandle adjacency =
        Adjacency_create(adj_data, adj_shape, 2, adj_indexes);
    PairDoubleDoubleHandle bounds = PairDoubleDouble_create(-1.0, 1.0);
    constraints = VoltageConstraints_create(adjacency, 1.0, bounds);

    handle = Config_create(screening_gates,
                           plunger_gates,
                           ohmics,
                           barrier_gates,
                           reservoir_gates,
                           groups,
                           wiring_DC,
                           constraints);

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
    Adjacency_destroy(adjacency);
    PairDoubleDouble_destroy(bounds);
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
    VoltageConstraints_destroy(constraints);
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

TEST_F(ConfigTest, VoltageConstraintsGetter) {
  VoltageConstraintsHandle vc = Config_voltage_constraints(handle);
  EXPECT_FALSE(vc == nullptr);
  VoltageConstraints_destroy(vc);
}

TEST_F(ConfigTest, SerializationRoundTrip) {
  StringHandle json   = Config_to_json_string(handle);
  ConfigHandle loaded = Config_from_json_string(json);
  EXPECT_TRUE(Config_equal(handle, loaded));
  Config_destroy(loaded);
  String_destroy(json);
}

TEST_F(ConfigTest, EqualityAndInequality) {
  ConfigHandle handle2 = Config_create(screening_gates,
                                       plunger_gates,
                                       ohmics,
                                       barrier_gates,
                                       reservoir_gates,
                                       groups,
                                       wiring_DC,
                                       constraints);
  EXPECT_TRUE(Config_equal(handle, handle2));
  EXPECT_FALSE(Config_not_equal(handle, handle2));
  Config_destroy(handle2);
}

TEST_F(ConfigTest, CreateThrowsOnNullArgs) {
  EXPECT_THROW(Config_create(nullptr,
                             plunger_gates,
                             ohmics,
                             barrier_gates,
                             reservoir_gates,
                             groups,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             nullptr,
                             ohmics,
                             barrier_gates,
                             reservoir_gates,
                             groups,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             nullptr,
                             barrier_gates,
                             reservoir_gates,
                             groups,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             ohmics,
                             nullptr,
                             reservoir_gates,
                             groups,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             ohmics,
                             barrier_gates,
                             nullptr,
                             groups,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             ohmics,
                             barrier_gates,
                             reservoir_gates,
                             nullptr,
                             wiring_DC,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             ohmics,
                             barrier_gates,
                             reservoir_gates,
                             groups,
                             nullptr,
                             constraints),
               std::invalid_argument);
  EXPECT_THROW(Config_create(screening_gates,
                             plunger_gates,
                             ohmics,
                             barrier_gates,
                             reservoir_gates,
                             groups,
                             wiring_DC,
                             nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, DestroyThrowsOnNullHandle) {
  EXPECT_THROW(Config_destroy(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, NumUniqueChannelsThrowsOnNullHandle) {
  EXPECT_THROW(Config_num_unique_channels(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GroupsThrowsOnNullHandle) {
  EXPECT_THROW(Config_groups(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetAllGroupsThrowsOnNullHandle) {
  EXPECT_THROW(Config_get_all_groups(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, SelectGroupThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_select_group(nullptr, gname), std::invalid_argument);
  EXPECT_THROW(Config_select_group(handle, nullptr), std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetDotNumberThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_dot_number(nullptr, gname), std::invalid_argument);
  EXPECT_THROW(Config_get_dot_number(handle, nullptr), std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetChargeSenseGroupsThrowsOnNullHandle) {
  EXPECT_THROW(Config_get_charge_sense_groups(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, OhmicInChargeSensorThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  EXPECT_THROW(Config_ohmic_in_charge_sensor(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(Config_ohmic_in_charge_sensor(handle, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, GetAssociatedOhmicThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_reservoir_gate(String_wrap("R1"));
  EXPECT_THROW(Config_get_associated_ohmic(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(Config_get_associated_ohmic(handle, nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetCurrentChannelsThrowsOnNullHandle) {
  EXPECT_THROW(Config_get_current_channels(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetGnameThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_gname(nullptr, channel), std::invalid_argument);
  EXPECT_THROW(Config_get_gname(handle, nullptr), std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetGroupBarrierGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_barrier_gates(nullptr, gname),
               std::invalid_argument);
  EXPECT_THROW(Config_get_group_barrier_gates(handle, nullptr),
               std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupPlungerGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_plunger_gates(nullptr, gname),
               std::invalid_argument);
  EXPECT_THROW(Config_get_group_plunger_gates(handle, nullptr),
               std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupReservoirGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_reservoir_gates(nullptr, gname),
               std::invalid_argument);
  EXPECT_THROW(Config_get_group_reservoir_gates(handle, nullptr),
               std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupScreeningGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_screening_gates(nullptr, gname),
               std::invalid_argument);
  EXPECT_THROW(Config_get_group_screening_gates(handle, nullptr),
               std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupDotGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_dot_gates(nullptr, gname),
               std::invalid_argument);
  EXPECT_THROW(Config_get_group_dot_gates(handle, nullptr),
               std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetGroupGatesThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_get_group_gates(nullptr, gname), std::invalid_argument);
  EXPECT_THROW(Config_get_group_gates(handle, nullptr), std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, GetChannelBarrierGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_barrier_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_barrier_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelPlungerGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_plunger_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_plunger_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelReservoirGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_reservoir_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_reservoir_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelScreeningGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_screening_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_screening_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelDotGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_dot_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_dot_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelGatesThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_gates(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_gates(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelOhmicsThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_ohmics(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_ohmics(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetChannelOrderNoOhmicsThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_get_channel_order_no_ohmics(nullptr, channel),
               std::invalid_argument);
  EXPECT_THROW(Config_get_channel_order_no_ohmics(handle, nullptr),
               std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetNumUniqueChannelsThrowsOnNullHandle) {
  EXPECT_THROW(Config_get_num_unique_channels(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, ReturnChannelsFromGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  EXPECT_THROW(Config_return_channels_from_gate(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(Config_return_channels_from_gate(handle, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, ReturnChannelFromGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  EXPECT_THROW(Config_return_channel_from_gate(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(Config_return_channel_from_gate(handle, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, OhmicInChannelThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  ChannelHandle    ch   = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_ohmic_in_channel(nullptr, conn, ch),
               std::invalid_argument);
  EXPECT_THROW(Config_ohmic_in_channel(handle, nullptr, ch),
               std::invalid_argument);
  EXPECT_THROW(Config_ohmic_in_channel(handle, conn, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
  Channel_destroy(ch);
}
TEST_F(ConfigTest, WiringDCThrowsOnNullHandle) {
  EXPECT_THROW(Config_wiring_DC(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, ChannelsThrowsOnNullHandle) {
  EXPECT_THROW(Config_channels(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, VoltageConstraintsThrowsOnNullHandle) {
  EXPECT_THROW(Config_voltage_constraints(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, EqualThrowsOnNullHandle) {
  EXPECT_THROW(Config_equal(nullptr, handle), std::invalid_argument);
  EXPECT_THROW(Config_equal(handle, nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, NotEqualThrowsOnNullHandle) {
  EXPECT_THROW(Config_not_equal(nullptr, handle), std::invalid_argument);
  EXPECT_THROW(Config_not_equal(handle, nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, ToJsonStringThrowsOnNullHandle) {
  EXPECT_THROW(Config_to_json_string(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, FromJsonStringThrowsOnNullHandle) {
  EXPECT_THROW(Config_from_json_string(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, HasReservoirGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_reservoir_gate(String_wrap("R1"));
  EXPECT_THROW(Config_has_reservoir_gate(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_reservoir_gate(handle, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasPlungerGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  EXPECT_THROW(Config_has_plunger_gate(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_plunger_gate(handle, nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasScreeningGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_screening_gate(String_wrap("SG1"));
  EXPECT_THROW(Config_has_screening_gate(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_screening_gate(handle, nullptr),
               std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasBarrierGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_barrier_gate(String_wrap("B1"));
  EXPECT_THROW(Config_has_barrier_gate(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_barrier_gate(handle, nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasOhmicThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  EXPECT_THROW(Config_has_ohmic(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_ohmic(handle, nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasGateThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_plunger_gate(String_wrap("P1"));
  EXPECT_THROW(Config_has_gate(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_has_gate(handle, nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, HasGnameThrowsOnNullHandle) {
  GnameHandle gname = Gname_create(String_wrap("group1"));
  EXPECT_THROW(Config_has_gname(nullptr, gname), std::invalid_argument);
  EXPECT_THROW(Config_has_gname(handle, nullptr), std::invalid_argument);
  Gname_destroy(gname);
}
TEST_F(ConfigTest, HasChannelThrowsOnNullHandle) {
  ChannelHandle channel = Channel_create(String_wrap("CH1"));
  EXPECT_THROW(Config_has_channel(nullptr, channel), std::invalid_argument);
  EXPECT_THROW(Config_has_channel(handle, nullptr), std::invalid_argument);
  Channel_destroy(channel);
}
TEST_F(ConfigTest, GetImpedanceThrowsOnNullHandle) {
  ConnectionHandle conn = Connection_create_ohmic(String_wrap("O1"));
  EXPECT_THROW(Config_get_impedance(nullptr, conn), std::invalid_argument);
  EXPECT_THROW(Config_get_impedance(handle, nullptr), std::invalid_argument);
  Connection_destroy(conn);
}
TEST_F(ConfigTest, GetAllGnamesThrowsOnNullHandle) {
  EXPECT_THROW(Config_get_all_gnames(nullptr), std::invalid_argument);
}

// Happy path for all "getter" and "has_*" functions
TEST_F(ConfigTest, GettersAndHasFunctionsWork) {
  // Use valid handles from the fixture
  // Get a channel, gname, and connection from the group
  ChannelHandle    channel = Channel_create(String_wrap("CH1"));
  GnameHandle      gname   = Gname_create(String_wrap("group1"));
  ConnectionHandle gate    = Connection_create_barrier_gate(String_wrap("B1"));
  ConnectionHandle ohmic   = Connection_create_ohmic(String_wrap("O1"));
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
