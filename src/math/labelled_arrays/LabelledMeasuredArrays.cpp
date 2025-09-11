#include "falcon_core/math/labelled_arrays/LabelledMeasuredArrays.hpp"

namespace falcon_core::math::labelled_arrays {

LabelledMeasuredArrays::LabelledMeasuredArrays() = default;
LabelledMeasuredArrays::LabelledMeasuredArrays(
    const std::vector<LabelledMeasuredArraySP>& arrays)
    : BaseLabelledArrays([&arrays]() {
        std::vector<std::shared_ptr<BaseLabelledArray<double>>> base_arrays;
        base_arrays.reserve(arrays.size());
        for (const auto& arr : arrays) {
          base_arrays.push_back(
              std::dynamic_pointer_cast<BaseLabelledArray<double>>(arr));
        }
        return base_arrays;
      }()) {}
}  // namespace falcon_core::math::labelled_arrays

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledMeasuredArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::labelled_arrays::BaseLabelledArrays<double>,
    falcon_core::math::labelled_arrays::LabelledMeasuredArrays)
