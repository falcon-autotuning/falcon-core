#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"

namespace falcon_core::math::arrays {
LabelledControlArray1D::LabelledControlArray1D() : LabelledControlArray() {}
LabelledControlArray1D::LabelledControlArray1D(
    const arrays::ControlArraySP&                               array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledControlArray(array, label) {}
LabelledControlArray1D::LabelledControlArray1D(
    const arrays::ControlArray1DSP&                             array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledControlArray(std::dynamic_pointer_cast<ControlArray>(array),
                           label) {}
LabelledControlArray1D::LabelledControlArray1D(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledControlArray(array, label) {}
std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator+(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator+(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator+(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator-(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator-(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator-(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator-()
    const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator*(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator*(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator*(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator/(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator/(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator/(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other));
}
std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::operator^(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator^(other));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::abs() const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::abs());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::min(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::min());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::min());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::max(
    const std::shared_ptr<LabelledControlArray1D>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::max());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::max());
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::reshape(shape));
}

std::shared_ptr<LabelledControlArray1D> LabelledControlArray1D::flip(
    size_t axis) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::flip(axis));
}
generic::FArraySP<double> LabelledControlArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledControlArray1D::gradient()
    const {
  return generic::FArray<double>::gradient();
}
}  // namespace falcon_core::math::arrays
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::FArray<double>,
    falcon_core::math::arrays::LabelledControlArray1D)
