%module(directors="1") falcon_core

%pythoncode %{
import sys
import importlib.util

# This code runs when the falcon_core module is imported.
# It creates the desired submodule structure in memory.
_pkg_name = __name__

# Create falcon_core.generic
_generic_spec = importlib.util.spec_from_loader(f'{_pkg_name}.generic', loader=None)
generic = importlib.util.module_from_spec(_generic_spec)
sys.modules[generic.__name__] = generic
setattr(sys.modules[_pkg_name], 'generic', generic)

# Create falcon_core.communications
_comm_spec = importlib.util.spec_from_loader(f'{_pkg_name}.communications', loader=None)
communications = importlib.util.module_from_spec(_comm_spec)
sys.modules[communications.__name__] = communications
setattr(sys.modules[_pkg_name], 'communications', communications)

# Create falcon_core.physics
_physics_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics', loader=None)
physics = importlib.util.module_from_spec(_physics_spec)
sys.modules[physics.__name__] = physics
setattr(sys.modules[_pkg_name], 'physics', physics)

# Create falcon_core.physics.units
_units_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.units', loader=None)
physics.units = importlib.util.module_from_spec(_units_spec)
sys.modules[physics.units.__name__] = physics.units

# Create falcon_core.math
_math_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math', loader=None)
math = importlib.util.module_from_spec(_math_spec)
sys.modules[math.__name__] = math
setattr(sys.modules[_pkg_name], 'math', math)

# Create falcon_core.math.domains
_domains_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.domains', loader=None)
math.domains = importlib.util.module_from_spec(_domains_spec)
sys.modules[math.domains.__name__] = math.domains

# Create falcon_core.math.arrays
_arrays_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.arrays', loader=None)
math.arrays = importlib.util.module_from_spec(_arrays_spec)
sys.modules[math.arrays.__name__] = math.arrays

# Create falcon_core.math.axes
_axes_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.axes', loader=None)
math.axes = importlib.util.module_from_spec(_axes_spec)
sys.modules[math.axes.__name__] = math.axes

# Create falcon_core.physics.device_structures
_devices_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.device_structures', loader=None)
physics.device_structures = importlib.util.module_from_spec(_devices_spec)
sys.modules[physics.device_structures.__name__] = physics.device_structures

# Create falcon_core.physics.config
_config_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.config', loader=None)
physics.config = importlib.util.module_from_spec(_config_spec)
sys.modules[physics.config.__name__] = physics.config

# Create falcon_core.physics.config.core
_config_core_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.config.core', loader=None)
physics.config.core = importlib.util.module_from_spec(_config_core_spec)
sys.modules[physics.config.core.__name__] = physics.config.core

# Create falcon_core.instrument_interfaces
_instruments_spec = importlib.util.spec_from_loader(f'{_pkg_name}.instrument_interfaces', loader=None)
instrument_interfaces = importlib.util.module_from_spec(_instruments_spec)
sys.modules[instrument_interfaces.__name__] = instrument_interfaces
setattr(sys.modules[_pkg_name], 'instrument_interfaces', instrument_interfaces)

# Create falcon_core.instrument_interfaces.names
_instruments_names_spec = importlib.util.spec_from_loader(f'{_pkg_name}.instrument_interfaces.names', loader=None)
instrument_interfaces.names = importlib.util.module_from_spec(_instruments_names_spec)
sys.modules[instrument_interfaces.names.__name__] = instrument_interfaces.names

# Create falcon_core.autotuner_interfaces
_autotuner_spec = importlib.util.spec_from_loader(f'{_pkg_name}.autotuner_interfaces', loader=None)
autotuner_interfaces = importlib.util.module_from_spec(_autotuner_spec)
sys.modules[autotuner_interfaces.__name__] = autotuner_interfaces
setattr(sys.modules[_pkg_name], 'autotuner_interfaces', autotuner_interfaces)

# Create falcon_core.autotuner_interfaces.contexts
_contexts_spec = importlib.util.spec_from_loader(f'{_pkg_name}.autotuner_interfaces.contexts', loader=None)
autotuner_interfaces.contexts = importlib.util.module_from_spec(_contexts_spec)
sys.modules[autotuner_interfaces.contexts.__name__] = autotuner_interfaces.contexts

# Create falcon_core.autotuner_interfaces.interpretations
_interpretations_spec = importlib.util.spec_from_loader(f'{_pkg_name}.autotuner_interfaces.interpretations', loader=None)
autotuner_interfaces.interpretations = importlib.util.module_from_spec(_interpretations_spec)
sys.modules[autotuner_interfaces.interpretations.__name__] = autotuner_interfaces.interpretations

# Create falcon_core.math.functions
_functions_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.functions', loader=None)
math.functions = importlib.util.module_from_spec(_functions_spec)
sys.modules[math.functions.__name__] = math.functions

# Create falcon_core.physics.transforms
_transforms_spec = importlib.util.spec_from_loader(f'{_pkg_name}.physics.transforms', loader=None)
physics.transforms = importlib.util.module_from_spec(_transforms_spec)
sys.modules[physics.transforms.__name__] = physics.transforms

# Create falcon_core.math.discretizers
_discretizers_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.discretizers', loader=None)
math.discretizers = importlib.util.module_from_spec(_discretizers_spec)
sys.modules[math.discretizers.__name__] = math.discretizers

# Create falcon_core.math.waveform
_waveform_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.waveform', loader=None)
math.waveform = importlib.util.module_from_spec(_waveform_spec)
sys.modules[math.waveform.__name__] = math.waveform

# Create falcon_core.math.labelled_arrays
_labelled_arrays_spec = importlib.util.spec_from_loader(f'{_pkg_name}.math.labelled_arrays', loader=None)
math.labelled_arrays = importlib.util.module_from_spec(_labelled_arrays_spec)
sys.modules[math.labelled_arrays.__name__] = math.labelled_arrays
%}

%{
#include "falcon_core/Jsonable.hpp"
#include "falcon_core/Time.hpp"
#include <string>
#include <cstddef>
#include <stdexcept>
// C++ headers for units are included via units.i
%}

// Include the Eigen typemaps for NumPy conversion
%include "eigen.i"

// Process the header files
%include "falcon_core/Jsonable.hpp"
%include "falcon_core/Time.hpp"

// Include the units definitions
%include "units.i"

// Include the math definitions
%include "math.i"

// Include the device definitions
%include "devices.i"

// Include the context definitions
%include "contexts.i"

// Include the transform definitions
%include "transforms.i"

// Include the waveform definitions
%include "waveforms.i"

// Typemap for nlohmann::json to a Python string.
// The user code in python will be responsible for json.loads()
%typemap(out) nlohmann::json {
  $result = PyUnicode_FromString($1.dump().c_str());
}

// Enable directors for Jsonable to allow subclassing in Python
%feature("director") falcon_core::Jsonable;

// Add python-like special methods to Jsonable
%extend falcon_core::Jsonable {
    std::string __str__() {
        return self->to_json_string();
    }
    size_t __hash__() {
        return self->hash();
    }
}

%pythoncode %{
# Move the wrapped C++ classes into their respective submodules
generic.Jsonable = Jsonable
del Jsonable

communications.Time = Time
del Time

physics.units.Dimension = Dimension
del Dimension
physics.units.Prefix = Prefix
del Prefix
physics.units.Sign = Sign
del Sign
physics.units.SymbolUnit = SymbolUnit
del SymbolUnit
physics.units.Unit = Unit
del Unit

# Move math classes
math.QuantityDouble = QuantityDouble
del QuantityDouble
generic.OneToOneMappingStringString = OneToOneMappingStringString # Mapped to generic for now
del OneToOneMappingStringString
math.domains.Domain = Domain
del Domain
math.domains.LabelledDomain = LabelledDomainBC
del LabelledDomainBC
math.domains.CoupledLabelledDomain = CoupledLabelledDomainBC
del CoupledLabelledDomainBC

# Move array classes
math.arrays.BaseArray = BaseArrayDouble
del BaseArrayDouble
math.arrays.ControlArray = ControlArrayDouble
del ControlArrayDouble
math.arrays.MeasuredArray = MeasuredArrayDouble
del MeasuredArrayDouble

# Move labelled array classes
math.labelled_arrays.LabelledControlArray1D = LabelledControlArray1D
del LabelledControlArray1D
math.labelled_arrays.BaseLabelledArrays = BaseLabelledArraysLCA1D
del BaseLabelledArraysLCA1D

# Move axes classes
math.axes.AxesDomain = AxesDomain
del AxesDomain
math.axes.Axes = AxesMeasurementContext
del AxesMeasurementContext

# Move device classes
physics.device_structures.NameBaseInt = NameBaseInt
del NameBaseInt
physics.device_structures.NameBaseString = NameBaseString
del NameBaseString
physics.device_structures.Channel = Channel
del Channel
physics.device_structures.BaseConnection = BaseConnection
del BaseConnection
physics.device_structures.Gate = Gate
del Gate
physics.device_structures.Ohmic = Ohmic
del Ohmic
physics.device_structures.Gates = Gates
del Gates
physics.device_structures.Impedance = Impedance
del Impedance
physics.device_structures.Impedances = Impedances
del Impedances
physics.device_structures.GateRelations = GateRelations
del GateRelations
physics.device_structures.Ohmics = Ohmics
del Ohmics

# Move config classes
physics.config.core.StandardConfigConnections = StandardConfigConnections
del StandardConfigConnections
physics.config.Loader = Loader
del Loader

# Move instrument and context classes
instrument_interfaces.names.InstrumentPort = InstrumentPortGate
del InstrumentPortGate
instrument_interfaces.names.Ports = PortsGate
del PortsGate
autotuner_interfaces.contexts.AcquisitionContext = AcquisitionContext
del AcquisitionContext
autotuner_interfaces.contexts.MeasurementContext = MeasurementContext
del MeasurementContext
autotuner_interfaces.interpretations.InterpretationContext = InterpretationContext
del InterpretationContext
autotuner_interfaces.interpretations.InterpretationContainer = InterpretationContainerControlArray
del InterpretationContainerControlArray

# Move transform classes
math.functions.AnalyticFunction = AnalyticFunction
del AnalyticFunction
physics.transforms.PortTransform = PortTransform
del PortTransform
physics.transforms.PortTransforms = PortTransforms
del PortTransforms

# Move waveform classes
math.discretizers.BaseDiscretizer = BaseDiscretizer
del BaseDiscretizer
math.waveform.Spaces = Spaces
del Spaces
math.waveform.Waveform = Waveform
del Waveform
%}
