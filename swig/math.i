%{
#include "falcon_core/Domain.hpp"
#include "falcon_core/Quantity.hpp"
#include "falcon_core/OneToOneMapping.hpp"
#include "falcon_core/BaseArray.hpp"
#include "falcon_core/ControlArray.hpp"
#include "falcon_core/MeasuredArray.hpp"
#include "falcon_core/Axes.hpp"
#include "falcon_core/LabelledDomain.hpp"
#include "falcon_core/CoupledLabelledDomain.hpp"
%}

%include "falcon_core/Domain.hpp"
%include "falcon_core/Quantity.hpp"
%include "falcon_core/OneToOneMapping.hpp"
%include "falcon_core/BaseArray.hpp"
%include "falcon_core/ControlArray.hpp"
%include "falcon_core/MeasuredArray.hpp"
%include "falcon_core/Axes.hpp"
%include "falcon_core/LabelledDomain.hpp"
%include "falcon_core/CoupledLabelledDomain.hpp"

// Expose concrete instantiations of template classes
%template(QuantityDouble) falcon_core::Quantity<double>;
%template(BaseArrayDouble) falcon_core::BaseArray<double>;
%template(ControlArrayDouble) falcon_core::ControlArray<double>;
%template(MeasuredArrayDouble) falcon_core::MeasuredArray<double>;

// Instantiate Axes for Domain as a placeholder until MeasurementContext is available
%include "std_vector.i"
%include "std_shared_ptr.i"
%shared_ptr(falcon_core::Domain)
%template(AxesDomain) falcon_core::Axes<falcon_core::Domain>;
%template(AxesMeasurementContext) falcon_core::Axes<falcon_core::MeasurementContext>;

// Instantiate Domain subclasses
%shared_ptr(falcon_core::BaseConnection)
%template(LabelledDomainBC) falcon_core::LabelledDomain<falcon_core::BaseConnection>;
%shared_ptr(falcon_core::LabelledDomain<falcon_core::BaseConnection>)
%template(CoupledLabelledDomainBC) falcon_core::CoupledLabelledDomain<falcon_core::BaseConnection>;
// Add other instantiations as needed, e.g., for int or complex types.

// A full implementation would require typemaps for K,V to be useful in Python.
// This is a basic starting point.
%template(OneToOneMappingStringString) falcon_core::OneToOneMapping<std::string, std::string>;
