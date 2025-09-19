%{
#include "falcon_core/physics/units/TotalDimensions.hpp"
#include "falcon_core/physics/units/Unit.hpp"
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


%include "falcon_core/physics/units/TotalDimensions.hpp"
%include "falcon_core/physics/units/Unit.hpp"
%include "falcon_core/physics/units/Prefix.hpp"
%include "falcon_core/physics/units/SymbolUnit.hpp"

%add_song_deserializers(falcon_core::physics::units::Unit);
%add_song_deserializers(falcon_core::physics::units::SymbolUnit);


