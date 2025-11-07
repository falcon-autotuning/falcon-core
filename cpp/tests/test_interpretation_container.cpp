#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/generic/Map.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

using namespace falcon_core;
using namespace autotuner_interfaces;
using namespace interpretations;
using namespace physics;
using namespace device_structures;
using namespace contexts;

TEST(InterpretationContainerTest, ConstructionAndUnit) {
  auto conn = std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto unit = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto mc =
      std::make_shared<MeasurementContext>(conn, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{}),
      unit);
  auto pair =
      std::make_shared<generic::Pair<InterpretationContext, double>>(ctx, 1.0);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx, 1.0);

  InterpretationContainer<double> container(map);
  EXPECT_EQ(*container.unit(), *unit);
  EXPECT_THROW(InterpretationContainer<double>(nullptr), std::invalid_argument);
}

TEST(InterpretationContainerTest, UnitMismatchThrows) {
  auto conn  = std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto ohmic = std::make_shared<Connection>("O", DeviceFeature::Ohmic);
  auto unit1 = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto unit2 = std::make_shared<units::SymbolUnit>(units::Unit::Ampere());
  auto mc =
      std::make_shared<MeasurementContext>(conn, INSTRUMENT_TYPES::VOLTMETER);
  auto ohmicContext =
      std::make_shared<MeasurementContext>(ohmic, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx1 = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{ohmicContext}),
      unit1);
  auto ctx2 = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{ohmicContext}),
      unit2);
  generic::MapSP<InterpretationContext, double> map =
      std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx1, 1.0);
  map->insert(ctx2, 2.0);
  EXPECT_THROW(InterpretationContainer<double> container(map),
               std::invalid_argument);
}

TEST(InterpretationContainerTest, SelectByConnection) {
  auto conn  = Connection::PlungerGate("A");
  auto ohmic = Connection::Ohmic("O");
  auto unit  = units::SymbolUnit::Volt();
  auto mc =
      std::make_shared<MeasurementContext>(conn, INSTRUMENT_TYPES::VOLTMETER);
  auto ohmicContext =
      std::make_shared<MeasurementContext>(ohmic, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{ohmicContext}),
      unit);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx, 1.0);
  InterpretationContainer<double> container(map);

  generic::ListSP<InterpretationContext> result =
      container.select_by_connection(conn);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctx);

  EXPECT_THROW(container.select_by_connection(nullptr), std::invalid_argument);
}

TEST(InterpretationContainerTest, SelectByConnections) {
  auto conn1 = std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto conn2 = std::make_shared<Connection>("B", DeviceFeature::PlungerGate);
  auto unit  = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto mc1 =
      std::make_shared<MeasurementContext>(conn1, INSTRUMENT_TYPES::VOLTMETER);
  auto mc2 =
      std::make_shared<MeasurementContext>(conn2, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx1 = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc1}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{}),
      unit);
  auto ctx2 = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc2}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{}),
      unit);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx1, 1.0);
  map->insert(ctx2, 2.0);
  InterpretationContainer<double> container(map);

  std::vector<ConnectionSP> connections = {conn1, conn2};
  auto result = container.select_by_connections(connections);
  EXPECT_EQ(result->size(), 0);  // No context matches both connections

  connections = {conn1};
  result      = container.select_by_connections(connections);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctx1);
}

TEST(InterpretationContainerTest, SelectByIndependentConnection) {
  auto conn = std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto unit = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto mc =
      std::make_shared<MeasurementContext>(conn, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{}),
      unit);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx, 1.0);
  InterpretationContainer<double> container(map);

  auto result = container.select_by_independent_connection(conn);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctx);

  EXPECT_THROW(container.select_by_independent_connection(nullptr),
               std::invalid_argument);

  auto bad_conn = std::make_shared<Connection>("B", DeviceFeature::PlungerGate);
  EXPECT_THROW(container.select_by_independent_connection(bad_conn),
               std::runtime_error);
}

TEST(InterpretationContainerTest, SelectByDependentConnection) {
  auto conn = std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto unit = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto mc =
      std::make_shared<MeasurementContext>(conn, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc}),
      unit);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx, 1.0);
  InterpretationContainer<double> container(map);

  auto result = container.select_by_dependent_connection(conn);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctx);

  EXPECT_THROW(container.select_by_dependent_connection(nullptr),
               std::invalid_argument);

  auto bad_conn = std::make_shared<Connection>("B", DeviceFeature::PlungerGate);
  EXPECT_THROW(container.select_by_dependent_connection(bad_conn),
               std::runtime_error);
}

TEST(InterpretationContainerTest, SelectContexts) {
  auto conn_indp =
      std::make_shared<Connection>("A", DeviceFeature::PlungerGate);
  auto conn_dep = std::make_shared<Connection>("B", DeviceFeature::PlungerGate);
  auto unit     = std::make_shared<units::SymbolUnit>(units::Unit::Volt());
  auto mc_indp  = std::make_shared<MeasurementContext>(
      conn_indp, INSTRUMENT_TYPES::VOLTMETER);
  auto mc_dep = std::make_shared<MeasurementContext>(
      conn_dep, INSTRUMENT_TYPES::VOLTMETER);
  auto ctx = std::make_shared<InterpretationContext>(
      std::make_shared<math::Axes<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc_indp}),
      std::make_shared<generic::List<MeasurementContext>>(
          std::vector<MeasurementContextSP>{mc_dep}),
      unit);
  auto map = std::make_shared<generic::Map<InterpretationContext, double>>();
  map->insert(ctx, 1.0);
  InterpretationContainer<double> container(map);

  auto indp_list = std::make_shared<generic::List<Connection>>(
      std::vector<ConnectionSP>{conn_indp});
  auto dep_list = std::make_shared<generic::List<Connection>>(
      std::vector<ConnectionSP>{conn_dep});
  auto result = container.select_contexts(indp_list, dep_list);
  EXPECT_EQ(result->size(), 1);
  EXPECT_EQ(*result->at(0), *ctx);

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
