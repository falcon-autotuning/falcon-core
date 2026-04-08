#include "falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include <stdexcept>

#include "falcon-core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon-core/math/AnalyticFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {
PortTransform::PortTransform(const PortTransform& other)
    : AnalyticFunction(other) {
  std::unique_lock<std::shared_timed_mutex> lock_o(_mu_port);
  if (!other.port()) {
    throw std::invalid_argument(
        "PortTransform copy constructor: Other PortTransform contains null "
        "shared pointer.");
  }
  _port = std::make_shared<names::InstrumentPort>(*other.port());
}
PortTransform& PortTransform::operator=(const PortTransform& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_o(_mu_port);
    if (!other.port()) {
      throw std::invalid_argument(
          "PortTransform copy constructor: Other PortTransform contains null "
          "shared pointer.");
    }
    _port = std::make_shared<names::InstrumentPort>(*other.port());
    math::AnalyticFunction::operator=(other);
  }
  return *this;
}
PortTransform::PortTransform(const names::InstrumentPortSP&  port,
                             const math::AnalyticFunctionSP& transform)
    : AnalyticFunction(transform ? *transform : *Identity()), _port(port) {
  if (!port || !transform) {
    throw std::invalid_argument(
        "InstrumentPort: The transform must not be null.");
  }
}

PortTransform::PortTransform() : AnalyticFunction(), _port(nullptr) {}
PortTransformSP PortTransform::ConstantTransform(
    const names::InstrumentPortSP& port, const double& value) {
  if (!port) {
    throw std::invalid_argument("InstrumentPort: The port must not be null.");
  }
  return std::make_shared<PortTransform>(
      port, math::AnalyticFunction::Constant(value));
}
PortTransformSP PortTransform::IdentityTransform(
    const names::InstrumentPortSP& port) {
  if (!port) {
    throw std::invalid_argument("InstrumentPort: The port must not be null.");
  }
  return std::make_shared<PortTransform>(port,
                                         math::AnalyticFunction::Identity());
}

const names::InstrumentPortSP PortTransform::port() const {
  std::shared_lock<std::shared_timed_mutex> lock_port(_mu_port);
  return _port;
}
bool PortTransform::operator==(const PortTransform& other) const {
  if (this == &other) return true;
  return (*port() == *other.port()) &&
         math::AnalyticFunction::operator==(other);
}
bool PortTransform::operator!=(const PortTransform& other) const {
  return !(*this == other);
}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
