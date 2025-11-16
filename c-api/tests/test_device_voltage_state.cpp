#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class DeviceVoltageStateTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_barrier_gate(String_wrap("A"));
    unit = SymbolUnit_create_volt();
    dvs  = DeviceVoltageState_create(conn, 1.0, unit);
    dvs2 = DeviceVoltageState_create(conn, 2.0, unit);
  }
  void TearDown() override {
    DeviceVoltageState_destroy(dvs);
    DeviceVoltageState_destroy(dvs2);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
  }
  ConnectionHandle         conn = nullptr;
  SymbolUnitHandle         unit = nullptr;
  DeviceVoltageStateHandle dvs  = nullptr;
  DeviceVoltageStateHandle dvs2 = nullptr;
};

TEST_F(DeviceVoltageStateTest, CreateDestroy) {
  auto d = DeviceVoltageState_create(conn, 3.0, unit);
  DeviceVoltageState_destroy(d);
  set_last_error(0, nullptr);
  DeviceVoltageState_create(nullptr, 1.0, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_create(conn, 1.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, Accessors) {
  auto c = DeviceVoltageState_connection(dvs);
  auto u = DeviceVoltageState_unit(dvs);
  EXPECT_DOUBLE_EQ(DeviceVoltageState_voltage(dvs), 1.0);
  EXPECT_DOUBLE_EQ(DeviceVoltageState_value(dvs), 1.0);
  Connection_destroy(c);
  SymbolUnit_destroy(u);

  set_last_error(0, nullptr);
  DeviceVoltageState_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_unit(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_voltage(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_value(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, ConvertTo) {
  auto u2 = SymbolUnit_create_millivolt();
  DeviceVoltageState_convert_to(dvs, u2);
  SymbolUnit_destroy(u2);
  set_last_error(0, nullptr);
  DeviceVoltageState_convert_to(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_convert_to(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, Arithmetic) {
  auto m1 = DeviceVoltageState_multiply_int(dvs, 2);
  auto m2 = DeviceVoltageState_multiply_double(dvs, 2.0);
  auto m3 = DeviceVoltageState_multiply_quantity(dvs, dvs2);
  auto d1 = DeviceVoltageState_divide_int(dvs, 2);
  auto d2 = DeviceVoltageState_divide_double(dvs, 2.0);
  auto d3 = DeviceVoltageState_divide_quantity(dvs, dvs2);
  auto a3 = DeviceVoltageState_add_quantity(dvs, dvs2);
  auto s3 = DeviceVoltageState_subtract_quantity(dvs, dvs2);
  auto p  = DeviceVoltageState_power(dvs, 2);
  auto n  = DeviceVoltageState_negate(dvs);
  auto ab = DeviceVoltageState_abs(dvs);

  DeviceVoltageState_destroy(m1);
  DeviceVoltageState_destroy(m2);
  DeviceVoltageState_destroy(m3);
  DeviceVoltageState_destroy(d1);
  DeviceVoltageState_destroy(d2);
  DeviceVoltageState_destroy(d3);
  DeviceVoltageState_destroy(a3);
  DeviceVoltageState_destroy(s3);
  DeviceVoltageState_destroy(p);
  DeviceVoltageState_destroy(n);
  DeviceVoltageState_destroy(ab);

  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_add_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_add_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_subtract_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_subtract_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_power(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_negate(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, ArithmeticEquals) {
  EXPECT_EQ(DeviceVoltageState_multiply_equals_int(dvs, 2), dvs);
  EXPECT_EQ(DeviceVoltageState_multiply_equals_double(dvs, 2.0), dvs);
  EXPECT_EQ(DeviceVoltageState_multiply_equals_quantity(dvs, dvs2), dvs);
  EXPECT_EQ(DeviceVoltageState_divide_equals_int(dvs, 2), dvs);
  EXPECT_EQ(DeviceVoltageState_divide_equals_double(dvs, 2.0), dvs);
  EXPECT_EQ(DeviceVoltageState_divide_equals_quantity(dvs, dvs2), dvs);
  EXPECT_EQ(DeviceVoltageState_add_equals_quantity(dvs, dvs2), dvs);
  EXPECT_EQ(DeviceVoltageState_subtract_equals_quantity(dvs, dvs2), dvs);

  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_equals_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_multiply_equals_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_equals_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_divide_equals_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_add_equals_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_add_equals_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_subtract_equals_quantity(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_subtract_equals_quantity(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, Equality) {
  EXPECT_FALSE(DeviceVoltageState_equal(dvs, dvs2));
  EXPECT_TRUE(DeviceVoltageState_not_equal(dvs, dvs2));
  set_last_error(0, nullptr);
  DeviceVoltageState_equal(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_equal(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_not_equal(nullptr, dvs2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_not_equal(dvs, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStateTest, ToJsonFromJson) {
  auto json = DeviceVoltageState_to_json_string(dvs);
  auto d2   = DeviceVoltageState_from_json_string(json);
  EXPECT_TRUE(DeviceVoltageState_equal(dvs, d2));
  DeviceVoltageState_destroy(d2);
  String_destroy(json);
  set_last_error(0, nullptr);
  DeviceVoltageState_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageState_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
