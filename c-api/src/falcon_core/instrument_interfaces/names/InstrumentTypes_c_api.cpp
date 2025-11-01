#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"

#include <falcon_core/instrument_interfaces/names/InstrumentTypes.hpp>

using namespace falcon_core::instrument_interfaces::names;

StringHandle InstrumentTypes_dc_voltage_source() {
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_VOLTAGE_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_VOLTAGE_SOURCE.size());
}

StringHandle InstrumentTypes_amnmeter() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::AMNMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::AMNMETER
          .size());
}

StringHandle InstrumentTypes_magnet() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::MAGNET
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::MAGNET
          .size());
}

StringHandle InstrumentTypes_lockin() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::LOCKIN
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::LOCKIN
          .size());
}

StringHandle InstrumentTypes_voltage_source() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTAGE_SOURCE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTAGE_SOURCE
          .size());
}

StringHandle InstrumentTypes_current_source() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::CURRENT_SOURCE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::CURRENT_SOURCE
          .size());
}

StringHandle InstrumentTypes_hf_voltage_source() {
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_VOLTAGE_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_VOLTAGE_SOURCE.size());
}

StringHandle InstrumentTypes_dc_current_source() {
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_CURRENT_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_CURRENT_SOURCE.size());
}

StringHandle InstrumentTypes_hf_current_source() {
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_CURRENT_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_CURRENT_SOURCE.size());
}

StringHandle InstrumentTypes_thermometer() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::THERMOMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::THERMOMETER
          .size());
}

StringHandle InstrumentTypes_voltmeter() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTMETER
          .size());
}

StringHandle InstrumentTypes_fpga() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::FPGA.c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::FPGA.size());
}

StringHandle InstrumentTypes_clock() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::CLOCK.c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::CLOCK.size());
}

StringHandle InstrumentTypes_discrete() {
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::DISCRETE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::DISCRETE
          .size());
}
