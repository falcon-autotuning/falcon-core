#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

BaseDiscretizer::BaseDiscretizer(double delta, std::shared_ptr<domains::Domain> delta_domain)
    : _delta(delta), _delta_domain(std::move(delta_domain)) {}

BaseDiscretizer::~BaseDiscretizer() = default;

double BaseDiscretizer::delta() const { return _delta; }
void BaseDiscretizer::set_delta(double delta) { _delta = delta; }
const std::shared_ptr<domains::Domain>& BaseDiscretizer::delta_domain() const { return _delta_domain; }

BaseDiscretizer::BaseDiscretizer() = default;

template <class Archive>
void BaseDiscretizer::serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain);
}

}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::BaseDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::BaseDiscretizer)
