#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainerString_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapInterpretationContextString_c_api.h"
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class InterpretationContainerStringTest : public ::testing::Test {
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
    pair1 = PairInterpretationContextString_create(ctx1, String_wrap("hello"));
    pair2 = PairInterpretationContextString_create(ctx2, String_wrap("world"));
    PairInterpretationContextStringHandle arr[2] = {pair1, pair2};
    map       = MapInterpretationContextString_create(arr, 2);
    container = InterpretationContainerString_create(map);
    val1      = String_wrap("amazing");
    val2      = String_wrap("woah");
  }
  void TearDown() override {
    InterpretationContainerString_destroy(container);
    MapInterpretationContextString_destroy(map);
    PairInterpretationContextString_destroy(pair1);
    PairInterpretationContextString_destroy(pair2);
    InterpretationContext_destroy(ctx1);
    InterpretationContext_destroy(ctx2);
  }
  bool String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
  StringHandle                          val1;
  StringHandle                          val2;
  InterpretationContextHandle           ctx1;
  InterpretationContextHandle           ctx2;
  PairInterpretationContextStringHandle pair1;
  PairInterpretationContextStringHandle pair2;
  MapInterpretationContextStringHandle  map;
  InterpretationContainerStringHandle   container;
};

TEST_F(InterpretationContainerStringTest, CreateDestroy) {
  EXPECT_THROW(InterpretationContainerString_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, InsertAssignAccessErase) {
  InterpretationContainerString_insert_or_assign(container, ctx1, val1);
  EXPECT_TRUE(
      String_equal(InterpretationContainerString_at(container, ctx1), val1));
  InterpretationContainerString_insert(container, ctx2, val2);
  EXPECT_TRUE(
      String_equal(InterpretationContainerString_at(container, ctx2), val2));
  InterpretationContainerString_erase(container, ctx2);
  EXPECT_FALSE(InterpretationContainerString_contains(container, ctx2));
  EXPECT_THROW(
      InterpretationContainerString_insert_or_assign(nullptr, ctx1, val1),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerString_insert_or_assign(container, nullptr, val1),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerString_insert_or_assign(container, ctx1, nullptr),
      std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_insert(nullptr, ctx1, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_insert(container, nullptr, val1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_insert(container, ctx1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_at(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_at(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_erase(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_erase(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, SizeEmptyClearContains) {
  EXPECT_EQ(InterpretationContainerString_size(container), 2);
  EXPECT_FALSE(InterpretationContainerString_empty(container));
  InterpretationContainerString_clear(container);
  EXPECT_TRUE(InterpretationContainerString_empty(container));
  EXPECT_THROW(InterpretationContainerString_size(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_empty(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_clear(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_contains(nullptr, ctx1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_contains(container, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, KeysValuesItems) {
  auto keys   = InterpretationContainerString_keys(container);
  auto values = InterpretationContainerString_values(container);
  auto items  = InterpretationContainerString_items(container);
  EXPECT_NE(keys, nullptr);
  EXPECT_NE(values, nullptr);
  EXPECT_NE(items, nullptr);
  ListInterpretationContext_destroy(keys);
  ListString_destroy(values);
  ListPairInterpretationContextString_destroy(items);
  EXPECT_THROW(InterpretationContainerString_keys(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_values(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_items(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, Equality) {
  PairInterpretationContextStringHandle arr[2] = {pair1, pair2};
  auto m2 = MapInterpretationContextString_create(arr, 2);
  auto c2 = InterpretationContainerString_create(m2);
  EXPECT_TRUE(InterpretationContainerString_equal(container, c2));
  EXPECT_FALSE(InterpretationContainerString_not_equal(container, c2));
  InterpretationContainerString_insert_or_assign(c2, ctx1, val1);
  EXPECT_FALSE(InterpretationContainerString_equal(container, c2));
  EXPECT_TRUE(InterpretationContainerString_not_equal(container, c2));
  EXPECT_THROW(InterpretationContainerString_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_equal(container, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_not_equal(nullptr, c2),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_not_equal(container, nullptr),
               std::invalid_argument);
  InterpretationContainerString_destroy(c2);
  MapInterpretationContextString_destroy(m2);
}

TEST_F(InterpretationContainerStringTest, ToJsonFromJson) {
  auto json = InterpretationContainerString_to_json_string(container);
  auto c2   = InterpretationContainerString_from_json_string(json);
  EXPECT_TRUE(InterpretationContainerString_equal(container, c2));
  InterpretationContainerString_destroy(c2);
  String_destroy(json);
  EXPECT_THROW(InterpretationContainerString_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, UnitAccessor) {
  auto unit = InterpretationContainerString_unit(container);
  EXPECT_NE(unit, nullptr);
  SymbolUnit_destroy(unit);
  EXPECT_THROW(InterpretationContainerString_unit(nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContainerStringTest, SelectByConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list =
      InterpretationContainerString_select_by_connection(container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerString_select_by_connection(nullptr, conn),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerString_select_by_connection(container, nullptr),
      std::invalid_argument);
  Connection_destroy(conn);
  ListInterpretationContext_destroy(list);
}

TEST_F(InterpretationContainerStringTest, SelectByConnections) {
  ConnectionHandle raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  auto conns = Connections_create(ListConnection_create(raw, 1));
  auto list =
      InterpretationContainerString_select_by_connections(container, conns);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(
      InterpretationContainerString_select_by_connections(nullptr, conns),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContainerString_select_by_connections(container, nullptr),
      std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connections_destroy(conns);
}

TEST_F(InterpretationContainerStringTest, SelectByIndependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list = InterpretationContainerString_select_by_independent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerString_select_by_independent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_select_by_independent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerStringTest, SelectByDependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateB"));
  auto list = InterpretationContainerString_select_by_dependent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerString_select_by_dependent_connection(
                   nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_select_by_dependent_connection(
                   container, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerStringTest, SelectContexts) {
  ConnectionHandle indp_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateA"))};
  ConnectionHandle dep_raw[1] = {
      Connection_create_plunger_gate(String_wrap("gateB"))};
  auto indp_list = ListConnection_create(indp_raw, 1);
  auto dep_list  = ListConnection_create(dep_raw, 1);
  auto list      = InterpretationContainerString_select_contexts(
      container, indp_list, dep_list);
  EXPECT_NE(list, nullptr);
  EXPECT_THROW(InterpretationContainerString_select_contexts(
                   nullptr, indp_list, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_select_contexts(
                   container, nullptr, dep_list),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContainerString_select_contexts(
                   container, indp_list, nullptr),
               std::invalid_argument);
  ListInterpretationContext_destroy(list);
  ListConnection_destroy(indp_list);
  ListConnection_destroy(dep_list);
}
