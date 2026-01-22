

# Class falcon\_core::autotuner\_interfaces::names::Gname



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**names**](namespacefalcon__core_1_1autotuner__interfaces_1_1names.md) **>** [**Gname**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md)








Inherits the following classes: [falcon\_core::autotuner\_interfaces::names::NameBase](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Gname**](#function-gname-13) (const std::string & name) <br> |
|   | [**Gname**](#function-gname-23) (const int & num) <br> |
|  std::string | [**gname**](#function-gname) () const<br>_Collect the gname as a string._  |
|  bool | [**operator!=**](#function-operator) (const Gname & other) const<br> |
|  bool | [**operator==**](#function-operator_1) (const Gname & other) const<br> |


## Public Functions inherited from falcon_core::autotuner_interfaces::names::NameBase

See [falcon\_core::autotuner\_interfaces::names::NameBase](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md)

| Type | Name |
| ---: | :--- |
|   | [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-namebase-15) (const NameBase & other) <br> |
|   | [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-namebase-25) (const std::string & name) <br> |
|   | [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-namebase-35) (const std::string & name, const std::string & index\_string) <br> |
|   | [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-namebase-45) (const int & num, const std::string & index\_string) <br> |
|  std::string | [**name**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-name) () const<br>_The string form of the name._  |
|  int | [**num**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-num) () const<br>_The numeric form of the name._  |
|  std::shared\_ptr&lt; NameBase &gt; | [**operator+**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-operator) (const std::shared\_ptr&lt; NameBase &gt; & other) const<br> |
|  std::shared\_ptr&lt; NameBase &gt; | [**operator-**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-operator-) (const std::shared\_ptr&lt; NameBase &gt; & other) const<br> |
|  NameBase & | [**operator=**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-operator_1) (const NameBase & other) <br> |


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
|   | [**Gname**](#function-gname-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::autotuner_interfaces::names::NameBase

See [falcon\_core::autotuner\_interfaces::names::NameBase](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md)

| Type | Name |
| ---: | :--- |
|   | [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-namebase-55) () = default<br> |
|  void | [**serialize**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function Gname [1/3]

```C++
falcon_core::autotuner_interfaces::names::Gname::Gname (
    const std::string & name
) 
```




<hr>



### function Gname [2/3]

```C++
falcon_core::autotuner_interfaces::names::Gname::Gname (
    const int & num
) 
```




<hr>



### function gname 

_Collect the gname as a string._ 
```C++
std::string falcon_core::autotuner_interfaces::names::Gname::gname () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::autotuner_interfaces::names::Gname::operator!= (
    const Gname & other
) const
```




<hr>



### function operator== 

```C++
bool falcon_core::autotuner_interfaces::names::Gname::operator== (
    const Gname & other
) const
```




<hr>
## Protected Functions Documentation




### function Gname [3/3]

```C++
falcon_core::autotuner_interfaces::names::Gname::Gname () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::names::Gname::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::names::Gname::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/names/Gname.hpp`

