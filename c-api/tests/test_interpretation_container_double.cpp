#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerDouble_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/MapInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class InterpretationContainerDoubleTest : public ::testing::Test {
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
    pair1 = PairInterpretationContextDouble_create(ctx1, 1.5);
    pair2 = PairInterpretationContextDouble_create(ctx2, 2.5);
    PairInterpretationContextDoubleHandle arr[2] = {pair1, pair2};
    map       = MapInterpretationContextDouble_create(arr, 2);
    container = InterpretationContainerDouble_create(map);
    val1      = 3.0;
    val2      = 4.0;
  }
  void TearDown() override {
    InterpretationContainerDouble_destroy(container);
    MapInterpretationContextDouble_destroy(map);
    PairInterpretationContextDouble_destroy(pair1);
    PairInterpretationContextDouble_destroy(pair2);
    InterpretationContext_destroy(ctx1);
    InterpretationContext_destroy(ctx2);
  }
  double                                val1;
  double                                val2;
  InterpretationContextHandle           ctx1;
  InterpretationContextHandle           ctx2;
  PairInterpretationContextDoubleHandle pair1;
  PairInterpretationContextDoubleHandle pair2;
  MapInterpretationContextDoubleHandle  map;
  InterpretationContainerDoubleHandle   container;
};

TEST_F(InterpretationContainerDoubleTest, CreateDestroy) {
  EXPECT_THROW(InterpretationContainerDouble_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, InsertAssignAccessErase) {
  InterpretationContainerDouble_insert_or_assign(container, ctx1, val1);
  EXPECT_EQ(InterpretationContainerDouble_at(container, ctx1), val1);
  InterpretationContainerDouble_insert(container, ctx2, val2);
  EXPECT_EQ(InterpretationContainerDouble_at(container, ctx2), val2);
  InterpretationContainerDouble_erase(container, ctx2);
  EXPECT_FALSE(InterpretationContainerDouble_contains(container, ctx2));
  EXPECT_THROW(
      InterpretationContainerDouble_insert_or_assign(nullptr, ctx1, val1),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerDouble_insert_or_assign(container, nullptr, val1),
      std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_insert(nullptr, ctx1, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_insert(container, nullptr, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_at(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_at(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_erase(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_erase(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, SizeEmptyClearContains) {
  EXPECT_EQ(InterpretationContainerDouble_size(container), 2);
  EXPECT_FALSE(InterpretationContainerDouble_empty(container));
  InterpretationContainerDouble_clear(container);
  EXPECT_TRUE(InterpretationContainerDouble_empty(container));
  EXPECT_THROW(InterpretationContainerDouble_size(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_empty(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_clear(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_contains(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_contains(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, KeysValuesItems) {
  auto keys   = InterpretationContainerDouble_keys(container);
  auto values = InterpretationContainerDouble_values(container);
  auto items  = InterpretationContainerDouble_items(container);
  EXPECT_NE(keys, nullptr);
  EXPECT_NE(values, nullptr);
  EXPECT_NE(items, nullptr);
  ListInterpretationContext_destroy(keys);
  ListDouble_destroy(values);
  ListPairInterpretationContextDouble_destroy(items);
  EXPECT_THROW(InterpretationContainerDouble_keys(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_values(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_items(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, Equality) {
  PairInterpretationContextDoubleHandle arr[2] = {pair1, pair2};
  auto m2 = MapInterpretationContextDouble_create(arr, 2);
  auto c2 = InterpretationContainerDouble_create(m2);
  EXPECT_TRUE(InterpretationContainerDouble_equal(container, c2));
  EXPECT_FALSE(InterpretationContainerDouble_not_equal(container, c2));
  InterpretationContainerDouble_insert_or_assign(c2, ctx1, val1);
  EXPECT_FALSE(InterpretationContainerDouble_equal(container, c2));
  EXPECT_TRUE(InterpretationContainerDouble_not_equal(container, c2));
  EXPECT_THROW(InterpretationContainerDouble_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_equal(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_not_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_not_equal(container, nullptr),
               std::invalid_argument);
  InterpretationContainerDouble_destroy(c2);
  MapInterpretationContextDouble_destroy(m2);
}

TEST_F(InterpretationContainerDoubleTest, ToJsonFromJson) {
  auto json = InterpretationContainerDouble_to_json_string(container);
  auto c2   = InterpretationContainerDouble_from_json_string(json);
  EXPECT_TRUE(InterpretationContainerDouble_equal(container, c2));
  InterpretationContainerDouble_destroy(c2);
  String_destroy(json);
  EXPECT_THROW(InterpretationContainerDouble_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, UnitAccessor) {
  auto unit = InterpretationContainerDouble_unit(container);
  EXPECT_NE(unit, nullptr);
  SymbolUnit_destroy(unit);
  EXPECT_THROW(InterpretationContainerDouble_unit(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerDoubleTest, SelectByConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list =
      InterpretationContainerDouble_select_by_connection(container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerDouble_select_by_connection(nullptr, conn),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerDouble_select_by_connection(container, nullptr),
      std::invalid_argument);
  Connection_destroy(conn);
  ListInterpretationContext_destroy(list);
}

TEST_F(InterpretationContainerDoubleTest, SelectByConnections) {
  ConnectionHandle raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  auto conns = Connections_create(ListConnection_create(raw, 1));
  auto list =
      InterpretationContainerDouble_select_by_connections(container, conns);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerDouble_select_by_connections(nullptr, conns),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerDouble_select_by_connections(container, nullptr),
      std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connections_destroy(conns);
}

TEST_F(InterpretationContainerDoubleTest, SelectByIndependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list = InterpretationContainerDouble_select_by_independent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerDouble_select_by_independent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_select_by_independent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerDoubleTest, SelectByDependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateB"));
  auto list = InterpretationContainerDouble_select_by_dependent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerDouble_select_by_dependent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_select_by_dependent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerDoubleTest, SelectContexts) {
  ConnectionHandle indp_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  ConnectionHandle dep_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateB"))};
  auto indp_list = ListConnection_create(indp_raw, 1);
  auto dep_list  = ListConnection_create(dep_raw, 1);
  auto list      = InterpretationContainerDouble_select_contexts(
      container, indp_list, dep_list);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerDouble_select_contexts(
                   nullptr, indp_list, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_select_contexts(
                   container, nullptr, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerDouble_select_contexts(
                   container, indp_list, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  ListConnection_destroy(indp_list);
  ListConnection_destroy(dep_list);
}
