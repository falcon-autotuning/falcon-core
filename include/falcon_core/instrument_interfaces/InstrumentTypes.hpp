#pragma once
#include "falcon_core/instrument_interfaces/Instrument.hpp"

namespace falcon_core {
namespace instrument_interfaces {
struct InstrumentTypes {
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
}  // namespace instrument_interfaces
}  // namespace falcon_core
