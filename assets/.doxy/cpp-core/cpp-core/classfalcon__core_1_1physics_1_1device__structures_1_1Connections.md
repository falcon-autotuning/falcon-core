

# Class falcon\_core::physics::device\_structures::Connections



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md) **>** [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md)



_A serializable vector of_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _pointers, also a Song._[More...](#detailed-description)

* `#include <Connections.hpp>`



Inherits the following classes: [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)
















## Public Types inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-iterator)  <br> |


























































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Connections**](#function-connections-14) () <br>_Default constructor: creates an empty_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container._ |
|   | [**Connections**](#function-connections-24) (size\_t count, const ConnectionSP & value) <br>_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container with a given size, and value._ |
|   | [**Connections**](#function-connections-34) (const std::vector&lt; ConnectionSP &gt; & vec) <br>_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container from an existing vector of values._ |
|   | [**Connections**](#function-connections-44) (const generic::ListSP&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; & vec) <br>_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container from an existing vector of values._ |
|  std::shared\_ptr&lt; [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; | [**intersection**](#function-intersection) (const std::shared\_ptr&lt; [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) &gt; & other) const<br>_Finds the intersection between this list and another._  |
|  bool | [**is\_barrier\_gates**](#function-is_barrier_gates) () const<br>_Check if all connections are barrier gates._  |
|  bool | [**is\_dot\_gates**](#function-is_dot_gates) () const<br>_Check if all connections are dot gates (plunger or barrier)._  |
|  bool | [**is\_gates**](#function-is_gates) () const<br>_Check if all connections are gates (not ohmics)._  |
|  bool | [**is\_ohmics**](#function-is_ohmics) () const<br>_Check if all connections are ohmics (not gates)._  |
|  bool | [**is\_plunger\_gates**](#function-is_plunger_gates) () const<br>_Check if all connections are plunger gates._  |
|  bool | [**is\_reservoir\_gates**](#function-is_reservoir_gates) () const<br>_Check if all connections are reservoir gates._  |
|  bool | [**is\_screening\_gates**](#function-is_screening_gates) () const<br>_Check if all connections are screening gates._  |
|  bool | [**operator!=**](#function-operator) (const [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) & other) const<br> |
|  bool | [**operator==**](#function-operator_1) (const [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) & other) const<br> |


## Public Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-16) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-26) (iterator begin, iterator end) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-36) () <br>[_**List**_](classfalcon__core_1_1generic_1_1List.md) _can be constructed in 5 different ways:_ |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-46) (size\_t count) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-56) (size\_t count, const StoredValue & value) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-66) (const Container & init) <br> |
|  auto | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-12) (const size\_t idx) const<br> |
|  auto | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-22) (const size\_t idx) <br> |
|  StoredValue | [**back**](classfalcon__core_1_1generic_1_1List.md#function-back-12) () <br>_Return the last element of a list._  |
|  const StoredValue & | [**back**](classfalcon__core_1_1generic_1_1List.md#function-back-22) () const<br>_Return the last element of a list._  |
|  iterator | [**begin**](classfalcon__core_1_1generic_1_1List.md#function-begin-12) () <br> |
|  const\_iterator | [**begin**](classfalcon__core_1_1generic_1_1List.md#function-begin-22) () const<br> |
|  void | [**clear**](classfalcon__core_1_1generic_1_1List.md#function-clear) () <br>_clears to contents of the list._  |
|  bool | [**contains**](classfalcon__core_1_1generic_1_1List.md#function-contains) (const StoredValue & value) const<br> |
|  bool | [**empty**](classfalcon__core_1_1generic_1_1List.md#function-empty) () const<br> |
|  iterator | [**end**](classfalcon__core_1_1generic_1_1List.md#function-end-12) () <br> |
|  const\_iterator | [**end**](classfalcon__core_1_1generic_1_1List.md#function-end-22) () const<br> |
|  void | [**erase\_at**](classfalcon__core_1_1generic_1_1List.md#function-erase_at) (size\_t idx) <br>_Allows for targetted eraseall of elements at an index._  |
|  size\_t | [**index**](classfalcon__core_1_1generic_1_1List.md#function-index) (const StoredValue & value) const<br> |
|  void | [**insert**](classfalcon__core_1_1generic_1_1List.md#function-insert) (iterator pos, const\_iterator first, const\_iterator last) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**intersection**](classfalcon__core_1_1generic_1_1List.md#function-intersection) (const std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; & other) const<br>_Finds the intersection between this list and another._  |
|  const Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-12) () const<br> |
|  Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-22) () <br> |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1List.md#function-operator) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) const<br> |
|  [**List**](classfalcon__core_1_1generic_1_1List.md) | [**operator=**](classfalcon__core_1_1generic_1_1List.md#function-operator_1) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1List.md#function-operator_2) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) const<br> |
|  StoredValue | [**operator[]**](classfalcon__core_1_1generic_1_1List.md#function-operator_3) (const size\_t idx) <br> |
|  const StoredValue & | [**operator[]**](classfalcon__core_1_1generic_1_1List.md#function-operator_4) (const size\_t idx) const<br> |
|  void | [**push\_back**](classfalcon__core_1_1generic_1_1List.md#function-push_back) (const StoredValue & item) <br> |
|  void | [**replace\_at**](classfalcon__core_1_1generic_1_1List.md#function-replace_at) (size\_t idx, const StoredValue & value) <br> |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1List.md#function-serialize) (Archive & ar) <br> |
|  size\_t | [**size**](classfalcon__core_1_1generic_1_1List.md#function-size) () const<br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |




## Public Static Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**allocate**](classfalcon__core_1_1generic_1_1List.md#function-allocate) (size\_t count) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**create**](classfalcon__core_1_1generic_1_1List.md#function-create) (const Container & init) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**create\_empty**](classfalcon__core_1_1generic_1_1List.md#function-create_empty) () <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**fill\_value**](classfalcon__core_1_1generic_1_1List.md#function-fill_value) (size\_t count, const StoredValue & value) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




## Protected Types inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
| typedef std::vector&lt; StoredValue &gt; | [**Container**](classfalcon__core_1_1generic_1_1List.md#typedef-container)  <br> |
| typedef typename std::conditional&lt; std::is\_base\_of&lt; [**Song**](classfalcon__core_1_1generic_1_1Song.md), Value &gt;::value, std::shared\_ptr&lt; Value &gt;, Value &gt;::type | [**StoredValue**](classfalcon__core_1_1generic_1_1List.md#typedef-storedvalue)  <br> |




























































## Protected Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|  StoredValue & | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-14) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  const StoredValue & | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-24) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  StoredValue | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-34) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) <br> |
|  const StoredValue | [**at\_impl**](classfalcon__core_1_1generic_1_1List.md#function-at_impl-44) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**contains\_impl**](classfalcon__core_1_1generic_1_1List.md#function-contains_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-13) (const Container & src, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-23) (const Container & src, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**copy\_items\_impl**](classfalcon__core_1_1generic_1_1List.md#function-copy_items_impl-33) (const Container &, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-13) (size\_t count, const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-23) (size\_t count, const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](classfalcon__core_1_1generic_1_1List.md#function-create_duplicates_impl-33) (size\_t count, const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  size\_t | [**index\_impl**](classfalcon__core_1_1generic_1_1List.md#function-index_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-13) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-23) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-33) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-13) (const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-23) (const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-33) (const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |










## Detailed Description


[**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) can be constructed in 5 different ways:



* Default constructor: creates an empty [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) container. 
```C++
Connections o;
```

* Sized constructor: creates an [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) container with a given number of default-initialized elements. 

**Parameters:**


  * `count` Number of elements. 
```C++
Connections o(10);
```



* Fill constructor: creates an [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) container with a given number of copies of a specified value. 

**Parameters:**


  * `count` Number of elements. 
  * `value` Value to copy. 
```C++
Connections o(10, someConnectionsP);
```



* Vector constructor: creates an [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) container from an existing vector of ConnectionSP. 

**Parameters:**


  * `vec` Vector of ConnectionSP to copy. 
```C++
std::vector<ConnectionsP> v = ...;
Connections o(v);
```



* Initializer list constructor: creates a [**Connections**](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) container from an initializer list of shared pointers. 

**Parameters:**


  * `init` Initializer list of shared\_ptr&lt;T&gt; to copy. 
```C++
Connections o{ptr1, ptr2, ptr3};
```
 






    
## Public Functions Documentation




### function Connections [1/4]

_Default constructor: creates an empty_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container._
```C++
falcon_core::physics::device_structures::Connections::Connections () 
```




<hr>



### function Connections [2/4]

_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container with a given size, and value._
```C++
falcon_core::physics::device_structures::Connections::Connections (
    size_t count,
    const ConnectionSP & value
) 
```





**Parameters:**


* `count` Number of elements. 
* `value` Value to copy. 




        

<hr>



### function Connections [3/4]

_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container from an existing vector of values._
```C++
falcon_core::physics::device_structures::Connections::Connections (
    const std::vector< ConnectionSP > & vec
) 
```





**Parameters:**


* `vec` Vector of values to copy. 




        

<hr>



### function Connections [4/4]

_Construct a_ [_**Connections**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connections.md) _container from an existing vector of values._
```C++
falcon_core::physics::device_structures::Connections::Connections (
    const generic::ListSP< Connection > & vec
) 
```





**Parameters:**


* `vec` Vector of values to copy. 




        

<hr>



### function intersection 

_Finds the intersection between this list and another._ 
```C++
std::shared_ptr< Connections > falcon_core::physics::device_structures::Connections::intersection (
    const std::shared_ptr< Connections > & other
) const
```





**Parameters:**


* `other` the other list to compare again. 



**Returns:**

A list of values containing elements from both. 





        

<hr>



### function is\_barrier\_gates 

_Check if all connections are barrier gates._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_barrier_gates () const
```




<hr>



### function is\_dot\_gates 

_Check if all connections are dot gates (plunger or barrier)._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_dot_gates () const
```




<hr>



### function is\_gates 

_Check if all connections are gates (not ohmics)._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_gates () const
```




<hr>



### function is\_ohmics 

_Check if all connections are ohmics (not gates)._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_ohmics () const
```




<hr>



### function is\_plunger\_gates 

_Check if all connections are plunger gates._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_plunger_gates () const
```




<hr>



### function is\_reservoir\_gates 

_Check if all connections are reservoir gates._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_reservoir_gates () const
```




<hr>



### function is\_screening\_gates 

_Check if all connections are screening gates._ 
```C++
bool falcon_core::physics::device_structures::Connections::is_screening_gates () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::physics::device_structures::Connections::operator!= (
    const Connections & other
) const
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::device_structures::Connections::operator== (
    const Connections & other
) const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/device_structures/Connections.hpp`

