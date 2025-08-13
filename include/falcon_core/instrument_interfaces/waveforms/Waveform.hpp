#pragma once

#include "falcon_core/ControlArray.hpp"
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/MeasuredArray.hpp"
#include "falcon_core/Spaces.hpp"
#include <memory>

namespace falcon_core {

class Waveform : public Jsonable {
public:
  Waveform(std::shared_ptr<ControlArray<double>> control_array,
           std::shared_ptr<MeasuredArray<double>> measured_array,
           std::shared_ptr<Spaces> spaces)
      : _control_array(std::move(control_array)),
        _measured_array(std::move(measured_array)), _spaces(std::move(spaces)) {
  }

  nlohmann::json to_json() const override {
    nlohmann::json j;
    add_metadata(j, "falcon_core.math.waveform.waveform", "Waveform");
    j["_control_array"] = _control_array->to_json();
    j["_measured_array"] = _measured_array->to_json();
    j["_spaces"] = _spaces->to_json();
    return j;
  }

  size_t hash() const override {
    size_t h1 = _control_array ? _control_array->hash() : 0;
    size_t h2 = _measured_array ? _measured_array->hash() : 0;
    size_t h3 = _spaces ? _spaces->hash() : 0;
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }

private:
  std::shared_ptr<ControlArray<double>> _control_array;
  std::shared_ptr<MeasuredArray<double>> _measured_array;
  std::shared_ptr<Spaces> _spaces;
};

} // namespace falcon_core
