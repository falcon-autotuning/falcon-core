#include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"

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
