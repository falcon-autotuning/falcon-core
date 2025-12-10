#include "falcon_core/math/arrays/LabelledControlArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
LabelledControlArray::LabelledControlArray(const LabelledControlArray& other)
    : ControlArray(other) {
  _label = other.label();
}
LabelledControlArray& LabelledControlArray::operator=(
    const LabelledControlArray& other) {
  if (this != &other) {
    ControlArray::operator=(other);
    _label = other.label();
  }
  return *this;
}
const arrays::ControlArray& check_and_deref(
    const arrays::ControlArraySP& array) {
  if (!array)
    throw std::invalid_argument(
        "LabelledControlArray: The array must not be null.");
  return *array;
}
const generic::FArray<double>& check_and_defref(
    const generic::FArraySP<double>& array) {
  if (!array)
    throw std::invalid_argument(
        "LabelledControlArray: The array must not be null.");
  return *array;
}
LabelledControlArray::LabelledControlArray() : ControlArray() {}
LabelledControlArray::LabelledControlArray(
    const arrays::ControlArraySP&                               array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(check_and_deref(array)) {
  if (!label) {
    throw std::invalid_argument(
        "LabelledControlArray: The label must not be null.");
  }
  _label = label;
}
LabelledControlArray::LabelledControlArray(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : ControlArray(check_and_defref(array)) {
  if (!label) {
    throw std::invalid_argument(
        "LabelledControlArray: The label must not be null.");
  }
  _label = label;
}
LabelledControlArray::LabelledControlArray(
    const generic::FArraySP<double>&                      array,
    const instrument_interfaces::names::InstrumentPortSP& port)
    : ControlArray(check_and_defref(array)) {
  if (!port) {
    throw std::invalid_argument(
        "LabelledControlArray: The port must not be null.");
  }
  _label = std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
      port);
}
LabelledControlArraySP LabelledControlArray::operator+(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator+(const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator+(
    const LabelledControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return LabelledControlArray::operator+(
      std::make_shared<LabelledControlArray>(other, this->label()));
}

LabelledControlArraySP LabelledControlArray::operator-(
    const double other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator-(const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator-(
    const LabelledControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return LabelledControlArray::operator-(
      std::make_shared<LabelledControlArray>(other, this->label()));
}

LabelledControlArraySP LabelledControlArray::operator-() const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator-(), this -> label());
}

LabelledControlArraySP LabelledControlArray::operator*(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator*(const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator/(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator/(const int other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledControlArraySP LabelledControlArray::operator^(
    const double other) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::operator^(other), this->label());
}

LabelledControlArraySP LabelledControlArray::abs() const {
  return std::make_shared<LabelledControlArray>(generic::FArray<double>::abs(),
                                                this->label());
}

double LabelledControlArray::min() const {
  return generic::FArray<double>::min();
}

LabelledControlArraySP LabelledControlArray::min(
    const LabelledControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::min(other), this->label());
}

LabelledControlArraySP LabelledControlArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::min(other), this->label());
}

double LabelledControlArray::max() const {
  return generic::FArray<double>::max();
}

LabelledControlArraySP LabelledControlArray::max(
    const LabelledControlArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::max(other), this->label());
}

LabelledControlArraySP LabelledControlArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "ControlArray: The other array cannot be null.");
  }
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::max(other), this->label());
}

LabelledControlArraySP LabelledControlArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledControlArray>(
      generic::FArray<double>::reshape(shape), this->label());
}

LabelledControlArraySP LabelledControlArray::flip(size_t axis) const {
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
bool LabelledControlArray::operator==(const LabelledControlArray& other) const {
  return (*label() == *other.label()) && ControlArray::operator==(other);
}
bool LabelledControlArray::operator!=(const LabelledControlArray& other) const {
  return !(*this == other);
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledControlArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::ControlArray,
    falcon_core::math::arrays::LabelledControlArray)
