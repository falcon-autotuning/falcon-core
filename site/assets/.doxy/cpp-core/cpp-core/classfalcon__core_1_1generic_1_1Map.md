

# Class falcon\_core::generic::Map

**template &lt;typename Key, typename Value&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**Map**](classfalcon__core_1_1generic_1_1Map.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Map**](#function-map-14) (const Map&lt; Key, Value &gt; & other) <br> |
|   | [**Map**](#function-map-24) () <br> |
|   | [**Map**](#function-map-34) (const std::vector&lt; std::pair&lt; typename ContainerItem::StoredT1, typename ContainerItem::StoredT2 &gt; &gt; & init) <br> |
|   | [**Map**](#function-map-44) (const Container & init) <br> |
|  ContainerItem::StoredT2 | [**at**](#function-at-12) (const typename ContainerItem::StoredT1 & key) <br> |
|  const ContainerItem::StoredT2 | [**at**](#function-at-22) (const typename ContainerItem::StoredT1 & key) const<br> |
|  iterator | [**begin**](#function-begin-12) () <br> |
|  const\_iterator | [**begin**](#function-begin-22) () const<br> |
|  const\_iterator | [**cbegin**](#function-cbegin) () const<br> |
|  const\_iterator | [**cend**](#function-cend) () const<br> |
|  void | [**clear**](#function-clear) () <br> |
|  bool | [**contains**](#function-contains) (const typename ContainerItem::StoredT1 & key) const<br> |
|  std::shared\_ptr&lt; Map&lt; Key, Value &gt; &gt; | [**create**](#function-create) (const Container & init) <br> |
|  bool | [**empty**](#function-empty) () const<br> |
|  iterator | [**end**](#function-end-12) () <br> |
|  const\_iterator | [**end**](#function-end-22) () const<br> |
|  void | [**erase**](#function-erase) (const typename ContainerItem::StoredT1 & key) <br> |
|  std::pair&lt; iterator, bool &gt; | [**insert**](#function-insert) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  void | [**insert\_or\_assign**](#function-insert_or_assign) (const typename ContainerItem::StoredT1 & key, const typename ContainerItem::StoredT2 & value) <br> |
|  const std::shared\_ptr&lt; Container &gt; | [**items**](#function-items-12) () const<br> |
|  std::shared\_ptr&lt; Container &gt; | [**items**](#function-items-22) () <br> |
|  const generic::ListSP&lt; Key &gt; | [**keys**](#function-keys) () const<br>_Return the keys of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._ |
|  bool | [**operator!=**](#function-operator) (const Map&lt; Key, Value &gt; & other) const<br> |
|  Map&lt; Key, Value &gt; & | [**operator=**](#function-operator_1) (const Map&lt; Key, Value &gt; & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const Map&lt; Key, Value &gt; & other) const<br> |
|  ContainerItem::StoredT2 | [**operator[]**](#function-operator_3) (const typename ContainerItem::StoredT1 & key) <br> |
|  std::size\_t | [**size**](#function-size) () const<br> |
|  const generic::ListSP&lt; Value &gt; | [**values**](#function-values) () const<br>_Return the values of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._ |


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
|  std::shared\_ptr&lt; Map&lt; Key, Value &gt; &gt; | [**create\_empty**](#function-create_empty) () <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |


## Protected Types

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](#typedef-iterator)  <br> |








































## Protected Functions

| Type | Name |
| ---: | :--- |
|  iterator | [**find**](#function-find-14) (const Key & key) <br> |
|  iterator | [**find**](#function-find-24) (const std::shared\_ptr&lt; Key &gt; & key) <br> |
|  const\_iterator | [**find**](#function-find-34) (const Key & key) const<br> |
|  const\_iterator | [**find**](#function-find-44) (const std::shared\_ptr&lt; Key &gt; & key) const<br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function Map [1/4]

```C++
inline falcon_core::generic::Map::Map (
    const Map< Key, Value > & other
) 
```




<hr>



### function Map [2/4]

```C++
inline falcon_core::generic::Map::Map () 
```




<hr>



### function Map [3/4]

```C++
inline falcon_core::generic::Map::Map (
    const std::vector< std::pair< typename ContainerItem::StoredT1, typename ContainerItem::StoredT2 > > & init
) 
```




<hr>



### function Map [4/4]

```C++
inline falcon_core::generic::Map::Map (
    const Container & init
) 
```




<hr>



### function at [1/2]

```C++
inline ContainerItem::StoredT2 falcon_core::generic::Map::at (
    const typename ContainerItem::StoredT1 & key
) 
```




<hr>



### function at [2/2]

```C++
inline const ContainerItem::StoredT2 falcon_core::generic::Map::at (
    const typename ContainerItem::StoredT1 & key
) const
```




<hr>



### function begin [1/2]

```C++
inline iterator falcon_core::generic::Map::begin () 
```




<hr>



### function begin [2/2]

```C++
inline const_iterator falcon_core::generic::Map::begin () const
```




<hr>



### function cbegin 

```C++
inline const_iterator falcon_core::generic::Map::cbegin () const
```




<hr>



### function cend 

```C++
inline const_iterator falcon_core::generic::Map::cend () const
```




<hr>



### function clear 

```C++
inline void falcon_core::generic::Map::clear () 
```




<hr>



### function contains 

```C++
inline bool falcon_core::generic::Map::contains (
    const typename ContainerItem::StoredT1 & key
) const
```




<hr>



### function create 

```C++
inline std::shared_ptr< Map< Key, Value > > falcon_core::generic::Map::create (
    const Container & init
) 
```




<hr>



### function empty 

```C++
inline bool falcon_core::generic::Map::empty () const
```




<hr>



### function end [1/2]

```C++
inline iterator falcon_core::generic::Map::end () 
```




<hr>



### function end [2/2]

```C++
inline const_iterator falcon_core::generic::Map::end () const
```




<hr>



### function erase 

```C++
inline void falcon_core::generic::Map::erase (
    const typename ContainerItem::StoredT1 & key
) 
```




<hr>



### function insert 

```C++
inline std::pair< iterator, bool > falcon_core::generic::Map::insert (
    const typename ContainerItem::StoredT1 & key,
    const typename ContainerItem::StoredT2 & value
) 
```




<hr>



### function insert\_or\_assign 

```C++
inline void falcon_core::generic::Map::insert_or_assign (
    const typename ContainerItem::StoredT1 & key,
    const typename ContainerItem::StoredT2 & value
) 
```




<hr>



### function items [1/2]

```C++
inline const std::shared_ptr< Container > falcon_core::generic::Map::items () const
```




<hr>



### function items [2/2]

```C++
inline std::shared_ptr< Container > falcon_core::generic::Map::items () 
```




<hr>



### function keys 

_Return the keys of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._
```C++
inline const generic::ListSP< Key > falcon_core::generic::Map::keys () const
```




<hr>



### function operator!= 

```C++
inline bool falcon_core::generic::Map::operator!= (
    const Map< Key, Value > & other
) const
```




<hr>



### function operator= 

```C++
inline Map< Key, Value > & falcon_core::generic::Map::operator= (
    const Map< Key, Value > & other
) 
```




<hr>



### function operator== 

```C++
inline bool falcon_core::generic::Map::operator== (
    const Map< Key, Value > & other
) const
```




<hr>



### function operator[] 

```C++
inline ContainerItem::StoredT2 falcon_core::generic::Map::operator[] (
    const typename ContainerItem::StoredT1 & key
) 
```




<hr>



### function size 

```C++
inline std::size_t falcon_core::generic::Map::size () const
```




<hr>



### function values 

_Return the values of the_ [_**Map**_](classfalcon__core_1_1generic_1_1Map.md) _._
```C++
inline const generic::ListSP< Value > falcon_core::generic::Map::values () const
```




<hr>
## Public Static Functions Documentation




### function create\_empty 

```C++
static inline std::shared_ptr< Map< Key, Value > > falcon_core::generic::Map::create_empty () 
```




<hr>
## Protected Types Documentation




### typedef const\_iterator 

```C++
using falcon_core::generic::Map< Key, Value >::const_iterator =  typename Container::const_iterator;
```




<hr>



### typedef iterator 

```C++
using falcon_core::generic::Map< Key, Value >::iterator =  typename Container::iterator;
```




<hr>
## Protected Functions Documentation




### function find [1/4]

```C++
inline iterator falcon_core::generic::Map::find (
    const Key & key
) 
```




<hr>



### function find [2/4]

```C++
inline iterator falcon_core::generic::Map::find (
    const std::shared_ptr< Key > & key
) 
```




<hr>



### function find [3/4]

```C++
inline const_iterator falcon_core::generic::Map::find (
    const Key & key
) const
```




<hr>



### function find [4/4]

```C++
inline const_iterator falcon_core::generic::Map::find (
    const std::shared_ptr< Key > & key
) const
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::generic::Map::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::generic::Map::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/Map.hpp`

