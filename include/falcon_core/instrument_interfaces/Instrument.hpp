#pragma once
#include <string>

namespace falcon_core {
namespace instrument_interfaces {

struct INSTRUMENT_TYPES {
  static const std::string DC_VOLTAGE_SOURCE;
  // Add other instrument types as needed
};

using Instrument = std::string;

}  // namespace instrument_interfaces
}  // namespace falcon_core
