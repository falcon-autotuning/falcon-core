

# Class falcon\_core::communications::messages::MeasurementResponse



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**messages**](namespacefalcon__core_1_1communications_1_1messages.md) **>** [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md)








Inherits the following classes: [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MeasurementResponse**](#function-measurementresponse-13) (const [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md) & other) <br> |
|   | [**MeasurementResponse**](#function-measurementresponse-23) (const math::arrays::LabelledArraysSP&lt; [**math::arrays::LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; & arrays) <br> |
|  const math::arrays::LabelledArraysSP&lt; [**math::arrays::LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; & | [**arrays**](#function-arrays) () const<br> |
|  bool | [**operator!=**](#function-operator) (const [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md) & other) const<br> |
|  [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md) & | [**operator=**](#function-operator_1) (const [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**MeasurementResponse**](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md) & other) const<br> |


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
|   | [**MeasurementResponse**](#function-measurementresponse-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::communications::messages::BaseMessage

See [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function MeasurementResponse [1/3]

```C++
falcon_core::communications::messages::MeasurementResponse::MeasurementResponse (
    const MeasurementResponse & other
) 
```




<hr>



### function MeasurementResponse [2/3]

```C++
falcon_core::communications::messages::MeasurementResponse::MeasurementResponse (
    const math::arrays::LabelledArraysSP< math::arrays::LabelledMeasuredArray > & arrays
) 
```




<hr>



### function arrays 

```C++
const math::arrays::LabelledArraysSP< math::arrays::LabelledMeasuredArray > & falcon_core::communications::messages::MeasurementResponse::arrays () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::communications::messages::MeasurementResponse::operator!= (
    const MeasurementResponse & other
) const
```




<hr>



### function operator= 

```C++
MeasurementResponse & falcon_core::communications::messages::MeasurementResponse::operator= (
    const MeasurementResponse & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::messages::MeasurementResponse::operator== (
    const MeasurementResponse & other
) const
```




<hr>
## Protected Functions Documentation




### function MeasurementResponse [3/3]

```C++
falcon_core::communications::messages::MeasurementResponse::MeasurementResponse () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::messages::MeasurementResponse::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::messages::MeasurementResponse::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/messages/MeasurementResponse.hpp`

