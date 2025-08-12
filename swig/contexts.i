%{
#include "falcon_core/AcquisitionContext.hpp"
#include "falcon_core/InterpretationContext.hpp"
#include "falcon_core/InterpretationContainer.hpp"
%}

%include "falcon_core/AcquisitionContext.hpp"
%include "falcon_core/InterpretationContext.hpp"
%include "falcon_core/InterpretationContainer.hpp"

%shared_ptr(falcon_core::InterpretationContext)

// Instantiate InterpretationContainer for ControlArray<double>
%template(InterpretationContainerControlArray) falcon_core::InterpretationContainer<falcon_core::ControlArray<double>>;
