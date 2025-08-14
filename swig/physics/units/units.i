%{
#include "falcon_core/physics/units/Unit.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/Units.hpp"
#include "falcon_core/physics/units/Dimension.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"
%}

%shared_ptr(falcon_core::physics::units::Unit);
%shared_ptr(falcon_core::physics::units::Units);
%shared_ptr(falcon_core::physics::units::CommonUnits);
%shared_ptr(falcon_core::physics::units::Dimension);
%shared_ptr(falcon_core::physics::units::Prefix);
%shared_ptr(falcon_core::physics::units::SymbolUnit);
%shared_ptr(falcon_core::physics::units::TotalDimensions);

// The %include directive is sufficient for SWIG to parse and generate
// wrappers for all classes, enums, and other constructs in these headers.

%include "falcon_core/physics/units/Unit.hpp"
%include "falcon_core/physics/units/CommonUnits.hpp"
%include "falcon_core/physics/units/Units.hpp"
%include "falcon_core/physics/units/Dimension.hpp"
%include "falcon_core/physics/units/Prefix.hpp"
%include "falcon_core/physics/units/SymbolUnit.hpp"
%include "falcon_core/physics/units/TotalDimensions.hpp"

