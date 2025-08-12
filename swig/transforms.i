%{
#include "falcon_core/AnalyticFunction.hpp"
#include "falcon_core/PortTransform.hpp"
#include "falcon_core/PortTransforms.hpp"
%}

%include "falcon_core/AnalyticFunction.hpp"
%include "falcon_core/PortTransform.hpp"
%include "falcon_core/PortTransforms.hpp"

// Enable directors to allow subclassing in Python
%feature("director") falcon_core::AnalyticFunction;
%feature("director") falcon_core::PortTransform;

%shared_ptr(falcon_core::AnalyticFunction)
%shared_ptr(falcon_core::PortTransform)
%shared_ptr(falcon_core::PortTransforms)
