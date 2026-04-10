#include "falcon-core/instrument_interfaces/names/InstrumentTypes.hpp"

#include "falcon-core/export.h"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {
FALCON_CORE_CPP_API const Instrument InstrumentTypes::DC_VOLTAGE_SOURCE{
    "dc_voltage_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::AMNMETER{"amnmeter"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::MAGNET{"magnet"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::LOCKIN{"lockin"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::VOLTAGE_SOURCE{
    "voltage_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::CURRENT_SOURCE{
    "current_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::HF_VOLTAGE_SOURCE{
    "hf_voltage_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::DC_CURRENT_SOURCE{
    "dc_current_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::HF_CURRENT_SOURCE{
    "hf_current_source"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::THERMOMETER{
    "thermometer"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::VOLTMETER{"voltmeter"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::FPGA{"fpga"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::CLOCK{"clock"};
FALCON_CORE_CPP_API const Instrument InstrumentTypes::DISCRETE{"discrete"};
}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core
