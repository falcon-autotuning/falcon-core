#include "falcon_core/math/arrays/ControlArray.hpp"
#include <cereal/types/polymorphic.hpp>
#include "falcon_core/math/arrays/BaseArray.hpp"

// Register for float and double
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::arrays::BaseArray<float>, falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::arrays::BaseArray<double>, falcon_core::math::arrays::ControlArray<double>)
