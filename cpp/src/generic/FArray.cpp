
#include "falcon_core/generic/FArray.hpp"

CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<int>);
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<float>);
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<double>);
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<size_t>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<int>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<double>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<float>);
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<size_t>);
extern "C" FALCON_CORE_CPP_API void cereal_register_farray() {}

// -----------------------------------------------------------------------------
// Explicit template instantiations
//
// These force the falcon_core library to emit the concrete List<T> symbols.
// Consumers (tests) should compile with FALCON_CORE_USE_EXTERN_TEMPLATES
// defined so they do not instantiate the same templates again (avoids
// duplicate-link).
// -----------------------------------------------------------------------------

template class FALCON_CORE_CPP_API falcon_core::generic::FArray<int>;
template class FALCON_CORE_CPP_API falcon_core::generic::FArray<float>;
template class FALCON_CORE_CPP_API falcon_core::generic::FArray<double>;
template class FALCON_CORE_CPP_API falcon_core::generic::FArray<size_t>;
