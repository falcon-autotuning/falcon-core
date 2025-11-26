#include <gtest/gtest.h>

#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>
#include <stdexcept>
namespace {
using namespace falcon_core::communications::voltage_states;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;

class DeviceVoltageStateTest : public ::testing::Test {
 protected:
  ConnectionSP connA = Connection::PlungerGate("A");
  SymbolUnitSP volt  = SymbolUnit::Volt();
};

TEST_F(DeviceVoltageStateTest, ConstructorAndGetters) {
  DeviceVoltageState dvs(connA, 1.23, volt);
  EXPECT_EQ(dvs.connection(), connA);
  EXPECT_DOUBLE_EQ(dvs.voltage(), 1.23);
  EXPECT_EQ(dvs.unit()->symbol(), "V");
}

TEST_F(DeviceVoltageStateTest, NullConnectionThrows) {
  EXPECT_THROW(DeviceVoltageState(nullptr, 1.0, volt), std::invalid_argument);
}

TEST_F(DeviceVoltageStateTest, NullUnitThrows) {
  EXPECT_THROW(DeviceVoltageState(connA, 1.0, nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStateTest, EqualityOperator) {
  DeviceVoltageState dvs1(connA, 2.0, volt);
  DeviceVoltageState dvs2(connA, 2.0, volt);
  DeviceVoltageState dvs3(connA, 3.0, volt);
  EXPECT_TRUE(dvs1 == dvs2);
  EXPECT_FALSE(dvs1 == dvs3);
}

TEST_F(DeviceVoltageStateTest, InEqualOperator) {
  DeviceVoltageState dvs1(connA, 2.0, volt);
  DeviceVoltageState dvs2(connA, 3.0, volt);
  EXPECT_TRUE(dvs1 != dvs2);
  EXPECT_FALSE(dvs1 != dvs1);
}

TEST_F(DeviceVoltageStateTest, SerializationRoundTrip) {
  DeviceVoltageState dvs(connA, 5.0, volt);
  auto               json = dvs.to_json_string();
  auto dvs2 = DeviceVoltageState::from_json_string<DeviceVoltageState>(json);
  EXPECT_EQ(dvs, *dvs2);
}
}  // namespace
