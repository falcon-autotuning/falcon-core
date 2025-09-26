#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace tests {
using namespace falcon_core;
using namespace falcon_core::physics::units;
class UnitTest : public ::testing::Test {};

TEST_F(UnitTest, ConstructorWithDimensionsOnly) {
  TotalDimensions dims = {{"LENGTH", 1}};
  Unit            u(dims);
  ASSERT_EQ(u.dimensions(), dims);
  ASSERT_DOUBLE_EQ(u.scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(u.offset(), 0.0);
  ASSERT_EQ(u.prefix(), SI::UNIT_SYMBOL);
}

TEST_F(UnitTest, ConstructorWithAllArguments) {
  TotalDimensions dims = {{"LENGTH", 2}, {"TIME", -1}};
  Unit            u(dims, 42.0, 3.14, "k");
  ASSERT_EQ(u.dimensions(), dims);
  ASSERT_DOUBLE_EQ(u.scale_factor(), 42.0);
  ASSERT_DOUBLE_EQ(u.offset(), 3.14);
  ASSERT_EQ(u.prefix(), "k");
}

TEST_F(UnitTest, StaticConstructors) {
  ASSERT_EQ(Unit::Meter()->dimensions().at(SI::DIMENSION_LENGTH), 1);
  ASSERT_EQ(Unit::Kilogram()->dimensions().at(SI::DIMENSION_MASS), 1);
  ASSERT_EQ(Unit::Second()->dimensions().at(SI::DIMENSION_TIME), 1);
  ASSERT_EQ(Unit::Ampere()->dimensions().at(SI::DIMENSION_CURRENT), 1);
  ASSERT_EQ(Unit::Kelvin()->dimensions().at(SI::DIMENSION_TEMPERATURE), 1);
  ASSERT_EQ(Unit::Mole()->dimensions().at(SI::DIMENSION_AMOUNT), 1);
  ASSERT_EQ(Unit::Candela()->dimensions().at(SI::DIMENSION_LUMINOSITY), 1);
  ASSERT_EQ(Unit::Dimensionless()->dimensions().size(), 0);
}

TEST_F(UnitTest, PrefixAndOffsetAccessors) {
  auto m = Unit::Meter();
  ASSERT_EQ(m->prefix(), SI::UNIT_SYMBOL);
  ASSERT_DOUBLE_EQ(m->offset(), 0.0);

  auto c = Unit::Celsius();
  ASSERT_DOUBLE_EQ(c->offset(), 273.15);
  ASSERT_EQ(c->prefix(), SI::UNIT_SYMBOL);
}

TEST_F(UnitTest, OperatorMultiplyNullptrThrows) {
  auto m = Unit::Meter();
  EXPECT_THROW(*m * nullptr, std::invalid_argument);
}

TEST_F(UnitTest, OperatorDivideNullptrThrows) {
  auto m = Unit::Meter();
  EXPECT_THROW(*m / nullptr, std::invalid_argument);
}

TEST_F(UnitTest, ConvertValueToNullptrThrows) {
  auto m = Unit::Meter();
  EXPECT_THROW(m->convert_value_to(1.0, nullptr), std::invalid_argument);
}

TEST_F(UnitTest, IsCompatibleWithNullptrThrows) {
  auto m = Unit::Meter();
  EXPECT_THROW(m->is_compatible_with(nullptr), std::invalid_argument);
}

TEST_F(UnitTest, OperatorMultiplyWorks) {
  auto m      = Unit::Meter();
  auto s      = Unit::Second();
  auto result = *m * s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_EQ(result->dimensions().at(SI::DIMENSION_LENGTH), 1);
  ASSERT_EQ(result->dimensions().at(SI::DIMENSION_TIME), 1);
}

TEST_F(UnitTest, OperatorDivideWorks) {
  auto m      = Unit::Meter();
  auto s      = Unit::Second();
  auto result = *m / s;
  ASSERT_TRUE(result != nullptr);
  ASSERT_EQ(result->dimensions().at(SI::DIMENSION_LENGTH), 1);
  ASSERT_EQ(result->dimensions().at(SI::DIMENSION_TIME), -1);
}

TEST_F(UnitTest, OperatorPowerWorks) {
  auto m      = Unit::Meter();
  auto result = *m ^ 2;
  ASSERT_TRUE(result != nullptr);
  ASSERT_EQ(result->dimensions().at(SI::DIMENSION_LENGTH), 2);
}

TEST_F(UnitTest, WithPrefixWorks) {
  auto m  = Unit::Meter();
  auto km = m->with_prefix(SI::KILO_SYMBOL);
  ASSERT_TRUE(km != nullptr);
  ASSERT_EQ(km->prefix(), SI::KILO_SYMBOL);
  ASSERT_EQ(km->scale_factor(), 1000.0);
  ASSERT_EQ(km->dimensions(), m->dimensions());
}

TEST_F(UnitTest, WithPrefixInvalidThrows) {
  auto m = Unit::Meter();
  EXPECT_THROW(m->with_prefix("invalid"), std::invalid_argument);
}

TEST_F(UnitTest, GetMilliMicroNanoPicoKiloMegaGiga) {
  auto   m         = Unit::Meter();
  double tolerance = 1e6;
  ASSERT_NEAR(m->get_milli()->scale_factor(), 0.001, tolerance);
  ASSERT_NEAR(m->get_micro()->scale_factor(), 1e-6, tolerance);
  ASSERT_NEAR(m->get_nano()->scale_factor(), 1e-9, tolerance);
  ASSERT_NEAR(m->get_pico()->scale_factor(), 1e-12, tolerance);
  ASSERT_NEAR(m->get_kilo()->scale_factor(), 1000.0, tolerance);
  ASSERT_NEAR(m->get_mega()->scale_factor(), 1e6, tolerance);
  ASSERT_NEAR(m->get_giga()->scale_factor(), 1e9, tolerance);
}

TEST_F(UnitTest, ConvertValueToWorks) {
  auto m  = Unit::Meter();
  auto mm = m->get_milli();
  ASSERT_DOUBLE_EQ(m->convert_value_to(1.0, mm), 1000.0);
}

TEST_F(UnitTest, ConvertValueToIncompatibleThrows) {
  auto m = Unit::Meter();
  auto s = Unit::Second();
  EXPECT_THROW(m->convert_value_to(1.0, s), std::invalid_argument);
}

TEST_F(UnitTest, IsCompatibleWithWorks) {
  auto m  = Unit::Meter();
  auto mm = m->get_milli();
  auto s  = Unit::Second();
  ASSERT_TRUE(m->is_compatible_with(mm));
  ASSERT_FALSE(m->is_compatible_with(s));
}

TEST_F(UnitTest, CleanDimensionsRemovesZeroExponents) {
  TotalDimensions dims = {{"LENGTH", 1}, {"TIME", 0}};
  Unit::clean_dimensions(dims);
  ASSERT_EQ(dims.count("TIME"), 0);
  ASSERT_EQ(dims.at("LENGTH"), 1);
}

TEST_F(UnitTest, SerializationRoundTrip) {
  auto              m = Unit::Meter();
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(m);
  }
  UnitSP m2 = Unit::Meter();
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(m2);
  }
  ASSERT_EQ(m->dimensions(), m2->dimensions());
  ASSERT_EQ(m->scale_factor(), m2->scale_factor());
  ASSERT_EQ(m->offset(), m2->offset());
  ASSERT_EQ(m->prefix(), m2->prefix());
}
TEST_F(UnitTest, Initialization) {
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

TEST_F(UnitTest, PrefixedSymbolUnit) {
  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  SymbolUnitSP kV = SymbolUnit::KiloVolt();

  ASSERT_EQ(mm->symbol(),
            std::string(SI::MILLI_SYMBOL) + std::string(SI::UNIT_SYMBOL_METER));
  ASSERT_EQ(kV->symbol(),
            std::string(SI::KILO_SYMBOL) + std::string(SI::UNIT_SYMBOL_VOLT));
}
TEST_F(UnitTest, Operations) {
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

TEST_F(UnitTest, EqualityAndCompatibility) {
  SymbolUnitSP m1 = SymbolUnit::Meter();
  SymbolUnitSP m2 = SymbolUnit::Meter();
  SymbolUnitSP s  = SymbolUnit::Second();

  ASSERT_EQ(*m1->unit(), *m2->unit());
  ASSERT_NE(m1->unit(), s->unit());

  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  ASSERT_TRUE(m1->is_compatible_with(mm));
  ASSERT_FALSE(m1->is_compatible_with(s));
}

TEST_F(UnitTest, Conversion) {
  SymbolUnitSP m  = SymbolUnit::Meter();
  SymbolUnitSP mm = SymbolUnit::MilliMeter();
  SymbolUnitSP km = SymbolUnit::KiloMeter();

  ASSERT_NEAR(m->convert_value_to(1.0, mm), 1000.0, 1e-9);
  ASSERT_NEAR(m->convert_value_to(1.0, km), 0.001, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, m), 1000.0, 1e-9);
  ASSERT_NEAR(km->convert_value_to(1.0, mm), 1e6, 1e-3);
}

TEST_F(UnitTest, DerivedSymbolUnit) {
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

TEST_F(UnitTest, DimensionlessSymbolUnit) {
  SymbolUnitSP dimensionless = SymbolUnit::Dimensionless();
  SymbolUnitSP percent       = SymbolUnit::Percent();

  // Adjust these checks to your actual dimensions representation
  // ASSERT_TRUE(dimensionless.unit().dimensions().empty());
  // ASSERT_TRUE(percent.unit().dimensions().empty());
  ASSERT_NEAR(percent->unit()->scale_factor(), 0.01, 1e-9);
  ASSERT_NEAR(percent->convert_value_to(100.0, dimensionless), 1.0, 1e-9);
}

TEST_F(UnitTest, ComplexSymbolUnit) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();

  SymbolUnitSP acceleration = *m / (*s ^ 2);

  // Adjust this check to your actual dimensions representation
  // ASSERT_EQ(acceleration.unit().dimensions(), ...);
  ASSERT_TRUE(acceleration->symbol().find("^-2") != std::string::npos);
}

TEST_F(UnitTest, CustomUnit) {
  // Create a custom unit with dimensions {length: 3}
  UnitSP       custom_unit = std::make_shared<Unit>(Unit({{"LENGTH", 3}}));
  SymbolUnitSP symbol_unit =
      std::make_shared<SymbolUnit>(SymbolUnit({custom_unit}));

  ASSERT_TRUE(symbol_unit->symbol().find("^3") != std::string::npos);
}

TEST_F(UnitTest, SymbolGeneration) {
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

TEST_F(UnitTest, WithPrefix) {
  SymbolUnitSP m  = SymbolUnit::Meter();
  SymbolUnitSP km = m->with_prefix(SI::KILO_SYMBOL);

  ASSERT_EQ(km->symbol(), std::string(SI::KILO_SYMBOL) + SI::UNIT_SYMBOL_METER);
  ASSERT_EQ(km->unit()->scale_factor(), 1000.0);
  ASSERT_EQ(km->unit()->dimensions(), m->unit()->dimensions());
}

TEST_F(UnitTest, InvalidConversion) {
  SymbolUnitSP m = SymbolUnit::Meter();
  SymbolUnitSP s = SymbolUnit::Second();

  EXPECT_THROW(m->convert_value_to(10.0, s), std::invalid_argument);
}

TEST_F(UnitTest, Comparison) {
  SymbolUnitSP m_per_s = *SymbolUnit::Meter() / SymbolUnit::Second();
  SymbolUnitSP v       = std::make_shared<SymbolUnit>(
      std::make_shared<Unit>(Unit({{"LENGTH", 1}, {"TIME", -1}})));

  SymbolUnit m_per_s_copy = *m_per_s;
  SymbolUnit v_copy       = *v;
  ASSERT_EQ(*m_per_s_copy.unit(), *v_copy.unit());
  // Symbol comparison may differ
}

TEST_F(UnitTest, AllStaticConstructors) {
  ASSERT_TRUE(Unit::Meter() != nullptr);
  ASSERT_TRUE(Unit::Kilogram() != nullptr);
  ASSERT_TRUE(Unit::Second() != nullptr);
  ASSERT_TRUE(Unit::Ampere() != nullptr);
  ASSERT_TRUE(Unit::Kelvin() != nullptr);
  ASSERT_TRUE(Unit::Mole() != nullptr);
  ASSERT_TRUE(Unit::Candela() != nullptr);
  ASSERT_TRUE(Unit::Hertz() != nullptr);
  ASSERT_TRUE(Unit::Newton() != nullptr);
  ASSERT_TRUE(Unit::Pascal() != nullptr);
  ASSERT_TRUE(Unit::Joule() != nullptr);
  ASSERT_TRUE(Unit::Watt() != nullptr);
  ASSERT_TRUE(Unit::Coulomb() != nullptr);
  ASSERT_TRUE(Unit::Volt() != nullptr);
  ASSERT_TRUE(Unit::Farad() != nullptr);
  ASSERT_TRUE(Unit::Ohm() != nullptr);
  ASSERT_TRUE(Unit::Siemens() != nullptr);
  ASSERT_TRUE(Unit::Weber() != nullptr);
  ASSERT_TRUE(Unit::Tesla() != nullptr);
  ASSERT_TRUE(Unit::Henry() != nullptr);
  ASSERT_TRUE(Unit::Minute() != nullptr);
  ASSERT_TRUE(Unit::Hour() != nullptr);
  ASSERT_TRUE(Unit::ElectronVolt() != nullptr);
  ASSERT_TRUE(Unit::Celsius() != nullptr);
  ASSERT_TRUE(Unit::Fahrenheit() != nullptr);
  ASSERT_TRUE(Unit::Dimensionless() != nullptr);
  ASSERT_TRUE(Unit::Percent() != nullptr);
  ASSERT_TRUE(Unit::Radian() != nullptr);
}

TEST_F(UnitTest, PowerOperations) {
  SymbolUnitSP m = SymbolUnit::Meter();

  SymbolUnitSP area = *m ^ 2;
  ASSERT_EQ(area->unit()->dimensions().at("LENGTH"), 2);
  ASSERT_TRUE(area->symbol().find("m^2") != std::string::npos);

  SymbolUnitSP volume = *m ^ 3;
  ASSERT_EQ(volume->unit()->dimensions().at("LENGTH"), 3);
  ASSERT_TRUE(volume->symbol().find("m^3") != std::string::npos);
}
TEST(TestUnit, BaseSymbolUnit) {
  UnitSP          meter = Unit::Meter();
  TotalDimensions mdims = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(meter->dimensions(), mdims);
  ASSERT_DOUBLE_EQ(meter->scale_factor(), 1.0);

  UnitSP          kilogram = Unit::Kilogram();
  TotalDimensions k_dims   = {{SI::DIMENSION_MASS, 1}};
  ASSERT_EQ(kilogram->dimensions(), k_dims);

  UnitSP          ampere = Unit::Ampere();
  TotalDimensions a_dims = {{SI::DIMENSION_CURRENT, 1}};
  ASSERT_EQ(ampere->dimensions(), a_dims);

  UnitSP          second = Unit::Second();
  TotalDimensions s_dims = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(second->dimensions(), s_dims);
}

TEST(TestUnit, DerivedSymbolUnit) {
  UnitSP          volt               = Unit::Volt();
  TotalDimensions expected_volt_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -3},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(volt->dimensions(), expected_volt_dims);

  UnitSP          newton               = Unit::Newton();
  TotalDimensions expected_newton_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 1},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(newton->dimensions(), expected_newton_dims);

  UnitSP          hertz               = Unit::Hertz();
  TotalDimensions expected_hertz_dims = {
      {SI::DIMENSION_TIME, -1},
  };
  ASSERT_EQ(hertz->dimensions(), expected_hertz_dims);

  UnitSP          tesla               = Unit::Tesla();
  TotalDimensions expected_tesla_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_TIME, -2},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(tesla->dimensions(), expected_tesla_dims);
}

TEST(TestUnit, ConsistencyWithDefinitionJoule) {
  // Joule = Newton * Meter
  UnitSP joule        = Unit::Joule();
  UnitSP newton_meter = *Unit::Newton() * Unit::Meter();
  ASSERT_EQ(joule->dimensions(), newton_meter->dimensions());
}

TEST(TestUnit, ConsistencyWithDefinitionWatt) {
  // Watt = Joule / Second
  UnitSP watt             = Unit::Watt();
  UnitSP joule_per_second = *Unit::Joule() / Unit::Second();
  ASSERT_EQ(watt->dimensions(), joule_per_second->dimensions());
}

TEST(TestUnit, ConsistencyWithDefinitionVolt) {
  // Volt = Watt / Ampere
  UnitSP volt            = Unit::Volt();
  UnitSP watt_per_ampere = *Unit::Watt() / (Unit::Ampere());
  ASSERT_EQ(volt->dimensions(), watt_per_ampere->dimensions());
}

TEST(TestUnit, ConsistencyWithDefinitionOhm) {
  // Ohm = Volt / Ampere
  UnitSP ohm             = Unit::Ohm();
  UnitSP volt_per_ampere = *Unit::Volt() / (Unit::Ampere());
  ASSERT_EQ(ohm->dimensions(), volt_per_ampere->dimensions());
}

// Non-SI units
TEST(TestUnit, NonSISymbolUnit) {
  // Minute
  UnitSP          minute   = Unit::Minute();
  TotalDimensions time_dim = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(minute->dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(minute->scale_factor(), 60.0);

  // Hour
  UnitSP hour = Unit::Hour();
  ASSERT_EQ(hour->dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(hour->scale_factor(), 3600.0);

  // Electron volt
  UnitSP          ev      = Unit::ElectronVolt();
  TotalDimensions ev_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(ev->dimensions(), ev_dims);
  ASSERT_NEAR(ev->scale_factor(), 1.602176634e-19, 1e-25);
}

// Temperature units
TEST(TestUnit, TemperatureSymbolUnit) {
  // Kelvin (base unit)
  UnitSP          kelvin   = Unit::Kelvin();
  TotalDimensions temp_dim = {{SI::DIMENSION_TEMPERATURE, 1}};
  ASSERT_EQ(kelvin->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(kelvin->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(kelvin->offset(), 0.0);

  // Celsius
  UnitSP celsius = Unit::Celsius();
  ASSERT_EQ(celsius->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(celsius->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(celsius->offset(), 273.15);

  // Fahrenheit
  UnitSP fahrenheit = Unit::Fahrenheit();
  ASSERT_EQ(fahrenheit->dimensions(), temp_dim);
  ASSERT_NEAR(fahrenheit->scale_factor(), 5.0 / 9.0, 1e-10);
  ASSERT_NEAR(fahrenheit->offset(), 459.67, 1e-10);

  // Temperature conversion validation
  // 0°C = 273.15K
  ASSERT_NEAR(celsius->convert_value_to(0.0, kelvin), 273.15, 1e-10);
  // 0K = -273.15°C
  ASSERT_NEAR(kelvin->convert_value_to(0.0, celsius), -273.15, 1e-10);
  // 32°F = 0°C
  ASSERT_NEAR(fahrenheit->convert_value_to(32.0, celsius), 0.0, 1e-10);
}

// Dimensionless units
TEST(TestUnit, DimensionlessSymbolUnit) {
  UnitSP          dimensionless = Unit::Dimensionless();
  TotalDimensions empty_dims;
  ASSERT_EQ(dimensionless->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(dimensionless->scale_factor(), 1.0);

  UnitSP percent = Unit::Percent();
  ASSERT_EQ(percent->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(percent->scale_factor(), 0.01);

  // 100% = 1.0 dimensionless
  ASSERT_DOUBLE_EQ(percent->convert_value_to(100.0, dimensionless), 1.0);
}

// Get unit with prefix
TEST(TestUnit, GetUnitWithPrefix) {
  // General prefix method
  UnitSP          millimeter = Unit::Meter()->get_milli();
  TotalDimensions len_dim    = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(millimeter->dimensions(), len_dim);
  ASSERT_DOUBLE_EQ(millimeter->scale_factor(), 0.001);

  // Specific prefix methods
  UnitSP km = Unit::Meter()->get_kilo();
  ASSERT_DOUBLE_EQ(km->scale_factor(), 1000.0);

  UnitSP uA = Unit::Ampere()->get_micro();
  ASSERT_DOUBLE_EQ(uA->scale_factor(), 1e-6);

  UnitSP mV = Unit::Volt()->get_milli();
  ASSERT_DOUBLE_EQ(mV->scale_factor(), 0.001);

  UnitSP MW = Unit::Watt()->get_mega();
  ASSERT_DOUBLE_EQ(MW->scale_factor(), 1e6);
}

// Conversion between prefixed units
TEST(TestUnit, ConversionBetweenPrefixedSymbolUnit) {
  // 1 km to m
  UnitSP km           = Unit::Meter()->get_kilo();
  double meters_in_km = km->convert_value_to(1.0, Unit::Meter());
  ASSERT_DOUBLE_EQ(meters_in_km, 1000.0);

  // 1000 mV to V
  UnitSP mV          = Unit::Volt()->get_milli();
  double volts_in_mV = mV->convert_value_to(1000.0, Unit::Volt());
  ASSERT_DOUBLE_EQ(volts_in_mV, 1.0);

  // 1 MW to kW
  UnitSP MW       = Unit::Watt()->get_mega();
  UnitSP kW       = Unit::Watt()->get_kilo();
  double kW_in_MW = MW->convert_value_to(1.0, kW);
  ASSERT_DOUBLE_EQ(kW_in_MW, 1000.0);
}
}  // namespace tests
