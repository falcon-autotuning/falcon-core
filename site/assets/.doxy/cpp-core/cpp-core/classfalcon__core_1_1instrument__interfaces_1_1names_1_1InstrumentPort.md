

# Class falcon\_core::instrument\_interfaces::names::InstrumentPort



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**instrument\_interfaces**](namespacefalcon__core_1_1instrument__interfaces.md) **>** [**names**](namespacefalcon__core_1_1instrument__interfaces_1_1names.md) **>** [**InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**InstrumentPort**](#function-instrumentport-13) (const InstrumentPort & other) <br> |
|   | [**InstrumentPort**](#function-instrumentport-23) (const std::string & default\_name, const physics::device\_structures::ConnectionSP & pseudo\_name=nullptr, const Instrument & instrument\_type=INSTRUMENT\_TYPES::DC\_VOLTAGE\_SOURCE, const physics::units::SymbolUnitSP & units=[**physics::units::SymbolUnit::Volt**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-volt)(), const std::string & description="", const PortType & type=PortType::InstrumentPort) <br>_Initialize an_ [_**InstrumentPort**_](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md) _._ |
|  const std::string | [**default\_name**](#function-default_name) () const<br>_Rreturn the default name of the port._  |
|  const std::string | [**description**](#function-description) () const<br>_Returns the description of the port._  |
|  const std::string | [**instrument\_facing\_name**](#function-instrument_facing_name) () const<br>_Returns the psuedo name if it exists, otherwise the instrument type as a string._  |
|  const Instrument | [**instrument\_type**](#function-instrument_type) () const<br>_Returns the type of the instrument that the port is connected to._  |
|  const bool | [**is\_knob**](#function-is_knob) () const<br>_Checks if this port is a knob._  |
|  const bool | [**is\_meter**](#function-is_meter) () const<br>_Checks if this port is a meter._  |
|  const bool | [**is\_port**](#function-is_port) () const<br>_Checks if this port is a port._  |
|  bool | [**operator!=**](#function-operator) (const InstrumentPort & other) const<br> |
|  InstrumentPort & | [**operator=**](#function-operator_1) (const InstrumentPort & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const InstrumentPort & other) const<br> |
|  const std::shared\_ptr&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**pseudo\_name**](#function-pseudo_name) () const<br>_Return the pseudo name of the port._  |
|  const PortType | [**type**](#function-type) () const<br> |
|  const std::shared\_ptr&lt; [**physics::units::SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) &gt; | [**units**](#function-units) () const<br>_Returns the untis of the port._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; InstrumentPort &gt; | [**ExecutionClock**](#function-executionclock) () <br>_A constructor for a ExecutionClock. This is used a dependant variable for output measurements._  |
|  std::shared\_ptr&lt; InstrumentPort &gt; | [**Knob**](#function-knob) (const std::string & default\_name, const physics::device\_structures::ConnectionSP & pseudo\_name=nullptr, const Instrument & instrument\_type=INSTRUMENT\_TYPES::DC\_VOLTAGE\_SOURCE, const physics::units::SymbolUnitSP units=[**physics::units::SymbolUnit::MilliVolt**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-millivolt)(), const std::string & description="A default voltage source") <br>_A constructor for a Instrument Knob. This is used as a setter interface._  |
|  std::shared\_ptr&lt; InstrumentPort &gt; | [**Meter**](#function-meter) (const std::string & default\_name, const physics::device\_structures::ConnectionSP & pseudo\_name=nullptr, const Instrument & instrument\_type=INSTRUMENT\_TYPES::AMNMETER, const physics::units::SymbolUnitSP units=[**physics::units::SymbolUnit::NanoAmpere**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-nanoampere)(), const std::string & description="A default current instrument\_interface") <br>_A constructor for a Instrument Meter. This is used as a getter interface._  |
|  std::shared\_ptr&lt; InstrumentPort &gt; | [**Timer**](#function-timer) () <br>_A constructor for a Timer. This is used a dependant variable for measurements._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**InstrumentPort**](#function-instrumentport-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function InstrumentPort [1/3]

```C++
falcon_core::instrument_interfaces::names::InstrumentPort::InstrumentPort (
    const InstrumentPort & other
) 
```




<hr>



### function InstrumentPort [2/3]

_Initialize an_ [_**InstrumentPort**_](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md) _._
```C++
falcon_core::instrument_interfaces::names::InstrumentPort::InstrumentPort (
    const std::string & default_name,
    const physics::device_structures::ConnectionSP & pseudo_name=nullptr,
    const Instrument & instrument_type=INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
    const physics::units::SymbolUnitSP & units=physics::units::SymbolUnit::Volt (),
    const std::string & description="",
    const PortType & type=PortType::InstrumentPort
) 
```





**Parameters:**


* `default_name` The default name of the port (e.g. "Vg1"). 
* `pseudo_name` The pseudo name (e.g. "plunger gate 1"). 
* `instrument_type` The type of instrument (e.g. DC\_VOLTAGE\_SOURCE). 
* `units` The units of the instrument (e.g. Volt). @description A description of the port. 




        

<hr>



### function default\_name 

_Rreturn the default name of the port._ 
```C++
const std::string falcon_core::instrument_interfaces::names::InstrumentPort::default_name () const
```




<hr>



### function description 

_Returns the description of the port._ 
```C++
const std::string falcon_core::instrument_interfaces::names::InstrumentPort::description () const
```




<hr>



### function instrument\_facing\_name 

_Returns the psuedo name if it exists, otherwise the instrument type as a string._ 
```C++
const std::string falcon_core::instrument_interfaces::names::InstrumentPort::instrument_facing_name () const
```




<hr>



### function instrument\_type 

_Returns the type of the instrument that the port is connected to._ 
```C++
const Instrument falcon_core::instrument_interfaces::names::InstrumentPort::instrument_type () const
```




<hr>



### function is\_knob 

_Checks if this port is a knob._ 
```C++
const bool falcon_core::instrument_interfaces::names::InstrumentPort::is_knob () const
```




<hr>



### function is\_meter 

_Checks if this port is a meter._ 
```C++
const bool falcon_core::instrument_interfaces::names::InstrumentPort::is_meter () const
```




<hr>



### function is\_port 

_Checks if this port is a port._ 
```C++
const bool falcon_core::instrument_interfaces::names::InstrumentPort::is_port () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::instrument_interfaces::names::InstrumentPort::operator!= (
    const InstrumentPort & other
) const
```




<hr>



### function operator= 

```C++
InstrumentPort & falcon_core::instrument_interfaces::names::InstrumentPort::operator= (
    const InstrumentPort & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::instrument_interfaces::names::InstrumentPort::operator== (
    const InstrumentPort & other
) const
```




<hr>



### function pseudo\_name 

_Return the pseudo name of the port._ 
```C++
const std::shared_ptr< physics::device_structures::Connection > falcon_core::instrument_interfaces::names::InstrumentPort::pseudo_name () const
```





**Exception:**


* `std::runtime_error` if the pseudo name is not set. 




        

<hr>



### function type 

```C++
const PortType falcon_core::instrument_interfaces::names::InstrumentPort::type () const
```




<hr>



### function units 

_Returns the untis of the port._ 
```C++
const std::shared_ptr< physics::units::SymbolUnit > falcon_core::instrument_interfaces::names::InstrumentPort::units () const
```




<hr>
## Public Static Functions Documentation




### function ExecutionClock 

_A constructor for a ExecutionClock. This is used a dependant variable for output measurements._ 
```C++
static std::shared_ptr< InstrumentPort > falcon_core::instrument_interfaces::names::InstrumentPort::ExecutionClock () 
```




<hr>



### function Knob 

_A constructor for a Instrument Knob. This is used as a setter interface._ 
```C++
static std::shared_ptr< InstrumentPort > falcon_core::instrument_interfaces::names::InstrumentPort::Knob (
    const std::string & default_name,
    const physics::device_structures::ConnectionSP & pseudo_name=nullptr,
    const Instrument & instrument_type=INSTRUMENT_TYPES::DC_VOLTAGE_SOURCE,
    const physics::units::SymbolUnitSP units=physics::units::SymbolUnit::MilliVolt (),
    const std::string & description="A default voltage source"
) 
```





**Parameters:**


* `default_name` The default name of the port (e.g. "Vg1"). 
* `pseudo_name` The pseudo name (e.g. "plunger gate 1"). 
* `instrument_type` The type of instrument (e.g. DC\_VOLTAGE\_SOURCE). 
* `units` The units of the instrument (e.g. Volt). @description A description of the port. @type The type of the port. 




        

<hr>



### function Meter 

_A constructor for a Instrument Meter. This is used as a getter interface._ 
```C++
static std::shared_ptr< InstrumentPort > falcon_core::instrument_interfaces::names::InstrumentPort::Meter (
    const std::string & default_name,
    const physics::device_structures::ConnectionSP & pseudo_name=nullptr,
    const Instrument & instrument_type=INSTRUMENT_TYPES::AMNMETER,
    const physics::units::SymbolUnitSP units=physics::units::SymbolUnit::NanoAmpere (),
    const std::string & description="A default current instrument_interface"
) 
```





**Parameters:**


* `default_name` The default name of the port (e.g. "Vg1"). 
* `pseudo_name` The pseudo name (e.g. "plunger gate 1"). 
* `instrument_type` The type of instrument (e.g. DC\_VOLTAGE\_SOURCE). 
* `units` The units of the instrument (e.g. Volt). @description A description of the port. 




        

<hr>



### function Timer 

_A constructor for a Timer. This is used a dependant variable for measurements._ 
```C++
static std::shared_ptr< InstrumentPort > falcon_core::instrument_interfaces::names::InstrumentPort::Timer () 
```




<hr>
## Protected Functions Documentation




### function InstrumentPort [3/3]

```C++
falcon_core::instrument_interfaces::names::InstrumentPort::InstrumentPort () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::instrument_interfaces::names::InstrumentPort::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::instrument_interfaces::names::InstrumentPort::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/instrument_interfaces/names/InstrumentPort.hpp`

