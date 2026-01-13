

# Class falcon\_core::physics::config::core::VoltageConstraints



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md) **>** [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md)



_Contains a ready to use voltage constrains matrix and matching limits for each constraint._ 

* `#include <VoltageConstraints.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**VoltageConstraints**](#function-voltageconstraints-13) (const [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) & other) <br> |
|   | [**VoltageConstraints**](#function-voltageconstraints-23) (const AdjacencySP adjacency, double max\_safe\_diff, std::pair&lt; double, double &gt; bounds) <br> |
|  const AdjacencySP | [**adjacency**](#function-adjacency) () const<br>_The adjacency matrix used to understand the device layout._  |
|  const [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; & | [**limits**](#function-limits) () const<br>_The y axis vector safe voltage limits for each constraint._  |
|  const [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; & | [**matrix**](#function-matrix-12) () const<br>_The constraint matrix._  |
|  const [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; double &gt; & | [**matrix**](#function-matrix-22) () <br>_The constraint matrix._  |
|  bool | [**operator!=**](#function-operator) (const [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) & other) const<br> |
|  [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) & | [**operator=**](#function-operator_1) (const [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**VoltageConstraints**](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md) & other) const<br> |


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
|   | [**VoltageConstraints**](#function-voltageconstraints-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function VoltageConstraints [1/3]

```C++
falcon_core::physics::config::core::VoltageConstraints::VoltageConstraints (
    const VoltageConstraints & other
) 
```




<hr>



### function VoltageConstraints [2/3]

```C++
falcon_core::physics::config::core::VoltageConstraints::VoltageConstraints (
    const AdjacencySP adjacency,
    double max_safe_diff,
    std::pair< double, double > bounds
) 
```




<hr>



### function adjacency 

_The adjacency matrix used to understand the device layout._ 
```C++
const AdjacencySP falcon_core::physics::config::core::VoltageConstraints::adjacency () const
```




<hr>



### function limits 

_The y axis vector safe voltage limits for each constraint._ 
```C++
const generic::FArray < double > & falcon_core::physics::config::core::VoltageConstraints::limits () const
```




<hr>



### function matrix [1/2]

_The constraint matrix._ 
```C++
const generic::FArray < double > & falcon_core::physics::config::core::VoltageConstraints::matrix () const
```




<hr>



### function matrix [2/2]

_The constraint matrix._ 
```C++
const generic::FArray < double > & falcon_core::physics::config::core::VoltageConstraints::matrix () 
```




<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::core::VoltageConstraints::operator!= (
    const VoltageConstraints & other
) const
```




<hr>



### function operator= 

```C++
VoltageConstraints & falcon_core::physics::config::core::VoltageConstraints::operator= (
    const VoltageConstraints & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::core::VoltageConstraints::operator== (
    const VoltageConstraints & other
) const
```




<hr>
## Protected Functions Documentation




### function VoltageConstraints [3/3]

```C++
falcon_core::physics::config::core::VoltageConstraints::VoltageConstraints () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::core::VoltageConstraints::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::core::VoltageConstraints::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/VoltageConstraints.hpp`

