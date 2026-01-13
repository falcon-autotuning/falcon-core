

# Class falcon\_core::autotuner\_interfaces::names::NameBase



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**names**](namespacefalcon__core_1_1autotuner__interfaces_1_1names.md) **>** [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::autotuner\_interfaces::names::Gname](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Gname.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**NameBase**](#function-namebase-15) (const [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) & other) <br> |
|   | [**NameBase**](#function-namebase-25) (const std::string & name) <br> |
|   | [**NameBase**](#function-namebase-35) (const std::string & name, const std::string & index\_string) <br> |
|   | [**NameBase**](#function-namebase-45) (const int & num, const std::string & index\_string) <br> |
|  std::string | [**name**](#function-name) () const<br>_The string form of the name._  |
|  int | [**num**](#function-num) () const<br>_The numeric form of the name._  |
|  std::shared\_ptr&lt; [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) &gt; | [**operator+**](#function-operator) (const std::shared\_ptr&lt; [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) &gt; | [**operator-**](#function-operator-) (const std::shared\_ptr&lt; [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) &gt; & other) const<br> |
|  [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) & | [**operator=**](#function-operator_1) (const [**NameBase**](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md) & other) <br> |


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
|   | [**NameBase**](#function-namebase-55) () = default<br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function NameBase [1/5]

```C++
falcon_core::autotuner_interfaces::names::NameBase::NameBase (
    const NameBase & other
) 
```




<hr>



### function NameBase [2/5]

```C++
falcon_core::autotuner_interfaces::names::NameBase::NameBase (
    const std::string & name
) 
```




<hr>



### function NameBase [3/5]

```C++
falcon_core::autotuner_interfaces::names::NameBase::NameBase (
    const std::string & name,
    const std::string & index_string
) 
```




<hr>



### function NameBase [4/5]

```C++
falcon_core::autotuner_interfaces::names::NameBase::NameBase (
    const int & num,
    const std::string & index_string
) 
```




<hr>



### function name 

_The string form of the name._ 
```C++
std::string falcon_core::autotuner_interfaces::names::NameBase::name () const
```




<hr>



### function num 

_The numeric form of the name._ 
```C++
int falcon_core::autotuner_interfaces::names::NameBase::num () const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< NameBase > falcon_core::autotuner_interfaces::names::NameBase::operator+ (
    const std::shared_ptr< NameBase > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< NameBase > falcon_core::autotuner_interfaces::names::NameBase::operator- (
    const std::shared_ptr< NameBase > & other
) const
```




<hr>



### function operator= 

```C++
NameBase & falcon_core::autotuner_interfaces::names::NameBase::operator= (
    const NameBase & other
) 
```




<hr>
## Protected Functions Documentation




### function NameBase [5/5]

```C++
falcon_core::autotuner_interfaces::names::NameBase::NameBase () = default
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::names::NameBase::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::names::NameBase::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/names/NameBase.hpp`

