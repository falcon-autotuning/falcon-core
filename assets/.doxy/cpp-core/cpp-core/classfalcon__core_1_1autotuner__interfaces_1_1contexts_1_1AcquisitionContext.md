

# Class falcon\_core::autotuner\_interfaces::contexts::AcquisitionContext



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**contexts**](namespacefalcon__core_1_1autotuner__interfaces_1_1contexts.md) **>** [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md)








Inherits the following classes: [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AcquisitionContext**](#function-acquisitioncontext-24) (const [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) & other) <br> |
|   | [**AcquisitionContext**](#function-acquisitioncontext-34) (const physics::device\_structures::ConnectionSP & connection, const instrument\_interfaces::names::Instrument & instrument\_type, const physics::units::SymbolUnitSP & units) <br>_Initialize an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _with a connection, instrument type, and units._ |
|   | [**AcquisitionContext**](#function-acquisitioncontext-44) (const instrument\_interfaces::names::InstrumentPortSP & port) <br>_Create an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _from an InstrumentPort._ |
|  const bool | [**match\_connection**](#function-match_connection) (physics::device\_structures::ConnectionSP other) const<br>_Returns if the connection is inside this context._  |
|  const bool | [**match\_instrument\_type**](#function-match_instrument_type) (instrument\_interfaces::names::Instrument other) const<br>_Returns if the instrument type matches this context._  |
|  bool | [**operator!=**](#function-operator) (const [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) & other) const<br> |
|  const std::shared\_ptr&lt; [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) &gt; | [**operator/**](#function-operator_1) (const physics::units::SymbolUnitSP & other) const<br>_Divide the units. The context on the top keeps all other details._  |
|  const std::shared\_ptr&lt; [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) &gt; | [**operator/**](#function-operator_2) (const std::shared\_ptr&lt; [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) &gt; & other) const<br>_Divide the units. The context on the top keeps all other details._  |
|  [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) & | [**operator=**](#function-operator_3) (const [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) & other) <br> |
|  bool | [**operator==**](#function-operator_4) (const [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) & other) const<br> |
|  const physics::units::SymbolUnitSP | [**units**](#function-units) () const<br>_Returns the units of the context._  |


## Public Functions inherited from falcon_core::autotuner_interfaces::contexts::BaseContext

See [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-14) (const [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) & other) <br> |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-24) (const physics::device\_structures::ConnectionSP & connection, const instrument\_interfaces::names::Instrument & instrument\_type) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with a connection and instrument type._ |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-34) (const instrument\_interfaces::names::InstrumentPortSP & port) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with an InstrumentPort._ |
|  const physics::device\_structures::ConnectionSP | [**connection**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-connection) () const<br>_Return the connection._  |
|  const instrument\_interfaces::names::Instrument | [**instrument\_type**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-instrument_type) () const<br>_Return the instrument type._  |
|  bool | [**operator!=**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator) (const [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) & other) const<br> |
|  [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) & | [**operator=**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator_1) (const [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator_2) (const [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) & other) const<br> |


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
|  std::shared\_ptr&lt; [**AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) &gt; | [**from\_context**](#function-from_context) (const BaseContextSP & measurement\_context, const physics::units::SymbolUnitSP & unit) <br>_Create an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _from a_[_**MeasurementContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) _._ |




## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |






























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**AcquisitionContext**](#function-acquisitioncontext-14) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::autotuner_interfaces::contexts::BaseContext

See [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-44) () <br> |
|  void | [**serialize**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function AcquisitionContext [2/4]

```C++
falcon_core::autotuner_interfaces::contexts::AcquisitionContext::AcquisitionContext (
    const AcquisitionContext & other
) 
```




<hr>



### function AcquisitionContext [3/4]

_Initialize an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _with a connection, instrument type, and units._
```C++
falcon_core::autotuner_interfaces::contexts::AcquisitionContext::AcquisitionContext (
    const physics::device_structures::ConnectionSP & connection,
    const instrument_interfaces::names::Instrument & instrument_type,
    const physics::units::SymbolUnitSP & units
) 
```





**Parameters:**


* `connection` The device connection. 
* `instrument_type` The type of instrument. 
* `units` The measurement units. 




        

<hr>



### function AcquisitionContext [4/4]

_Create an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _from an InstrumentPort._
```C++
falcon_core::autotuner_interfaces::contexts::AcquisitionContext::AcquisitionContext (
    const instrument_interfaces::names::InstrumentPortSP & port
) 
```





**Parameters:**


* `port` The instrument port. 




        

<hr>



### function match\_connection 

_Returns if the connection is inside this context._ 
```C++
const bool falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_connection (
    physics::device_structures::ConnectionSP other
) const
```




<hr>



### function match\_instrument\_type 

_Returns if the instrument type matches this context._ 
```C++
const bool falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_instrument_type (
    instrument_interfaces::names::Instrument other
) const
```




<hr>



### function operator!= 

```C++
bool falcon_core::autotuner_interfaces::contexts::AcquisitionContext::operator!= (
    const AcquisitionContext & other
) const
```




<hr>



### function operator/ 

_Divide the units. The context on the top keeps all other details._ 
```C++
const std::shared_ptr< AcquisitionContext > falcon_core::autotuner_interfaces::contexts::AcquisitionContext::operator/ (
    const physics::units::SymbolUnitSP & other
) const
```





**Parameters:**


* `other` The unit to divide by. 



**Returns:**

A new context with the divided units. 





        

<hr>



### function operator/ 

_Divide the units. The context on the top keeps all other details._ 
```C++
const std::shared_ptr< AcquisitionContext > falcon_core::autotuner_interfaces::contexts::AcquisitionContext::operator/ (
    const std::shared_ptr< AcquisitionContext > & other
) const
```





**Parameters:**


* `other` The unit to divide by. 



**Returns:**

A new context with the divided units. 





        

<hr>



### function operator= 

```C++
AcquisitionContext & falcon_core::autotuner_interfaces::contexts::AcquisitionContext::operator= (
    const AcquisitionContext & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::autotuner_interfaces::contexts::AcquisitionContext::operator== (
    const AcquisitionContext & other
) const
```




<hr>



### function units 

_Returns the units of the context._ 
```C++
const physics::units::SymbolUnitSP falcon_core::autotuner_interfaces::contexts::AcquisitionContext::units () const
```




<hr>
## Public Static Functions Documentation




### function from\_context 

_Create an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _from a_[_**MeasurementContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md) _._
```C++
static std::shared_ptr< AcquisitionContext > falcon_core::autotuner_interfaces::contexts::AcquisitionContext::from_context (
    const BaseContextSP & measurement_context,
    const physics::units::SymbolUnitSP & unit
) 
```





**Parameters:**


* `measurement_context` The base measurement context. 
* `units` The measurement units. 




        

<hr>
## Protected Functions Documentation




### function AcquisitionContext [1/4]

```C++
falcon_core::autotuner_interfaces::contexts::AcquisitionContext::AcquisitionContext () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::contexts::AcquisitionContext::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::contexts::AcquisitionContext::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp`

