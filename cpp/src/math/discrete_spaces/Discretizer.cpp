#include "falcon_core/math/discrete_spaces/Discretizer.hpp"

#include <stdexcept>

#include "falcon_core/Constants.hpp"
namespace falcon_core {
namespace math {
namespace discrete_spaces {
Discretizer::Discretizer(const Discretizer& other) : generic::Song(other) {
  std::shared_lock<std::shared_timed_mutex> lock_delta(other._mu_delta,
                                                       std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_delta_domain(
      other._mu_delta_domain, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_type(other._mu_type,
                                                      std::defer_lock);
  std::lock(lock_delta, lock_delta_domain, lock_type);
  _delta        = other._delta;
  _delta_domain = other._delta_domain;
  _type         = other._type;
}
Discretizer Discretizer::operator=(const Discretizer& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_delta(other._mu_delta,
                                                               std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_delta_domain(
        other._mu_delta_domain, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_type(other._mu_type,
                                                              std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_delta(_mu_delta,
                                                         std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_delta_domain(
        _mu_delta_domain, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::lock(lock_delta,
              lock_delta_domain,
              lock_type,
              lock_other_delta,
              lock_other_delta_domain,
              lock_other_type);
    _delta        = other._delta;
    _delta_domain = other._delta_domain;
    _type         = other._type;
  }
  return *this;
}
Discretizer::Discretizer(const double&            delta,
                         const domains::DomainSP& delta_domain,
                         const Dividers&          type)
    : _delta(delta), _delta_domain(delta_domain), _type(type) {
  if (!delta_domain) {
    throw std::invalid_argument("Discretizer: The domain must not be null.");
  }
}
DiscretizerSP Discretizer::CartesianDiscretizer(const double& delta) {
  return std::make_shared<Discretizer>(
      delta, std::make_shared<domains::Domain>(-1.0, 1.0), Dividers::Cartesian);
}
DiscretizerSP Discretizer::PolarDiscretizer(const double& delta) {
  return std::make_shared<Discretizer>(
      delta,
      std::make_shared<domains::Domain>(-2.0 * falcon_core::PI,
                                        2.0 * falcon_core::PI),
      Dividers::Polar);
}

double Discretizer::delta() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_delta);
  return _delta;
}
void Discretizer::set_delta(double delta) {
  std::unique_lock<std::shared_timed_mutex> lock(_mu_delta);
  _delta = delta;
}
const domains::DomainSP& Discretizer::domain() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_delta_domain);
  return _delta_domain;
}
const bool Discretizer::is_cartesian() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type == Dividers::Cartesian;
}
const bool Discretizer::is_polar() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_type);
  return _type == Dividers::Polar;
}

Discretizer::Discretizer() = default;
bool Discretizer::operator==(const Discretizer& other) const {
  std::shared_lock<std::shared_timed_mutex> lock_other_type(other._mu_type,
                                                            std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                      std::defer_lock);
  std::lock(lock_type, lock_other_type);
  return (delta() == other.delta()) && (*domain() == *other.domain()) &&
         (_type == other._type);
}
bool Discretizer::operator!=(const Discretizer& other) const {
  return !(*this == other);
}
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::Discretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::discrete_spaces::Discretizer)
