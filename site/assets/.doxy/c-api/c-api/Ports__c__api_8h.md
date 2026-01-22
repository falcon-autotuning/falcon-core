

# File Ports\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**names**](dir_fb9004cf3d6d1aecbf7000576bf4839c.md) **>** [**Ports\_c\_api.h**](Ports__c__api_8h.md)

[Go to the source code of this file](Ports__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/ListInstrumentPort_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PortsHandle**](#typedef-portshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListStringHandle | [**Ports\_\_get\_instrument\_facing\_names**](#function-ports__get_instrument_facing_names) (PortsHandle handle) <br>_Gets a llist of names to satisfy an instrument interface._  |
|  InstrumentPortHandle | [**Ports\_\_get\_instrument\_type\_matching\_port**](#function-ports__get_instrument_type_matching_port) (PortsHandle handle, StringHandle insttype) <br>_Check if any port has the given instrument type._  |
|  InstrumentPortHandle | [**Ports\_\_get\_psuedoname\_matching\_port**](#function-ports__get_psuedoname_matching_port) (PortsHandle handle, ConnectionHandle name) <br>_Check if any port has the given pseudo name._  |
|  ListStringHandle | [**Ports\_\_get\_raw\_names**](#function-ports__get_raw_names) (PortsHandle handle) <br>_Return the raw string names of the ports._  |
|  InstrumentPortHandle | [**Ports\_at**](#function-ports_at) (PortsHandle handle, size\_t idx) <br> |
|  void | [**Ports\_clear**](#function-ports_clear) (PortsHandle handle) <br> |
|  bool | [**Ports\_contains**](#function-ports_contains) (PortsHandle handle, InstrumentPortHandle value) <br> |
|  PortsHandle | [**Ports\_copy**](#function-ports_copy) (PortsHandle handle) <br> |
|  PortsHandle | [**Ports\_create**](#function-ports_create) (ListInstrumentPortHandle items) <br> |
|  PortsHandle | [**Ports\_create\_empty**](#function-ports_create_empty) () <br> |
|  ListStringHandle | [**Ports\_default\_names**](#function-ports_default_names) (PortsHandle handle) <br> |
|  void | [**Ports\_destroy**](#function-ports_destroy) (PortsHandle handle) <br> |
|  bool | [**Ports\_empty**](#function-ports_empty) (PortsHandle handle) <br> |
|  bool | [**Ports\_equal**](#function-ports_equal) (PortsHandle handle, PortsHandle other) <br> |
|  void | [**Ports\_erase\_at**](#function-ports_erase_at) (PortsHandle handle, size\_t idx) <br> |
|  PortsHandle | [**Ports\_from\_json\_string**](#function-ports_from_json_string) (StringHandle json) <br> |
|  ListConnectionHandle | [**Ports\_get\_psuedo\_names**](#function-ports_get_psuedo_names) (PortsHandle handle) <br> |
|  size\_t | [**Ports\_index**](#function-ports_index) (PortsHandle handle, InstrumentPortHandle value) <br> |
|  PortsHandle | [**Ports\_intersection**](#function-ports_intersection) (PortsHandle handle, PortsHandle other) <br> |
|  bool | [**Ports\_is\_knobs**](#function-ports_is_knobs) (PortsHandle handle) <br>_Check if the ports contains only knobs._  |
|  bool | [**Ports\_is\_meters**](#function-ports_is_meters) (PortsHandle handle) <br>_Check if the ports contains only meters._  |
|  ListStringHandle | [**Ports\_items**](#function-ports_items) (PortsHandle handle) <br> |
|  bool | [**Ports\_not\_equal**](#function-ports_not_equal) (PortsHandle handle, PortsHandle other) <br> |
|  ListInstrumentPortHandle | [**Ports\_ports**](#function-ports_ports) (PortsHandle handle) <br>_return the collection of ports._  |
|  void | [**Ports\_push\_back**](#function-ports_push_back) (PortsHandle handle, InstrumentPortHandle value) <br> |
|  size\_t | [**Ports\_size**](#function-ports_size) (PortsHandle handle) <br> |
|  StringHandle | [**Ports\_to\_json\_string**](#function-ports_to_json_string) (PortsHandle handle) <br> |




























## Public Types Documentation




### typedef PortsHandle 

```C++
typedef void* PortsHandle;
```




<hr>
## Public Functions Documentation




### function Ports\_\_get\_instrument\_facing\_names 

_Gets a llist of names to satisfy an instrument interface._ 
```C++
ListStringHandle Ports__get_instrument_facing_names (
    PortsHandle handle
) 
```




<hr>



### function Ports\_\_get\_instrument\_type\_matching\_port 

_Check if any port has the given instrument type._ 
```C++
InstrumentPortHandle Ports__get_instrument_type_matching_port (
    PortsHandle handle,
    StringHandle insttype
) 
```





**Parameters:**


* `type` The instrument type to check for. 



**Returns:**

The port with the given instrument type. 




**Exception:**


* `std::runtime_error` if no port has the given type. 




        

<hr>



### function Ports\_\_get\_psuedoname\_matching\_port 

_Check if any port has the given pseudo name._ 
```C++
InstrumentPortHandle Ports__get_psuedoname_matching_port (
    PortsHandle handle,
    ConnectionHandle name
) 
```





**Parameters:**


* `name` The pseudo name to check for. 



**Returns:**

The port with the given name 




**Exception:**


* `std::runtime_error` if no port has the given name. 




        

<hr>



### function Ports\_\_get\_raw\_names 

_Return the raw string names of the ports._ 
```C++
ListStringHandle Ports__get_raw_names (
    PortsHandle handle
) 
```




<hr>



### function Ports\_at 

```C++
InstrumentPortHandle Ports_at (
    PortsHandle handle,
    size_t idx
) 
```




<hr>



### function Ports\_clear 

```C++
void Ports_clear (
    PortsHandle handle
) 
```




<hr>



### function Ports\_contains 

```C++
bool Ports_contains (
    PortsHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function Ports\_copy 

```C++
PortsHandle Ports_copy (
    PortsHandle handle
) 
```




<hr>



### function Ports\_create 

```C++
PortsHandle Ports_create (
    ListInstrumentPortHandle items
) 
```




<hr>



### function Ports\_create\_empty 

```C++
PortsHandle Ports_create_empty () 
```




<hr>



### function Ports\_default\_names 

```C++
ListStringHandle Ports_default_names (
    PortsHandle handle
) 
```




<hr>



### function Ports\_destroy 

```C++
void Ports_destroy (
    PortsHandle handle
) 
```




<hr>



### function Ports\_empty 

```C++
bool Ports_empty (
    PortsHandle handle
) 
```




<hr>



### function Ports\_equal 

```C++
bool Ports_equal (
    PortsHandle handle,
    PortsHandle other
) 
```




<hr>



### function Ports\_erase\_at 

```C++
void Ports_erase_at (
    PortsHandle handle,
    size_t idx
) 
```




<hr>



### function Ports\_from\_json\_string 

```C++
PortsHandle Ports_from_json_string (
    StringHandle json
) 
```




<hr>



### function Ports\_get\_psuedo\_names 

```C++
ListConnectionHandle Ports_get_psuedo_names (
    PortsHandle handle
) 
```




<hr>



### function Ports\_index 

```C++
size_t Ports_index (
    PortsHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function Ports\_intersection 

```C++
PortsHandle Ports_intersection (
    PortsHandle handle,
    PortsHandle other
) 
```




<hr>



### function Ports\_is\_knobs 

_Check if the ports contains only knobs._ 
```C++
bool Ports_is_knobs (
    PortsHandle handle
) 
```





**Returns:**

True if the ports only contain knobs. 





        

<hr>



### function Ports\_is\_meters 

_Check if the ports contains only meters._ 
```C++
bool Ports_is_meters (
    PortsHandle handle
) 
```





**Returns:**

True if the ports only contain meters. 





        

<hr>



### function Ports\_items 

```C++
ListStringHandle Ports_items (
    PortsHandle handle
) 
```




<hr>



### function Ports\_not\_equal 

```C++
bool Ports_not_equal (
    PortsHandle handle,
    PortsHandle other
) 
```




<hr>



### function Ports\_ports 

_return the collection of ports._ 
```C++
ListInstrumentPortHandle Ports_ports (
    PortsHandle handle
) 
```




<hr>



### function Ports\_push\_back 

```C++
void Ports_push_back (
    PortsHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function Ports\_size 

```C++
size_t Ports_size (
    PortsHandle handle
) 
```




<hr>



### function Ports\_to\_json\_string 

```C++
StringHandle Ports_to_json_string (
    PortsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/instrument_interfaces/names/Ports_c_api.h`

