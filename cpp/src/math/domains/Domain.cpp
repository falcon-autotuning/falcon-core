#include "falcon_core/math/domains/Domain.hpp"

#include <stdexcept>

namespace falcon_core {
namespace math {
namespace domains {
Domain::Domain(const Domain& other) {
  std::unique_lock<std::shared_timed_mutex> lock_lesser_bound(_mu_lesser_bound,
                                                              std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_greater_bound(
      _mu_greater_bound, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_lesser_bound_contained(
      _mu_lesser_bound_contained, std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_greater_bound_contained(
      _mu_greater_bound_contained, std::defer_lock);
  std::lock(lock_lesser_bound,
            lock_greater_bound,
            lock_lesser_bound_contained,
            lock_greater_bound_contained);
  _lesser_bound            = other.lesser_bound();
  _greater_bound           = other.greater_bound();
  _lesser_bound_contained  = other.lesser_bound_contained();
  _greater_bound_contained = other.greater_bound_contained();
}
Domain& Domain::operator=(const Domain& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_lesser_bound(
        _mu_lesser_bound, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_greater_bound(
        _mu_greater_bound, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_lesser_bound_contained(
        _mu_lesser_bound_contained, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_greater_bound_contained(
        _mu_greater_bound_contained, std::defer_lock);
    std::lock(lock_lesser_bound,
              lock_greater_bound,
              lock_lesser_bound_contained,
              lock_greater_bound_contained);
    _lesser_bound            = other.lesser_bound();
    _greater_bound           = other.greater_bound();
    _lesser_bound_contained  = other.lesser_bound_contained();
    _greater_bound_contained = other.greater_bound_contained();
  }
  return *this;
}
Domain::Domain() = default;
Domain::Domain(double min_val,
               double max_val,
               bool   lesser_bound_contained,
               bool   greater_bound_contained)
    : _lesser_bound(min_val),
      _greater_bound(max_val),
      _lesser_bound_contained(lesser_bound_contained),
      _greater_bound_contained(greater_bound_contained) {
  if (_lesser_bound > _greater_bound) {
    throw std::invalid_argument("min cannot be greater than max");
  }
}
Domain::Domain(std::pair<double, double> bounds,
               bool                      lesser_bound_contained,
               bool                      greater_bound_contained)
    : Domain(std::min(bounds.first, bounds.second),
             std::max(bounds.first, bounds.second),
             lesser_bound_contained,
             greater_bound_contained) {}
const double Domain::lesser_bound() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_lesser_bound);
  return _lesser_bound;
}
const double Domain::greater_bound() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_greater_bound);
  return _greater_bound;
}
const std::pair<double, double> Domain::bounds() const {
  return {lesser_bound(), greater_bound()};
}
const bool Domain::lesser_bound_contained() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_lesser_bound_contained);
  return _lesser_bound_contained;
}
const bool Domain::greater_bound_contained() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_greater_bound_contained);
  return _greater_bound_contained;
}
const bool Domain::in(double value) const {
  bool greater_than_min = lesser_bound_contained() ? value >= lesser_bound()
                                                   : value > lesser_bound();
  bool less_than_max    = greater_bound_contained() ? value <= greater_bound()
                                                    : value < greater_bound();
  return greater_than_min && less_than_max;
}
const double Domain::range() const { return greater_bound() - lesser_bound(); }
const double Domain::get_center() const {
  return (lesser_bound() + greater_bound()) / 2.0;
}
const std::shared_ptr<Domain> Domain::operator&(
    const std::shared_ptr<Domain>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Domain: The other domain to & with must not be null.");
  }
  double new_min = std::max(this->lesser_bound(), other->lesser_bound());
  double new_max = std::min(this->greater_bound(), other->greater_bound());
  if (new_min > new_max)
    throw std::runtime_error("Domain: Domains are split and do not intersect");
  bool new_min_contained =
      (new_min == this->lesser_bound() && this->lesser_bound_contained()) ||
      (new_min == other->lesser_bound() && other->lesser_bound_contained());
  bool new_max_contained =
      (new_max == this->greater_bound() && this->greater_bound_contained()) ||
      (new_max == other->greater_bound() && other->greater_bound_contained());
  if (new_min == new_max && (!new_min_contained || !new_max_contained)) {
    throw std::runtime_error("Domain: Domains do not intersect");
  }
  return std::make_shared<Domain>(
      new_min, new_max, new_min_contained, new_max_contained);
}
const std::shared_ptr<Domain> Domain::operator|(
    const std::shared_ptr<Domain>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Domain: The other domain to & with must not be null.");
  }
  this->operator&(other);  // Check if they intersect or touch
  double new_min = std::min(this->lesser_bound(), other->lesser_bound());
  double new_max = std::max(this->greater_bound(), other->greater_bound());

  bool new_min_contained =
      (new_min == this->lesser_bound() && this->lesser_bound_contained()) ||
      (new_min == other->lesser_bound() && other->lesser_bound_contained());
  bool new_max_contained =
      (new_max == this->greater_bound() && this->greater_bound_contained()) ||
      (new_max == other->greater_bound() && other->greater_bound_contained());

  return std::make_shared<Domain>(
      new_min, new_max, new_min_contained, new_max_contained);
}
const bool Domain::is_empty() const {
  return lesser_bound() == greater_bound() &&
         (!lesser_bound_contained() || !greater_bound_contained());
}
const bool Domain::contains_domain(const std::shared_ptr<Domain>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Domain: The other domain to & with must not be null.");
  }
  return *(*this | other) == *this;
}
const std::shared_ptr<Domain> Domain::shift(double offset) const {
  return std::make_shared<Domain>(lesser_bound() + offset,
                                  greater_bound() + offset,
                                  lesser_bound_contained(),
                                  greater_bound_contained());
}
const std::shared_ptr<Domain> Domain::scale(double factor) const {
  double center         = get_center();
  double half_range     = range() / 2.0;
  double new_half_range = half_range * std::abs(factor);
  return std::make_shared<Domain>(center - new_half_range,
                                  center + new_half_range,
                                  lesser_bound_contained(),
                                  greater_bound_contained());
}
const std::pair<double, double> Domain::calculate_transform(
    const std::shared_ptr<Domain>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Domain: The other domain to & with must not be null.");
  }
  double scale  = range() / other->range();
  double offset = other->lesser_bound() - lesser_bound() * scale;
  return {scale, offset};
}
const double Domain::transform(const std::shared_ptr<Domain>& other,
                               double                         value) const {
  if (!other) {
    throw std::invalid_argument(
        "Domain: The other to transfofrm using must not be null.");
  }
  auto transform = calculate_transform(other);
  auto scale     = transform.first;
  auto offset    = transform.second;
  return value * scale + offset;
}
bool Domain::operator==(const Domain& other) const {
  if (this == &other) return true;
  return (lesser_bound() == other.lesser_bound()) &&
         (greater_bound() == other.greater_bound()) &&
         (lesser_bound_contained() == other.lesser_bound_contained()) &&
         (greater_bound_contained() == other.greater_bound_contained());
}
bool Domain::operator!=(const Domain& other) const { return !(*this == other); }
}  // namespace domains
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::domains::Domain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::Domain)
