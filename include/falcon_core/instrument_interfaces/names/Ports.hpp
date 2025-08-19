#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {
template <typename T>
class Ports : public generic::Song {
 public:
  using value_type     = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  Ports() = default;

  void append(const std::shared_ptr<value_type> &port) {
    _ports.push_back(port);
  }

  const container_type &get_ports() const { return _ports; }

 private:
  container_type _ports;
};
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
#ifndef SWIG
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::names::Ports<
        falcon_core::instrument_interfaces::names::InstrumentPort<
            falcon_core::physics::device_structures::BaseConnection>>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Ports<
        falcon_core::instrument_interfaces::names::InstrumentPort<
            falcon_core::physics::device_structures::BaseConnection>>)
#endif
