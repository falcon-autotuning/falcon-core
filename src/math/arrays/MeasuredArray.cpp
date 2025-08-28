#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
template <class Archive>
void MeasuredArray<T>::serialize(Archive& ar) {
  ar(cereal::base_class<BaseArray<T>>(this));
}

// Explicit instantiation for double
template class MeasuredArray<double>;

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::arrays::MeasuredArray<double>)
