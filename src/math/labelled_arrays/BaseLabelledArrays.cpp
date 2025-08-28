#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

template <typename T>
BaseLabelledArrays<T>::BaseLabelledArrays() = default;

template <typename T>
void BaseLabelledArrays<T>::append(const std::shared_ptr<value_type> &labelled_array) {
  _arrays.push_back(labelled_array);
}

template <typename T>
const typename BaseLabelledArrays<T>::container_type &BaseLabelledArrays<T>::get_arrays() const {
  return _arrays;
}

template <typename T>
template <class Archive>
void BaseLabelledArrays<T>::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _arrays);
}

// Explicit instantiation for your used types
using BLA = falcon_core::math::labelled_arrays::BaseLabelledArray<
    falcon_core::math::arrays::BaseArray<double>, int>;
using BLAs = falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>;
template class falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>;
template void falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive&);
template void falcon_core::math::labelled_arrays::BaseLabelledArrays<BLA>::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive&);

}}} // namespace

CEREAL_REGISTER_TYPE(BLAs)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, BLAs)
