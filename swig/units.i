%{
#include "falcon_core/Dimension.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
#include "falcon_core/Sign.hpp"
#include "falcon_core/physics/units/Unit.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include "falcon_core/Units.hpp"
%}

%shared_ptr(falcon_core::Unit);
%shared_ptr(falcon_core::SymbolUnit);
%shared_ptr(falcon_core::Dimension);
%shared_ptr(falcon_core::Prefix);
// The %include directive is sufficient for SWIG to parse and generate
// wrappers for all classes, enums, and other constructs in these headers.
%include "falcon_core/Sign.hpp"
%include "falcon_core/Dimension.hpp"
%include "falcon_core/physics/units/Prefix.hpp"
%include "falcon_core/physics/units/Unit.hpp"
%include "falcon_core/SymbolUnit.hpp"
%include "falcon_core/Units.hpp"


