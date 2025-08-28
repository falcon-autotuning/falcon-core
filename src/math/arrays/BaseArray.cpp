#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
BaseArray<T>::BaseArray(const MatrixType &data) : _data(data) {}

template <typename T>
BaseArray<T>::BaseArray() = default;

template <typename T>
const typename BaseArray<T>::MatrixType &BaseArray<T>::data() const { return _data; }

template <typename T>
typename BaseArray<T>::MatrixType &BaseArray<T>::data() { return _data; }

template <typename T>
bool BaseArray<T>::is_1d() const { return _data.rows() == 1 || _data.cols() == 1; }

template <typename T>
template <class Archive>
void BaseArray<T>::serialize(Archive &ar) {
  ar(cereal::base_class<generic::Song>(this), _data);
}

// Explicit instantiation for double
template class BaseArray<double>;

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::BaseArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::arrays::BaseArray<double>)
