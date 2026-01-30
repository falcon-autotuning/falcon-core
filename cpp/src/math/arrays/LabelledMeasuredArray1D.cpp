#include "falcon_core/math/arrays/LabelledMeasuredArray1D.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
LabelledMeasuredArray1D::LabelledMeasuredArray1D() : LabelledMeasuredArray() {}
LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    const arrays::MeasuredArraySP&                              array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledMeasuredArray(array, label) {}
LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    const arrays::MeasuredArray1DSP&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledMeasuredArray(std::dynamic_pointer_cast<MeasuredArray>(array),
                            label) {}
LabelledMeasuredArray1D::LabelledMeasuredArray1D(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : LabelledMeasuredArray(array, label) {}
std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator+(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator+(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator+(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator-(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator-(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator-(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator-()
    const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator-(), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator*(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator*(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator*(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator/(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator/(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator/(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}
std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::operator^(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::operator^(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::abs() const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::abs(), this->label());
}

double LabelledMeasuredArray1D::min() const {
  return generic::FArray<double>::min();
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::min(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::min(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::min(other), this->label());
}

double LabelledMeasuredArray1D::max() const {
  return generic::FArray<double>::max();
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::max(
    const std::shared_ptr<LabelledMeasuredArray1D>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::max(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::max(other), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::reshape(shape), this->label());
}

std::shared_ptr<LabelledMeasuredArray1D> LabelledMeasuredArray1D::flip(
    size_t axis) const {
  return std::make_shared<LabelledMeasuredArray1D>(
      generic::FArray<double>::flip(axis), this->label());
}
generic::FArraySP<double> LabelledMeasuredArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledMeasuredArray1D::gradient()
    const {
  return generic::FArray<double>::gradient();
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
