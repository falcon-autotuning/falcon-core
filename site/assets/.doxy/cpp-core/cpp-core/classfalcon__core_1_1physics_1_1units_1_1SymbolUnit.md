

# Class falcon\_core::physics::units::SymbolUnit



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**units**](namespacefalcon__core_1_1physics_1_1units.md) **>** [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SymbolUnit**](#function-symbolunit-13) (const SymbolUnit & other) <br> |
|   | [**SymbolUnit**](#function-symbolunit-23) (UnitSP unit) <br>_Construct a_ [_**SymbolUnit**_](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) _with a specific symbol and associated_[_**Unit**_](classfalcon__core_1_1physics_1_1units_1_1Unit.md) _._ |
|  const double | [**convert\_value\_to**](#function-convert_value_to) (const double value, const std::shared\_ptr&lt; SymbolUnit &gt; & target\_unit) const<br>_Convert a value from this symbol unit to a target symbol unit._  |
|  const std::map&lt; std::string, std::string &gt; | [**get\_dimension\_symbols**](#function-get_dimension_symbols) () const<br> |
|  const std::vector&lt; std::tuple&lt; UnitSP, const char \*, const char \* &gt; &gt; | [**get\_unit\_symbols**](#function-get_unit_symbols) () const<br> |
|  const bool | [**is\_compatible\_with**](#function-is_compatible_with) (const std::shared\_ptr&lt; SymbolUnit &gt; & other) const<br>_Check if this symbol unit is compatible with another symbol unit._  |
|  const std::string | [**name**](#function-name) () const<br>_Get the name of the unit._  |
|  bool | [**operator!=**](#function-operator) (const SymbolUnit & other) const<br> |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**operator\***](#function-operator_1) (const std::shared\_ptr&lt; SymbolUnit &gt; & other) const<br>_Multiply this symbol unit by another symbol unit._  |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**operator\***](#function-operator_2) (const UnitSP & other) const<br> |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**operator/**](#function-operator_3) (const std::shared\_ptr&lt; SymbolUnit &gt; & other) const<br>_Divide this symbol unit by another symbol unit._  |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**operator/**](#function-operator_4) (const UnitSP & other) const<br> |
|  SymbolUnit & | [**operator=**](#function-operator_5) (const SymbolUnit & other) <br> |
|  bool | [**operator==**](#function-operator_6) (const SymbolUnit & other) const<br> |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**operator^**](#function-operator_7) (const int power) const<br>_Raise the symbol unit to a power._  |
|  const std::string | [**symbol**](#function-symbol) () const<br>_Get the name of the unit._  |
|  const UnitSP | [**unit**](#function-unit) () const<br>_Get the symbol of the unit._  |
|  const std::shared\_ptr&lt; SymbolUnit &gt; | [**with\_prefix**](#function-with_prefix) (const std::string prefix) const<br>_Apply a prefix to this symbol unit._  |


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
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Ampere**](#function-ampere) () <br>_Construct an Ampere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**AmperesPerMeter**](#function-amperespermeter) () <br>_Construct an AmperesPerMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Candela**](#function-candela) () <br>_Construct a Candela._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Celsius**](#function-celsius) () <br>_Construct a Celsius._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Coulomb**](#function-coulomb) () <br>_Construct a Coulomb._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Dimensionless**](#function-dimensionless) () <br>_Construct a Dimensionless._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**ElectronVolt**](#function-electronvolt) () <br>_Construct an ElectronVolt._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Fahrenheit**](#function-fahrenheit) () <br>_Construct a Fahrenheit._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Farad**](#function-farad) () <br>_Construct a Farad._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**GigaHertz**](#function-gigahertz) () <br>_Construct a GigaHertz._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Henry**](#function-henry) () <br>_Construct a Henry._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Hertz**](#function-hertz) () <br>_Construct a Hertz._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Hour**](#function-hour) () <br>_Construct an Hour._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Joule**](#function-joule) () <br>_Construct a Joule._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Kelvin**](#function-kelvin) () <br>_Construct a Kelvin._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**KiloHertz**](#function-kilohertz) () <br>_Construct a KiloHertz._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**KiloMeter**](#function-kilometer) () <br>_Construct a KiloMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**KiloOhm**](#function-kiloohm) () <br>_Construct a KiloOhm._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**KiloVolt**](#function-kilovolt) () <br>_Construct a KiloVolt._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Kilogram**](#function-kilogram) () <br>_Construct a Kilogram._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MegaHertz**](#function-megahertz) () <br>_Construct a MegaHertz._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MegaOhm**](#function-megaohm) () <br>_Construct a MegaOhm._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Meter**](#function-meter) () <br>_Construct a Meter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MetersPerSecond**](#function-meterspersecond) () <br>_Construct a MetersPerSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MetersPerSecondSquared**](#function-meterspersecondsquared) () <br>_Construct a MetersPerSecondSquared._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MicroAmpere**](#function-microampere) () <br>_Construct a MicroAmpere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MicroSecond**](#function-microsecond) () <br>_Construct a MicroSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliAmpere**](#function-milliampere) () <br>_Construct a MilliAmpere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliHertz**](#function-millihertz) () <br>_Construct a MilliHertz._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliMeter**](#function-millimeter) () <br>_Construct a MilliMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliOhm**](#function-milliohm) () <br>_Construct a MilliOhm._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliSecond**](#function-millisecond) () <br>_Construct a MilliSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**MilliVolt**](#function-millivolt) () <br>_Construct a MilliVolt._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Minute**](#function-minute) () <br>_Construct a Minute._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Mole**](#function-mole) () <br>_Construct a Mole._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**NanoAmpere**](#function-nanoampere) () <br>_Construct a NanoAmpere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**NanoSecond**](#function-nanosecond) () <br>_Construct a NanoSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Newton**](#function-newton) () <br>_Construct a Newton._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**NewtonMeter**](#function-newtonmeter) () <br>_Construct a NewtonMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**NewtonPerMeter**](#function-newtonpermeter) () <br>_Construct a NewtonPerMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Ohm**](#function-ohm) () <br>_Construct an Ohm._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Pascal**](#function-pascal) () <br>_Construct a Pascal._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Percent**](#function-percent) () <br>_Construct a Percent._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**PicoAmpere**](#function-picoampere) () <br>_Construct a PicoAmpere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**PicoSecond**](#function-picosecond) () <br>_Construct a PicoSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Radian**](#function-radian) () <br>_Construct a Radian._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Second**](#function-second) () <br>_Construct a Second._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Siemens**](#function-siemens) () <br>_Construct a Seimens._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Tesla**](#function-tesla) () <br>_Construct a Tesla._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Volt**](#function-volt) () <br>_Construct a Volt._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**VoltsPerAmpere**](#function-voltsperampere) () <br>_Construct a VoltsPerAmpere._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**VoltsPerMeter**](#function-voltspermeter) () <br>_Construct a VoltsPerMeter._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**VoltsPerSecond**](#function-voltspersecond) () <br>_Construct a VoltsPerSecond._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Watt**](#function-watt) () <br>_Construct a Watt._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**WattsPerMeterKelvin**](#function-wattspermeterkelvin) () <br>_Construct a WattsPerMeterKelvin._  |
|  std::shared\_ptr&lt; SymbolUnit &gt; | [**Weber**](#function-weber) () <br>_Construct a Weber._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**SymbolUnit**](#function-symbolunit-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function SymbolUnit [1/3]

```C++
falcon_core::physics::units::SymbolUnit::SymbolUnit (
    const SymbolUnit & other
) 
```




<hr>



### function SymbolUnit [2/3]

_Construct a_ [_**SymbolUnit**_](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) _with a specific symbol and associated_[_**Unit**_](classfalcon__core_1_1physics_1_1units_1_1Unit.md) _._
```C++
falcon_core::physics::units::SymbolUnit::SymbolUnit (
    UnitSP unit
) 
```





**Parameters:**


* `unit` The [**Unit**](classfalcon__core_1_1physics_1_1units_1_1Unit.md) object associated with this symbol. 




        

<hr>



### function convert\_value\_to 

_Convert a value from this symbol unit to a target symbol unit._ 
```C++
const double falcon_core::physics::units::SymbolUnit::convert_value_to (
    const double value,
    const std::shared_ptr< SymbolUnit > & target_unit
) const
```





**Parameters:**


* `value` The value in this symbol unit to convert. 
* `target_unit` The symbol unit to convert the value to. 



**Returns:**

The converted value in the target symbol unit. 




**Exception:**


* `std::invalid_argument` if the units are not compatible. 




        

<hr>



### function get\_dimension\_symbols 

```C++
const std::map< std::string, std::string > falcon_core::physics::units::SymbolUnit::get_dimension_symbols () const
```




<hr>



### function get\_unit\_symbols 

```C++
const std::vector< std::tuple< UnitSP, const char *, const char * > > falcon_core::physics::units::SymbolUnit::get_unit_symbols () const
```




<hr>



### function is\_compatible\_with 

_Check if this symbol unit is compatible with another symbol unit._ 
```C++
const bool falcon_core::physics::units::SymbolUnit::is_compatible_with (
    const std::shared_ptr< SymbolUnit > & other
) const
```





**Parameters:**


* `other` The symbol unit to check compatibility with. 



**Returns:**

True if the symbol units are compatible (same dimensions), false otherwise. 





        

<hr>



### function name 

_Get the name of the unit._ 
```C++
const std::string falcon_core::physics::units::SymbolUnit::name () const
```





**Returns:**

The name as a string. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::units::SymbolUnit::operator!= (
    const SymbolUnit & other
) const
```




<hr>



### function operator\* 

_Multiply this symbol unit by another symbol unit._ 
```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::operator* (
    const std::shared_ptr< SymbolUnit > & other
) const
```





**Parameters:**


* `other` The symbol unit to multiply by. 



**Returns:**

A new [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) representing the product of this symbol unit and the other. 





        

<hr>



### function operator\* 

```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::operator* (
    const UnitSP & other
) const
```




<hr>



### function operator/ 

_Divide this symbol unit by another symbol unit._ 
```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::operator/ (
    const std::shared_ptr< SymbolUnit > & other
) const
```





**Parameters:**


* `other` The symbol unit to divide by. 



**Returns:**

A new [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) representing the division of this symbol unit by the other. 





        

<hr>



### function operator/ 

```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::operator/ (
    const UnitSP & other
) const
```




<hr>



### function operator= 

```C++
SymbolUnit & falcon_core::physics::units::SymbolUnit::operator= (
    const SymbolUnit & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::units::SymbolUnit::operator== (
    const SymbolUnit & other
) const
```




<hr>



### function operator^ 

_Raise the symbol unit to a power._ 
```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::operator^ (
    const int power
) const
```





**Parameters:**


* `power` The exponent to raise the symbol unit to. 



**Returns:**

A new [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) raised to the specified power. 





        

<hr>



### function symbol 

_Get the name of the unit._ 
```C++
const std::string falcon_core::physics::units::SymbolUnit::symbol () const
```





**Returns:**

The name as a string. 





        

<hr>



### function unit 

_Get the symbol of the unit._ 
```C++
const UnitSP falcon_core::physics::units::SymbolUnit::unit () const
```





**Returns:**

The symbol as a string. 





        

<hr>



### function with\_prefix 

_Apply a prefix to this symbol unit._ 
```C++
const std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::with_prefix (
    const std::string prefix
) const
```





**Parameters:**


* `prefix` The prefix symbol to apply (e.g. "k" for kilo 



**Returns:**

A new [**SymbolUnit**](classfalcon__core_1_1physics_1_1units_1_1SymbolUnit.md) with the specified prefix applied. 




**Exception:**


* `std::invalid_argument` if the prefix is not valid. 




        

<hr>
## Public Static Functions Documentation




### function Ampere 

_Construct an Ampere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Ampere () 
```




<hr>



### function AmperesPerMeter 

_Construct an AmperesPerMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::AmperesPerMeter () 
```




<hr>



### function Candela 

_Construct a Candela._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Candela () 
```




<hr>



### function Celsius 

_Construct a Celsius._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Celsius () 
```




<hr>



### function Coulomb 

_Construct a Coulomb._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Coulomb () 
```




<hr>



### function Dimensionless 

_Construct a Dimensionless._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Dimensionless () 
```




<hr>



### function ElectronVolt 

_Construct an ElectronVolt._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::ElectronVolt () 
```




<hr>



### function Fahrenheit 

_Construct a Fahrenheit._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Fahrenheit () 
```




<hr>



### function Farad 

_Construct a Farad._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Farad () 
```




<hr>



### function GigaHertz 

_Construct a GigaHertz._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::GigaHertz () 
```




<hr>



### function Henry 

_Construct a Henry._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Henry () 
```




<hr>



### function Hertz 

_Construct a Hertz._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Hertz () 
```




<hr>



### function Hour 

_Construct an Hour._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Hour () 
```




<hr>



### function Joule 

_Construct a Joule._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Joule () 
```




<hr>



### function Kelvin 

_Construct a Kelvin._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Kelvin () 
```




<hr>



### function KiloHertz 

_Construct a KiloHertz._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::KiloHertz () 
```




<hr>



### function KiloMeter 

_Construct a KiloMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::KiloMeter () 
```




<hr>



### function KiloOhm 

_Construct a KiloOhm._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::KiloOhm () 
```




<hr>



### function KiloVolt 

_Construct a KiloVolt._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::KiloVolt () 
```




<hr>



### function Kilogram 

_Construct a Kilogram._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Kilogram () 
```




<hr>



### function MegaHertz 

_Construct a MegaHertz._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MegaHertz () 
```




<hr>



### function MegaOhm 

_Construct a MegaOhm._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MegaOhm () 
```




<hr>



### function Meter 

_Construct a Meter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Meter () 
```




<hr>



### function MetersPerSecond 

_Construct a MetersPerSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MetersPerSecond () 
```




<hr>



### function MetersPerSecondSquared 

_Construct a MetersPerSecondSquared._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MetersPerSecondSquared () 
```




<hr>



### function MicroAmpere 

_Construct a MicroAmpere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MicroAmpere () 
```




<hr>



### function MicroSecond 

_Construct a MicroSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MicroSecond () 
```




<hr>



### function MilliAmpere 

_Construct a MilliAmpere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliAmpere () 
```




<hr>



### function MilliHertz 

_Construct a MilliHertz._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliHertz () 
```




<hr>



### function MilliMeter 

_Construct a MilliMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliMeter () 
```




<hr>



### function MilliOhm 

_Construct a MilliOhm._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliOhm () 
```




<hr>



### function MilliSecond 

_Construct a MilliSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliSecond () 
```




<hr>



### function MilliVolt 

_Construct a MilliVolt._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::MilliVolt () 
```




<hr>



### function Minute 

_Construct a Minute._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Minute () 
```




<hr>



### function Mole 

_Construct a Mole._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Mole () 
```




<hr>



### function NanoAmpere 

_Construct a NanoAmpere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::NanoAmpere () 
```




<hr>



### function NanoSecond 

_Construct a NanoSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::NanoSecond () 
```




<hr>



### function Newton 

_Construct a Newton._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Newton () 
```




<hr>



### function NewtonMeter 

_Construct a NewtonMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::NewtonMeter () 
```




<hr>



### function NewtonPerMeter 

_Construct a NewtonPerMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::NewtonPerMeter () 
```




<hr>



### function Ohm 

_Construct an Ohm._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Ohm () 
```




<hr>



### function Pascal 

_Construct a Pascal._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Pascal () 
```




<hr>



### function Percent 

_Construct a Percent._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Percent () 
```




<hr>



### function PicoAmpere 

_Construct a PicoAmpere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::PicoAmpere () 
```




<hr>



### function PicoSecond 

_Construct a PicoSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::PicoSecond () 
```




<hr>



### function Radian 

_Construct a Radian._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Radian () 
```




<hr>



### function Second 

_Construct a Second._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Second () 
```




<hr>



### function Siemens 

_Construct a Seimens._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Siemens () 
```




<hr>



### function Tesla 

_Construct a Tesla._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Tesla () 
```




<hr>



### function Volt 

_Construct a Volt._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Volt () 
```




<hr>



### function VoltsPerAmpere 

_Construct a VoltsPerAmpere._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::VoltsPerAmpere () 
```




<hr>



### function VoltsPerMeter 

_Construct a VoltsPerMeter._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::VoltsPerMeter () 
```




<hr>



### function VoltsPerSecond 

_Construct a VoltsPerSecond._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::VoltsPerSecond () 
```




<hr>



### function Watt 

_Construct a Watt._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Watt () 
```




<hr>



### function WattsPerMeterKelvin 

_Construct a WattsPerMeterKelvin._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::WattsPerMeterKelvin () 
```




<hr>



### function Weber 

_Construct a Weber._ 
```C++
static std::shared_ptr< SymbolUnit > falcon_core::physics::units::SymbolUnit::Weber () 
```




<hr>
## Protected Functions Documentation




### function SymbolUnit [3/3]

```C++
falcon_core::physics::units::SymbolUnit::SymbolUnit () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::units::SymbolUnit::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::units::SymbolUnit::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/units/SymbolUnit.hpp`

