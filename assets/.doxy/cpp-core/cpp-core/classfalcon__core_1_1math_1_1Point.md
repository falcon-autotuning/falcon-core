

# Class falcon\_core::math::Point



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**Point**](classfalcon__core_1_1math_1_1Point.md)



_Represents a point in a multi-dimensional space, indexed by connections._ [More...](#detailed-description)

* `#include <Point.hpp>`



Inherits the following classes: [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Point**](#function-point-14) (const [**Point**](classfalcon__core_1_1math_1_1Point.md) & other) <br> |
|   | [**Point**](#function-point-24) () <br> |
|   | [**Point**](#function-point-34) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), double &gt; & init, const physics::units::SymbolUnitSP & unit) <br> |
|   | [**Point**](#function-point-44) (const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; & init) <br> |
|  const generic::ListSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**connections**](#function-connections) () const<br>_Returns the connections for the point._  |
|  const generic::MapSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md) &gt; | [**coordinates**](#function-coordinates) () const<br>_Returns the coordinates for the point._  |
|  std::pair&lt; iterator, bool &gt; | [**insert**](#function-insert) (const physics::device\_structures::ConnectionSP & key, const QuantitySP & value) <br>_an overide of insert to make sure units are fixed._  |
|  void | [**insert\_or\_assign**](#function-insert_or_assign) (const physics::device\_structures::ConnectionSP & key, const QuantitySP & value) <br>_an overide of insert to make sure units are fixed._  |
|  bool | [**operator!=**](#function-operator) (const [**Point**](classfalcon__core_1_1math_1_1Point.md) & other) const<br> |
|  std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**operator\***](#function-operator_1) (double scalar) const<br> |
|  std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**operator+**](#function-operator_2) (const std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**operator-**](#function-operator-) (const std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**operator-**](#function-operator-_1) () const<br> |
|  std::shared\_ptr&lt; [**Point**](classfalcon__core_1_1math_1_1Point.md) &gt; | [**operator/**](#function-operator_3) (double scalar) const<br> |
|  [**Point**](classfalcon__core_1_1math_1_1Point.md) & | [**operator=**](#function-operator_4) (const [**Point**](classfalcon__core_1_1math_1_1Point.md) & other) <br> |
|  bool | [**operator==**](#function-operator_5) (const [**Point**](classfalcon__core_1_1math_1_1Point.md) & other) const<br> |
|  void | [**set\_unit**](#function-set_unit) (physics::units::SymbolUnitSP unit) <br> |
|  const physics::units::SymbolUnitSP | [**unit**](#function-unit) () const<br>_Returns the SI unit for the point._  |


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


Each [**Point**](classfalcon__core_1_1math_1_1Point.md) stores a mapping from device connections to coordinate values, along with a unit. Supports arithmetic operations and iteration. 


    
## Public Functions Documentation




### function Point [1/4]

```C++
falcon_core::math::Point::Point (
    const Point & other
) 
```




<hr>



### function Point [2/4]

```C++
falcon_core::math::Point::Point () 
```




<hr>



### function Point [3/4]

```C++
falcon_core::math::Point::Point (
    const generic::MapSP< physics::device_structures::Connection , double > & init,
    const physics::units::SymbolUnitSP & unit
) 
```




<hr>



### function Point [4/4]

```C++
falcon_core::math::Point::Point (
    const generic::MapSP< physics::device_structures::Connection , Quantity > & init
) 
```




<hr>



### function connections 

_Returns the connections for the point._ 
```C++
const generic::ListSP< physics::device_structures::Connection > falcon_core::math::Point::connections () const
```




<hr>



### function coordinates 

_Returns the coordinates for the point._ 
```C++
const generic::MapSP< physics::device_structures::Connection , Quantity > falcon_core::math::Point::coordinates () const
```




<hr>



### function insert 

_an overide of insert to make sure units are fixed._ 
```C++
std::pair< iterator, bool > falcon_core::math::Point::insert (
    const physics::device_structures::ConnectionSP & key,
    const QuantitySP & value
) 
```




<hr>



### function insert\_or\_assign 

_an overide of insert to make sure units are fixed._ 
```C++
void falcon_core::math::Point::insert_or_assign (
    const physics::device_structures::ConnectionSP & key,
    const QuantitySP & value
) 
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::Point::operator!= (
    const Point & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Point > falcon_core::math::Point::operator* (
    double scalar
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< Point > falcon_core::math::Point::operator+ (
    const std::shared_ptr< Point > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Point > falcon_core::math::Point::operator- (
    const std::shared_ptr< Point > & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Point > falcon_core::math::Point::operator- () const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Point > falcon_core::math::Point::operator/ (
    double scalar
) const
```




<hr>



### function operator= 

```C++
Point & falcon_core::math::Point::operator= (
    const Point & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::Point::operator== (
    const Point & other
) const
```




<hr>



### function set\_unit 

```C++
void falcon_core::math::Point::set_unit (
    physics::units::SymbolUnitSP unit
) 
```




<hr>



### function unit 

_Returns the SI unit for the point._ 
```C++
const physics::units::SymbolUnitSP falcon_core::math::Point::unit () const
```




<hr>
## Protected Functions Documentation




### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::Point::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::Point::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/Point.hpp`

