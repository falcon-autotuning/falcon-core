#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContainerString_c_api.h"
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon-core/generic/ListInterpretationContext_c_api.h"
#include "falcon-core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon-core/generic/ListString_c_api.h"
#include "falcon-core/generic/MapInterpretationContextString_c_api.h"
#include "falcon-core/generic/PairInterpretationContextString_c_api.h"
#include "falcon-core/generic/String_c_api.h"

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
  set_last_error(0, nullptr);
  InterpretationContainerString_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  InterpretationContainerString_insert_or_assign(nullptr, ctx1, val1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_insert_or_assign(container, nullptr, val1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_insert_or_assign(container, ctx1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_insert(nullptr, ctx1, val1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_insert(container, nullptr, val1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_insert(container, ctx1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_at(nullptr, ctx1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_at(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_erase(nullptr, ctx1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_erase(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContainerStringTest, SizeEmptyClearContains) {
  EXPECT_EQ(InterpretationContainerString_size(container), 2);
  EXPECT_FALSE(InterpretationContainerString_empty(container));
  InterpretationContainerString_clear(container);
  EXPECT_TRUE(InterpretationContainerString_empty(container));
  set_last_error(0, nullptr);
  InterpretationContainerString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_contains(nullptr, ctx1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_contains(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  InterpretationContainerString_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  InterpretationContainerString_equal(nullptr, c2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_equal(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_not_equal(nullptr, c2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_not_equal(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  InterpretationContainerString_destroy(c2);
  MapInterpretationContextString_destroy(m2);
}

TEST_F(InterpretationContainerStringTest, ToJsonFromJson) {
  auto json = InterpretationContainerString_to_json_string(container);
  auto c2   = InterpretationContainerString_from_json_string(json);
  EXPECT_TRUE(InterpretationContainerString_equal(container, c2));
  InterpretationContainerString_destroy(c2);
  String_destroy(json);
  set_last_error(0, nullptr);
  InterpretationContainerString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContainerStringTest, UnitAccessor) {
  auto unit = InterpretationContainerString_unit(container);
  EXPECT_NE(unit, nullptr);
  SymbolUnit_destroy(unit);
  set_last_error(0, nullptr);
  InterpretationContainerString_unit(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContainerStringTest, SelectByConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list =
      InterpretationContainerString_select_by_connection(container, conn);
  EXPECT_NE(list, nullptr);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_connection(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_connection(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_connections(nullptr, conns);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_connections(container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(list);
  Connections_destroy(conns);
}

TEST_F(InterpretationContainerStringTest, SelectByIndependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateA"));
  auto list = InterpretationContainerString_select_by_independent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_independent_connection(                   nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_independent_connection(                   container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(list);
  Connection_destroy(conn);
}

TEST_F(InterpretationContainerStringTest, SelectByDependentConnection) {
  auto conn = Connection_create_plunger_gate(String_wrap("gateB"));
  auto list = InterpretationContainerString_select_by_dependent_connection(
      container, conn);
  EXPECT_NE(list, nullptr);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_dependent_connection(                   nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_by_dependent_connection(                   container, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  InterpretationContainerString_select_contexts(                   nullptr, indp_list, dep_list);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_contexts(                   container, nullptr, dep_list);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContainerString_select_contexts(                   container, indp_list, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListInterpretationContext_destroy(list);
  ListConnection_destroy(indp_list);
  ListConnection_destroy(dep_list);
}
