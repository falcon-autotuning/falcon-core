#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include <cereal/archives/binary.hpp>

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

PortTransform::PortTransform(
    std::shared_ptr<math::analytic_functions::AnalyticFunction> function)
    : _function(std::move(function)) {}

PortTransform::PortTransform() : _function(nullptr) {}

double PortTransform::apply(double value) const {
  if (!_function) return value;
  return _function->evaluate(value);
}

template <class Archive>
void PortTransform::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _function);
}
// Explicit instantiations for Cereal archives
template void PortTransform::serialize<cereal::BinaryInputArchive>(
    cereal::BinaryInputArchive&);
template void PortTransform::serialize<cereal::BinaryOutputArchive>(
    cereal::BinaryOutputArchive&);
template void PortTransform::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive&);
template void PortTransform::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive&);
}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
