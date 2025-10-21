#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

#include <stdexcept>

#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {
const arrays::MeasuredArray& check_and_deref(
    const arrays::MeasuredArraySP& array) {
  if (!array)
    throw std::invalid_argument(
        "LabelledControlArray: The array must not be null.");
  return *array;
}
const generic::FArray<double>& lma_check_and_defref(
    const generic::FArraySP<double>& array) {
  if (!array)
    throw std::invalid_argument(
        "LabelledControlArray: The array must not be null.");
  return *array;
}
LabelledMeasuredArray::LabelledMeasuredArray() : MeasuredArray() {}
LabelledMeasuredArray::LabelledMeasuredArray(
    const arrays::MeasuredArraySP&                              array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : MeasuredArray(check_and_deref(array)) {
  if (!label) {
    throw std::invalid_argument(
        "LabelledControlArray: The label must not be null.");
  }
  _label = label;
}
LabelledMeasuredArray::LabelledMeasuredArray(
    const generic::FArraySP<double>&                            array,
    const autotuner_interfaces::contexts::AcquisitionContextSP& label)
    : MeasuredArray(lma_check_and_defref(array)) {
  if (!label) {
    throw std::invalid_argument(
        "LabelledControlArray: The label must not be null.");
  }
  _label = label;
}
LabelledMeasuredArray::LabelledMeasuredArray(
    const generic::FArraySP<double>&                      array,
    const instrument_interfaces::names::InstrumentPortSP& port)
    : MeasuredArray(lma_check_and_defref(array)) {
  if (!port) {
    throw std::invalid_argument(
        "LabelledControlArray: The port must not be null.");
  }
  _label = std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
      port);
}
LabelledMeasuredArraySP LabelledMeasuredArray::operator+(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator+(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator+(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator+(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator+(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator-(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator-(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator-(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator-(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator-() const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator-(), this -> label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator*(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator*(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator*(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator*(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator*(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator/(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator/(
    const int other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator/(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other), this->label());
}
LabelledMeasuredArraySP LabelledMeasuredArray::operator/(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator/(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::operator^(
    const double other) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::operator^(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::abs() const {
  return std::make_shared<LabelledMeasuredArray>(generic::FArray<double>::abs(),
                                                 this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::min(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::min(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::min(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::min(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::max(
    const LabelledMeasuredArraySP& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  if (*other->label() != *label()) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to have a matching "
        "label.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::max(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::max(
    const std::shared_ptr<FArray<double>>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "LabelledMeasuredArray: The other array needs to not be null.");
  }
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::max(other), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::reshape(
    const std::vector<size_t>& shape) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::reshape(shape), this->label());
}

LabelledMeasuredArraySP LabelledMeasuredArray::flip(size_t axis) const {
  return std::make_shared<LabelledMeasuredArray>(
      generic::FArray<double>::flip(axis), this->label());
}
generic::FArraySP<double> LabelledMeasuredArray::gradient(size_t axis) const {
  return generic::FArray<double>::gradient(axis);
}
generic::ListSP<generic::FArray<double>> LabelledMeasuredArray::gradient()
    const {
  return generic::FArray<double>::gradient();
}
bool LabelledMeasuredArray::operator==(
    const LabelledMeasuredArray& other) const {
  return (*label() == *other.label()) && MeasuredArray::operator==(other);
}
bool LabelledMeasuredArray::operator!=(
    const LabelledMeasuredArray& other) const {
  return !(*this == other);
}
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::LabelledMeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::MeasuredArray,
    falcon_core::math::arrays::LabelledMeasuredArray)
