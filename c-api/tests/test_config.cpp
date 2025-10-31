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
