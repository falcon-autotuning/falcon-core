

# Class falcon\_core::math::arrays::Is1D

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**Is1D**](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md)








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
|  generic::FArraySP&lt; T &gt; | [**as\_1D**](#function-as_1d) () const<br>_Return the data as a 1D array._  |
|  generic::ListSP&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; | [**even\_divisions**](#function-even_divisions) (size\_t divisions) const<br>_Splits the array into even divisions if possible._  |
|  size\_t | [**get\_closest\_index**](#function-get_closest_index) (double value) const<br>_Get the index of the closest element to the given value._  |
|  T | [**get\_distance**](#function-get_distance) () const<br>_Get the distance between the first and last element of the 1D array._  |
|  T | [**get\_end**](#function-get_end) () const<br>_Get the last element of the 1D array._  |
|  double | [**get\_mean**](#function-get_mean) () const<br>_Get the mean of the 1D array._  |
|  T | [**get\_start**](#function-get_start) () const<br>_Get the first element of the 1D array._  |
|  double | [**get\_std**](#function-get_std) () const<br>_Get the standard deviation of the 1D array._  |
|  bool | [**is\_1D**](#function-is_1d) () const<br>_Check if the array is 1D._  |
|  bool | [**is\_decreasing**](#function-is_decreasing) () const<br>_Check if the array is decreasing._  |
|  bool | [**is\_increasing**](#function-is_increasing) () const<br>_Check if the array is increasing._  |
|  void | [**reverse**](#function-reverse) () <br>_Reverse the 1D array._  |


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






















































## Public Functions Documentation




### function as\_1D 

_Return the data as a 1D array._ 
```C++
inline generic::FArraySP< T > falcon_core::math::arrays::Is1D::as_1D () const
```





**Returns:**

The data as a 1D array. 




**Exception:**


* `std::runtime_error` if not 1D. 




        

<hr>



### function even\_divisions 

_Splits the array into even divisions if possible._ 
```C++
inline generic::ListSP< generic::FArray < T > > falcon_core::math::arrays::Is1D::even_divisions (
    size_t divisions
) const
```





**Parameters:**


* `divisions` The number of divisions to split the array into. 



**Returns:**

The divisions as a ListSP of BaseArray segments. 




**Exception:**


* `std::runtime_error` if array cannot be evenly divided. 




        

<hr>



### function get\_closest\_index 

_Get the index of the closest element to the given value._ 
```C++
inline size_t falcon_core::math::arrays::Is1D::get_closest_index (
    double value
) const
```





**Parameters:**


* `value` The value to find the closest index to. 



**Returns:**

The index of the closest element. 





        

<hr>



### function get\_distance 

_Get the distance between the first and last element of the 1D array._ 
```C++
inline T falcon_core::math::arrays::Is1D::get_distance () const
```





**Returns:**

The distance between the first and last element of the 1D array. 





        

<hr>



### function get\_end 

_Get the last element of the 1D array._ 
```C++
inline T falcon_core::math::arrays::Is1D::get_end () const
```





**Returns:**

The last element of the 1D array. 





        

<hr>



### function get\_mean 

_Get the mean of the 1D array._ 
```C++
inline double falcon_core::math::arrays::Is1D::get_mean () const
```





**Returns:**

The mean value. 





        

<hr>



### function get\_start 

_Get the first element of the 1D array._ 
```C++
inline T falcon_core::math::arrays::Is1D::get_start () const
```





**Returns:**

The first element of the 1D array. 





        

<hr>



### function get\_std 

_Get the standard deviation of the 1D array._ 
```C++
inline double falcon_core::math::arrays::Is1D::get_std () const
```





**Returns:**

The standard deviation value. 





        

<hr>



### function is\_1D 

_Check if the array is 1D._ 
```C++
inline bool falcon_core::math::arrays::Is1D::is_1D () const
```





**Returns:**

True if the array is 1D, False otherwise. 





        

<hr>



### function is\_decreasing 

_Check if the array is decreasing._ 
```C++
inline bool falcon_core::math::arrays::Is1D::is_decreasing () const
```





**Returns:**

True if the array is decreasing, False otherwise. 





        

<hr>



### function is\_increasing 

_Check if the array is increasing._ 
```C++
inline bool falcon_core::math::arrays::Is1D::is_increasing () const
```





**Returns:**

True if the array is increasing, False otherwise. 





        

<hr>



### function reverse 

_Reverse the 1D array._ 
```C++
inline void falcon_core::math::arrays::Is1D::reverse () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/Is1D.hpp`

