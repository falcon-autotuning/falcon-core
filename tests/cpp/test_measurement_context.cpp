#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/autotuner_interfaces/contexts/MeasurementContext.hpp"

namespace {
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::physics::units;

TEST(MeasurementContextTest, ConstructorFromThings) {
  auto conn = Connection::PlungerGate("a");
  Instrument instr = Instrument::Voltage_Source;
  MeasurementContext ctx(conn, instr);
  EXPECT_EQ(*ctx.connection(), *conn);
  EXPECT_EQ(ctx.instrument_type(), instr);
}

TEST(MeasurementContextTest, ConstructorFromBaseContext) {
  auto conn = Connection::PlungerGate("a");
  Instrument instr = Instrument::Voltage_Source;
  BaseContext ctx(conn, instr);
  MeasurementContext mctx(std::make_shared<BaseContext>(ctx));
  EXPECT_EQ(*mctx.connection(), *conn);
  EXPECT_EQ(mctx.instrument_type(), instr);
}

TEST(MeasurementContextTest, ConstructorFromAcquisitionContext) {
  auto conn = Connection::PlungerGate("a");
  Instrument instr = Instrument::Voltage_Source;
  SymbolUnitSP unit = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  MeasurementContext mctx(std::make_shared<AcquisitionContext>(ctx));
  EXPECT_EQ(*mctx.connection(), *conn);
  EXPECT_EQ(mctx.instrument_type(), instr);
}

} // namespace
