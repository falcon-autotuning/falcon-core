

# Class falcon\_core::physics::config::geometries::HasLeftNeighbor



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md) **>** [**HasLeftNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasLeftNeighbor.md)



_A gate with a left neighbor._ 

* `#include <HasLeftNeighbor.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::physics::config::geometries::DotGateWithNeighbors](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md),  [falcon\_core::physics::config::geometries::RightReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**HasLeftNeighbor**](#function-hasleftneighbor-13) (const HasLeftNeighbor & other) <br> |
|   | [**HasLeftNeighbor**](#function-hasleftneighbor-23) (device\_structures::ConnectionSP left\_neighbor) <br> |
|  device\_structures::ConnectionSP | [**left\_neighbor**](#function-left_neighbor) () const<br>_Returns the left neighbor of the gate._  |
|  HasLeftNeighbor & | [**operator=**](#function-operator) (const HasLeftNeighbor & other) <br> |


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
|   | [**HasLeftNeighbor**](#function-hasleftneighbor-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function HasLeftNeighbor [1/3]

```C++
falcon_core::physics::config::geometries::HasLeftNeighbor::HasLeftNeighbor (
    const HasLeftNeighbor & other
) 
```




<hr>



### function HasLeftNeighbor [2/3]

```C++
falcon_core::physics::config::geometries::HasLeftNeighbor::HasLeftNeighbor (
    device_structures::ConnectionSP left_neighbor
) 
```




<hr>



### function left\_neighbor 

_Returns the left neighbor of the gate._ 
```C++
device_structures::ConnectionSP falcon_core::physics::config::geometries::HasLeftNeighbor::left_neighbor () const
```




<hr>



### function operator= 

```C++
HasLeftNeighbor & falcon_core::physics::config::geometries::HasLeftNeighbor::operator= (
    const HasLeftNeighbor & other
) 
```




<hr>
## Protected Functions Documentation




### function HasLeftNeighbor [3/3]

```C++
falcon_core::physics::config::geometries::HasLeftNeighbor::HasLeftNeighbor () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::geometries::HasLeftNeighbor::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::geometries::HasLeftNeighbor::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/HasLeftNeighbor.hpp`

