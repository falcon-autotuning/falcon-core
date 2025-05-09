"""All of the available instuemtn types for falcon."""

from .instrument import Instrument


class INSTRUMENT_TYPES:
    """Instrument types."""

    DC_VOLTAGE_SOURCE = Instrument("dc_voltage_source")
    AMNMETER = Instrument("amnmeter")
    MAGNET = Instrument("magnet")
    LOCKIN = Instrument("lockin")
    VOLTAGE_SOURCE = Instrument("voltage_source")
    CURRENT_SOURCE = Instrument("current_source")
    HF_VOLTAGE_SOURCE = Instrument("hf_voltage_source")
    DC_CURRENT_SOURCE = Instrument("dc_current_source")
    HF_CURRENT_SOURCE = Instrument("hf_current_source")
    THERMOMETER = Instrument("thermometer")
    VOLTMETER = Instrument("voltmeter")
    FPGA = Instrument("fpga")
    CLOCK = Instrument("clock")
    DISCRETE = Instrument("discrete")
