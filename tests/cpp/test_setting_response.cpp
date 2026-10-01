#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>

#include "falcon-core/communications/messages/SettingResponse.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/math/Quantity.hpp"

namespace {

using namespace falcon_core::communications::messages;
using namespace falcon_core::generic;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::math;

class SettingResponseTest : public ::testing::Test {
protected:
  std::string message;
  InstrumentPortSP knob_port;
  MapSP<InstrumentPort, Quantity> getters;

  void SetUp() override {
    message = "msg";

    knob_port = InstrumentPort::Knob(
        "Vg1", "instrument1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));

    getters = std::make_shared<Map<InstrumentPort, Quantity>>();
    getters->insert(knob_port, std::make_shared<Quantity>(1.23));
  }
};

TEST_F(SettingResponseTest, ConstructorWorks) {
  SettingResponse resp(message, getters);

  EXPECT_EQ(resp.getters(), getters);
}

TEST_F(SettingResponseTest, ThrowsOnNullGetters) {
  EXPECT_THROW(SettingResponse(message, nullptr), std::invalid_argument);
}

TEST_F(SettingResponseTest, CopyConstructorWorks) {
  SettingResponse original(message, getters);

  SettingResponse copy(original);

  EXPECT_EQ(original, copy);

  EXPECT_NE(copy.getters(), original.getters());
}

TEST_F(SettingResponseTest, AssignmentOperatorWorks) {
  SettingResponse original(message, getters);

  auto new_getters = std::make_shared<Map<InstrumentPort, Quantity>>();

  SettingResponse assigned("other", new_getters);

  assigned = original;

  EXPECT_EQ(original, assigned);

  EXPECT_NE(assigned.getters(), original.getters());
}

TEST_F(SettingResponseTest, EqualityOperatorWorks) {
  SettingResponse lhs(message, getters);
  SettingResponse rhs(message, getters);

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);
}

TEST_F(SettingResponseTest, InequalityOperatorWorks) {
  SettingResponse lhs(message, getters);

  auto different_getters = std::make_shared<Map<InstrumentPort, Quantity>>();
  different_getters->insert(knob_port, std::make_shared<Quantity>(5.0));

  SettingResponse rhs(message, different_getters);

  EXPECT_TRUE(lhs != rhs);
  EXPECT_FALSE(lhs == rhs);
}

TEST_F(SettingResponseTest, SelfAssignmentWorks) {
  SettingResponse resp(message, getters);

  resp = resp;

  EXPECT_EQ(resp.getters(), resp.getters());
}

TEST_F(SettingResponseTest, SerializationRoundTrip) {
  SettingResponse resp(message, getters);

  auto string = resp.to_json_string();

  auto loaded = SettingResponse::from_json_string<SettingResponse>(string);

  EXPECT_EQ(resp, *loaded);
}

} // namespace
