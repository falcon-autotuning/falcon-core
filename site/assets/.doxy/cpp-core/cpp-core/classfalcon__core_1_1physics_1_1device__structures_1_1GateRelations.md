

# Class falcon\_core::physics::device\_structures::GateRelations



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md) **>** [**GateRelations**](classfalcon__core_1_1physics_1_1device__structures_1_1GateRelations.md)



_Holds the relations between gates and their neighbors._ 

* `#include <GateRelations.hpp>`



Inherits the following classes: [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GateRelations**](#function-gaterelations-12) () <br> |
|   | [**GateRelations**](#function-gaterelations-22) (std::vector&lt; std::pair&lt; ConnectionSP, ConnectionsSP &gt; &gt; init) <br> |
|  std::pair&lt; [**generic::List**](classfalcon__core_1_1generic_1_1List.md)&lt; [**generic::Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md), [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; &gt;::iterator, bool &gt; | [**insert**](#function-insert) (const ConnectionSP & key, const ConnectionsSP & value) <br>_Override the assert method to force gate typing._  |
|  void | [**insert\_or\_assign**](#function-insert_or_assign) (const ConnectionSP & key, const ConnectionsSP & value) <br>_Override the default Map assignment to force gate typing._  |
|  bool | [**operator!=**](#function-operator) (const GateRelations & other) const<br> |
|  bool | [**operator==**](#function-operator_1) (const GateRelations & other) const<br> |


## Public Functions inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
|   | [**Map**](classfalcon__core_1_1generic_1_1Map.md#function-map-14) (const Map&lt; Key, Value &gt; & other) <br> |
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
|  std::shared\_ptr&lt; Map&lt; Key, Value &gt; &gt; | [**create**](classfalcon__core_1_1generic_1_1Map.md#function-create) (const Container & init) <br> |
|  bool | [**empty**](classfalcon__core_1_1generic_1_1Map.md#function-empty) () const<br> |
|  iterator | [**end**](classfalcon__core_1_1generic_1_1Map.md#function-end-12) () <br> |
|  const\_iterator | [**end**](classfalcon__core_1_1generic_1_1Map.md#function-end-22) () const<br> |
|  void | [**erase**](classfalcon__core_1_1generic_1_1Map.md#function-erase) (const typename ContainerItem::StoredT1 & key) <br> |
|  std::pair&lt; iterator, bool &gt; | [**insert**](classfalcon__core_1_1generic_1_1Map.md#function-insert) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  void | [**insert\_or\_assign**](classfalcon__core_1_1generic_1_1Map.md#function-insert_or_assign) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  const std::shared\_ptr&lt; Container &gt; | [**items**](classfalcon__core_1_1generic_1_1Map.md#function-items-12) () const<br> |
|  std::shared\_ptr&lt; Container &gt; | [**items**](classfalcon__core_1_1generic_1_1Map.md#function-items-22) () <br> |
|  const generic::ListSP&lt; Key &gt; | [**keys**](classfalcon__core_1_1generic_1_1Map.md#function-keys) () const<br>_Return the keys of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._ |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1Map.md#function-operator) (const Map&lt; Key, Value &gt; & other) const<br> |
|  Map&lt; Key, Value &gt; & | [**operator=**](classfalcon__core_1_1generic_1_1Map.md#function-operator_1) (const Map&lt; Key, Value &gt; & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1Map.md#function-operator_2) (const Map&lt; Key, Value &gt; & other) const<br> |
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
|  std::shared\_ptr&lt; Map&lt; Key, Value &gt; &gt; | [**create\_empty**](classfalcon__core_1_1generic_1_1Map.md#function-create_empty) () <br> |


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




























































## Protected Functions inherited from falcon_core::generic::Map

See [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)

| Type | Name |
| ---: | :--- |
|  iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-14) (const Key & key) <br> |
|  iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-24) (const std::shared\_ptr&lt; Key &gt; & key) <br> |
|  const\_iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-34) (const Key & key) const<br> |
|  const\_iterator | [**find**](classfalcon__core_1_1generic_1_1Map.md#function-find-44) (const std::shared\_ptr&lt; Key &gt; & key) const<br> |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Map.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function GateRelations [1/2]

```C++
falcon_core::physics::device_structures::GateRelations::GateRelations () 
```




<hr>



### function GateRelations [2/2]

```C++
falcon_core::physics::device_structures::GateRelations::GateRelations (
    std::vector< std::pair< ConnectionSP, ConnectionsSP > > init
) 
```




<hr>



### function insert 

_Override the assert method to force gate typing._ 
```C++
std::pair< generic::List < generic::Pair < Connection , Connections > >::iterator, bool > falcon_core::physics::device_structures::GateRelations::insert (
    const ConnectionSP & key,
    const ConnectionsSP & value
) 
```




<hr>



### function insert\_or\_assign 

_Override the default Map assignment to force gate typing._ 
```C++
void falcon_core::physics::device_structures::GateRelations::insert_or_assign (
    const ConnectionSP & key,
    const ConnectionsSP & value
) 
```




<hr>



### function operator!= 

```C++
bool falcon_core::physics::device_structures::GateRelations::operator!= (
    const GateRelations & other
) const
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::device_structures::GateRelations::operator== (
    const GateRelations & other
) const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/device_structures/GateRelations.hpp`

