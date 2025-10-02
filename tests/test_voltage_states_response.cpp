#include <gtest/gtest.h>

#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <stdexcept>
namespace {
using namespace falcon_core;
using namespace generic;
using namespace communications::messages;
using namespace communications::voltage_states;
using namespace physics::device_structures;
using namespace physics::units;

class VoltageStatesResponseTest : public ::testing::Test {
 protected:
  ConnectionSP          connA = Connection::PlungerGate("A");
  SymbolUnitSP          volt  = SymbolUnit::Volt();
  DeviceVoltageStateSP  dvsA;
  DeviceVoltageStatesSP dvsList;
  void                  SetUp() override {
    dvsA = std::make_shared<DeviceVoltageState>(connA, 1.0, volt);
    auto list = std::make_shared<generic::List<DeviceVoltageState>>();
    list->push_back(dvsA);
    dvsList = std::make_shared<DeviceVoltageStates>(list);
  }
};

TEST_F(VoltageStatesResponseTest, ConstructorAndGetters) {
  VoltageStatesResponse resp("msg", dvsList);
  EXPECT_EQ(resp.message(), "msg");
  EXPECT_EQ(resp.states(), dvsList);
}

TEST_F(VoltageStatesResponseTest, NullStatesThrows) {
  EXPECT_THROW(VoltageStatesResponse("msg", nullptr), std::invalid_argument);
}

TEST_F(VoltageStatesResponseTest, EqualityOperator) {
  VoltageStatesResponse resp1("msg", dvsList);
  VoltageStatesResponse resp2("msg", dvsList);
  VoltageStatesResponse resp3("other", dvsList);
  EXPECT_TRUE(resp1 == resp2);
  EXPECT_FALSE(resp1 == resp3);
}

TEST_F(VoltageStatesResponseTest, InequalityOperator) {
  VoltageStatesResponse resp1("msg", dvsList);
  VoltageStatesResponse resp2("other", dvsList);
  EXPECT_TRUE(resp1 != resp2);
  EXPECT_FALSE(resp1 != resp1);
}

TEST_F(VoltageStatesResponseTest, SerializationRoundTrip) {
  VoltageStatesResponse resp("msg", dvsList);
  auto                  json = resp.to_json_string();
  auto                  resp2 =
      VoltageStatesResponse::from_json_string<VoltageStatesResponse>(json);
  EXPECT_EQ(resp, *resp2);
}
}  // namespace
