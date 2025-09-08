#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

template <typename T>
BaseLabelledArrays<T>::BaseLabelledArrays() = default;

template <typename T>
void BaseLabelledArrays<T>::append(
    const std::shared_ptr<value_type> &labelled_array) {
  _arrays.push_back(labelled_array);
}

template <typename T>
const typename BaseLabelledArrays<T>::container_type &
BaseLabelledArrays<T>::get_arrays() const {
  return _arrays;
}

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
// Explicit instantiation for your used types
using BLA = falcon_core::math::labelled_arrays::
    BaseLabelledArray<falcon_core::math::arrays::BaseArray<double>, int>;
using BLAs = falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>;
template class falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>;
template void falcon_core::math::labelled_arrays::BaseLabelledArrays<
    BLA>::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive &);
template void falcon_core::math::labelled_arrays::BaseLabelledArrays<
    BLA>::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive &);

CEREAL_REGISTER_TYPE(BLAs)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLAs)
