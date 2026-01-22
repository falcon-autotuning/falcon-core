
# Class List


Here are the classes, structs, unions and interfaces with brief descriptions:

* **namespace** [**INSTRUMENT\_TYPES**](namespaceINSTRUMENT__TYPES.md) _Different Instrument types supported by falcon software._ 
* **namespace** [**cereal**](namespacecereal.md)     
* **namespace** [**falcon\_core**](namespacefalcon__core.md) _A transform that maps a port to a time domain analytic function._     
    * **namespace** [**INSTRUMENT\_TYPES**](namespacefalcon__core_1_1INSTRUMENT__TYPES.md)     
    * **namespace** [**SI**](namespacefalcon__core_1_1SI.md)     
    * **namespace** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md)     
        * **namespace** [**contexts**](namespacefalcon__core_1_1autotuner__interfaces_1_1contexts.md)     
            * **class** [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md)     
            * **class** [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)     
            * **class** [**MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md)     
        * **namespace** [**interpretations**](namespacefalcon__core_1_1autotuner__interfaces_1_1interpretations.md)     
            * **class** [**InterpretationContainer**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContainer.md)     
            * **class** [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) _A context that describes measurement variables._     
        * **namespace** [**names**](namespacefalcon__core_1_1autotuner__interfaces_1_1names.md)     
            * **class** [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) _A string corresponding to a channel name._     
            * **class** [**Channels**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channels.md) _A collection of channels.._     
            * **class** [**Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md)     
            * **class** [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md)     
    * **namespace** [**communications**](namespacefalcon__core_1_1communications.md)     
        * **class** [**HDF5Data**](classfalcon__core_1_1communications_1_1HDF5Data.md)     
        * **class** [**Time**](classfalcon__core_1_1communications_1_1Time.md) _Represents a point in time with microsecond precision._     
        * **namespace** [**messages**](namespacefalcon__core_1_1communications_1_1messages.md)     
            * **class** [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)     
            * **class** [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md)     
            * **class** [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md)     
            * **class** [**StandardRequest**](classfalcon__core_1_1communications_1_1messages_1_1StandardRequest.md)     
            * **class** [**StandardResponse**](classfalcon__core_1_1communications_1_1messages_1_1StandardResponse.md)     
            * **class** [**VoltageStatesResponse**](classfalcon__core_1_1communications_1_1messages_1_1VoltageStatesResponse.md)     
        * **namespace** [**voltage\_states**](namespacefalcon__core_1_1communications_1_1voltage__states.md)     
            * **class** [**DeviceVoltageState**](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageState.md)     
            * **class** [**DeviceVoltageStates**](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageStates.md)     
    * **namespace** [**generic**](namespacefalcon__core_1_1generic.md)     
        * **class** [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)     
        * **class** [**IFArray**](classfalcon__core_1_1generic_1_1IFArray.md)     
        * **class** [**List**](classfalcon__core_1_1generic_1_1List.md)     
        * **class** [**Map**](classfalcon__core_1_1generic_1_1Map.md)     
        * **class** [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)     
        * **class** [**Song**](classfalcon__core_1_1generic_1_1Song.md) _Abstract base for all serializable_ [_**Song**_](classfalcon__core_1_1generic_1_1Song.md) _objects._    
        * **namespace** [**category**](namespacefalcon__core_1_1generic_1_1category.md)     
            * **struct** [**bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) 
            * **struct** [**determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)     
            * **struct** [**determine\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__tag.md)     
            * **struct** [**is\_shared\_ptr**](structfalcon__core_1_1generic_1_1category_1_1is__shared__ptr.md) 
            * **struct** [**is\_shared\_ptr&lt; std::shared\_ptr&lt; T &gt; &gt;**](structfalcon__core_1_1generic_1_1category_1_1is__shared__ptr_3_01std_1_1shared__ptr_3_01T_01_4_01_4.md) 
            * **struct** [**other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md) 
            * **struct** [**primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md) 
            * **struct** [**song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md) 
        * **struct** [**is\_primitive**](structfalcon__core_1_1generic_1_1is__primitive.md) 
    * **namespace** [**instrument\_interfaces**](namespacefalcon__core_1_1instrument__interfaces.md)     
        * **class** [**Waveform**](classfalcon__core_1_1instrument__interfaces_1_1Waveform.md)     
        * **namespace** [**names**](namespacefalcon__core_1_1instrument__interfaces_1_1names.md)     
            * **class** [**InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md)     
            * **struct** [**InstrumentTypes**](structfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentTypes.md)     
            * **class** [**Ports**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1Ports.md)     
        * **namespace** [**port\_transforms**](namespacefalcon__core_1_1instrument__interfaces_1_1port__transforms.md)     
            * **class** [**PortTransform**](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransform.md)     
            * **class** [**PortTransforms**](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransforms.md)     
    * **namespace** [**math**](namespacefalcon__core_1_1math.md)     
        * **class** [**AnalyticFunction**](classfalcon__core_1_1math_1_1AnalyticFunction.md)     
        * **class** [**Axes**](classfalcon__core_1_1math_1_1Axes.md) _Container for a collection of axis objects._     
        * **class** [**Point**](classfalcon__core_1_1math_1_1Point.md) _Represents a point in a multi-dimensional space, indexed by connections._     
        * **class** [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) _Represents a physical quantity with a value and unit._     
        * **class** [**UnitSpace**](classfalcon__core_1_1math_1_1UnitSpace.md) _Respresents a hypercube of measurement space. It is defined by a set of axes, each of which can be discretized._     
        * **class** [**Vector**](classfalcon__core_1_1math_1_1Vector.md) _Represents a vector in a multi-dimensional space, defined by start and end points._     
        * **namespace** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md)     
            * **class** [**ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) _Array type for control independant axis data._     
            * **class** [**ControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray1D.md) _1D control array, enforces 1D shape at construction._     
            * **class** [**IncreasingAlignment**](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md) _A three state system. The three states are 1, -1, and 0. 0 implies no trend in the domain._     
            * **class** [**Is1D**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md)     
            * **class** [**IsControl**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md)     
            * **class** [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)     
            * **class** [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md) _Container for multiple labelled arrays._     
            * **class** [**LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) _An array with a context label attached._     
            * **class** [**LabelledControlArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray1D.md) _1D control array with a label._     
            * **class** [**LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) _An array with a context label attached._     
            * **class** [**LabelledMeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray1D.md) _1D control array with a label._     
            * **class** [**MeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray.md) _Array type for measured data, derived from BaseArray._     
            * **class** [**MeasuredArray1D**](classfalcon__core_1_1math_1_1arrays_1_1MeasuredArray1D.md) _Array type for measured data, derived from BaseArray._     
        * **namespace** [**discrete\_spaces**](namespacefalcon__core_1_1math_1_1discrete__spaces.md)     
            * **class** [**DiscreteSpace**](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md)     
            * **class** [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _Abstract base class for discretizers._     
        * **namespace** [**domains**](namespacefalcon__core_1_1math_1_1domains.md)     
            * **class** [**CoupledLabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1CoupledLabelledDomain.md) _A collection of coupled domains to be attached together._     
            * **class** [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md)     
            * **class** [**LabelledDomain**](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md) [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _with an associated label with the instrument associated._    
    * **namespace** [**physics**](namespacefalcon__core_1_1physics.md)     
        * **namespace** [**config**](namespacefalcon__core_1_1physics_1_1config.md)     
            * **class** [**ConfigManipulations**](classfalcon__core_1_1physics_1_1config_1_1ConfigManipulations.md) _A utility class for manipulating and extracting information from device configurations._     
            * **class** [**Loader**](classfalcon__core_1_1physics_1_1config_1_1Loader.md)     
            * **namespace** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md)     
                * **class** [**Adjacency**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Adjacency.md) _This a graph representation of the connections between gates in a quantum dot device._     
                * **class** [**Config**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md) _The imported config file for falcon use._     
                * **class** [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) _Elements of the config that pertain to an individual group of gates._     
                * **class** [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) _Base config functionality for core config classes._     
                * **class** [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) _Contains a ready to use voltage constrains matrix and matching limits for each constraint._     
            * **namespace** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md)     
                * **class** [**DotGateWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md)     
                * **class** [**DotGatesWithNeighbors**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGatesWithNeighbors.md) _A serializable vector of_ [_**DotGateWithNeighbors**_](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md) _pointers, also a Song._    
                * **class** [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) _A 1D array of quantum dots with left and right reservoirs, barrier gates, plunger gates, ohmics, and screening gates. This contains the geometry of the 1D array._     
                * **class** [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md) _A gate with an ohmic below it._     
                * **class** [**HasLeftNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasLeftNeighbor.md) _A gate with a left neighbor._     
                * **class** [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md) _A gate with a right neighbor._     
                * **class** [**LeftReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md) _A special reservoir geometry that has an implanted ohmic contact and the rest of the channel extending to the right._     
                * **class** [**RightReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md) _A special reservoir geometry that has an implanted ohmic contact and the rest of the channel extending to the left._     
        * **namespace** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md)     
            * **class** [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)     
            * **class** [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _A serializable vector of_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _pointers, also a Song._    
            * **class** [**GateRelations**](classfalcon__core_1_1physics_1_1device__structures_1_1GateRelations.md) _Holds the relations between gates and their neighbors._     
            * **class** [**Impedance**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md)     
            * **class** [**Impedances**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md) _A collection of_ [_**Impedances**_](classfalcon__core_1_1physics_1_1device__structures_1_1Impedances.md) _._    
        * **namespace** [**units**](namespacefalcon__core_1_1physics_1_1units.md)     
            * **class** [**Prefix**](classfalcon__core_1_1physics_1_1units_1_1Prefix.md)     
            * **class** [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md)     
            * **class** [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md)     
* **namespace** [**std**](namespacestd.md) 

