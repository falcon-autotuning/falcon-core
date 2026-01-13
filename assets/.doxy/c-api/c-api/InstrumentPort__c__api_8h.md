

# File InstrumentPort\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**names**](dir_fb9004cf3d6d1aecbf7000576bf4839c.md) **>** [**InstrumentPort\_c\_api.h**](InstrumentPort__c__api_8h.md)

[Go to the source code of this file](InstrumentPort__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include <stddef.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**InstrumentPortHandle**](#typedef-instrumentporthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  InstrumentPortHandle | [**InstrumentPort\_copy**](#function-instrumentport_copy) (InstrumentPortHandle handle) <br> |
|  InstrumentPortHandle | [**InstrumentPort\_create\_execution\_clock**](#function-instrumentport_create_execution_clock) () <br> |
|  InstrumentPortHandle | [**InstrumentPort\_create\_knob**](#function-instrumentport_create_knob) ([**StringHandle**](structstring.md) default\_name, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  InstrumentPortHandle | [**InstrumentPort\_create\_meter**](#function-instrumentport_create_meter) ([**StringHandle**](structstring.md) default\_name, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  InstrumentPortHandle | [**InstrumentPort\_create\_port**](#function-instrumentport_create_port) ([**StringHandle**](structstring.md) default\_name, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  InstrumentPortHandle | [**InstrumentPort\_create\_timer**](#function-instrumentport_create_timer) () <br> |
|  [**StringHandle**](structstring.md) | [**InstrumentPort\_default\_name**](#function-instrumentport_default_name) (InstrumentPortHandle handle) <br>_Rreturn the default name of the port._  |
|  [**StringHandle**](structstring.md) | [**InstrumentPort\_description**](#function-instrumentport_description) (InstrumentPortHandle handle) <br>_Returns the description of the port._  |
|  void | [**InstrumentPort\_destroy**](#function-instrumentport_destroy) (InstrumentPortHandle handle) <br> |
|  bool | [**InstrumentPort\_equal**](#function-instrumentport_equal) (InstrumentPortHandle handle, InstrumentPortHandle other) <br> |
|  InstrumentPortHandle | [**InstrumentPort\_from\_json\_string**](#function-instrumentport_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**InstrumentPort\_instrument\_facing\_name**](#function-instrumentport_instrument_facing_name) (InstrumentPortHandle handle) <br>_Returns the psuedo name if it exists, otherwise the instrument type as a string._  |
|  [**StringHandle**](structstring.md) | [**InstrumentPort\_instrument\_type**](#function-instrumentport_instrument_type) (InstrumentPortHandle handle) <br>_Returns the type of the instrument that the port is connected to._  |
|  bool | [**InstrumentPort\_is\_knob**](#function-instrumentport_is_knob) (InstrumentPortHandle handle) <br>_Checks if this port is a knob._  |
|  bool | [**InstrumentPort\_is\_meter**](#function-instrumentport_is_meter) (InstrumentPortHandle handle) <br>_Checks if this port is a meter._  |
|  bool | [**InstrumentPort\_is\_port**](#function-instrumentport_is_port) (InstrumentPortHandle handle) <br>_Checks if this port is a port._  |
|  bool | [**InstrumentPort\_not\_equal**](#function-instrumentport_not_equal) (InstrumentPortHandle handle, InstrumentPortHandle other) <br> |
|  ConnectionHandle | [**InstrumentPort\_psuedo\_name**](#function-instrumentport_psuedo_name) (InstrumentPortHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**InstrumentPort\_to\_json\_string**](#function-instrumentport_to_json_string) (InstrumentPortHandle handle) <br> |
|  SymbolUnitHandle | [**InstrumentPort\_units**](#function-instrumentport_units) (InstrumentPortHandle handle) <br>_Returns the untis of the port._  |




























## Public Types Documentation




### typedef InstrumentPortHandle 

```C++
typedef void* InstrumentPortHandle;
```




<hr>
## Public Functions Documentation




### function InstrumentPort\_copy 

```C++
InstrumentPortHandle InstrumentPort_copy (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_create\_execution\_clock 

```C++
InstrumentPortHandle InstrumentPort_create_execution_clock () 
```




<hr>



### function InstrumentPort\_create\_knob 

```C++
InstrumentPortHandle InstrumentPort_create_knob (
    StringHandle default_name,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function InstrumentPort\_create\_meter 

```C++
InstrumentPortHandle InstrumentPort_create_meter (
    StringHandle default_name,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function InstrumentPort\_create\_port 

```C++
InstrumentPortHandle InstrumentPort_create_port (
    StringHandle default_name,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function InstrumentPort\_create\_timer 

```C++
InstrumentPortHandle InstrumentPort_create_timer () 
```




<hr>



### function InstrumentPort\_default\_name 

_Rreturn the default name of the port._ 
```C++
StringHandle InstrumentPort_default_name (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_description 

_Returns the description of the port._ 
```C++
StringHandle InstrumentPort_description (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_destroy 

```C++
void InstrumentPort_destroy (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_equal 

```C++
bool InstrumentPort_equal (
    InstrumentPortHandle handle,
    InstrumentPortHandle other
) 
```




<hr>



### function InstrumentPort\_from\_json\_string 

```C++
InstrumentPortHandle InstrumentPort_from_json_string (
    StringHandle json
) 
```




<hr>



### function InstrumentPort\_instrument\_facing\_name 

_Returns the psuedo name if it exists, otherwise the instrument type as a string._ 
```C++
StringHandle InstrumentPort_instrument_facing_name (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_instrument\_type 

_Returns the type of the instrument that the port is connected to._ 
```C++
StringHandle InstrumentPort_instrument_type (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_is\_knob 

_Checks if this port is a knob._ 
```C++
bool InstrumentPort_is_knob (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_is\_meter 

_Checks if this port is a meter._ 
```C++
bool InstrumentPort_is_meter (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_is\_port 

_Checks if this port is a port._ 
```C++
bool InstrumentPort_is_port (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_not\_equal 

```C++
bool InstrumentPort_not_equal (
    InstrumentPortHandle handle,
    InstrumentPortHandle other
) 
```




<hr>



### function InstrumentPort\_psuedo\_name 

```C++
ConnectionHandle InstrumentPort_psuedo_name (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_to\_json\_string 

```C++
StringHandle InstrumentPort_to_json_string (
    InstrumentPortHandle handle
) 
```




<hr>



### function InstrumentPort\_units 

_Returns the untis of the port._ 
```C++
SymbolUnitHandle InstrumentPort_units (
    InstrumentPortHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h`

