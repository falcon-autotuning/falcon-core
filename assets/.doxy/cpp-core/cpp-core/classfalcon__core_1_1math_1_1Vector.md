

# Class falcon\_core::math::Vector



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**Vector**](classfalcon__core_1_1math_1_1Vector.md)



_Represents a vector in a multi-dimensional space, defined by start and end points._ [More...](#detailed-description)

* `#include <Vector.hpp>`



Inherits the following classes: [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Vector**](#function-vector-19) (const [**Vector**](classfalcon__core_1_1math_1_1Vector.md) & other) <br> |
|   | [**Vector**](#function-vector-29) (const PointSP & start, const PointSP & end) <br> |
|   | [**Vector**](#function-vector-39) (const PointSP & end) <br> |
|   | [**Vector**](#function-vector-49) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; & end) <br> |
|   | [**Vector**](#function-vector-59) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; & start, const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; & end) <br> |
|   | [**Vector**](#function-vector-69) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; & end, falcon\_core::physics::units::SymbolUnitSP unit) <br> |
|   | [**Vector**](#function-vector-79) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; & start, const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; & end, falcon\_core::physics::units::SymbolUnitSP unit) <br> |
|   | [**Vector**](#function-vector-89) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**generic::Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; &gt; map) <br> |
|  const physics::device\_structures::ConnectionsSP & | [**connections**](#function-connections) () const<br>_Returns the affected connections for this vector._  |
|  const PointSP | [**endPoint**](#function-endpoint) () const<br>_Returns the point at the end._  |
|  const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; | [**end\_map**](#function-end_map) () const<br>_Returns the raw unitless map of the ending point._  |
|  const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; | [**end\_quantities**](#function-end_quantities) () const<br>_Returns the raw map of the ending point._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**extend**](#function-extend-12) (const double & extension) const<br>_Extends a vector in place with its start point anchored._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**extend**](#function-extend-22) (const int & extension) const<br>_Extends a vector in place with its start point anchored._  |
|  const double | [**magnitude**](#function-magnitude) () const<br>_The magnitude of the vector._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**normalize**](#function-normalize) () const<br>_Returns the normalized vector starting at the anchored starting point._  |
|  bool | [**operator!=**](#function-operator) (const [**Vector**](classfalcon__core_1_1math_1_1Vector.md) & other) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator\***](#function-operator_1) (double scalar) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator\***](#function-operator_2) (int scalar) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator+**](#function-operator_3) (const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator-**](#function-operator-) (const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator-**](#function-operator-_1) () const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator/**](#function-operator_4) (double scalar) const<br> |
|  std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**operator/**](#function-operator_5) (int scalar) const<br> |
|  [**Vector**](classfalcon__core_1_1math_1_1Vector.md) & | [**operator=**](#function-operator_6) (const [**Vector**](classfalcon__core_1_1math_1_1Vector.md) & other) <br> |
|  bool | [**operator==**](#function-operator_7) (const [**Vector**](classfalcon__core_1_1math_1_1Vector.md) & other) const<br> |
|  const physics::device\_structures::ConnectionSP | [**principle\_connection**](#function-principle_connection) () const<br>_returns the principle\_connection that is the largest._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**project**](#function-project) (const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; & other) const<br>_Projects this vector onto another._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**shrink**](#function-shrink-12) (const double & shrink) const<br>_Shrinks a vector in place with its start point anchored._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**shrink**](#function-shrink-22) (const int & shrink) const<br>_Shrinks a vector in place with its start point anchored._  |
|  const PointSP | [**startPoint**](#function-startpoint) () const<br>_Returns the point at the start._  |
|  const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; | [**start\_map**](#function-start_map) () const<br>_Returns the raw unitless map of the starting point._  |
|  const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; | [**start\_quantities**](#function-start_quantities) () const<br>_Returns the raw map of the starting point._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**translate**](#function-translate-13) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; point, const physics::units::SymbolUnitSP unit) const<br>_Displaces the origin of a vector by a point._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**translate**](#function-translate-23) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; point) const<br>_Displaces the origin of a vector by a point._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**translate**](#function-translate-33) (const PointSP & point) const<br>_Displaces the origin of a vector by a point._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**translate\_to\_origin**](#function-translate_to_origin) () const<br>_Translates a vector to the origin._  |
|  const falcon\_core::physics::units::SymbolUnitSP & | [**unit**](#function-unit) () const<br>_Returns the unit of this vector._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**unit\_vector**](#function-unit_vector) () const<br>_Generates the unit vector for the direction of this vector._  |
|  const std::shared\_ptr&lt; [**Vector**](classfalcon__core_1_1math_1_1Vector.md) &gt; | [**update\_start\_from\_states**](#function-update_start_from_states) (const communications::voltage\_states::DeviceVoltageStatesSP & state) const<br>_Updates the vector to start from teh given DeviceCVoltageStates._  |
|  void | [**update\_unit**](#function-update_unit) (const physics::units::SymbolUnitSP & unit) <br>_Updates the unit of this vector._  |


## Public Functions inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
|   | [**Map**](classfalcon__core_1_1generic_1_1Map.md#function-map-14) (const [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; & other) <br> |
|   | [**Map**](classfalcon__core_1_1generic_1_1Map.md#function-map-24) () <br> |
|   | [**Map**](classfalcon__core_1_1generic_1_1Map.md#function-map-34) (const std::vector&lt; std::pair&lt; typename ContainerItem::StoredT1, typename ContainerItem::StoredT2 &gt; &gt; & init) <br> |
|   | [**Map**](classfalcon__core_1_1generic_1_1Map.md#function-map-44) (const Container & init) <br> |
|  ContainerItem::StoredT2 | [**at**](classfalcon__core_1_1generic_1_1Map.md#function-at-12) (const typename ContainerItem::StoredT1 & key) <br> |
|  const ContainerItem::StoredT2 | [**at**](classfalcon__core_1_1generic_1_1Map.md#function-at-22) (const typename ContainerItem::StoredT1 & key) const<br> |
|  iterator | [**begin**](classfalcon__core_1_1generic_1_1Map.md#function-begin-12) () <br> |
|  const\_iterator | [**begin**](classfalcon__core_1_1generic_1_1Map.md#function-begin-22) () const<br> |
|  const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1Map.md#function-cbegin) () const<br> |
|  const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1Map.md#function-cend) () const<br> |
|  void | [**clear**](classfalcon__core_1_1generic_1_1Map.md#function-clear) () <br> |
|  bool | [**contains**](classfalcon__core_1_1generic_1_1Map.md#function-contains) (const typename ContainerItem::StoredT1 & key) const<br> |
|  std::shared\_ptr&lt; [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; &gt; | [**create**](classfalcon__core_1_1generic_1_1Map.md#function-create) (const Container & init) <br> |
|  bool | [**empty**](classfalcon__core_1_1generic_1_1Map.md#function-empty) () const<br> |
|  iterator | [**end**](classfalcon__core_1_1generic_1_1Map.md#function-end-12) () <br> |
|  const\_iterator | [**end**](classfalcon__core_1_1generic_1_1Map.md#function-end-22) () const<br> |
|  void | [**erase**](classfalcon__core_1_1generic_1_1Map.md#function-erase) (const typename ContainerItem::StoredT1 & key) <br> |
|  std::pair&lt; iterator, bool &gt; | [**insert**](classfalcon__core_1_1generic_1_1Map.md#function-insert) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  void | [**insert\_or\_assign**](classfalcon__core_1_1generic_1_1Map.md#function-insert_or_assign) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  const std::shared\_ptr&lt; Container &gt; | [**items**](classfalcon__core_1_1generic_1_1Map.md#function-items-12) () const<br> |
|  std::shared\_ptr&lt; Container &gt; | [**items**](classfalcon__core_1_1generic_1_1Map.md#function-items-22) () <br> |
|  const generic::ListSP&lt; Key &gt; | [**keys**](classfalcon__core_1_1generic_1_1Map.md#function-keys) () const<br>_Return the keys of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._ |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1Map.md#function-operator) (const [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; & other) const<br> |
|  [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1Map.md#function-operator_1) (const [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1Map.md#function-operator_2) (const [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; & other) const<br> |
|  ContainerItem::StoredT2 | [**operator[]**](classfalcon__core_1_1generic_1_1Map.md#function-operator_3) (const typename ContainerItem::StoredT1 & key) <br> |
|  std::size\_t | [**size**](classfalcon__core_1_1generic_1_1Map.md#function-size) () const<br> |
|  const generic::ListSP&lt; Value &gt; | [**values**](classfalcon__core_1_1generic_1_1Map.md#function-values) () const<br>_Return the values of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._ |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |




## Public Static Functions inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**Map**](classfalcon__core_1_1generic_1_1Map.md)&lt; Key, Value &gt; &gt; | [**create\_empty**](classfalcon__core_1_1generic_1_1Map.md#function-create_empty) () <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




## Protected Types inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](classfalcon__core_1_1generic_1_1Map.md#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](classfalcon__core_1_1generic_1_1Map.md#typedef-iterator)  <br> |


























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Vector**](#function-vector-99) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
|  iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-14) (const Key & key) <br> |
|  iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-24) (const std::shared\_ptr&lt; Key &gt; & key) <br> |
|  const\_iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-34) (const Key & key) const<br> |
|  const\_iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-44) (const std::shared\_ptr&lt; Key &gt; & key) const<br> |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Map.md#function-serialize) (Archive & ar) <br> |










## Detailed Description


[**Vector**](classfalcon__core_1_1math_1_1Vector.md) supports arithmetic operations, magnitude calculation, and unit conversion. Each vector is defined by two points and a set of device connections. 


    
## Public Functions Documentation




### function Vector [1/9]

```C++
falcon_core::math::Vector::Vector (
    const Vector & other
) 
```




<hr>



### function Vector [2/9]

```C++
falcon_core::math::Vector::Vector (
    const PointSP & start,
    const PointSP & end
) 
```




<hr>



### function Vector [3/9]

```C++
falcon_core::math::Vector::Vector (
    const PointSP & end
) 
```




<hr>



### function Vector [4/9]

```C++
falcon_core::math::Vector::Vector (
    const generic::MapSP< physics::device_structures::Connection , Quantity > & end
) 
```




<hr>



### function Vector [5/9]

```C++
falcon_core::math::Vector::Vector (
    const generic::MapSP< physics::device_structures::Connection , Quantity > & start,
    const generic::MapSP< physics::device_structures::Connection , Quantity > & end
) 
```




<hr>



### function Vector [6/9]

```C++
falcon_core::math::Vector::Vector (
    const generic::MapSP< physics::device_structures::Connection , double > & end,
    falcon_core::physics::units::SymbolUnitSP unit
) 
```




<hr>



### function Vector [7/9]

```C++
falcon_core::math::Vector::Vector (
    const generic::MapSP< physics::device_structures::Connection , double > & start,
    const generic::MapSP< physics::device_structures::Connection , double > & end,
    falcon_core::physics::units::SymbolUnitSP unit
) 
```




<hr>



### function Vector [8/9]

```C++
falcon_core::math::Vector::Vector (
    const generic::MapSP< physics::device_structures::Connection , generic::Pair < Quantity , Quantity > > map
) 
```




<hr>



### function connections 

_Returns the affected connections for this vector._ 
```C++
const physics::device_structures::ConnectionsSP & falcon_core::math::Vector::connections () const
```




<hr>



### function endPoint 

_Returns the point at the end._ 
```C++
const PointSP falcon_core::math::Vector::endPoint () const
```




<hr>



### function end\_map 

_Returns the raw unitless map of the ending point._ 
```C++
const generic::MapSP< physics::device_structures::Connection , double > falcon_core::math::Vector::end_map () const
```




<hr>



### function end\_quantities 

_Returns the raw map of the ending point._ 
```C++
const generic::MapSP< physics::device_structures::Connection , Quantity > falcon_core::math::Vector::end_quantities () const
```




<hr>



### function extend [1/2]

_Extends a vector in place with its start point anchored._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::extend (
    const double & extension
) const
```




<hr>



### function extend [2/2]

_Extends a vector in place with its start point anchored._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::extend (
    const int & extension
) const
```




<hr>



### function magnitude 

_The magnitude of the vector._ 
```C++
const double falcon_core::math::Vector::magnitude () const
```




<hr>



### function normalize 

_Returns the normalized vector starting at the anchored starting point._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::normalize () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::Vector::operator!= (
    const Vector & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator* (
    double scalar
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator* (
    int scalar
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator+ (
    const std::shared_ptr< Vector > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator- (
    const std::shared_ptr< Vector > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator- () const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator/ (
    double scalar
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Vector > falcon_core::math::Vector::operator/ (
    int scalar
) const
```




<hr>



### function operator= 

```C++
Vector & falcon_core::math::Vector::operator= (
    const Vector & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::Vector::operator== (
    const Vector & other
) const
```




<hr>



### function principle\_connection 

_returns the principle\_connection that is the largest._ 
```C++
const physics::device_structures::ConnectionSP falcon_core::math::Vector::principle_connection () const
```




<hr>



### function project 

_Projects this vector onto another._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::project (
    const std::shared_ptr< Vector > & other
) const
```




<hr>



### function shrink [1/2]

_Shrinks a vector in place with its start point anchored._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::shrink (
    const double & shrink
) const
```




<hr>



### function shrink [2/2]

_Shrinks a vector in place with its start point anchored._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::shrink (
    const int & shrink
) const
```




<hr>



### function startPoint 

_Returns the point at the start._ 
```C++
const PointSP falcon_core::math::Vector::startPoint () const
```




<hr>



### function start\_map 

_Returns the raw unitless map of the starting point._ 
```C++
const generic::MapSP< physics::device_structures::Connection , double > falcon_core::math::Vector::start_map () const
```




<hr>



### function start\_quantities 

_Returns the raw map of the starting point._ 
```C++
const generic::MapSP< physics::device_structures::Connection , Quantity > falcon_core::math::Vector::start_quantities () const
```




<hr>



### function translate [1/3]

_Displaces the origin of a vector by a point._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::translate (
    const generic::MapSP< physics::device_structures::Connection , double > point,
    const physics::units::SymbolUnitSP unit
) const
```





**Parameters:**


* `point` the diplacement 
* `unit` the unit of displacement 




        

<hr>



### function translate [2/3]

_Displaces the origin of a vector by a point._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::translate (
    const generic::MapSP< physics::device_structures::Connection , Quantity > point
) const
```





**Parameters:**


* `point` the diplacement 




        

<hr>



### function translate [3/3]

_Displaces the origin of a vector by a point._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::translate (
    const PointSP & point
) const
```





**Parameters:**


* `point` the diplacement 




        

<hr>



### function translate\_to\_origin 

_Translates a vector to the origin._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::translate_to_origin () const
```




<hr>



### function unit 

_Returns the unit of this vector._ 
```C++
const falcon_core::physics::units::SymbolUnitSP & falcon_core::math::Vector::unit () const
```




<hr>



### function unit\_vector 

_Generates the unit vector for the direction of this vector._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::unit_vector () const
```




<hr>



### function update\_start\_from\_states 

_Updates the vector to start from teh given DeviceCVoltageStates._ 
```C++
const std::shared_ptr< Vector > falcon_core::math::Vector::update_start_from_states (
    const communications::voltage_states::DeviceVoltageStatesSP & state
) const
```





**Parameters:**


* `state` the new device voltage state. 



**Returns:**

the displaced vector which starts at the given state. 





        

<hr>



### function update\_unit 

_Updates the unit of this vector._ 
```C++
void falcon_core::math::Vector::update_unit (
    const physics::units::SymbolUnitSP & unit
) 
```




<hr>
## Protected Functions Documentation




### function Vector [9/9]

```C++
falcon_core::math::Vector::Vector () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::Vector::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::Vector::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/Vector.hpp`

