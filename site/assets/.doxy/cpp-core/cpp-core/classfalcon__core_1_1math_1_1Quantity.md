

# Class falcon\_core::math::Quantity



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**math**](namespacefalcon__core_1_1math.md) **>** [**Quantity**](classfalcon__core_1_1math_1_1Quantity.md)



_Represents a physical quantity with a value and unit._ [More...](#detailed-description)

* `#include <Quantity.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::communications::voltage\_states::DeviceVoltageState](classfalcon__core_1_1communications_1_1voltage__states_1_1DeviceVoltageState.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Quantity**](#function-quantity-13) (const Quantity & other) <br> |
|   | [**Quantity**](#function-quantity-23) (double value, physics::units::SymbolUnitSP unit=[**physics::units::SymbolUnit::Volt**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md#function-volt)()) <br>_Initialize a_ [_**Quantity**_](classfalcon__core_1_1math_1_1Quantity.md) _, which is a float with a unit._ |
|  std::shared\_ptr&lt; Quantity &gt; | [**abs**](#function-abs) () const<br> |
|  void | [**convert\_to**](#function-convert_to) (physics::units::SymbolUnitSP target\_unit) <br>_Convert the quantity to a different unit._  |
|  bool | [**operator!=**](#function-operator) (const Quantity & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](#function-operator_1) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](#function-operator_2) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator\***](#function-operator_3) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator\*=**](#function-operator_4) (const int & other) <br> |
|  Quantity & | [**operator\*=**](#function-operator_5) (const double & other) <br> |
|  Quantity & | [**operator\*=**](#function-operator_6) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](#function-operator_7) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](#function-operator_8) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator+**](#function-operator_9) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator+=**](#function-operator_10) (const int & other) <br> |
|  Quantity & | [**operator+=**](#function-operator_11) (const double & other) <br> |
|  Quantity & | [**operator+=**](#function-operator_12) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](#function-operator-) () const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](#function-operator-_1) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](#function-operator-_2) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator-**](#function-operator-_3) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator-=**](#function-operator-_4) (const int & other) <br> |
|  Quantity & | [**operator-=**](#function-operator-_5) (const double & other) <br> |
|  Quantity & | [**operator-=**](#function-operator-_6) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](#function-operator_13) (const int & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](#function-operator_14) (const double & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator/**](#function-operator_15) (const std::shared\_ptr&lt; Quantity &gt; & other) const<br> |
|  Quantity & | [**operator/=**](#function-operator_16) (const int & other) <br> |
|  Quantity & | [**operator/=**](#function-operator_17) (const double & other) <br> |
|  Quantity & | [**operator/=**](#function-operator_18) (const std::shared\_ptr&lt; Quantity &gt; & other) <br> |
|  Quantity & | [**operator=**](#function-operator_19) (const Quantity & other) <br> |
|  bool | [**operator==**](#function-operator_20) (const Quantity & other) const<br> |
|  std::shared\_ptr&lt; Quantity &gt; | [**operator^**](#function-operator_21) (const int & other) const<br> |
|  physics::units::SymbolUnitSP | [**unit**](#function-unit) () const<br>_Return the unit of the quantity._  |
|  double | [**value**](#function-value) () const<br>_Return the value of the quantity._  |


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
|   | [**Quantity**](#function-quantity-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Detailed Description


Supports arithmetic operations and unit conversion. 


    
## Public Functions Documentation




### function Quantity [1/3]

```C++
falcon_core::math::Quantity::Quantity (
    const Quantity & other
) 
```




<hr>



### function Quantity [2/3]

_Initialize a_ [_**Quantity**_](classfalcon__core_1_1math_1_1Quantity.md) _, which is a float with a unit._
```C++
falcon_core::math::Quantity::Quantity (
    double value,
    physics::units::SymbolUnitSP unit=physics::units::SymbolUnit::Volt ()
) 
```





**Parameters:**


* `value` the value of the quantity. 
* `unit` the unit of the quantity. 




        

<hr>



### function abs 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::abs () const
```




<hr>



### function convert\_to 

_Convert the quantity to a different unit._ 
```C++
void falcon_core::math::Quantity::convert_to (
    physics::units::SymbolUnitSP target_unit
) 
```





**Parameters:**


* `target_unit` the raget unit to convert to. 




        

<hr>



### function operator!= 

```C++
bool falcon_core::math::Quantity::operator!= (
    const Quantity & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator* (
    const int & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator* (
    const double & other
) const
```




<hr>



### function operator\* 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator* (
    const std::shared_ptr< Quantity > & other
) const
```




<hr>



### function operator\*= 

```C++
Quantity & falcon_core::math::Quantity::operator*= (
    const int & other
) 
```




<hr>



### function operator\*= 

```C++
Quantity & falcon_core::math::Quantity::operator*= (
    const double & other
) 
```




<hr>



### function operator\*= 

```C++
Quantity & falcon_core::math::Quantity::operator*= (
    const std::shared_ptr< Quantity > & other
) 
```




<hr>



### function operator+ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator+ (
    const int & other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator+ (
    const double & other
) const
```




<hr>



### function operator+ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator+ (
    const std::shared_ptr< Quantity > & other
) const
```




<hr>



### function operator+= 

```C++
Quantity & falcon_core::math::Quantity::operator+= (
    const int & other
) 
```




<hr>



### function operator+= 

```C++
Quantity & falcon_core::math::Quantity::operator+= (
    const double & other
) 
```




<hr>



### function operator+= 

```C++
Quantity & falcon_core::math::Quantity::operator+= (
    const std::shared_ptr< Quantity > & other
) 
```




<hr>



### function operator- 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator- () const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator- (
    const int & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator- (
    const double & other
) const
```




<hr>



### function operator- 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator- (
    const std::shared_ptr< Quantity > & other
) const
```




<hr>



### function operator-= 

```C++
Quantity & falcon_core::math::Quantity::operator-= (
    const int & other
) 
```




<hr>



### function operator-= 

```C++
Quantity & falcon_core::math::Quantity::operator-= (
    const double & other
) 
```




<hr>



### function operator-= 

```C++
Quantity & falcon_core::math::Quantity::operator-= (
    const std::shared_ptr< Quantity > & other
) 
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator/ (
    const int & other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator/ (
    const double & other
) const
```




<hr>



### function operator/ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator/ (
    const std::shared_ptr< Quantity > & other
) const
```




<hr>



### function operator/= 

```C++
Quantity & falcon_core::math::Quantity::operator/= (
    const int & other
) 
```




<hr>



### function operator/= 

```C++
Quantity & falcon_core::math::Quantity::operator/= (
    const double & other
) 
```




<hr>



### function operator/= 

```C++
Quantity & falcon_core::math::Quantity::operator/= (
    const std::shared_ptr< Quantity > & other
) 
```




<hr>



### function operator= 

```C++
Quantity & falcon_core::math::Quantity::operator= (
    const Quantity & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::math::Quantity::operator== (
    const Quantity & other
) const
```




<hr>



### function operator^ 

```C++
std::shared_ptr< Quantity > falcon_core::math::Quantity::operator^ (
    const int & other
) const
```




<hr>



### function unit 

_Return the unit of the quantity._ 
```C++
physics::units::SymbolUnitSP falcon_core::math::Quantity::unit () const
```




<hr>



### function value 

_Return the value of the quantity._ 
```C++
double falcon_core::math::Quantity::value () const
```




<hr>
## Protected Functions Documentation




### function Quantity [3/3]

```C++
falcon_core::math::Quantity::Quantity () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::math::Quantity::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::math::Quantity::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/math/Quantity.hpp`

