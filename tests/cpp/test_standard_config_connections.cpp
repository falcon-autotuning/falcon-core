
#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/physics/config/core/StandardConfigConnections.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core::physics::config::core;
using namespace falcon_core::physics::device_structures;

class StandardConfigConnectionsTest : public ::testing::Test {
 protected:
  ConnectionsSP screening, reservoir, plunger, barrier, ohmics;
  ConnectionSP  ohmic, gate, barrier_gate, plunger_gate, reservoir_gate,
      screening_gate;
  StandardConfigConnectionsTest() {
    screening      = std::make_shared<Connections>();
    screening_gate = Connection::ScreeningGate("S1");
    screening->push_back(screening_gate);
    reservoir      = std::make_shared<Connections>();
    reservoir_gate = Connection::ReservoirGate("R1");
    reservoir->push_back(reservoir_gate);

    plunger      = std::make_shared<Connections>();
    plunger_gate = Connection::PlungerGate("P1");
    plunger->push_back(plunger_gate);

    barrier      = std::make_shared<Connections>();
    barrier_gate = Connection::BarrierGate("B1");
    barrier->push_back(barrier_gate);

    ohmics = std::make_shared<Connections>();
    ohmic  = Connection::Ohmic("O1");
    ohmics->push_back(ohmic);

    gate = Connection::PlungerGate("P2");
  }
};

TEST_F(StandardConfigConnectionsTest, ConstructorValid) {
  EXPECT_NO_THROW(StandardConfigConnections(
      screening, reservoir, plunger, barrier, ohmics));
}

TEST_F(StandardConfigConnectionsTest, ConstructorNullptrScreeningThrows) {
  EXPECT_THROW(
      StandardConfigConnections(nullptr, reservoir, plunger, barrier, ohmics),
      std::invalid_argument);
}
TEST_F(StandardConfigConnectionsTest, ConstructorNullptrReservoirThrows) {
  EXPECT_THROW(
      StandardConfigConnections(screening, nullptr, plunger, barrier, ohmics),
      std::invalid_argument);
}
TEST_F(StandardConfigConnectionsTest, ConstructorNullptrPlungerThrows) {
  EXPECT_THROW(
      StandardConfigConnections(screening, reservoir, nullptr, barrier, ohmics),
      std::invalid_argument);
}
TEST_F(StandardConfigConnectionsTest, ConstructorNullptrBarrierThrows) {
  EXPECT_THROW(
      StandardConfigConnections(screening, reservoir, plunger, nullptr, ohmics),
      std::invalid_argument);
}
TEST_F(StandardConfigConnectionsTest, ConstructorNullptrOhmicsThrows) {
  EXPECT_THROW(StandardConfigConnections(
                   screening, reservoir, plunger, barrier, nullptr),
               std::invalid_argument);
}

TEST_F(StandardConfigConnectionsTest, GettersReturnExpected) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.screening_gates(), screening);
  EXPECT_EQ(scc.reservoir_gates(), reservoir);
  EXPECT_EQ(scc.plunger_gates(), plunger);
  EXPECT_EQ(scc.barrier_gates(), barrier);
  EXPECT_EQ(scc.ohmics(), ohmics);
}

TEST_F(StandardConfigConnectionsTest, HasFunctionsNullptrThrows) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_THROW(scc.has_ohmic(nullptr), std::invalid_argument);
  EXPECT_THROW(scc.has_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(scc.has_barrier_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(scc.has_plunger_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(scc.has_reservoir_gate(nullptr), std::invalid_argument);
  EXPECT_THROW(scc.has_screening_gate(nullptr), std::invalid_argument);
}

TEST_F(StandardConfigConnectionsTest, FiveConnections) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.barrier_gates()->size(), 1);
  EXPECT_EQ(scc.screening_gates()->size(), 1);
  EXPECT_EQ(scc.reservoir_gates()->size(), 1);
  EXPECT_EQ(scc.plunger_gates()->size(), 1);
  EXPECT_EQ(scc.ohmics()->size(), 1);
  EXPECT_EQ(scc.dot_gates()->size(), 2);
  EXPECT_EQ(scc.barrier_gates()->size(), 1);
  EXPECT_EQ(scc.screening_gates()->size(), 1);
  EXPECT_EQ(scc.reservoir_gates()->size(), 1);
  EXPECT_EQ(scc.plunger_gates()->size(), 1);
  EXPECT_EQ(scc.ohmics()->size(), 1);
  EXPECT_EQ(scc.get_all_gates()->size(), 4);
  EXPECT_EQ(scc.barrier_gates()->size(), 1);
  EXPECT_EQ(scc.screening_gates()->size(), 1);
  EXPECT_EQ(scc.reservoir_gates()->size(), 1);
  EXPECT_EQ(scc.plunger_gates()->size(), 1);
  EXPECT_EQ(scc.ohmics()->size(), 1);
  EXPECT_EQ(scc.get_all_connections()->size(), 5);
}

TEST_F(StandardConfigConnectionsTest, HasFunctionsReturnTrueFalse) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_TRUE(scc.has_ohmic(ohmic));
  EXPECT_FALSE(scc.has_ohmic(gate));
  EXPECT_TRUE(scc.has_gate(plunger_gate));
  EXPECT_TRUE(scc.has_gate(screening_gate));
  EXPECT_FALSE(scc.has_gate(ohmic));
  EXPECT_TRUE(scc.has_barrier_gate(barrier_gate));
  EXPECT_FALSE(scc.has_barrier_gate(plunger_gate));
  EXPECT_TRUE(scc.has_plunger_gate(plunger_gate));
  EXPECT_FALSE(scc.has_plunger_gate(barrier_gate));
  EXPECT_TRUE(scc.has_reservoir_gate(reservoir_gate));
  EXPECT_FALSE(scc.has_reservoir_gate(barrier_gate));
  EXPECT_TRUE(scc.has_screening_gate(screening_gate));
  EXPECT_FALSE(scc.has_screening_gate(barrier_gate));
}

TEST_F(StandardConfigConnectionsTest, SerializationRoundTrip) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  std::stringstream         ss;
  auto                      string = scc.to_json_string();
  auto                      loaded =
      StandardConfigConnections::from_json_string<StandardConfigConnections>(
          string);
  EXPECT_EQ(*scc.screening_gates(), *loaded->screening_gates());
  EXPECT_EQ(*scc.reservoir_gates(), *loaded->reservoir_gates());
  EXPECT_EQ(*scc.plunger_gates(), *loaded->plunger_gates());
  EXPECT_EQ(*scc.barrier_gates(), *loaded->barrier_gates());
  EXPECT_EQ(*scc.ohmics(), *loaded->ohmics());
}

TEST_F(StandardConfigConnectionsTest, GetOhmicReturnsFirst) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_ohmic(), ohmic);
}

TEST_F(StandardConfigConnectionsTest, GetBarrierGateReturnsFirst) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_barrier_gate(), barrier_gate);
}

TEST_F(StandardConfigConnectionsTest, GetPlungerGateReturnsFirst) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_plunger_gate(), plunger_gate);
}

TEST_F(StandardConfigConnectionsTest, GetReservoirGateReturnsFirst) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_reservoir_gate(), reservoir_gate);
}

TEST_F(StandardConfigConnectionsTest, GetScreeningGateReturnsFirst) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_screening_gate(), screening_gate);
}

TEST_F(StandardConfigConnectionsTest, GetDotGatePrefersPlunger) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_dot_gate(), plunger_gate);
}

TEST_F(StandardConfigConnectionsTest, GetDotGateFallsBackToBarrier) {
  auto                      empty_plunger = std::make_shared<Connections>();
  StandardConfigConnections scc(
      screening, reservoir, empty_plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_dot_gate(), barrier_gate);
}

TEST_F(StandardConfigConnectionsTest, GetDotGateReturnsNullptr) {
  auto                      empty_plunger = std::make_shared<Connections>();
  auto                      empty_barrier = std::make_shared<Connections>();
  StandardConfigConnections scc(
      screening, reservoir, empty_plunger, empty_barrier, ohmics);
  EXPECT_EQ(scc.get_dot_gate(), nullptr);
}

TEST_F(StandardConfigConnectionsTest, GetGatePrefersPlunger) {
  StandardConfigConnections scc(screening, reservoir, plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_gate(), plunger_gate);
}

TEST_F(StandardConfigConnectionsTest, GetGateFallsBackToBarrier) {
  auto                      empty_plunger = std::make_shared<Connections>();
  StandardConfigConnections scc(
      screening, reservoir, empty_plunger, barrier, ohmics);
  EXPECT_EQ(scc.get_gate(), barrier_gate);
}

TEST_F(StandardConfigConnectionsTest, GetGateFallsBackToReservoir) {
  auto                      empty_plunger = std::make_shared<Connections>();
  auto                      empty_barrier = std::make_shared<Connections>();
  StandardConfigConnections scc(
      screening, reservoir, empty_plunger, empty_barrier, ohmics);
  EXPECT_EQ(scc.get_gate(), reservoir_gate);
}

TEST_F(StandardConfigConnectionsTest, GetGateFallsBackToScreening) {
  auto                      empty_plunger   = std::make_shared<Connections>();
  auto                      empty_barrier   = std::make_shared<Connections>();
  auto                      empty_reservoir = std::make_shared<Connections>();
  StandardConfigConnections scc(
      screening, empty_reservoir, empty_plunger, empty_barrier, ohmics);
  EXPECT_EQ(scc.get_gate(), screening_gate);
}

TEST_F(StandardConfigConnectionsTest, GetGateReturnsNullptr) {
  auto                      empty_plunger   = std::make_shared<Connections>();
  auto                      empty_barrier   = std::make_shared<Connections>();
  auto                      empty_reservoir = std::make_shared<Connections>();
  auto                      empty_screening = std::make_shared<Connections>();
  StandardConfigConnections scc(
      empty_screening, empty_reservoir, empty_plunger, empty_barrier, ohmics);
  EXPECT_EQ(scc.get_gate(), nullptr);
}

TEST_F(StandardConfigConnectionsTest,
       ConstructorThrowsIfScreeningGatesWrongType) {
  auto bad_screening = std::make_shared<Connections>();
  bad_screening->push_back(Connection::PlungerGate("P1"));
  EXPECT_THROW(StandardConfigConnections(
                   bad_screening, reservoir, plunger, barrier, ohmics),
               std::runtime_error);
}

TEST_F(StandardConfigConnectionsTest,
       ConstructorThrowsIfReservoirGatesWrongType) {
  auto bad_reservoir = std::make_shared<Connections>();
  bad_reservoir->push_back(Connection::BarrierGate("B1"));
  EXPECT_THROW(StandardConfigConnections(
                   screening, bad_reservoir, plunger, barrier, ohmics),
               std::runtime_error);
}

TEST_F(StandardConfigConnectionsTest,
       ConstructorThrowsIfPlungerGatesWrongType) {
  auto bad_plunger = std::make_shared<Connections>();
  bad_plunger->push_back(Connection::ScreeningGate("S1"));
  EXPECT_THROW(StandardConfigConnections(
                   screening, reservoir, bad_plunger, barrier, ohmics),
               std::runtime_error);
}

TEST_F(StandardConfigConnectionsTest,
       ConstructorThrowsIfBarrierGatesWrongType) {
  auto bad_barrier = std::make_shared<Connections>();
  bad_barrier->push_back(Connection::ReservoirGate("R1"));
  EXPECT_THROW(StandardConfigConnections(
                   screening, reservoir, plunger, bad_barrier, ohmics),
               std::runtime_error);
}

TEST_F(StandardConfigConnectionsTest, ConstructorThrowsIfOhmicsWrongType) {
  auto bad_ohmics = std::make_shared<Connections>();
  bad_ohmics->push_back(Connection::ScreeningGate("S1"));
  EXPECT_THROW(StandardConfigConnections(
                   screening, reservoir, plunger, barrier, bad_ohmics),
               std::runtime_error);
}
}  // namespace
