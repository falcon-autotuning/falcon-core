

# Class falcon\_core::math::arrays::IsLabelled

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**arrays**](namespacefalcon__core_1_1math_1_1arrays.md) **>** [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)








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
|  const physics::device\_structures::ConnectionSP | [**connection**](#function-connection) () const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**flip**](#function-flip) (size\_t axis) const<br>_Flip the data along the given axis._  |
|  generic::ListSP&lt; std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; &gt; | [**gradient**](#function-gradient-12) () const<br>_Return the gradient of the data along all axes._  |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**gradient**](#function-gradient-22) (size\_t axis) const<br>_Return the gradient of the data along a given axis._  |
|  const instrument\_interfaces::names::Instrument | [**instrument\_type**](#function-instrument_type) () const<br> |
|  autotuner\_interfaces::contexts::AcquisitionContextSP | [**label**](#function-label) () const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator\***](#function-operator) (const std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator\***](#function-operator_1) (const int other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator\***](#function-operator_2) (const double other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator+**](#function-operator_3) (const std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator+**](#function-operator_4) (const int other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator+**](#function-operator_5) (const double other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator-**](#function-operator-) () const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator-**](#function-operator-_1) (const std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator-**](#function-operator-_2) (const int other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator-**](#function-operator-_3) (const double other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator/**](#function-operator_6) (const std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; & other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator/**](#function-operator_7) (const int other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator/**](#function-operator_8) (const double other) const<br> |
|  std::shared\_ptr&lt; [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md)&lt; T &gt; &gt; | [**operator^**](#function-operator_9) (const int other) const<br> |
|  const physics::units::SymbolUnitSP | [**units**](#function-units) () const<br> |


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
|  autotuner\_interfaces::contexts::AcquisitionContextSP | [**\_label**](#variable-_label)  <br> |
|  std::shared\_timed\_mutex | [**\_mu\_label**](#variable-_mu_label)  <br> |








































## Public Functions Documentation




### function connection 

```C++
inline const physics::device_structures::ConnectionSP falcon_core::math::arrays::IsLabelled::connection () const
```




<hr>



### function flip 

_Flip the data along the given axis._ 
```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::flip (
    size_t axis
) const
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md). 





        

<hr>



### function gradient [1/2]

_Return the gradient of the data along all axes._ 
```C++
inline generic::ListSP< std::shared_ptr< IsLabelled < T > > > falcon_core::math::arrays::IsLabelled::gradient () const
```




<hr>



### function gradient [2/2]

_Return the gradient of the data along a given axis._ 
```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::gradient (
    size_t axis
) const
```





**Parameters:**


* `axis` The axis to compute the gradient. 



**Returns:**

The gradient [**IsLabelled**](classfalcon__core_1_1math_1_1arrays_1_1IsLabelled.md). 





        

<hr>



### function instrument\_type 

```C++
inline const instrument_interfaces::names::Instrument falcon_core::math::arrays::IsLabelled::instrument_type () const
```




<hr>



### function label 

```C++
inline autotuner_interfaces::contexts::AcquisitionContextSP falcon_core::math::arrays::IsLabelled::label () const
```




<hr>



### function operator\* 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator* (
    const std::shared_ptr< IsLabelled < T > > & other
) const
```




<hr>



### function operator\* 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator* (
    const int other
) const
```




<hr>



### function operator\* 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator* (
    const double other
) const
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator+ (
    const std::shared_ptr< IsLabelled < T > > & other
) const
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator+ (
    const int other
) const
```




<hr>



### function operator+ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator+ (
    const double other
) const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator- () const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator- (
    const std::shared_ptr< IsLabelled < T > > & other
) const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator- (
    const int other
) const
```




<hr>



### function operator- 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator- (
    const double other
) const
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator/ (
    const std::shared_ptr< IsLabelled < T > > & other
) const
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator/ (
    const int other
) const
```




<hr>



### function operator/ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator/ (
    const double other
) const
```




<hr>



### function operator^ 

```C++
inline std::shared_ptr< IsLabelled < T > > falcon_core::math::arrays::IsLabelled::operator^ (
    const int other
) const
```




<hr>



### function units 

```C++
inline const physics::units::SymbolUnitSP falcon_core::math::arrays::IsLabelled::units () const
```




<hr>
## Protected Attributes Documentation




### variable \_label 

```C++
autotuner_interfaces::contexts::AcquisitionContextSP falcon_core::math::arrays::IsLabelled< T >::_label;
```




<hr>



### variable \_mu\_label 

```C++
std::shared_timed_mutex falcon_core::math::arrays::IsLabelled< T >::_mu_label;
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::arrays::IsLabelled::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/arrays/IsLabelled.hpp`

