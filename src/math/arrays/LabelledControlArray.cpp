#include "falcon_core/math/arrays/LabelledControlArray.hpp"

namespace falcon_core::math::arrays {
LabelledControlArray::LabelledControlArray() : ControlArray() {
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
LabelledControlArray::LabelledControlArray(
    const arrays::ControlArraySP&                               array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(*array) {
  _label               = label;
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
LabelledControlArray::LabelledControlArray(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(*array) {
  _label               = label;
  _principle_dimension = 0;
  _alignment           = _determine_alignments();
}
std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-() const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator^(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::abs() const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::abs());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::min(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::min());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::min());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::max(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::max());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::max());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::flip(
    size_t axis) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> LabelledControlArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledControlArray::gradient()
    const {
  return generic::FArray<double>::gradient();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<double>,
    falcon_core::math::arrays::LabelledControlArray)
