#include "falcon_core/math/analytic_functions/Identity.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

Identity::Identity() = default;

double Identity::evaluate(double x) const { return x; }

template <class Archive>
void Identity::serialize(Archive& ar) {
  ar(cereal::base_class<AnalyticFunction>(this));
}

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::Identity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::analytic_functions::Identity)
