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
#include "falcon_core/BaseLabelledArray.hpp"
#include "falcon_core/LabelledControlArray1D.hpp"
#include "falcon_core/BaseLabelledArrays.hpp"
#include "falcon_core/IncreasingAlignment.hpp"
#include "falcon_core/ControlArray1D.hpp"
%}

%shared_ptr(falcon_core::Domain);
%shared_ptr(falcon_core::IncreasingAlignment);
%shared_ptr(falcon_core::BaseArray<double>);
%shared_ptr(falcon_core::ControlArray<double>);
%shared_ptr(falcon_core::MeasuredArray<double>);
%shared_ptr(falcon_core::ControlArray1D);
%shared_ptr(falcon_core::LabelledControlArray1D);
%shared_ptr(falcon_core::BaseLabelledArray<falcon_core::ControlArray1D, falcon_core::InstrumentPort<falcon_core::Gate>>);


%include "falcon_core/Domain.hpp"
%include "falcon_core/Quantity.hpp"
%include "falcon_core/OneToOneMapping.hpp"
%include "falcon_core/BaseArray.hpp"
%include "falcon_core/ControlArray.hpp"
%include "falcon_core/MeasuredArray.hpp"
%include "falcon_core/Axes.hpp"
%include "falcon_core/LabelledDomain.hpp"
%include "falcon_core/CoupledLabelledDomain.hpp"
%include "falcon_core/BaseLabelledArray.hpp"
%include "falcon_core/LabelledControlArray1D.hpp"
%nodefaultctor falcon_core::LabelledControlArray1D;
%include "falcon_core/BaseLabelledArrays.hpp"
%include "falcon_core/IncreasingAlignment.hpp"
%include "falcon_core/ControlArray1D.hpp"

// Expose concrete instantiations of template classes
%shared_ptr(falcon_core::Quantity<double>);
%template(QuantityDouble) falcon_core::Quantity<double>;
%shared_ptr(falcon_core::BaseArray<double>);
%template(BaseArrayDouble) falcon_core::BaseArray<double>;
%shared_ptr(falcon_core::ControlArray<double>);
%template(ControlArrayDouble) falcon_core::ControlArray<double>;
%shared_ptr(falcon_core::MeasuredArray<double>);
%template(MeasuredArrayDouble) falcon_core::MeasuredArray<double>;

// Instantiate Axes for Domain as a placeholder until MeasurementContext is available
%include "std_vector.i"
%include "std_shared_ptr.i"
%shared_ptr(falcon_core::Axes<falcon_core::Domain>);
%template(AxesDomain) falcon_core::Axes<falcon_core::Domain>;
%shared_ptr(falcon_core::Axes<falcon_core::MeasurementContext>);
%template(AxesMeasurementContext) falcon_core::Axes<falcon_core::MeasurementContext>;

// Instantiate Domain subclasses
%shared_ptr(falcon_core::LabelledDomain<falcon_core::BaseConnection>);
%template(LabelledDomainBC) falcon_core::LabelledDomain<falcon_core::BaseConnection>;
%shared_ptr(falcon_core::CoupledLabelledDomain<falcon_core::BaseConnection>);
%template(CoupledLabelledDomainBC) falcon_core::CoupledLabelledDomain<falcon_core::BaseConnection>;

// Instantiate Labelled Array classes
%shared_ptr(falcon_core::BaseLabelledArrays<falcon_core::LabelledControlArray1D>);
%template(BaseLabelledArraysLCA1D) falcon_core::BaseLabelledArrays<falcon_core::LabelledControlArray1D>;

// Add other instantiations as needed, e.g., for int or complex types.

// A full implementation would require typemaps for K,V to be useful in Python.
// This is a basic starting point.
%shared_ptr(falcon_core::OneToOneMapping);
%template(OneToOneMappingStringString) falcon_core::OneToOneMapping<std::string, std::string>;
