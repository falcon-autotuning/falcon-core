#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "falcon_core/physics/config/ConfigManipulations.hpp"
#include "falcon_core/physics/config/core/Config.hpp"
#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
namespace {
using namespace falcon_core::physics::config;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::config::core;

class ConfigManipulationsTest : public ::testing::Test {
 protected:
  ConfigManipulations manip;
  YAML::Node          config;
  void                SetUp() override {
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
    config = YAML::Load(yaml_content);
  }
};

TEST_F(ConfigManipulationsTest, UnpackDeviceConfigWorks) {
  auto cfg = manip.unpack_device_config(config);
  ASSERT_NE(cfg, nullptr);
  EXPECT_EQ(cfg->num_unique_channels(), 2);
  EXPECT_TRUE(cfg->groups()->size() == 2);
}

TEST_F(ConfigManipulationsTest, ExtractStandardConfigConnectionsWorks) {
  auto std_conns = manip._extract_standard_config_connections(config);
  ASSERT_NE(std_conns, nullptr);
  EXPECT_TRUE(std_conns->plunger_gates()->size() == 3);
  EXPECT_TRUE(std_conns->barrier_gates()->size() == 5);
  EXPECT_TRUE(std_conns->reservoir_gates()->size() == 4);
  EXPECT_TRUE(std_conns->screening_gates()->size() == 3);
  EXPECT_TRUE(std_conns->ohmics()->size() == 4);
}

TEST_F(ConfigManipulationsTest, ExtractBarrierGatesWorks) {
  auto gates = manip._extract_barrier_gates("B1;B2;B3;B4;B5");
  EXPECT_EQ(gates->size(), 5);
}

TEST_F(ConfigManipulationsTest, ExtractPlungerGatesWorks) {
  auto gates = manip._extract_plunger_gates("P1;P2;P3");
  EXPECT_EQ(gates->size(), 3);
}

TEST_F(ConfigManipulationsTest, ExtractReservoirGatesWorks) {
  auto gates = manip._extract_reservoir_gates("R1;R2;R3;R4");
  EXPECT_EQ(gates->size(), 4);
}

TEST_F(ConfigManipulationsTest, ExtractScreeningGatesWorks) {
  auto gates = manip._extract_screening_gates("S1;S2;S3");
  EXPECT_EQ(gates->size(), 3);
}

TEST_F(ConfigManipulationsTest, ExtractOhmicsWorks) {
  auto gates = manip._extract_ohmics("O1;O2;O3;O4");
  EXPECT_EQ(gates->size(), 4);
}

TEST_F(ConfigManipulationsTest, ExtractOrderWorks) {
  auto std_conns = manip._extract_standard_config_connections(config);
  auto order = manip._extract_order("O1;R1;B1;P1;B2;P2;B3;R2;O2", std_conns);
  EXPECT_EQ(order->size(), 9);
}
}  // namespace
