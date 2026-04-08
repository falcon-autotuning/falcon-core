#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes.hpp"

namespace {
using namespace falcon_core::autotuner_interfaces::contexts;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::instrument_interfaces::names;
using namespace falcon_core::physics::units;

TEST(AcquisitionContextTest, ConstructorWithValidConnection) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_EQ(ctx.units(), unit);
}

TEST(AcquisitionContextTest, ConstructorWithNullConnectionThrows) {
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto       unit  = SymbolUnit::Volt();
  EXPECT_THROW(
      { AcquisitionContext ctx(nullptr, instr, unit); }, std::invalid_argument);
}

TEST(AcquisitionContextTest, ConstructorWithValidPort) {
  auto port = InstrumentPort::Knob(
      "knob1", Connection::PlungerGate("a"), InstrumentTypes::VOLTAGE_SOURCE);
  AcquisitionContext ctx(port);
  EXPECT_NE(ctx.units(), nullptr);
}

TEST(AcquisitionContextTest, ConstructorWithNullPortThrows) {
  EXPECT_THROW(AcquisitionContext ctx(nullptr), std::invalid_argument);
}

TEST(AcquisitionContextTest, ConstructorWithValidMeasurementContext) {
  auto                 conn  = Connection::PlungerGate("a");
  Instrument           instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto                 unit  = SymbolUnit::Ampere();
  auto                 base  = std::make_shared<BaseContext>(conn, instr);
  AcquisitionContextSP ctx   = AcquisitionContext::from_context(base, unit);
  EXPECT_EQ(ctx->units(), unit);
}

TEST(AcquisitionContextTest, ConstructorWithNullMeasurementContextThrows) {
  auto unit = SymbolUnit::Ampere();
  EXPECT_THROW(AcquisitionContext::from_context(nullptr, unit),
               std::invalid_argument);
}

TEST(AcquisitionContextTest, OperatorDivideWithNullUnitThrows) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_THROW(
      { ctx / static_cast<SymbolUnitSP>(nullptr); }, std::invalid_argument);
}

TEST(AcquisitionContextTest, OperatorDivideWithNullContextThrows) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_THROW(
      { ctx / static_cast<AcquisitionContextSP>(nullptr); },
      std::invalid_argument);
}

TEST(AcquisitionContextTest, MatchConnectionWithNullThrows) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_THROW({ ctx.match_connection(nullptr); }, std::invalid_argument);
}

TEST(AcquisitionContextTest, SerializationRoundTripJson) {
  auto               conn  = Connection::PlungerGate("A");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  auto               json = ctx.to_json_string();
  auto loaded = AcquisitionContext::from_json_string<AcquisitionContext>(json);
  EXPECT_EQ(loaded->units()->symbol(), unit->symbol());
  EXPECT_EQ(loaded->units()->name(), unit->name());
}

// Test BaseContextSP constructor with nullptr unit (covers throw branch)
TEST(AcquisitionContextTest,
     ConstructorWithNullUnitInMeasurementContextThrows) {
  auto       conn  = Connection::PlungerGate("a");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto       base  = std::make_shared<BaseContext>(conn, instr);
  EXPECT_THROW(AcquisitionContext::from_context(base, nullptr),
               std::invalid_argument);
}

// Test match_instrument_type (covers return branch)
TEST(AcquisitionContextTest, MatchInstrumentType) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_TRUE(ctx.match_instrument_type(instr));
  EXPECT_FALSE(ctx.match_instrument_type(InstrumentTypes::CURRENT_SOURCE));
}

TEST(AcquisitionContextTest, ConstructorWithNullUnitsThrows) {
  auto       conn  = Connection::PlungerGate("a");
  Instrument instr = InstrumentTypes::VOLTAGE_SOURCE;
  EXPECT_THROW(
      { AcquisitionContext ctx(conn, instr, nullptr); }, std::invalid_argument);
}

TEST(AcquisitionContextTest, OperatorDivideWithUnit) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  auto               divided = ctx / SymbolUnit::Ampere();
  EXPECT_EQ(divided->units()->symbol(),
            (*unit / SymbolUnit::Ampere())->symbol());
}

TEST(AcquisitionContextTest, OperatorDivideWithContext) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx1(conn, instr, unit);
  AcquisitionContext ctx2(conn, instr, SymbolUnit::Ampere());
  auto divided = ctx1 / std::make_shared<AcquisitionContext>(ctx2);
  EXPECT_EQ(divided->units()->symbol(),
            (*unit / SymbolUnit::Ampere())->symbol());
}

TEST(AcquisitionContextTest, MatchConnectionTrue) {
  auto               conn  = Connection::PlungerGate("a");
  Instrument         instr = InstrumentTypes::VOLTAGE_SOURCE;
  auto               unit  = SymbolUnit::Volt();
  AcquisitionContext ctx(conn, instr, unit);
  EXPECT_TRUE(ctx.match_connection(conn));
}

}  // namespace
