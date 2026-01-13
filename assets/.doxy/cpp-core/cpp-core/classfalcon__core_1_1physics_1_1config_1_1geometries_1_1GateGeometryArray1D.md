

# Class falcon\_core::physics::config::geometries::GateGeometryArray1D



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md) **>** [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md)



_A 1D array of quantum dots with left and right reservoirs, barrier gates, plunger gates, ohmics, and screening gates. This contains the geometry of the 1D array._ 

* `#include <GateGeometryArray1D.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)














## Public Types

| Type | Name |
| ---: | :--- |
| typedef typename device\_structures::Connections::const\_iterator | [**const\_iterator**](#typedef-const_iterator)  <br> |
| typedef typename device\_structures::Connections::iterator | [**iterator**](#typedef-iterator)  <br> |








































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GateGeometryArray1D**](#function-gategeometryarray1d-13) (const [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) & other) <br> |
|   | [**GateGeometryArray1D**](#function-gategeometryarray1d-23) (device\_structures::ConnectionsSP lineararray, device\_structures::ConnectionsSP screening\_gates) <br>_Starts the geometry of the gates._  |
|  DotGatesWithNeighborsSP | [**all\_dot\_gates**](#function-all_dot_gates) () const<br>_Gets all of the dot gates in the geometry._  |
|  void | [**append\_central\_gate**](#function-append_central_gate) (const device\_structures::ConnectionSP & left\_neighbor, const device\_structures::ConnectionSP & selected\_gate, const device\_structures::ConnectionSP & right\_neighbor) <br>_Appends a central gate to the geometry._  |
|  iterator | [**begin**](#function-begin-12) () <br> |
|  const\_iterator | [**begin**](#function-begin-22) () const<br> |
|  DotGatesWithNeighborsSP | [**central\_dot\_gates**](#function-central_dot_gates) () const<br>_Gets the central gates with localities._  |
|  iterator | [**end**](#function-end-12) () <br> |
|  const\_iterator | [**end**](#function-end-22) () const<br> |
|  DotGateWithNeighborsSP | [**left\_barrier**](#function-left_barrier) () const<br>_Gets the leftmost barrier gate in the array._  |
|  LeftReservoirWithImplantedOhmicSP | [**left\_reservoir**](#function-left_reservoir) () const<br>_Gets the left reservoir with implanted ohmic contact._  |
|  const device\_structures::ConnectionsSP & | [**lineararray**](#function-lineararray) () const<br>_Gets the linear array of connections._  |
|  device\_structures::ConnectionsSP | [**ohmics**](#function-ohmics) () const<br>_Gets the ohmics attached the the quantum dot geometry._  |
|  bool | [**operator!=**](#function-operator) (const [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) & other) const<br> |
|  [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) & | [**operator=**](#function-operator_1) (const [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**GateGeometryArray1D**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1GateGeometryArray1D.md) & other) const<br> |
|  device\_structures::ConnectionsSP | [**query\_neighbors**](#function-query_neighbors) (const device\_structures::ConnectionSP & gate) const<br>_Queries the neighbors of a gate._  |
|  device\_structures::ConnectionsSP | [**raw\_central\_gates**](#function-raw_central_gates) () const<br>_Gets the central gates without localities._  |
|  DotGateWithNeighborsSP | [**right\_barrier**](#function-right_barrier) () const<br>_Gets the rightmost barrier gate in the array._  |
|  RightReservoirWithImplantedOhmicSP | [**right\_reservoir**](#function-right_reservoir) () const<br>_Gets the right reservoir with implanted ohmic contact._  |
|  const device\_structures::ConnectionsSP & | [**screening\_gates**](#function-screening_gates) () const<br>_Gets the screening gates in the geometry._  |


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
|   | [**GateGeometryArray1D**](#function-gategeometryarray1d-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Types Documentation




### typedef const\_iterator 

```C++
using falcon_core::physics::config::geometries::GateGeometryArray1D::const_iterator =  typename device_structures::Connections::const_iterator;
```




<hr>



### typedef iterator 

```C++
using falcon_core::physics::config::geometries::GateGeometryArray1D::iterator =  typename device_structures::Connections::iterator;
```




<hr>
## Public Functions Documentation




### function GateGeometryArray1D [1/3]

```C++
falcon_core::physics::config::geometries::GateGeometryArray1D::GateGeometryArray1D (
    const GateGeometryArray1D & other
) 
```




<hr>



### function GateGeometryArray1D [2/3]

_Starts the geometry of the gates._ 
```C++
falcon_core::physics::config::geometries::GateGeometryArray1D::GateGeometryArray1D (
    device_structures::ConnectionsSP lineararray,
    device_structures::ConnectionsSP screening_gates
) 
```





**Parameters:**


* `lineararray` A linear array of gates and ohmics in the order left to right in the channel. 
* `screening_gates` A collection of two screening gates. 



**Exception:**


* `std::invalid_argument` if the input does not conform to the expected structure. 




        

<hr>



### function all\_dot\_gates 

_Gets all of the dot gates in the geometry._ 
```C++
DotGatesWithNeighborsSP falcon_core::physics::config::geometries::GateGeometryArray1D::all_dot_gates () const
```





**Returns:**

A collection of all dot gates in the array with localities. 





        

<hr>



### function append\_central\_gate 

_Appends a central gate to the geometry._ 
```C++
void falcon_core::physics::config::geometries::GateGeometryArray1D::append_central_gate (
    const device_structures::ConnectionSP & left_neighbor,
    const device_structures::ConnectionSP & selected_gate,
    const device_structures::ConnectionSP & right_neighbor
) 
```





**Parameters:**


* `gate` The gate to append. 




        

<hr>



### function begin [1/2]

```C++
iterator falcon_core::physics::config::geometries::GateGeometryArray1D::begin () 
```




<hr>



### function begin [2/2]

```C++
const_iterator falcon_core::physics::config::geometries::GateGeometryArray1D::begin () const
```




<hr>



### function central\_dot\_gates 

_Gets the central gates with localities._ 
```C++
DotGatesWithNeighborsSP falcon_core::physics::config::geometries::GateGeometryArray1D::central_dot_gates () const
```





**Returns:**

The central gates with localities. 





        

<hr>



### function end [1/2]

```C++
iterator falcon_core::physics::config::geometries::GateGeometryArray1D::end () 
```




<hr>



### function end [2/2]

```C++
const_iterator falcon_core::physics::config::geometries::GateGeometryArray1D::end () const
```




<hr>



### function left\_barrier 

_Gets the leftmost barrier gate in the array._ 
```C++
DotGateWithNeighborsSP falcon_core::physics::config::geometries::GateGeometryArray1D::left_barrier () const
```





**Returns:**

The leftmost barrier gate. 





        

<hr>



### function left\_reservoir 

_Gets the left reservoir with implanted ohmic contact._ 
```C++
LeftReservoirWithImplantedOhmicSP falcon_core::physics::config::geometries::GateGeometryArray1D::left_reservoir () const
```





**Returns:**

The left reservoir with implanted ohmic contact. 





        

<hr>



### function lineararray 

_Gets the linear array of connections._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::geometries::GateGeometryArray1D::lineararray () const
```





**Returns:**

The linear array of connections. 





        

<hr>



### function ohmics 

_Gets the ohmics attached the the quantum dot geometry._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::geometries::GateGeometryArray1D::ohmics () const
```





**Returns:**

The ohmics attached to the quantum dot geometry. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::geometries::GateGeometryArray1D::operator!= (
    const GateGeometryArray1D & other
) const
```




<hr>



### function operator= 

```C++
GateGeometryArray1D & falcon_core::physics::config::geometries::GateGeometryArray1D::operator= (
    const GateGeometryArray1D & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::geometries::GateGeometryArray1D::operator== (
    const GateGeometryArray1D & other
) const
```




<hr>



### function query\_neighbors 

_Queries the neighbors of a gate._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::geometries::GateGeometryArray1D::query_neighbors (
    const device_structures::ConnectionSP & gate
) const
```





**Parameters:**


* `gate` The gate to query neighbors for 



**Returns:**

The collection of neighboring gates 





        

<hr>



### function raw\_central\_gates 

_Gets the central gates without localities._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::geometries::GateGeometryArray1D::raw_central_gates () const
```





**Returns:**

The central gates without localities. 





        

<hr>



### function right\_barrier 

_Gets the rightmost barrier gate in the array._ 
```C++
DotGateWithNeighborsSP falcon_core::physics::config::geometries::GateGeometryArray1D::right_barrier () const
```





**Returns:**

The rightmost barrier gate. 





        

<hr>



### function right\_reservoir 

_Gets the right reservoir with implanted ohmic contact._ 
```C++
RightReservoirWithImplantedOhmicSP falcon_core::physics::config::geometries::GateGeometryArray1D::right_reservoir () const
```





**Returns:**

The right reservoir with implanted ohmic contact. 





        

<hr>



### function screening\_gates 

_Gets the screening gates in the geometry._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::geometries::GateGeometryArray1D::screening_gates () const
```





**Returns:**

The screening gates in the geometry. 





        

<hr>
## Protected Functions Documentation




### function GateGeometryArray1D [3/3]

```C++
falcon_core::physics::config::geometries::GateGeometryArray1D::GateGeometryArray1D () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::geometries::GateGeometryArray1D::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::geometries::GateGeometryArray1D::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/GateGeometryArray1D.hpp`

