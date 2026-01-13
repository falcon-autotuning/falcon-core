

# Class falcon\_core::physics::units::Unit



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**units**](namespacefalcon__core_1_1physics_1_1units.md) **>** [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Unit**](#function-unit-12) (TotalDimensions dimensions, double scale\_factor=1.0, double offset=0.0, std::string prefix=SI::UNIT\_SYMBOL) <br> |
|  double | [**convert\_value\_to**](#function-convert_value_to) (const double value, const std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; & target\_unit) const<br>_Convert a value from this unit to a target unit._  |
|  TotalDimensions | [**dimensions**](#function-dimensions) () const<br>_Dimensions of this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_giga**](#function-get_giga) () const<br>_Apply a giga prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_kilo**](#function-get_kilo) () const<br>_Apply a kilo prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_mega**](#function-get_mega) () const<br>_Apply a mega prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_micro**](#function-get_micro) () const<br>_Apply a micro prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_milli**](#function-get_milli) () const<br>_Apply a milli prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_nano**](#function-get_nano) () const<br>_Apply a nano prefix to this unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**get\_pico**](#function-get_pico) () const<br>_Apply a pico prefix to this unit._  |
|  bool | [**is\_compatible\_with**](#function-is_compatible_with) (const std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; & other) const<br>_Check if this unit is compatible with another unit._  |
|  double | [**offset**](#function-offset) () const<br>_Offset from base unit._  |
|  bool | [**operator!=**](#function-operator) (const [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) & other) const<br> |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**operator\***](#function-operator_1) (const std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; & other) const<br>_Multiply this unit by another unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**operator/**](#function-operator_2) (const std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; & other) const<br>_Divide this unit by another unit._  |
|  bool | [**operator==**](#function-operator_3) (const [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) & other) const<br> |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**operator^**](#function-operator_4) (const int power) const<br>_Raise the unit to a power._  |
|  std::string | [**prefix**](#function-prefix) () const<br>_The prefix applied to this unit._  |
|  double | [**scale\_factor**](#function-scale_factor) () const<br>_Scale factor relatice to SI base units._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**with\_prefix**](#function-with_prefix) (const std::string prefix) const<br>_Apply a prefix to this unit._  |


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
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Ampere**](#function-ampere) () <br>_A special constructor to build a ampere unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Candela**](#function-candela) () <br>_A special constructor to build a candela unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Celsius**](#function-celsius) () <br>_A special constructor to build a celsius unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Coulomb**](#function-coulomb) () <br>_A special constructor to build a coulomb unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Dimensionless**](#function-dimensionless) () <br>_A special constructor to build a dimensionless unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**ElectronVolt**](#function-electronvolt) () <br>_A special constructor to build a electronvolt unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Fahrenheit**](#function-fahrenheit) () <br>_A special constructor to build a fahrenheit unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Farad**](#function-farad) () <br>_A special constructor to build a farad unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Henry**](#function-henry) () <br>_A special constructor to build a henry unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Hertz**](#function-hertz) () <br>_A special constructor to build a hertz unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Hour**](#function-hour) () <br>_A special constructor to build a hour unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Joule**](#function-joule) () <br>_A special constructor to build a joule unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Kelvin**](#function-kelvin) () <br>_A special constructor to build a kelvin unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Kilogram**](#function-kilogram) () <br>_A special constructor to build a kilogram unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Meter**](#function-meter) () <br>_A special constructor to build a meter unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Minute**](#function-minute) () <br>_A special constructor to build a minute unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Mole**](#function-mole) () <br>_A special constructor to build a mole unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Newton**](#function-newton) () <br>_A special constructor to build a newton unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Ohm**](#function-ohm) () <br>_A special constructor to build a ohm unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Pascal**](#function-pascal) () <br>_A special constructor to build a pascal unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Percent**](#function-percent) () <br>_A special constructor to build a percent unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Radian**](#function-radian) () <br>_A special constructor to build a radian unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Second**](#function-second) () <br>_A special constructor to build a second unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Siemens**](#function-siemens) () <br>_A special constructor to build a seimen unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Tesla**](#function-tesla) () <br>_A special constructor to build a tesla unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Volt**](#function-volt) () <br>_A special constructor to build a volt unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Watt**](#function-watt) () <br>_A special constructor to build a watt unit._  |
|  std::shared\_ptr&lt; [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) &gt; | [**Weber**](#function-weber) () <br>_A special constructor to build a weber unit._  |
|  void | [**clean\_dimensions**](#function-clean_dimensions) (TotalDimensions & dims) <br> |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Unit**](#function-unit-22) () = default<br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function Unit [1/2]

```C++
falcon_core::physics::units::Unit::Unit (
    TotalDimensions dimensions,
    double scale_factor=1.0,
    double offset=0.0,
    std::string prefix=SI::UNIT_SYMBOL
) 
```




<hr>



### function convert\_value\_to 

_Convert a value from this unit to a target unit._ 
```C++
double falcon_core::physics::units::Unit::convert_value_to (
    const double value,
    const std::shared_ptr< Unit > & target_unit
) const
```





**Parameters:**


* `value` The value in this unit to convert. 
* `target_unit` The unit to convert the value to. 



**Returns:**

The converted value in the target unit. 




**Exception:**


* `std::invalid_argument` if the units are not compatible. 




        

<hr>



### function dimensions 

_Dimensions of this unit._ 
```C++
TotalDimensions falcon_core::physics::units::Unit::dimensions () const
```




<hr>



### function get\_giga 

_Apply a giga prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_giga () const
```




<hr>



### function get\_kilo 

_Apply a kilo prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_kilo () const
```




<hr>



### function get\_mega 

_Apply a mega prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_mega () const
```




<hr>



### function get\_micro 

_Apply a micro prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_micro () const
```




<hr>



### function get\_milli 

_Apply a milli prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_milli () const
```




<hr>



### function get\_nano 

_Apply a nano prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_nano () const
```




<hr>



### function get\_pico 

_Apply a pico prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::get_pico () const
```




<hr>



### function is\_compatible\_with 

_Check if this unit is compatible with another unit._ 
```C++
bool falcon_core::physics::units::Unit::is_compatible_with (
    const std::shared_ptr< Unit > & other
) const
```





**Parameters:**


* `other` The unit to check compatibility with. 



**Returns:**

True if the units are compatible (same dimensions), false otherwise. 





        

<hr>



### function offset 

_Offset from base unit._ 
```C++
double falcon_core::physics::units::Unit::offset () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::physics::units::Unit::operator!= (
    const Unit & other
) const
```




<hr>



### function operator\* 

_Multiply this unit by another unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::operator* (
    const std::shared_ptr< Unit > & other
) const
```





**Parameters:**


* `other` The unit to multiply by. 



**Returns:**

A new [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) representing the product of this unit and the other. 





        

<hr>



### function operator/ 

_Divide this unit by another unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::operator/ (
    const std::shared_ptr< Unit > & other
) const
```





**Parameters:**


* `other` The unit to divide by. 



**Returns:**

A new [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) representing the division of this unit by the other. 





        

<hr>



### function operator== 

```C++
bool falcon_core::physics::units::Unit::operator== (
    const Unit & other
) const
```




<hr>



### function operator^ 

_Raise the unit to a power._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::operator^ (
    const int power
) const
```





**Parameters:**


* `power` The exponent to raise the unit to. 



**Returns:**

A new [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) raised to the specified power. 





        

<hr>



### function prefix 

_The prefix applied to this unit._ 
```C++
std::string falcon_core::physics::units::Unit::prefix () const
```




<hr>



### function scale\_factor 

_Scale factor relatice to SI base units._ 
```C++
double falcon_core::physics::units::Unit::scale_factor () const
```




<hr>



### function with\_prefix 

_Apply a prefix to this unit._ 
```C++
std::shared_ptr< Unit > falcon_core::physics::units::Unit::with_prefix (
    const std::string prefix
) const
```





**Parameters:**


* `prefix` The prefix symbol to apply (e.g. "k" for kilo 



**Returns:**

A new [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) with the specified prefix applied. 




**Exception:**


* `std::invalid_argument` if the prefix is not valid. 




        

<hr>
## Public Static Functions Documentation




### function Ampere 

_A special constructor to build a ampere unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Ampere () 
```




<hr>



### function Candela 

_A special constructor to build a candela unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Candela () 
```




<hr>



### function Celsius 

_A special constructor to build a celsius unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Celsius () 
```




<hr>



### function Coulomb 

_A special constructor to build a coulomb unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Coulomb () 
```




<hr>



### function Dimensionless 

_A special constructor to build a dimensionless unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Dimensionless () 
```




<hr>



### function ElectronVolt 

_A special constructor to build a electronvolt unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::ElectronVolt () 
```




<hr>



### function Fahrenheit 

_A special constructor to build a fahrenheit unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Fahrenheit () 
```




<hr>



### function Farad 

_A special constructor to build a farad unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Farad () 
```




<hr>



### function Henry 

_A special constructor to build a henry unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Henry () 
```




<hr>



### function Hertz 

_A special constructor to build a hertz unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Hertz () 
```




<hr>



### function Hour 

_A special constructor to build a hour unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Hour () 
```




<hr>



### function Joule 

_A special constructor to build a joule unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Joule () 
```




<hr>



### function Kelvin 

_A special constructor to build a kelvin unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Kelvin () 
```




<hr>



### function Kilogram 

_A special constructor to build a kilogram unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Kilogram () 
```




<hr>



### function Meter 

_A special constructor to build a meter unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Meter () 
```




<hr>



### function Minute 

_A special constructor to build a minute unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Minute () 
```




<hr>



### function Mole 

_A special constructor to build a mole unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Mole () 
```




<hr>



### function Newton 

_A special constructor to build a newton unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Newton () 
```




<hr>



### function Ohm 

_A special constructor to build a ohm unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Ohm () 
```




<hr>



### function Pascal 

_A special constructor to build a pascal unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Pascal () 
```




<hr>



### function Percent 

_A special constructor to build a percent unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Percent () 
```




<hr>



### function Radian 

_A special constructor to build a radian unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Radian () 
```




<hr>



### function Second 

_A special constructor to build a second unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Second () 
```




<hr>



### function Siemens 

_A special constructor to build a seimen unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Siemens () 
```




<hr>



### function Tesla 

_A special constructor to build a tesla unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Tesla () 
```




<hr>



### function Volt 

_A special constructor to build a volt unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Volt () 
```




<hr>



### function Watt 

_A special constructor to build a watt unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Watt () 
```




<hr>



### function Weber 

_A special constructor to build a weber unit._ 
```C++
static std::shared_ptr< Unit > falcon_core::physics::units::Unit::Weber () 
```




<hr>



### function clean\_dimensions 

```C++
static void falcon_core::physics::units::Unit::clean_dimensions (
    TotalDimensions & dims
) 
```




<hr>
## Protected Functions Documentation




### function Unit [2/2]

```C++
falcon_core::physics::units::Unit::Unit () = default
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::units::Unit::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::units::Unit::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/units/Unit.hpp`

