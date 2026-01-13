

# Class falcon\_core::autotuner\_interfaces::names::Channel



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**names**](namespacefalcon__core_1_1autotuner__interfaces_1_1names.md) **>** [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md)



_A string corresponding to a channel name._ 

* `#include <Channel.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Channel**](#function-channel-13) (const [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) & other) <br>_Constructs a channel with the given name._  |
|   | [**Channel**](#function-channel-23) (const std::string & name) <br> |
|  std::string | [**name**](#function-name) () const<br> |
|  bool | [**operator!=**](#function-operator) (const [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) & other) const<br> |
|  [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) & | [**operator=**](#function-operator_1) (const [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Channel**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md) & other) const<br> |


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
|   | [**Channel**](#function-channel-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function Channel [1/3]

_Constructs a channel with the given name._ 
```C++
falcon_core::autotuner_interfaces::names::Channel::Channel (
    const Channel & other
) 
```




<hr>



### function Channel [2/3]

```C++
falcon_core::autotuner_interfaces::names::Channel::Channel (
    const std::string & name
) 
```




<hr>



### function name 

```C++
std::string falcon_core::autotuner_interfaces::names::Channel::name () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::autotuner_interfaces::names::Channel::operator!= (
    const Channel & other
) const
```




<hr>



### function operator= 

```C++
Channel & falcon_core::autotuner_interfaces::names::Channel::operator= (
    const Channel & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::autotuner_interfaces::names::Channel::operator== (
    const Channel & other
) const
```




<hr>
## Protected Functions Documentation




### function Channel [3/3]

```C++
falcon_core::autotuner_interfaces::names::Channel::Channel () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::names::Channel::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::names::Channel::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/names/Channel.hpp`

