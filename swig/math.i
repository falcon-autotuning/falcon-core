%{
#include "falcon_core/Domain.hpp"
#include "falcon_core/Quantity.hpp"
#include "falcon_core/OneToOneMapping.hpp"
#include "falcon_core/BaseArray.hpp"
#include "falcon_core/ControlArray.hpp"
#include "falcon_core/MeasuredArray.hpp"
%}

%include "falcon_core/Domain.hpp"
%include "falcon_core/Quantity.hpp"
%include "falcon_core/OneToOneMapping.hpp"
%include "falcon_core/BaseArray.hpp"
%include "falcon_core/ControlArray.hpp"
%include "falcon_core/MeasuredArray.hpp"

// Expose concrete instantiations of template classes
%template(QuantityDouble) falcon_core::Quantity<double>;
%template(BaseArrayDouble) falcon_core::BaseArray<double>;
%template(ControlArrayDouble) falcon_core::ControlArray<double>;
%template(MeasuredArrayDouble) falcon_core::MeasuredArray<double>;
// Add other instantiations as needed, e.g., for int or complex types.

// A full implementation would require typemaps for K,V to be useful in Python.
// This is a basic starting point.
%template(OneToOneMappingStringString) falcon_core::OneToOneMapping<std::string, std::string>;
