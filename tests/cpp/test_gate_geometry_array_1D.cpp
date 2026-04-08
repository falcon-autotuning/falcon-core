#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon-core/physics/config/geometries/GateGeometryArray1D.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
namespace {
using namespace falcon_core;
using namespace physics;
using namespace config;
using namespace device_structures;
using namespace geometries;

class GateGeometryArray1DTest : public ::testing::Test {
 protected:
  ConnectionsSP linear;
  ConnectionsSP even_linear;
  ConnectionsSP screening;
  ConnectionsSP empty_screening;
  ConnectionsSP screening_wrong_contents;
  ConnectionsSP nolohmic;
  ConnectionsSP norohmic;
  void          SetUp() override {
    linear = std::make_shared<Connections>();
    linear->push_back(Connection::Ohmic("O1"));
    linear->push_back(Connection::ReservoirGate("R1"));
    linear->push_back(Connection::BarrierGate("B1"));
    linear->push_back(Connection::PlungerGate("P1"));
    linear->push_back(Connection::BarrierGate("B2"));
    linear->push_back(Connection::ReservoirGate("R2"));
    linear->push_back(Connection::Ohmic("O2"));

    screening = std::make_shared<Connections>();
    screening->push_back(Connection::ScreeningGate("S1"));
    screening->push_back(Connection::ScreeningGate("S2"));

    empty_screening = std::make_shared<Connections>();

    screening_wrong_contents = std::make_shared<Connections>();
    screening_wrong_contents->push_back(Connection::PlungerGate("P1"));

    even_linear = std::make_shared<Connections>();
    even_linear->push_back(Connection::Ohmic("O1"));
    even_linear->push_back(Connection::ReservoirGate("R1"));
    even_linear->push_back(Connection::BarrierGate("B1"));
    even_linear->push_back(Connection::PlungerGate("P1"));
    even_linear->push_back(Connection::PlungerGate("P2"));
    even_linear->push_back(Connection::BarrierGate("B2"));
    even_linear->push_back(Connection::ReservoirGate("R2"));
    even_linear->push_back(Connection::Ohmic("O2"));

    nolohmic = std::make_shared<Connections>();
    nolohmic->push_back(Connection::ReservoirGate("R1"));
    nolohmic->push_back(Connection::BarrierGate("B1"));
    nolohmic->push_back(Connection::PlungerGate("P1"));
    nolohmic->push_back(Connection::PlungerGate("P2"));
    nolohmic->push_back(Connection::BarrierGate("B2"));
    nolohmic->push_back(Connection::ReservoirGate("R2"));
    nolohmic->push_back(Connection::Ohmic("O2"));

    norohmic = std::make_shared<Connections>();
    norohmic->push_back(Connection::Ohmic("O1"));
    norohmic->push_back(Connection::ReservoirGate("R1"));
    norohmic->push_back(Connection::BarrierGate("B1"));
    norohmic->push_back(Connection::PlungerGate("P1"));
    norohmic->push_back(Connection::PlungerGate("P2"));
    norohmic->push_back(Connection::BarrierGate("B2"));
    norohmic->push_back(Connection::ReservoirGate("R2"));
  }
};

TEST_F(GateGeometryArray1DTest, ConstructorValid) {
  EXPECT_NO_THROW(GateGeometryArray1D(linear, screening));
}

TEST_F(GateGeometryArray1DTest, TooManyGatesInArray) {
  EXPECT_THROW(GateGeometryArray1D(even_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, OScreeningGateConstructorThrow) {
  EXPECT_THROW(GateGeometryArray1D(linear, empty_screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, NoScreeningGateConstructorThrow) {
  EXPECT_THROW(GateGeometryArray1D(linear, screening_wrong_contents),
               std::runtime_error);
}

TEST_F(GateGeometryArray1DTest, ConstructorNullptrLineararrayThrows) {
  EXPECT_THROW(GateGeometryArray1D(nullptr, screening), std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, NoLeftOhmicThrows) {
  EXPECT_THROW(GateGeometryArray1D(nolohmic, screening), std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, NoRightOhmicThrows) {
  EXPECT_THROW(GateGeometryArray1D(norohmic, screening), std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, ConstructorNullptrScreeningThrows) {
  EXPECT_THROW(GateGeometryArray1D(linear, nullptr), std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, Serialization) {
  GateGeometryArray1D original(linear, screening);
  auto                string = original.to_json_string();
  auto                loaded =
      GateGeometryArray1D::from_json_string<GateGeometryArray1D>(string);
  ASSERT_EQ(*original.screening_gates(), *loaded->screening_gates());
  ASSERT_EQ(*original.raw_central_gates(), *loaded->raw_central_gates());
  ASSERT_EQ(*original.central_dot_gates(), *loaded->central_dot_gates());
  ASSERT_EQ(*original.ohmics(), *loaded->ohmics());
  ASSERT_EQ(*original.all_dot_gates(), *loaded->all_dot_gates());
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateNullptrLeftThrows) {
  GateGeometryArray1D arr(linear, screening);
  auto                gate = Connection::PlungerGate("P1");
  EXPECT_THROW(arr.append_central_gate(nullptr, gate, gate),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateNullptrSelectedThrows) {
  GateGeometryArray1D arr(linear, screening);
  auto                gate = Connection::PlungerGate("P1");
  EXPECT_THROW(arr.append_central_gate(gate, nullptr, gate),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateNullptrRightThrows) {
  GateGeometryArray1D arr(linear, screening);
  auto                gate = Connection::PlungerGate("P1");
  EXPECT_THROW(arr.append_central_gate(gate, gate, nullptr),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, ScreeningGatesTypeCheckThrows) {
  GateGeometryArray1D arr(linear, screening);
  // Force _screening_gates to be invalid by casting away constness (hack for
  // coverage)
  auto* nonconst = const_cast<Connections*>(arr.screening_gates().get());
  // Replace with a non-screening gate to trigger the runtime_error
  nonconst->clear();
  nonconst->push_back(Connection::PlungerGate("P1"));
  EXPECT_THROW(arr.screening_gates(), std::runtime_error);
}

TEST_F(GateGeometryArray1DTest, RawCentralGatesReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  auto                raw = arr.raw_central_gates();
  ASSERT_EQ(raw->size(), 3);
  EXPECT_TRUE((*raw)[0]->is_barrier_gate());
  EXPECT_TRUE((*raw)[1]->is_plunger_gate());
  EXPECT_TRUE((*raw)[2]->is_barrier_gate());
}

TEST_F(GateGeometryArray1DTest, CentralDotGatesReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  auto                central = arr.central_dot_gates();
  ASSERT_EQ(central->size(), 1);
  EXPECT_EQ((*central)[0]->name(), "P1");
}

TEST_F(GateGeometryArray1DTest, AllDotGatesReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  auto                all = arr.all_dot_gates();
  ASSERT_EQ(all->size(), 3);
  EXPECT_EQ((*all)[0]->name(), "B1");
  EXPECT_EQ((*all)[1]->name(), "P1");
  EXPECT_EQ((*all)[2]->name(), "B2");
}

TEST_F(GateGeometryArray1DTest, OhmicsReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  auto                ohmics = arr.ohmics();
  ASSERT_EQ(ohmics->size(), 2);
  EXPECT_TRUE((*ohmics)[0]->is_ohmic());
  EXPECT_TRUE((*ohmics)[1]->is_ohmic());
}

TEST_F(GateGeometryArray1DTest, LeftReservoirThrowsIfNotOhmic) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace first element with a non-ohmic
  ConnectionSP value = Connection::BarrierGate("BX");
  bad_linear->replace_at(0, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, LeftReservoirThrowsIfNotBarrier) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace second element with a non-barrier
  ConnectionSP value = Connection::PlungerGate("PX");
  bad_linear->replace_at(2, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, RightReservoirThrowsIfNotBarrier) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace third-to-last element with a non-barrier
  auto value = Connection::PlungerGate("PX");
  bad_linear->replace_at(bad_linear->size() - 3, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, LeftBarrierThrowsIfNotReservoir) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace second element with a non-reservoir
  auto value = Connection::BarrierGate("BX");
  bad_linear->replace_at(1, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, LeftBarrierThrowsIfNotPlunger) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace fourth element with a non-plunger
  auto value = Connection::BarrierGate("BX");
  bad_linear->replace_at(3, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, RightBarrierThrowsIfNotReservoir) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace second-to-last element with a non-reservoir
  auto value = Connection::BarrierGate("BX");
  bad_linear->replace_at(bad_linear->size() - 2, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, RightBarrierThrowsIfNotPlunger) {
  auto bad_linear = std::make_shared<Connections>(*linear);
  // Replace fourth-to-last element with a non-plunger
  auto value = Connection::BarrierGate("BX");
  bad_linear->replace_at(bad_linear->size() - 4, value);
  EXPECT_THROW(GateGeometryArray1D(bad_linear, screening),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateThrowsForWrongNeighbors) {
  GateGeometryArray1D arr(linear, screening);
  auto                barrier = Connection::BarrierGate("BX");
  auto                plunger = Connection::PlungerGate("PX");
  // Barrier must be bounded by plunger
  EXPECT_THROW(arr.append_central_gate(barrier, barrier, barrier),
               std::invalid_argument);
  // Plunger must be bounded by barrier
  EXPECT_THROW(arr.append_central_gate(plunger, plunger, plunger),
               std::invalid_argument);
  // Selected gate must be plunger or barrier
  auto ohmic = Connection::Ohmic("OX");
  EXPECT_THROW(arr.append_central_gate(barrier, ohmic, barrier),
               std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, IteratorsWork) {
  GateGeometryArray1D arr(linear, screening);
  auto                it    = arr.begin();
  auto                end   = arr.end();
  int                 count = 0;
  for (; it != end; ++it) ++count;
  EXPECT_EQ(count, linear->size());
}

TEST_F(GateGeometryArray1DTest, ConstIteratorsWork) {
  const GateGeometryArray1D arr(linear, screening);
  auto                      it    = arr.begin();
  auto                      end   = arr.end();
  int                       count = 0;
  for (; it != end; ++it) ++count;
  EXPECT_EQ(count, linear->size());
}

TEST_F(GateGeometryArray1DTest, LineararrayReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  EXPECT_EQ(arr.lineararray(), linear);
}

TEST_F(GateGeometryArray1DTest, ScreeningGatesReturnsExpected) {
  GateGeometryArray1D arr(linear, screening);
  EXPECT_EQ(arr.screening_gates(), screening);
}

TEST_F(GateGeometryArray1DTest, AppendCentralGateValid) {
  GateGeometryArray1D arr(linear, screening);
  auto                left     = Connection::BarrierGate("B1");
  auto                selected = Connection::PlungerGate("P1");
  auto                right    = Connection::BarrierGate("B2");
  EXPECT_NO_THROW(arr.append_central_gate(left, selected, right));
}

TEST_F(GateGeometryArray1DTest, QueryNeighborsThrowsForUnknownGate) {
  GateGeometryArray1D arr(linear, screening);
  auto                unknown = Connection::Ohmic("unknown");
  EXPECT_THROW(arr.query_neighbors(unknown), std::invalid_argument);
}

TEST_F(GateGeometryArray1DTest, QueryNeighborsScreeningGate) {
  GateGeometryArray1D arr(linear, screening);
  auto                result = arr.query_neighbors((*screening)[0]);
  // Should contain left_barrier()->left_neighbor(), all raw_central_gates,
  // right_barrier()->right_neighbor()
  EXPECT_GT(result->size(), 0);
}

TEST_F(GateGeometryArray1DTest, QueryNeighborsLeftReservoir) {
  GateGeometryArray1D arr(linear, screening);
  auto                result = arr.query_neighbors((*linear)[1]);
  // Should contain left_reservoir()->right_neighbor() and all screening gates
  EXPECT_GT(result->size(), 0);
}

TEST_F(GateGeometryArray1DTest, QueryNeighborsRightReservoir) {
  GateGeometryArray1D arr(linear, screening);
  auto result = arr.query_neighbors((*linear)[linear->size() - 2]);
  // Should contain right_reservoir()->left_neighbor() and all screening gates
  EXPECT_GT(result->size(), 0);
}

TEST_F(GateGeometryArray1DTest, QueryNeighborsDotGate) {
  GateGeometryArray1D arr(linear, screening);
  auto dot_gate = (*linear)[3];  // Should be a plunger gate in the middle
  auto result   = arr.query_neighbors(dot_gate);
  // Should contain left_neighbor, right_neighbor, and all screening gates
  EXPECT_GT(result->size(), 0);
}

TEST_F(GateGeometryArray1DTest,
       AppendCentralGateThrowsIfRightNeighborNotPlunger) {
  GateGeometryArray1D arr(linear, screening);
  auto                barrier = Connection::BarrierGate("B1");
  auto                plunger = Connection::PlungerGate("P1");
  auto not_plunger            = Connection::BarrierGate("B2");  // Not a plunger
  // left is plunger, right is not plunger
  EXPECT_THROW(arr.append_central_gate(plunger, barrier, not_plunger),
               std::invalid_argument);
}
}  // namespace
