#pragma once

#include "falcon_core/Jsonable.hpp"
#include <memory>
#include <vector>

namespace falcon_core {

template <typename T> class Ports : public Jsonable {
public:
  using value_type = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  Ports() = default;

  void append(const std::shared_ptr<value_type> &port) {
    _ports.push_back(port);
  }

  const container_type &get_ports() const { return _ports; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.instrument_interfaces.names.ports", "Ports");
    nlohmann::json ports_json = nlohmann::json::array();
    for (const auto &port : _ports) {
      ports_json.push_back(port->to_json());
    }
    j["_ports"] = ports_json;
    return j;
  }

  size_t hash() const override {
    size_t seed = _ports.size();
    for (const auto &port : _ports) {
      seed ^= port->hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }

private:
  container_type _ports;
};

} // namespace falcon_core
