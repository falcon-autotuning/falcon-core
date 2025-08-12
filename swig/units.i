%{
#include "falcon_core/Dimension.hpp"
#include "falcon_core/Prefix.hpp"
#include "falcon_core/Sign.hpp"
#include "falcon_core/Unit.hpp"
#include "falcon_core/SymbolUnit.hpp"
%}



// The %include directive is sufficient for SWIG to parse and generate
// wrappers for all classes, enums, and other constructs in these headers.
%include "falcon_core/Sign.hpp"
%include "falcon_core/Dimension.hpp"
%include "falcon_core/Prefix.hpp"
%include "falcon_core/Unit.hpp"
%include "falcon_core/SymbolUnit.hpp"


