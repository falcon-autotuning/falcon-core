#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

#include <cereal/archives/binary.hpp>

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

// Explicit instantiations for Cereal archives
template void AnalyticFunction::serialize<cereal::BinaryInputArchive>(
    cereal::BinaryInputArchive&);
template void AnalyticFunction::serialize<cereal::BinaryOutputArchive>(
    cereal::BinaryOutputArchive&);
template void AnalyticFunction::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive&);
template void AnalyticFunction::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive&);

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::AnalyticFunction)

// // Explicit instantiation of serialize for AnalyticFunction
// template void falcon_core::math::analytic_functions::AnalyticFunction::
//     serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive&);
// template void falcon_core::math::analytic_functions::AnalyticFunction::
//     serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive&);
