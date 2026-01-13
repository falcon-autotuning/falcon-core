

# Class falcon\_core::math::arrays::LabelledArrays

**template &lt;typename ArrayType&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)



_Container for multiple labelled arrays._ [More...](#detailed-description)

* `#include <LabelledArrays.hpp>`



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
|   | [**LabelledArrays**](#function-labelledarrays-12) () <br> |
|   | [**LabelledArrays**](#function-labelledarrays-22) (const std::vector&lt; std::shared\_ptr&lt; ArrayType &gt; &gt; & items) <br> |
|  std::vector&lt; std::shared\_ptr&lt; ArrayType &gt; &gt; | [**arrays**](#function-arrays) () <br>_Returns the internal vector of labelled arrays._  |
|  void | [**check\_array\_labels**](#function-check_array_labels) () const<br>_Checks that all array labels are unique._  |
|  bool | [**is\_control\_arrays**](#function-is_control_arrays) () const<br>_Checks if the contents are of control arrays._  |
|  bool | [**is\_measured\_arrays**](#function-is_measured_arrays) () const<br>_Checks if the contents are of measured arrays._  |
|  generic::ListSP&lt; [**autotuner\_interfaces::contexts::AcquisitionContext**](classfalcon__core_1_1autotuner__interfaces_1_1contexts_1_1AcquisitionContext.md) &gt; | [**labels**](#function-labels) () const<br>_Returns the labels of all labelled arrays._  |


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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)&lt; [**LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) &gt; &gt; | [**LabelledControlArrays**](#function-labelledcontrolarrays-12) (const std::vector&lt; LabelledControlArraySP &gt; & arrays) <br>_Construct a collection of labelled control arrays._  |
|  std::shared\_ptr&lt; [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)&lt; [**LabelledControlArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledControlArray.md) &gt; &gt; | [**LabelledControlArrays**](#function-labelledcontrolarrays-22) () <br> |
|  std::shared\_ptr&lt; [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)&lt; [**LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; &gt; | [**LabelledMeasuredArrays**](#function-labelledmeasuredarrays-12) (const std::vector&lt; LabelledMeasuredArraySP &gt; & arrays) <br>_Construct a collection of labelled measured arrays._  |
|  std::shared\_ptr&lt; [**LabelledArrays**](classfalcon__core_1_1math_1_1arrays_1_1LabelledArrays.md)&lt; [**LabelledMeasuredArray**](classfalcon__core_1_1math_1_1arrays_1_1LabelledMeasuredArray.md) &gt; &gt; | [**LabelledMeasuredArrays**](#function-labelledmeasuredarrays-22) () <br> |


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




**Parameters:**


* `T` Type of labelled array. 




    
## Public Functions Documentation




### function LabelledArrays [1/2]

```C++
inline falcon_core::math::arrays::LabelledArrays::LabelledArrays () 
```




<hr>



### function LabelledArrays [2/2]

```C++
inline falcon_core::math::arrays::LabelledArrays::LabelledArrays (
    const std::vector< std::shared_ptr< ArrayType > > & items
) 
```




<hr>



### function arrays 

_Returns the internal vector of labelled arrays._ 
```C++
inline std::vector< std::shared_ptr< ArrayType > > falcon_core::math::arrays::LabelledArrays::arrays () 
```




<hr>



### function check\_array\_labels 

_Checks that all array labels are unique._ 
```C++
inline void falcon_core::math::arrays::LabelledArrays::check_array_labels () const
```





**Exception:**


* `std::runtime_error` if any labels are not unique. 




        

<hr>



### function is\_control\_arrays 

_Checks if the contents are of control arrays._ 
```C++
inline bool falcon_core::math::arrays::LabelledArrays::is_control_arrays () const
```




<hr>



### function is\_measured\_arrays 

_Checks if the contents are of measured arrays._ 
```C++
inline bool falcon_core::math::arrays::LabelledArrays::is_measured_arrays () const
```




<hr>



### function labels 

_Returns the labels of all labelled arrays._ 
```C++
inline generic::ListSP< autotuner_interfaces::contexts::AcquisitionContext > falcon_core::math::arrays::LabelledArrays::labels () const
```




<hr>
## Public Static Functions Documentation




### function LabelledControlArrays [1/2]

_Construct a collection of labelled control arrays._ 
```C++
static inline std::shared_ptr< LabelledArrays < LabelledControlArray > > falcon_core::math::arrays::LabelledArrays::LabelledControlArrays (
    const std::vector< LabelledControlArraySP > & arrays
) 
```




<hr>



### function LabelledControlArrays [2/2]

```C++
static inline std::shared_ptr< LabelledArrays < LabelledControlArray > > falcon_core::math::arrays::LabelledArrays::LabelledControlArrays () 
```




<hr>



### function LabelledMeasuredArrays [1/2]

_Construct a collection of labelled measured arrays._ 
```C++
static inline std::shared_ptr< LabelledArrays < LabelledMeasuredArray > > falcon_core::math::arrays::LabelledArrays::LabelledMeasuredArrays (
    const std::vector< LabelledMeasuredArraySP > & arrays
) 
```




<hr>



### function LabelledMeasuredArrays [2/2]

```C++
static inline std::shared_ptr< LabelledArrays < LabelledMeasuredArray > > falcon_core::math::arrays::LabelledArrays::LabelledMeasuredArrays () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/LabelledArrays.hpp`

