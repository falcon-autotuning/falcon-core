

# Class falcon\_core::communications::messages::StandardRequest



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**communications**](namespacefalcon__core_1_1communications.md) **>** [**messages**](namespacefalcon__core_1_1communications_1_1messages.md) **>** [**StandardRequest**](classfalcon__core_1_1communications_1_1messages_1_1StandardRequest.md)








Inherits the following classes: [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**StandardRequest**](#function-standardrequest-12) (const std::string & message) <br> |


## Public Functions inherited from falcon_core::communications::messages::BaseMessage

See [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-13) (const BaseMessage & other) <br> |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-23) (const std::string & message) <br> |
|  const std::string & | [**message**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-message) () const<br> |
|  bool | [**operator!=**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator) (const BaseMessage & other) const<br> |
|  BaseMessage & | [**operator=**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator_1) (const BaseMessage & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-operator_2) (const BaseMessage & other) const<br> |


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
|   | [**StandardRequest**](#function-standardrequest-22) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::communications::messages::BaseMessage

See [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md)

| Type | Name |
| ---: | :--- |
|   | [**BaseMessage**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-basemessage-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function StandardRequest [1/2]

```C++
falcon_core::communications::messages::StandardRequest::StandardRequest (
    const std::string & message
) 
```




<hr>
## Protected Functions Documentation




### function StandardRequest [2/2]

```C++
falcon_core::communications::messages::StandardRequest::StandardRequest () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::communications::messages::StandardRequest::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::communications::messages::StandardRequest::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/communications/messages/StandardRequest.hpp`

