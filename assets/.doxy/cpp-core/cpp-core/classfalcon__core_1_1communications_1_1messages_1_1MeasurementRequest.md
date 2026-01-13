

# Class falcon\_core::communications::messages::MeasurementRequest



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**messages**](namespacefalcon__core_1_1communications_1_1messages.md) **>** [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md)








Inherits the following classes: [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MeasurementRequest**](#function-measurementrequest-13) (const [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md) & other) <br> |
|   | [**MeasurementRequest**](#function-measurementrequest-23) (const std::string & message, const std::string & measurement\_name, const generic::ListSP&lt; [**instrument\_interfaces::Waveform**](classfalcon__core_1_1instrument__interfaces_1_1Waveform.md) &gt; & waveforms, const instrument\_interfaces::names::PortsSP & getters, const generic::MapSP&lt; [**instrument\_interfaces::names::InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md), [**instrument\_interfaces::port\_transforms::PortTransform**](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransform.md) &gt; & meter\_transforms, const math::domains::LabelledDomainSP & time\_domain) <br> |
|  const instrument\_interfaces::names::PortsSP & | [**getters**](#function-getters) () const<br> |
|  const std::string & | [**measurement\_name**](#function-measurement_name) () const<br> |
|  const generic::MapSP&lt; [**instrument\_interfaces::names::InstrumentPort**](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md), [**instrument\_interfaces::port\_transforms::PortTransform**](classfalcon__core_1_1instrument__interfaces_1_1port__transforms_1_1PortTransform.md) &gt; & | [**meter\_transforms**](#function-meter_transforms) () const<br> |
|  bool | [**operator!=**](#function-operator) (const [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md) & other) const<br> |
|  [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md) & | [**operator=**](#function-operator_1) (const [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**MeasurementRequest**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md) & other) const<br> |
|  const math::domains::LabelledDomainSP & | [**time\_domain**](#function-time_domain) () const<br> |
|  const generic::ListSP&lt; [**instrument\_interfaces::Waveform**](classfalcon__core_1_1instrument__interfaces_1_1Waveform.md) &gt; | [**waveforms**](#function-waveforms) () const<br> |


## Public Functions inherited from falcon_core::communications::messages::BaseMessage

See [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-13) (const [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md) & other) <br> |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-23) (const std::string & message) <br> |
|  const std::string & | [**message**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-message) () const<br> |
|  bool | [**operator!=**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator) (const [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md) & other) const<br> |
|  [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md) & | [**operator=**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator_1) (const [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md) & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator_2) (const [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md) & other) const<br> |


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
|   | [**MeasurementRequest**](#function-measurementrequest-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::communications::messages::BaseMessage

See [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function MeasurementRequest [1/3]

```C++
falcon_core::communications::messages::MeasurementRequest::MeasurementRequest (
    const MeasurementRequest & other
) 
```




<hr>



### function MeasurementRequest [2/3]

```C++
falcon_core::communications::messages::MeasurementRequest::MeasurementRequest (
    const std::string & message,
    const std::string & measurement_name,
    const generic::ListSP< instrument_interfaces::Waveform > & waveforms,
    const instrument_interfaces::names::PortsSP & getters,
    const generic::MapSP< instrument_interfaces::names::InstrumentPort , instrument_interfaces::port_transforms::PortTransform > & meter_transforms,
    const math::domains::LabelledDomainSP & time_domain
) 
```




<hr>



### function getters 

```C++
const instrument_interfaces::names::PortsSP & falcon_core::communications::messages::MeasurementRequest::getters () const
```




<hr>



### function measurement\_name 

```C++
const std::string & falcon_core::communications::messages::MeasurementRequest::measurement_name () const
```




<hr>



### function meter\_transforms 

```C++
const generic::MapSP< instrument_interfaces::names::InstrumentPort , instrument_interfaces::port_transforms::PortTransform > & falcon_core::communications::messages::MeasurementRequest::meter_transforms () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::communications::messages::MeasurementRequest::operator!= (
    const MeasurementRequest & other
) const
```




<hr>



### function operator= 

```C++
MeasurementRequest & falcon_core::communications::messages::MeasurementRequest::operator= (
    const MeasurementRequest & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::messages::MeasurementRequest::operator== (
    const MeasurementRequest & other
) const
```




<hr>



### function time\_domain 

```C++
const math::domains::LabelledDomainSP & falcon_core::communications::messages::MeasurementRequest::time_domain () const
```




<hr>



### function waveforms 

```C++
const generic::ListSP< instrument_interfaces::Waveform > falcon_core::communications::messages::MeasurementRequest::waveforms () const
```




<hr>
## Protected Functions Documentation




### function MeasurementRequest [3/3]

```C++
falcon_core::communications::messages::MeasurementRequest::MeasurementRequest () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::messages::MeasurementRequest::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::messages::MeasurementRequest::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/messages/MeasurementRequest.hpp`

