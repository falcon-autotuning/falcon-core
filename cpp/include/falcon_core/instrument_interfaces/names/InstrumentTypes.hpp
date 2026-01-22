#pragma once
#include "falcon_core/export.h"
#include "falcon_core/instrument_interfaces/names/Instrument.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {
struct FALCON_CORE_CPP_API InstrumentTypes {
  static const Instrument DC_VOLTAGE_SOURCE;
  static const Instrument AMNMETER;
  static const Instrument MAGNET;
  static const Instrument LOCKIN;
  static const Instrument VOLTAGE_SOURCE;
  static const Instrument CURRENT_SOURCE;
  static const Instrument HF_VOLTAGE_SOURCE;
  static const Instrument DC_CURRENT_SOURCE;
  static const Instrument HF_CURRENT_SOURCE;
  static const Instrument THERMOMETER;
  static const Instrument VOLTMETER;
  static const Instrument FPGA;
  static const Instrument CLOCK;
  static const Instrument DISCRETE;
};
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
