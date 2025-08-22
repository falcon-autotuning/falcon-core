#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/macros.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Units.hpp"
using namespace falcon_core;
using namespace falcon_core::physics::units;
#define SPS(...) SP(SymbolUnit, __VA_ARGS__)
#define SPU(...) SP(Unit, __VA_ARGS__)
TEST(TestSymbolUnit, Initialization) {
  SymbolUnit m = Units::Meter;
  SymbolUnit s = Units::Second;
  SymbolUnit v = Units::Volt;

  ASSERT_EQ(m.symbol(), SI::UNIT_SYMBOL_METER);
  ASSERT_EQ(m.name(), SI::UNIT_NAME_METER);
  ASSERT_EQ(s.symbol(), SI::UNIT_SYMBOL_SECOND);
  ASSERT_EQ(s.name(), SI::UNIT_NAME_SECOND);
  ASSERT_EQ(v.symbol(), SI::UNIT_SYMBOL_VOLT);
  ASSERT_EQ(v.name(), SI::UNIT_NAME_VOLT);
}

TEST(TestSymbolUnit, PrefixedUnits) {
  SymbolUnit mm = Units::MilliMeter;
  SymbolUnit kV = Units::KiloVolt;

  ASSERT_EQ(mm.symbol(),
            std::string(SI::MILLI_SYMBOL) + std::string(SI::UNIT_SYMBOL_METER));
  ASSERT_EQ(kV.symbol(),
            std::string(SI::KILO_SYMBOL) + std::string(SI::UNIT_SYMBOL_VOLT));
}
TEST(TestSymbolUnit, Operations) {
  SymbolUnitSP m = SPS(Units::Meter);
  SymbolUnitSP s = SPS(Units::Second);
  SymbolUnitSP v = SPS(Units::Volt);

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
  SymbolUnitSP ohm       = SPS(Units::Ohm);
  SymbolUnitSP v_div_ohm = *v / ohm;
  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(v_div_ohm.unit().dimensions(), ...);
}

TEST(TestSymbolUnit, EqualityAndCompatibility) {
  SymbolUnitSP m1 = SPS(Units::Meter);
  SymbolUnitSP m2 = SPS(Units::Meter);
  SymbolUnitSP s  = SPS(Units::Second);

  ASSERT_EQ(m1->unit(), m2->unit());
  ASSERT_NE(m1->unit(), s->unit());

  SymbolUnitSP mm = SPS(Units::MilliMeter);
  ASSERT_TRUE(m1->is_compatible_with(mm));
  ASSERT_FALSE(m1->is_compatible_with(s));
}

TEST(TestSymbolUnit, Conversion) {
  SymbolUnitSP m  = SPS(Units::Meter);
  SymbolUnitSP mm = SPS(Units::MilliMeter);
  SymbolUnitSP km = SPS(Units::KiloMeter);

  ASSERT_NEAR(m->convert_value_to(1.0, mm), 1000.0, 1e-9);
  ASSERT_NEAR(m->convert_value_to(1.0, km), 0.001, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, m), 1000.0, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, mm), 1e6, 1e-3);
}

TEST(TestSymbolUnit, DerivedUnits) {
  SymbolUnitSP m = SPS(Units::Meter);
  SymbolUnitSP s = SPS(Units::Second);
  SymbolUnitSP n = SPS(Units::Newton);

  SymbolUnitSP m_per_s   = *m / s;
  SymbolUnitSP n_times_m = *n * m;

  ASSERT_EQ(m_per_s->symbol(),
            std::string(SI::UNIT_SYMBOL_METER) + "/" + SI::UNIT_SYMBOL_SECOND);
  ASSERT_EQ(*n_times_m->unit(), *Units::Joule.unit());
  ASSERT_EQ(n_times_m->symbol(), SI::UNIT_SYMBOL_JOULE);
}

TEST(TestSymbolUnit, DimensionlessUnits) {
  SymbolUnitSP dimensionless = SPS(Units::Dimensionless);
  SymbolUnitSP percent       = SPS(Units::Percent);

  // Adjust these checks to your actual dimensions representation
  // ASSERT_TRUE(dimensionless.unit().dimensions().empty());
  // ASSERT_TRUE(percent.unit().dimensions().empty());
  ASSERT_NEAR(percent->unit()->scale_factor(), 0.01, 1e-9);
  ASSERT_NEAR(percent->convert_value_to(100.0, dimensionless), 1.0, 1e-9);
}

TEST(TestSymbolUnit, ComplexUnits) {
  SymbolUnitSP m = SPS(Units::Meter);
  SymbolUnitSP s = SPS(Units::Second);

  SymbolUnitSP acceleration = *m / (*s ^ 2);

  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(acceleration.unit().dimensions(), ...);
  ASSERT_TRUE(acceleration->symbol().find("^-2") != std::string::npos);
}

TEST(TestSymbolUnit, CustomUnit) {
  // Create a custom unit with dimensions {length: 3}
  UnitSP       custom_unit = SPU(Unit({{"LENGTH", 3}}));
  SymbolUnitSP symbol_unit = SPS(SymbolUnit({custom_unit}));

  ASSERT_TRUE(symbol_unit->symbol().find("^3") != std::string::npos);
}

TEST(TestSymbolUnit, SymbolGeneration) {
  UnitSP length_time  = SPU(Unit({{"LENGTH", 1}, {"TIME", 1}}));
  UnitSP complex_unit = SPU(Unit({{"LENGTH", 2}, {"TIME", -1}, {"MASS", 1}}));

  SymbolUnitSP length_time_symbol = SPS(SymbolUnit({length_time}));
  SymbolUnitSP complex_symbol     = SPS(SymbolUnit({complex_unit}));

  ASSERT_TRUE(length_time_symbol->symbol().find(SI::UNIT_SYMBOL_METER) !=
              std::string::npos);
  ASSERT_TRUE(length_time_symbol->symbol().find(SI::UNIT_SYMBOL_SECOND) !=
              std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("kg") != std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("m^2") != std::string::npos);
  ASSERT_TRUE(complex_symbol->symbol().find("s") != std::string::npos);
}

TEST(TestSymbolUnit, WithPrefix) {
  SymbolUnit   m  = Units::Meter;
  SymbolUnitSP km = m.with_prefix(SI::KILO_SYMBOL);

  ASSERT_EQ(km->symbol(), std::string(SI::KILO_SYMBOL) + SI::UNIT_SYMBOL_METER);
  ASSERT_EQ(km->unit()->scale_factor(), 1000.0);
  ASSERT_EQ(km->unit()->dimensions(), m.unit()->dimensions());
}

TEST(TestSymbolUnit, InvalidConversion) {
  SymbolUnitSP m = SPS(Units::Meter);
  SymbolUnitSP s = SPS(Units::Second);

  EXPECT_THROW(m->convert_value_to(10.0, s), std::invalid_argument);
}
TEST(TestSymbolUnit, Comparison) {
  SymbolUnitSP m_per_s = Units::Meter / SPS(Units::Second);
  SymbolUnitSP v       = SPS(SPU(Unit({{"LENGTH", 1}, {"TIME", -1}})));

  SymbolUnit m_per_s_copy = *m_per_s;
  SymbolUnit v_copy       = *v;
  ASSERT_EQ(*m_per_s_copy.unit(), *v_copy.unit());
  // Symbol comparison may differ
}

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <sstream>

TEST(TestSymbolUnit, SerializationRoundTrip) {
  SymbolUnit m = Units::Meter;

  // Serialize to JSON
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(m);
  }

  // Deserialize from JSON
  SymbolUnit m2 = Units::Meter;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(m2);
  }

  ASSERT_EQ(m.symbol(), m2.symbol());
  ASSERT_EQ(m.name(), m2.name());
}

TEST(TestSymbolUnit, StringRepresentations) {
  SymbolUnit m = Units::Meter;

  ASSERT_EQ(m.str(), SI::UNIT_SYMBOL_METER);
  std::string repr_str = m.repr();
  std::cout << "String Representation:\n" << repr_str << std::endl;
  ASSERT_TRUE(repr_str.find("\"value2\": \"m\"") != std::string::npos);
  ASSERT_TRUE(repr_str.find("\"value3\": \"meter\"") != std::string::npos);
}

TEST(TestSymbolUnit, PowerOperations) {
  SymbolUnit m = Units::Meter;

  SymbolUnitSP area = m ^ 2;
  ASSERT_EQ(area->unit()->dimensions().at("LENGTH"), 2);
  ASSERT_TRUE(area->symbol().find("m^2") != std::string::npos);

  SymbolUnitSP volume = m ^ 3;
  ASSERT_EQ(volume->unit()->dimensions().at("LENGTH"), 3);
  ASSERT_TRUE(volume->symbol().find("m^3") != std::string::npos);
}
