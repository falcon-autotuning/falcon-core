%{
#include "falcon_core/physics/units/TotalDimensions.hpp"
#include "falcon_core/physics/units/Unit.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Units.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
%}

%shared_ptr(falcon_core::physics::units::TotalDimensions);
%shared_ptr(falcon_core::physics::units::Unit);
%shared_ptr(falcon_core::physics::units::Units);
%shared_ptr(falcon_core::physics::units::CommonUnits);
%shared_ptr(falcon_core::physics::units::Prefix);
%shared_ptr(falcon_core::physics::units::SymbolUnit);

%include "std_map.i"
%template(SymbolToPowerMap) std::map<std::string, int>;
%template(PowerToSymbolMap) std::map<int, std::string>;

%rename(symbol_to_power, pyname="physics.units.symbol_to_power")
    falcon_core::physics::units::Prefix::get_symbol_to_power_map;
%rename(power_to_symbol, pyname="physics.units.power_to_symbol")
    falcon_core::physics::units::Prefix::get_power_to_symbol_map;

// Rename classes and place them in the physics.units submodule
%rename(Unit, pyname="physics.units.Unit") falcon_core::physics::units::Unit;
%rename(SymbolUnit, pyname="physics.units.SymbolUnit") falcon_core::physics::units::SymbolUnit;
%rename(Prefix, pyname="physics.units.Prefix") falcon_core::physics::units::Prefix;

// Rename constants from Units.hpp and place them in the physics.units submodule
%rename(Meter, pyname="physics.units.Meter") falcon_core::physics::units::Meter;
%rename(Kilogram, pyname="physics.units.Kilogram") falcon_core::physics::units::Kilogram;
%rename(Second, pyname="physics.units.Second") falcon_core::physics::units::Second;
%rename(Ampere, pyname="physics.units.Ampere") falcon_core::physics::units::Ampere;
%rename(Kelvin, pyname="physics.units.Kelvin") falcon_core::physics::units::Kelvin;
%rename(Mole, pyname="physics.units.Mole") falcon_core::physics::units::Mole;
%rename(Candela, pyname="physics.units.Candela") falcon_core::physics::units::Candela;
%rename(Hertz, pyname="physics.units.Hertz") falcon_core::physics::units::Hertz;
%rename(Newton, pyname="physics.units.Newton") falcon_core::physics::units::Newton;
%rename(Pascal, pyname="physics.units.Pascal") falcon_core::physics::units::Pascal;
%rename(Joule, pyname="physics.units.Joule") falcon_core::physics::units::Joule;
%rename(Watt, pyname="physics.units.Watt") falcon_core::physics::units::Watt;
%rename(Coulomb, pyname="physics.units.Coulomb") falcon_core::physics::units::Coulomb;
%rename(Volt, pyname="physics.units.Volt") falcon_core::physics::units::Volt;
%rename(Farad, pyname="physics.units.Farad") falcon_core::physics::units::Farad;
%rename(Ohm, pyname="physics.units.Ohm") falcon_core::physics::units::Ohm;
%rename(Siemens, pyname="physics.units.Siemens") falcon_core::physics::units::Siemens;
%rename(Weber, pyname="physics.units.Weber") falcon_core::physics::units::Weber;
%rename(Tesla, pyname="physics.units.Tesla") falcon_core::physics::units::Tesla;
%rename(Henry, pyname="physics.units.Henry") falcon_core::physics::units::Henry;
%rename(Minute, pyname="physics.units.Minute") falcon_core::physics::units::Minute;
%rename(Hour, pyname="physics.units.Hour") falcon_core::physics::units::Hour;
%rename(ElectronVolt, pyname="physics.units.ElectronVolt") falcon_core::physics::units::ElectronVolt;
%rename(Celsius, pyname="physics.units.Celsius") falcon_core::physics::units::Celsius;
%rename(Fahrenheit, pyname="physics.units.Fahrenheit") falcon_core::physics::units::Fahrenheit;
%rename(Dimensionless, pyname="physics.units.Dimensionless") falcon_core::physics::units::Dimensionless;
%rename(Percent, pyname="physics.units.Percent") falcon_core::physics::units::Percent;
%rename(Radian, pyname="physics.units.Radian") falcon_core::physics::units::Radian;
%rename(MilliMeter, pyname="physics.units.MilliMeter") falcon_core::physics::units::MilliMeter;
%rename(KiloMeter, pyname="physics.units.KiloMeter") falcon_core::physics::units::KiloMeter;
%rename(MilliVolt, pyname="physics.units.MilliVolt") falcon_core::physics::units::MilliVolt;
%rename(KiloVolt, pyname="physics.units.KiloVolt") falcon_core::physics::units::KiloVolt;
%rename(MilliAmpere, pyname="physics.units.MilliAmpere") falcon_core::physics::units::MilliAmpere;
%rename(MicroAmpere, pyname="physics.units.MicroAmpere") falcon_core::physics::units::MicroAmpere;
%rename(NanoAmpere, pyname="physics.units.NanoAmpere") falcon_core::physics::units::NanoAmpere;
%rename(PicoAmpere, pyname="physics.units.PicoAmpere") falcon_core::physics::units::PicoAmpere;
%rename(MilliSecond, pyname="physics.units.MilliSecond") falcon_core::physics::units::MilliSecond;
%rename(MicroSecond, pyname="physics.units.MicroSecond") falcon_core::physics::units::MicroSecond;
%rename(NanoSecond, pyname="physics.units.NanoSecond") falcon_core::physics::units::NanoSecond;
%rename(PicoSecond, pyname="physics.units.PicoSecond") falcon_core::physics::units::PicoSecond;
%rename(MilliOhm, pyname="physics.units.MilliOhm") falcon_core::physics::units::MilliOhm;
%rename(KiloOhm, pyname="physics.units.KiloOhm") falcon_core::physics::units::KiloOhm;
%rename(MegaOhm, pyname="physics.units.MegaOhm") falcon_core::physics::units::MegaOhm;
%rename(MilliHertz, pyname="physics.units.MilliHertz") falcon_core::physics::units::MilliHertz;
%rename(KiloHertz, pyname="physics.units.KiloHertz") falcon_core::physics::units::KiloHertz;
%rename(MegaHertz, pyname="physics.units.MegaHertz") falcon_core::physics::units::MegaHertz;
%rename(GigaHertz, pyname="physics.units.GigaHertz") falcon_core::physics::units::GigaHertz;
%rename(MetersPerSecond, pyname="physics.units.MetersPerSecond") falcon_core::physics::units::MetersPerSecond;
%rename(MetersPerSecondSquared, pyname="physics.units.MetersPerSecondSquared") falcon_core::physics::units::MetersPerSecondSquared;
%rename(NewtonMeter, pyname="physics.units.NewtonMeter") falcon_core::physics::units::NewtonMeter;
%rename(NewtonPerMeter, pyname="physics.units.NewtonPerMeter") falcon_core::physics::units::NewtonPerMeter;
%rename(VoltsPerMeter, pyname="physics.units.VoltsPerMeter") falcon_core::physics::units::VoltsPerMeter;
%rename(VoltsPerSecond, pyname="physics.units.VoltsPerSecond") falcon_core::physics::units::VoltsPerSecond;
%rename(AmperesPerMeter, pyname="physics.units.AmperesPerMeter") falcon_core::physics::units::AmperesPerMeter;
%rename(VoltsPerAmpere, pyname="physics.units.VoltsPerAmpere") falcon_core::physics::units::VoltsPerAmpere;
%rename(WattsPerMeterKelvin, pyname="physics.units.WattsPerMeterKelvin") falcon_core::physics::units::WattsPerMeterKelvin;

// The %include directive is sufficient for SWIG to parse and generate
// wrappers for all classes, enums, and other constructs in these headers.


%ignore falcon_core::physics::units::common_units::Meter;
%ignore falcon_core::physics::units::common_units::Kilogram;
%ignore falcon_core::physics::units::common_units::Second;
%ignore falcon_core::physics::units::common_units::Ampere;
%ignore falcon_core::physics::units::common_units::Kelvin;
%ignore falcon_core::physics::units::common_units::Mole;
%ignore falcon_core::physics::units::common_units::Candela;
%ignore falcon_core::physics::units::common_units::Hertz;
%ignore falcon_core::physics::units::common_units::Newton;
%ignore falcon_core::physics::units::common_units::Pascal;
%ignore falcon_core::physics::units::common_units::Joule;
%ignore falcon_core::physics::units::common_units::Watt;
%ignore falcon_core::physics::units::common_units::Coulomb;
%ignore falcon_core::physics::units::common_units::Volt;
%ignore falcon_core::physics::units::common_units::Farad;
%ignore falcon_core::physics::units::common_units::Ohm;
%ignore falcon_core::physics::units::common_units::Siemens;
%ignore falcon_core::physics::units::common_units::Weber;
%ignore falcon_core::physics::units::common_units::Tesla;
%ignore falcon_core::physics::units::common_units::Henry;
%ignore falcon_core::physics::units::common_units::Minute;
%ignore falcon_core::physics::units::common_units::Hour;
%ignore falcon_core::physics::units::common_units::ElectronVolt;
%ignore falcon_core::physics::units::common_units::Celsius;
%ignore falcon_core::physics::units::common_units::Fahrenheit;
%ignore falcon_core::physics::units::common_units::Dimensionless;
%ignore falcon_core::physics::units::common_units::Percent;
%ignore falcon_core::physics::units::common_units::Radian;

%include "falcon_core/physics/units/TotalDimensions.hpp"
%include "falcon_core/physics/units/Unit.hpp"
%include "falcon_core/physics/units/CommonUnits.hpp"
%include "falcon_core/physics/units/Units.hpp"
%include "falcon_core/physics/units/Prefix.hpp"
%include "falcon_core/physics/units/SymbolUnit.hpp"


