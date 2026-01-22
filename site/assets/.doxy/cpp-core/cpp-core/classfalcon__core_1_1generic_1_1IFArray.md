

# Class falcon\_core::generic::IFArray

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**generic**](namespacefalcon__core_1_1generic.md) **>** [**IFArray**](classfalcon__core_1_1generic_1_1IFArray.md)










Inherited by the following classes: [falcon\_core::generic::FArray](classfalcon__core_1_1generic_1_1FArray.md),  [falcon\_core::math::arrays::Is1D](classfalcon__core_1_1math_1_1arrays_1_1Is1D.md),  [falcon\_core::math::arrays::IsControl](classfalcon__core_1_1math_1_1arrays_1_1IsControl.md),  [falcon\_core::math::arrays::IsLabelled](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef xt::xarray&lt; T &gt; | [**array\_type**](#typedef-array_type)  <br> |
| typedef const T & | [**const\_reference**](#typedef-const_reference)  <br> |
| typedef T & | [**reference**](#typedef-reference)  <br> |
| typedef T | [**value\_type**](#typedef-value_type)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
| virtual array\_type::iterator | [**begin**](#function-begin) () noexcept = 0<br> |
| virtual array\_type::const\_iterator | [**cbegin**](#function-cbegin) () noexcept const = 0<br> |
| virtual array\_type::const\_iterator | [**cend**](#function-cend) () noexcept const = 0<br> |
| virtual array\_type & | [**data**](#function-data-12) () noexcept = 0<br> |
| virtual const array\_type & | [**data**](#function-data-22) () noexcept const = 0<br> |
| virtual size\_t | [**dimension**](#function-dimension) () noexcept const = 0<br> |
| virtual array\_type::iterator | [**end**](#function-end) () noexcept = 0<br> |
| virtual T | [**max**](#function-max) () const = 0<br> |
| virtual T | [**min**](#function-min) () const = 0<br> |
| virtual  | [**operator array\_type &**](#function-operator-array_type-&) () = 0<br> |
| virtual  | [**operator const array\_type &**](#function-operator-const-array_type-&) () const = 0<br> |
| virtual reference | [**operator()**](#function-operator) (size\_t i) = 0<br> |
| virtual const\_reference | [**operator()**](#function-operator_1) (size\_t i) const = 0<br> |
| virtual bool | [**operator&lt;**](#function-operator_2) (const T & value) const = 0<br> |
| virtual bool | [**operator&gt;**](#function-operator_3) (const T & value) const = 0<br> |
| virtual T \* | [**raw\_data**](#function-raw_data-12) () noexcept = 0<br> |
| virtual const T \* | [**raw\_data**](#function-raw_data-22) () noexcept const = 0<br> |
| virtual void | [**remove\_offset**](#function-remove_offset) (const T & offset) = 0<br> |
| virtual const xt::dynamic\_shape&lt; size\_t &gt; & | [**shape**](#function-shape) () noexcept const = 0<br> |
| virtual size\_t | [**size**](#function-size) () noexcept const = 0<br> |
| virtual T | [**sum**](#function-sum) () const = 0<br> |
| virtual ListSP&lt; [**List**](classfalcon__core_1_1generic_1_1List.md)&lt; size\_t &gt; &gt; | [**where**](#function-where) (const T & value) const = 0<br> |
| virtual  | [**~IFArray**](#function-ifarray) () = default<br> |




























## Public Types Documentation




### typedef array\_type 

```C++
using falcon_core::generic::IFArray< T >::array_type =  xt::xarray<T>;
```




<hr>



### typedef const\_reference 

```C++
using falcon_core::generic::IFArray< T >::const_reference =  const T&;
```




<hr>



### typedef reference 

```C++
using falcon_core::generic::IFArray< T >::reference =  T&;
```




<hr>



### typedef value\_type 

```C++
using falcon_core::generic::IFArray< T >::value_type =  T;
```




<hr>
## Public Functions Documentation




### function begin 

```C++
virtual array_type::iterator falcon_core::generic::IFArray::begin () noexcept = 0
```




<hr>



### function cbegin 

```C++
virtual array_type::const_iterator falcon_core::generic::IFArray::cbegin () noexcept const = 0
```




<hr>



### function cend 

```C++
virtual array_type::const_iterator falcon_core::generic::IFArray::cend () noexcept const = 0
```




<hr>



### function data [1/2]

```C++
virtual array_type & falcon_core::generic::IFArray::data () noexcept = 0
```




<hr>



### function data [2/2]

```C++
virtual const array_type & falcon_core::generic::IFArray::data () noexcept const = 0
```




<hr>



### function dimension 

```C++
virtual size_t falcon_core::generic::IFArray::dimension () noexcept const = 0
```




<hr>



### function end 

```C++
virtual array_type::iterator falcon_core::generic::IFArray::end () noexcept = 0
```




<hr>



### function max 

```C++
virtual T falcon_core::generic::IFArray::max () const = 0
```




<hr>



### function min 

```C++
virtual T falcon_core::generic::IFArray::min () const = 0
```




<hr>



### function operator array\_type & 

```C++
virtual falcon_core::generic::IFArray::operator array_type & () = 0
```




<hr>



### function operator const array\_type & 

```C++
virtual falcon_core::generic::IFArray::operator const array_type & () const = 0
```




<hr>



### function operator() 

```C++
virtual reference falcon_core::generic::IFArray::operator() (
    size_t i
) = 0
```




<hr>



### function operator() 

```C++
virtual const_reference falcon_core::generic::IFArray::operator() (
    size_t i
) const = 0
```




<hr>



### function operator&lt; 

```C++
virtual bool falcon_core::generic::IFArray::operator< (
    const T & value
) const = 0
```




<hr>



### function operator&gt; 

```C++
virtual bool falcon_core::generic::IFArray::operator> (
    const T & value
) const = 0
```




<hr>



### function raw\_data [1/2]

```C++
virtual T * falcon_core::generic::IFArray::raw_data () noexcept = 0
```




<hr>



### function raw\_data [2/2]

```C++
virtual const T * falcon_core::generic::IFArray::raw_data () noexcept const = 0
```




<hr>



### function remove\_offset 

```C++
virtual void falcon_core::generic::IFArray::remove_offset (
    const T & offset
) = 0
```




<hr>



### function shape 

```C++
virtual const xt::dynamic_shape< size_t > & falcon_core::generic::IFArray::shape () noexcept const = 0
```




<hr>



### function size 

```C++
virtual size_t falcon_core::generic::IFArray::size () noexcept const = 0
```




<hr>



### function sum 

```C++
virtual T falcon_core::generic::IFArray::sum () const = 0
```




<hr>



### function where 

```C++
virtual ListSP< List < size_t > > falcon_core::generic::IFArray::where (
    const T & value
) const = 0
```




<hr>



### function ~IFArray 

```C++
virtual falcon_core::generic::IFArray::~IFArray () = default
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/generic/FArrayProtocol.hpp`

