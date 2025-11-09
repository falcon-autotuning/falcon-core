#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerQuantity_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/MapInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class InterpretationContainerQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ListMeasurementContextHandle axes_indp1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateA")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep1 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep1,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateB")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_indp2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_indp2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateC")),
            InstrumentTypes_voltmeter()));
    ListMeasurementContextHandle axes_dep2 =
        ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(
        axes_dep2,
        MeasurementContext_create(
            Connection_create_plunger_gate(String_wrap("gateD")),
            InstrumentTypes_voltmeter()));
    ctx1 =
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp1),
                                     axes_dep1,
                                     SymbolUnit_create_volt());
    ctx2 =
        InterpretationContext_create(AxesMeasurementContext_create(axes_indp2),
                                     axes_dep2,
                                     SymbolUnit_create_volt());
    pair1 = PairInterpretationContextQuantity_create(
        ctx1, Quantity_create(1.0, SymbolUnit_create_volt()));
    pair2 = PairInterpretationContextQuantity_create(
        ctx2, Quantity_create(1.5, SymbolUnit_create_volt()));
    PairInterpretationContextQuantityHandle arr[2] = {pair1, pair2};
    map       = MapInterpretationContextQuantity_create(arr, 2);
    container = InterpretationContainerQuantity_create(map);
    val1      = Quantity_create(2.5, SymbolUnit_create_volt());
    val2      = Quantity_create(3.5, SymbolUnit_create_volt());
  }
  void TearDown() override {
    InterpretationContainerQuantity_destroy(container);
    MapInterpretationContextQuantity_destroy(map);
    PairInterpretationContextQuantity_destroy(pair1);
    PairInterpretationContextQuantity_destroy(pair2);
    InterpretationContext_destroy(ctx1);
    InterpretationContext_destroy(ctx2);
  }
  QuantityHandle                          val1;
  QuantityHandle                          val2;
  InterpretationContextHandle             ctx1;
  InterpretationContextHandle             ctx2;
  PairInterpretationContextQuantityHandle pair1;
  PairInterpretationContextQuantityHandle pair2;
  MapInterpretationContextQuantityHandle  map;
  InterpretationContainerQuantityHandle   container;
};

TEST_F(InterpretationContainerQuantityTest, CreateDestroy) {
  EXPECT_THROW(InterpretationContainerQuantity_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, InsertAssignAccessErase) {
  InterpretationContainerQuantity_insert_or_assign(container, ctx1, val1);
  EXPECT_TRUE(Quantity_equal(
      InterpretationContainerQuantity_at(container, ctx1), val1));
  InterpretationContainerQuantity_insert(container, ctx2, val2);
  EXPECT_TRUE(Quantity_equal(
      InterpretationContainerQuantity_at(container, ctx2), val2));
  InterpretationContainerQuantity_erase(container, ctx2);
  EXPECT_FALSE(InterpretationContainerQuantity_contains(container, ctx2));
  EXPECT_THROW(
      InterpretationContainerQuantity_insert_or_assign(nullptr, ctx1, val1),
      std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_insert_or_assign(
                   container, nullptr, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_insert_or_assign(
                   container, ctx1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_insert(nullptr, ctx1, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_insert(container, nullptr, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_insert(container, ctx1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_at(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_at(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_erase(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_erase(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, SizeEmptyClearContains) {
  EXPECT_EQ(InterpretationContainerQuantity_size(container), 2);
  EXPECT_FALSE(InterpretationContainerQuantity_empty(container));
  InterpretationContainerQuantity_clear(container);
  EXPECT_TRUE(InterpretationContainerQuantity_empty(container));
  EXPECT_THROW(InterpretationContainerQuantity_size(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_empty(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_clear(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_contains(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_contains(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, KeysValuesItems) {
  auto keys   = InterpretationContainerQuantity_keys(container);
  auto values = InterpretationContainerQuantity_values(container);
  auto items  = InterpretationContainerQuantity_items(container);
  EXPECT_NE(keys, nullptr);
  EXPECT_NE(values, nullptr);
  EXPECT_NE(items, nullptr);
  ListInterpretationContext_destroy(keys);
  ListQuantity_destroy(values);
  ListPairInterpretationContextQuantity_destroy(items);
  EXPECT_THROW(InterpretationContainerQuantity_keys(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_values(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_items(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, Equality) {
  PairInterpretationContextQuantityHandle arr[2] = {pair1, pair2};
  auto m2 = MapInterpretationContextQuantity_create(arr, 2);
  auto c2 = InterpretationContainerQuantity_create(m2);
  EXPECT_TRUE(InterpretationContainerQuantity_equal(container, c2));
  EXPECT_FALSE(InterpretationContainerQuantity_not_equal(container, c2));
  InterpretationContainerQuantity_insert_or_assign(c2, ctx1, val1);
  EXPECT_FALSE(InterpretationContainerQuantity_equal(container, c2));
  EXPECT_TRUE(InterpretationContainerQuantity_not_equal(container, c2));
  EXPECT_THROW(InterpretationContainerQuantity_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_equal(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_not_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_not_equal(container, nullptr),
               std::invalid_argument);
  InterpretationContainerQuantity_destroy(c2);
  MapInterpretationContextQuantity_destroy(m2);
}

TEST_F(InterpretationContainerQuantityTest, ToJsonFromJson) {
  auto json = InterpretationContainerQuantity_to_json_string(container);
  auto c2   = InterpretationContainerQuantity_from_json_string(json);
  EXPECT_TRUE(InterpretationContainerQuantity_equal(container, c2));
  InterpretationContainerQuantity_destroy(c2);
  String_destroy(json);
  EXPECT_THROW(InterpretationContainerQuantity_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, UnitAccessor) {
  auto unit = InterpretationContainerQuantity_unit(container);
  EXPECT_NE(unit, nullptr);
  SymbolUnit_destroy(unit);
  EXPECT_THROW(InterpretationContainerQuantity_unit(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerQuantityTest, SelectByConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list =
      InterpretationContainerQuantity_select_by_connection(container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerQuantity_select_by_connection(nullptr, conn),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerQuantity_select_by_connection(container, nullptr),
      std::invalid_argument);
  Connection_destroy(conn);
  ListInterpretationContext_destroy(list);
}

TEST_F(InterpretationContainerQuantityTest, SelectByConnections) {
  ConnectionHandle raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  auto conns = Connections_create(ListConnection_create(raw, 1));
  auto list =
      InterpretationContainerQuantity_select_by_connections(container, conns);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerQuantity_select_by_connections(nullptr, conns),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerQuantity_select_by_connections(container, nullptr),
      std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connections_destroy(conns);
}

TEST_F(InterpretationContainerQuantityTest, SelectByIndependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list = InterpretationContainerQuantity_select_by_independent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerQuantity_select_by_independent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_select_by_independent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerQuantityTest, SelectByDependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateB"));
  auto list = InterpretationContainerQuantity_select_by_dependent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerQuantity_select_by_dependent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_select_by_dependent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerQuantityTest, SelectContexts) {
  ConnectionHandle indp_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  ConnectionHandle dep_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateB"))};
  auto indp_list = ListConnection_create(indp_raw, 1);
  auto dep_list  = ListConnection_create(dep_raw, 1);
  auto list      = InterpretationContainerQuantity_select_contexts(
      container, indp_list, dep_list);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerQuantity_select_contexts(
                   nullptr, indp_list, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_select_contexts(
                   container, nullptr, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerQuantity_select_contexts(
                   container, indp_list, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  ListConnection_destroy(indp_list);
  ListConnection_destroy(dep_list);
}
