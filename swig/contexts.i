%{
#include "falcon_core/AcquisitionContext.hpp"
#include "falcon_core/MeasurementContext.hpp"
#include "falcon_core/InterpretationContext.hpp"
#include "falcon_core/InterpretationContainer.hpp"
%}

%shared_ptr(falcon_core::MeasurementContext);
%shared_ptr(falcon_core::AcquisitionContext);
%shared_ptr(falcon_core::InterpretationContext);
%shared_ptr(falcon_core::InterpretationContainer<falcon_core::ControlArray<double>>);
%include "falcon_core/AcquisitionContext.hpp"
%include "falcon_core/MeasurementContext.hpp"
%include "falcon_core/InterpretationContext.hpp"
%include "falcon_core/InterpretationContainer.hpp"

// Instantiate InterpretationContainer for ControlArray<double>
%template(InterpretationContainerControlArray) falcon_core::InterpretationContainer<falcon_core::ControlArray<double>>;
