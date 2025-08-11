%{
#include "falcon_core/Dimension.hpp"
#include "falcon_core/Prefix.hpp"
#include "falcon_core/Sign.hpp"
#include "falcon_core/Unit.hpp"
#include "falcon_core/SymbolUnit.hpp"
#include <memory>
%}

// std library support
%include "std_string.i"
%include "std_map.i"
%include "std_shared_ptr.i"

// Expose std::map<BaseDimension, int> to python
%template(DimensionMap) std::map<falcon_core::BaseDimension, int>;

// std::shared_ptr support for Unit and SymbolUnit
%shared_ptr(falcon_core::Unit);
%shared_ptr(falcon_core::SymbolUnit);

// Expose the enums
%include "falcon_core/Sign.hpp"
enum falcon_core::Sign;
%include "falcon_core/Dimension.hpp"
enum falcon_core::BaseDimension;


// Process the class headers
%include "falcon_core/Dimension.hpp"
%include "falcon_core/Prefix.hpp"
%include "falcon_core/Unit.hpp"
%include "falcon_core/SymbolUnit.hpp"

// Add python-like special methods for Unit
%extend falcon_core::Unit {
    std::shared_ptr<falcon_core::Unit> __mul__(const falcon_core::Unit& other) {
        return self->operator*(other);
    }
    std::shared_ptr<falcon_core::Unit> __truediv__(const falcon_core::Unit& other) {
        return self->operator/(other);
    }
}
