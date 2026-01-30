#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp"

#include "falcon_core/math/Quantity.hpp"

// -----------------------------------------------------------------------------
// Explicit template instantiations
//
// These force the falcon_core library to emit the concrete
// InterpretationContainer<T> symbols. Consumers (tests) should compile with
// FALCON_CORE_USE_EXTERN_TEMPLATES defined so they do not instantiate the same
// templates again (avoids duplicate-link).
// -----------------------------------------------------------------------------

template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<double>;
template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<std::string>;
template class FALCON_CORE_CPP_API falcon_core::autotuner_interfaces::
    interpretations::InterpretationContainer<falcon_core::math::Quantity>;
