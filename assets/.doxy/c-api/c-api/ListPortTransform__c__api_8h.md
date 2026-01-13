

# File ListPortTransform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPortTransform\_c\_api.h**](ListPortTransform__c__api_8h.md)

[Go to the source code of this file](ListPortTransform__c__api_8h_source.md)



* `#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPortTransformHandle**](#typedef-listporttransformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PortTransformHandle | [**ListPortTransform\_at**](#function-listporttransform_at) (ListPortTransformHandle handle, size\_t idx) <br> |
|  void | [**ListPortTransform\_clear**](#function-listporttransform_clear) (ListPortTransformHandle handle) <br> |
|  bool | [**ListPortTransform\_contains**](#function-listporttransform_contains) (ListPortTransformHandle handle, PortTransformHandle value) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_copy**](#function-listporttransform_copy) (ListPortTransformHandle handle) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_create**](#function-listporttransform_create) (PortTransformHandle \* data, size\_t count) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_create\_empty**](#function-listporttransform_create_empty) () <br> |
|  void | [**ListPortTransform\_destroy**](#function-listporttransform_destroy) (ListPortTransformHandle handle) <br> |
|  bool | [**ListPortTransform\_empty**](#function-listporttransform_empty) (ListPortTransformHandle handle) <br> |
|  bool | [**ListPortTransform\_equal**](#function-listporttransform_equal) (ListPortTransformHandle handle, ListPortTransformHandle other) <br> |
|  void | [**ListPortTransform\_erase\_at**](#function-listporttransform_erase_at) (ListPortTransformHandle handle, size\_t idx) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_fill\_value**](#function-listporttransform_fill_value) (size\_t count, PortTransformHandle value) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_from\_json\_string**](#function-listporttransform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPortTransform\_index**](#function-listporttransform_index) (ListPortTransformHandle handle, PortTransformHandle value) <br> |
|  ListPortTransformHandle | [**ListPortTransform\_intersection**](#function-listporttransform_intersection) (ListPortTransformHandle handle, ListPortTransformHandle other) <br> |
|  size\_t | [**ListPortTransform\_items**](#function-listporttransform_items) (ListPortTransformHandle handle, PortTransformHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPortTransform\_not\_equal**](#function-listporttransform_not_equal) (ListPortTransformHandle handle, ListPortTransformHandle other) <br> |
|  void | [**ListPortTransform\_push\_back**](#function-listporttransform_push_back) (ListPortTransformHandle handle, PortTransformHandle value) <br> |
|  size\_t | [**ListPortTransform\_size**](#function-listporttransform_size) (ListPortTransformHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPortTransform\_to\_json\_string**](#function-listporttransform_to_json_string) (ListPortTransformHandle handle) <br> |




























## Public Types Documentation




### typedef ListPortTransformHandle 

```C++
typedef void* ListPortTransformHandle;
```




<hr>
## Public Functions Documentation




### function ListPortTransform\_at 

```C++
PortTransformHandle ListPortTransform_at (
    ListPortTransformHandle handle,
    size_t idx
) 
```




<hr>



### function ListPortTransform\_clear 

```C++
void ListPortTransform_clear (
    ListPortTransformHandle handle
) 
```




<hr>



### function ListPortTransform\_contains 

```C++
bool ListPortTransform_contains (
    ListPortTransformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function ListPortTransform\_copy 

```C++
ListPortTransformHandle ListPortTransform_copy (
    ListPortTransformHandle handle
) 
```




<hr>



### function ListPortTransform\_create 

```C++
ListPortTransformHandle ListPortTransform_create (
    PortTransformHandle * data,
    size_t count
) 
```




<hr>



### function ListPortTransform\_create\_empty 

```C++
ListPortTransformHandle ListPortTransform_create_empty () 
```




<hr>



### function ListPortTransform\_destroy 

```C++
void ListPortTransform_destroy (
    ListPortTransformHandle handle
) 
```




<hr>



### function ListPortTransform\_empty 

```C++
bool ListPortTransform_empty (
    ListPortTransformHandle handle
) 
```




<hr>



### function ListPortTransform\_equal 

```C++
bool ListPortTransform_equal (
    ListPortTransformHandle handle,
    ListPortTransformHandle other
) 
```




<hr>



### function ListPortTransform\_erase\_at 

```C++
void ListPortTransform_erase_at (
    ListPortTransformHandle handle,
    size_t idx
) 
```




<hr>



### function ListPortTransform\_fill\_value 

```C++
ListPortTransformHandle ListPortTransform_fill_value (
    size_t count,
    PortTransformHandle value
) 
```




<hr>



### function ListPortTransform\_from\_json\_string 

```C++
ListPortTransformHandle ListPortTransform_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPortTransform\_index 

```C++
size_t ListPortTransform_index (
    ListPortTransformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function ListPortTransform\_intersection 

```C++
ListPortTransformHandle ListPortTransform_intersection (
    ListPortTransformHandle handle,
    ListPortTransformHandle other
) 
```




<hr>



### function ListPortTransform\_items 

```C++
size_t ListPortTransform_items (
    ListPortTransformHandle handle,
    PortTransformHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPortTransform\_not\_equal 

```C++
bool ListPortTransform_not_equal (
    ListPortTransformHandle handle,
    ListPortTransformHandle other
) 
```




<hr>



### function ListPortTransform\_push\_back 

```C++
void ListPortTransform_push_back (
    ListPortTransformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function ListPortTransform\_size 

```C++
size_t ListPortTransform_size (
    ListPortTransformHandle handle
) 
```




<hr>



### function ListPortTransform\_to\_json\_string 

```C++
StringHandle ListPortTransform_to_json_string (
    ListPortTransformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPortTransform_c_api.h`

