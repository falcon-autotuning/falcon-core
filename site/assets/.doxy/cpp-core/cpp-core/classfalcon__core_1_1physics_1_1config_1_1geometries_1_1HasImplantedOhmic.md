

# Class falcon\_core::physics::config::geometries::HasImplantedOhmic



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md) **>** [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md)



_A gate with an ohmic below it._ 

* `#include <HasImplantedOhmic.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::physics::config::geometries::LeftReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md),  [falcon\_core::physics::config::geometries::RightReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**HasImplantedOhmic**](#function-hasimplantedohmic-13) (const HasImplantedOhmic & other) <br> |
|   | [**HasImplantedOhmic**](#function-hasimplantedohmic-23) (device\_structures::ConnectionSP ohmic) <br> |
|  device\_structures::ConnectionSP | [**ohmic**](#function-ohmic) () const<br>_Returns the ohmic below the gate._  |
|  HasImplantedOhmic & | [**operator=**](#function-operator) (const HasImplantedOhmic & other) <br> |


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
|   | [**HasImplantedOhmic**](#function-hasimplantedohmic-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function HasImplantedOhmic [1/3]

```C++
falcon_core::physics::config::geometries::HasImplantedOhmic::HasImplantedOhmic (
    const HasImplantedOhmic & other
) 
```




<hr>



### function HasImplantedOhmic [2/3]

```C++
falcon_core::physics::config::geometries::HasImplantedOhmic::HasImplantedOhmic (
    device_structures::ConnectionSP ohmic
) 
```




<hr>



### function ohmic 

_Returns the ohmic below the gate._ 
```C++
device_structures::ConnectionSP falcon_core::physics::config::geometries::HasImplantedOhmic::ohmic () const
```




<hr>



### function operator= 

```C++
HasImplantedOhmic & falcon_core::physics::config::geometries::HasImplantedOhmic::operator= (
    const HasImplantedOhmic & other
) 
```




<hr>
## Protected Functions Documentation




### function HasImplantedOhmic [3/3]

```C++
falcon_core::physics::config::geometries::HasImplantedOhmic::HasImplantedOhmic () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::geometries::HasImplantedOhmic::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::geometries::HasImplantedOhmic::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/HasImplantedOhmic.hpp`

