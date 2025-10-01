#include "falcon_core/math/arrays/ControlArray.hpp"

#include <stdexcept>

#include "falcon_core/math/arrays/IncreasingAlignment.hpp"
namespace falcon_core::math::arrays {
ControlArray::ControlArray() : FArray<double>() {
  _principle_dimension = 0;
  _alignment = std::make_shared<IncreasingAlignment>(IncreasingAlignment(true));
}
ControlArray::ControlArray(const xt::xarray<double>& arr)
    : FArray<double>(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(const generic::FArraySP<double>& arr)
    : FArray<double>(arr ? *arr : generic::FArray<double>()) {
  if (!arr) {
    throw std::invalid_argument("ControlArray: input array must not be null.");
  }
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(xt::xarray<double>&& arr) noexcept
    : FArray<double>(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
std::shared_ptr<ControlArray> ControlArray::operator+(
    const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray> ControlArray::operator+(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray> ControlArray::operator+(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<ControlArray> ControlArray::operator+(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator+(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::operator-(
    const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray> ControlArray::operator-(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray> ControlArray::operator-(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<ControlArray> ControlArray::operator-(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator-(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::operator-() const {
  return std::make_shared<ControlArray>(generic::FArray<double>::operator-());
}

std::shared_ptr<ControlArray> ControlArray::operator*(
    const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray> ControlArray::operator*(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray> ControlArray::operator*(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<ControlArray> ControlArray::operator*(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator*(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::operator/(
    const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray> ControlArray::operator/(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray> ControlArray::operator/(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<ControlArray> ControlArray::operator/(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator/(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::operator^(
    const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<ControlArray> ControlArray::abs() const {
  return std::make_shared<ControlArray>(generic::FArray<double>::abs());
}

std::shared_ptr<ControlArray> ControlArray::min(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(generic::FArray<double>::min(other));
}

std::shared_ptr<ControlArray> ControlArray::min(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::min(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::max(
    const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (*other->alignment() != *alignment()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different alignment.");
  }
  return std::make_shared<ControlArray>(generic::FArray<double>::max(other));
}

std::shared_ptr<ControlArray> ControlArray::max(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::max(std::make_shared<ControlArray>(other));
}

std::shared_ptr<ControlArray> ControlArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<ControlArray> ControlArray::flip(size_t axis) const {
  return std::make_shared<ControlArray>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> ControlArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> ControlArray::gradient() const {
  return generic::FArray<double>::gradient();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray)
