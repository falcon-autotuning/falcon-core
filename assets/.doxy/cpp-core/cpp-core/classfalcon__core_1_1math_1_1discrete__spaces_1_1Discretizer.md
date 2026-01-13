

# Class falcon\_core::math::discrete\_spaces::Discretizer



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**discrete\_spaces**](namespacefalcon__core_1_1math_1_1discrete__spaces.md) **>** [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md)



_Abstract base class for discretizers._ [More...](#detailed-description)

* `#include <Discretizer.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Discretizer**](#function-discretizer-13) (const [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) & other) <br> |
|   | [**Discretizer**](#function-discretizer-23) (const double & delta, const domains::DomainSP & delta\_domain, const Dividers & type) <br>_Construct a_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _. The delta must be within the delta\_domain._ |
|  double | [**delta**](#function-delta) () const<br> |
|  const domains::DomainSP & | [**domain**](#function-domain) () const<br> |
|  const bool | [**is\_cartesian**](#function-is_cartesian) () const<br>_Checks if the current_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _is Cartesian._ |
|  const bool | [**is\_polar**](#function-is_polar) () const<br>_Checks if the current_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _is Polar._ |
|  bool | [**operator!=**](#function-operator) (const [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) & other) const<br> |
|  [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) & | [**operator=**](#function-operator_1) (const [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) & other) const<br> |
|  void | [**set\_delta**](#function-set_delta) (double delta) <br> |


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
|  std::shared\_ptr&lt; [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) &gt; | [**CartesianDiscretizer**](#function-cartesiandiscretizer) (const double & delta) <br>_Constructs a CartesianDiscretizer for Cartesian square axes._  |
|  std::shared\_ptr&lt; [**Discretizer**](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) &gt; | [**PolarDiscretizer**](#function-polardiscretizer) (const double & delta) <br>_Construct a PolarDiscretizer for polar angled coordinates._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Discretizer**](#function-discretizer-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Detailed Description


Discretizers define how a domain is divided into discrete steps. 


    
## Public Functions Documentation




### function Discretizer [1/3]

```C++
falcon_core::math::discrete_spaces::Discretizer::Discretizer (
    const Discretizer & other
) 
```




<hr>



### function Discretizer [2/3]

_Construct a_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _. The delta must be within the delta\_domain._
```C++
falcon_core::math::discrete_spaces::Discretizer::Discretizer (
    const double & delta,
    const domains::DomainSP & delta_domain,
    const Dividers & type
) 
```





**Parameters:**


* `delta` Step size. 
* `delta_domain` Domain for step size. 
* `type` the type of Dividers to construct. 




        

<hr>



### function delta 

```C++
double falcon_core::math::discrete_spaces::Discretizer::delta () const
```




<hr>



### function domain 

```C++
const domains::DomainSP & falcon_core::math::discrete_spaces::Discretizer::domain () const
```




<hr>



### function is\_cartesian 

_Checks if the current_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _is Cartesian._
```C++
const bool falcon_core::math::discrete_spaces::Discretizer::is_cartesian () const
```




<hr>



### function is\_polar 

_Checks if the current_ [_**Discretizer**_](classfalcon__core_1_1math_1_1discrete__spaces_1_1Discretizer.md) _is Polar._
```C++
const bool falcon_core::math::discrete_spaces::Discretizer::is_polar () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::math::discrete_spaces::Discretizer::operator!= (
    const Discretizer & other
) const
```




<hr>



### function operator= 

```C++
Discretizer & falcon_core::math::discrete_spaces::Discretizer::operator= (
    const Discretizer & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::discrete_spaces::Discretizer::operator== (
    const Discretizer & other
) const
```




<hr>



### function set\_delta 

```C++
void falcon_core::math::discrete_spaces::Discretizer::set_delta (
    double delta
) 
```




<hr>
## Public Static Functions Documentation




### function CartesianDiscretizer 

_Constructs a CartesianDiscretizer for Cartesian square axes._ 
```C++
static std::shared_ptr< Discretizer > falcon_core::math::discrete_spaces::Discretizer::CartesianDiscretizer (
    const double & delta
) 
```




<hr>



### function PolarDiscretizer 

_Construct a PolarDiscretizer for polar angled coordinates._ 
```C++
static std::shared_ptr< Discretizer > falcon_core::math::discrete_spaces::Discretizer::PolarDiscretizer (
    const double & delta
) 
```




<hr>
## Protected Functions Documentation




### function Discretizer [3/3]

```C++
falcon_core::math::discrete_spaces::Discretizer::Discretizer () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::discrete_spaces::Discretizer::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::discrete_spaces::Discretizer::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/discrete_spaces/Discretizer.hpp`

