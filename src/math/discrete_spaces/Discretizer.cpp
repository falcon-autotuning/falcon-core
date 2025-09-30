#include "falcon_core/math/discrete_spaces/Discretizer.hpp"

#include <stdexcept>

#include "falcon_core/Constants.hpp"
namespace falcon_core::math::discrete_spaces {

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

double Discretizer::delta() const { return _delta; }
void   Discretizer::set_delta(double delta) { _delta = delta; }
const domains::DomainSP& Discretizer::domain() const { return _delta_domain; }
const bool               Discretizer::is_cartesian() const {
  return _type == Dividers::Cartesian;
}
const bool Discretizer::is_polar() const { return _type == Dividers::Polar; }

Discretizer::Discretizer() = default;
bool Discretizer::operator==(const Discretizer& other) const {
  return (delta() == other.delta()) && (*domain() == *other.domain()) &&
         (_type == other._type);
}
bool Discretizer::operator!=(const Discretizer& other) const {
  return !(*this == other);
}
}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::Discretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::discrete_spaces::Discretizer)
