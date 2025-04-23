"""Starts up the falcon_core package."""

from .generic import Enum


class INSTRUMENT_TYPES(Enum):
    """Instrument types."""

    DC_VOLTAGE_SOURCE = "dc_voltage_source"
    AMNMETER = "amnmeter"
    MAGNET = "magnet"
    LOCKIN = "lockin"
    VOLTAGE_SOURCE = "voltage_source"
    CURRENT_SOURCE = "current_source"
    HF_VOLTAGE_SOURCE = "hf_voltage_source"
    DC_CURRENT_SOURCE = "dc_current_source"
    HF_CURRENT_SOURCE = "hf_current_source"
    THERMOMETER = "thermometer"
    VOLTMETER = "voltmeter"
    FPGA = "fpga"
    CLOCK = "clock"
    DISCRETE = "discrete"
