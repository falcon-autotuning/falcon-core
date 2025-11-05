#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
MeasuredArray::MeasuredArray() : FArray<double>() {}
MeasuredArray::MeasuredArray(const xt::xarray<double>& arr)
    : FArray<double>(arr) {}
MeasuredArray::MeasuredArray(const generic::FArraySP<double>& arr)
    : FArray<double>(arr ? *arr : generic::FArray<double>()) {
  if (!arr) {
    throw std::invalid_argument("MeasuredArray: input array must not be null.");
  }
}
MeasuredArray::MeasuredArray(xt::xarray<double>&& arr) noexcept
    : FArray<double>(arr) {}
std::shared_ptr<MeasuredArray> MeasuredArray::operator+(
    const double other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator+(const int other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator+(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator-(
    const double other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator-(const int other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator-(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator-() const {
  return std::make_shared<MeasuredArray>(generic::FArray<double>::operator-());
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator*(
    const double other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator*(const int other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator*(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator/(
    const double other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator/(const int other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator/(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<MeasuredArray> MeasuredArray::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::operator^(
    const double other) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::abs() const {
  return std::make_shared<MeasuredArray>(generic::FArray<double>::abs());
}

std::shared_ptr<MeasuredArray> MeasuredArray::min(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(generic::FArray<double>::min(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(generic::FArray<double>::min(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::max(
    const std::shared_ptr<MeasuredArray>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(generic::FArray<double>::max(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument("MeasuredArray: other array must not be null.");
  }
  return std::make_shared<MeasuredArray>(generic::FArray<double>::max(other));
}

std::shared_ptr<MeasuredArray> MeasuredArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<MeasuredArray>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<MeasuredArray> MeasuredArray::flip(size_t axis) const {
  return std::make_shared<MeasuredArray>(generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> MeasuredArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> MeasuredArray::gradient() const {
  return generic::FArray<double>::gradient();
}
bool MeasuredArray::operator==(const MeasuredArray& other) const {
  return generic::FArray<double>::operator==(other);
}
bool MeasuredArray::operator!=(const MeasuredArray& other) const {
  return generic::FArray<double>::operator!=(other);
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::FArray<double>,
                                     falcon_core::math::arrays::MeasuredArray)
