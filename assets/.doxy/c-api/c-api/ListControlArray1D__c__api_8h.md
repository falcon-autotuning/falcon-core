

# File ListControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListControlArray1D\_c\_api.h**](ListControlArray1D__c__api_8h.md)

[Go to the source code of this file](ListControlArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/ControlArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListControlArray1DHandle**](#typedef-listcontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArray1DHandle | [**ListControlArray1D\_at**](#function-listcontrolarray1d_at) (ListControlArray1DHandle handle, size\_t idx) <br> |
|  void | [**ListControlArray1D\_clear**](#function-listcontrolarray1d_clear) (ListControlArray1DHandle handle) <br> |
|  bool | [**ListControlArray1D\_contains**](#function-listcontrolarray1d_contains) (ListControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_copy**](#function-listcontrolarray1d_copy) (ListControlArray1DHandle handle) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_create**](#function-listcontrolarray1d_create) (ControlArray1DHandle \* data, size\_t count) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_create\_empty**](#function-listcontrolarray1d_create_empty) () <br> |
|  void | [**ListControlArray1D\_destroy**](#function-listcontrolarray1d_destroy) (ListControlArray1DHandle handle) <br> |
|  bool | [**ListControlArray1D\_empty**](#function-listcontrolarray1d_empty) (ListControlArray1DHandle handle) <br> |
|  bool | [**ListControlArray1D\_equal**](#function-listcontrolarray1d_equal) (ListControlArray1DHandle handle, ListControlArray1DHandle other) <br> |
|  void | [**ListControlArray1D\_erase\_at**](#function-listcontrolarray1d_erase_at) (ListControlArray1DHandle handle, size\_t idx) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_fill\_value**](#function-listcontrolarray1d_fill_value) (size\_t count, ControlArray1DHandle value) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_from\_json\_string**](#function-listcontrolarray1d_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListControlArray1D\_index**](#function-listcontrolarray1d_index) (ListControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  ListControlArray1DHandle | [**ListControlArray1D\_intersection**](#function-listcontrolarray1d_intersection) (ListControlArray1DHandle handle, ListControlArray1DHandle other) <br> |
|  size\_t | [**ListControlArray1D\_items**](#function-listcontrolarray1d_items) (ListControlArray1DHandle handle, ControlArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListControlArray1D\_not\_equal**](#function-listcontrolarray1d_not_equal) (ListControlArray1DHandle handle, ListControlArray1DHandle other) <br> |
|  void | [**ListControlArray1D\_push\_back**](#function-listcontrolarray1d_push_back) (ListControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  size\_t | [**ListControlArray1D\_size**](#function-listcontrolarray1d_size) (ListControlArray1DHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListControlArray1D\_to\_json\_string**](#function-listcontrolarray1d_to_json_string) (ListControlArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef ListControlArray1DHandle 

```C++
typedef void* ListControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function ListControlArray1D\_at 

```C++
ControlArray1DHandle ListControlArray1D_at (
    ListControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListControlArray1D\_clear 

```C++
void ListControlArray1D_clear (
    ListControlArray1DHandle handle
) 
```




<hr>



### function ListControlArray1D\_contains 

```C++
bool ListControlArray1D_contains (
    ListControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function ListControlArray1D\_copy 

```C++
ListControlArray1DHandle ListControlArray1D_copy (
    ListControlArray1DHandle handle
) 
```




<hr>



### function ListControlArray1D\_create 

```C++
ListControlArray1DHandle ListControlArray1D_create (
    ControlArray1DHandle * data,
    size_t count
) 
```




<hr>



### function ListControlArray1D\_create\_empty 

```C++
ListControlArray1DHandle ListControlArray1D_create_empty () 
```




<hr>



### function ListControlArray1D\_destroy 

```C++
void ListControlArray1D_destroy (
    ListControlArray1DHandle handle
) 
```




<hr>



### function ListControlArray1D\_empty 

```C++
bool ListControlArray1D_empty (
    ListControlArray1DHandle handle
) 
```




<hr>



### function ListControlArray1D\_equal 

```C++
bool ListControlArray1D_equal (
    ListControlArray1DHandle handle,
    ListControlArray1DHandle other
) 
```




<hr>



### function ListControlArray1D\_erase\_at 

```C++
void ListControlArray1D_erase_at (
    ListControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListControlArray1D\_fill\_value 

```C++
ListControlArray1DHandle ListControlArray1D_fill_value (
    size_t count,
    ControlArray1DHandle value
) 
```




<hr>



### function ListControlArray1D\_from\_json\_string 

```C++
ListControlArray1DHandle ListControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListControlArray1D\_index 

```C++
size_t ListControlArray1D_index (
    ListControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function ListControlArray1D\_intersection 

```C++
ListControlArray1DHandle ListControlArray1D_intersection (
    ListControlArray1DHandle handle,
    ListControlArray1DHandle other
) 
```




<hr>



### function ListControlArray1D\_items 

```C++
size_t ListControlArray1D_items (
    ListControlArray1DHandle handle,
    ControlArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListControlArray1D\_not\_equal 

```C++
bool ListControlArray1D_not_equal (
    ListControlArray1DHandle handle,
    ListControlArray1DHandle other
) 
```




<hr>



### function ListControlArray1D\_push\_back 

```C++
void ListControlArray1D_push_back (
    ListControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function ListControlArray1D\_size 

```C++
size_t ListControlArray1D_size (
    ListControlArray1DHandle handle
) 
```




<hr>



### function ListControlArray1D\_to\_json\_string 

```C++
StringHandle ListControlArray1D_to_json_string (
    ListControlArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListControlArray1D_c_api.h`

