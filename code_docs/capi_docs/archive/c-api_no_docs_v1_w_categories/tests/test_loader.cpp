#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include <boost/filesystem.hpp>
#include <fstream>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/Loader_c_api.h"
#include "falcon_core/physics/config/core/Config_c_api.h"

class LoaderTest : public ::testing::Test {
 protected:
  boost::filesystem::path yaml_path;
  std::string             yaml_content;
  LoaderHandle            loader;

  void SetUp() override {
    yaml_content =
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
    yaml_path = boost::filesystem::unique_path();
    std::ofstream out(yaml_path.string());
    out << yaml_content;
    out.close();
    StringHandle path_str =
        String_create(yaml_path.string().c_str(), yaml_path.string().size());
    loader = Loader_create(path_str);
    String_destroy(path_str);
  }

  void TearDown() override {
    Loader_destroy(loader);
    boost::filesystem::remove(yaml_path);
  }
};

TEST_F(LoaderTest, LoaderConfigReturnsConfig) {
  ConfigHandle cfg = Loader_config(loader);
  EXPECT_NE(cfg, nullptr);
  EXPECT_EQ(Config_num_unique_channels(cfg), 2);
  Config_destroy(cfg);
}

TEST_F(LoaderTest, ThrowsOnMissingFile) {
  StringHandle bad_path = String_create("/tmp/nonexistent_config.yaml", 27);
  set_last_error(0, nullptr);
  Loader_create(bad_path);
  EXPECT_EQ(get_last_error_code(), 1);
  String_destroy(bad_path);
}

TEST_F(LoaderTest, ThrowsOnNullPath) {
  set_last_error(0, nullptr);
  Loader_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LoaderTest, DestroyThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Loader_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LoaderTest, ConfigThrowsOnNullHandle) {
  set_last_error(0, nullptr);
  Loader_config(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
