#include "falcon_core/math/arrays/LabelledArrays.hpp"

#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledMeasuredArray1D>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledArrays<
                     falcon_core::math::arrays::LabelledControlArray1D>)

CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledMeasuredArray>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledMeasuredArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledControlArray>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledMeasuredArray1D>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledMeasuredArray1D>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::math::arrays::LabelledControlArray1D>,
    falcon_core::math::arrays::LabelledArrays<
        falcon_core::math::arrays::LabelledControlArray1D>)
