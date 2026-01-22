

# Class falcon\_core::generic::Song



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**Song**](classfalcon__core_1_1generic_1_1Song.md)



_Abstract base for all serializable_ [_**Song**_](classfalcon__core_1_1generic_1_1Song.md) _objects._[More...](#detailed-description)

* `#include <Song.hpp>`





Inherited by the following classes: [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md),  [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Pair](classfalcon__core_1_1generic_1_1Pair.md),  [falcon\_core::autotuner\_interfaces::contexts::BaseContext](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1BaseContext.md),  [falcon\_core::autotuner\_interfaces::interpretations::InterpretationContext](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md),  [falcon\_core::autotuner\_interfaces::names::Channel](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1Channel.md),  [falcon\_core::autotuner\_interfaces::names::NameBase](classfalcon__core_1_1autotuner__interfaces_1_1names_1_1NameBase.md),  [falcon\_core::communications::HDF5Data](classfalcon__core_1_1communications_1_1HDF5Data.md),  [falcon\_core::communications::Time](classfalcon__core_1_1communications_1_1Time.md),  [falcon\_core::communications::messages::BaseMessage](classfalcon__core_1_1communications_1_1messages_1_1BaseMessage.md),  [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md),  [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md),  [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md),  [falcon\_core::generic::Pair](classfalcon__core_1_1generic_1_1Pair.md),  [falcon\_core::instrument\_interfaces::names::InstrumentPort](classfalcon__core_1_1instrument__interfaces_1_1names_1_1InstrumentPort.md),  [falcon\_core::math::Quantity](classfalcon__core_1_1math_1_1Quantity.md),  [falcon\_core::math::arrays::IncreasingAlignment](classfalcon__core_1_1math_1_1arrays_1_1IncreasingAlignment.md),  [falcon\_core::math::discrete\_spaces::DiscreteSpace](classfalcon__core_1_1math_1_1discrete__spaces_1_1DiscreteSpace.md),  [falcon\_core::math::discrete\_spaces::Discretizer](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md),  [falcon\_core::math::domains::Domain](classfalcon__core_1_1math_1_1domains_1_1Domain.md),  [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md),  [falcon\_core::physics::config::core::VoltageConstraints](classfalcon__core_1_1physics_1_1config_1_1core_1_1VoltageConstraints.md),  [falcon\_core::physics::config::geometries::GateGeometryArray1D](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md),  [falcon\_core::physics::config::geometries::HasImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md),  [falcon\_core::physics::config::geometries::HasLeftNeighbor](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasLeftNeighbor.md),  [falcon\_core::physics::config::geometries::HasRightNeighbor](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md),  [falcon\_core::physics::device\_structures::Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md),  [falcon\_core::physics::device\_structures::Impedance](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md),  [falcon\_core::physics::units::SymbolUnit](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md),  [falcon\_core::physics::units::Unit](classfalcon__core_1_1physics_1_1units_1_1Unit.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](#function-song) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |


























## Detailed Description


Inherit from [**Song**](classfalcon__core_1_1generic_1_1Song.md) in your serializable class, implement [**serialize()**](classfalcon__core_1_1generic_1_1Song.md#function-serialize), and register with cereal.




**Note:**

std::hash&lt;falcon\_core::generic::Song&gt; is specialized (see Song.cpp) so [**Song**](classfalcon__core_1_1generic_1_1Song.md) can be used as a key in std::unordered\_map.





## Usage



```C++
struct Animal : public Song {
    int legs = 4;
    template<class Archive>
    void serialize(Archive& ar) { ar(CEREAL_NVP(legs)); }
    virtual ~Animal() = default;
};
struct Dog : public Animal {
    bool tail = true;
    template<class Archive>
    void serialize(Archive& ar) {
        ar(cereal::base_class<Animal>(this), CEREAL_NVP(tail));
    }
};
CEREAL_REGISTER_TYPE(Animal)
CEREAL_REGISTER_TYPE(Dog)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Animal, Dog)
```
 



    
## Public Functions Documentation




### function serialize 

_cereal serialization interface. Override in derived classes._ 
```C++
template<class Archive>
inline void falcon_core::generic::Song::serialize (
    Archive &
) 
```




<hr>



### function to\_json\_string 

_Serialize this object to a JSON string._ 
```C++
std::string falcon_core::generic::Song::to_json_string () const
```




<hr>



### function ~Song 

```C++
virtual falcon_core::generic::Song::~Song () = default
```




<hr>
## Public Static Functions Documentation




### function from\_json\_string 

_Deserialize an object from a JSON string._ 
```C++
template<typename T>
static inline std::shared_ptr< T > falcon_core::generic::Song::from_json_string (
    const std::string & json
) 
```





**Returns:**

std::shared\_ptr&lt;Song&gt; (actually the derived type) 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/Song.hpp`

