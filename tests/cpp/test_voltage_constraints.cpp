#include <gtest/gtest.h>

#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/physics/config/core/Adjacency.hpp"
#include "falcon-core/physics/config/core/VoltageConstraints.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;

class VoltageConstraintsTest : public ::testing::Test {
protected:
  AdjacencySP adjacency;
  xt::xarray<int> adj_matrix;
  double max_safe_diff;
  std::pair<double, double> bounds;
  falcon_core::instrument_interfaces::names::PortsSP ports;

  void SetUp() override {
    auto indexes = std::make_shared<Connections>();
    indexes->push_back(Connection::Ohmic("O1"));
    indexes->push_back(Connection::ReservoirGate("R1"));
    indexes->push_back(Connection::BarrierGate("B1"));
    ports =
        std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
    ports->push_back(
        falcon_core::instrument_interfaces::names::InstrumentPort::Meter(
            "ohmicTest", Connection::Ohmic("O1")));
    ports->push_back(
        falcon_core::instrument_interfaces::names::InstrumentPort::Knob(
            "reservoirTest", Connection::ReservoirGate("R1")));
    ports->push_back(
        falcon_core::instrument_interfaces::names::InstrumentPort::Knob(
            "barrierTest", Connection::BarrierGate("B1")));
    adj_matrix = xt::xarray<int>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    adjacency = std::make_shared<Adjacency>(adj_matrix, indexes);
    max_safe_diff = 1.5;
    bounds = {0.0, 5.0};
  }
};

TEST_F(VoltageConstraintsTest, ConstructorValid) {
  EXPECT_NO_THROW(VoltageConstraints vc(adjacency, max_safe_diff, bounds));
}

TEST_F(VoltageConstraintsTest, ConstructorNullptrAdjacencyThrows) {
  EXPECT_THROW(VoltageConstraints vc(nullptr, max_safe_diff, bounds),
               std::invalid_argument);
}

TEST_F(VoltageConstraintsTest, AdjacencyReturnsExpected) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_EQ(vc.adjacency(), adjacency);
}

TEST_F(VoltageConstraintsTest, MaxSafeDiffReturnsExpected) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_EQ(vc.max_safe_diff(), max_safe_diff);
}

TEST_F(VoltageConstraintsTest, MinBoundReturnsExpected) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_EQ(vc.min_bound(), bounds.first);
}

TEST_F(VoltageConstraintsTest, MaxBoundReturnsExpected) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_EQ(vc.max_bound(), bounds.second);
}

TEST_F(VoltageConstraintsTest, ComputeOneNeighborDomainRequest) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP current_state =
      std::make_shared<cv::DeviceVoltageStates>();
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  auto search_domain =
      std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
  search_domain->push_back(ports->at(0));
  auto maximal_domain = vc.compute_maximal_domain(search_domain, current_state);
  EXPECT_NE(maximal_domain, nullptr) << "Maximal domain should not be null";
  int size = maximal_domain->size();
  EXPECT_EQ(size, 1) << "Unexpected number of domains in maximal domain. Got "
                     << std::to_string(size) << ", expected 1.";
  double lesser_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound, 0.0) << "Unexpected lesser bound. Got " +
                                             std::to_string(lesser_bound) +
                                             ", expected 0.0.";
  double greater_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound, 2.5) << "Unexpected greater bound. Got " +
                                              std::to_string(greater_bound) +
                                              ", expected 2.5.";
}

TEST_F(VoltageConstraintsTest, ComputeTwoNeighborDomainRequest) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP current_state =
      std::make_shared<cv::DeviceVoltageStates>();
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  auto search_domain =
      std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
  search_domain->push_back(ports->at(1));
  auto maximal_domain = vc.compute_maximal_domain(search_domain, current_state);
  EXPECT_NE(maximal_domain, nullptr) << "Maximal domain should not be null";
  int size = maximal_domain->size();
  EXPECT_EQ(size, 1) << "Unexpected number of domains in maximal domain. Got "
                     << std::to_string(size) << ", expected 1.";
  double lesser_bound =
      maximal_domain->get_domain(ports->at(1))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound, 0.0) << "Unexpected lesser bound. Got " +
                                             std::to_string(lesser_bound) +
                                             ", expected 0.0.";
  double greater_bound =
      maximal_domain->get_domain(ports->at(1))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound, 1.5) << "Unexpected greater bound. Got " +
                                              std::to_string(greater_bound) +
                                              ", expected 1.5.";
}

TEST_F(VoltageConstraintsTest, ComputeDoubleDomainRequest) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP current_state =
      std::make_shared<cv::DeviceVoltageStates>();
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 4.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  auto search_domain =
      std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
  search_domain->push_back(ports->at(0));
  search_domain->push_back(ports->at(2));
  auto maximal_domain = vc.compute_maximal_domain(search_domain, current_state);
  EXPECT_NE(maximal_domain, nullptr) << "Maximal domain should not be null";
  int size = maximal_domain->size();
  EXPECT_EQ(size, 2) << "Unexpected number of domains in maximal domain. Got "
                     << std::to_string(size) << ", expected 2.";
  double lesser_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound, 2.5) << "Unexpected lesser bound. Got " +
                                             std::to_string(lesser_bound) +
                                             ", expected 1.5.";
  double greater_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound, 5.0) << "Unexpected greater bound. Got " +
                                              std::to_string(greater_bound) +
                                              ", expected 5.0.";
  double lesser_bound2 =
      maximal_domain->get_domain(ports->at(2))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound2, 2.5) << "Unexpected lesser bound. Got " +
                                              std::to_string(lesser_bound2) +
                                              ", expected 1.5.";
  double greater_bound2 =
      maximal_domain->get_domain(ports->at(2))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound2, 5.0) << "Unexpected greater bound. Got " +
                                               std::to_string(greater_bound2) +
                                               ", expected 5.0.";
}

TEST_F(VoltageConstraintsTest, ComputeUnboundedDoubleDomainRequest) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP current_state =
      std::make_shared<cv::DeviceVoltageStates>();
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 4.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  auto search_domain =
      std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
  search_domain->push_back(ports->at(0));
  search_domain->push_back(ports->at(1));
  auto maximal_domain = vc.compute_maximal_domain(search_domain, current_state);
  EXPECT_NE(maximal_domain, nullptr) << "Maximal domain should not be null";
  int size = maximal_domain->size();
  EXPECT_EQ(size, 2) << "Unexpected number of domains in maximal domain. Got "
                     << std::to_string(size) << ", expected 2.";
  double lesser_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound, 0.0) << "Unexpected lesser bound. Got " +
                                             std::to_string(lesser_bound) +
                                             ", expected 0.0.";
  double greater_bound =
      maximal_domain->get_domain(ports->at(0))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound, 5.0) << "Unexpected greater bound. Got " +
                                              std::to_string(greater_bound) +
                                              ", expected 5.0.";
  double lesser_bound2 =
      maximal_domain->get_domain(ports->at(1))->domain()->lesser_bound();
  EXPECT_DOUBLE_EQ(lesser_bound2, 0.0) << "Unexpected lesser bound. Got " +
                                              std::to_string(lesser_bound2) +
                                              ", expected 0.0.";
  double greater_bound2 =
      maximal_domain->get_domain(ports->at(1))->domain()->greater_bound();
  EXPECT_DOUBLE_EQ(greater_bound2, 2.5) << "Unexpected greater bound. Got " +
                                               std::to_string(greater_bound2) +
                                               ", expected 2.5.";
}

TEST_F(VoltageConstraintsTest, ValidateVoltageStateValid) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP voltage_state =
      std::make_shared<cv::DeviceVoltageStates>();
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  EXPECT_TRUE(vc.validate_voltage_state(voltage_state->to_point()));
}

TEST_F(VoltageConstraintsTest, ValidateVoltageStateInvalidDueToBounds) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP voltage_state =
      std::make_shared<cv::DeviceVoltageStates>();
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), -1.0, // Invalid
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  EXPECT_FALSE(vc.validate_voltage_state(voltage_state->to_point()));
}

TEST_F(VoltageConstraintsTest, ValidateVoltageStateInvalidDueToSafeDiff) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP voltage_state =
      std::make_shared<cv::DeviceVoltageStates>();
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::ReservoirGate("R1"), 3.0, // Invalid
      falcon_core::physics::units::SymbolUnit::Volt()));
  voltage_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::BarrierGate("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  EXPECT_FALSE(vc.validate_voltage_state(voltage_state->to_point()));
}

TEST_F(VoltageConstraintsTest, ValidateVoltageStateInvalidNullptr) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  EXPECT_THROW(vc.validate_voltage_state(nullptr), std::invalid_argument);
}

TEST_F(VoltageConstraintsTest, ComputeMaximalDomainNullptrStateThrows) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  auto search_domain =
      std::make_shared<falcon_core::instrument_interfaces::names::Ports>();
  search_domain->push_back(ports->at(0));
  EXPECT_THROW(vc.compute_maximal_domain(search_domain, nullptr),
               std::invalid_argument);
}

TEST_F(VoltageConstraintsTest, ComputeMaximalDomainNullptrSearchDomainThrows) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  namespace cv = falcon_core::communications::voltage_states;
  cv::DeviceVoltageStatesSP current_state =
      std::make_shared<cv::DeviceVoltageStates>();
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("O1"), 0.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("R1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  current_state->add_state(std::make_shared<cv::DeviceVoltageState>(
      Connection::Ohmic("B1"), 1.0,
      falcon_core::physics::units::SymbolUnit::Volt()));
  EXPECT_THROW(vc.compute_maximal_domain(nullptr, current_state),
               std::invalid_argument);
}

TEST_F(VoltageConstraintsTest, SerializationRoundTrip) {
  VoltageConstraints vc(adjacency, max_safe_diff, bounds);
  auto string = vc.to_json_string();
  auto loaded =
      VoltageConstraints::from_json_string<VoltageConstraints>(string);
  EXPECT_EQ(vc, *loaded);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorTrueForIdentical) {
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adjacency, max_safe_diff, bounds);
  EXPECT_TRUE(vc1 == vc2);
  EXPECT_FALSE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentLimits) {
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adjacency, max_safe_diff, std::make_pair(1.0, 5.0));
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentAdjacency) {
  auto indexes2 = std::make_shared<Connections>();
  indexes2->push_back(Connection::Ohmic("O1"));
  indexes2->push_back(Connection::ReservoirGate("R1"));
  indexes2->push_back(Connection::BarrierGate("B2")); // Different
  auto adj2 = std::make_shared<Adjacency>(adj_matrix, indexes2);
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adj2, max_safe_diff, bounds);
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}

TEST_F(VoltageConstraintsTest, EqualityOperatorFalseForDifferentMatrix) {
  xt::xarray<int> other_matrix{{0, 0, 0}, {0, 0, 1}, {0, 1, 0}};
  auto adj2 = std::make_shared<Adjacency>(other_matrix, adjacency->indexes());
  VoltageConstraints vc1(adjacency, max_safe_diff, bounds);
  VoltageConstraints vc2(adj2, max_safe_diff, bounds);
  EXPECT_FALSE(vc1 == vc2);
  EXPECT_TRUE(vc1 != vc2);
}
} // namespace
