

# Class falcon\_core::autotuner\_interfaces::contexts::MeasurementContext



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**contexts**](namespacefalcon__core_1_1autotuner__interfaces_1_1contexts.md) **>** [**MeasurementContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md)








Inherits the following classes: [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MeasurementContext**](#function-measurementcontext-24) (const MeasurementContext & other) <br> |
|   | [**MeasurementContext**](#function-measurementcontext-34) (const physics::device\_structures::ConnectionSP & connection, const instrument\_interfaces::names::Instrument & instrument\_type) <br>_Constructs the measurement context._  |
|   | [**MeasurementContext**](#function-measurementcontext-44) (const contexts::BaseContextSP & acquisition\_context) <br>_Constructs a MeasururementContext from an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _._ |
|  MeasurementContext & | [**operator=**](#function-operator) (const MeasurementContext & other) <br> |


## Public Functions inherited from falcon_core::autotuner_interfaces::contexts::BaseContext

See [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-14) (const BaseContext & other) <br> |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-24) (const physics::device\_structures::ConnectionSP & connection, const instrument\_interfaces::names::Instrument & instrument\_type) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with a connection and instrument type._ |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-34) (const instrument\_interfaces::names::InstrumentPortSP & port) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with an InstrumentPort._ |
|  const physics::device\_structures::ConnectionSP | [**connection**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-connection) () const<br>_Return the connection._  |
|  const instrument\_interfaces::names::Instrument | [**instrument\_type**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-instrument_type) () const<br>_Return the instrument type._  |
|  bool | [**operator!=**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator) (const BaseContext & other) const<br> |
|  BaseContext & | [**operator=**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator_1) (const BaseContext & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-operator_2) (const BaseContext & other) const<br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |






## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |






























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**MeasurementContext**](#function-measurementcontext-14) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::autotuner_interfaces::contexts::BaseContext

See [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-basecontext-44) () <br> |
|  void | [**serialize**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function MeasurementContext [2/4]

```C++
falcon_core::autotuner_interfaces::contexts::MeasurementContext::MeasurementContext (
    const MeasurementContext & other
) 
```




<hr>



### function MeasurementContext [3/4]

_Constructs the measurement context._ 
```C++
falcon_core::autotuner_interfaces::contexts::MeasurementContext::MeasurementContext (
    const physics::device_structures::ConnectionSP & connection,
    const instrument_interfaces::names::Instrument & instrument_type
) 
```





**Parameters:**


* `connection` The device connection. 
* `instrument_type` The type of instrument. 




        

<hr>



### function MeasurementContext [4/4]

_Constructs a MeasururementContext from an_ [_**AcquisitionContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) _._
```C++
falcon_core::autotuner_interfaces::contexts::MeasurementContext::MeasurementContext (
    const contexts::BaseContextSP & acquisition_context
) 
```





**Parameters:**


* `acquisition_context` The acquisition context. 




        

<hr>



### function operator= 

```C++
MeasurementContext & falcon_core::autotuner_interfaces::contexts::MeasurementContext::operator= (
    const MeasurementContext & other
) 
```




<hr>
## Protected Functions Documentation




### function MeasurementContext [1/4]

```C++
falcon_core::autotuner_interfaces::contexts::MeasurementContext::MeasurementContext () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::contexts::MeasurementContext::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::contexts::MeasurementContext::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp`

