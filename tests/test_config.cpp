#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <algorithm>
#include <string>

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/autotuner_interfaces/names/Gname.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/config/core/Adjacency.hpp"
#include "falcon_core/physics/config/core/Config.hpp"
#include "falcon_core/physics/config/core/Group.hpp"
#include "falcon_core/physics/config/core/VoltageConstraints.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::autotuner_interfaces::names;
class ConfigTestFixture : public ::testing::Test {
 protected:
  falcon_core::physics::config::core::Config original_config;

  ConfigTestFixture()
      : original_config(
            std::make_shared<ScreeningGates>(std::vector<ScreeningGateSP>{
                std::make_shared<ScreeningGate>("SG1"),
                std::make_shared<ScreeningGate>("SG2")}),
            std::make_shared<PlungerGates>(std::vector<PlungerGateSP>{
                std::make_shared<PlungerGate>("P1"),
                std::make_shared<PlungerGate>("P2")}),
            std::make_shared<Ohmics>(std::vector<OhmicSP>{
                std::make_shared<Ohmic>("O1"), std::make_shared<Ohmic>("O2")}),
            std::make_shared<BarrierGates>(std::vector<BarrierGateSP>{
                std::make_shared<BarrierGate>("B1"),
                std::make_shared<BarrierGate>("B2"),
                std::make_shared<BarrierGate>("B3")}),
            std::make_shared<ReservoirGates>(std::vector<ReservoirGateSP>{
                std::make_shared<ReservoirGate>("R1"),
                std::make_shared<ReservoirGate>("R2")}),
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
                         std::make_shared<ScreeningGates>(
                             std::vector<ScreeningGateSP>{
                                 std::make_shared<ScreeningGate>("SG1"),
                                 std::make_shared<ScreeningGate>("SG2")}),
                         std::make_shared<ReservoirGates>(
                             std::vector<ReservoirGateSP>{
                                 std::make_shared<ReservoirGate>("R1"),
                                 std::make_shared<ReservoirGate>("R2")}),
                         std::make_shared<PlungerGates>(
                             std::vector<PlungerGateSP>{
                                 std::make_shared<PlungerGate>("P1"),
                                 std::make_shared<PlungerGate>("P2")}),
                         std::make_shared<BarrierGates>(
                             std::vector<BarrierGateSP>{
                                 std::make_shared<BarrierGate>("B1"),
                                 std::make_shared<BarrierGate>("B2"),
                                 std::make_shared<BarrierGate>("B3")}),
                         std::make_shared<BaseConnections<BaseConnection>>(
                             std::vector<std::shared_ptr<BaseConnection>>{
                                 std::make_shared<Ohmic>("O1"),
                                 std::make_shared<ReservoirGate>("R1"),
                                 std::make_shared<BarrierGate>("B1"),
                                 std::make_shared<PlungerGate>("P1"),
                                 std::make_shared<BarrierGate>("B2"),
                                 std::make_shared<PlungerGate>("P2"),
                                 std::make_shared<BarrierGate>("B3"),
                                 std::make_shared<ReservoirGate>("R2"),
                                 std::make_shared<Ohmic>("O2"),
                             }))}}),
            std::make_shared<Impedances>(std::vector<ImpedanceSP>{
                std::make_shared<Impedance>(
                    std::make_shared<Ohmic>("O1"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<Ohmic>("O2"), 1000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<BarrierGate>("B1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<BarrierGate>("B2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<BarrierGate>("B3"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<PlungerGate>("P1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<PlungerGate>("P2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<ReservoirGate>("R1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<ReservoirGate>("R2"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<ScreeningGate>("SG1"), 10000.0, 1e-12),
                std::make_shared<Impedance>(
                    std::make_shared<ScreeningGate>("SG2"), 10000.0, 1e-12),
            }),
            std::make_shared<
                falcon_core::physics::config::core::VoltageConstraints>(
                std::make_shared<falcon_core::physics::config::core::Adjacency>(
                    Eigen::MatrixXi::Identity(9, 9),
                    std::make_shared<Gates<Gate>>(std::vector<GateSP>{
                        std::make_shared<ScreeningGate>("SG1"),
                        std::make_shared<ScreeningGate>("SG2"),
                        std::make_shared<PlungerGate>("P1"),
                        std::make_shared<PlungerGate>("P2"),
                        std::make_shared<BarrierGate>("B1"),
                        std::make_shared<BarrierGate>("B2"),
                        std::make_shared<BarrierGate>("B3"),
                        std::make_shared<ReservoirGate>("R1"),
                        std::make_shared<ReservoirGate>("R2"),
                    })),
                1.0,
                std::make_pair(-1.0, 1.0))) {}

  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(ConfigTestFixture, JsonRoundTrip) {
  // Use the fixture's original_config
  std::string json_str = original_config.to_json_string();
  ASSERT_FALSE(json_str.empty());

  // Deserialize from JSON
  auto deserialized_config =
      *falcon_core::physics::config::core::Config::from_json_string<
          falcon_core::physics::config::core::Config>(json_str);

  // Verify basic properties are preserved
  ASSERT_EQ(deserialized_config.num_unique_channels(),
            original_config.num_unique_channels());
  ASSERT_EQ(deserialized_config.groups()->size(),
            original_config.groups()->size());

  // Compare channels
  std::vector<std::string> ch1, ch2;
  for (const auto& c : *deserialized_config.channels())
    ch1.push_back(c->name());
  for (const auto& c : *original_config.channels()) ch2.push_back(c->name());
  std::sort(ch1.begin(), ch1.end());
  std::sort(ch2.begin(), ch2.end());
  ASSERT_EQ(ch1, ch2);

  // Compare gates
  ASSERT_EQ(deserialized_config.get_all_gates()->size(),
            original_config.get_all_gates()->size());
  std::vector<std::string> g1, g2;
  for (const auto& g : *deserialized_config.get_all_gates())
    g1.push_back(g->name());
  for (const auto& g : *original_config.get_all_gates())
    g2.push_back(g->name());
  std::sort(g1.begin(), g1.end());
  std::sort(g2.begin(), g2.end());
  ASSERT_EQ(g1, g2);

  // Compare ohmics
  ASSERT_EQ(deserialized_config.ohmics()->size(),
            original_config.ohmics()->size());
  std::vector<std::string> o1, o2;
  for (const auto& o : *deserialized_config.ohmics()) o1.push_back(o->name());
  for (const auto& o : *original_config.ohmics()) o2.push_back(o->name());
  std::sort(o1.begin(), o1.end());
  std::sort(o2.begin(), o2.end());
  ASSERT_EQ(o1, o2);

  // Compare impedances
  ASSERT_EQ(deserialized_config.wiring_DC()->size(),
            original_config.wiring_DC()->size());
  auto sort_by_conn = [](const ImpedanceSP& a, const ImpedanceSP& b) {
    return a->connection()->name() < b->connection()->name();
  };
  auto w1 = *deserialized_config.wiring_DC(), w2 = *original_config.wiring_DC();
  std::sort(w1.begin(), w1.end(), sort_by_conn);
  std::sort(w2.begin(), w2.end(), sort_by_conn);
  for (size_t i = 0; i < w1.size(); ++i) {
    ASSERT_EQ(w1[i]->connection()->name(), w2[i]->connection()->name());
    ASSERT_EQ(w1[i]->resistance(), w2[i]->resistance());
    ASSERT_EQ(w1[i]->capacitance(), w2[i]->capacitance());
  }

  // Test that we can re-serialize the deserialized object
  std::string json_str2 = deserialized_config.to_json_string();
  ASSERT_FALSE(json_str2.empty());
}
TEST_F(ConfigTestFixture, BasicQueries) {
  auto gnames = original_config.get_all_gnames();
  auto groups = original_config.get_all_groups();
  ASSERT_EQ(gnames.size(), groups.size());
  for (size_t i = 0; i < gnames.size(); ++i) {
    ASSERT_TRUE(groups[i]);
    ASSERT_TRUE(gnames[i]);
  }

  // Test compile_channels and has_channel
  auto channels = original_config.get_current_channels();
  ASSERT_TRUE(channels);
  for (const auto& ch : *channels) {
    ASSERT_TRUE(original_config.has_channel(ch));
  }

  // Test has_gname and select_group
  for (const auto& gn : gnames) {
    ASSERT_TRUE(original_config.has_gname(gn));
    auto group = original_config.select_group(gn);
    ASSERT_TRUE(group);
  }

  // Test get_dot_number
  for (const auto& ch : *channels) {
    int dots = original_config.get_dot_number(ch);
    ASSERT_GE(dots, 0);
  }

  // Test get_charge_sense_groups (should not throw, may be empty)
  auto charge_sense = original_config.get_charge_sense_groups();

  // Test ohmic_in_charge_sensor (should not throw, may be false)
  for (const auto& o : *original_config.ohmics()) {
    original_config.ohmic_in_charge_sensor(o);
  }

  // Test get_associated_ohmic (should not throw, may be nullptr)
  for (const auto& r : *original_config.reservoir_gates()) {
    original_config.get_associated_ohmic(r);
  }

  // Test get_gname and get_channel_gates
  for (const auto& ch : *channels) {
    auto gn = original_config.get_gname(ch);
    if (gn) {
      auto bg = original_config.get_channel_gates(
          ch, std::make_shared<BarrierGate>("B1"));
      auto pg = original_config.get_channel_gates(
          ch, std::make_shared<PlungerGate>("P1"));
      auto rg = original_config.get_channel_gates(
          ch, std::make_shared<ReservoirGate>("R1"));
      auto sg = original_config.get_channel_gates(
          ch, std::make_shared<ScreeningGate>("SG1"));
      // Just check that these calls do not throw and return something (may be
      // nullptr)
    }
  }

  // Test get_isolated_gates and get_shared_gates
  auto isolated_barriers =
      original_config.get_isolated_gates(std::make_shared<BarrierGate>("B1"));
  auto shared_barriers =
      original_config.get_shared_gates(std::make_shared<BarrierGate>("B1"));
  // Should not throw, may be empty

  // Test get_isolated_channel_gates
  for (const auto& ch : *channels) {
    auto iso = original_config.get_isolated_channel_gates(
        std::make_shared<BarrierGate>("B1"), ch);
    // Should not throw, may be empty
  }

  // Test get_isolated_gates_by_type
  auto iso_map = original_config.get_isolated_gates_by_type(
      std::make_shared<BarrierGate>("B1"));
  // Should not throw, may be empty

  // Test generate_gate_relations
  auto relations = original_config.generate_gate_relations();
  ASSERT_TRUE(relations);

  // Test get_impedance for all connections
  for (const auto& conn : *original_config.get_all_connections()) {
    original_config.get_impedance(*conn);
  }
}
