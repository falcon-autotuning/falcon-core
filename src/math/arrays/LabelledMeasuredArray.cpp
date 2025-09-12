#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core::math::arrays {
LabelledMeasuredArray::LabelledMeasuredArray() : MeasuredArray() {}
LabelledMeasuredArray::LabelledMeasuredArray(
    const arrays::MeasuredArraySP&                              array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : MeasuredArray(*array) {
  _label = label;
}
LabelledMeasuredArray::LabelledMeasuredArray(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : MeasuredArray(*array) {
  _label = label;
}
std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator+(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator+(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator+(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator-(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator-(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator-(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator-()
    const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator*(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator*(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator*(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator/(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator/(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator/(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::operator^(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::abs() const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::abs());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::min(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::min());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::min());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::max(
    const std::shared_ptr<LabelledMeasuredArray>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::max());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::max());
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<LabelledMeasuredArray> LabelledMeasuredArray::flip(
    size_t axis) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> LabelledMeasuredArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledMeasuredArray::gradient()
    const {
  return generic::FArray<double>::gradient();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<double>,
    falcon_core::math::arrays::LabelledMeasuredArray)
