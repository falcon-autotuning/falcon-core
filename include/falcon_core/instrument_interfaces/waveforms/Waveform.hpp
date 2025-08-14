#pragma once

#include <memory>

#include "falcon_core/Spaces.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace waveforms {

class Waveform : public generic::Song {
 public:
  Waveform(std::shared_ptr<ControlArray<double>>  control_array,
           std::shared_ptr<MeasuredArray<double>> measured_array,
           std::shared_ptr<Spaces>                spaces)
      : _control_array(std::move(control_array)),
        _measured_array(std::move(measured_array)),
        _spaces(std::move(spaces)) {}

 private:
  std::shared_ptr<ControlArray<double>>  _control_array;
  std::shared_ptr<MeasuredArray<double>> _measured_array;
  std::shared_ptr<Spaces>                _spaces;
};
}  // namespace waveforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
