#pragma once

#include "falcon_core/generic/Jsonable.hpp"
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>

namespace falcon_core {

template <typename T> class BaseConnections : public Jsonable {
public:
  using value_type = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  BaseConnections() = default;

  void append(const std::shared_ptr<value_type> &connection) {
    _connections.push_back(connection);
  }

  size_t index(const std::shared_ptr<value_type> &value) const {
    auto it = std::find(_connections.begin(), _connections.end(), value);
    if (it == _connections.end()) {
      throw std::out_of_range("Value not found in BaseConnections");
    }
    return std::distance(_connections.begin(), it);
  }

  const container_type &get_connections() const { return _connections; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.device_structures.base_connection",
                 "BaseConnections");
    nlohmann::json connections_json = nlohmann::json::array();
    for (const auto &conn : _connections) {
      connections_json.push_back(conn->to_json());
    }
    j["_connections"] = connections_json;
    return j;
  }

  size_t hash() const override {
    size_t seed = _connections.size();
    for (const auto &conn : _connections) {
      seed ^= conn->hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }

private:
  container_type _connections;
};

} // namespace falcon_core
