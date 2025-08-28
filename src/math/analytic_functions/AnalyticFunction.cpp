#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

AnalyticFunction::AnalyticFunction() = default;
AnalyticFunction::AnalyticFunction(const std::string& name) : _name(name) {}

std::string AnalyticFunction::name() const { return _name; }
void AnalyticFunction::set_name(const std::string& name) { _name = name; }

template <class Archive>
void AnalyticFunction::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _name);
}

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::AnalyticFunction)
