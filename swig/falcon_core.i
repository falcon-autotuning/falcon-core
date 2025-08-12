%module(directors="1") falcon_core

%pythoncode %{
import sys
import importlib.util

# This code runs when the falcon_core module is imported.
# It creates the desired submodule structure in memory.
_pkg_name = __name__

# Create falcon_core.generic
_generic_spec = importlib.util.spec_from_loader(f'{_pkg_name}.generic', loader=None)
generic = importlib.util.module_from_spec(_generic_spec)
sys.modules[generic.__name__] = generic
setattr(sys.modules[_pkg_name], 'generic', generic)

# Create falcon_core.communications
_comm_spec = importlib.util.spec_from_loader(f'{_pkg_name}.communications', loader=None)
communications = importlib.util.module_from_spec(_comm_spec)
sys.modules[communications.__name__] = communications
setattr(sys.modules[_pkg_name], 'communications', communications)

# Create falcon_core.physics
_physics_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics', loader=None)
physics = importlib.util.module_from_spec(_physics_spec)
sys.modules[physics.__name__] = physics
setattr(sys.modules[_pkg_name], 'physics', physics)

# Create falcon_core.physics.units
_units_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.units', loader=None)
physics.units = importlib.util.module_from_spec(_units_spec)
sys.modules[physics.units.__name__] = physics.units

# Create falcon_core.math
_math_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math', loader=None)
math = importlib.util.module_from_spec(_math_spec)
sys.modules[math.__name__] = math
setattr(sys.modules[_pkg_name], 'math', math)

# Create falcon_core.math.domains
_domains_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.domains', loader=None)
math.domains = importlib.util.module_from_spec(_domains_spec)
sys.modules[math.domains.__name__] = math.domains

# Create falcon_core.math.arrays
_arrays_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.arrays', loader=None)
math.arrays = importlib.util.module_from_spec(_arrays_spec)
sys.modules[math.arrays.__name__] = math.arrays
%}

%{
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Time.hpp"
#include <string>
#include <cstddef>
#include <stdexcept>
// C++ headers for units are included via units.i
%}

// Process the header files
%include "falcon_core/Jsonable.hpp"
%include "falcon_core/Time.hpp"

// Include the units definitions
%include "units.i"

// Include the math definitions
%include "math.i"

// Typemap for nlohmann::json to a Python string.
// The user code in python will be responsible for json.loads()
%typemap(out) nlohmann::json {
  $result = PyUnicode_FromString($1.dump().c_str());
}

// Enable directors for Jsonable to allow subclassing in Python
%feature("director") falcon_core::Jsonable;

// Add python-like special methods to Jsonable
%extend falcon_core::Jsonable {
    std::string __str__() {
        return self->to_json_string();
    }
    size_t __hash__() {
        return self->hash();
    }
}

%pythoncode %{
# Move the wrapped C++ classes into their respective submodules
generic.Jsonable = Jsonable
del Jsonable

communications.Time = Time
del Time

physics.units.Dimension = Dimension
del Dimension
physics.units.Prefix = Prefix
del Prefix
physics.units.Sign = Sign
del Sign
physics.units.SymbolUnit = SymbolUnit
del SymbolUnit
physics.units.Unit = Unit
del Unit

# Move math classes
math.QuantityDouble = QuantityDouble
del QuantityDouble
generic.OneToOneMappingStringString = OneToOneMappingStringString # Mapped to generic for now
del OneToOneMappingStringString
math.domains.Domain = Domain
del Domain

# Move array classes
math.arrays.BaseArray = BaseArrayDouble
del BaseArrayDouble
math.arrays.ControlArray = ControlArrayDouble
del ControlArrayDouble
math.arrays.MeasuredArray = MeasuredArrayDouble
del MeasuredArrayDouble
%}
