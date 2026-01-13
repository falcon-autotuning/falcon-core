

# File ListMeasurementContext\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListMeasurementContext\_c\_api.h**](ListMeasurementContext__c__api_8h.md)

[Go to the source code of this file](ListMeasurementContext__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListMeasurementContextHandle**](#typedef-listmeasurementcontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MeasurementContextHandle | [**ListMeasurementContext\_at**](#function-listmeasurementcontext_at) (ListMeasurementContextHandle handle, size\_t idx) <br> |
|  void | [**ListMeasurementContext\_clear**](#function-listmeasurementcontext_clear) (ListMeasurementContextHandle handle) <br> |
|  bool | [**ListMeasurementContext\_contains**](#function-listmeasurementcontext_contains) (ListMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_copy**](#function-listmeasurementcontext_copy) (ListMeasurementContextHandle handle) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_create**](#function-listmeasurementcontext_create) (MeasurementContextHandle \* data, size\_t count) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_create\_empty**](#function-listmeasurementcontext_create_empty) () <br> |
|  void | [**ListMeasurementContext\_destroy**](#function-listmeasurementcontext_destroy) (ListMeasurementContextHandle handle) <br> |
|  bool | [**ListMeasurementContext\_empty**](#function-listmeasurementcontext_empty) (ListMeasurementContextHandle handle) <br> |
|  bool | [**ListMeasurementContext\_equal**](#function-listmeasurementcontext_equal) (ListMeasurementContextHandle handle, ListMeasurementContextHandle other) <br> |
|  void | [**ListMeasurementContext\_erase\_at**](#function-listmeasurementcontext_erase_at) (ListMeasurementContextHandle handle, size\_t idx) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_fill\_value**](#function-listmeasurementcontext_fill_value) (size\_t count, MeasurementContextHandle value) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_from\_json\_string**](#function-listmeasurementcontext_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListMeasurementContext\_index**](#function-listmeasurementcontext_index) (ListMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  ListMeasurementContextHandle | [**ListMeasurementContext\_intersection**](#function-listmeasurementcontext_intersection) (ListMeasurementContextHandle handle, ListMeasurementContextHandle other) <br> |
|  size\_t | [**ListMeasurementContext\_items**](#function-listmeasurementcontext_items) (ListMeasurementContextHandle handle, MeasurementContextHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListMeasurementContext\_not\_equal**](#function-listmeasurementcontext_not_equal) (ListMeasurementContextHandle handle, ListMeasurementContextHandle other) <br> |
|  void | [**ListMeasurementContext\_push\_back**](#function-listmeasurementcontext_push_back) (ListMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  size\_t | [**ListMeasurementContext\_size**](#function-listmeasurementcontext_size) (ListMeasurementContextHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListMeasurementContext\_to\_json\_string**](#function-listmeasurementcontext_to_json_string) (ListMeasurementContextHandle handle) <br> |




























## Public Types Documentation




### typedef ListMeasurementContextHandle 

```C++
typedef void* ListMeasurementContextHandle;
```




<hr>
## Public Functions Documentation




### function ListMeasurementContext\_at 

```C++
MeasurementContextHandle ListMeasurementContext_at (
    ListMeasurementContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListMeasurementContext\_clear 

```C++
void ListMeasurementContext_clear (
    ListMeasurementContextHandle handle
) 
```




<hr>



### function ListMeasurementContext\_contains 

```C++
bool ListMeasurementContext_contains (
    ListMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function ListMeasurementContext\_copy 

```C++
ListMeasurementContextHandle ListMeasurementContext_copy (
    ListMeasurementContextHandle handle
) 
```




<hr>



### function ListMeasurementContext\_create 

```C++
ListMeasurementContextHandle ListMeasurementContext_create (
    MeasurementContextHandle * data,
    size_t count
) 
```




<hr>



### function ListMeasurementContext\_create\_empty 

```C++
ListMeasurementContextHandle ListMeasurementContext_create_empty () 
```




<hr>



### function ListMeasurementContext\_destroy 

```C++
void ListMeasurementContext_destroy (
    ListMeasurementContextHandle handle
) 
```




<hr>



### function ListMeasurementContext\_empty 

```C++
bool ListMeasurementContext_empty (
    ListMeasurementContextHandle handle
) 
```




<hr>



### function ListMeasurementContext\_equal 

```C++
bool ListMeasurementContext_equal (
    ListMeasurementContextHandle handle,
    ListMeasurementContextHandle other
) 
```




<hr>



### function ListMeasurementContext\_erase\_at 

```C++
void ListMeasurementContext_erase_at (
    ListMeasurementContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListMeasurementContext\_fill\_value 

```C++
ListMeasurementContextHandle ListMeasurementContext_fill_value (
    size_t count,
    MeasurementContextHandle value
) 
```




<hr>



### function ListMeasurementContext\_from\_json\_string 

```C++
ListMeasurementContextHandle ListMeasurementContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListMeasurementContext\_index 

```C++
size_t ListMeasurementContext_index (
    ListMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function ListMeasurementContext\_intersection 

```C++
ListMeasurementContextHandle ListMeasurementContext_intersection (
    ListMeasurementContextHandle handle,
    ListMeasurementContextHandle other
) 
```




<hr>



### function ListMeasurementContext\_items 

```C++
size_t ListMeasurementContext_items (
    ListMeasurementContextHandle handle,
    MeasurementContextHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListMeasurementContext\_not\_equal 

```C++
bool ListMeasurementContext_not_equal (
    ListMeasurementContextHandle handle,
    ListMeasurementContextHandle other
) 
```




<hr>



### function ListMeasurementContext\_push\_back 

```C++
void ListMeasurementContext_push_back (
    ListMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function ListMeasurementContext\_size 

```C++
size_t ListMeasurementContext_size (
    ListMeasurementContextHandle handle
) 
```




<hr>



### function ListMeasurementContext\_to\_json\_string 

```C++
StringHandle ListMeasurementContext_to_json_string (
    ListMeasurementContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListMeasurementContext_c_api.h`

