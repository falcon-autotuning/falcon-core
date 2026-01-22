

# Class falcon\_core::autotuner\_interfaces::interpretations::InterpretationContainer

**template &lt;typename Value&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**autotuner\_interfaces**](namespacefalcon__core_1_1autotuner__interfaces.md) **>** [**interpretations**](namespacefalcon__core_1_1autotuner__interfaces_1_1interpretations.md) **>** [**InterpretationContainer**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContainer.md)








Inherits the following classes: [falcon\_core::generic::Map](classfalcon__core_1_1generic_1_1Map.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**InterpretationContainer**](#function-interpretationcontainer-23) (const InterpretationContainer&lt; Value &gt; & other) <br> |
|   | [**InterpretationContainer**](#function-interpretationcontainer-33) (const generic::MapSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md), Value &gt; & map) <br>_A container for interpretations of the contents._  |
|  bool | [**operator!=**](#function-operator) (const InterpretationContainer&lt; Value &gt; & other) const<br> |
|  [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) & | [**operator=**](#function-operator_1) (const InterpretationContainer&lt; Value &gt; & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const InterpretationContainer&lt; Value &gt; & other) const<br> |
|  const generic::ListSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**select\_by\_connection**](#function-select_by_connection) (const physics::device\_structures::ConnectionSP & connection) const<br>_Select contexts that involve a specific connection._  |
|  const generic::ListSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**select\_by\_connections**](#function-select_by_connections) (const std::vector&lt; physics::device\_structures::ConnectionSP &gt; & connections) const<br>_Select contexts that involve all of the specified connections._  |
|  const generic::ListSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**select\_by\_dependent\_connection**](#function-select_by_dependent_connection) (const physics::device\_structures::ConnectionSP & connection) <br> |
|  const generic::ListSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**select\_by\_independent\_connection**](#function-select_by_independent_connection) (const physics::device\_structures::ConnectionSP & connection) <br> |
|  const generic::ListSP&lt; [**InterpretationContext**](classfalcon__core_1_1autotuner__interfaces_1_1interpretations_1_1InterpretationContext.md) &gt; | [**select\_contexts**](#function-select_contexts) (const generic::ListSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; & independent\_connections, const generic::ListSP&lt; [**physics::device\_structures::Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; & dependent\_connections) <br> |
|  const physics::units::SymbolUnitSP | [**unit**](#function-unit) () const<br>_Returns the unit that all contexts in this constainer must have._  |


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


























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**InterpretationContainer**](#function-interpretationcontainer-13) () = default<br> |
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










## Public Functions Documentation




### function InterpretationContainer [2/3]

```C++
inline falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::InterpretationContainer (
    const InterpretationContainer< Value > & other
) 
```




<hr>



### function InterpretationContainer [3/3]

_A container for interpretations of the contents._ 
```C++
inline falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::InterpretationContainer (
    const generic::MapSP< InterpretationContext , Value > & map
) 
```





**Parameters:**


* `contexts` The list of contexts. 



**Exception:**


* `std::invalid_argument` if contexts have different units. 




        

<hr>



### function operator!= 

```C++
inline bool falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::operator!= (
    const InterpretationContainer< Value > & other
) const
```




<hr>



### function operator= 

```C++
inline InterpretationContext & falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::operator= (
    const InterpretationContainer< Value > & other
) 
```




<hr>



### function operator== 

```C++
inline bool falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::operator== (
    const InterpretationContainer< Value > & other
) const
```




<hr>



### function select\_by\_connection 

_Select contexts that involve a specific connection._ 
```C++
inline const generic::ListSP< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connection (
    const physics::device_structures::ConnectionSP & connection
) const
```





**Parameters:**


* `connection` The connection to search for. 



**Returns:**

A list of contexts that involve the specified connection in either independant or dependant variables. 





        

<hr>



### function select\_by\_connections 

_Select contexts that involve all of the specified connections._ 
```C++
inline const generic::ListSP< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_connections (
    const std::vector< physics::device_structures::ConnectionSP > & connections
) const
```





**Parameters:**


* `connections` List of connections to search for. 



**Returns:**

A list of contexts that involve all specified connections. 





        

<hr>



### function select\_by\_dependent\_connection 

```C++
inline const generic::ListSP< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_dependent_connection (
    const physics::device_structures::ConnectionSP & connection
) 
```




<hr>



### function select\_by\_independent\_connection 

```C++
inline const generic::ListSP< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_by_independent_connection (
    const physics::device_structures::ConnectionSP & connection
) 
```




<hr>



### function select\_contexts 

```C++
inline const generic::ListSP< InterpretationContext > falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::select_contexts (
    const generic::ListSP< physics::device_structures::Connection > & independent_connections,
    const generic::ListSP< physics::device_structures::Connection > & dependent_connections
) 
```




<hr>



### function unit 

_Returns the unit that all contexts in this constainer must have._ 
```C++
inline const physics::units::SymbolUnitSP falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::unit () const
```




<hr>
## Protected Functions Documentation




### function InterpretationContainer [1/3]

```C++
falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::InterpretationContainer () = default
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::autotuner_interfaces::interpretations::InterpretationContainer::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContainer.hpp`

