#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>
#include <sstream>
#include <stdexcept>

#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace {
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;

TEST(BaseContextTest, ConstructorWithValidConnection) {
  auto        conn  = Connection::PlungerGate("a");
  Instrument  instr = InstrumentTypes::VOLTAGE_SOURCE;
  BaseContext ctx(conn, instr);
  EXPECT_EQ(ctx.connection(), conn);
  EXPECT_EQ(ctx.instrument_type(), instr);
}

TEST(BaseContextTest, ConstructorWithNullConnectionThrows) {
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;
  EXPECT_THROW({ BaseContext ctx(nullptr, instr); }, std::invalid_argument);
}

TEST(BaseContextTest, ConstructorWithValidPort) {
  auto port = InstrumentPort::Knob(
      "knob1", Connection::PlungerGate("a"), InstrumentTypes::VOLTAGE_SOURCE);
  BaseContext ctx(port);
  EXPECT_NE(ctx.connection(), nullptr);
}

TEST(BaseContextTest, ConstructorWithNullPortThrows) {
  EXPECT_THROW(
      { BaseContext ctx(static_cast<InstrumentPortSP>(nullptr)); },
      std::invalid_argument);
}

TEST(BaseContextTest, SerializationRoundTrip) {
  auto        conn  = Connection::PlungerGate("A");
  Instrument  instr = InstrumentTypes::VOLTAGE_SOURCE;
  BaseContext ctx(conn, instr);
  auto        string = ctx.to_json_string();
  auto        loaded = BaseContext::from_json_string<BaseContext>(string);
  EXPECT_EQ(loaded->instrument_type(), instr);
  EXPECT_NE(loaded->connection(), nullptr);
}

}  // namespace
