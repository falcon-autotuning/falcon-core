

# File ListInstrumentPort\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListInstrumentPort\_c\_api.h**](ListInstrumentPort__c__api_8h.md)

[Go to the source code of this file](ListInstrumentPort__c__api_8h_source.md)



* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListInstrumentPortHandle**](#typedef-listinstrumentporthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  InstrumentPortHandle | [**ListInstrumentPort\_at**](#function-listinstrumentport_at) (ListInstrumentPortHandle handle, size\_t idx) <br> |
|  void | [**ListInstrumentPort\_clear**](#function-listinstrumentport_clear) (ListInstrumentPortHandle handle) <br> |
|  bool | [**ListInstrumentPort\_contains**](#function-listinstrumentport_contains) (ListInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_copy**](#function-listinstrumentport_copy) (ListInstrumentPortHandle handle) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_create**](#function-listinstrumentport_create) (InstrumentPortHandle \* data, size\_t count) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_create\_empty**](#function-listinstrumentport_create_empty) () <br> |
|  void | [**ListInstrumentPort\_destroy**](#function-listinstrumentport_destroy) (ListInstrumentPortHandle handle) <br> |
|  bool | [**ListInstrumentPort\_empty**](#function-listinstrumentport_empty) (ListInstrumentPortHandle handle) <br> |
|  bool | [**ListInstrumentPort\_equal**](#function-listinstrumentport_equal) (ListInstrumentPortHandle handle, ListInstrumentPortHandle other) <br> |
|  void | [**ListInstrumentPort\_erase\_at**](#function-listinstrumentport_erase_at) (ListInstrumentPortHandle handle, size\_t idx) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_fill\_value**](#function-listinstrumentport_fill_value) (size\_t count, InstrumentPortHandle value) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_from\_json\_string**](#function-listinstrumentport_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListInstrumentPort\_index**](#function-listinstrumentport_index) (ListInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  ListInstrumentPortHandle | [**ListInstrumentPort\_intersection**](#function-listinstrumentport_intersection) (ListInstrumentPortHandle handle, ListInstrumentPortHandle other) <br> |
|  size\_t | [**ListInstrumentPort\_items**](#function-listinstrumentport_items) (ListInstrumentPortHandle handle, InstrumentPortHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListInstrumentPort\_not\_equal**](#function-listinstrumentport_not_equal) (ListInstrumentPortHandle handle, ListInstrumentPortHandle other) <br> |
|  void | [**ListInstrumentPort\_push\_back**](#function-listinstrumentport_push_back) (ListInstrumentPortHandle handle, InstrumentPortHandle value) <br> |
|  size\_t | [**ListInstrumentPort\_size**](#function-listinstrumentport_size) (ListInstrumentPortHandle handle) <br> |
|  StringHandle | [**ListInstrumentPort\_to\_json\_string**](#function-listinstrumentport_to_json_string) (ListInstrumentPortHandle handle) <br> |




























## Public Types Documentation




### typedef ListInstrumentPortHandle 

```C++
typedef void* ListInstrumentPortHandle;
```




<hr>
## Public Functions Documentation




### function ListInstrumentPort\_at 

```C++
InstrumentPortHandle ListInstrumentPort_at (
    ListInstrumentPortHandle handle,
    size_t idx
) 
```




<hr>



### function ListInstrumentPort\_clear 

```C++
void ListInstrumentPort_clear (
    ListInstrumentPortHandle handle
) 
```




<hr>



### function ListInstrumentPort\_contains 

```C++
bool ListInstrumentPort_contains (
    ListInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function ListInstrumentPort\_copy 

```C++
ListInstrumentPortHandle ListInstrumentPort_copy (
    ListInstrumentPortHandle handle
) 
```




<hr>



### function ListInstrumentPort\_create 

```C++
ListInstrumentPortHandle ListInstrumentPort_create (
    InstrumentPortHandle * data,
    size_t count
) 
```




<hr>



### function ListInstrumentPort\_create\_empty 

```C++
ListInstrumentPortHandle ListInstrumentPort_create_empty () 
```




<hr>



### function ListInstrumentPort\_destroy 

```C++
void ListInstrumentPort_destroy (
    ListInstrumentPortHandle handle
) 
```




<hr>



### function ListInstrumentPort\_empty 

```C++
bool ListInstrumentPort_empty (
    ListInstrumentPortHandle handle
) 
```




<hr>



### function ListInstrumentPort\_equal 

```C++
bool ListInstrumentPort_equal (
    ListInstrumentPortHandle handle,
    ListInstrumentPortHandle other
) 
```




<hr>



### function ListInstrumentPort\_erase\_at 

```C++
void ListInstrumentPort_erase_at (
    ListInstrumentPortHandle handle,
    size_t idx
) 
```




<hr>



### function ListInstrumentPort\_fill\_value 

```C++
ListInstrumentPortHandle ListInstrumentPort_fill_value (
    size_t count,
    InstrumentPortHandle value
) 
```




<hr>



### function ListInstrumentPort\_from\_json\_string 

```C++
ListInstrumentPortHandle ListInstrumentPort_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListInstrumentPort\_index 

```C++
size_t ListInstrumentPort_index (
    ListInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function ListInstrumentPort\_intersection 

```C++
ListInstrumentPortHandle ListInstrumentPort_intersection (
    ListInstrumentPortHandle handle,
    ListInstrumentPortHandle other
) 
```




<hr>



### function ListInstrumentPort\_items 

```C++
size_t ListInstrumentPort_items (
    ListInstrumentPortHandle handle,
    InstrumentPortHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListInstrumentPort\_not\_equal 

```C++
bool ListInstrumentPort_not_equal (
    ListInstrumentPortHandle handle,
    ListInstrumentPortHandle other
) 
```




<hr>



### function ListInstrumentPort\_push\_back 

```C++
void ListInstrumentPort_push_back (
    ListInstrumentPortHandle handle,
    InstrumentPortHandle value
) 
```




<hr>



### function ListInstrumentPort\_size 

```C++
size_t ListInstrumentPort_size (
    ListInstrumentPortHandle handle
) 
```




<hr>



### function ListInstrumentPort\_to\_json\_string 

```C++
StringHandle ListInstrumentPort_to_json_string (
    ListInstrumentPortHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListInstrumentPort_c_api.h`

