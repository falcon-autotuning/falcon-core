#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>

#include "falcon-core/communications/messages/SettingRequest.hpp"
#include "falcon-core/generic/Map.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/instrument_interfaces/names/Ports.hpp"
#include "falcon-core/math/Quantity.hpp"

namespace {

using namespace falcon_core::communications::messages;
using namespace falcon_core::generic;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::math;

class SettingRequestTest : public ::testing::Test {
protected:
  std::string message;
  InstrumentPortSP knob_port;
  PortsSP getters;
  MapSP<InstrumentPort, Quantity> setters;

  void SetUp() override {
    message = "msg";

    knob_port = InstrumentPort::Knob(
        "Vg1", "instrument1",
        falcon_core::physics::device_structures::Connection::PlungerGate("P1"));

    getters = std::make_shared<Ports>();
    getters->push_back(knob_port);

    setters = std::make_shared<Map<InstrumentPort, Quantity>>();
    setters->insert(knob_port, std::make_shared<Quantity>(1.23));
  }
};

TEST_F(SettingRequestTest, ConstructorWorks) {
  SettingRequest req(message, getters, setters);

  EXPECT_EQ(req.getters(), getters);
  EXPECT_EQ(req.setters(), setters);
}

TEST_F(SettingRequestTest, ThrowsOnNullGetters) {
  EXPECT_THROW(SettingRequest(message, nullptr, setters),
               std::invalid_argument);
}

TEST_F(SettingRequestTest, ThrowsOnNullSetters) {
  EXPECT_THROW(SettingRequest(message, getters, nullptr),
               std::invalid_argument);
}

TEST_F(SettingRequestTest, CopyConstructorWorks) {
  SettingRequest original(message, getters, setters);

  SettingRequest copy(original);

  EXPECT_EQ(original, copy);

  EXPECT_NE(copy.getters(), original.getters());
  EXPECT_NE(copy.setters(), original.setters());
}

TEST_F(SettingRequestTest, AssignmentOperatorWorks) {
  SettingRequest original(message, getters, setters);

  auto new_getters = std::make_shared<Ports>();
  auto new_setters = std::make_shared<Map<InstrumentPort, Quantity>>();

  SettingRequest assigned("other", new_getters, new_setters);

  assigned = original;

  EXPECT_EQ(original, assigned);

  EXPECT_NE(assigned.getters(), original.getters());
  EXPECT_NE(assigned.setters(), original.setters());
}

TEST_F(SettingRequestTest, EqualityOperatorWorks) {
  SettingRequest lhs(message, getters, setters);
  SettingRequest rhs(message, getters, setters);

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);
}

TEST_F(SettingRequestTest, InequalityOperatorWorks) {
  SettingRequest lhs(message, getters, setters);

  auto different_setters = std::make_shared<Map<InstrumentPort, Quantity>>();
  different_setters->insert(knob_port, std::make_shared<Quantity>(5.0));

  SettingRequest rhs(message, getters, different_setters);

  EXPECT_TRUE(lhs != rhs);
  EXPECT_FALSE(lhs == rhs);
}

TEST_F(SettingRequestTest, SelfAssignmentWorks) {
  SettingRequest req(message, getters, setters);

  req = req;

  EXPECT_EQ(req.getters(), req.getters());
  EXPECT_EQ(req.setters(), req.setters());
}

TEST_F(SettingRequestTest, SerializationRoundTrip) {
  SettingRequest req(message, getters, setters);

  auto string = req.to_json_string();

  auto loaded = SettingRequest::from_json_string<SettingRequest>(string);

  EXPECT_EQ(req, *loaded);
}

} // namespace
