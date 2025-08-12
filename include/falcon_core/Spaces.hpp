#pragma once

#include "falcon_core/Axes.hpp"
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/MeasurementContext.hpp"
#include <memory>
#include <vector>

namespace falcon_core {

class Spaces : public Jsonable {
public:
  using AxesType = Axes<MeasurementContext>;
  using container_type = std::vector<std::shared_ptr<AxesType>>;

  Spaces() = default;

  void append(const std::shared_ptr<AxesType> &space) {
    _spaces.push_back(space);
  }

  const container_type &get_spaces() const { return _spaces; }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.math.waveform.spaces", "Spaces");
    nlohmann::json spaces_json = nlohmann::json::array();
    for (const auto &s : _spaces) {
      spaces_json.push_back(s->to_json());
    }
    j["_spaces"] = spaces_json;
    return j;
  }

  size_t hash() const override {
    size_t seed = _spaces.size();
    for (const auto &s : _spaces) {
      seed ^= s->hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }

private:
  container_type _spaces;
};

} // namespace falcon_core
