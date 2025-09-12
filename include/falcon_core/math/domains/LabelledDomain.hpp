/**
 * @file LabelledDomain.hpp
 * @brief Defines the LabelledDomain template for FalconCore.
 */

#pragma once

#include "falcon_core/math/domains/BaseLabelledDomain.hpp"

namespace falcon_core::math::domains {

/**
 * @brief Domain with an associated label.
 * @tparam T Type of the label.
 */
template <typename T>
class LabelledDomain : public BaseLabelledDomain<T> {
 public:
  /**
   * @brief Construct a labelled domain.
   * @param min_val Minimum value of the domain.
   * @param max_val Maximum value of the domain.
   * @param label Shared pointer to the label.
   */
  LabelledDomain(const double              min_val,
                 const double              max_val,
                 const std::shared_ptr<T>& label,
                 const bool                lesser_bound_contained  = true,
                 const bool                greater_bound_contained = true)
      : BaseLabelledDomain<T>(min_val,
                              max_val,
                              label,
                              lesser_bound_contained,
                              greater_bound_contained) {}
  /**
   * @brief Construct a labelled domain.
   * @param bounds Minimum, Maximum pair of the domain.
   * @param label Shared pointer to the label.
   */
  LabelledDomain(const std::pair<double, double> bounds,
                 const std::shared_ptr<T>&       label,
                 const bool                      lesser_bound_contained  = true,
                 const bool                      greater_bound_contained = true)
      : BaseLabelledDomain<T>(
            bounds, label, lesser_bound_contained, greater_bound_contained) {}

 private:
  friend class cereal::access;
  LabelledDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledDomain<T>>(this));
  }
};
}  // namespace falcon_core::math::domains
