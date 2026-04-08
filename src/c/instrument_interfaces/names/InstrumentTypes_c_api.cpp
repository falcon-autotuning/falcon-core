#include "falcon-core/instrument_interfaces/names/InstrumentTypes_c_api.h"

#include <falcon-core/instrument_interfaces/names/InstrumentTypes.hpp>

#include "falcon-core/generic/ErrorHandling_c_api.h"

using namespace falcon_core::instrument_interfaces::names;

extern "C" {
StringHandle InstrumentTypes_dc_voltage_source() {
  FALCON_C_API_BEGIN
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_VOLTAGE_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_VOLTAGE_SOURCE.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_amnmeter() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::AMNMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::AMNMETER
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_magnet() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::MAGNET
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::MAGNET
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_lockin() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::LOCKIN
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::LOCKIN
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_voltage_source() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTAGE_SOURCE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTAGE_SOURCE
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_current_source() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::CURRENT_SOURCE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::CURRENT_SOURCE
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_hf_voltage_source() {
  FALCON_C_API_BEGIN
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_VOLTAGE_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_VOLTAGE_SOURCE.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_dc_current_source() {
  FALCON_C_API_BEGIN
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_CURRENT_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::DC_CURRENT_SOURCE.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_hf_current_source() {
  FALCON_C_API_BEGIN
  return String_create(falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_CURRENT_SOURCE.c_str(),
                       falcon_core::instrument_interfaces::names::
                           InstrumentTypes::HF_CURRENT_SOURCE.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_thermometer() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::THERMOMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::THERMOMETER
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_voltmeter() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTMETER
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::VOLTMETER
          .size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_fpga() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::FPGA.c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::FPGA.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_clock() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::CLOCK.c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::CLOCK.size());
  FALCON_C_API_END(nullptr)
}

StringHandle InstrumentTypes_discrete() {
  FALCON_C_API_BEGIN
  return String_create(
      falcon_core::instrument_interfaces::names::InstrumentTypes::DISCRETE
          .c_str(),
      falcon_core::instrument_interfaces::names::InstrumentTypes::DISCRETE
          .size());
  FALCON_C_API_END(nullptr)
}
}
