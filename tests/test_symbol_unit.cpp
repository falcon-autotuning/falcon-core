#include <gtest/gtest.h>

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace {
using namespace falcon_core;
using namespace physics;
using namespace units;
class SymbolUnitTest : public ::testing::Test {
 protected:
  SymbolUnitSP meter() { return SymbolUnit::Meter(); }
  SymbolUnitSP second() { return SymbolUnit::Second(); }
  SymbolUnitSP volt() { return SymbolUnit::Volt(); }
  SymbolUnitSP kilometer() { return SymbolUnit::KiloMeter(); }
  SymbolUnitSP millimeter() { return SymbolUnit::MilliMeter(); }
  SymbolUnitSP dimensionless() { return SymbolUnit::Dimensionless(); }
  SymbolUnitSP percent() { return SymbolUnit::Percent(); }
  SymbolUnitSP celsius() { return SymbolUnit::Celsius(); }
  SymbolUnitSP fahrenheit() { return SymbolUnit::Fahrenheit(); }
  SymbolUnitSP joule() { return SymbolUnit::Joule(); }
  SymbolUnitSP ohm() { return SymbolUnit::Ohm(); }
};

TEST_F(SymbolUnitTest, StaticConstructors) {
  ASSERT_TRUE(meter() != nullptr);
  ASSERT_TRUE(second() != nullptr);
  ASSERT_TRUE(volt() != nullptr);
  ASSERT_TRUE(kilometer() != nullptr);
  ASSERT_TRUE(millimeter() != nullptr);
  ASSERT_TRUE(dimensionless() != nullptr);
  ASSERT_TRUE(percent() != nullptr);
  ASSERT_TRUE(celsius() != nullptr);
  ASSERT_TRUE(fahrenheit() != nullptr);
  ASSERT_TRUE(joule() != nullptr);
  ASSERT_TRUE(ohm() != nullptr);
}

TEST_F(SymbolUnitTest, Properties) {
  auto m = meter();
  ASSERT_EQ(m->symbol(), "m");
  ASSERT_FALSE(m->name().empty());
  ASSERT_TRUE(m->unit() != nullptr);
  ASSERT_GT(m->str().size(), 0);
}

TEST_F(SymbolUnitTest, OperatorMultiplyWorks) {
  auto m      = meter();
  auto s      = second();
  auto result = *m * s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_TRUE(result->symbol().find("m·s") != std::string::npos);
}

TEST_F(SymbolUnitTest, OperatorMultiplyUnitWorks) {
  auto m      = meter();
  auto s      = Unit::Second();
  auto result = *m * s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_TRUE(result->symbol().find("m·s") != std::string::npos);
}

TEST_F(SymbolUnitTest, OperatorMultiplyNullptrThrows) {
  auto         m = meter();
  SymbolUnitSP other;
  EXPECT_THROW(*m * other, std::invalid_argument);
  EXPECT_THROW(m->operator*(UnitSP()), std::invalid_argument);
}

TEST_F(SymbolUnitTest, OperatorDivideWorks) {
  auto m      = meter();
  auto s      = second();
  auto result = *m / s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_TRUE(result->symbol().find("m/s") != std::string::npos);
}

TEST_F(SymbolUnitTest, OperatorDivideUnitWorks) {
  auto m      = meter();
  auto s      = Unit::Second();
  auto result = *m / s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_TRUE(result->symbol().find("m/s") != std::string::npos);
}

TEST_F(SymbolUnitTest, OperatorDivideNullptrThrows) {
  auto         m = meter();
  SymbolUnitSP other;
  EXPECT_THROW(*m / other, std::invalid_argument);
  EXPECT_THROW(m->operator/(UnitSP()), std::invalid_argument);
}

TEST_F(SymbolUnitTest, OperatorPowerWorks) {
  auto m    = meter();
  auto area = *m ^ 2;
  ASSERT_TRUE(area != nullptr);
  ASSERT_TRUE(area->symbol().find("m^2") != std::string::npos);
}

TEST_F(SymbolUnitTest, WithPrefixWorks) {
  auto m  = meter();
  auto km = m->with_prefix("k");
  ASSERT_TRUE(km != nullptr);
  ASSERT_TRUE(km->symbol().find("km") != std::string::npos);
}

TEST_F(SymbolUnitTest, WithPrefixInvalidThrows) {
  auto m = meter();
  EXPECT_THROW(m->with_prefix("invalid"), std::invalid_argument);
}

TEST_F(SymbolUnitTest, ConvertValueToWorks) {
  auto m  = meter();
  auto mm = millimeter();
  ASSERT_NEAR(m->convert_value_to(1.0, mm), 1000.0, 1e-9);
}

TEST_F(SymbolUnitTest, ConvertValueToNullptrThrows) {
  auto m = meter();
  EXPECT_THROW(m->convert_value_to(1.0, nullptr), std::invalid_argument);
}

TEST_F(SymbolUnitTest, ConvertValueToIncompatibleThrows) {
  auto m = meter();
  auto s = second();
  EXPECT_THROW(m->convert_value_to(1.0, s), std::invalid_argument);
}

TEST_F(SymbolUnitTest, IsCompatibleWithWorks) {
  auto m  = meter();
  auto mm = millimeter();
  auto s  = second();
  ASSERT_TRUE(m->is_compatible_with(mm));
  ASSERT_FALSE(m->is_compatible_with(s));
}

TEST_F(SymbolUnitTest, IsCompatibleWithNullptrThrows) {
  auto m = meter();
  EXPECT_THROW(m->is_compatible_with(nullptr), std::invalid_argument);
}

TEST_F(SymbolUnitTest, GetUnitSymbolsAndDimensionSymbols) {
  auto m       = meter();
  auto symbols = m->get_unit_symbols();
  auto dims    = m->get_dimension_symbols();
  ASSERT_FALSE(symbols.empty());
  ASSERT_FALSE(dims.empty());
}

TEST_F(SymbolUnitTest, SerializationRoundTrip) {
  auto              m = meter();
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(m);
  }
  SymbolUnitSP m2 = SymbolUnit::Meter();
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(m2);
  }
  ASSERT_EQ(m->symbol(), m2->symbol());
  ASSERT_EQ(m->name(), m2->name());
  ASSERT_EQ(m->unit()->dimensions(), m2->unit()->dimensions());
}

TEST_F(SymbolUnitTest, CustomConstructor) {
  auto custom_unit = std::make_shared<Unit>(TotalDimensions({{"LENGTH", 3}}));
  SymbolUnit custom_symbol(custom_unit);
  ASSERT_TRUE(custom_symbol.symbol().find("^3") != std::string::npos);
  ASSERT_EQ(custom_symbol.unit()->dimensions().at("LENGTH"), 3);
}

TEST_F(SymbolUnitTest, Initialization) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();
  SymbolUnitSP v = SymbolUnit::Volt();

  ASSERT_EQ(m->symbol(), SI::UNIT_SYMBOL_METER);
  ASSERT_EQ(m->name(), SI::UNIT_NAME_METER);
  ASSERT_EQ(s->symbol(), SI::UNIT_SYMBOL_SECOND);
  ASSERT_EQ(s->name(), SI::UNIT_NAME_SECOND);
  ASSERT_EQ(v->symbol(), SI::UNIT_SYMBOL_VOLT);
  ASSERT_EQ(v->name(), SI::UNIT_NAME_VOLT);
}

TEST_F(SymbolUnitTest, PrefixedSymbolUnit) {
  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  SymbolUnitSP kV = SymbolUnit::KiloVolt();

  ASSERT_EQ(mm->symbol(),
            std::string(SI::MILLI_SYMBOL) + std::string(SI::UNIT_SYMBOL_METER));
  ASSERT_EQ(kV->symbol(),
            std::string(SI::KILO_SYMBOL) + std::string(SI::UNIT_SYMBOL_VOLT));
}
TEST_F(SymbolUnitTest, Operations) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();
  SymbolUnitSP v = SymbolUnit::Volt();

  // Multiplication
  SymbolUnitSP m_times_s = *m * s;
  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(m_times_s.unit().dimensions(), ...);
  ASSERT_EQ(m_times_s->symbol(),
            std::string(SI::UNIT_SYMBOL_METER) + "·" + SI::UNIT_SYMBOL_SECOND);

  // Division
  SymbolUnitSP m_per_s = *m / s;
  ASSERT_EQ(m_per_s->symbol(),
            std::string(SI::UNIT_SYMBOL_METER) + "/" + SI::UNIT_SYMBOL_SECOND);

  // More complex operations
  SymbolUnitSP ohm       = SymbolUnit::Ohm();
  SymbolUnitSP v_div_ohm = *v / ohm;
  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(v_div_ohm.unit().dimensions(), ...);
}

TEST_F(SymbolUnitTest, EqualityAndCompatibility) {
  SymbolUnitSP m1 = SymbolUnit::Meter();
  SymbolUnitSP m2 = SymbolUnit::Meter();
  SymbolUnitSP s  = SymbolUnit::Second();

  ASSERT_EQ(*m1->unit(), *m2->unit());
  ASSERT_NE(m1->unit(), s->unit());

  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  ASSERT_TRUE(m1->is_compatible_with(mm));
  ASSERT_FALSE(m1->is_compatible_with(s));
}

TEST_F(SymbolUnitTest, Conversion) {
  SymbolUnitSP m  = SymbolUnit::Meter();
  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  SymbolUnitSP km = SymbolUnit::KiloMeter();

  ASSERT_NEAR(m->convert_value_to(1.0, mm), 1000.0, 1e-9);
  ASSERT_NEAR(m->convert_value_to(1.0, km), 0.001, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, m), 1000.0, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, mm), 1e6, 1e-3);
}

TEST_F(SymbolUnitTest, DerivedSymbolUnit) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();
  SymbolUnitSP n = SymbolUnit::Newton();

  SymbolUnitSP m_per_s   = *m / s;
  SymbolUnitSP n_times_m = *n * m;

  ASSERT_EQ(m_per_s->symbol(),
            std::string(SI::UNIT_SYMBOL_METER) + "/" + SI::UNIT_SYMBOL_SECOND);
  ASSERT_EQ(*n_times_m->unit(), *SymbolUnit::Joule()->unit());
  ASSERT_EQ(n_times_m->symbol(), SI::UNIT_SYMBOL_JOULE);
}

TEST_F(SymbolUnitTest, DimensionlessSymbolUnit) {
  SymbolUnitSP dimensionless = SymbolUnit::Dimensionless();
  SymbolUnitSP percent       = SymbolUnit::Percent();

  // Adjust these checks to your actual dimensions representation
  // ASSERT_TRUE(dimensionless.unit().dimensions().empty());
  // ASSERT_TRUE(percent.unit().dimensions().empty());
  ASSERT_NEAR(percent->unit()->scale_factor(), 0.01, 1e-9);
  ASSERT_NEAR(percent->convert_value_to(100.0, dimensionless), 1.0, 1e-9);
}

TEST_F(SymbolUnitTest, ComplexSymbolUnit) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();

  SymbolUnitSP acceleration = *m / (*s ^ 2);

  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(acceleration.unit().dimensions(), ...);
  ASSERT_TRUE(acceleration->symbol().find("^-2") != std::string::npos);
}

TEST_F(SymbolUnitTest, CustomUnit) {
  // Create a custom unit with dimensions {length: 3}
  UnitSP       custom_unit = std::make_shared<Unit>(Unit({{"LENGTH", 3}}));
  SymbolUnitSP symbol_unit =
      std::make_shared<SymbolUnit>(SymbolUnit({custom_unit}));

  ASSERT_TRUE(symbol_unit->symbol().find("^3") != std::string::npos);
}

TEST_F(SymbolUnitTest, SymbolGeneration) {
  UnitSP length_time =
      std::make_shared<Unit>(Unit({{"LENGTH", 1}, {"TIME", 1}}));
  UnitSP complex_unit =
      std::make_shared<Unit>(Unit({{"LENGTH", 2}, {"TIME", -1}, {"MASS", 1}}));

  SymbolUnitSP length_time_symbol =
      std::make_shared<SymbolUnit>(SymbolUnit({length_time}));
  SymbolUnitSP complex_symbol =
      std::make_shared<SymbolUnit>(SymbolUnit({complex_unit}));

  ASSERT_TRUE(length_time_symbol->symbol().find(SI::UNIT_SYMBOL_METER) !=
              std::string::npos);
  ASSERT_TRUE(length_time_symbol->symbol().find(SI::UNIT_SYMBOL_SECOND) !=
              std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("kg") != std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("m^2") != std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("s") != std::string::npos);
}

TEST_F(SymbolUnitTest, WithPrefix) {
  SymbolUnitSP m  = SymbolUnit::Meter();
  SymbolUnitSP km = m->with_prefix(SI::KILO_SYMBOL);

  ASSERT_EQ(km->symbol(), std::string(SI::KILO_SYMBOL) + SI::UNIT_SYMBOL_METER);
  ASSERT_EQ(km->unit()->scale_factor(), 1000.0);
  ASSERT_EQ(km->unit()->dimensions(), m->unit()->dimensions());
}

TEST_F(SymbolUnitTest, InvalidConversion) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();

  EXPECT_THROW(m->convert_value_to(10.0, s), std::invalid_argument);
}

TEST_F(SymbolUnitTest, Comparison) {
  SymbolUnitSP m_per_s = *SymbolUnit::Meter() / SymbolUnit::Second();
  SymbolUnitSP v       = std::make_shared<SymbolUnit>(
      std::make_shared<Unit>(Unit({{"LENGTH", 1}, {"TIME", -1}})));

  SymbolUnit m_per_s_copy = *m_per_s;
  SymbolUnit v_copy       = *v;
  ASSERT_EQ(*m_per_s_copy.unit(), *v_copy.unit());
  // Symbol comparison may differ
}

TEST_F(SymbolUnitTest, PowerOperations) {
  SymbolUnitSP m = SymbolUnit::Meter();

  SymbolUnitSP area = *m ^ 2;
  ASSERT_EQ(area->unit()->dimensions().at("LENGTH"), 2);
  ASSERT_TRUE(area->symbol().find("m^2") != std::string::npos);

  SymbolUnitSP volume = *m ^ 3;
  ASSERT_EQ(volume->unit()->dimensions().at("LENGTH"), 3);
  ASSERT_TRUE(volume->symbol().find("m^3") != std::string::npos);
}
TEST_F(SymbolUnitTest, AllStaticConstructors) {
  ASSERT_TRUE(SymbolUnit::Meter() != nullptr);
  ASSERT_TRUE(SymbolUnit::Kilogram() != nullptr);
  ASSERT_TRUE(SymbolUnit::Second() != nullptr);
  ASSERT_TRUE(SymbolUnit::Ampere() != nullptr);
  ASSERT_TRUE(SymbolUnit::Kelvin() != nullptr);
  ASSERT_TRUE(SymbolUnit::Mole() != nullptr);
  ASSERT_TRUE(SymbolUnit::Candela() != nullptr);
  ASSERT_TRUE(SymbolUnit::Hertz() != nullptr);
  ASSERT_TRUE(SymbolUnit::Newton() != nullptr);
  ASSERT_TRUE(SymbolUnit::Pascal() != nullptr);
  ASSERT_TRUE(SymbolUnit::Joule() != nullptr);
  ASSERT_TRUE(SymbolUnit::Watt() != nullptr);
  ASSERT_TRUE(SymbolUnit::Coulomb() != nullptr);
  ASSERT_TRUE(SymbolUnit::Volt() != nullptr);
  ASSERT_TRUE(SymbolUnit::Farad() != nullptr);
  ASSERT_TRUE(SymbolUnit::Ohm() != nullptr);
  ASSERT_TRUE(SymbolUnit::Siemens() != nullptr);
  ASSERT_TRUE(SymbolUnit::Weber() != nullptr);
  ASSERT_TRUE(SymbolUnit::Tesla() != nullptr);
  ASSERT_TRUE(SymbolUnit::Henry() != nullptr);
  ASSERT_TRUE(SymbolUnit::Minute() != nullptr);
  ASSERT_TRUE(SymbolUnit::Hour() != nullptr);
  ASSERT_TRUE(SymbolUnit::ElectronVolt() != nullptr);
  ASSERT_TRUE(SymbolUnit::Celsius() != nullptr);
  ASSERT_TRUE(SymbolUnit::Fahrenheit() != nullptr);
  ASSERT_TRUE(SymbolUnit::Dimensionless() != nullptr);
  ASSERT_TRUE(SymbolUnit::Percent() != nullptr);
  ASSERT_TRUE(SymbolUnit::Radian() != nullptr);

  // Also test all prefixed and derived units
  ASSERT_TRUE(SymbolUnit::KiloMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliVolt() != nullptr);
  ASSERT_TRUE(SymbolUnit::KiloVolt() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliAmpere() != nullptr);
  ASSERT_TRUE(SymbolUnit::MicroAmpere() != nullptr);
  ASSERT_TRUE(SymbolUnit::NanoAmpere() != nullptr);
  ASSERT_TRUE(SymbolUnit::PicoAmpere() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::MicroSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::NanoSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::PicoSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliOhm() != nullptr);
  ASSERT_TRUE(SymbolUnit::KiloOhm() != nullptr);
  ASSERT_TRUE(SymbolUnit::MegaOhm() != nullptr);
  ASSERT_TRUE(SymbolUnit::MilliHertz() != nullptr);
  ASSERT_TRUE(SymbolUnit::KiloHertz() != nullptr);
  ASSERT_TRUE(SymbolUnit::MegaHertz() != nullptr);
  ASSERT_TRUE(SymbolUnit::GigaHertz() != nullptr);
  ASSERT_TRUE(SymbolUnit::MetersPerSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::MetersPerSecondSquared() != nullptr);
  ASSERT_TRUE(SymbolUnit::NewtonMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::NewtonPerMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::VoltsPerMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::VoltsPerSecond() != nullptr);
  ASSERT_TRUE(SymbolUnit::AmperesPerMeter() != nullptr);
  ASSERT_TRUE(SymbolUnit::VoltsPerAmpere() != nullptr);
  ASSERT_TRUE(SymbolUnit::WattsPerMeterKelvin() != nullptr);
}

TEST_F(SymbolUnitTest, DimensionlessSymbols) {
  ASSERT_EQ(SymbolUnit::Dimensionless()->symbol(), "");
  ASSERT_EQ(SymbolUnit::Radian()->symbol(), "rad");
  ASSERT_EQ(SymbolUnit::Percent()->symbol(), "%");
}

TEST_F(SymbolUnitTest, InvMeter) {
  auto inv_meter = *Unit::Meter() / (*Unit::Meter() ^ 2);
  auto symbol    = SymbolUnit(inv_meter);
  ASSERT_EQ(symbol.name(), "1/m");
}

TEST_F(SymbolUnitTest, CustomCrash) {
  auto custom = std::make_shared<Unit>(std::map<std::string, int>{{"woah", 1}});
  ASSERT_THROW(SymbolUnit thebads(custom), std::invalid_argument);
}
}  // namespace
