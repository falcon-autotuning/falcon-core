#include <gtest/gtest.h>

#include <boost/filesystem.hpp>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "falcon-core/physics/config/Loader.hpp"

namespace {

using namespace falcon_core::physics::config;
using namespace falcon_core::physics::config::core;

std::string basic_config_yaml() {
  return R"yaml(
ScreeningGates: "S1;S2;S3"
PlungerGates: "P1;P2;P3"
Ohmics: "O1;O2;O3;O4"
BarrierGates: "B1;B2;B3;B4;B5"
ReservoirGates: "R1;R2;R3;R4"
num-unique-channels: 2

groups:
  group1:
    Name: "I_O1"
    NumDots: 2
    ScreeningGates: "S1;S2"
    ReservoirGates: "R1;R2"
    PlungerGates: "P1;P2"
    BarrierGates: "B1;B2;B3"
    Order: "O1;R1;B1;P1;B2;P2;B3;R2;O2"

  group2:
    Name: "I_O3"
    NumDots: 1
    ScreeningGates: "S2;S3"
    ReservoirGates: "R3;R4"
    PlungerGates: "P3"
    BarrierGates: "B4;B5"
    Order: "O3;R3;B4;P3;B5;R4;O4"

adjacency:
  S2: "P1;P2;P3;P4;R1;R2;R3;R4;B1;B2;B3;B4;B5"
  S1: "P1;P2;R1;R2;B1;B2;B3"
  S3: "P3;B4;B5;R3;R4"
  B1: "R1;P1"
  B2: "P1;P2"
  B3: "P2;R2"
  B4: "P3;R3"
  B5: "R4;P3"
  O1: "R1"
  O2: "R2"
  O3: "R3"
  O4: "R4"

max_safe_diff: 1.0
safe_voltage_bounds: [-1.0, 1.0]

wiringDC:
  S1: {resistance: 1000.0, capacitance: 1e-12}
  S2: {resistance: 1000.0, capacitance: 1e-12}
  S3: {resistance: 1000.0, capacitance: 1e-12}
  P1: {resistance: 1000.0, capacitance: 1e-12}
  P2: {resistance: 1000.0, capacitance: 1e-12}
  P3: {resistance: 1000.0, capacitance: 1e-12}
  O1: {resistance: 1000.0, capacitance: 1e-12}
  O2: {resistance: 1000.0, capacitance: 1e-12}
  O3: {resistance: 1000.0, capacitance: 1e-12}
  O4: {resistance: 1000.0, capacitance: 1e-12}
  R1: {resistance: 1000.0, capacitance: 1e-12}
  R2: {resistance: 1000.0, capacitance: 1e-12}
  R3: {resistance: 1000.0, capacitance: 1e-12}
  R4: {resistance: 1000.0, capacitance: 1e-12}
  B1: {resistance: 1000.0, capacitance: 1e-12}
  B2: {resistance: 1000.0, capacitance: 1e-12}
  B3: {resistance: 1000.0, capacitance: 1e-12}
  B4: {resistance: 1000.0, capacitance: 1e-12}
  B5: {resistance: 1000.0, capacitance: 1e-12}
)yaml";
}

std::string complex_device_yaml() {
  return R"yaml(
ScreeningGates: "SG1;CG0a;CG0b"
PlungerGates: "P0;P1;P2;P20"
Ohmics: "S0;S1;S2;S3"
BarrierGates: "B0;B1;B2;B3;B20;B21"
ReservoirGates: "AC0;AC1;AC2;AC3"
num-unique-channels: 2
groups:
  group1:
    Name: "Qubit"
    NumDots: 3
    ScreeningGates: "SG1;CG0a"
    ReservoirGates: "AC0;AC1"
    PlungerGates: "P0;P1;P2"
    BarrierGates: "B0;B1;B2;B3"
    Order: "S0;AC0;B0;P0;B1;P1;B2;P2;B3;AC1;S1"
  group2:
    Name: "Sensor"
    NumDots: 1
    ScreeningGates: "SG1;CG0b"
    ReservoirGates: "AC2;AC3"
    PlungerGates: "P20"
    BarrierGates: "B20;B21"
    Order: "S3;AC3;B20;P20;B21;AC2;S2"
adjacency:
  SG1: "AC0;AC1;AC2;AC3;B0;B1;B2;B3;B20;B21;P0;P1;P2;P20"
  CG0a: "AC0;AC1;P0;P1;P2;B0;B1;B2;B3"
  CG0b: "AC2;AC3;P20;B20;B21"
  AC0: "S0;B0"
  AC1: "S1;B3"
  AC2: "S2;B21"
  AC3: "S3;B20"
  P0: "B0;B1"
  P1: "B1;B2"
  P2: "B2;B3"
  P20: "B20;B21"
max_safe_diff: 1.5
safe_voltage_bounds: [-1.5, 1.5] 
wiringDC:
  SG1:
    resistance: 1740 
    capacitance: 0.0000000033 
  AC1:
    resistance: 1740 
    capacitance: 0.0000000033
  S1:
    resistance: 1740 
    capacitance: 0.0000000033
  S2:
    resistance: 101000
    capacitance: 0.0000000043
  AC2:
    resistance: 1740 
    capacitance: 0.0000000033
  P20:
    resistance: 1740 
    capacitance: 0.0000000033
  B21:
    resistance: 1740 
    capacitance: 0.0000000033
  B21:
    resistance: 101000
    capacitance: 0.0000000043
  AC3:
    resistance: 1740 
    capacitance: 0.0000000033
  S3:
    resistance: 1740 
    capacitance: 0.0000000033
  CG0b:
    resistance: 1740 
    capacitance: 0.0000000033
  S0:
    resistance: 1740 
    capacitance: 0.0000000033
  AC0:
    resistance: 1740 
    capacitance: 0.0000000033
  B0:
    resistance: 1740 
    capacitance: 0.0000000033
  P0:
    resistance: 3200
    capacitance: 0.0000001033
  B1:
    resistance: 3200
    capacitance: 0.0000001033
  P1:
    resistance: 3200
    capacitance: 0.0000001033
  P2:
    resistance: 3200
    capacitance: 0.0000001033
  B2:
    resistance: 3200
    capacitance: 0.0000001033
  B3:
    resistance: 3200
    capacitance: 0.0000001033
  CG0a:
    resistance: 1740 
    capacitance: 0.0000000033  
)yaml";
}

class LoaderTest : public ::testing::Test {
protected:
  boost::filesystem::path yaml_path;
  std::vector<boost::filesystem::path> temp_files;

  boost::filesystem::path write_config(const std::string &yaml) {
    auto path = boost::filesystem::unique_path();

    std::ofstream out(path.string());
    out << yaml;
    out.close();

    temp_files.push_back(path);
    return path;
  }

  void SetUp() override { yaml_path = write_config(basic_config_yaml()); }

  void TearDown() override {
    for (const auto &file : temp_files) {
      boost::filesystem::remove(file);
    }
  }
};

TEST_F(LoaderTest, ConstructorWithPathWorks) {
  Loader loader(yaml_path);
  EXPECT_NO_THROW(loader._load_config());
}

TEST_F(LoaderTest, ConstructorWithStringWorks) {
  Loader loader(yaml_path.string());
  EXPECT_NO_THROW(loader._load_config());
}

TEST_F(LoaderTest, LoadConfigReturnsConfig) {
  Loader loader(yaml_path);

  auto cfg = loader._load_config();

  ASSERT_NE(cfg, nullptr);
  EXPECT_EQ(cfg->num_unique_channels(), 2);
}

TEST_F(LoaderTest, ConfigGetterWorks) {
  Loader loader(yaml_path);

  loader._load_config();

  auto cfg = loader.config();

  ASSERT_NE(cfg, nullptr);
  EXPECT_EQ(cfg->groups()->size(), 2);
}

TEST_F(LoaderTest, ThrowsOnMissingFile) {
  EXPECT_THROW(Loader(std::string("/tmp/nonexistent_config.yaml")),
               std::runtime_error);
}

TEST_F(LoaderTest, LoadsRealDeviceConfig) {
  const auto path = write_config(complex_device_yaml());

  Loader loader(path);

  auto cfg = loader._load_config();

  ASSERT_NE(cfg, nullptr);

  EXPECT_EQ(cfg->num_unique_channels(), 2);
  EXPECT_EQ(cfg->groups()->size(), 2);

  auto groups = cfg->groups();

  EXPECT_EQ(groups->at("group1").name(), "Qubit");
  EXPECT_EQ(groups->at("group1").num_dots(), 3);

  EXPECT_EQ(groups->at("group2").name(), "Sensor");
  EXPECT_EQ(groups->at("group2").num_dots(), 1);
}

} // namespace
