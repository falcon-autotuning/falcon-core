# C++ Core API Reference

This section contains the complete C++ API documentation for Falcon Core, automatically generated from the source code.

## Quick Navigation

- **[Classes](classes.md)** - List of all classes with brief descriptions
- **[Class Hierarchy](hierarchy.md)** - Class inheritance diagrams
- **[Namespaces](namespaces.md)** - List of all namespaces
- **[Files](files.md)** - List of all header files

## API Overview

### Core Components

#### Autotuner Interfaces
- **[Contexts](namespacefalcon__core_1_1autotuner__interfaces_1_1contexts.md)** - Acquisition and measurement contexts
  - [AcquisitionContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md)
  - [MeasurementContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md)
  - [BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)

- **[Interpretations](namespacefalcon__core_1_1autotuner__interfaces_1_1interpretations.md)** - Data interpretation containers
  - [InterpretationContainer](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContainer.md)
  - [InterpretationContext](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md)

- **[Names](namespacefalcon__core_1_1autotuner__interfaces_1_1names.md)** - Naming conventions and structures
  - [Channel](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md)
  - [Channels](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channels.md)
  - [Gname](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md)

#### Communications
- **[Messages](namespacefalcon__core_1_1communications_1_1messages.md)** - Message types for communication
  - [MeasurementRequest](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md)
  - [MeasurementResponse](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md)
  - [StandardRequest](classfalcon__core_1_1communications_1_1messages_1_1StandardRequest.md)
  - [StandardResponse](classfalcon__core_1_1communications_1_1messages_1_1StandardResponse.md)

- **[Voltage States](namespacefalcon__core_1_1communications_1_1voltage__states.md)** - Device voltage state management
  - [DeviceVoltageState](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageState.md)
  - [DeviceVoltageStates](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageStates.md)

- **[HDF5Data](classfalcon__core_1_1communications_1_1HDF5Data.md)** - HDF5 data handling
- **[Time](classfalcon__core_1_1communications_1_1Time.md)** - Time utilities

#### Generic Containers
- **[Generic](namespacefalcon__core_1_1generic.md)** - Generic container types
  - [FArray](classfalcon__core_1_1generic_1_1FArray.md) - Fixed-size array
  - [IFArray](classfalcon__core_1_1generic_1_1IFArray.md) - Interface for arrays
  - [List](classfalcon__core_1_1generic_1_1List.md) - List container
  - [Map](classfalcon__core_1_1generic_1_1Map.md) - Map container
  - [Pair](classfalcon__core_1_1generic_1_1Pair.md) - Pair container
  - [Song](classfalcon__core_1_1generic_1_1Song.md) - Song data structure

#### Instrument Interfaces
- **[Instrument Interfaces](namespacefalcon__core_1_1instrument__interfaces.md)** - Instrument communication interfaces
  - [Waveform](classfalcon__core_1_1instrument__interfaces_1_1Waveform.md)
  - [InstrumentPort](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md)
  - [Ports](classfalcon__core_1_1instrument__interfaces_1_1names_1_1Ports.md)
  - [PortTransform](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransform.md)
  - [PortTransforms](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransforms.md)

#### Mathematics
- **[Math](namespacefalcon__core_1_1math.md)** - Mathematical utilities
  - [AnalyticFunction](classfalcon__core_1_1math_1_1AnalyticFunction.md)
  - [Axes](classfalcon__core_1_1math_1_1Axes.md)
  - [Point](classfalcon__core_1_1math_1_1Point.md)
  - [Quantity](classfalcon__core_1_1math_1_1Quantity.md)
  - [UnitSpace](classfalcon__core_1_1math_1_1UnitSpace.md)
  - [Vector](classfalcon__core_1_1math_1_1Vector.md)

- **[Arrays](namespacefalcon__core_1_1math_1_1arrays.md)** - Array types for control and measurement
  - [ControlArray](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md)
  - [ControlArray1D](classfalcon__core_1_1math_1_1arrays_1_1ControlArray1D.md)
  - [LabelledControlArray](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md)
  - [LabelledControlArray1D](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray1D.md)
  - [MeasuredArray](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md)
  - [MeasuredArray1D](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md)
  - [LabelledMeasuredArray](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md)
  - [LabelledMeasuredArray1D](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray1D.md)

- **[Discrete Spaces](namespacefalcon__core_1_1math_1_1discrete__spaces.md)** - Discrete space utilities
  - [DiscreteSpace](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md)
  - [Discretizer](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md)

- **[Domains](namespacefalcon__core_1_1math_1_1domains.md)** - Domain definitions
  - [Domain](classfalcon__core_1_1math_1_1domains_1_1Domain.md)
  - [LabelledDomain](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md)
  - [CoupledLabelledDomain](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md)

#### Physics
- **[Config](namespacefalcon__core_1_1physics_1_1config.md)** - Configuration management
  - [Config](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md)
  - [ConfigManipulations](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md)
  - [Loader](classfalcon__core_1_1physics_1_1config_1_1Loader.md)
  - [Group](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md)
  - [Adjacency](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md)
  - [VoltageConstraints](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md)

- **[Geometries](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md)** - Device geometry definitions
  - [GateGeometryArray1D](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md)
  - [DotGateWithNeighbors](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md)
  - [DotGatesWithNeighbors](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGatesWithNeighbors.md)
  - [LeftReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md)
  - [RightReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md)

- **[Device Structures](namespacefalcon__core_1_1physics_1_1device__structures.md)** - Physical device structures
  - [Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)
  - [Connections](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md)
  - [GateRelations](classfalcon__core_1_1physics_1_1device__structures_1_1GateRelations.md)
  - [Impedance](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md)
  - [Impedances](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md)

- **[Units](namespacefalcon__core_1_1physics_1_1units.md)** - Physical unit system
  - [Unit](classfalcon__core_1_1physics_1_1units_1_1Unit.md)
  - [SymbolUnit](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md)
  - [Prefix](classfalcon__core_1_1physics_1_1units_1_1Prefix.md)

## Additional Resources

- **[All Classes Index](annotated.md)** - Annotated class list
- **[Namespace Members](namespace_members.md)** - All namespace-level functions, variables, and types
- **[Class Members](class_members.md)** - All class member functions, variables, and types
- **[File Documentation](files.md)** - Documentation organized by source file

---

*This documentation is automatically generated from the C++ source code using Doxygen.*
