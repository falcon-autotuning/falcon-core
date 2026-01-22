

# Class falcon\_core::math::UnitSpace



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**UnitSpace**](classfalcon__core_1_1math_1_1UnitSpace.md)



_Respresents a hypercube of measurement space. It is defined by a set of axes, each of which can be discretized._ [More...](#detailed-description)

* `#include <UnitSpace.hpp>`



Inherits the following classes: [falcon\_core::math::Axes](classfalcon__core_1_1math_1_1Axes.md)


















## Public Types inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
| typedef typename Container::const\_iterator | [**const\_iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-const_iterator)  <br> |
| typedef typename Container::iterator | [**iterator**](classfalcon__core_1_1generic_1_1List.md#typedef-iterator)  <br> |












































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**UnitSpace**](#function-unitspace-13) (const UnitSpace & other) <br> |
|   | [**UnitSpace**](#function-unitspace-23) (const AxesSP&lt; [**discrete\_spaces::Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) &gt; & axes, const domains::DomainSP & domain) <br>_Initialize a_ [_**UnitSpace**_](classfalcon__core_1_1math_1_1UnitSpace.md) _._ |
|  const AxesSP&lt; [**discrete\_spaces::Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) &gt; | [**axes**](#function-axes) () const<br>_Return the axes of the space._  |
|  void | [**compile**](#function-compile) () <br>_Compile the unit space into a space._  |
|  const AxesSP&lt; [**arrays::ControlArray**](classfalcon__core_1_1math_1_1arrays_1_1ControlArray.md) &gt; | [**create\_array**](#function-create_array) (const AxesSP&lt; int &gt; & axes) const<br>_Return the projection of the space onto the given axes. The projection contains the indexes of the axes to project onto._  |
|  const int | [**dimension**](#function-dimension) () const<br>_Return the number of dimensions in the space._  |
|  const domains::DomainSP & | [**domain**](#function-domain) () const<br>_Return the domain of the space._  |
|  bool | [**operator!=**](#function-operator) (const UnitSpace & other) const<br> |
|  UnitSpace & | [**operator=**](#function-operator_1) (const UnitSpace & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const UnitSpace & other) const<br> |
|  const generic::ListSP&lt; int &gt; | [**shape**](#function-shape) () const<br>_Return the shape of the unit space._  |
|  const generic::FArraySP&lt; double &gt; & | [**space**](#function-space) () const<br>_Return the stored space._  |


## Public Functions inherited from falcon_core::math::Axes

See [falcon\_core::math::Axes](classfalcon__core_1_1math_1_1Axes.md)

| Type | Name |
| ---: | :--- |
|   | [**Axes**](classfalcon__core_1_1math_1_1Axes.md#function-axes-13) () = default<br> |
|   | [**Axes**](classfalcon__core_1_1math_1_1Axes.md#function-axes-23) (const typename [**generic::List**](classfalcon__core_1_1generic_1_1List.md)&lt; Value &gt;::Container & items) <br>_Construct_ [_**Axes**_](classfalcon__core_1_1math_1_1Axes.md) _from a vector of items._ |
|   | [**Axes**](classfalcon__core_1_1math_1_1Axes.md#function-axes-33) (const generic::ListSP&lt; Value &gt; & items) <br>_Construct_ [_**Axes**_](classfalcon__core_1_1math_1_1Axes.md) _from a vector of items._ |
|  bool | [**operator!=**](classfalcon__core_1_1math_1_1Axes.md#function-operator) (const Axes&lt; Value &gt; & other) const<br> |
|  bool | [**operator==**](classfalcon__core_1_1math_1_1Axes.md#function-operator_1) (const Axes&lt; Value &gt; & other) const<br> |


## Public Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-16) (const List&lt; Value &gt; & other) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-26) (iterator begin, iterator end) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-36) () <br>[_**List**_](classfalcon__core_1_1generic_1_1List.md) _can be constructed in 5 different ways:_ |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-46) (size\_t count) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-56) (size\_t count, const StoredValue & value) <br> |
|   | [**List**](classfalcon__core_1_1generic_1_1List.md#function-list-66) (const Container & init) <br> |
|  std::conditional\_t&lt; std::is\_same&lt; typename [**category::determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)&lt; Value &gt;::type, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) &gt;::value, StoredValue, const StoredValue & &gt; | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-12) (const size\_t idx) const<br> |
|  std::conditional\_t&lt; std::is\_same&lt; typename [**category::determine\_bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1determine__bool__tag.md)&lt; Value &gt;::type, [**category::bool\_tag**](structfalcon__core_1_1generic_1_1category_1_1bool__tag.md) &gt;::value, StoredValue, StoredValue & &gt; | [**at**](classfalcon__core_1_1generic_1_1List.md#function-at-22) (const size\_t idx) <br> |
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
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**intersection**](classfalcon__core_1_1generic_1_1List.md#function-intersection) (const std::shared\_ptr&lt; List&lt; Value &gt; &gt; & other) const<br>_Finds the intersection between this list and another._  |
|  const Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-12) () const<br> |
|  Container | [**items**](classfalcon__core_1_1generic_1_1List.md#function-items-22) () <br> |
|  bool | [**operator!=**](classfalcon__core_1_1generic_1_1List.md#function-operator) (const List&lt; Value &gt; & other) const<br> |
|  List | [**operator=**](classfalcon__core_1_1generic_1_1List.md#function-operator_1) (const List&lt; Value &gt; & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1generic_1_1List.md#function-operator_2) (const List&lt; Value &gt; & other) const<br> |
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
|  std::shared\_ptr&lt; UnitSpace &gt; | [**Cartesian1DSpace**](#function-cartesian1dspace) (const double & delta, const domains::DomainSP & domain) <br>_Create a 1D cartesian space._  |
|  std::shared\_ptr&lt; UnitSpace &gt; | [**Cartesian2DSpace**](#function-cartesian2dspace) (const AxesSP&lt; double &gt; & deltas, const domains::DomainSP & domain) <br>_Create a 2D cartesian space._  |
|  std::shared\_ptr&lt; UnitSpace &gt; | [**CartesianSpace**](#function-cartesianspace) (const AxesSP&lt; double &gt; & deltas, const domains::DomainSP & domain) <br>_Create a ND cartesian space._  |
|  std::shared\_ptr&lt; UnitSpace &gt; | [**RaySpace**](#function-rayspace) (const double & dr, const double & dtheta, const domains::DomainSP & domain) <br>_Create a ray space with radial and angular discretization._  |




## Public Static Functions inherited from falcon_core::generic::List

See [falcon\_core::generic::List](classfalcon__core_1_1generic_1_1List.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**allocate**](classfalcon__core_1_1generic_1_1List.md#function-allocate) (size\_t count) <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**create**](classfalcon__core_1_1generic_1_1List.md#function-create) (const Container & init) <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**create\_empty**](classfalcon__core_1_1generic_1_1List.md#function-create_empty) () <br> |
|  std::shared\_ptr&lt; List&lt; Value &gt; &gt; | [**fill\_value**](classfalcon__core_1_1generic_1_1List.md#function-fill_value) (size\_t count, const StoredValue & value) <br> |


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












































































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**UnitSpace**](#function-unitspace-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::math::Axes

See [falcon\_core::math::Axes](classfalcon__core_1_1math_1_1Axes.md)

| Type | Name |
| ---: | :--- |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1math_1_1Axes.md#function-operator_equal_impl-13) (const Axes&lt; Value &gt; & other, [**generic::category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1math_1_1Axes.md#function-operator_equal_impl-23) (const Axes&lt; Value &gt; & other, [**generic::category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1math_1_1Axes.md#function-operator_equal_impl-33) (const Axes&lt; Value &gt; & other, [**generic::category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |


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
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-13) (const List&lt; Value &gt; & other, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-23) (const List&lt; Value &gt; & other, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) const<br> |
|  bool | [**operator\_equal\_impl**](classfalcon__core_1_1generic_1_1List.md#function-operator_equal_impl-33) (const List&lt; Value &gt; & other, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) const<br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-13) (const std::shared\_ptr&lt; T &gt; & item, [**category::song\_tag**](structfalcon__core_1_1generic_1_1category_1_1song__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-23) (const T & item, [**category::primitive\_tag**](structfalcon__core_1_1generic_1_1category_1_1primitive__tag.md)) <br> |
|  void | [**push\_back\_impl**](classfalcon__core_1_1generic_1_1List.md#function-push_back_impl-33) (const T & item, [**category::other\_tag**](structfalcon__core_1_1generic_1_1category_1_1other__tag.md)) <br> |












## Detailed Description


This space can be compiled and packed into the space when necessary.


[**UnitSpace**](classfalcon__core_1_1math_1_1UnitSpace.md) is the base class for spaces with axes and a domain. 


    
## Public Functions Documentation




### function UnitSpace [1/3]

```C++
falcon_core::math::UnitSpace::UnitSpace (
    const UnitSpace & other
) 
```




<hr>



### function UnitSpace [2/3]

_Initialize a_ [_**UnitSpace**_](classfalcon__core_1_1math_1_1UnitSpace.md) _._
```C++
falcon_core::math::UnitSpace::UnitSpace (
    const AxesSP< discrete_spaces::Discretizer > & axes,
    const domains::DomainSP & domain
) 
```





**Parameters:**


* `axes` The axes defining the space. 
* `domain` The domain of the space. 




        

<hr>



### function axes 

_Return the axes of the space._ 
```C++
const AxesSP< discrete_spaces::Discretizer > falcon_core::math::UnitSpace::axes () const
```




<hr>



### function compile 

_Compile the unit space into a space._ 
```C++
void falcon_core::math::UnitSpace::compile () 
```




<hr>



### function create\_array 

_Return the projection of the space onto the given axes. The projection contains the indexes of the axes to project onto._ 
```C++
const AxesSP< arrays::ControlArray > falcon_core::math::UnitSpace::create_array (
    const AxesSP< int > & axes
) const
```





**Parameters:**


* `axes` The axes to project onto. 



**Returns:**

A set of proper Control Arrays 





        

<hr>



### function dimension 

_Return the number of dimensions in the space._ 
```C++
const int falcon_core::math::UnitSpace::dimension () const
```




<hr>



### function domain 

_Return the domain of the space._ 
```C++
const domains::DomainSP & falcon_core::math::UnitSpace::domain () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::UnitSpace::operator!= (
    const UnitSpace & other
) const
```




<hr>



### function operator= 

```C++
UnitSpace & falcon_core::math::UnitSpace::operator= (
    const UnitSpace & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::UnitSpace::operator== (
    const UnitSpace & other
) const
```




<hr>



### function shape 

_Return the shape of the unit space._ 
```C++
const generic::ListSP< int > falcon_core::math::UnitSpace::shape () const
```




<hr>



### function space 

_Return the stored space._ 
```C++
const generic::FArraySP< double > & falcon_core::math::UnitSpace::space () const
```




<hr>
## Public Static Functions Documentation




### function Cartesian1DSpace 

_Create a 1D cartesian space._ 
```C++
static std::shared_ptr< UnitSpace > falcon_core::math::UnitSpace::Cartesian1DSpace (
    const double & delta,
    const domains::DomainSP & domain
) 
```





**Parameters:**


* `delta` The discretization for the main axis. 
* `domain` The domain of the space. 




        

<hr>



### function Cartesian2DSpace 

_Create a 2D cartesian space._ 
```C++
static std::shared_ptr< UnitSpace > falcon_core::math::UnitSpace::Cartesian2DSpace (
    const AxesSP< double > & deltas,
    const domains::DomainSP & domain
) 
```





**Parameters:**


* `deltas` The discretizations for each axis. 
* `domain` The domain of the space. 




        

<hr>



### function CartesianSpace 

_Create a ND cartesian space._ 
```C++
static std::shared_ptr< UnitSpace > falcon_core::math::UnitSpace::CartesianSpace (
    const AxesSP< double > & deltas,
    const domains::DomainSP & domain
) 
```





**Parameters:**


* `deltas` The discretizations for each axis. 
* `domain` The domain of the space. 




        

<hr>



### function RaySpace 

_Create a ray space with radial and angular discretization._ 
```C++
static std::shared_ptr< UnitSpace > falcon_core::math::UnitSpace::RaySpace (
    const double & dr,
    const double & dtheta,
    const domains::DomainSP & domain
) 
```





**Parameters:**


* `dr` the radial delta. 
* `dtheta` the angular delta. 
* `domain` The domain of the space. 




        

<hr>
## Protected Functions Documentation




### function UnitSpace [3/3]

```C++
falcon_core::math::UnitSpace::UnitSpace () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::UnitSpace::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::UnitSpace::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/UnitSpace.hpp`

