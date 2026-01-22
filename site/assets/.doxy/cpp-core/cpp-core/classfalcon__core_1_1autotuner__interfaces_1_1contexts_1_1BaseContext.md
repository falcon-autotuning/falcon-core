

# Class falcon\_core::autotuner\_interfaces::contexts::BaseContext



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**contexts**](namespacefalcon__core_1_1autotuner__interfaces_1_1contexts.md) **>** [**BaseContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::autotuner\_interfaces::contexts::AcquisitionContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md),  [falcon\_core::autotuner\_interfaces::contexts::MeasurementContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1MeasurementContext.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BaseContext**](#function-basecontext-14) (const BaseContext & other) <br> |
|   | [**BaseContext**](#function-basecontext-24) (const physics::device\_structures::ConnectionSP & connection, const instrument\_interfaces::names::Instrument & instrument\_type) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with a connection and instrument type._ |
|   | [**BaseContext**](#function-basecontext-34) (const instrument\_interfaces::names::InstrumentPortSP & port) <br>_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with an InstrumentPort._ |
|  const physics::device\_structures::ConnectionSP | [**connection**](#function-connection) () const<br>_Return the connection._  |
|  const instrument\_interfaces::names::Instrument | [**instrument\_type**](#function-instrument_type) () const<br>_Return the instrument type._  |
|  bool | [**operator!=**](#function-operator) (const BaseContext & other) const<br> |
|  BaseContext & | [**operator=**](#function-operator_1) (const BaseContext & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const BaseContext & other) const<br> |


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
|   | [**BaseContext**](#function-basecontext-44) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function BaseContext [1/4]

```C++
falcon_core::autotuner_interfaces::contexts::BaseContext::BaseContext (
    const BaseContext & other
) 
```




<hr>



### function BaseContext [2/4]

_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with a connection and instrument type._
```C++
falcon_core::autotuner_interfaces::contexts::BaseContext::BaseContext (
    const physics::device_structures::ConnectionSP & connection,
    const instrument_interfaces::names::Instrument & instrument_type
) 
```





**Parameters:**


* `connection` The device connection. 
* `instrument_type` The type of instrument. 




        

<hr>



### function BaseContext [3/4]

_Initialize a_ [_**BaseContext**_](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md) _with an InstrumentPort._
```C++
falcon_core::autotuner_interfaces::contexts::BaseContext::BaseContext (
    const instrument_interfaces::names::InstrumentPortSP & port
) 
```





**Parameters:**


* `port` The instrument port. 




        

<hr>



### function connection 

_Return the connection._ 
```C++
const physics::device_structures::ConnectionSP falcon_core::autotuner_interfaces::contexts::BaseContext::connection () const
```




<hr>



### function instrument\_type 

_Return the instrument type._ 
```C++
const instrument_interfaces::names::Instrument falcon_core::autotuner_interfaces::contexts::BaseContext::instrument_type () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::autotuner_interfaces::contexts::BaseContext::operator!= (
    const BaseContext & other
) const
```




<hr>



### function operator= 

```C++
BaseContext & falcon_core::autotuner_interfaces::contexts::BaseContext::operator= (
    const BaseContext & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::autotuner_interfaces::contexts::BaseContext::operator== (
    const BaseContext & other
) const
```




<hr>
## Protected Functions Documentation




### function BaseContext [4/4]

```C++
falcon_core::autotuner_interfaces::contexts::BaseContext::BaseContext () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::contexts::BaseContext::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::contexts::BaseContext::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/contexts/BaseContext.hpp`

