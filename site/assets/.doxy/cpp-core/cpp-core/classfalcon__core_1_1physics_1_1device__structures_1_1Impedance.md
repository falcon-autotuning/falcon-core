

# Class falcon\_core::physics::device\_structures::Impedance



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md) **>** [**Impedance**](classfalcon__core_1_1physics_1_1device__structures_1_1Impedance.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Impedance**](#function-impedance-13) (const Impedance & other) <br> |
|   | [**Impedance**](#function-impedance-23) (std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; connection, double resistance, double capacitance) <br> |
|  double | [**capacitance**](#function-capacitance) () const<br>_Gets the capacitance of the impedance._  |
|  ConnectionSP | [**connection**](#function-connection) () const<br>_Gets the connection leading to the fridge with this impedance._  |
|  bool | [**operator!=**](#function-operator) (const Impedance & other) const<br> |
|  Impedance & | [**operator=**](#function-operator_1) (const Impedance & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const Impedance & other) const<br> |
|  double | [**resistance**](#function-resistance) () const<br>_Gets the resistance of the impedance._  |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; Impedance &gt; | [**create**](#function-create) (const ConnectionSP connection, const double resistance, const double capacitance) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Impedance**](#function-impedance-33) () <br> |








## Public Functions Documentation




### function Impedance [1/3]

```C++
falcon_core::physics::device_structures::Impedance::Impedance (
    const Impedance & other
) 
```




<hr>



### function Impedance [2/3]

```C++
falcon_core::physics::device_structures::Impedance::Impedance (
    std::shared_ptr< Connection > connection,
    double resistance,
    double capacitance
) 
```




<hr>



### function capacitance 

_Gets the capacitance of the impedance._ 
```C++
double falcon_core::physics::device_structures::Impedance::capacitance () const
```





**Returns:**

The capacitance in farads 





        

<hr>



### function connection 

_Gets the connection leading to the fridge with this impedance._ 
```C++
ConnectionSP falcon_core::physics::device_structures::Impedance::connection () const
```





**Returns:**

A shared pointer to the BaseConnection 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::device_structures::Impedance::operator!= (
    const Impedance & other
) const
```




<hr>



### function operator= 

```C++
Impedance & falcon_core::physics::device_structures::Impedance::operator= (
    const Impedance & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::device_structures::Impedance::operator== (
    const Impedance & other
) const
```




<hr>



### function resistance 

_Gets the resistance of the impedance._ 
```C++
double falcon_core::physics::device_structures::Impedance::resistance () const
```





**Returns:**

The resistance in ohms 





        

<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::device_structures::Impedance::serialize (
    Archive & ar
) 
```




<hr>
## Public Static Functions Documentation




### function create 

```C++
static std::shared_ptr< Impedance > falcon_core::physics::device_structures::Impedance::create (
    const ConnectionSP connection,
    const double resistance,
    const double capacitance
) 
```




<hr>
## Protected Functions Documentation




### function Impedance [3/3]

```C++
falcon_core::physics::device_structures::Impedance::Impedance () 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::device_structures::Impedance::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/device_structures/Impedance.hpp`

