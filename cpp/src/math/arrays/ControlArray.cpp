#include "falcon_core/math/arrays/ControlArray.hpp"

#include <cereal/types/polymorphic.hpp>
#include <stdexcept>

#include "falcon_core/math/arrays/IncreasingAlignment.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
ControlArray::ControlArray(const ControlArray& other) : FArray<double>(other) {
  _principle_dimension = other._principle_dimension;
  _alignment           = other._alignment;
}
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
ControlArraySP ControlArray::operator+(const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

ControlArraySP ControlArray::operator+(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

ControlArraySP ControlArray::operator+(const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (other->principle_dimension() != principle_dimension()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different "
        "principle_dimension.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
}

ControlArraySP ControlArray::operator+(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator+(std::make_shared<ControlArray>(other));
}

ControlArraySP ControlArray::operator-(const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

ControlArraySP ControlArray::operator-(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

ControlArraySP ControlArray::operator-(const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (other->principle_dimension() != principle_dimension()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different "
        "principle_dimension.");
  }
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
}

ControlArraySP ControlArray::operator-(
    const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::operator-(std::make_shared<ControlArray>(other));
}

ControlArraySP ControlArray::operator-() const {
  return std::make_shared<ControlArray>(generic::FArray<double>::operator-());
}

ControlArraySP ControlArray::operator*(const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
}

ControlArraySP ControlArray::operator*(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
}

ControlArraySP ControlArray::operator/(const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
}

ControlArraySP ControlArray::operator/(const int other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
}

ControlArraySP ControlArray::operator^(const double other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator^(other));
}

ControlArraySP ControlArray::abs() const {
  return std::make_shared<ControlArray>(generic::FArray<double>::abs());
}

double ControlArray::min() const { return generic::FArray<double>::min(); }

ControlArraySP ControlArray::min(const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (other->principle_dimension() != principle_dimension()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different "
        "principle_dimension.");
  }
  return std::make_shared<ControlArray>(generic::FArray<double>::min(other));
}

ControlArraySP ControlArray::min(const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::min(std::make_shared<ControlArray>(other));
}

double ControlArray::max() const { return generic::FArray<double>::max(); }

ControlArraySP ControlArray::max(const ControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  if (other->principle_dimension() != principle_dimension()) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot have a different "
        "principle_dimension.");
  }
  return std::make_shared<ControlArray>(generic::FArray<double>::max(other));
}

ControlArraySP ControlArray::max(const generic::FArraySP<double>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return ControlArray::max(std::make_shared<ControlArray>(other));
}

ControlArraySP ControlArray::reshape(const std::vector<size_t>& shape) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::reshape(shape));
}

ControlArraySP ControlArray::flip(size_t axis) const {
  return std::make_shared<ControlArray>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> ControlArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> ControlArray::gradient() const {
  return generic::FArray<double>::gradient();
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray)
CEREAL_REGISTER_TYPE(falcon_core::generic::FArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::FArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::ControlArray)
