# C API Reference

This section contains the complete C API documentation for Falcon Core, providing C bindings for the C++ core library.

## Quick Navigation

- **[Classes](classes.md)** - List of all C API structures and types
- **[Class Hierarchy](hierarchy.md)** - Type hierarchy
- **[Files](files.md)** - List of all C API header files

## API Overview

The C API provides C-compatible wrappers for the C++ core functionality, enabling integration with C-based applications and other language bindings.

### Core Data Types

#### Generic Containers
- **Error Handling** - [ErrorHandling_c_api.h](ErrorHandling__c__api_8h.md)
- **String** - [String_c_api.h](String__c__api_8h.md) / [string struct](structstring.md)
- **Lists** - Various list types for different data types:
  - [ListDouble](ListDouble__c__api_8h.md)
  - [ListInt](ListInt__c__api_8h.md)
  - [ListString](ListString__c__api_8h.md)
  - [ListBool](ListBool__c__api_8h.md)
- **Maps** - Key-value map types:
  - [MapStringString](MapStringString__c__api_8h.md)
  - [MapStringDouble](MapStringDouble__c__api_8h.md)
  - [MapStringBool](MapStringBool__c__api_8h.md)
- **Pairs** - Pair types for various combinations:
  - [PairStringString](PairStringString__c__api_8h.md)
  - [PairDoubleDouble](PairDoubleDouble__c__api_8h.md)
  - [PairIntInt](PairIntInt__c__api_8h.md)
- **Arrays** - [FArrayDouble](FArrayDouble__c__api_8h.md), [FArrayInt](FArrayInt__c__api_8h.md)

### Autotuner Interfaces

#### Contexts
- **[AcquisitionContext](AcquisitionContext__c__api_8h.md)** - Acquisition context C API
  - [ListAcquisitionContext](ListAcquisitionContext__c__api_8h.md)
- **[MeasurementContext](MeasurementContext__c__api_8h.md)** - Measurement context C API
  - [ListMeasurementContext](ListMeasurementContext__c__api_8h.md)
  - [AxesMeasurementContext](AxesMeasurementContext__c__api_8h.md)

#### Interpretations
- **[InterpretationContext](InterpretationContext__c__api_8h.md)** - Interpretation context
  - [ListInterpretationContext](ListInterpretationContext__c__api_8h.md)
  - [PairInterpretationContextDouble](PairInterpretationContextDouble__c__api_8h.md)
  - [PairInterpretationContextQuantity](PairInterpretationContextQuantity__c__api_8h.md)
  - [PairInterpretationContextString](PairInterpretationContextString__c__api_8h.md)
- **Interpretation Containers**:
  - [InterpretationContainerDouble](InterpretationContainerDouble__c__api_8h.md)
  - [InterpretationContainerQuantity](InterpretationContainerQuantity__c__api_8h.md)
  - [InterpretationContainerString](InterpretationContainerString__c__api_8h.md)

#### Names
- **[Channel](Channel__c__api_8h.md)** - Channel naming
  - [ListChannel](ListChannel__c__api_8h.md)
- **[Channels](Channels__c__api_8h.md)** - Channel collections
- **[Gname](Gname__c__api_8h.md)** - Gate naming
  - [ListGname](ListGname__c__api_8h.md)

### Communications

#### Messages
- **[MeasurementRequest](MeasurementRequest__c__api_8h.md)** - Measurement request messages
- **[MeasurementResponse](MeasurementResponse__c__api_8h.md)** - Measurement response messages
  - [PairMeasurementResponseMeasurementRequest](PairMeasurementResponseMeasurementRequest__c__api_8h.md)
- **[StandardRequest](StandardRequest__c__api_8h.md)** - Standard request messages
- **[StandardResponse](StandardResponse__c__api_8h.md)** - Standard response messages
- **[VoltageStatesResponse](VoltageStatesResponse__c__api_8h.md)** - Voltage state responses

#### Data Storage
- **[HDF5Data](HDF5Data__c__api_8h.md)** - HDF5 data handling C API
- **[Time](Time__c__api_8h.md)** - Time utilities

#### Voltage States
- **[DeviceVoltageState](DeviceVoltageState__c__api_8h.md)** - Single device voltage state
  - [ListDeviceVoltageState](ListDeviceVoltageState__c__api_8h.md)
- **[DeviceVoltageStates](DeviceVoltageStates__c__api_8h.md)** - Multiple device voltage states

### Instrument Interfaces

- **[Waveform](Waveform__c__api_8h.md)** - Waveform data
  - [ListWaveform](ListWaveform__c__api_8h.md)
- **[InstrumentPort](InstrumentPort__c__api_8h.md)** - Instrument port definitions
  - [ListInstrumentPort](ListInstrumentPort__c__api_8h.md)
  - [AxesInstrumentPort](AxesInstrumentPort__c__api_8h.md)
- **[Ports](Ports__c__api_8h.md)** - Port collections
- **[InstrumentTypes](InstrumentTypes__c__api_8h.md)** - Instrument type definitions
- **[PortTransform](PortTransform__c__api_8h.md)** - Port transformations
  - [ListPortTransform](ListPortTransform__c__api_8h.md)
- **[PortTransforms](PortTransforms__c__api_8h.md)** - Port transformation collections

### Mathematics

#### Core Math Types
- **[Quantity](Quantity__c__api_8h.md)** - Physical quantities with units
  - [ListQuantity](ListQuantity__c__api_8h.md)
  - [PairQuantityQuantity](PairQuantityQuantity__c__api_8h.md)
- **[Point](Point__c__api_8h.md)** - Point in space
- **[Vector](Vector__c__api_8h.md)** - Vector operations
- **[AnalyticFunction](AnalyticFunction__c__api_8h.md)** - Analytic functions
- **[Sign](Sign__c__api_8h.md)** - Sign utilities
- **[UnitSpace](UnitSpace__c__api_8h.md)** - Unit space definitions

#### Axes Types
- **[AxesDouble](AxesDouble__c__api_8h.md)** - Axes for double values
- **[AxesInt](AxesInt__c__api_8h.md)** - Axes for integer values
- **[AxesControlArray](AxesControlArray__c__api_8h.md)** - Axes for control arrays
- **[AxesControlArray1D](AxesControlArray1D__c__api_8h.md)** - Axes for 1D control arrays
- **[AxesLabelledControlArray](AxesLabelledControlArray__c__api_8h.md)** - Axes for labelled control arrays
- **[AxesLabelledControlArray1D](AxesLabelledControlArray1D__c__api_8h.md)** - Axes for 1D labelled control arrays
- **[AxesLabelledMeasuredArray](AxesLabelledMeasuredArray__c__api_8h.md)** - Axes for labelled measured arrays
- **[AxesLabelledMeasuredArray1D](AxesLabelledMeasuredArray1D__c__api_8h.md)** - Axes for 1D labelled measured arrays

#### Array Types
- **Control Arrays**:
  - [ControlArray](ControlArray__c__api_8h.md) - Multi-dimensional control arrays
  - [ControlArray1D](ControlArray1D__c__api_8h.md) - 1D control arrays
  - [LabelledControlArray](LabelledControlArray__c__api_8h.md) - Labelled control arrays
  - [LabelledControlArray1D](LabelledControlArray1D__c__api_8h.md) - 1D labelled control arrays
  - List types: [ListControlArray](ListControlArray__c__api_8h.md), [ListControlArray1D](ListControlArray1D__c__api_8h.md), etc.

- **Measured Arrays**:
  - [MeasuredArray](MeasuredArray__c__api_8h.md) - Multi-dimensional measured arrays
  - [MeasuredArray1D](MeasuredArray1D__c__api_8h.md) - 1D measured arrays
  - [LabelledMeasuredArray](LabelledMeasuredArray__c__api_8h.md) - Labelled measured arrays
  - [LabelledMeasuredArray1D](LabelledMeasuredArray1D__c__api_8h.md) - 1D labelled measured arrays
  - List types: [ListLabelledMeasuredArray](ListLabelledMeasuredArray__c__api_8h.md), [ListLabelledMeasuredArray1D](ListLabelledMeasuredArray1D__c__api_8h.md)

- **Labelled Arrays Utilities**:
  - [LabelledArraysLabelledControlArray](LabelledArraysLabelledControlArray__c__api_8h.md)
  - [LabelledArraysLabelledControlArray1D](LabelledArraysLabelledControlArray1D__c__api_8h.md)
  - [LabelledArraysLabelledMeasuredArray](LabelledArraysLabelledMeasuredArray__c__api_8h.md)
  - [LabelledArraysLabelledMeasuredArray1D](LabelledArraysLabelledMeasuredArray1D__c__api_8h.md)

- **[IncreasingAlignment](IncreasingAlignment__c__api_8h.md)** - Increasing alignment utilities

#### Discrete Spaces
- **[DiscreteSpace](DiscreteSpace__c__api_8h.md)** - Discrete space operations
- **[Discretizer](Discretizer__c__api_8h.md)** - Space discretization
  - [ListDiscretizer](ListDiscretizer__c__api_8h.md)
  - [AxesDiscretizer](AxesDiscretizer__c__api_8h.md)

#### Domains
- **[Domain](Domain__c__api_8h.md)** - Domain definitions
- **[LabelledDomain](LabelledDomain__c__api_8h.md)** - Labelled domains
  - [ListLabelledDomain](ListLabelledDomain__c__api_8h.md)
- **[CoupledLabelledDomain](CoupledLabelledDomain__c__api_8h.md)** - Coupled labelled domains
  - [ListCoupledLabelledDomain](ListCoupledLabelledDomain__c__api_8h.md)
  - [AxesCoupledLabelledDomain](AxesCoupledLabelledDomain__c__api_8h.md)

### Physics

#### Configuration
- **[Config](Config__c__api_8h.md)** - Device configuration
- **[Loader](Loader__c__api_8h.md)** - Configuration loader
- **[Group](Group__c__api_8h.md)** - Gate groups
  - [ListGroup](ListGroup__c__api_8h.md)
- **[Adjacency](Adjacency__c__api_8h.md)** - Gate adjacency information
- **[VoltageConstraints](VoltageConstraints__c__api_8h.md)** - Voltage constraints

#### Geometries
- **[GateGeometryArray1D](GateGeometryArray1D__c__api_8h.md)** - 1D gate geometry arrays
- **[DotGateWithNeighbors](DotGateWithNeighbors__c__api_8h.md)** - Dot gate with neighbor information
  - [ListDotGateWithNeighbors](ListDotGateWithNeighbors__c__api_8h.md)
- **[DotGatesWithNeighbors](DotGatesWithNeighbors__c__api_8h.md)** - Collection of dot gates with neighbors
- **[LeftReservoirWithImplantedOhmic](LeftReservoirWithImplantedOhmic__c__api_8h.md)** - Left reservoir geometry
- **[RightReservoirWithImplantedOhmic](RightReservoirWithImplantedOhmic__c__api_8h.md)** - Right reservoir geometry

#### Device Structures
- **[Connection](Connection__c__api_8h.md)** - Device connections
  - [ListConnection](ListConnection__c__api_8h.md)
  - [PairConnectionDouble](PairConnectionDouble__c__api_8h.md)
  - [PairConnectionQuantity](PairConnectionQuantity__c__api_8h.md)
  - [PairConnectionConnections](PairConnectionConnections__c__api_8h.md)
- **[Connections](Connections__c__api_8h.md)** - Connection collections
  - [ListConnections](ListConnections__c__api_8h.md)
  - [MapChannelConnections](MapChannelConnections__c__api_8h.md)
  - [PairChannelConnections](PairChannelConnections__c__api_8h.md)
- **[GateRelations](GateRelations__c__api_8h.md)** - Gate relationship definitions
- **[Impedance](Impedance__c__api_8h.md)** - Impedance values
  - [ListImpedance](ListImpedance__c__api_8h.md)
- **[Impedances](Impedances__c__api_8h.md)** - Impedance collections

#### Units
- **[SymbolUnit](SymbolUnit__c__api_8h.md)** - Symbol-based unit system

### Utility Macros

The C API includes several utility macro headers for common operations:

- **[CerealMacro_c_api.h](CerealMacro__c__api_8h.md)** - Serialization macros
- **[CopyMacro_c_api.h](CopyMacro__c__api_8h.md)** - Copy operation macros
- **[DestroyMacro_c_api.h](DestroyMacro__c__api_8h.md)** - Destruction/cleanup macros
- **[EqualityMacro_c_api.h](EqualityMacro__c__api_8h.md)** - Equality comparison macros
- **[Precompiled_c_api.h](Precompiled__c__api_8h.md)** - Precompiled header

## Usage Guidelines

The C API follows these conventions:

1. **Memory Management**: All C API functions that allocate memory return pointers that must be freed using the corresponding `destroy` functions.
2. **Error Handling**: Use the error handling utilities provided in `ErrorHandling_c_api.h` to check return values.
3. **String Handling**: Strings are represented using the `string` struct and should be managed using the provided string utilities.
4. **Type Naming**: C API types follow the pattern `<CppType>_c_api` to distinguish them from C++ types.

## Additional Resources

- **[All Types](annotated.md)** - Complete list of all C API types
- **[File Documentation](files.md)** - Documentation organized by header file

---

*This documentation is automatically generated from the C API header files using Doxygen.*
