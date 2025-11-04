#include <gtest/gtest.h>

#include <concepts>
#include <fstream>
#include <iostream>
#include <memory>
#include <ranges>
#include <stdexcept>

#include "falcon_core/physics/config/Loader.hpp"
#include "falcon_core/physics/config/core/Config.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace {
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::autotuner_interfaces::names;

class ConfigTest : public ::testing::Test {
 protected:
  falcon_core::physics::config::core::Config original_config;
  falcon_core::physics::config::core::Config two_channel_config;
  ConfigTest()
      : original_config(
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::ScreeningGate("SG1"),
                                          Connection::ScreeningGate("SG2")}),
            std::make_shared<Connections>(std::vector<ConnectionSP>{
                Connection::PlungerGate("P1"), Connection::PlungerGate("P2")}),
            std::make_shared<Connections>(std::vector<ConnectionSP>{
                Connection::Ohmic("O1"), Connection::Ohmic("O2")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::BarrierGate("B1"),
                                          Connection::BarrierGate("B2"),
                                          Connection::BarrierGate("B3")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::ReservoirGate("R1"),
                                          Connection::ReservoirGate("R2")}),
            std::make_shared<falcon_core::generic::Map<
                Gname,
                falcon_core::physics::config::core::Group>>(
                std::vector<
                    std::pair<std::shared_ptr<Gname>,
                              std::shared_ptr<
                                  falcon_core::physics::config::core::Group>>>{
                    {std::make_shared<Gname>("group1"),
                     std::make_shared<
                         falcon_core::physics::config::core::Group>(
                         std::make_shared<Channel>("CH1"),
                         2,
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ScreeningGate("SG1"),
                                 Connection::ScreeningGate("SG2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ReservoirGate("R1"),
                                 Connection::ReservoirGate("R2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::PlungerGate("P1"),
                                 Connection::PlungerGate("P2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::BarrierGate("B1"),
                                 Connection::BarrierGate("B2"),
                                 Connection::BarrierGate("B3")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::Ohmic("O1"),
                                 Connection::ReservoirGate("R1"),
                                 Connection::BarrierGate("B1"),
                                 Connection::PlungerGate("P1"),
                                 Connection::BarrierGate("B2"),
                                 Connection::PlungerGate("P2"),
                                 Connection::BarrierGate("B3"),
                                 Connection::ReservoirGate("R2"),
                                 Connection::Ohmic("O2"),
                             }))}}),
            std::make_shared<Impedances>(std::vector<ImpedanceSP>{
                std::make_shared<Impedance>(
                    Connection::Ohmic("O1"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::Ohmic("O2"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B3"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::PlungerGate("P1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::PlungerGate("P2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ScreeningGate("SG1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ScreeningGate("SG2"), 10000.0, 1e-12),
            }),
            std::make_shared<
                falcon_core::physics::config::core::VoltageConstraints>(
                std::make_shared<falcon_core::physics::config::core::Adjacency>(
                    xt::eye(9),
                    std::make_shared<Connections>(std::vector<ConnectionSP>{
                        Connection::ScreeningGate("SG1"),
                        Connection::ScreeningGate("SG2"),
                        Connection::PlungerGate("P1"),
                        Connection::PlungerGate("P2"),
                        Connection::BarrierGate("B1"),
                        Connection::BarrierGate("B2"),
                        Connection::BarrierGate("B3"),
                        Connection::ReservoirGate("R1"),
                        Connection::ReservoirGate("R2"),
                    })),
                1.0,
                std::make_pair(-1.0, 1.0))),
        two_channel_config(
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::ScreeningGate("SG1"),
                                          Connection::ScreeningGate("SG2"),
                                          Connection::ScreeningGate("SG3")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::PlungerGate("P1"),
                                          Connection::PlungerGate("P2"),
                                          Connection::PlungerGate("P3")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::Ohmic("O1"),
                                          Connection::Ohmic("O2"),
                                          Connection::Ohmic("O3"),
                                          Connection::Ohmic("O4")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::BarrierGate("B1"),
                                          Connection::BarrierGate("B2"),
                                          Connection::BarrierGate("B3"),
                                          Connection::BarrierGate("B4"),
                                          Connection::BarrierGate("B5")}),
            std::make_shared<Connections>(
                std::vector<ConnectionSP>{Connection::ReservoirGate("R1"),
                                          Connection::ReservoirGate("R2"),
                                          Connection::ReservoirGate("R3"),
                                          Connection::ReservoirGate("R4")}),
            std::make_shared<falcon_core::generic::Map<
                Gname,
                falcon_core::physics::config::core::Group>>(
                std::vector<
                    std::pair<std::shared_ptr<Gname>,
                              std::shared_ptr<
                                  falcon_core::physics::config::core::Group>>>{
                    {std::make_shared<Gname>("group1"),
                     std::make_shared<
                         falcon_core::physics::config::core::Group>(
                         std::make_shared<Channel>("CH1"),
                         2,
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ScreeningGate("SG1"),
                                 Connection::ScreeningGate("SG2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ReservoirGate("R1"),
                                 Connection::ReservoirGate("R2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::PlungerGate("P1"),
                                 Connection::PlungerGate("P2")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::BarrierGate("B1"),
                                 Connection::BarrierGate("B2"),
                                 Connection::BarrierGate("B3")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::Ohmic("O1"),
                                 Connection::ReservoirGate("R1"),
                                 Connection::BarrierGate("B1"),
                                 Connection::PlungerGate("P1"),
                                 Connection::BarrierGate("B2"),
                                 Connection::PlungerGate("P2"),
                                 Connection::BarrierGate("B3"),
                                 Connection::ReservoirGate("R2"),
                                 Connection::Ohmic("O2"),
                             }))},
                    {std::make_shared<Gname>("group2"),
                     std::make_shared<
                         falcon_core::physics::config::core::Group>(
                         std::make_shared<Channel>("CH2"),
                         1,
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ScreeningGate("SG2"),
                                 Connection::ScreeningGate("SG3")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::ReservoirGate("R3"),
                                 Connection::ReservoirGate("R4")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::PlungerGate("P3")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::BarrierGate("B4"),
                                 Connection::BarrierGate("B5")}),
                         std::make_shared<Connections>(
                             std::vector<ConnectionSP>{
                                 Connection::Ohmic("O3"),
                                 Connection::ReservoirGate("R3"),
                                 Connection::BarrierGate("B4"),
                                 Connection::PlungerGate("P3"),
                                 Connection::BarrierGate("B5"),
                                 Connection::ReservoirGate("R4"),
                                 Connection::Ohmic("O4"),
                             }))}}),
            std::make_shared<Impedances>(std::vector<ImpedanceSP>{
                std::make_shared<Impedance>(
                    Connection::Ohmic("O1"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::Ohmic("O2"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::Ohmic("O3"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::Ohmic("O4"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B3"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B4"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::BarrierGate("B5"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::PlungerGate("P1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::PlungerGate("P2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::PlungerGate("P3"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R3"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ReservoirGate("R4"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ScreeningGate("SG1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ScreeningGate("SG2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    Connection::ScreeningGate("SG3"), 10000.0, 1e-12),
            }),
            std::make_shared<
                falcon_core::physics::config::core::VoltageConstraints>(
                std::make_shared<falcon_core::physics::config::core::Adjacency>(
                    xt::eye(9),
                    std::make_shared<Connections>(std::vector<ConnectionSP>{
                        Connection::ScreeningGate("SG1"),
                        Connection::ScreeningGate("SG2"),
                        Connection::ScreeningGate("SG3"),
                        Connection::PlungerGate("P1"),
                        Connection::PlungerGate("P2"),
                        Connection::PlungerGate("P3"),
                        Connection::BarrierGate("B1"),
                        Connection::BarrierGate("B2"),
                        Connection::BarrierGate("B3"),
                        Connection::BarrierGate("B4"),
                        Connection::BarrierGate("B5"),
                        Connection::ReservoirGate("R1"),
                        Connection::ReservoirGate("R2"),
                        Connection::ReservoirGate("R3"),
                        Connection::ReservoirGate("R4"),
                    })),
                1.0,
                std::make_pair(-1.0, 1.0))) {}
};

TEST_F(ConfigTest, JsonRoundTrip) {
  std::string json_str = original_config.to_json_string();
  ASSERT_FALSE(json_str.empty());
  auto deserialized_config =
      *falcon_core::physics::config::core::Config::from_json_string<
          falcon_core::physics::config::core::Config>(json_str);
  ASSERT_EQ(deserialized_config.num_unique_channels(),
            original_config.num_unique_channels());
  ASSERT_EQ(deserialized_config.groups()->size(),
            original_config.groups()->size());
  std::vector<std::string> ch1, ch2;
  for (const auto& c : *deserialized_config.channels())
    ch1.push_back(c->name());
  for (const auto& c : *original_config.channels()) ch2.push_back(c->name());
  std::sort(ch1.begin(), ch1.end());
  std::sort(ch2.begin(), ch2.end());
  ASSERT_EQ(ch1, ch2);
  ASSERT_EQ(deserialized_config.get_all_gates()->size(),
            original_config.get_all_gates()->size());
  std::vector<std::string> g1, g2;
  auto                     all_gates    = *deserialized_config.get_all_gates();
  auto                     all_og_names = *original_config.get_all_gates();
  for (const auto& g : all_gates) g1.push_back(g->name());
  for (const auto& g : all_og_names) g2.push_back(g->name());
  std::sort(g1.begin(), g1.end());
  std::sort(g2.begin(), g2.end());
  ASSERT_EQ(g1, g2);
  ASSERT_EQ(deserialized_config.ohmics()->size(),
            original_config.ohmics()->size());
  std::vector<std::string> o1, o2;
  auto                     all_ohmics    = *deserialized_config.ohmics();
  auto                     all_og_ohmics = *original_config.ohmics();
  for (const auto& o : all_ohmics) o1.push_back(o->name());
  for (const auto& o : all_og_ohmics) o2.push_back(o->name());
  std::sort(o1.begin(), o1.end());
  std::sort(o2.begin(), o2.end());
  ASSERT_EQ(o1, o2);
  ASSERT_EQ(deserialized_config.wiring_DC()->size(),
            original_config.wiring_DC()->size());
  auto sort_by_conn = [](const ImpedanceSP& a, const ImpedanceSP& b) {
    return a->connection()->name() < b->connection()->name();
  };
  ASSERT_TRUE(*(deserialized_config.wiring_DC()) ==
              *(original_config.wiring_DC()));
}

TEST_F(ConfigTest, BasicQueries) {
  auto gnames = original_config.get_all_gnames();
  auto groups = original_config.get_all_groups();
  ASSERT_EQ(gnames->size(), groups->size());
  for (size_t i = 0; i < gnames->size(); ++i) {
    ASSERT_TRUE(groups->items()[i]);
    ASSERT_TRUE(gnames->items()[i]);
  }
  auto channels = original_config.get_current_channels();
  ASSERT_TRUE(channels);
  for (const auto& ch : *channels) {
    ASSERT_TRUE(original_config.has_channel(ch));
  }
  for (const auto& gn : *gnames) {
    ASSERT_TRUE(original_config.has_gname(gn));
    auto group = original_config.select_group(gn);
    ASSERT_TRUE(group);
  }
  for (const auto& ch : *channels) {
    int dots = original_config.get_dot_number(ch);
    ASSERT_GE(dots, 0);
  }
  auto charge_sense    = original_config.get_charge_sense_groups();
  auto ohmics          = *original_config.ohmics();
  auto reservoir_gates = *original_config.reservoir_gates();
  for (const auto& o : ohmics) {
    original_config.ohmic_in_charge_sensor(o);
  }
  for (const auto& r : reservoir_gates) {
    original_config.get_associated_ohmic(r);
  }
  for (const auto& ch : *channels) {
    auto gn = original_config.get_gname(ch);
    if (gn) {
      auto bg = original_config.get_channel_barrier_gates(ch);
      auto pg = original_config.get_channel_plunger_gates(ch);
      auto rg = original_config.get_channel_reservoir_gates(ch);
      auto sg = original_config.get_channel_screening_gates(ch);
    }
  }
  auto isolated_barriers = original_config.get_isolated_barrier_gates();
  auto shared_barriers   = original_config.get_shared_barrier_gates();
  for (const auto& ch : *channels) {
    auto iso = original_config.get_isolated_channel_gates(ch);
  }
  auto iso_map   = original_config.get_isolated_gates_by_channel();
  auto relations = original_config.generate_gate_relations();
  ASSERT_TRUE(relations);
  auto all_connections = *original_config.get_all_connections();
  for (const auto& conn : all_connections) {
    original_config.get_impedance(conn);
  }
}

TEST_F(ConfigTest, Constructor_NullArgsThrow) {
  using Config = falcon_core::physics::config::core::Config;
  EXPECT_THROW(Config(original_config.screening_gates(),
                      original_config.plunger_gates(),
                      original_config.ohmics(),
                      original_config.barrier_gates(),
                      original_config.reservoir_gates(),
                      nullptr,
                      original_config.wiring_DC(),
                      original_config.voltage_constraints()),
               std::invalid_argument);
  EXPECT_THROW(Config(original_config.screening_gates(),
                      original_config.plunger_gates(),
                      original_config.ohmics(),
                      original_config.barrier_gates(),
                      original_config.reservoir_gates(),
                      original_config.groups(),
                      nullptr,
                      original_config.voltage_constraints()),
               std::invalid_argument);
  EXPECT_THROW(Config(original_config.screening_gates(),
                      original_config.plunger_gates(),
                      original_config.ohmics(),
                      original_config.barrier_gates(),
                      original_config.reservoir_gates(),
                      original_config.groups(),
                      original_config.wiring_DC(),
                      nullptr),
               std::invalid_argument);
}

TEST_F(ConfigTest, Constructor_NoGroupsThrows) {
  auto empty_groups = std::make_shared<
      falcon_core::generic::Map<Gname,
                                falcon_core::physics::config::core::Group>>();
  EXPECT_THROW(
      falcon_core::physics::config::core::Config(
          original_config.screening_gates(),
          original_config.plunger_gates(),
          original_config.ohmics(),
          original_config.barrier_gates(),
          original_config.reservoir_gates(),
          empty_groups,
          original_config.wiring_DC(),
          original_config.voltage_constraints()),
      std::runtime_error);
}

TEST_F(ConfigTest, ImpedanceConsistency_ExtraImpedanceThrows) {
  auto bad_wiring = std::make_shared<Impedances>(*original_config.wiring_DC());
  bad_wiring->push_back(
      std::make_shared<Impedance>(Connection::Ohmic("O99"), 1000.0, 1e-12));

  EXPECT_THROW(
      falcon_core::physics::config::core::Config(
          original_config.screening_gates(),
          original_config.plunger_gates(),
          original_config.ohmics(),
          original_config.barrier_gates(),
          original_config.reservoir_gates(),
          original_config.groups(),
          bad_wiring,
          original_config.voltage_constraints()),
      std::runtime_error);
}

TEST_F(ConfigTest, ImpedanceConsistency_MissingImpedanceThrows) {
  auto bad_wiring = std::make_shared<Impedances>(*original_config.wiring_DC());
  bad_wiring->erase_at(0);  // remove one

  EXPECT_THROW(
      falcon_core::physics::config::core::Config(
          original_config.screening_gates(),
          original_config.plunger_gates(),
          original_config.ohmics(),
          original_config.barrier_gates(),
          original_config.reservoir_gates(),
          original_config.groups(),
          bad_wiring,
          original_config.voltage_constraints()),
      std::runtime_error);
}

TEST_F(ConfigTest, HasChannel_NonExistentReturnsFalse) {
  auto bad_channel = std::make_shared<Channel>("nonexistent");
  EXPECT_FALSE(original_config.has_channel(bad_channel));
}

TEST_F(ConfigTest, HasGname_NonExistentReturnsFalse) {
  auto bad_gname = std::make_shared<Gname>("nonexistent");
  EXPECT_FALSE(original_config.has_gname(bad_gname));
}

TEST_F(ConfigTest, GetGname_InvalidChannelThrows) {
  auto bad_channel = std::make_shared<Channel>("nonexistent");
  EXPECT_THROW(original_config.get_gname(bad_channel), std::invalid_argument);
}

TEST_F(ConfigTest, GetGroupGates_InvalidGnameThrows) {
  auto bad_gname = std::make_shared<Gname>("nonexistent");
  EXPECT_THROW(original_config.get_group_barrier_gates(bad_gname),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_group_plunger_gates(bad_gname),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_group_reservoir_gates(bad_gname),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_group_screening_gates(bad_gname),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_group_dot_gates(bad_gname),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_group_gates(bad_gname),
               std::invalid_argument);
}

TEST_F(ConfigTest, GetChannelOhmics_ValidAndInvalid) {
  auto ch1 = std::make_shared<Channel>("CH1");
  auto ohmics = original_config.get_channel_ohmics(ch1);
  ASSERT_NE(ohmics, nullptr);
  ASSERT_EQ(ohmics->size(), 2);  // O1, O2
  EXPECT_TRUE(ohmics->contains(Connection::Ohmic("O1")));
  EXPECT_TRUE(ohmics->contains(Connection::Ohmic("O2")));

  auto bad_channel = std::make_shared<Channel>("nonexistent");
  EXPECT_THROW(original_config.get_channel_ohmics(bad_channel),
               std::invalid_argument);
}

TEST_F(ConfigTest, GetChannelOrderNoOhmics_ReturnsGatesOnly) {
  auto ch1   = std::make_shared<Channel>("CH1");
  auto order = original_config.get_channel_order_no_ohmics(ch1);
  ASSERT_NE(order, nullptr);
  // original order: O1;R1;B1;P1;B2;P2;B3;R2;O2
  // expected: R1;B1;P1;B2;P2;B3;R2
  ASSERT_EQ(order->size(), 7);
  for (const auto& conn : *order) {
    EXPECT_FALSE(conn->is_ohmic());
  }
}

TEST_F(ConfigTest, GetNumUniqueChannels_ReturnsCorrectCount) {
  EXPECT_EQ(original_config.get_num_unique_channels(), 1);
  EXPECT_EQ(two_channel_config.get_num_unique_channels(), 2);
}

TEST_F(ConfigTest, ReturnChannelsFromGate_SharedGate) {
  auto shared_gate = Connection::ScreeningGate("SG2");
  auto channels = two_channel_config.return_channels_from_gate(shared_gate);
  ASSERT_NE(channels, nullptr);
  ASSERT_EQ(channels->size(), 2);
  EXPECT_TRUE(channels->contains(std::make_shared<Channel>("CH1")));
  EXPECT_TRUE(channels->contains(std::make_shared<Channel>("CH2")));
}

TEST_F(ConfigTest, ReturnChannelFromGate_NonExistentGateThrows) {
  auto bad_gate = Connection::ScreeningGate("nonexistent");
  EXPECT_THROW(original_config.return_channel_from_gate(bad_gate),
               std::invalid_argument);
}

TEST_F(ConfigTest, OhmicInChannel_TrueAndFalse) {
  auto ch1  = std::make_shared<Channel>("CH1");
  auto ch2  = std::make_shared<Channel>("CH2");
  auto o1   = Connection::Ohmic("O1");
  auto o3   = Connection::Ohmic("O3");

  EXPECT_TRUE(two_channel_config.ohmic_in_channel(o1, ch1));
  EXPECT_FALSE(two_channel_config.ohmic_in_channel(o3, ch1));
  EXPECT_TRUE(two_channel_config.ohmic_in_channel(o3, ch2));
  EXPECT_FALSE(two_channel_config.ohmic_in_channel(o1, ch2));
}

TEST_F(ConfigTest, GetDotChannelNeighbors_ValidGate) {
  auto p1        = Connection::PlungerGate("P1");
  auto neighbors = original_config.get_dot_channel_neighbors(p1);
  ASSERT_NE(neighbors.first, nullptr);
  ASSERT_NE(neighbors.second, nullptr);
  EXPECT_EQ(neighbors.first->name(), "B1");
  EXPECT_EQ(neighbors.second->name(), "B2");
}

TEST_F(ConfigTest, GetChargeSenseGroups_FindsOneDotGroup) {
  auto charge_sense_groups = two_channel_config.get_charge_sense_groups();
  ASSERT_NE(charge_sense_groups, nullptr);
  ASSERT_EQ(charge_sense_groups->size(), 1);
  EXPECT_EQ((*charge_sense_groups)[0]->name(), "group2");
}

TEST_F(ConfigTest, OhmicInChargeSensor_ReturnsTrueAndFalse) {
  auto ohmic_in_cs = Connection::Ohmic("O3");  // In group2 (charge sensor)
  EXPECT_TRUE(two_channel_config.ohmic_in_charge_sensor(ohmic_in_cs));
  auto ohmic_not_in_cs = Connection::Ohmic("O1");  // In group1 (not cs)
  EXPECT_FALSE(two_channel_config.ohmic_in_charge_sensor(ohmic_not_in_cs));
}

TEST_F(ConfigTest, HasChannelNullptrThrows) {
  EXPECT_THROW(original_config.has_channel(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, HasGnameNullptrThrows) {
  EXPECT_THROW(original_config.has_gname(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, SelectGroupNullptrThrows) {
  EXPECT_THROW(original_config.select_group(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetDotNumberNullptrThrows) {
  EXPECT_THROW(original_config.get_dot_number(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetNullImpedanceThrows) {
  EXPECT_THROW(original_config.get_impedance(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetInvalidImpedanceThrows) {
  auto bad_conn = Connection::ScreeningGate("nonsense");
  EXPECT_THROW(original_config.get_impedance(bad_conn), std::invalid_argument);
}
TEST_F(ConfigTest, OhmicInChargeSensorNullptrThrows) {
  EXPECT_THROW(original_config.ohmic_in_charge_sensor(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetAssociatedOhmicNullptrThrows) {
  EXPECT_THROW(original_config.get_associated_ohmic(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGnameNullptrThrows) {
  EXPECT_THROW(original_config.get_gname(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupBarrierGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_barrier_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupPlungerGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_plunger_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupReservoirGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_reservoir_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupScreeningGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_screening_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupDotGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_dot_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetGroupGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_group_gates(nullptr), std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelBarrierGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_barrier_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelPlungerGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_plunger_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelReservoirGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_reservoir_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelScreeningGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_screening_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelDotGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_dot_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelOhmicsNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_ohmics(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetChannelOrderNoOhmicsNullptrThrows) {
  EXPECT_THROW(original_config.get_channel_order_no_ohmics(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, ReturnChannelsFromGateNullptrThrows) {
  EXPECT_THROW(original_config.return_channels_from_gate(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, ReturnChannelFromGateNullptrThrows) {
  EXPECT_THROW(original_config.return_channel_from_gate(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, OhmicInChannelNullptrOhmicThrows) {
  auto ch = std::make_shared<Channel>("CH1");
  EXPECT_THROW(original_config.ohmic_in_channel(nullptr, ch),
               std::invalid_argument);
}
TEST_F(ConfigTest, OhmicInChannelNullptrChannelThrows) {
  auto ohmic = Connection::Ohmic("O1");
  EXPECT_THROW(original_config.ohmic_in_channel(ohmic, nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetDotChannelNeighborsNullptrThrows) {
  EXPECT_THROW(original_config.get_dot_channel_neighbors(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelBarrierGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_barrier_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelPlungerGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_plunger_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelReservoirGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_reservoir_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelScreeningGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_screening_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelDotGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_dot_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetSharedChannelGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_shared_channel_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelBarrierGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_barrier_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelPlungerGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_plunger_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelReservoirGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_reservoir_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelScreeningGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_screening_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelDotGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_dot_gates(nullptr),
               std::invalid_argument);
}
TEST_F(ConfigTest, GetIsolatedChannelGatesNullptrThrows) {
  EXPECT_THROW(original_config.get_isolated_channel_gates(nullptr),
               std::invalid_argument);
}

TEST(ConfigLoaderTest, LoadConfigFromYaml) {
  const char* yaml_content =
      "ScreeningGates: \"S1;S2;S3\"\n"
      "PlungerGates: \"P1;P2;P3\"\n"
      "Ohmics: \"O1;O2;O3;O4\"\n"
      "BarrierGates: \"B1;B2;B3;B4;B5\"\n"
      "ReservoirGates: \"R1;R2;R3;R4\"\n"
      "num-unique-channels: 2\n"
      "groups:\n"
      "  group1:\n"
      "    Name: \"I_O1\"\n"
      "    NumDots: 2\n"
      "    ScreeningGates: \"S1;S2\"\n"
      "    ReservoirGates: \"R1;R2\"\n"
      "    PlungerGates: \"P1;P2\"\n"
      "    BarrierGates: \"B1;B2;B3\"\n"
      "    Order: \"O1;R1;B1;P1;B2;P2;B3;R2;O2\"\n"
      "  group2:\n"
      "    Name: \"I_O3\"\n"
      "    NumDots: 1\n"
      "    ScreeningGates: \"S2;S3\"\n"
      "    ReservoirGates: \"R3;R4\"\n"
      "    PlungerGates: \"P3\"\n"
      "    BarrierGates: \"B4;B5\"\n"
      "    Order: \"O3;R3;B4;P3;B5;R4;O4\"\n"
      "adjacency:\n"
      "  S2: \"P1;P2;P3;P4;R1;R2;R3;R4;B1;B2;B3;B4;B5\"\n"
      "  S1: \"P1;P2;R1;R2;B1;B2;B3\"\n"
      "  S3: \"P3;B4;B5;R3;R4\"\n"
      "  B1: \"R1;P1\"\n"
      "  B2: \"P1;P2\"\n"
      "  B3: \"P2;R2\"\n"
      "  B4: \"P3;R3\"\n"
      "  B5: \"R4;P3\"\n"
      "  O3: \"R3\"\n"
      "  O4: \"R4\"\n"
      "  O1: \"R1\"\n"
      "  O2: \"R2\"\n"
      "max_safe_diff: 1.0\n"
      "safe_voltage_bounds: [-1.0, 1.0]\n"
      "wiringDC:\n"
      "  S1: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  S2: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  S3: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  P1: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  P2: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  P3: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  O1: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  O2: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  O3: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  O4: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  R1: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  R2: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  R3: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  R4: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  B1: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  B2: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  B3: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  B4: {resistance: 1000.0, capacitance: 1e-12}\n"
      "  B5: {resistance: 1000.0, capacitance: 1e-12}\n";
  std::string   temp_yaml_path = "/tmp/test_config.yaml";
  std::ofstream yaml_file(temp_yaml_path);
  yaml_file << yaml_content;
  yaml_file.close();
  falcon_core::physics::config::Loader loader(temp_yaml_path);
  auto                                 config = loader.config();
  ASSERT_TRUE(config != nullptr);
  EXPECT_EQ(config->num_unique_channels(), 2);
}

TEST_F(ConfigTest, SharedChannelGateFunctions_NullChannel) {
  // Test that all functions throw on nullptr channel
  EXPECT_THROW(original_config.get_shared_channel_barrier_gates(nullptr),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_shared_channel_plunger_gates(nullptr),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_shared_channel_reservoir_gates(nullptr),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_shared_channel_screening_gates(nullptr),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_shared_channel_dot_gates(nullptr),
               std::invalid_argument);
  EXPECT_THROW(original_config.get_shared_channel_gates(nullptr),
               std::invalid_argument);
}

TEST_F(ConfigTest, SharedChannelGateFunctions_ValidChannel) {
  // Create or obtain a valid ChannelSP for testing
  auto channel = std::make_shared<Channel>("CH1");

  // Each function should return a non-null ConnectionsSP
  EXPECT_NE(original_config.get_shared_channel_barrier_gates(channel), nullptr);
  EXPECT_NE(original_config.get_shared_channel_plunger_gates(channel), nullptr);
  EXPECT_NE(original_config.get_shared_channel_reservoir_gates(channel),
            nullptr);
  EXPECT_NE(original_config.get_shared_channel_screening_gates(channel),
            nullptr);
  EXPECT_NE(original_config.get_shared_channel_dot_gates(channel), nullptr);
  EXPECT_NE(original_config.get_shared_channel_gates(channel), nullptr);
}

TEST_F(ConfigTest, GetIsolatedBarrierGates_ReturnsExpected) {
  auto result = original_config.get_isolated_barrier_gates();
  ASSERT_NE(result, nullptr);
  // Should contain all unique barrier gates from the config
  EXPECT_GE(result->size(), 1);
}

TEST_F(ConfigTest, GetIsolatedPlungerGates_ReturnsExpected) {
  auto result = original_config.get_isolated_plunger_gates();
  ASSERT_NE(result, nullptr);
  EXPECT_GE(result->size(), 1);
}

TEST_F(ConfigTest, GetIsolatedReservoirGates_ReturnsExpected) {
  auto result = original_config.get_isolated_reservoir_gates();
  ASSERT_NE(result, nullptr);
  EXPECT_GE(result->size(), 1);
}

TEST_F(ConfigTest, GetIsolatedScreeningGates_ReturnsExpected) {
  auto result = original_config.get_isolated_screening_gates();
  ASSERT_NE(result, nullptr);
  EXPECT_GE(result->size(), 1);
}

TEST_F(ConfigTest, GetIsolatedDotGates_ReturnsExpected) {
  auto result = original_config.get_isolated_dot_gates();
  ASSERT_NE(result, nullptr);
  EXPECT_GE(result->size(), 1);
}

TEST_F(ConfigTest, GetBarrierGateDict_ReturnsExpected) {
  auto dict = original_config.get_barrier_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->barrier_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

TEST_F(ConfigTest, GetPlungerGateDict_ReturnsExpected) {
  auto dict = original_config.get_plunger_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->plunger_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

TEST_F(ConfigTest, GetReservoirGateDict_ReturnsExpected) {
  auto dict = original_config.get_reservoir_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->reservoir_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

TEST_F(ConfigTest, GetScreeningGateDict_ReturnsExpected) {
  auto dict = original_config.get_screening_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->screening_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

TEST_F(ConfigTest, GetDotGateDict_ReturnsExpected) {
  auto dict = original_config.get_dot_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->dot_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

TEST_F(ConfigTest, GetIsolatedBarrierGatesByChannel_ReturnsExpected) {
  auto dict = original_config.get_isolated_barrier_gates_by_channel();
  ASSERT_NE(dict, nullptr);
  auto channels = original_config.get_current_channels();
  auto isolated = original_config.get_isolated_barrier_gates();
  std::unordered_set<std::string> isolated_names;
  for (const auto& g : *isolated) isolated_names.insert(g->name());
  for (const auto& ch : *channels) {
    if (dict->contains(ch)) {
      auto gates = dict->at(ch);
      for (const auto& g : *gates) EXPECT_TRUE(isolated_names.count(g->name()));
    }
  }
}

TEST_F(ConfigTest, GetIsolatedPlungerGatesByChannel_ReturnsExpected) {
  auto dict = original_config.get_isolated_plunger_gates_by_channel();
  ASSERT_NE(dict, nullptr);
  auto channels = original_config.get_current_channels();
  auto isolated = original_config.get_isolated_plunger_gates();
  std::unordered_set<std::string> isolated_names;
  for (const auto& g : *isolated) isolated_names.insert(g->name());
  for (const auto& ch : *channels) {
    if (dict->contains(ch)) {
      auto gates = dict->at(ch);
      for (const auto& g : *gates) EXPECT_TRUE(isolated_names.count(g->name()));
    }
  }
}

TEST_F(ConfigTest, GetIsolatedReservoirGatesByChannel_ReturnsExpected) {
  auto dict = original_config.get_isolated_reservoir_gates_by_channel();
  ASSERT_NE(dict, nullptr);
  auto channels = original_config.get_current_channels();
  auto isolated = original_config.get_isolated_reservoir_gates();
  std::unordered_set<std::string> isolated_names;
  for (const auto& g : *isolated) isolated_names.insert(g->name());
  for (const auto& ch : *channels) {
    if (dict->contains(ch)) {
      auto gates = dict->at(ch);
      for (const auto& g : *gates) EXPECT_TRUE(isolated_names.count(g->name()));
    }
  }
}

TEST_F(ConfigTest, GetIsolatedScreeningGatesByChannel_ReturnsExpected) {
  auto dict = original_config.get_isolated_screening_gates_by_channel();
  ASSERT_NE(dict, nullptr);
  auto channels = original_config.get_current_channels();
  auto isolated = original_config.get_isolated_screening_gates();
  std::unordered_set<std::string> isolated_names;
  for (const auto& g : *isolated) isolated_names.insert(g->name());
  for (const auto& ch : *channels) {
    if (dict->contains(ch)) {
      auto gates = dict->at(ch);
      for (const auto& g : *gates) EXPECT_TRUE(isolated_names.count(g->name()));
    }
  }
}

TEST_F(ConfigTest, GetIsolatedDotGatesByChannel_ReturnsExpected) {
  auto dict = original_config.get_isolated_dot_gates_by_channel();
  ASSERT_NE(dict, nullptr);
  auto channels = original_config.get_current_channels();
  auto isolated = original_config.get_isolated_dot_gates();
  std::unordered_set<std::string> isolated_names;
  for (const auto& g : *isolated) isolated_names.insert(g->name());
  for (const auto& ch : *channels) {
    if (dict->contains(ch)) {
      auto gates = dict->at(ch);
      for (const auto& g : *gates) EXPECT_TRUE(isolated_names.count(g->name()));
    }
  }
}

TEST_F(ConfigTest, GetSharedChannelGates_PushBackHappens_TwoChannel) {
  // Use a channel that is present in the two_channel_config and has shared
  // gates
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_gates(channel);
  ASSERT_NE(result, nullptr);
  // At least one gate should be present if there is overlap
  EXPECT_GT(result->size(), 0);
  // Optionally, check that all gates in result are in both shared_gates and
  // channel_gates
  auto shared_gates  = two_channel_config.get_shared_gates();
  auto channel_gates = two_channel_config.get_channel_gates(channel);
  for (const auto& gate : *result) {
    bool in_shared  = shared_gates->contains(gate);
    bool in_channel = channel_gates->contains(gate);
    EXPECT_TRUE(in_shared && in_channel);
  }
}

// Helper: Clone the two_channel_config and mutate a group's gate type
static falcon_core::physics::config::core::Config
MakeGroupGateTypeInconsistentConfig(
    std::function<void(
        std::shared_ptr<falcon_core::physics::config::core::Group>&)> mutator,
    const falcon_core::physics::config::core::Config&                 base) {
  using namespace falcon_core::physics::config::core;
  using namespace falcon_core::autotuner_interfaces::names;

  // Deep copy groups
  auto groups_vec =
      std::vector<std::pair<std::shared_ptr<Gname>, std::shared_ptr<Group>>>();
  for (const auto& pair : *base.groups()) {
    auto gname = std::make_shared<Gname>(*pair->first());
    auto group = std::make_shared<Group>(*pair->second());
    mutator(group);
    groups_vec.emplace_back(gname, group);
  }
  auto groups =
      std::make_shared<falcon_core::generic::Map<Gname, Group>>(groups_vec);

  return Config(base.screening_gates(),
                base.plunger_gates(),
                base.ohmics(),
                base.barrier_gates(),
                base.reservoir_gates(),
                groups,
                base.wiring_DC(),
                base.voltage_constraints());
}

TEST_F(ConfigTest, CheckGroupConsistency_ThrowsOnScreeningGate) {
  EXPECT_THROW(MakeGroupGateTypeInconsistentConfig(
                   [](auto& group) {
                     group->screening_gates()->push_back(
                         falcon_core::physics::device_structures::Connection::
                             ScreeningGate("SG999"));
                   },
                   two_channel_config),
               std::logic_error);
}

TEST_F(ConfigTest, CheckGroupConsistency_ThrowsOnReservoirGate) {
  EXPECT_THROW(MakeGroupGateTypeInconsistentConfig(
                   [](auto& group) {
                     group->reservoir_gates()->push_back(
                         falcon_core::physics::device_structures::Connection::
                             ReservoirGate("R999"));
                   },
                   two_channel_config),
               std::logic_error);
}

TEST_F(ConfigTest, CheckGroupConsistency_ThrowsOnPlungerGate) {
  EXPECT_THROW(MakeGroupGateTypeInconsistentConfig(
                   [](auto& group) {
                     group->plunger_gates()->push_back(
                         falcon_core::physics::device_structures::Connection::
                             PlungerGate("P999"));
                   },
                   two_channel_config),
               std::logic_error);
}

TEST_F(ConfigTest, CheckGroupConsistency_ThrowsOnBarrierGate) {
  EXPECT_THROW(MakeGroupGateTypeInconsistentConfig(
                   [](auto& group) {
                     group->barrier_gates()->push_back(
                         falcon_core::physics::device_structures::Connection::
                             BarrierGate("B999"));
                   },
                   two_channel_config),
               std::logic_error);
}

TEST_F(ConfigTest, CheckGroupConsistency_ThrowsOnOhmic) {
  EXPECT_THROW(
      MakeGroupGateTypeInconsistentConfig(
          [](auto& group) {
            group->ohmics()->push_back(
                falcon_core::physics::device_structures::Connection::Ohmic(
                    "O999"));
          },
          two_channel_config),
      std::logic_error);
}

TEST_F(ConfigTest, GetSharedChannelBarrierGates_PushBackHappens_TwoChannel) {
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_barrier_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result->size(), 0);
  auto shared_gates  = two_channel_config.get_shared_barrier_gates();
  auto channel_gates = two_channel_config.get_channel_barrier_gates(channel);
  for (const auto& gate : *result) {
    EXPECT_TRUE(shared_gates->contains(gate));
    EXPECT_TRUE(channel_gates->contains(gate));
  }
}

TEST_F(ConfigTest, GetSharedChannelPlungerGates_PushBackHappens_TwoChannel) {
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_plunger_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result->size(), 0);
  auto shared_gates  = two_channel_config.get_shared_plunger_gates();
  auto channel_gates = two_channel_config.get_channel_plunger_gates(channel);
  for (const auto& gate : *result) {
    EXPECT_TRUE(shared_gates->contains(gate));
    EXPECT_TRUE(channel_gates->contains(gate));
  }
}

TEST_F(ConfigTest, GetSharedChannelReservoirGates_PushBackHappens_TwoChannel) {
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_reservoir_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result->size(), 0);
  auto shared_gates  = two_channel_config.get_shared_reservoir_gates();
  auto channel_gates = two_channel_config.get_channel_reservoir_gates(channel);
  for (const auto& gate : *result) {
    EXPECT_TRUE(shared_gates->contains(gate));
    EXPECT_TRUE(channel_gates->contains(gate));
  }
}

TEST_F(ConfigTest, GetSharedChannelScreeningGates_PushBackHappens_TwoChannel) {
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_screening_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
  auto shared_gates  = two_channel_config.get_shared_screening_gates();
  auto channel_gates = two_channel_config.get_channel_screening_gates(channel);
  for (const auto& gate : *result) {
    EXPECT_TRUE(shared_gates->contains(gate));
    EXPECT_TRUE(channel_gates->contains(gate));
  }
}

TEST_F(ConfigTest, GetSharedChannelDotGates_PushBackHappens_TwoChannel) {
  auto channel = std::make_shared<Channel>("CH1");
  auto result  = two_channel_config.get_shared_channel_dot_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result->size(), 0);
  auto shared_gates  = two_channel_config.get_shared_dot_gates();
  auto channel_gates = two_channel_config.get_channel_dot_gates(channel);
  for (const auto& gate : *result) {
    EXPECT_TRUE(shared_gates->contains(gate));
    EXPECT_TRUE(channel_gates->contains(gate));
  }
}

TEST_F(ConfigTest, GetIsolatedChannelBarrierGates_NoIsolatedGatesFound) {
  auto channel = std::make_shared<Channel>("CH2");
  auto result  = two_channel_config.get_isolated_channel_barrier_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
}

TEST_F(ConfigTest, GetIsolatedChannelPlungerGates_NoIsolatedGatesFound) {
  auto channel = std::make_shared<Channel>("CH2");
  auto result  = two_channel_config.get_isolated_channel_plunger_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
}

TEST_F(ConfigTest, GetIsolatedChannelReservoirGates_NoIsolatedGatesFound) {
  auto channel = std::make_shared<Channel>("CH2");
  auto result =
      two_channel_config.get_isolated_channel_reservoir_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
}

TEST_F(ConfigTest, GetIsolatedChannelScreeningGates_NoIsolatedGatesFound) {
  auto channel = std::make_shared<Channel>("CH2");
  auto result =
      two_channel_config.get_isolated_channel_screening_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
}

TEST_F(ConfigTest, GetIsolatedChannelDotGates_NoIsolatedGatesFound) {
  auto channel = std::make_shared<Channel>("CH2");
  auto result  = two_channel_config.get_isolated_channel_dot_gates(channel);
  ASSERT_NE(result, nullptr);
  EXPECT_GT(result->size(), 0);
}

TEST_F(ConfigTest, GetGateDictWorks) {
  auto dict = original_config.get_gate_dict();
  ASSERT_NE(dict, nullptr);
  auto groups = original_config.get_all_groups();
  for (const auto& group : *groups) {
    auto key   = group->name();
    auto gates = group->get_all_gates();
    ASSERT_TRUE(dict->contains(key));
    auto mapped = dict->at(key);
    ASSERT_EQ(mapped->size(), gates->size());
    for (size_t i = 0; i < gates->size(); ++i)
      EXPECT_EQ((*mapped)[i]->name(), (*gates)[i]->name());
  }
}

class EmptyGateConfigTest : public ::testing::Test {
 protected:
  falcon_core::physics::config::core::ConfigSP config_with_empty_gate_lists;

  EmptyGateConfigTest() {
    auto empty_list = std::make_shared<Connections>();
    auto p_list = std::make_shared<Connections>(
        std::vector<ConnectionSP>{Connection::PlungerGate("P1")});
    auto r_list = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::ReservoirGate("R1"), Connection::ReservoirGate("R2")});
    auto b_list = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::BarrierGate("B1"), Connection::BarrierGate("B2")});
    auto o_list = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::Ohmic("O1"),       Connection::ReservoirGate("R1"),
        Connection::BarrierGate("B1"), Connection::PlungerGate("P1"),
        Connection::BarrierGate("B2"), Connection::ReservoirGate("R2"),
        Connection::Ohmic("O2")});
    auto screening_gates_for_group = std::make_shared<Connections>(
        std::vector<ConnectionSP>{Connection::ScreeningGate("SG1"),
                                  Connection::ScreeningGate("SG2")});

    auto gname = std::make_shared<Gname>("g1");
    auto channel = std::make_shared<Channel>("CH1");
    auto group   = std::make_shared<falcon_core::physics::config::core::Group>(
        channel,
        1,
        screening_gates_for_group,
        r_list,
        p_list,
        b_list,
        o_list);
    auto groups = std::make_shared<
        falcon_core::generic::Map<Gname,
                                  falcon_core::physics::config::core::Group>>(
        std::vector<std::pair<std::shared_ptr<Gname>,
                              std::shared_ptr<
                                  falcon_core::physics::config::core::Group>>>{
            {gname, group}});

    auto wiring = std::make_shared<Impedances>(std::vector<ImpedanceSP>{
        std::make_shared<Impedance>(Connection::PlungerGate("P1"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::Ohmic("O1"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::Ohmic("O2"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::ReservoirGate("R1"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::ReservoirGate("R2"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::BarrierGate("B1"), 1.0, 1.0),
        std::make_shared<Impedance>(Connection::BarrierGate("B2"), 1.0, 1.0)});
    auto adj_indexes = std::make_shared<Connections>(std::vector<ConnectionSP>{
        Connection::PlungerGate("P1"),       Connection::Ohmic("O1"),
        Connection::Ohmic("O2"),       Connection::ReservoirGate("R1"),
        Connection::ReservoirGate("R2"), Connection::BarrierGate("B1"),
        Connection::BarrierGate("B2")});
    auto adj         = std::make_shared<
        falcon_core::physics::config::core::Adjacency>(
        xt::eye(7), adj_indexes);
    auto constraints =
        std::make_shared<falcon_core::physics::config::core::VoltageConstraints>(
            adj, 1.0, std::make_pair(-1.0, 1.0));

    config_with_empty_gate_lists =
        std::make_shared<falcon_core::physics::config::core::Config>(empty_list,
                                                   p_list,
                                                   o_list,
                                                   b_list,
                                                   r_list,
                                                   groups,
                                                   wiring,
                                                   constraints);
  }
};

TEST_F(EmptyGateConfigTest, GetGates_EmptyListThrows) {
  EXPECT_THROW(config_with_empty_gate_lists->get_isolated_barrier_gates(),
               std::runtime_error);
  EXPECT_THROW(config_with_empty_gate_lists->get_isolated_reservoir_gates(),
               std::runtime_error);
  EXPECT_THROW(config_with_empty_gate_lists->get_isolated_screening_gates(),
               std::runtime_error);

  EXPECT_THROW(config_with_empty_gate_lists->get_shared_barrier_gates(),
               std::runtime_error);
  EXPECT_THROW(config_with_empty_gate_lists->get_shared_reservoir_gates(),
               std::runtime_error);
  EXPECT_THROW(config_with_empty_gate_lists->get_shared_screening_gates(),
               std::runtime_error);
}

}  // namespace
