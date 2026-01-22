

# Class falcon\_core::math::arrays::IsControl

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**IsControl**](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md)








Inherits the following classes: [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)
















## Public Types inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-const_reference)  <br> |
| typedef T & | [**reference**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-reference)  <br> |
| typedef T | [**value\_type**](classfalcon__core_1_1generic_1_1IFArray.md#typedef-value_type)  <br> |






































## Public Functions

| Type | Name |
| ---: | :--- |
|  IncreasingAlignmentSP | [**\_determine\_alignments**](#function-_determine_alignments) () <br>_Determine the alignment for each dimension of the array. for each dimension checks if the values are increasing, decreasing, or not changing._  |
|  IncreasingAlignmentSP | [**alignment**](#function-alignment) () const<br>_Return the increasing alignments for each dimension._  |
| virtual generic::FArraySP&lt; T &gt; | [**gradient**](#function-gradient-12) (size\_t axis) const = 0<br> |
| virtual generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**gradient**](#function-gradient-22) () const = 0<br> |
|  int | [**principle\_dimension**](#function-principle_dimension) () const<br>_Return the principle dimension of the array._  |
|  void | [**update\_alignments**](#function-update_alignments) () <br>_Recalculates the alignments zmerinobased on current data._  |


## Public Functions inherited from falcon_core::generic::IFArray

See [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)

| Type | Name |
| ---: | :--- |
| virtual array\_type::iterator | [**begin**](classfalcon__core_1_1generic_1_1IFArray.md#function-begin) () noexcept = 0<br> |
| virtual array\_type::const\_iterator | [**cbegin**](classfalcon__core_1_1generic_1_1IFArray.md#function-cbegin) () noexcept const = 0<br> |
| virtual array\_type::const\_iterator | [**cend**](classfalcon__core_1_1generic_1_1IFArray.md#function-cend) () noexcept const = 0<br> |
| virtual array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-12) () noexcept = 0<br> |
| virtual const array\_type & | [**data**](classfalcon__core_1_1generic_1_1IFArray.md#function-data-22) () noexcept const = 0<br> |
| virtual size\_t | [**dimension**](classfalcon__core_1_1generic_1_1IFArray.md#function-dimension) () noexcept const = 0<br> |
| virtual array\_type::iterator | [**end**](classfalcon__core_1_1generic_1_1IFArray.md#function-end) () noexcept = 0<br> |
| virtual T | [**max**](classfalcon__core_1_1generic_1_1IFArray.md#function-max) () const = 0<br> |
| virtual T | [**min**](classfalcon__core_1_1generic_1_1IFArray.md#function-min) () const = 0<br> |
| virtual  | [**operator array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-array_type-&) () = 0<br> |
| virtual  | [**operator const array\_type &**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-const-array_type-&) () const = 0<br> |
| virtual reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator) (size\_t i) = 0<br> |
| virtual const\_reference | [**operator()**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_1) (size\_t i) const = 0<br> |
| virtual bool | [**operator&lt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_2) (const T & value) const = 0<br> |
| virtual bool | [**operator&gt;**](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_3) (const T & value) const = 0<br> |
| virtual T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-12) () noexcept = 0<br> |
| virtual const T \* | [**raw\_data**](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-22) () noexcept const = 0<br> |
| virtual void | [**remove\_offset**](classfalcon__core_1_1generic_1_1IFArray.md#function-remove_offset) (const T & offset) = 0<br> |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](classfalcon__core_1_1generic_1_1IFArray.md#function-shape) () noexcept const = 0<br> |
| virtual size\_t | [**size**](classfalcon__core_1_1generic_1_1IFArray.md#function-size) () noexcept const = 0<br> |
| virtual T | [**sum**](classfalcon__core_1_1generic_1_1IFArray.md#function-sum) () const = 0<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](classfalcon__core_1_1generic_1_1IFArray.md#function-where) (const T & value) const = 0<br> |
| virtual  | [**~IFArray**](classfalcon__core_1_1generic_1_1IFArray.md#function-ifarray) () = default<br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  IncreasingAlignmentSP | [**\_alignment**](#variable-_alignment)  <br> |
|  std::shared\_timed\_mutex | [**\_mu\_alignment**](#variable-_mu_alignment)  <br> |
|  std::shared\_timed\_mutex | [**\_mu\_principle\_dimension**](#variable-_mu_principle_dimension)  <br> |
|  int | [**\_principle\_dimension**](#variable-_principle_dimension)  <br> |








































## Public Functions Documentation




### function \_determine\_alignments 

_Determine the alignment for each dimension of the array. for each dimension checks if the values are increasing, decreasing, or not changing._ 
```C++
inline IncreasingAlignmentSP falcon_core::math::arrays::IsControl::_determine_alignments () 
```





**Returns:**

the alignment for each dimension. 




**Exception:**


* `std::runtime_error` if no alignment is found. 
* `std::runtime_error` if more than one alignment is found. 




        

<hr>



### function alignment 

_Return the increasing alignments for each dimension._ 
```C++
inline IncreasingAlignmentSP falcon_core::math::arrays::IsControl::alignment () const
```




<hr>



### function gradient [1/2]

```C++
virtual generic::FArraySP< T > falcon_core::math::arrays::IsControl::gradient (
    size_t axis
) const = 0
```




<hr>



### function gradient [2/2]

```C++
virtual generic::ListSP< generic::FArray < T > > falcon_core::math::arrays::IsControl::gradient () const = 0
```




<hr>



### function principle\_dimension 

_Return the principle dimension of the array._ 
```C++
inline int falcon_core::math::arrays::IsControl::principle_dimension () const
```




<hr>



### function update\_alignments 

_Recalculates the alignments zmerinobased on current data._ 
```C++
inline void falcon_core::math::arrays::IsControl::update_alignments () 
```




<hr>
## Protected Attributes Documentation




### variable \_alignment 

```C++
IncreasingAlignmentSP falcon_core::math::arrays::IsControl< T >::_alignment;
```




<hr>



### variable \_mu\_alignment 

```C++
std::shared_timed_mutex falcon_core::math::arrays::IsControl< T >::_mu_alignment;
```




<hr>



### variable \_mu\_principle\_dimension 

```C++
std::shared_timed_mutex falcon_core::math::arrays::IsControl< T >::_mu_principle_dimension;
```




<hr>



### variable \_principle\_dimension 

```C++
int falcon_core::math::arrays::IsControl< T >::_principle_dimension;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/IsControl.hpp`

