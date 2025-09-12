#pragma once
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/FArrayProtocol.hpp"
namespace falcon_core::math::arrays {
template <typename T>
class IsLabelled : public virtual generic::IFArray<T> {
 protected:
  autotuner_interfaces::contexts::AcquisitionContextSP _label;

 public:
  const autotuner_interfaces::contexts::AcquisitionContextSP& label() const {
    return _label;
  }
  const physics::device_structures::BaseConnectionSP connection() const {
    return label()->connection();
  }
  const instrument_interfaces::Instrument instrument_type() const {
    return label()->instrument_type();
  }
  const physics::units::SymbolUnitSP units() const { return label()->units(); }

  bool operator==(const std::shared_ptr<IsLabelled<T>>& other) const {
    return (*this == *other && label() == other->label());
  }
  std::shared_ptr<IsLabelled<T>> operator+(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<IsLabelled<T>>(*this + *other, this->label());
    } else {
      throw std::runtime_error(
          "Cannot add labelled arrays with different labels.");
    }
  }
  std::shared_ptr<IsLabelled<T>> operator+(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this + other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator+(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this + other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator-() const {
    return std::make_shared<IsLabelled<T>>(-*this, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator-(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<IsLabelled<T>>(*this - *other, this->label());
    } else {
      throw std::runtime_error(
          "Cannot subtract labelled arrays with different labels.");
    }
  }
  std::shared_ptr<IsLabelled<T>> operator-(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this - other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator-(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this - other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator^(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this ^ other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator*(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() *= other.label()->units();
    return std::make_shared<IsLabelled<T>>(*this * *other, label);
  }
  std::shared_ptr<IsLabelled<T>> operator*(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this * other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator*(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this * other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator/(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() /= other.label()->units();
    return std::make_shared<IsLabelled<T>>(*this / *other, label);
  }
  std::shared_ptr<IsLabelled<T>> operator/(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this / other, this->label());
  }
  std::shared_ptr<IsLabelled<T>> operator/(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this / other, this->label());
  }
  /**
   * @brief Get the sum of squares of the data.
   */
  double get_sum_of_squares() const { return this->get_sum_of_squares(); }
  bool   operator>(const double value) const { return this > value; }
  bool   operator<(const double value) const { return this < value; }
  /**
   * @brief Remove an offset from the data.
   * @param offset The offset to remove.
   */
  void remove_offset(const double offset) {
    generic::IFArray<T>::remove_offset(offset);
  }
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped IsLabelled.
   */
  std::shared_ptr<IsLabelled<T>> flip(size_t axis) const {
    return std::make_shared<IsLabelled<T>>(generic::IFArray<T>::flip(axis));
  }
  /**
   * @brief Return the gradient of the data along all axes.
   */
  generic::ListSP<std::shared_ptr<IsLabelled<T>>> gradient() const {
    auto grads = generic::IFArray<T>::gradient();
    auto list =
        std::make_shared<generic::List<std::shared_ptr<IsLabelled<T>>>>();
    for (const auto& grad : *grads) {
      list->push_back(std::make_shared<IsLabelled<T>>(std::make_shared<T>(grad),
                                                      this->label()));
    }
    return list;
  }
  /**
   * @brief Return the gradient of the data along a given axis.
   * @param axis The axis to compute the gradient.
   * @return The gradient IsLabelled.
   */
  std::shared_ptr<IsLabelled<T>> gradient(size_t axis) const {
    auto grad = generic::IFArray<T>::gradient(axis);
    return std::make_shared<IsLabelled<T>>(std::make_shared<T>(*grad),
                                           this->label());
  }
};
}  // namespace falcon_core::math::arrays
