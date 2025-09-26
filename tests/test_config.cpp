#include <gtest/gtest.h>

#include <fstream>
#include <memory>

#include "falcon_core/physics/config/Loader.hpp"
#include "falcon_core/physics/config/core/Config.hpp"
namespace tests {
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::autotuner_interfaces::names;
class ConfigTestFixture : public ::testing::Test {
 protected:
  falcon_core::physics::config::core::Config original_config;

  ConfigTestFixture()
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
  ASSERT_EQ(gnames->size(), groups->size());
  for (size_t i = 0; i < gnames->size(); ++i) {
    ASSERT_TRUE(groups->items()[i]);
    ASSERT_TRUE(gnames->items()[i]);
  }

  // Test compile_channels and has_channel
  auto channels = original_config.get_current_channels();
  ASSERT_TRUE(channels);
  for (const auto& ch : *channels) {
    ASSERT_TRUE(original_config.has_channel(ch));
  }

  // Test has_gname and select_group
  for (const auto& gn : *gnames) {
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
      auto bg = original_config.get_channel_barrier_gates(ch);
      auto pg = original_config.get_channel_plunger_gates(ch);
      auto rg = original_config.get_channel_reservoir_gates(ch);
      auto sg = original_config.get_channel_screening_gates(ch);
      // Just check that these calls do not throw and return something (may be
      // nullptr)
    }
  }

  // Test get_isolated_gates and get_shared_gates
  auto isolated_barriers = original_config.get_isolated_barrier_gates();
  auto shared_barriers   = original_config.get_shared_barrier_gates();
  // Should not throw, may be empty

  // Test get_isolated_channel_gates
  for (const auto& ch : *channels) {
    auto iso = original_config.get_isolated_channel_gates(ch);
    // Should not throw, may be empty
  }

  // Test get_isolated_gates_by_type
  auto iso_map = original_config.get_isolated_gates_by_channel();
  // Should not throw, may be empty

  // Test generate_gate_relations
  auto relations = original_config.generate_gate_relations();
  ASSERT_TRUE(relations);

  // Test get_impedance for all connections
  for (const auto& conn : *original_config.get_all_connections()) {
    original_config.get_impedance(*conn);
  }
}
TEST(ConfigLoaderTest, LoadConfigFromYaml) {
  // Write YAML to a temp file
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
}  // namespace tests
