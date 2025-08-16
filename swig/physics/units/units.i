%{
#include "falcon_core/physics/units/TotalDimensions.hpp"
#include "falcon_core/physics/units/Unit.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Units.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/generic/Song.hpp"

using namespace falcon_core::physics::units;
%}

%shared_ptr(falcon_core::physics::units::TotalDimensions);
%shared_ptr(falcon_core::physics::units::Unit);
%shared_ptr(falcon_core::physics::units::Units);
%shared_ptr(falcon_core::physics::units::CommonUnits);
%shared_ptr(falcon_core::physics::units::Prefix);
%shared_ptr(falcon_core::physics::units::SymbolUnit);
%include "std_string.i"
%include "std_map.i"
%template(SymbolToPowerMap) std::map<std::string, int>;
%template(PowerToSymbolMap) std::map<int, std::string>;

%rename(symbol_to_power, pyname="physics.units.symbol_to_power")
    falcon_core::physics::units::Prefix::get_symbol_to_power_map();
%rename(power_to_symbol, pyname="physics.units.power_to_symbol")
    falcon_core::physics::units::Prefix::get_power_to_symbol_map();

// Rename classes and place them in the physics.units submodule
%rename(pyname="physics.units.Unit") falcon_core::physics::units::Unit;
%rename(pyname="physics.units.SymbolUnit") falcon_core::physics::units::SymbolUnit;
%rename(pyname="physics.units.Prefix") falcon_core::physics::units::Prefix;

// Rename constants from Units.hpp and place them in the physics.units submodule
%rename(pyname="physics.units.Meter") falcon_core::physics::units::Meter();
%rename(pyname="physics.units.Kilogram") falcon_core::physics::units::Kilogram();
%rename(pyname="physics.units.Second") falcon_core::physics::units::Second();
%rename(pyname="physics.units.Ampere") falcon_core::physics::units::Ampere();
%rename(pyname="physics.units.Kelvin") falcon_core::physics::units::Kelvin();
%rename(pyname="physics.units.Mole") falcon_core::physics::units::Mole();
%rename(pyname="physics.units.Candela") falcon_core::physics::units::Candela();
%rename(pyname="physics.units.Hertz") falcon_core::physics::units::Hertz();
%rename(pyname="physics.units.Newton") falcon_core::physics::units::Newton();
%rename(pyname="physics.units.Pascal") falcon_core::physics::units::Pascal();
%rename(pyname="physics.units.Joule") falcon_core::physics::units::Joule();
%rename(pyname="physics.units.Watt") falcon_core::physics::units::Watt();
%rename(pyname="physics.units.Coulomb") falcon_core::physics::units::Coulomb();
%rename(pyname="physics.units.Volt") falcon_core::physics::units::Volt();
%rename(pyname="physics.units.Farad") falcon_core::physics::units::Farad();
%rename(pyname="physics.units.Ohm") falcon_core::physics::units::Ohm();
%rename(pyname="physics.units.Siemens") falcon_core::physics::units::Siemens();
%rename(pyname="physics.units.Weber") falcon_core::physics::units::Weber();
%rename(pyname="physics.units.Tesla") falcon_core::physics::units::Tesla();
%rename(pyname="physics.units.Henry") falcon_core::physics::units::Henry();
%rename(pyname="physics.units.Minute") falcon_core::physics::units::Minute();
%rename(pyname="physics.units.Hour") falcon_core::physics::units::Hour();
%rename(pyname="physics.units.ElectronVolt") falcon_core::physics::units::ElectronVolt();
%rename(pyname="physics.units.Celsius") falcon_core::physics::units::Celsius();
%rename(pyname="physics.units.Fahrenheit") falcon_core::physics::units::Fahrenheit();
%rename(pyname="physics.units.Dimensionless") falcon_core::physics::units::Dimensionless();
%rename(pyname="physics.units.Percent") falcon_core::physics::units::Percent();
%rename(pyname="physics.units.Radian") falcon_core::physics::units::Radian();
%rename(pyname="physics.units.MilliMeter") falcon_core::physics::units::MilliMeter();
%rename(pyname="physics.units.KiloMeter") falcon_core::physics::units::KiloMeter();
%rename(pyname="physics.units.MilliVolt") falcon_core::physics::units::MilliVolt();
%rename(pyname="physics.units.KiloVolt") falcon_core::physics::units::KiloVolt();
%rename(pyname="physics.units.MilliAmpere") falcon_core::physics::units::MilliAmpere();
%rename(pyname="physics.units.MicroAmpere") falcon_core::physics::units::MicroAmpere();
%rename(pyname="physics.units.NanoAmpere") falcon_core::physics::units::NanoAmpere();
%rename(pyname="physics.units.PicoAmpere") falcon_core::physics::units::PicoAmpere();
%rename(pyname="physics.units.MilliSecond") falcon_core::physics::units::MilliSecond();
%rename(pyname="physics.units.MicroSecond") falcon_core::physics::units::MicroSecond();
%rename(pyname="physics.units.NanoSecond") falcon_core::physics::units::NanoSecond();
%rename(pyname="physics.units.PicoSecond") falcon_core::physics::units::PicoSecond();
%rename(pyname="physics.units.MilliOhm") falcon_core::physics::units::MilliOhm();
%rename(pyname="physics.units.KiloOhm") falcon_core::physics::units::KiloOhm();
%rename(pyname="physics.units.MegaOhm") falcon_core::physics::units::MegaOhm();
%rename(pyname="physics.units.MilliHertz") falcon_core::physics::units::MilliHertz();
%rename(pyname="physics.units.KiloHertz") falcon_core::physics::units::KiloHertz();
%rename(pyname="physics.units.MegaHertz") falcon_core::physics::units::MegaHertz();
%rename(pyname="physics.units.GigaHertz") falcon_core::physics::units::GigaHertz();
%rename(pyname="physics.units.MetersPerSecond") falcon_core::physics::units::MetersPerSecond();
%rename(pyname="physics.units.MetersPerSecondSquared") falcon_core::physics::units::MetersPerSecondSquared();
%rename(pyname="physics.units.NewtonMeter") falcon_core::physics::units::NewtonMeter();
%rename(pyname="physics.units.NewtonPerMeter") falcon_core::physics::units::NewtonPerMeter();
%rename(pyname="physics.units.VoltsPerMeter") falcon_core::physics::units::VoltsPerMeter();
%rename(pyname="physics.units.VoltsPerSecond") falcon_core::physics::units::VoltsPerSecond();
%rename(pyname="physics.units.AmperesPerMeter") falcon_core::physics::units::AmperesPerMeter();
%rename(pyname="physics.units.VoltsPerAmpere") falcon_core::physics::units::VoltsPerAmpere();
%rename(pyname="physics.units.WattsPerMeterKelvin") falcon_core::physics::units::WattsPerMeterKelvin();

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

%add_song_deserializers(falcon_core::physics::units::Unit);
%add_song_deserializers(falcon_core::physics::units::SymbolUnit);


