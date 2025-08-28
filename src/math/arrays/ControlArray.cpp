#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
ControlArray<T>::ControlArray() : BaseArray<T>() {}

template <typename T>
ControlArray<T>::ControlArray(const ControlArray& other)
    : BaseArray<T>(other) {}

template <typename T>
ControlArray<T>::ControlArray(const typename BaseArray<T>::MatrixType& data)
    : BaseArray<T>(data) {}

template <typename T>
template <class Archive>
void ControlArray<T>::serialize(Archive& ar) {
  ar(cereal::base_class<BaseArray<T>>(this));
}

// Explicit instantiation for float and double
template class ControlArray<float>;
template class ControlArray<double>;

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<float>,
    falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<double>,
    falcon_core::math::arrays::ControlArray<double>)
