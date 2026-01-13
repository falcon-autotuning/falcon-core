

# File LabelledDomain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**LabelledDomain\_c\_api.h**](LabelledDomain__c__api_8h.md)

[Go to the source code of this file](LabelledDomain__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/math/domains/Domain_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledDomainHandle**](#typedef-labelleddomainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**LabelledDomain\_center**](#function-labelleddomain_center) (LabelledDomainHandle handle) <br> |
|  bool | [**LabelledDomain\_contains\_domain**](#function-labelleddomain_contains_domain) (LabelledDomainHandle handle, LabelledDomainHandle other) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_copy**](#function-labelleddomain_copy) (LabelledDomainHandle handle) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_from\_domain**](#function-labelleddomain_create_from_domain) (DomainHandle domain, [**StringHandle**](structstring.md) default\_name, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_from\_port**](#function-labelleddomain_create_from_port) (double min\_val, double max\_val, InstrumentPortHandle port, bool lesser\_bound\_contained, bool greater\_bound\_contained) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_from\_port\_and\_domain**](#function-labelleddomain_create_from_port_and_domain) (InstrumentPortHandle port, DomainHandle domain) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_primitive\_knob**](#function-labelleddomain_create_primitive_knob) ([**StringHandle**](structstring.md) default\_name, double min\_val, double max\_val, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, bool lesser\_bound\_contained, bool greater\_bound\_contained, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_primitive\_meter**](#function-labelleddomain_create_primitive_meter) ([**StringHandle**](structstring.md) default\_name, double min\_val, double max\_val, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, bool lesser\_bound\_contained, bool greater\_bound\_contained, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_create\_primitive\_port**](#function-labelleddomain_create_primitive_port) ([**StringHandle**](structstring.md) default\_name, double min\_val, double max\_val, ConnectionHandle psuedo\_name, [**StringHandle**](structstring.md) instrument\_type, bool lesser\_bound\_contained, bool greater\_bound\_contained, SymbolUnitHandle units, [**StringHandle**](structstring.md) description) <br> |
|  void | [**LabelledDomain\_destroy**](#function-labelleddomain_destroy) (LabelledDomainHandle handle) <br> |
|  DomainHandle | [**LabelledDomain\_domain**](#function-labelleddomain_domain) (LabelledDomainHandle handle) <br>_Gets the domain associated with the port._  |
|  bool | [**LabelledDomain\_equal**](#function-labelleddomain_equal) (LabelledDomainHandle handle, LabelledDomainHandle other) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_from\_json\_string**](#function-labelleddomain_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  double | [**LabelledDomain\_greater\_bound**](#function-labelleddomain_greater_bound) (LabelledDomainHandle handle) <br> |
|  bool | [**LabelledDomain\_greater\_bound\_contained**](#function-labelleddomain_greater_bound_contained) (LabelledDomainHandle handle) <br> |
|  bool | [**LabelledDomain\_in**](#function-labelleddomain_in) (LabelledDomainHandle handle, double value) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_intersection**](#function-labelleddomain_intersection) (LabelledDomainHandle handle, LabelledDomainHandle other) <br> |
|  bool | [**LabelledDomain\_is\_empty**](#function-labelleddomain_is_empty) (LabelledDomainHandle handle) <br> |
|  double | [**LabelledDomain\_lesser\_bound**](#function-labelleddomain_lesser_bound) (LabelledDomainHandle handle) <br> |
|  bool | [**LabelledDomain\_lesser\_bound\_contained**](#function-labelleddomain_lesser_bound_contained) (LabelledDomainHandle handle) <br> |
|  bool | [**LabelledDomain\_matching\_port**](#function-labelleddomain_matching_port) (LabelledDomainHandle handle, InstrumentPortHandle port) <br>_Checks if the port matches the given port._  |
|  bool | [**LabelledDomain\_not\_equal**](#function-labelleddomain_not_equal) (LabelledDomainHandle handle, LabelledDomainHandle other) <br> |
|  InstrumentPortHandle | [**LabelledDomain\_port**](#function-labelleddomain_port) (LabelledDomainHandle handle) <br>_Get the port._  |
|  double | [**LabelledDomain\_range**](#function-labelleddomain_range) (LabelledDomainHandle handle) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_scale**](#function-labelleddomain_scale) (LabelledDomainHandle handle, double scale) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_shift**](#function-labelleddomain_shift) (LabelledDomainHandle handle, double offset) <br> |
|  [**StringHandle**](structstring.md) | [**LabelledDomain\_to\_json\_string**](#function-labelleddomain_to_json_string) (LabelledDomainHandle handle) <br> |
|  double | [**LabelledDomain\_transform**](#function-labelleddomain_transform) (LabelledDomainHandle handle, LabelledDomainHandle other, double value) <br> |
|  LabelledDomainHandle | [**LabelledDomain\_union**](#function-labelleddomain_union) (LabelledDomainHandle handle, LabelledDomainHandle other) <br> |




























## Public Types Documentation




### typedef LabelledDomainHandle 

```C++
typedef void* LabelledDomainHandle;
```




<hr>
## Public Functions Documentation




### function LabelledDomain\_center 

```C++
double LabelledDomain_center (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_contains\_domain 

```C++
bool LabelledDomain_contains_domain (
    LabelledDomainHandle handle,
    LabelledDomainHandle other
) 
```




<hr>



### function LabelledDomain\_copy 

```C++
LabelledDomainHandle LabelledDomain_copy (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_create\_from\_domain 

```C++
LabelledDomainHandle LabelledDomain_create_from_domain (
    DomainHandle domain,
    StringHandle default_name,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function LabelledDomain\_create\_from\_port 

```C++
LabelledDomainHandle LabelledDomain_create_from_port (
    double min_val,
    double max_val,
    InstrumentPortHandle port,
    bool lesser_bound_contained,
    bool greater_bound_contained
) 
```




<hr>



### function LabelledDomain\_create\_from\_port\_and\_domain 

```C++
LabelledDomainHandle LabelledDomain_create_from_port_and_domain (
    InstrumentPortHandle port,
    DomainHandle domain
) 
```




<hr>



### function LabelledDomain\_create\_primitive\_knob 

```C++
LabelledDomainHandle LabelledDomain_create_primitive_knob (
    StringHandle default_name,
    double min_val,
    double max_val,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    bool lesser_bound_contained,
    bool greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function LabelledDomain\_create\_primitive\_meter 

```C++
LabelledDomainHandle LabelledDomain_create_primitive_meter (
    StringHandle default_name,
    double min_val,
    double max_val,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    bool lesser_bound_contained,
    bool greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function LabelledDomain\_create\_primitive\_port 

```C++
LabelledDomainHandle LabelledDomain_create_primitive_port (
    StringHandle default_name,
    double min_val,
    double max_val,
    ConnectionHandle psuedo_name,
    StringHandle instrument_type,
    bool lesser_bound_contained,
    bool greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle description
) 
```




<hr>



### function LabelledDomain\_destroy 

```C++
void LabelledDomain_destroy (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_domain 

_Gets the domain associated with the port._ 
```C++
DomainHandle LabelledDomain_domain (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_equal 

```C++
bool LabelledDomain_equal (
    LabelledDomainHandle handle,
    LabelledDomainHandle other
) 
```




<hr>



### function LabelledDomain\_from\_json\_string 

```C++
LabelledDomainHandle LabelledDomain_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledDomain\_greater\_bound 

```C++
double LabelledDomain_greater_bound (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_greater\_bound\_contained 

```C++
bool LabelledDomain_greater_bound_contained (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_in 

```C++
bool LabelledDomain_in (
    LabelledDomainHandle handle,
    double value
) 
```




<hr>



### function LabelledDomain\_intersection 

```C++
LabelledDomainHandle LabelledDomain_intersection (
    LabelledDomainHandle handle,
    LabelledDomainHandle other
) 
```




<hr>



### function LabelledDomain\_is\_empty 

```C++
bool LabelledDomain_is_empty (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_lesser\_bound 

```C++
double LabelledDomain_lesser_bound (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_lesser\_bound\_contained 

```C++
bool LabelledDomain_lesser_bound_contained (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_matching\_port 

_Checks if the port matches the given port._ 
```C++
bool LabelledDomain_matching_port (
    LabelledDomainHandle handle,
    InstrumentPortHandle port
) 
```





**Parameters:**


* `port` The port to compare with. 



**Returns:**

True if the ports match, false otherwise. 





        

<hr>



### function LabelledDomain\_not\_equal 

```C++
bool LabelledDomain_not_equal (
    LabelledDomainHandle handle,
    LabelledDomainHandle other
) 
```




<hr>



### function LabelledDomain\_port 

_Get the port._ 
```C++
InstrumentPortHandle LabelledDomain_port (
    LabelledDomainHandle handle
) 
```





**Returns:**

Shared pointer to the port. 





        

<hr>



### function LabelledDomain\_range 

```C++
double LabelledDomain_range (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_scale 

```C++
LabelledDomainHandle LabelledDomain_scale (
    LabelledDomainHandle handle,
    double scale
) 
```




<hr>



### function LabelledDomain\_shift 

```C++
LabelledDomainHandle LabelledDomain_shift (
    LabelledDomainHandle handle,
    double offset
) 
```




<hr>



### function LabelledDomain\_to\_json\_string 

```C++
StringHandle LabelledDomain_to_json_string (
    LabelledDomainHandle handle
) 
```




<hr>



### function LabelledDomain\_transform 

```C++
double LabelledDomain_transform (
    LabelledDomainHandle handle,
    LabelledDomainHandle other,
    double value
) 
```




<hr>



### function LabelledDomain\_union 

```C++
LabelledDomainHandle LabelledDomain_union (
    LabelledDomainHandle handle,
    LabelledDomainHandle other
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/domains/LabelledDomain_c_api.h`

