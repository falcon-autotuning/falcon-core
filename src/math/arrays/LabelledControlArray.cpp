#include "falcon_core/math/arrays/LabelledControlArray.hpp"

namespace falcon_core::math::arrays {
LabelledControlArray::LabelledControlArray() : ControlArray() {}
LabelledControlArray::LabelledControlArray(
    const arrays::ControlArraySP&                               array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(*array) {
  _label = label;
}
LabelledControlArray::LabelledControlArray(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(*array) {
  _label = label;
}
LabelledControlArray::LabelledControlArray(
    const generic::FArraySP<double>&                      array,
    const instrument_interfaces::names::InstrumentPortSP& port)
    : ControlArray(*array) {
  _label = std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
      port);
}
std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator-() const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(), this -> label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}
std::shared_ptr<LabelledControlArray> LabelledControlArray::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::operator^(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator^(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::abs() const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::abs(),
                                                this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::min(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::min(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::min(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::max(
    const std::shared_ptr<LabelledControlArray>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::max(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::max(other), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::reshape(shape), this->label());
}

std::shared_ptr<LabelledControlArray> LabelledControlArray::flip(
    size_t axis) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::flip(axis), this->label());
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
