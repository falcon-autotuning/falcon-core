

# Class falcon\_core::math::domains::Domain



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**domains**](namespacefalcon__core_1_1math_1_1domains.md) **>** [**Domain**](classfalcon__core_1_1math_1_1domains_1_1Domain.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::math::domains::LabelledDomain](classfalcon__core_1_1math_1_1domains_1_1LabelledDomain.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Domain**](#function-domain-14) (const Domain & other) <br> |
|   | [**Domain**](#function-domain-24) (double min\_val, double max\_val, bool lesser\_bound\_contained=true, bool greater\_bound\_contained=true) <br>_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _._ |
|   | [**Domain**](#function-domain-34) (std::pair&lt; double, double &gt; bounds, bool lesser\_bound\_contained=true, bool greater\_bound\_contained=true) <br>_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _from a pair of bounds._ |
|  const std::pair&lt; double, double &gt; | [**bounds**](#function-bounds) () const<br>_Get the bounds of the domain as a pair._  |
|  const std::pair&lt; double, double &gt; | [**calculate\_transform**](#function-calculate_transform) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Calculate the linear transformation parameters to map this domain to another domain._  |
|  const bool | [**contains\_domain**](#function-contains_domain) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Check if this domain completely contains another domain._  |
|  const double | [**get\_center**](#function-get_center) () const<br>_Get the center of the domain._  |
|  const double | [**greater\_bound**](#function-greater_bound) () const<br>_Get the greater bound of the domain._  |
|  const bool | [**greater\_bound\_contained**](#function-greater_bound_contained) () const<br>_Check if the greater bound is contained in the domain._  |
|  const bool | [**in**](#function-in) (double value) const<br>_Check if a value is in the domain._  |
|  const bool | [**is\_empty**](#function-is_empty) () const<br>_Check if the domain is empty._  |
|  const double | [**lesser\_bound**](#function-lesser_bound) () const<br>_Get the lesser bound of the domain._  |
|  const bool | [**lesser\_bound\_contained**](#function-lesser_bound_contained) () const<br>_Check if the lesser bound is contained in the domain._  |
|  bool | [**operator!=**](#function-operator) (const Domain & other) const<br> |
|  const std::shared\_ptr&lt; Domain &gt; | [**operator&**](#function-operator_1) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Get the intersection of this domain with another domain._  |
|  Domain & | [**operator=**](#function-operator_2) (const Domain & other) <br> |
|  bool | [**operator==**](#function-operator_3) (const Domain & other) const<br> |
|  const std::shared\_ptr&lt; Domain &gt; | [**operator\|**](#function-operator_4) (const std::shared\_ptr&lt; Domain &gt; & other) const<br>_Get the union of this domain with another domain._  |
|  const double | [**range**](#function-range) () const<br>_Get the size of the domain._  |
|  const std::shared\_ptr&lt; Domain &gt; | [**scale**](#function-scale) (double factor) const<br>_Scale the domain by a factor._  |
|  const std::shared\_ptr&lt; Domain &gt; | [**shift**](#function-shift) (double offset) const<br>_Shift the domain by an offset._  |
|  const double | [**transform**](#function-transform) (const std::shared\_ptr&lt; Domain &gt; & other, double value) const<br>_Transform a value from this domain to another domain._  |


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
|   | [**Domain**](#function-domain-44) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function Domain [1/4]

```C++
falcon_core::math::domains::Domain::Domain (
    const Domain & other
) 
```




<hr>



### function Domain [2/4]

_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _._
```C++
falcon_core::math::domains::Domain::Domain (
    double min_val,
    double max_val,
    bool lesser_bound_contained=true,
    bool greater_bound_contained=true
) 
```





**Parameters:**


* `min_val` Minimum value of the domain. 
* `max_val` Maximum value of the domain. 
* `lesser_bound_contained` Whether the minimum value is included in the domain. 
* `greater_bound_contained` Whether the maximum value is included in the domain. 



**Exception:**


* `std::invalid_argument` if min\_val is greater than max\_val. 




        

<hr>



### function Domain [3/4]

_Construct a_ [_**Domain**_](classfalcon__core_1_1math_1_1domains_1_1Domain.md) _from a pair of bounds._
```C++
falcon_core::math::domains::Domain::Domain (
    std::pair< double, double > bounds,
    bool lesser_bound_contained=true,
    bool greater_bound_contained=true
) 
```





**Parameters:**


* `bounds` A pair of doubles representing the minimum and maximum values. 
* `lesser_bound_contained` Whether the minimum value is included in the domain. 
* `greater_bound_contained` Whether the maximum value is included in the domain. 




        

<hr>



### function bounds 

_Get the bounds of the domain as a pair._ 
```C++
const std::pair< double, double > falcon_core::math::domains::Domain::bounds () const
```





**Returns:**

A pair of doubles representing the lesser and greater bounds. 





        

<hr>



### function calculate\_transform 

_Calculate the linear transformation parameters to map this domain to another domain._ 
```C++
const std::pair< double, double > falcon_core::math::domains::Domain::calculate_transform (
    const std::shared_ptr< Domain > & other
) const
```





**Parameters:**


* `other` The other domain to map to. 



**Returns:**

A pair of doubles representing the scale and offset of the transformation. 





        

<hr>



### function contains\_domain 

_Check if this domain completely contains another domain._ 
```C++
const bool falcon_core::math::domains::Domain::contains_domain (
    const std::shared_ptr< Domain > & other
) const
```





**Parameters:**


* `other` The other domain. 



**Returns:**

True if this domain contains the other domain, false otherwise. 





        

<hr>



### function get\_center 

_Get the center of the domain._ 
```C++
const double falcon_core::math::domains::Domain::get_center () const
```





**Returns:**

The center of the domain. 





        

<hr>



### function greater\_bound 

_Get the greater bound of the domain._ 
```C++
const double falcon_core::math::domains::Domain::greater_bound () const
```





**Returns:**

The greater bound. 





        

<hr>



### function greater\_bound\_contained 

_Check if the greater bound is contained in the domain._ 
```C++
const bool falcon_core::math::domains::Domain::greater_bound_contained () const
```





**Returns:**

True if the greater bound is contained, false otherwise. 





        

<hr>



### function in 

_Check if a value is in the domain._ 
```C++
const bool falcon_core::math::domains::Domain::in (
    double value
) const
```





**Parameters:**


* `value` The value to check. 



**Returns:**

True if the value is in the domain, false otherwise. 





        

<hr>



### function is\_empty 

_Check if the domain is empty._ 
```C++
const bool falcon_core::math::domains::Domain::is_empty () const
```





**Returns:**

True if the domain is empty, false otherwise. 





        

<hr>



### function lesser\_bound 

_Get the lesser bound of the domain._ 
```C++
const double falcon_core::math::domains::Domain::lesser_bound () const
```





**Returns:**

The lesser bound. 





        

<hr>



### function lesser\_bound\_contained 

_Check if the lesser bound is contained in the domain._ 
```C++
const bool falcon_core::math::domains::Domain::lesser_bound_contained () const
```





**Returns:**

True if the lesser bound is contained, false otherwise. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::math::domains::Domain::operator!= (
    const Domain & other
) const
```




<hr>



### function operator& 

_Get the intersection of this domain with another domain._ 
```C++
const std::shared_ptr< Domain > falcon_core::math::domains::Domain::operator& (
    const std::shared_ptr< Domain > & other
) const
```





**Parameters:**


* `other` The other domain. 



**Returns:**

A new domain representing the intersection. 




**Exception:**


* `std::runtime_error` if the domains do not intersect. 




        

<hr>



### function operator= 

```C++
Domain & falcon_core::math::domains::Domain::operator= (
    const Domain & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::domains::Domain::operator== (
    const Domain & other
) const
```




<hr>



### function operator\| 

_Get the union of this domain with another domain._ 
```C++
const std::shared_ptr< Domain > falcon_core::math::domains::Domain::operator| (
    const std::shared_ptr< Domain > & other
) const
```





**Parameters:**


* `other` The other domain. 



**Returns:**

A new domain representing the union. 




**Exception:**


* `std::runtime_error` if the domains do not overlap or touch. 




        

<hr>



### function range 

_Get the size of the domain._ 
```C++
const double falcon_core::math::domains::Domain::range () const
```





**Returns:**

The size of the domain. 





        

<hr>



### function scale 

_Scale the domain by a factor._ 
```C++
const std::shared_ptr< Domain > falcon_core::math::domains::Domain::scale (
    double factor
) const
```





**Parameters:**


* `factor` The factor to scale by. 



**Returns:**

A new domain representing the scaled domain. 





        

<hr>



### function shift 

_Shift the domain by an offset._ 
```C++
const std::shared_ptr< Domain > falcon_core::math::domains::Domain::shift (
    double offset
) const
```





**Parameters:**


* `offset` The offset to shift by. 



**Returns:**

A new domain representing the shifted domain. 





        

<hr>



### function transform 

_Transform a value from this domain to another domain._ 
```C++
const double falcon_core::math::domains::Domain::transform (
    const std::shared_ptr< Domain > & other,
    double value
) const
```





**Parameters:**


* `other` The other domain to transform to. 
* `value` The value to transform. 



**Returns:**

The transformed value. 





        

<hr>
## Protected Functions Documentation




### function Domain [4/4]

```C++
falcon_core::math::domains::Domain::Domain () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::domains::Domain::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::domains::Domain::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/domains/Domain.hpp`

