#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"
#include "falcon-core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace autotuner_interfaces;
using namespace instrument_interfaces::names;
using namespace interpretations;
using namespace physics;
using namespace device_structures;
using namespace contexts;

class InterpretationContainerTest : public ::testing::Test {
 protected:
  std::shared_ptr<Connection> connA =
      std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  std::shared_ptr<Connection> connB =
      std::make_shared<Connection>("B", DeviceFeature::PlungerGate);
  std::shared_ptr<Connection> connO =
      std::make_shared<Connection>("O", DeviceFeature::Ohmic);
  std::shared_ptr<units::SymbolUnit> unitV =
      std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  std::shared_ptr<units::SymbolUnit> unitA =
      std::make_shared<units::SymbolUnit>(units::Unit::Ampere());
  MeasurementContextSP    mcA, mcB, mcO;
  InterpretationContextSP ctxA_O_V, ctxB_O_V, ctxA_O_A;
  void                    SetUp() override {
    mcA =
        std::make_shared<MeasurementContext>(connA, InstrumentTypes::VOLTMETER);
    mcB =
        std::make_shared<MeasurementContext>(connB, InstrumentTypes::VOLTMETER);
    mcO =
        std::make_shared<MeasurementContext>(connO, InstrumentTypes::VOLTMETER);
    ctxA_O_V = std::make_shared<InterpretationContext>(
        std::make_shared<math::Axes<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcA}),
        std::make_shared<generic::List<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcO}),
        unitV);
    ctxB_O_V = std::make_shared<InterpretationContext>(
        std::make_shared<math::Axes<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcB}),
        std::make_shared<generic::List<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcO}),
        unitV);
    ctxA_O_A = std::make_shared<InterpretationContext>(
        std::make_shared<math::Axes<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcA}),
        std::make_shared<generic::List<MeasurementContext>>(
            std::vector<MeasurementContextSP>{mcO}),
        unitA);
  }
};

TEST_F(InterpretationContainerTest, ConstructionAndUnit) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  EXPECT_EQ(*container.unit(), *unitV);
  EXPECT_EQ(container.keys()->size(), 1);
  generic::List<InterpretationContext> keys = *(container.keys());
  for (const InterpretationContextSP& context : keys) {
    if (!context) {
      throw std::invalid_argument("This is a broken context");
    }
    EXPECT_EQ(context->dimension(), 1);
  }
  EXPECT_EQ(container.values()->size(), 1);
  EXPECT_THROW(InterpretationContainer<double>(nullptr), std::invalid_argument);
}

TEST_F(InterpretationContainerTest, ConstructionAndUnitBigger) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  map->insert(ctxB_O_V, 2.5);
  InterpretationContainer<double> container(map);
  EXPECT_EQ(*container.unit(), *unitV);
  EXPECT_EQ(container.keys()->size(), 2);
  generic::List<InterpretationContext> keys = *(container.keys());
  for (const InterpretationContextSP& context : keys) {
    EXPECT_EQ(context->dimension(), 1);
  }
  EXPECT_EQ(container.values()->size(), 2);
  EXPECT_THROW(InterpretationContainer<double>(nullptr), std::invalid_argument);
}

TEST_F(InterpretationContainerTest, UnitMismatchThrows) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  map->insert(ctxA_O_A, 2.0);
  EXPECT_THROW(InterpretationContainer<double> container(map),
               std::invalid_argument);
}

TEST_F(InterpretationContainerTest, IndependantVariablesDimension) {
  EXPECT_EQ(ctxA_O_V->dimension(), 1);
}

TEST_F(InterpretationContainerTest, SelectByConnection) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  auto result = container.select_by_connection(connA);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctxA_O_V);
  EXPECT_THROW(container.select_by_connection(nullptr), std::invalid_argument);
}

TEST_F(InterpretationContainerTest, SelectByConnections) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  map->insert(ctxB_O_V, 2.0);
  InterpretationContainer<double> container(map);
  std::vector<ConnectionSP>       connections = {connA, connB};
  auto result = container.select_by_connections(connections);
  EXPECT_EQ(result->size(), 0);  // No context matches both connections
  connections = {connA};
  result      = container.select_by_connections(connections);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctxA_O_V);
}

TEST_F(InterpretationContainerTest, SelectByIndependentConnection) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  auto result = container.select_by_independent_connection(connA);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctxA_O_V);
  EXPECT_THROW(container.select_by_independent_connection(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerTest, SelectByDependentConnection) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  auto result = container.select_by_dependent_connection(connO);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctxA_O_V);
  EXPECT_THROW(container.select_by_dependent_connection(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerTest, SelectContexts) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  auto indp_list = std::make_shared<generic::List<Connection>>(
      std::vector<ConnectionSP>{connA});
  auto dep_list = std::make_shared<generic::List<Connection>>(
      std::vector<ConnectionSP>{connO});
  auto result = container.select_contexts(indp_list, dep_list);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctxA_O_V);
  auto bad_list =
      std::make_shared<generic::List<Connection>>(std::vector<ConnectionSP>{
          std::make_shared<Connection>("C", DeviceFeature::PlungerGate)});
  EXPECT_EQ(container.select_contexts(bad_list, dep_list)->size(), 0);
  EXPECT_EQ(container.select_contexts(indp_list, bad_list)->size(), 0);
  EXPECT_THROW(container.select_contexts(nullptr, dep_list),
               std::invalid_argument);
  EXPECT_THROW(container.select_contexts(indp_list, nullptr),
               std::invalid_argument);
}
TEST_F(InterpretationContainerTest, SerializationRoundTrip) {
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctxA_O_V, 1.0);
  InterpretationContainer<double> container(map);
  auto                            string = container.to_json_string();
  auto c2 = InterpretationContainer<double>::from_json_string<
      InterpretationContainer<double>>(string);
  EXPECT_EQ(container, *c2);
}
