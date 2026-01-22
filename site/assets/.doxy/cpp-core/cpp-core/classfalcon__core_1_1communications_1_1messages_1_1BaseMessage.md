

# Class falcon\_core::communications::messages::BaseMessage



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**messages**](namespacefalcon__core_1_1communications_1_1messages.md) **>** [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::communications::messages::MeasurementRequest](classfalcon__core_1_1communications_1_1messages_1_1MeasurementRequest.md),  [falcon\_core::communications::messages::MeasurementResponse](classfalcon__core_1_1communications_1_1messages_1_1MeasurementResponse.md),  [falcon\_core::communications::messages::StandardRequest](classfalcon__core_1_1communications_1_1messages_1_1StandardRequest.md),  [falcon\_core::communications::messages::StandardResponse](classfalcon__core_1_1communications_1_1messages_1_1StandardResponse.md),  [falcon\_core::communications::messages::VoltageStatesResponse](classfalcon__core_1_1communications_1_1messages_1_1VoltageStatesResponse.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](#function-basemessage-13) (const BaseMessage & other) <br> |
|   | [**BaseMessage**](#function-basemessage-23) (const std::string & message) <br> |
|  const std::string & | [**message**](#function-message) () const<br> |
|  bool | [**operator!=**](#function-operator) (const BaseMessage & other) const<br> |
|  BaseMessage & | [**operator=**](#function-operator_1) (const BaseMessage & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const BaseMessage & other) const<br> |


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
|   | [**BaseMessage**](#function-basemessage-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function BaseMessage [1/3]

```C++
falcon_core::communications::messages::BaseMessage::BaseMessage (
    const BaseMessage & other
) 
```




<hr>



### function BaseMessage [2/3]

```C++
falcon_core::communications::messages::BaseMessage::BaseMessage (
    const std::string & message
) 
```




<hr>



### function message 

```C++
const std::string & falcon_core::communications::messages::BaseMessage::message () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::communications::messages::BaseMessage::operator!= (
    const BaseMessage & other
) const
```




<hr>



### function operator= 

```C++
BaseMessage & falcon_core::communications::messages::BaseMessage::operator= (
    const BaseMessage & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::communications::messages::BaseMessage::operator== (
    const BaseMessage & other
) const
```




<hr>
## Protected Functions Documentation




### function BaseMessage [3/3]

```C++
falcon_core::communications::messages::BaseMessage::BaseMessage () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::messages::BaseMessage::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::messages::BaseMessage::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/messages/BaseMessage.hpp`

