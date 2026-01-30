#include "falcon_core/math/arrays/LabelledControlArray1D.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
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
LabelledControlArray1DSP LabelledControlArray1D::operator+(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator+(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator+(
    const LabelledControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator-(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator-(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator-(
    const LabelledControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator-() const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator-(), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator*(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator*(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator/(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator/(
    const int other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::operator^(
    const double other) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::operator^(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::abs() const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::abs(), this->label());
}

double LabelledControlArray1D::min() const {
  return generic::FArray<double>::min();
}

LabelledControlArray1DSP LabelledControlArray1D::min(
    const LabelledControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::min(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::min(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::min(other), this->label());
}

double LabelledControlArray1D::max() const {
  return generic::FArray<double>::max();
}

LabelledControlArray1DSP LabelledControlArray1D::max(
    const LabelledControlArray1DSP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::max(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::max(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledControlArray1D: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::max(other), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::reshape(shape), this->label());
}

LabelledControlArray1DSP LabelledControlArray1D::flip(size_t axis) const {
  return std::make_shared<LabelledControlArray1D>(
      generic::FArray<double>::flip(axis), this->label());
}
generic::FArraySP<double> LabelledControlArray1D::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledControlArray1D::gradient()
    const {
  return generic::FArray<double>::gradient();
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
