#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/PortTransform.hpp"
#include <memory>
#include <vector>

namespace falcon_core {

class PortTransforms : public Jsonable {
public:
  using value_type = PortTransform;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  PortTransforms() = default;

  void append(const std::shared_ptr<value_type> &transform) {
    _transforms.push_back(transform);
  }

  const container_type &get_transforms() const { return _transforms; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.physics.transforms.port_transforms",
                 "PortTransforms");
    nlohmann::json transforms_json = nlohmann::json::array();
    for (const auto &t : _transforms) {
      transforms_json.push_back(t->to_json());
    }
    j["_transforms"] = transforms_json;
    return j;
  }

  size_t hash() const override {
    size_t seed = _transforms.size();
    for (const auto &t : _transforms) {
      seed ^= t->hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }

private:
  container_type _transforms;
};

} // namespace falcon_core
