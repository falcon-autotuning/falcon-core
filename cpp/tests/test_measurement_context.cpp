#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes.hpp"

namespace {
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::physics::units;

TEST(MeasurementContextTest, ConstructorFromThings) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  MeasurementContext ctx(conn, instr);
  EXPECT_EQ(*ctx.connection(), *conn);
  EXPECT_EQ(ctx.instrument_type(), instr);
}

TEST(MeasurementContextTest, ConstructorFromBaseContext) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  BaseContext        ctx(conn, instr);
  MeasurementContext mctx(std::make_shared<BaseContext>(ctx));
  EXPECT_EQ(*mctx.connection(), *conn);
  EXPECT_EQ(mctx.instrument_type(), instr);
}

TEST(MeasurementContextTest, ConstructorFromAcquisitionContext) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  SymbolUnitSP       unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  MeasurementContext mctx(std::make_shared<AcquisitionContext>(ctx));
  EXPECT_EQ(*mctx.connection(), *conn);
  EXPECT_EQ(mctx.instrument_type(), instr);
}

}  // namespace
