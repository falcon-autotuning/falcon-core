

# Class falcon\_core::generic::Pair

**template &lt;typename T1, typename T2&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)














## Public Types

| Type | Name |
| ---: | :--- |
| typedef typename std::conditional&lt; std::is\_base\_of&lt; [**generic::Song**](classfalcon__core_1_1generic_1_1Song.md), T1 &gt;::value, std::shared\_ptr&lt; T1 &gt;, T1 &gt;::type | [**StoredT1**](#typedef-storedt1)  <br> |
| typedef typename std::conditional&lt; std::is\_base\_of&lt; [**generic::Song**](classfalcon__core_1_1generic_1_1Song.md), T2 &gt;::value, std::shared\_ptr&lt; T2 &gt;, T2 &gt;::type | [**StoredT2**](#typedef-storedt2)  <br> |








































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Pair**](#function-pair-13) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other) <br> |
|   | [**Pair**](#function-pair-23) (const StoredT1 & first, const StoredT2 & second) <br>_Store a pair of values._  |
|  std::shared\_ptr&lt; [**Pair**](classfalcon__core_1_1generic_1_1Pair.md) &gt; | [**create**](#function-create) (const StoredT1 & first, const StoredT2 & second) <br>_Store a pair of values._  |
|  const StoredT1 | [**first**](#function-first-12) () const<br>_Get the stored first value._  |
|  StoredT1 | [**first**](#function-first-22) () <br>_Get the stored first value._  |
|  bool | [**operator!=**](#function-operator) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other) const<br> |
|  [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & | [**operator=**](#function-operator_1) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other) const<br> |
|  const StoredT2 | [**second**](#function-second-12) () const<br>_Get the stored second value._  |
|  StoredT2 | [**second**](#function-second-22) () <br>_Get the stored second value._  |


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
|   | [**Pair**](#function-pair-33) () = default<br> |
|  void | [**copy\_impl**](#function-copy_impl-14) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md), [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**copy\_impl**](#function-copy_impl-24) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md), [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**copy\_impl**](#function-copy_impl-34) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md), [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**copy\_impl**](#function-copy_impl-44) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; T1, T2 &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md), [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-14) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; U1, U2 &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md), [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-24) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; U1, U2 &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md), [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-34) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; U1, U2 &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md), [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](#function-operator_equal_impl-44) (const [**Pair**](classfalcon__core_1_1generic_1_1Pair.md)&lt; U1, U2 &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md), [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Types Documentation




### typedef StoredT1 

```C++
using falcon_core::generic::Pair< T1, T2 >::StoredT1 =  typename std::conditional<std::is_base_of<generic::Song, T1>::value, std::shared_ptr<T1>, T1>::type;
```




<hr>



### typedef StoredT2 

```C++
using falcon_core::generic::Pair< T1, T2 >::StoredT2 =  typename std::conditional<std::is_base_of<generic::Song, T2>::value, std::shared_ptr<T2>, T2>::type;
```




<hr>
## Public Functions Documentation




### function Pair [1/3]

```C++
inline falcon_core::generic::Pair::Pair (
    const Pair < T1, T2 > & other
) 
```




<hr>



### function Pair [2/3]

_Store a pair of values._ 
```C++
inline falcon_core::generic::Pair::Pair (
    const StoredT1 & first,
    const StoredT2 & second
) 
```





**Parameters:**


* `first` The first value. 
* `second` The second value. 




        

<hr>



### function create 

_Store a pair of values._ 
```C++
inline std::shared_ptr< Pair > falcon_core::generic::Pair::create (
    const StoredT1 & first,
    const StoredT2 & second
) 
```





**Parameters:**


* `first` The first value. 
* `second` The second value. 




        

<hr>



### function first [1/2]

_Get the stored first value._ 
```C++
inline const StoredT1 falcon_core::generic::Pair::first () const
```




<hr>



### function first [2/2]

_Get the stored first value._ 
```C++
inline StoredT1 falcon_core::generic::Pair::first () 
```




<hr>



### function operator!= 

```C++
inline bool falcon_core::generic::Pair::operator!= (
    const Pair < T1, T2 > & other
) const
```




<hr>



### function operator= 

```C++
inline Pair < T1, T2 > & falcon_core::generic::Pair::operator= (
    const Pair < T1, T2 > & other
) 
```




<hr>



### function operator== 

```C++
inline bool falcon_core::generic::Pair::operator== (
    const Pair < T1, T2 > & other
) const
```




<hr>



### function second [1/2]

_Get the stored second value._ 
```C++
inline const StoredT2 falcon_core::generic::Pair::second () const
```




<hr>



### function second [2/2]

_Get the stored second value._ 
```C++
inline StoredT2 falcon_core::generic::Pair::second () 
```




<hr>
## Protected Functions Documentation




### function Pair [3/3]

```C++
falcon_core::generic::Pair::Pair () = default
```




<hr>



### function copy\_impl [1/4]

```C++
inline void falcon_core::generic::Pair::copy_impl (
    const Pair < T1, T2 > & other,
    category::primitive_tag,
    category::primitive_tag
) 
```




<hr>



### function copy\_impl [2/4]

```C++
inline void falcon_core::generic::Pair::copy_impl (
    const Pair < T1, T2 > & other,
    category::primitive_tag,
    category::song_tag
) 
```




<hr>



### function copy\_impl [3/4]

```C++
inline void falcon_core::generic::Pair::copy_impl (
    const Pair < T1, T2 > & other,
    category::song_tag,
    category::primitive_tag
) 
```




<hr>



### function copy\_impl [4/4]

```C++
inline void falcon_core::generic::Pair::copy_impl (
    const Pair < T1, T2 > & other,
    category::song_tag,
    category::song_tag
) 
```




<hr>



### function operator\_equal\_impl [1/4]

```C++
template<typename U1, typename U2>
inline bool falcon_core::generic::Pair::operator_equal_impl (
    const Pair < U1, U2 > & other,
    category::primitive_tag,
    category::primitive_tag
) const
```




<hr>



### function operator\_equal\_impl [2/4]

```C++
template<typename U1, typename U2>
inline bool falcon_core::generic::Pair::operator_equal_impl (
    const Pair < U1, U2 > & other,
    category::primitive_tag,
    category::song_tag
) const
```




<hr>



### function operator\_equal\_impl [3/4]

```C++
template<typename U1, typename U2>
inline bool falcon_core::generic::Pair::operator_equal_impl (
    const Pair < U1, U2 > & other,
    category::song_tag,
    category::primitive_tag
) const
```




<hr>



### function operator\_equal\_impl [4/4]

```C++
template<typename U1, typename U2>
inline bool falcon_core::generic::Pair::operator_equal_impl (
    const Pair < U1, U2 > & other,
    category::song_tag,
    category::song_tag
) const
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::generic::Pair::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::generic::Pair::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/Pair.hpp`

