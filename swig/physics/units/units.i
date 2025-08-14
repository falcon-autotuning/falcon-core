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


