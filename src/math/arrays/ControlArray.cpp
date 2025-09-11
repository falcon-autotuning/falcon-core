#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core::math::arrays {
ControlArray::ControlArray() : FArray<double>() {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(const xt::xarray<double>& arr)
    : FArray<double>(arr) {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
ControlArray::ControlArray(const FArray<double>& arr) : FArray<double>(arr) {
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
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator+(other));
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
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator-(other));
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
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator*(other));
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
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(
      generic::FArray<double>::operator/(other));
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
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(generic::FArray<double>::min());
}

std::shared_ptr<ControlArray> ControlArray::max(
    const std::shared_ptr<ControlArray>& other) const {
  return std::make_shared<ControlArray>(generic::FArray<double>::max());
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
