

# File SymbolUnit\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**units**](dir_819f82495bddee121ceebbf28911313c.md) **>** [**SymbolUnit\_c\_api.h**](SymbolUnit__c__api_8h.md)

[Go to the source code of this file](SymbolUnit__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**SymbolUnitHandle**](#typedef-symbolunithandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**SymbolUnit\_convert\_value\_to**](#function-symbolunit_convert_value_to) (SymbolUnitHandle handle, double value, SymbolUnitHandle target) <br>_Convert a value from this symbol unit to a target symbol unit._  |
|  SymbolUnitHandle | [**SymbolUnit\_copy**](#function-symbolunit_copy) (SymbolUnitHandle handle) <br> |
|  SymbolUnitHandle | [**SymbolUnit\_create\_ampere**](#function-symbolunit_create_ampere) () <br>_Construct an Ampere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_amperes\_per\_meter**](#function-symbolunit_create_amperes_per_meter) () <br>_Construct an AmperesPerMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_candela**](#function-symbolunit_create_candela) () <br>_Construct a Candela._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_celsius**](#function-symbolunit_create_celsius) () <br>_Construct a Celsius._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_coulomb**](#function-symbolunit_create_coulomb) () <br>_Construct a Coulomb._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_dimensionless**](#function-symbolunit_create_dimensionless) () <br>_Construct a Dimensionless._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_electronvolt**](#function-symbolunit_create_electronvolt) () <br>_Construct an ElectronVolt._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_fahrenheit**](#function-symbolunit_create_fahrenheit) () <br>_Construct a Fahrenheit._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_farad**](#function-symbolunit_create_farad) () <br>_Construct a Farad._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_gigahertz**](#function-symbolunit_create_gigahertz) () <br>_Construct a GigaHertz._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_henry**](#function-symbolunit_create_henry) () <br>_Construct a Henry._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_hertz**](#function-symbolunit_create_hertz) () <br>_Construct a Hertz._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_hour**](#function-symbolunit_create_hour) () <br>_Construct an Hour._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_joule**](#function-symbolunit_create_joule) () <br>_Construct a Joule._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kelvin**](#function-symbolunit_create_kelvin) () <br>_Construct a Kelvin._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kilogram**](#function-symbolunit_create_kilogram) () <br>_Construct a Kilogram._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kilohertz**](#function-symbolunit_create_kilohertz) () <br>_Construct a KiloHertz._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kilometer**](#function-symbolunit_create_kilometer) () <br>_Construct a KiloMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kiloohm**](#function-symbolunit_create_kiloohm) () <br>_Construct a KiloOhm._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_kilovolt**](#function-symbolunit_create_kilovolt) () <br>_Construct a KiloVolt._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_megahertz**](#function-symbolunit_create_megahertz) () <br>_Construct a MegaHertz._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_megaohm**](#function-symbolunit_create_megaohm) () <br>_Construct a MegaOhm._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_meter**](#function-symbolunit_create_meter) () <br>_Construct a Meter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_meters\_per\_second**](#function-symbolunit_create_meters_per_second) () <br>_Construct a MetersPerSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_meters\_per\_second\_squared**](#function-symbolunit_create_meters_per_second_squared) () <br>_Construct a MetersPerSecondSquared._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_microampere**](#function-symbolunit_create_microampere) () <br>_Construct a MicroAmpere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_microsecond**](#function-symbolunit_create_microsecond) () <br>_Construct a MicroSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_milliampere**](#function-symbolunit_create_milliampere) () <br>_Construct a MilliAmpere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_millihertz**](#function-symbolunit_create_millihertz) () <br>_Construct a MilliHertz._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_millimeter**](#function-symbolunit_create_millimeter) () <br>_Construct a MilliMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_milliohm**](#function-symbolunit_create_milliohm) () <br>_Construct a MilliOhm._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_millisecond**](#function-symbolunit_create_millisecond) () <br>_Construct a MilliSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_millivolt**](#function-symbolunit_create_millivolt) () <br>_Construct a MilliVolt._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_minute**](#function-symbolunit_create_minute) () <br>_Construct a Minute._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_mole**](#function-symbolunit_create_mole) () <br>_Construct a Mole._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_nanoampere**](#function-symbolunit_create_nanoampere) () <br>_Construct a NanoAmpere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_nanosecond**](#function-symbolunit_create_nanosecond) () <br>_Construct a NanoSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_newton**](#function-symbolunit_create_newton) () <br>_Construct a Newton._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_newton\_meter**](#function-symbolunit_create_newton_meter) () <br>_Construct a NewtonMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_newtons\_per\_meter**](#function-symbolunit_create_newtons_per_meter) () <br>_Construct a NewtonPerMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_ohm**](#function-symbolunit_create_ohm) () <br>_Construct an Ohm._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_pascal**](#function-symbolunit_create_pascal) () <br>_Construct a Pascal._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_percent**](#function-symbolunit_create_percent) () <br>_Construct a Percent._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_picoampere**](#function-symbolunit_create_picoampere) () <br>_Construct a PicoAmpere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_picosecond**](#function-symbolunit_create_picosecond) () <br>_Construct a PicoSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_radian**](#function-symbolunit_create_radian) () <br>_Construct a Radian._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_second**](#function-symbolunit_create_second) () <br>_Construct a Second._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_siemens**](#function-symbolunit_create_siemens) () <br>_Construct a Seimens._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_tesla**](#function-symbolunit_create_tesla) () <br>_Construct a Tesla._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_volt**](#function-symbolunit_create_volt) () <br>_Construct a Volt._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_volts\_per\_ampere**](#function-symbolunit_create_volts_per_ampere) () <br>_Construct a VoltsPerAmpere._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_volts\_per\_meter**](#function-symbolunit_create_volts_per_meter) () <br>_Construct a VoltsPerMeter._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_volts\_per\_second**](#function-symbolunit_create_volts_per_second) () <br>_Construct a VoltsPerSecond._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_watt**](#function-symbolunit_create_watt) () <br>_Construct a Watt._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_watts\_per\_meter\_kelvin**](#function-symbolunit_create_watts_per_meter_kelvin) () <br>_Construct a WattsPerMeterKelvin._  |
|  SymbolUnitHandle | [**SymbolUnit\_create\_weber**](#function-symbolunit_create_weber) () <br>_Construct a Weber._  |
|  void | [**SymbolUnit\_destroy**](#function-symbolunit_destroy) (SymbolUnitHandle handle) <br> |
|  SymbolUnitHandle | [**SymbolUnit\_division**](#function-symbolunit_division) (SymbolUnitHandle handle, SymbolUnitHandle other) <br> |
|  bool | [**SymbolUnit\_equal**](#function-symbolunit_equal) (SymbolUnitHandle handle, SymbolUnitHandle other) <br> |
|  SymbolUnitHandle | [**SymbolUnit\_from\_json\_string**](#function-symbolunit_from_json_string) (StringHandle json) <br> |
|  bool | [**SymbolUnit\_is\_compatible\_with**](#function-symbolunit_is_compatible_with) (SymbolUnitHandle handle, SymbolUnitHandle other) <br>_Check if this symbol unit is compatible with another symbol unit._  |
|  SymbolUnitHandle | [**SymbolUnit\_multiplication**](#function-symbolunit_multiplication) (SymbolUnitHandle handle, SymbolUnitHandle other) <br> |
|  StringHandle | [**SymbolUnit\_name**](#function-symbolunit_name) (SymbolUnitHandle handle) <br>_Get the name of the unit._  |
|  bool | [**SymbolUnit\_not\_equal**](#function-symbolunit_not_equal) (SymbolUnitHandle handle, SymbolUnitHandle other) <br> |
|  SymbolUnitHandle | [**SymbolUnit\_power**](#function-symbolunit_power) (SymbolUnitHandle handle, int power) <br> |
|  StringHandle | [**SymbolUnit\_symbol**](#function-symbolunit_symbol) (SymbolUnitHandle handle) <br>_Get the name of the unit._  |
|  StringHandle | [**SymbolUnit\_to\_json\_string**](#function-symbolunit_to_json_string) (SymbolUnitHandle handle) <br> |
|  SymbolUnitHandle | [**SymbolUnit\_with\_prefix**](#function-symbolunit_with_prefix) (SymbolUnitHandle handle, StringHandle prefix) <br> |




























## Public Types Documentation




### typedef SymbolUnitHandle 

```C++
typedef void* SymbolUnitHandle;
```




<hr>
## Public Functions Documentation




### function SymbolUnit\_convert\_value\_to 

_Convert a value from this symbol unit to a target symbol unit._ 
```C++
double SymbolUnit_convert_value_to (
    SymbolUnitHandle handle,
    double value,
    SymbolUnitHandle target
) 
```





**Parameters:**


* `value` The value in this symbol unit to convert. 
* `target_unit` The symbol unit to convert the value to. 



**Returns:**

The converted value in the target symbol unit. 




**Exception:**


* `std::invalid_argument` if the units are not compatible. 




        

<hr>



### function SymbolUnit\_copy 

```C++
SymbolUnitHandle SymbolUnit_copy (
    SymbolUnitHandle handle
) 
```




<hr>



### function SymbolUnit\_create\_ampere 

_Construct an Ampere._ 
```C++
SymbolUnitHandle SymbolUnit_create_ampere () 
```




<hr>



### function SymbolUnit\_create\_amperes\_per\_meter 

_Construct an AmperesPerMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_amperes_per_meter () 
```




<hr>



### function SymbolUnit\_create\_candela 

_Construct a Candela._ 
```C++
SymbolUnitHandle SymbolUnit_create_candela () 
```




<hr>



### function SymbolUnit\_create\_celsius 

_Construct a Celsius._ 
```C++
SymbolUnitHandle SymbolUnit_create_celsius () 
```




<hr>



### function SymbolUnit\_create\_coulomb 

_Construct a Coulomb._ 
```C++
SymbolUnitHandle SymbolUnit_create_coulomb () 
```




<hr>



### function SymbolUnit\_create\_dimensionless 

_Construct a Dimensionless._ 
```C++
SymbolUnitHandle SymbolUnit_create_dimensionless () 
```




<hr>



### function SymbolUnit\_create\_electronvolt 

_Construct an ElectronVolt._ 
```C++
SymbolUnitHandle SymbolUnit_create_electronvolt () 
```




<hr>



### function SymbolUnit\_create\_fahrenheit 

_Construct a Fahrenheit._ 
```C++
SymbolUnitHandle SymbolUnit_create_fahrenheit () 
```




<hr>



### function SymbolUnit\_create\_farad 

_Construct a Farad._ 
```C++
SymbolUnitHandle SymbolUnit_create_farad () 
```




<hr>



### function SymbolUnit\_create\_gigahertz 

_Construct a GigaHertz._ 
```C++
SymbolUnitHandle SymbolUnit_create_gigahertz () 
```




<hr>



### function SymbolUnit\_create\_henry 

_Construct a Henry._ 
```C++
SymbolUnitHandle SymbolUnit_create_henry () 
```




<hr>



### function SymbolUnit\_create\_hertz 

_Construct a Hertz._ 
```C++
SymbolUnitHandle SymbolUnit_create_hertz () 
```




<hr>



### function SymbolUnit\_create\_hour 

_Construct an Hour._ 
```C++
SymbolUnitHandle SymbolUnit_create_hour () 
```




<hr>



### function SymbolUnit\_create\_joule 

_Construct a Joule._ 
```C++
SymbolUnitHandle SymbolUnit_create_joule () 
```




<hr>



### function SymbolUnit\_create\_kelvin 

_Construct a Kelvin._ 
```C++
SymbolUnitHandle SymbolUnit_create_kelvin () 
```




<hr>



### function SymbolUnit\_create\_kilogram 

_Construct a Kilogram._ 
```C++
SymbolUnitHandle SymbolUnit_create_kilogram () 
```




<hr>



### function SymbolUnit\_create\_kilohertz 

_Construct a KiloHertz._ 
```C++
SymbolUnitHandle SymbolUnit_create_kilohertz () 
```




<hr>



### function SymbolUnit\_create\_kilometer 

_Construct a KiloMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_kilometer () 
```




<hr>



### function SymbolUnit\_create\_kiloohm 

_Construct a KiloOhm._ 
```C++
SymbolUnitHandle SymbolUnit_create_kiloohm () 
```




<hr>



### function SymbolUnit\_create\_kilovolt 

_Construct a KiloVolt._ 
```C++
SymbolUnitHandle SymbolUnit_create_kilovolt () 
```




<hr>



### function SymbolUnit\_create\_megahertz 

_Construct a MegaHertz._ 
```C++
SymbolUnitHandle SymbolUnit_create_megahertz () 
```




<hr>



### function SymbolUnit\_create\_megaohm 

_Construct a MegaOhm._ 
```C++
SymbolUnitHandle SymbolUnit_create_megaohm () 
```




<hr>



### function SymbolUnit\_create\_meter 

_Construct a Meter._ 
```C++
SymbolUnitHandle SymbolUnit_create_meter () 
```




<hr>



### function SymbolUnit\_create\_meters\_per\_second 

_Construct a MetersPerSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_meters_per_second () 
```




<hr>



### function SymbolUnit\_create\_meters\_per\_second\_squared 

_Construct a MetersPerSecondSquared._ 
```C++
SymbolUnitHandle SymbolUnit_create_meters_per_second_squared () 
```




<hr>



### function SymbolUnit\_create\_microampere 

_Construct a MicroAmpere._ 
```C++
SymbolUnitHandle SymbolUnit_create_microampere () 
```




<hr>



### function SymbolUnit\_create\_microsecond 

_Construct a MicroSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_microsecond () 
```




<hr>



### function SymbolUnit\_create\_milliampere 

_Construct a MilliAmpere._ 
```C++
SymbolUnitHandle SymbolUnit_create_milliampere () 
```




<hr>



### function SymbolUnit\_create\_millihertz 

_Construct a MilliHertz._ 
```C++
SymbolUnitHandle SymbolUnit_create_millihertz () 
```




<hr>



### function SymbolUnit\_create\_millimeter 

_Construct a MilliMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_millimeter () 
```




<hr>



### function SymbolUnit\_create\_milliohm 

_Construct a MilliOhm._ 
```C++
SymbolUnitHandle SymbolUnit_create_milliohm () 
```




<hr>



### function SymbolUnit\_create\_millisecond 

_Construct a MilliSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_millisecond () 
```




<hr>



### function SymbolUnit\_create\_millivolt 

_Construct a MilliVolt._ 
```C++
SymbolUnitHandle SymbolUnit_create_millivolt () 
```




<hr>



### function SymbolUnit\_create\_minute 

_Construct a Minute._ 
```C++
SymbolUnitHandle SymbolUnit_create_minute () 
```




<hr>



### function SymbolUnit\_create\_mole 

_Construct a Mole._ 
```C++
SymbolUnitHandle SymbolUnit_create_mole () 
```




<hr>



### function SymbolUnit\_create\_nanoampere 

_Construct a NanoAmpere._ 
```C++
SymbolUnitHandle SymbolUnit_create_nanoampere () 
```




<hr>



### function SymbolUnit\_create\_nanosecond 

_Construct a NanoSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_nanosecond () 
```




<hr>



### function SymbolUnit\_create\_newton 

_Construct a Newton._ 
```C++
SymbolUnitHandle SymbolUnit_create_newton () 
```




<hr>



### function SymbolUnit\_create\_newton\_meter 

_Construct a NewtonMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_newton_meter () 
```




<hr>



### function SymbolUnit\_create\_newtons\_per\_meter 

_Construct a NewtonPerMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_newtons_per_meter () 
```




<hr>



### function SymbolUnit\_create\_ohm 

_Construct an Ohm._ 
```C++
SymbolUnitHandle SymbolUnit_create_ohm () 
```




<hr>



### function SymbolUnit\_create\_pascal 

_Construct a Pascal._ 
```C++
SymbolUnitHandle SymbolUnit_create_pascal () 
```




<hr>



### function SymbolUnit\_create\_percent 

_Construct a Percent._ 
```C++
SymbolUnitHandle SymbolUnit_create_percent () 
```




<hr>



### function SymbolUnit\_create\_picoampere 

_Construct a PicoAmpere._ 
```C++
SymbolUnitHandle SymbolUnit_create_picoampere () 
```




<hr>



### function SymbolUnit\_create\_picosecond 

_Construct a PicoSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_picosecond () 
```




<hr>



### function SymbolUnit\_create\_radian 

_Construct a Radian._ 
```C++
SymbolUnitHandle SymbolUnit_create_radian () 
```




<hr>



### function SymbolUnit\_create\_second 

_Construct a Second._ 
```C++
SymbolUnitHandle SymbolUnit_create_second () 
```




<hr>



### function SymbolUnit\_create\_siemens 

_Construct a Seimens._ 
```C++
SymbolUnitHandle SymbolUnit_create_siemens () 
```




<hr>



### function SymbolUnit\_create\_tesla 

_Construct a Tesla._ 
```C++
SymbolUnitHandle SymbolUnit_create_tesla () 
```




<hr>



### function SymbolUnit\_create\_volt 

_Construct a Volt._ 
```C++
SymbolUnitHandle SymbolUnit_create_volt () 
```




<hr>



### function SymbolUnit\_create\_volts\_per\_ampere 

_Construct a VoltsPerAmpere._ 
```C++
SymbolUnitHandle SymbolUnit_create_volts_per_ampere () 
```




<hr>



### function SymbolUnit\_create\_volts\_per\_meter 

_Construct a VoltsPerMeter._ 
```C++
SymbolUnitHandle SymbolUnit_create_volts_per_meter () 
```




<hr>



### function SymbolUnit\_create\_volts\_per\_second 

_Construct a VoltsPerSecond._ 
```C++
SymbolUnitHandle SymbolUnit_create_volts_per_second () 
```




<hr>



### function SymbolUnit\_create\_watt 

_Construct a Watt._ 
```C++
SymbolUnitHandle SymbolUnit_create_watt () 
```




<hr>



### function SymbolUnit\_create\_watts\_per\_meter\_kelvin 

_Construct a WattsPerMeterKelvin._ 
```C++
SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin () 
```




<hr>



### function SymbolUnit\_create\_weber 

_Construct a Weber._ 
```C++
SymbolUnitHandle SymbolUnit_create_weber () 
```




<hr>



### function SymbolUnit\_destroy 

```C++
void SymbolUnit_destroy (
    SymbolUnitHandle handle
) 
```




<hr>



### function SymbolUnit\_division 

```C++
SymbolUnitHandle SymbolUnit_division (
    SymbolUnitHandle handle,
    SymbolUnitHandle other
) 
```




<hr>



### function SymbolUnit\_equal 

```C++
bool SymbolUnit_equal (
    SymbolUnitHandle handle,
    SymbolUnitHandle other
) 
```




<hr>



### function SymbolUnit\_from\_json\_string 

```C++
SymbolUnitHandle SymbolUnit_from_json_string (
    StringHandle json
) 
```




<hr>



### function SymbolUnit\_is\_compatible\_with 

_Check if this symbol unit is compatible with another symbol unit._ 
```C++
bool SymbolUnit_is_compatible_with (
    SymbolUnitHandle handle,
    SymbolUnitHandle other
) 
```





**Parameters:**


* `other` The symbol unit to check compatibility with. 



**Returns:**

True if the symbol units are compatible (same dimensions), false otherwise. 





        

<hr>



### function SymbolUnit\_multiplication 

```C++
SymbolUnitHandle SymbolUnit_multiplication (
    SymbolUnitHandle handle,
    SymbolUnitHandle other
) 
```




<hr>



### function SymbolUnit\_name 

_Get the name of the unit._ 
```C++
StringHandle SymbolUnit_name (
    SymbolUnitHandle handle
) 
```





**Returns:**

The name as a string. 





        

<hr>



### function SymbolUnit\_not\_equal 

```C++
bool SymbolUnit_not_equal (
    SymbolUnitHandle handle,
    SymbolUnitHandle other
) 
```




<hr>



### function SymbolUnit\_power 

```C++
SymbolUnitHandle SymbolUnit_power (
    SymbolUnitHandle handle,
    int power
) 
```




<hr>



### function SymbolUnit\_symbol 

_Get the name of the unit._ 
```C++
StringHandle SymbolUnit_symbol (
    SymbolUnitHandle handle
) 
```





**Returns:**

The name as a string. 





        

<hr>



### function SymbolUnit\_to\_json\_string 

```C++
StringHandle SymbolUnit_to_json_string (
    SymbolUnitHandle handle
) 
```




<hr>



### function SymbolUnit\_with\_prefix 

```C++
SymbolUnitHandle SymbolUnit_with_prefix (
    SymbolUnitHandle handle,
    StringHandle prefix
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/units/SymbolUnit_c_api.h`

