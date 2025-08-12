%{
#include "falcon_core/Domain.hpp"
#include "falcon_core/Quantity.hpp"
#include "falcon_core/OneToOneMapping.hpp"
%}

%include "falcon_core/Domain.hpp"
%include "falcon_core/Quantity.hpp"
%include "falcon_core/OneToOneMapping.hpp"

// Expose concrete instantiations of template classes
%template(QuantityDouble) falcon_core::Quantity<double>;
// Add other instantiations as needed, e.g., for int or complex types.

// A full implementation would require typemaps for K,V to be useful in Python.
// This is a basic starting point.
%template(OneToOneMappingStringString) falcon_core::OneToOneMapping<std::string, std::string>;
