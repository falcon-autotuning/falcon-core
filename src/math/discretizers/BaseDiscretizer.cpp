#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

#include <cereal/archives/binary.hpp>

namespace falcon_core::math::discretizers {

BaseDiscretizer::BaseDiscretizer(
    const double &delta, const std::shared_ptr<domains::Domain> &delta_domain)
    : _delta(delta), _delta_domain(std::move(delta_domain)) {}

double BaseDiscretizer::delta() const { return _delta; }
void   BaseDiscretizer::set_delta(double delta) { _delta = delta; }
const std::shared_ptr<domains::Domain> &BaseDiscretizer::domain() const {
  return _delta_domain;
}

BaseDiscretizer::BaseDiscretizer() = default;

}  // namespace falcon_core::math::discretizers

CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::BaseDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::BaseDiscretizer)
