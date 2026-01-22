

# Class falcon\_core::generic::FArray

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**FArray**](classfalcon__core_1_1generic_1_1FArray.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md),  [falcon\_core::generic::IFArray](classfalcon__core_1_1generic_1_1IFArray.md)














## Public Types

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](#typedef-const_reference)  <br> |
| typedef T & | [**reference**](#typedef-reference)  <br> |
| typedef T | [**value\_type**](#typedef-value_type)  <br> |




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
|   | [**FArray**](#function-farray-15) (const FArray&lt; T &gt; & other) <br> |
|   | [**FArray**](#function-farray-25) () = default<br> |
|   | [**FArray**](#function-farray-35) (const array\_type & arr) <br> |
|   | [**FArray**](#function-farray-45) (array\_type && arr) noexcept<br> |
|   | [**FArray**](#function-farray-55) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**abs**](#function-abs) () const<br> |
| virtual array\_type::iterator | [**begin**](#function-begin) () noexcept override<br> |
| virtual array\_type::const\_iterator | [**cbegin**](#function-cbegin) () noexcept override const<br> |
| virtual array\_type::const\_iterator | [**cend**](#function-cend) () noexcept override const<br> |
| virtual array\_type & | [**data**](#function-data-12) () noexcept override<br> |
| virtual const array\_type & | [**data**](#function-data-22) () noexcept override const<br> |
| virtual size\_t | [**dimension**](#function-dimension) () noexcept override const<br> |
| virtual array\_type::iterator | [**end**](#function-end) () noexcept override<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**flip**](#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  double | [**get\_sum\_of\_squares**](#function-get_sum_of_squares-14) () const<br> |
|  double | [**get\_sum\_of\_squares**](#function-get_sum_of_squares-24) (const int other) const<br> |
|  double | [**get\_sum\_of\_squares**](#function-get_sum_of_squares-34) (const double other) const<br> |
|  double | [**get\_sum\_of\_squares**](#function-get_sum_of_squares-44) (const std::shared\_ptr&lt; [**generic::FArray**](classfalcon__core_1_1generic_1_1FArray.md)&lt; T &gt; &gt; & other) const<br> |
|  ListSP&lt; FArray&lt; T &gt; &gt; | [**gradient**](#function-gradient-12) () const<br>_Return the gradient of the data along all axes._  |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**gradient**](#function-gradient-22) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
| virtual T | [**max**](#function-max-12) () override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**max**](#function-max-22) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; other) const<br> |
| virtual T | [**min**](#function-min-12) () override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**min**](#function-min-22) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; other) const<br> |
| virtual  | [**operator array\_type &**](#function-operator-array_type-&) () override<br> |
| virtual  | [**operator const array\_type &**](#function-operator-const-array_type-&) () override const<br> |
|  bool | [**operator!=**](#function-operator) (const FArray&lt; T &gt; & other) const<br> |
|  decltype(auto) | [**operator()**](#function-operator_1) (Args &&... args) <br> |
|  decltype(auto) | [**operator()**](#function-operator_2) (Args &&... args) const<br> |
| virtual reference | [**operator()**](#function-operator_3) (size\_t i) override<br> |
| virtual const\_reference | [**operator()**](#function-operator_4) (size\_t i) override const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](#function-operator_5) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](#function-operator_6) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator\***](#function-operator_7) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator\*=**](#function-operator_8) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator\*=**](#function-operator_9) (const int other) <br> |
|  FArray&lt; T &gt; & | [**operator\*=**](#function-operator_10) (const FArray&lt; T &gt; & other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](#function-operator_11) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](#function-operator_12) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator+**](#function-operator_13) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator+=**](#function-operator_14) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator+=**](#function-operator_15) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator+=**](#function-operator_16) (const int other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](#function-operator-) () const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](#function-operator-_1) () <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](#function-operator-_2) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](#function-operator-_3) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator-**](#function-operator-_4) (const int other) const<br> |
|  FArray&lt; T &gt; & | [**operator-=**](#function-operator-_5) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator-=**](#function-operator-_6) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator-=**](#function-operator-_7) (const int other) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](#function-operator_17) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](#function-operator_18) (const int other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator/**](#function-operator_19) (const std::shared\_ptr&lt; FArray&lt; T &gt; &gt; & other) const<br> |
|  FArray&lt; T &gt; & | [**operator/=**](#function-operator_20) (const double other) <br> |
|  FArray&lt; T &gt; & | [**operator/=**](#function-operator_21) (const int other) <br> |
|  FArray&lt; T &gt; & | [**operator/=**](#function-operator_22) (const FArray&lt; T &gt; & other) <br> |
| virtual bool | [**operator&lt;**](#function-operator_23) (const T & value) override const<br>_Check if any of the data is less than the value._  |
|  FArray&lt; T &gt; & | [**operator=**](#function-operator_24) (const FArray&lt; T &gt; & other) <br> |
|  FArray&lt; T &gt; & | [**operator=**](#function-operator_25) (const array\_type & arr) <br> |
|  bool | [**operator==**](#function-operator_26) (const FArray&lt; T &gt; & other) const<br> |
| virtual bool | [**operator&gt;**](#function-operator_27) (const T & value) override const<br>_Check if any of the data is greater than the value._  |
|  std::shared\_ptr&lt; FArray&lt; double &gt; &gt; | [**operator^**](#function-operator_28) (const double other) const<br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**operator^**](#function-operator_29) (const int other) const<br> |
|  void | [**pow\_inplace**](#function-pow_inplace) (const T other) <br> |
| virtual T \* | [**raw\_data**](#function-raw_data-12) () noexcept override<br> |
| virtual const T \* | [**raw\_data**](#function-raw_data-22) () noexcept override const<br> |
| virtual void | [**remove\_offset**](#function-remove_offset) (const T & offset) override<br>_Remove the offset from the data._  |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**reshape**](#function-reshape) (const std::vector&lt; size\_t &gt; & shape) const<br>_Return a new Array with the given shape._  |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](#function-shape) () noexcept override const<br> |
| virtual size\_t | [**size**](#function-size) () noexcept override const<br> |
| virtual T | [**sum**](#function-sum) () override const<br>_Return the sum of the data._  |
|  decltype(auto) | [**view**](#function-view-12) (Args &&... args) <br> |
|  decltype(auto) | [**view**](#function-view-22) (Args &&... args) const<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](#function-where) (const T & value) override const<br>_Return the indices of the data where the value is._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**empty**](#function-empty) (const std::vector&lt; size\_t &gt; & shape) <br> |
|  std::shared\_ptr&lt; FArray&lt; T &gt; &gt; | [**zeros**](#function-zeros) (const std::vector&lt; size\_t &gt; & shape) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |
































































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |












## Public Types Documentation




### typedef array\_type 

```C++
using falcon_core::generic::FArray< T >::array_type =  xt::xarray<T>;
```




<hr>



### typedef const\_reference 

```C++
using falcon_core::generic::FArray< T >::const_reference =  const T&;
```




<hr>



### typedef reference 

```C++
using falcon_core::generic::FArray< T >::reference =  T&;
```




<hr>



### typedef value\_type 

```C++
using falcon_core::generic::FArray< T >::value_type =  T;
```




<hr>
## Public Functions Documentation




### function FArray [1/5]

```C++
inline falcon_core::generic::FArray::FArray (
    const FArray< T > & other
) 
```




<hr>



### function FArray [2/5]

```C++
falcon_core::generic::FArray::FArray () = default
```




<hr>



### function FArray [3/5]

```C++
inline falcon_core::generic::FArray::FArray (
    const array_type & arr
) 
```




<hr>



### function FArray [4/5]

```C++
inline falcon_core::generic::FArray::FArray (
    array_type && arr
) noexcept
```




<hr>



### function FArray [5/5]

```C++
inline explicit falcon_core::generic::FArray::FArray (
    const std::vector< size_t > & shape
) 
```




<hr>



### function abs 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::abs () const
```




<hr>



### function begin 

```C++
inline virtual array_type::iterator falcon_core::generic::FArray::begin () noexcept override
```



Implements [*falcon\_core::generic::IFArray::begin*](classfalcon__core_1_1generic_1_1IFArray.md#function-begin)


<hr>



### function cbegin 

```C++
inline virtual array_type::const_iterator falcon_core::generic::FArray::cbegin () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::cbegin*](classfalcon__core_1_1generic_1_1IFArray.md#function-cbegin)


<hr>



### function cend 

```C++
inline virtual array_type::const_iterator falcon_core::generic::FArray::cend () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::cend*](classfalcon__core_1_1generic_1_1IFArray.md#function-cend)


<hr>



### function data [1/2]

```C++
inline virtual array_type & falcon_core::generic::FArray::data () noexcept override
```



Implements [*falcon\_core::generic::IFArray::data*](classfalcon__core_1_1generic_1_1IFArray.md#function-data-12)


<hr>



### function data [2/2]

```C++
inline virtual const array_type & falcon_core::generic::FArray::data () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::data*](classfalcon__core_1_1generic_1_1IFArray.md#function-data-22)


<hr>



### function dimension 

```C++
inline virtual size_t falcon_core::generic::FArray::dimension () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::dimension*](classfalcon__core_1_1generic_1_1IFArray.md#function-dimension)


<hr>



### function end 

```C++
inline virtual array_type::iterator falcon_core::generic::FArray::end () noexcept override
```



Implements [*falcon\_core::generic::IFArray::end*](classfalcon__core_1_1generic_1_1IFArray.md#function-end)


<hr>



### function flip 

_Flip the data along the given axis._ 
```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::flip (
    size_t axis
) const
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped [**FArray**](classfalcon__core_1_1generic_1_1FArray.md). 





        

<hr>



### function get\_sum\_of\_squares [1/4]

```C++
inline double falcon_core::generic::FArray::get_sum_of_squares () const
```




<hr>



### function get\_sum\_of\_squares [2/4]

```C++
inline double falcon_core::generic::FArray::get_sum_of_squares (
    const int other
) const
```




<hr>



### function get\_sum\_of\_squares [3/4]

```C++
inline double falcon_core::generic::FArray::get_sum_of_squares (
    const double other
) const
```




<hr>



### function get\_sum\_of\_squares [4/4]

```C++
inline double falcon_core::generic::FArray::get_sum_of_squares (
    const std::shared_ptr< generic::FArray < T > > & other
) const
```




<hr>



### function gradient [1/2]

_Return the gradient of the data along all axes._ 
```C++
inline ListSP< FArray< T > > falcon_core::generic::FArray::gradient () const
```



Computes the gradient for each axis of the array using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference.






**Returns:**

A vector of [**FArray**](classfalcon__core_1_1generic_1_1FArray.md) gradients (one for each axis). 





        

<hr>



### function gradient [2/2]

_Return the gradient of the data along a given axis._ 
```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::gradient (
    size_t axis
) const
```



Computes the gradient along the specified axis using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference.






**Parameters:**


* `axis` The axis to compute the gradient. 



**Returns:**

The gradient [**FArray**](classfalcon__core_1_1generic_1_1FArray.md). 





        

<hr>



### function max [1/2]

```C++
inline virtual T falcon_core::generic::FArray::max () override const
```



Implements [*falcon\_core::generic::IFArray::max*](classfalcon__core_1_1generic_1_1IFArray.md#function-max)


<hr>



### function max [2/2]

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::max (
    const std::shared_ptr< FArray< T > > other
) const
```




<hr>



### function min [1/2]

```C++
inline virtual T falcon_core::generic::FArray::min () override const
```



Implements [*falcon\_core::generic::IFArray::min*](classfalcon__core_1_1generic_1_1IFArray.md#function-min)


<hr>



### function min [2/2]

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::min (
    const std::shared_ptr< FArray< T > > other
) const
```




<hr>



### function operator array\_type & 

```C++
inline virtual falcon_core::generic::FArray::operator array_type & () override
```



Implements [*falcon\_core::generic::IFArray::operator array\_type &*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-array_type-&)


<hr>



### function operator const array\_type & 

```C++
inline virtual falcon_core::generic::FArray::operator const array_type & () override const
```



Implements [*falcon\_core::generic::IFArray::operator const array\_type &*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator-const-array_type-&)


<hr>



### function operator!= 

```C++
inline bool falcon_core::generic::FArray::operator!= (
    const FArray< T > & other
) const
```




<hr>



### function operator() 

```C++
template<typename... Args>
inline decltype(auto) falcon_core::generic::FArray::operator() (
    Args &&... args
) 
```




<hr>



### function operator() 

```C++
template<typename... Args>
inline decltype(auto) falcon_core::generic::FArray::operator() (
    Args &&... args
) const
```




<hr>



### function operator() 

```C++
inline virtual reference falcon_core::generic::FArray::operator() (
    size_t i
) override
```



Implements [*falcon\_core::generic::IFArray::operator()*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator)


<hr>



### function operator() 

```C++
inline virtual const_reference falcon_core::generic::FArray::operator() (
    size_t i
) override const
```



Implements [*falcon\_core::generic::IFArray::operator()*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_1)


<hr>



### function operator\* 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator* (
    const double other
) const
```




<hr>



### function operator\* 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator* (
    const int other
) const
```




<hr>



### function operator\* 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator* (
    const std::shared_ptr< FArray< T > > & other
) const
```




<hr>



### function operator\*= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator*= (
    const double other
) 
```




<hr>



### function operator\*= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator*= (
    const int other
) 
```




<hr>



### function operator\*= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator*= (
    const FArray< T > & other
) 
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator+ (
    const double other
) const
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator+ (
    const int other
) const
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator+ (
    const std::shared_ptr< FArray< T > > & other
) const
```




<hr>



### function operator+= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator+= (
    const FArray< T > & other
) 
```




<hr>



### function operator+= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator+= (
    const double other
) 
```




<hr>



### function operator+= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator+= (
    const int other
) 
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator- () const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator- () 
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator- (
    const std::shared_ptr< FArray< T > > & other
) const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator- (
    const double other
) const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator- (
    const int other
) const
```




<hr>



### function operator-= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator-= (
    const FArray< T > & other
) 
```




<hr>



### function operator-= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator-= (
    const double other
) 
```




<hr>



### function operator-= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator-= (
    const int other
) 
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator/ (
    const double other
) const
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator/ (
    const int other
) const
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator/ (
    const std::shared_ptr< FArray< T > > & other
) const
```




<hr>



### function operator/= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator/= (
    const double other
) 
```




<hr>



### function operator/= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator/= (
    const int other
) 
```




<hr>



### function operator/= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator/= (
    const FArray< T > & other
) 
```




<hr>



### function operator&lt; 

_Check if any of the data is less than the value._ 
```C++
inline virtual bool falcon_core::generic::FArray::operator< (
    const T & value
) override const
```





**Parameters:**


* `value` The value to compare to. 



**Returns:**

True if any of the data is less than the value, False otherwise. 





        
Implements [*falcon\_core::generic::IFArray::operator&lt;*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_2)


<hr>



### function operator= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator= (
    const FArray< T > & other
) 
```




<hr>



### function operator= 

```C++
inline FArray< T > & falcon_core::generic::FArray::operator= (
    const array_type & arr
) 
```




<hr>



### function operator== 

```C++
inline bool falcon_core::generic::FArray::operator== (
    const FArray< T > & other
) const
```




<hr>



### function operator&gt; 

_Check if any of the data is greater than the value._ 
```C++
inline virtual bool falcon_core::generic::FArray::operator> (
    const T & value
) override const
```





**Parameters:**


* `value` The value to compare to. 



**Returns:**

True if any of the data is greater than the value, False otherwise. 





        
Implements [*falcon\_core::generic::IFArray::operator&gt;*](classfalcon__core_1_1generic_1_1IFArray.md#function-operator_3)


<hr>



### function operator^ 

```C++
inline std::shared_ptr< FArray< double > > falcon_core::generic::FArray::operator^ (
    const double other
) const
```




<hr>



### function operator^ 

```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::operator^ (
    const int other
) const
```




<hr>



### function pow\_inplace 

```C++
inline void falcon_core::generic::FArray::pow_inplace (
    const T other
) 
```




<hr>



### function raw\_data [1/2]

```C++
inline virtual T * falcon_core::generic::FArray::raw_data () noexcept override
```



Implements [*falcon\_core::generic::IFArray::raw\_data*](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-12)


<hr>



### function raw\_data [2/2]

```C++
inline virtual const T * falcon_core::generic::FArray::raw_data () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::raw\_data*](classfalcon__core_1_1generic_1_1IFArray.md#function-raw_data-22)


<hr>



### function remove\_offset 

_Remove the offset from the data._ 
```C++
inline virtual void falcon_core::generic::FArray::remove_offset (
    const T & offset
) override
```





**Parameters:**


* `offset` The offset to remove. 




        
Implements [*falcon\_core::generic::IFArray::remove\_offset*](classfalcon__core_1_1generic_1_1IFArray.md#function-remove_offset)


<hr>



### function reshape 

_Return a new Array with the given shape._ 
```C++
inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::reshape (
    const std::vector< size_t > & shape
) const
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped [**FArray**](classfalcon__core_1_1generic_1_1FArray.md). 





        

<hr>



### function shape 

```C++
inline virtual const xt::dynamic_shape< size_t > & falcon_core::generic::FArray::shape () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::shape*](classfalcon__core_1_1generic_1_1IFArray.md#function-shape)


<hr>



### function size 

```C++
inline virtual size_t falcon_core::generic::FArray::size () noexcept override const
```



Implements [*falcon\_core::generic::IFArray::size*](classfalcon__core_1_1generic_1_1IFArray.md#function-size)


<hr>



### function sum 

_Return the sum of the data._ 
```C++
inline virtual T falcon_core::generic::FArray::sum () override const
```





**Returns:**

The sum of the data. 





        
Implements [*falcon\_core::generic::IFArray::sum*](classfalcon__core_1_1generic_1_1IFArray.md#function-sum)


<hr>



### function view [1/2]

```C++
template<typename... Args>
inline decltype(auto) falcon_core::generic::FArray::view (
    Args &&... args
) 
```




<hr>



### function view [2/2]

```C++
template<typename... Args>
inline decltype(auto) falcon_core::generic::FArray::view (
    Args &&... args
) const
```




<hr>



### function where 

_Return the indices of the data where the value is._ 
```C++
inline virtual ListSP< List < size_t > > falcon_core::generic::FArray::where (
    const T & value
) override const
```





**Parameters:**


* `value` The value to search for. 



**Returns:**

Indices where the value matches. 





        
Implements [*falcon\_core::generic::IFArray::where*](classfalcon__core_1_1generic_1_1IFArray.md#function-where)


<hr>
## Public Static Functions Documentation




### function empty 

```C++
static inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::empty (
    const std::vector< size_t > & shape
) 
```




<hr>



### function zeros 

```C++
static inline std::shared_ptr< FArray< T > > falcon_core::generic::FArray::zeros (
    const std::vector< size_t > & shape
) 
```




<hr>
## Protected Functions Documentation




### function serialize 

```C++
template<class Archive>
inline void falcon_core::generic::FArray::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::generic::FArray::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/FArray.hpp`

