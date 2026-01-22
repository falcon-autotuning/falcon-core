

# File AxesInstrumentPort\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesInstrumentPort\_c\_api.h**](AxesInstrumentPort__c__api_8h.md)

[Go to the source code of this file](AxesInstrumentPort__c__api_8h_source.md)



* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/generic/ListInstrumentPort_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesInstrumentPortHandle**](#typedef-axesinstrumentporthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  InstrumentPortHandle | [**AxesInstrumentPort\_at**](#function-axesinstrumentport_at) (AxesInstrumentPortHandle handle, size\_t idx) <br> |
|  void | [**AxesInstrumentPort\_clear**](#function-axesinstrumentport_clear) (AxesInstrumentPortHandle handle) <br> |
|  bool | [**AxesInstrumentPort\_contains**](#function-axesinstrumentport_contains) (AxesInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  AxesInstrumentPortHandle | [**AxesInstrumentPort\_copy**](#function-axesinstrumentport_copy) (AxesInstrumentPortHandle handle) <br> |
|  AxesInstrumentPortHandle | [**AxesInstrumentPort\_create**](#function-axesinstrumentport_create) (ListInstrumentPortHandle data) <br> |
|  AxesInstrumentPortHandle | [**AxesInstrumentPort\_create\_empty**](#function-axesinstrumentport_create_empty) () <br> |
|  void | [**AxesInstrumentPort\_destroy**](#function-axesinstrumentport_destroy) (AxesInstrumentPortHandle handle) <br> |
|  bool | [**AxesInstrumentPort\_empty**](#function-axesinstrumentport_empty) (AxesInstrumentPortHandle handle) <br> |
|  bool | [**AxesInstrumentPort\_equal**](#function-axesinstrumentport_equal) (AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) <br> |
|  void | [**AxesInstrumentPort\_erase\_at**](#function-axesinstrumentport_erase_at) (AxesInstrumentPortHandle handle, size\_t idx) <br> |
|  AxesInstrumentPortHandle | [**AxesInstrumentPort\_from\_json\_string**](#function-axesinstrumentport_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesInstrumentPort\_index**](#function-axesinstrumentport_index) (AxesInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  AxesInstrumentPortHandle | [**AxesInstrumentPort\_intersection**](#function-axesinstrumentport_intersection) (AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) <br> |
|  size\_t | [**AxesInstrumentPort\_items**](#function-axesinstrumentport_items) (AxesInstrumentPortHandle handle, InstrumentPortHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesInstrumentPort\_not\_equal**](#function-axesinstrumentport_not_equal) (AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) <br> |
|  void | [**AxesInstrumentPort\_push\_back**](#function-axesinstrumentport_push_back) (AxesInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  size\_t | [**AxesInstrumentPort\_size**](#function-axesinstrumentport_size) (AxesInstrumentPortHandle handle) <br> |
|  StringHandle | [**AxesInstrumentPort\_to\_json\_string**](#function-axesinstrumentport_to_json_string) (AxesInstrumentPortHandle handle) <br> |




























## Public Types Documentation




### typedef AxesInstrumentPortHandle 

```C++
typedef void* AxesInstrumentPortHandle;
```




<hr>
## Public Functions Documentation




### function AxesInstrumentPort\_at 

```C++
InstrumentPortHandle AxesInstrumentPort_at (
    AxesInstrumentPortHandle handle,
    size_t idx
) 
```




<hr>



### function AxesInstrumentPort\_clear 

```C++
void AxesInstrumentPort_clear (
    AxesInstrumentPortHandle handle
) 
```




<hr>



### function AxesInstrumentPort\_contains 

```C++
bool AxesInstrumentPort_contains (
    AxesInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function AxesInstrumentPort\_copy 

```C++
AxesInstrumentPortHandle AxesInstrumentPort_copy (
    AxesInstrumentPortHandle handle
) 
```




<hr>



### function AxesInstrumentPort\_create 

```C++
AxesInstrumentPortHandle AxesInstrumentPort_create (
    ListInstrumentPortHandle data
) 
```




<hr>



### function AxesInstrumentPort\_create\_empty 

```C++
AxesInstrumentPortHandle AxesInstrumentPort_create_empty () 
```




<hr>



### function AxesInstrumentPort\_destroy 

```C++
void AxesInstrumentPort_destroy (
    AxesInstrumentPortHandle handle
) 
```




<hr>



### function AxesInstrumentPort\_empty 

```C++
bool AxesInstrumentPort_empty (
    AxesInstrumentPortHandle handle
) 
```




<hr>



### function AxesInstrumentPort\_equal 

```C++
bool AxesInstrumentPort_equal (
    AxesInstrumentPortHandle handle,
    AxesInstrumentPortHandle other
) 
```




<hr>



### function AxesInstrumentPort\_erase\_at 

```C++
void AxesInstrumentPort_erase_at (
    AxesInstrumentPortHandle handle,
    size_t idx
) 
```




<hr>



### function AxesInstrumentPort\_from\_json\_string 

```C++
AxesInstrumentPortHandle AxesInstrumentPort_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesInstrumentPort\_index 

```C++
size_t AxesInstrumentPort_index (
    AxesInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function AxesInstrumentPort\_intersection 

```C++
AxesInstrumentPortHandle AxesInstrumentPort_intersection (
    AxesInstrumentPortHandle handle,
    AxesInstrumentPortHandle other
) 
```




<hr>



### function AxesInstrumentPort\_items 

```C++
size_t AxesInstrumentPort_items (
    AxesInstrumentPortHandle handle,
    InstrumentPortHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesInstrumentPort\_not\_equal 

```C++
bool AxesInstrumentPort_not_equal (
    AxesInstrumentPortHandle handle,
    AxesInstrumentPortHandle other
) 
```




<hr>



### function AxesInstrumentPort\_push\_back 

```C++
void AxesInstrumentPort_push_back (
    AxesInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function AxesInstrumentPort\_size 

```C++
size_t AxesInstrumentPort_size (
    AxesInstrumentPortHandle handle
) 
```




<hr>



### function AxesInstrumentPort\_to\_json\_string 

```C++
StringHandle AxesInstrumentPort_to_json_string (
    AxesInstrumentPortHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesInstrumentPort_c_api.h`

