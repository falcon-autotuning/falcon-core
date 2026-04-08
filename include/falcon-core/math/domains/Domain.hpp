#pragma once

#include <mutex>
#include <shared_mutex>

#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class FALCON_CORE_CPP_API Domain : public generic::Song {
  double                          _lesser_bound;
  double                          _greater_bound;
  bool                            _lesser_bound_contained;
  bool                            _greater_bound_contained;
  mutable std::shared_timed_mutex _mu_lesser_bound;
  mutable std::shared_timed_mutex _mu_greater_bound;
  mutable std::shared_timed_mutex _mu_lesser_bound_contained;
  mutable std::shared_timed_mutex _mu_greater_bound_contained;

 public:
  Domain(const Domain& other);
  Domain& operator=(const Domain& other);
  /**
   * @brief Construct a Domain.
   * @param min_val Minimum value of the domain.
   * @param max_val Maximum value of the domain.
   * @param lesser_bound_contained Whether the minimum value is included in the
   * domain.
   * @param greater_bound_contained Whether the maximum value is included in the
   * domain.
   * @throws std::invalid_argument if min_val is greater than max_val.
   */
  Domain(double min_val,
         double max_val,
         bool   lesser_bound_contained  = true,
         bool   greater_bound_contained = true);
  /**
   * @brief Construct a Domain from a pair of bounds.
   * @param bounds A pair of doubles representing the minimum and maximum
   * values.
   * @param lesser_bound_contained Whether the minimum value is included in the
   * domain.
   * @param greater_bound_contained Whether the maximum value is included in the
   * domain.
   */
  Domain(std::pair<double, double> bounds,
         bool                      lesser_bound_contained  = true,
         bool                      greater_bound_contained = true);
  /**
   * @brief Get the lesser bound of the domain.
   * @return The lesser bound.
   */
  const double lesser_bound() const;
  /**
   * @brief Get the greater bound of the domain.
   * @return The greater bound.
   */
  const double greater_bound() const;
  /**
   * @brief Get the bounds of the domain as a pair.
   * @return A pair of doubles representing the lesser and greater bounds.
   */
  const std::pair<double, double> bounds() const;
  /**
   * @brief Check if the lesser bound is contained in the domain.
   * @return True if the lesser bound is contained, false otherwise.
   */
  const bool lesser_bound_contained() const;
  /**
   * @brief Check if the greater bound is contained in the domain.
   * @return True if the greater bound is contained, false otherwise.
   */
  const bool greater_bound_contained() const;
  /**
   * @brief Check if a value is in the domain.
   * @param value The value to check.
   * @return True if the value is in the domain, false otherwise.
   */
  const bool in(double value) const;
  /**
   * @brief Get the size of the domain.
   * @return The size of the domain.
   */
  const double range() const;
  /**
   * @brief Get the center of the domain.
   * @return The center of the domain.
   */
  const double get_center() const;
  /**
   * @brief Get the intersection of this domain with another domain.
   * @param other The other domain.
   * @return A new domain representing the intersection.
   * @throws std::runtime_error if the domains do not intersect.
   */
  const std::shared_ptr<Domain> operator&(
      const std::shared_ptr<Domain>& other) const;
  /**
   * @brief Get the union of this domain with another domain.
   * @param other The other domain.
   * @return A new domain representing the union.
   * @throws std::runtime_error if the domains do not overlap or touch.
   */
  const std::shared_ptr<Domain> operator|(
      const std::shared_ptr<Domain>& other) const;
  /**
   * @brief Check if the domain is empty.
   * @return True if the domain is empty, false otherwise.
   */
  const bool is_empty() const;
  /**
   * @brief Check if this domain completely contains another domain.
   * @param other The other domain.
   * @return True if this domain contains the other domain, false otherwise.
   */
  const bool contains_domain(const std::shared_ptr<Domain>& other) const;
  /**
   * @brief Shift the domain by an offset.
   * @param offset The offset to shift by.
   * @return A new domain representing the shifted domain.
   */
  const std::shared_ptr<Domain> shift(double offset) const;
  /**
   * @brief Scale the domain by a factor.
   * @param factor The factor to scale by.
   * @return A new domain representing the scaled domain.
   */
  const std::shared_ptr<Domain> scale(double factor) const;
  /**
   * @brief Calculate the linear transformation parameters to map this domain to
   * another domain.
   * @param other The other domain to map to.
   * @return A pair of doubles representing the scale and offset of the
   * transformation.
   */
  const std::pair<double, double> calculate_transform(
      const std::shared_ptr<Domain>& other) const;
  /**
   * @brief Transform a value from this domain to another domain.
   * @param other The other domain to transform to.
   * @param value The value to transform.
   * @return The transformed value.
   */
  const double transform(const std::shared_ptr<Domain>& other,
                         double                         value) const;
  bool         operator==(const Domain& other) const;
  bool         operator!=(const Domain& other) const;

 protected:
  friend class cereal::access;
  Domain();
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_lesser_bound(
        _mu_lesser_bound, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_greater_bound(
        _mu_greater_bound, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_lesser_bound_contained(
        _mu_lesser_bound_contained, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_greater_bound_contained(
        _mu_greater_bound_contained, std::defer_lock);
    std::lock(lock_lesser_bound,
              lock_greater_bound,
              lock_lesser_bound_contained,
              lock_greater_bound_contained);
    ar(cereal::base_class<falcon_core::generic::Song>(this),
       _lesser_bound,
       _greater_bound,
       _lesser_bound_contained,
       _greater_bound_contained);
  }
};
using DomainSP = std::shared_ptr<Domain>;
}  // namespace domains
}  // namespace math
}  // namespace falcon_core
