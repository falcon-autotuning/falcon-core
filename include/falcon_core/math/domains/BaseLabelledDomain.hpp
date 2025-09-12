/**
 * @file BaseLabelledDomain.hpp
 * @brief Defines the BaseLabelledDomain template for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core::math::domains {

/**
 * @brief Domain with an associated label.
 * @tparam T Type of the label.
 */
template <typename T>
class BaseLabelledDomain : public Domain {
  std::shared_ptr<T> _label;

 public:
  /**
   * @brief Construct a labelled domain.
   * @param min_val Minimum value of the domain.
   * @param max_val Maximum value of the domain.
   * @param label Shared pointer to the label.
   */
  BaseLabelledDomain(const double              min_val,
                     const double              max_val,
                     const std::shared_ptr<T>& label,
                     const bool                lesser_bound_contained  = true,
                     const bool                greater_bound_contained = true)
      : Domain(
            min_val, max_val, lesser_bound_contained, greater_bound_contained),
        _label(std::move(label)) {}
  /**
   * @brief Construct a labelled domain.
   * @param bounds Minimum, Maximum pair of the domain.
   * @param label Shared pointer to the label.
   */
  BaseLabelledDomain(const std::pair<double, double> bounds,
                     const std::shared_ptr<T>&       label,
                     const bool lesser_bound_contained  = true,
                     const bool greater_bound_contained = true)
      : Domain(bounds, lesser_bound_contained, greater_bound_contained),
        _label(std::move(label)) {}

  /**
   * @brief Get the label.
   * @return Shared pointer to the label.
   */
  const std::shared_ptr<T>& label() const { return _label; }
  /**
   * @brief Gets the domain associated with the label.
   */
  std::shared_ptr<Domain> domain() const {
    return std::make_shared<Domain>(this->lesser_bound(),
                                    this->greater_bound(),
                                    this->lesser_bound_contained(),
                                    this->greater_bound_contained());
  }
  /**
   * @brief Checks if the label matches the given label.
   * @param label The label to compare with.
   * @return True if the labels match, false otherwise.
   */
  bool matching_label(const std::shared_ptr<T>& label) const {
    return _label && *_label == *label;
  }

 protected:
  BaseLabelledDomain() = default;
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Domain>(this), _label);
  }
};
template <typename T>
using BaseLabelledDomainSP = std::shared_ptr<BaseLabelledDomain<T>>;
}  // namespace falcon_core::math::domains
