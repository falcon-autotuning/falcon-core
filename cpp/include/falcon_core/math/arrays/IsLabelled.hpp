#pragma once
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/export.h"
#include "falcon_core/generic/FArrayProtocol.hpp"
namespace falcon_core {
namespace math {
namespace arrays {
template <typename T>
class FALCON_CORE_CPP_API IsLabelled : public virtual generic::IFArray<T> {
 protected:
  friend class cereal::access;
  autotuner_interfaces::contexts::AcquisitionContextSP _label;
  mutable std::shared_timed_mutex                      _mu_label;

 public:
  autotuner_interfaces::contexts::AcquisitionContextSP label() const {
    std::shared_lock<std::shared_timed_mutex> lock_l(_mu_label);
    return _label;
  }
  inline const physics::device_structures::ConnectionSP connection() const {
    return label()->connection();
  }
  inline const instrument_interfaces::names::Instrument instrument_type()
      const {
    return label()->instrument_type();
  }
  inline const physics::units::SymbolUnitSP units() const {
    return label()->units();
  }

  inline std::shared_ptr<IsLabelled<T>> operator+(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<IsLabelled<T>>(*this + *other, this->label());
    } else {
      throw std::runtime_error(
          "Cannot add labelled arrays with different labels.");
    }
  }
  inline std::shared_ptr<IsLabelled<T>> operator+(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this + other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator+(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this + other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator-() const {
    return std::make_shared<IsLabelled<T>>(-*this, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator-(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<IsLabelled<T>>(*this - *other, this->label());
    } else {
      throw std::runtime_error(
          "Cannot subtract labelled arrays with different labels.");
    }
  }
  inline std::shared_ptr<IsLabelled<T>> operator-(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this - other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator-(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this - other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator^(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this ^ other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator*(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() *= other.label()->units();
    return std::make_shared<IsLabelled<T>>(*this * *other, label);
  }
  inline std::shared_ptr<IsLabelled<T>> operator*(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this * other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator*(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this * other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator/(
      const std::shared_ptr<IsLabelled<T>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() /= other.label()->units();
    return std::make_shared<IsLabelled<T>>(*this / *other, label);
  }
  inline std::shared_ptr<IsLabelled<T>> operator/(const int other) const {
    return std::make_shared<IsLabelled<T>>(*this / other, this->label());
  }
  inline std::shared_ptr<IsLabelled<T>> operator/(const double other) const {
    return std::make_shared<IsLabelled<T>>(*this / other, this->label());
  }
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped IsLabelled.
   */
  inline std::shared_ptr<IsLabelled<T>> flip(size_t axis) const {
    return std::make_shared<IsLabelled<T>>(generic::IFArray<T>::flip(axis));
  }
  /**
   * @brief Return the gradient of the data along all axes.
   */
  inline generic::ListSP<std::shared_ptr<IsLabelled<T>>> gradient() const {
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
  inline std::shared_ptr<IsLabelled<T>> gradient(size_t axis) const {
    auto grad = generic::IFArray<T>::gradient(axis);
    return std::make_shared<IsLabelled<T>>(std::make_shared<T>(*grad),
                                           this->label());
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
