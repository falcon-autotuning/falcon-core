

# Class falcon\_core::generic::List

**template &lt;typename Value&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**List**](classfalcon__core_1_1generic_1_1List.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::math::Axes](classfalcon__core_1_1math_1_1Axes.md),  [falcon\_core::math::Axes](classfalcon__core_1_1math_1_1Axes.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](#typedef-iterator)  <br> |








































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**List**](#function-list-16) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) <br> |
|   | [**List**](#function-list-26) (iterator begin, iterator end) <br> |
|   | [**List**](#function-list-36) () <br>[_**List**_](classfalcon__core_1_1generic_1_1List.md) _can be constructed in 5 different ways:_ |
|   | [**List**](#function-list-46) (size\_t count) <br> |
|   | [**List**](#function-list-56) (size\_t count, const StoredValue & value) <br> |
|   | [**List**](#function-list-66) (const Container & init) <br> |
|  auto | [**at**](#function-at-12) (const size\_t idx) const<br> |
|  auto | [**at**](#function-at-22) (const size\_t idx) <br> |
|  StoredValue | [**back**](#function-back-12) () <br>_Return the last element of a list._  |
|  const StoredValue & | [**back**](#function-back-22) () const<br>_Return the last element of a list._  |
|  iterator | [**begin**](#function-begin-12) () <br> |
|  const\_iterator | [**begin**](#function-begin-22) () const<br> |
|  void | [**clear**](#function-clear) () <br>_clears to contents of the list._  |
|  bool | [**contains**](#function-contains) (const StoredValue & value) const<br> |
|  bool | [**empty**](#function-empty) () const<br> |
|  iterator | [**end**](#function-end-12) () <br> |
|  const\_iterator | [**end**](#function-end-22) () const<br> |
|  void | [**erase\_at**](#function-erase_at) (size\_t idx) <br>_Allows for targetted eraseall of elements at an index._  |
|  size\_t | [**index**](#function-index) (const StoredValue & value) const<br> |
|  void | [**insert**](#function-insert) (iterator pos, const\_iterator first, const\_iterator last) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**intersection**](#function-intersection) (const std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; & other) const<br>_Finds the intersection between this list and another._  |
|  const Container | [**items**](#function-items-12) () const<br> |
|  Container | [**items**](#function-items-22) () <br> |
|  bool | [**operator!=**](#function-operator) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) const<br> |
|  [**List**](classfalcon__core_1_1generic_1_1List.md) | [**operator=**](#function-operator_1) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other) const<br> |
|  StoredValue | [**operator[]**](#function-operator_3) (const size\_t idx) <br> |
|  const StoredValue & | [**operator[]**](#function-operator_4) (const size\_t idx) const<br> |
|  void | [**push\_back**](#function-push_back) (const StoredValue & item) <br> |
|  void | [**replace\_at**](#function-replace_at) (size\_t idx, const StoredValue & value) <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |
|  size\_t | [**size**](#function-size) () const<br> |


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
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**allocate**](#function-allocate) (size\_t count) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**create**](#function-create) (const Container & init) <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**create\_empty**](#function-create_empty) () <br> |
|  std::shared\_ptr&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; &gt; | [**fill\_value**](#function-fill_value) (size\_t count, const StoredValue & value) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |


## Protected Types

| Type | Name |
| ---: | :--- |
| typedef std::vector&lt; StoredValue &gt; | [**Container**](#typedef-container)  <br> |
| typedef typename std::conditional&lt; std::is\_base\_of&lt; [**Song**](classfalcon__core_1_1generic_1_1Song.md), Value &gt;::value, std::shared\_ptr&lt; Value &gt;, Value &gt;::type | [**StoredValue**](#typedef-storedvalue)  <br> |








































## Protected Functions

| Type | Name |
| ---: | :--- |
|  StoredValue & | [**at\_impl**](#function-at_impl-14) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  const StoredValue & | [**at\_impl**](#function-at_impl-24) (size\_t idx, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  StoredValue | [**at\_impl**](#function-at_impl-34) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) <br> |
|  const StoredValue | [**at\_impl**](#function-at_impl-44) (size\_t idx, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md)) const<br> |
|  bool | [**contains\_impl**](#function-contains_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**contains\_impl**](#function-contains_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**contains\_impl**](#function-contains_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**copy\_items\_impl**](#function-copy_items_impl-13) (const Container & src, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**copy\_items\_impl**](#function-copy_items_impl-23) (const Container & src, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**copy\_items\_impl**](#function-copy_items_impl-33) (const Container &, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](#function-create_duplicates_impl-13) (size\_t count, const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](#function-create_duplicates_impl-23) (size\_t count, const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**create\_duplicates\_impl**](#function-create_duplicates_impl-33) (size\_t count, const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |
|  size\_t | [**index\_impl**](#function-index_impl-13) (const std::shared\_ptr&lt; T &gt; & value, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  size\_t | [**index\_impl**](#function-index_impl-23) (const T & value, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  size\_t | [**index\_impl**](#function-index_impl-33) (const T & value, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-13) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-23) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-33) (const [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt; & other, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**push\_back\_impl**](#function-push_back_impl-13) (const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**push\_back\_impl**](#function-push_back_impl-23) (const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**push\_back\_impl**](#function-push_back_impl-33) (const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |








## Public Types Documentation




### typedef const\_iterator 

```C++
using falcon_core::generic::List< Value >::const_iterator =  typename Container::const_iterator;
```




<hr>



### typedef iterator 

```C++
using falcon_core::generic::List< Value >::iterator =  typename Container::iterator;
```




<hr>
## Public Functions Documentation




### function List [1/6]

```C++
inline falcon_core::generic::List::List (
    const List < Value > & other
) 
```




<hr>



### function List [2/6]

```C++
inline falcon_core::generic::List::List (
    iterator begin,
    iterator end
) 
```




<hr>



### function List [3/6]

[_**List**_](classfalcon__core_1_1generic_1_1List.md) _can be constructed in 5 different ways:_
```C++
inline falcon_core::generic::List::List () 
```




* Default constructor: creates an empty [**List**](classfalcon__core_1_1generic_1_1List.md) container. 
```C++
List o;
```

* Sized constructor: creates an [**List**](classfalcon__core_1_1generic_1_1List.md) container with a given number of default-initialized elements. 

**Parameters:**


  * `count` Number of elements. 
```C++
List o(10);
```



* Fill constructor: creates an [**List**](classfalcon__core_1_1generic_1_1List.md) container with a given number of copies of a specified value. 

**Parameters:**


  * `count` Number of elements. 
  * `value` Value to copy. 
```C++
List o(10, someValue);
```



* Vector constructor: creates an [**List**](classfalcon__core_1_1generic_1_1List.md) container from an existing vector of values. 

**Parameters:**


  * `vec` Vector of values to copy. 
```C++
std::vector<ListP> v = ...;
List o(v);
```



* Initializer list constructor: creates a [**List**](classfalcon__core_1_1generic_1_1List.md) container from an initializer list of shared pointers. 

**Parameters:**


  * `init` Initializer list of shared\_ptr&lt;T&gt; to copy. 
```C++
List o{ptr1, ptr2, ptr3};
```
 






        

<hr>



### function List [4/6]

```C++
inline falcon_core::generic::List::List (
    size_t count
) 
```




<hr>



### function List [5/6]

```C++
inline falcon_core::generic::List::List (
    size_t count,
    const StoredValue & value
) 
```




<hr>



### function List [6/6]

```C++
inline falcon_core::generic::List::List (
    const Container & init
) 
```




<hr>



### function at [1/2]

```C++
inline auto falcon_core::generic::List::at (
    const size_t idx
) const
```




<hr>



### function at [2/2]

```C++
inline auto falcon_core::generic::List::at (
    const size_t idx
) 
```




<hr>



### function back [1/2]

_Return the last element of a list._ 
```C++
inline StoredValue falcon_core::generic::List::back () 
```




<hr>



### function back [2/2]

_Return the last element of a list._ 
```C++
inline const StoredValue & falcon_core::generic::List::back () const
```




<hr>



### function begin [1/2]

```C++
inline iterator falcon_core::generic::List::begin () 
```




<hr>



### function begin [2/2]

```C++
inline const_iterator falcon_core::generic::List::begin () const
```




<hr>



### function clear 

_clears to contents of the list._ 
```C++
inline void falcon_core::generic::List::clear () 
```




<hr>



### function contains 

```C++
inline bool falcon_core::generic::List::contains (
    const StoredValue & value
) const
```




<hr>



### function empty 

```C++
inline bool falcon_core::generic::List::empty () const
```




<hr>



### function end [1/2]

```C++
inline iterator falcon_core::generic::List::end () 
```




<hr>



### function end [2/2]

```C++
inline const_iterator falcon_core::generic::List::end () const
```




<hr>



### function erase\_at 

_Allows for targetted eraseall of elements at an index._ 
```C++
inline void falcon_core::generic::List::erase_at (
    size_t idx
) 
```





**Parameters:**


* `idx` The index to erase at. 




        

<hr>



### function index 

```C++
inline size_t falcon_core::generic::List::index (
    const StoredValue & value
) const
```




<hr>



### function insert 

```C++
inline void falcon_core::generic::List::insert (
    iterator pos,
    const_iterator first,
    const_iterator last
) 
```




<hr>



### function intersection 

_Finds the intersection between this list and another._ 
```C++
inline std::shared_ptr< List < Value > > falcon_core::generic::List::intersection (
    const std::shared_ptr< List < Value > > & other
) const
```





**Parameters:**


* `other` the other list to compare again. 



**Returns:**

A list of values containing elements from both. 





        

<hr>



### function items [1/2]

```C++
inline const Container falcon_core::generic::List::items () const
```




<hr>



### function items [2/2]

```C++
inline Container falcon_core::generic::List::items () 
```




<hr>



### function operator!= 

```C++
inline bool falcon_core::generic::List::operator!= (
    const List < Value > & other
) const
```




<hr>



### function operator= 

```C++
inline List falcon_core::generic::List::operator= (
    const List < Value > & other
) 
```




<hr>



### function operator== 

```C++
inline bool falcon_core::generic::List::operator== (
    const List < Value > & other
) const
```




<hr>



### function operator[] 

```C++
inline StoredValue falcon_core::generic::List::operator[] (
    const size_t idx
) 
```




<hr>



### function operator[] 

```C++
inline const StoredValue & falcon_core::generic::List::operator[] (
    const size_t idx
) const
```




<hr>



### function push\_back 

```C++
inline void falcon_core::generic::List::push_back (
    const StoredValue & item
) 
```




<hr>



### function replace\_at 

```C++
inline void falcon_core::generic::List::replace_at (
    size_t idx,
    const StoredValue & value
) 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::generic::List::serialize (
    Archive & ar
) 
```




<hr>



### function size 

```C++
inline size_t falcon_core::generic::List::size () const
```




<hr>
## Public Static Functions Documentation




### function allocate 

```C++
static inline std::shared_ptr< List < Value > > falcon_core::generic::List::allocate (
    size_t count
) 
```




<hr>



### function create 

```C++
static inline std::shared_ptr< List < Value > > falcon_core::generic::List::create (
    const Container & init
) 
```




<hr>



### function create\_empty 

```C++
static inline std::shared_ptr< List < Value > > falcon_core::generic::List::create_empty () 
```




<hr>



### function fill\_value 

```C++
static inline std::shared_ptr< List < Value > > falcon_core::generic::List::fill_value (
    size_t count,
    const StoredValue & value
) 
```




<hr>
## Protected Types Documentation




### typedef Container 

```C++
using falcon_core::generic::List< Value >::Container =  std::vector<StoredValue>;
```




<hr>



### typedef StoredValue 

```C++
using falcon_core::generic::List< Value >::StoredValue =  typename std::conditional<std::is_base_of<Song, Value>::value, std::shared_ptr<Value>, Value>::type;
```




<hr>
## Protected Functions Documentation




### function at\_impl [1/4]

```C++
inline StoredValue & falcon_core::generic::List::at_impl (
    size_t idx,
    category::other_tag
) 
```




<hr>



### function at\_impl [2/4]

```C++
inline const StoredValue & falcon_core::generic::List::at_impl (
    size_t idx,
    category::other_tag
) const
```




<hr>



### function at\_impl [3/4]

```C++
inline StoredValue falcon_core::generic::List::at_impl (
    size_t idx,
    category::bool_tag
) 
```




<hr>



### function at\_impl [4/4]

```C++
inline const StoredValue falcon_core::generic::List::at_impl (
    size_t idx,
    category::bool_tag
) const
```




<hr>



### function contains\_impl [1/3]

```C++
template<typename T>
inline bool falcon_core::generic::List::contains_impl (
    const std::shared_ptr< T > & value,
    category::song_tag
) const
```




<hr>



### function contains\_impl [2/3]

```C++
template<typename T>
inline bool falcon_core::generic::List::contains_impl (
    const T & value,
    category::primitive_tag
) const
```




<hr>



### function contains\_impl [3/3]

```C++
template<typename T>
inline bool falcon_core::generic::List::contains_impl (
    const T & value,
    category::other_tag
) const
```




<hr>



### function copy\_items\_impl [1/3]

```C++
inline void falcon_core::generic::List::copy_items_impl (
    const Container & src,
    category::song_tag
) 
```




<hr>



### function copy\_items\_impl [2/3]

```C++
inline void falcon_core::generic::List::copy_items_impl (
    const Container & src,
    category::primitive_tag
) 
```




<hr>



### function copy\_items\_impl [3/3]

```C++
inline void falcon_core::generic::List::copy_items_impl (
    const Container &,
    category::other_tag
) 
```




<hr>



### function create\_duplicates\_impl [1/3]

```C++
template<typename T>
inline void falcon_core::generic::List::create_duplicates_impl (
    size_t count,
    const std::shared_ptr< T > & item,
    category::song_tag
) 
```




<hr>



### function create\_duplicates\_impl [2/3]

```C++
template<typename T>
inline void falcon_core::generic::List::create_duplicates_impl (
    size_t count,
    const T & item,
    category::primitive_tag
) 
```




<hr>



### function create\_duplicates\_impl [3/3]

```C++
template<typename T>
inline void falcon_core::generic::List::create_duplicates_impl (
    size_t count,
    const T & item,
    category::other_tag
) 
```




<hr>



### function index\_impl [1/3]

```C++
template<typename T>
inline size_t falcon_core::generic::List::index_impl (
    const std::shared_ptr< T > & value,
    category::song_tag
) const
```




<hr>



### function index\_impl [2/3]

```C++
template<typename T>
inline size_t falcon_core::generic::List::index_impl (
    const T & value,
    category::primitive_tag
) const
```




<hr>



### function index\_impl [3/3]

```C++
template<typename T>
inline size_t falcon_core::generic::List::index_impl (
    const T & value,
    category::other_tag
) const
```




<hr>



### function operator\_equal\_impl [1/3]

```C++
inline bool falcon_core::generic::List::operator_equal_impl (
    const List < Value > & other,
    category::song_tag
) const
```




<hr>



### function operator\_equal\_impl [2/3]

```C++
inline bool falcon_core::generic::List::operator_equal_impl (
    const List < Value > & other,
    category::primitive_tag
) const
```




<hr>



### function operator\_equal\_impl [3/3]

```C++
inline bool falcon_core::generic::List::operator_equal_impl (
    const List < Value > & other,
    category::other_tag
) const
```




<hr>



### function push\_back\_impl [1/3]

```C++
template<typename T>
inline void falcon_core::generic::List::push_back_impl (
    const std::shared_ptr< T > & item,
    category::song_tag
) 
```




<hr>



### function push\_back\_impl [2/3]

```C++
template<typename T>
inline void falcon_core::generic::List::push_back_impl (
    const T & item,
    category::primitive_tag
) 
```




<hr>



### function push\_back\_impl [3/3]

```C++
template<typename T>
inline void falcon_core::generic::List::push_back_impl (
    const T & item,
    category::other_tag
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::generic::List::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/List.hpp`

