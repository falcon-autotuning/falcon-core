#include "falcon_core/math/labelled_arrays/LabelledControlArrays.hpp"

namespace falcon_core::math::labelled_arrays {

LabelledControlArrays::LabelledControlArrays() = default;
LabelledControlArrays::LabelledControlArrays(
    const std::vector<LabelledControlArraySP>& arrays)
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

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledControlArrays)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::labelled_arrays::BaseLabelledArrays<double>,
    falcon_core::math::labelled_arrays::LabelledControlArrays)
