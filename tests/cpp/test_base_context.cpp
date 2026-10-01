#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/BaseContext.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"

namespace {
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;

TEST(BaseContextTest, ConstructorWithValidConnection) {
  auto conn = Connection::PlungerGate("a");
  Instrument instr = Instrument::Voltage_Source;
  BaseContext ctx(conn, instr);
  EXPECT_EQ(ctx.connection(), conn);
  EXPECT_EQ(ctx.instrument_type(), instr);
}

TEST(BaseContextTest, ConstructorWithNullConnectionThrows) {
  Instrument instr = Instrument::Voltage_Source;
  EXPECT_THROW({ BaseContext ctx(nullptr, instr); }, std::invalid_argument);
}

TEST(BaseContextTest, ConstructorWithValidPort) {
  auto port =
      InstrumentPort::Knob("knob1", "instrument1", Connection::PlungerGate("a"),
                           Instrument::Voltage_Source);
  BaseContext ctx(port);
  EXPECT_NE(ctx.connection(), nullptr);
}

TEST(BaseContextTest, ConstructorWithNullPortThrows) {
  EXPECT_THROW(BaseContext ctx(nullptr), std::invalid_argument);
}

TEST(BaseContextTest, EqualityOperators) {
  auto conn1 = Connection::PlungerGate("A");
  auto conn2 = Connection::PlungerGate("B");
  Instrument instr1 = Instrument::Voltage_Source;
  Instrument instr2 = Instrument::Current_Source;
  BaseContext ctx1(conn1, instr1);
  BaseContext ctx2(conn1, instr1);
  BaseContext ctx3(conn2, instr1);
  BaseContext ctx4(conn1, instr2);

  EXPECT_TRUE(ctx1 == ctx2);
  EXPECT_TRUE(ctx1 != ctx3);
  EXPECT_NE(ctx1, ctx4);
}

TEST(BaseContextTest, SerializationRoundTrip) {
  auto conn = Connection::PlungerGate("A");
  Instrument instr = Instrument::Voltage_Source;
  BaseContext ctx(conn, instr);
  auto string = ctx.to_json_string();
  BaseContextSP loaded = BaseContext::from_json_string<BaseContext>(string);
  EXPECT_EQ(*loaded, ctx);
  EXPECT_EQ(loaded->instrument_type(), instr);
  EXPECT_NE(loaded->connection(), nullptr);
}

} // namespace
