/*
%{
#include "falcon_core/AnalyticFunction.hpp"
#include "falcon_core/PortTransform.hpp"
#include "falcon_core/PortTransforms.hpp"
#include "falcon_core/ConstantFunction.hpp"
#include "falcon_core/Identity.hpp"
#include "falcon_core/IdentityTransform.hpp"
%}

%shared_ptr(falcon_core::AnalyticFunction);
%shared_ptr(falcon_core::PortTransform);
%shared_ptr(falcon_core::PortTransforms);
%shared_ptr(falcon_core::ConstantFunction);
%shared_ptr(falcon_core::Identity);
%shared_ptr(falcon_core::IdentityTransform);

%include "falcon_core/AnalyticFunction.hpp"
%include "falcon_core/PortTransform.hpp"
%include "falcon_core/PortTransforms.hpp"
%include "falcon_core/ConstantFunction.hpp"
%include "falcon_core/Identity.hpp"
%include "falcon_core/IdentityTransform.hpp"

// Enable directors to allow subclassing in Python
%feature("director") falcon_core::AnalyticFunction;
%feature("director") falcon_core::PortTransform;
*/
