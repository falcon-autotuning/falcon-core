

# File ListImpedance\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListImpedance\_c\_api.h**](ListImpedance__c__api_8h.md)

[Go to the source code of this file](ListImpedance__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Impedance_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListImpedanceHandle**](#typedef-listimpedancehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ImpedanceHandle | [**ListImpedance\_at**](#function-listimpedance_at) (ListImpedanceHandle handle, size\_t idx) <br> |
|  void | [**ListImpedance\_clear**](#function-listimpedance_clear) (ListImpedanceHandle handle) <br> |
|  bool | [**ListImpedance\_contains**](#function-listimpedance_contains) (ListImpedanceHandle handle, ImpedanceHandle value) <br> |
|  ListImpedanceHandle | [**ListImpedance\_copy**](#function-listimpedance_copy) (ListImpedanceHandle handle) <br> |
|  ListImpedanceHandle | [**ListImpedance\_create**](#function-listimpedance_create) (ImpedanceHandle \* data, size\_t count) <br> |
|  ListImpedanceHandle | [**ListImpedance\_create\_empty**](#function-listimpedance_create_empty) () <br> |
|  void | [**ListImpedance\_destroy**](#function-listimpedance_destroy) (ListImpedanceHandle handle) <br> |
|  bool | [**ListImpedance\_empty**](#function-listimpedance_empty) (ListImpedanceHandle handle) <br> |
|  bool | [**ListImpedance\_equal**](#function-listimpedance_equal) (ListImpedanceHandle handle, ListImpedanceHandle other) <br> |
|  void | [**ListImpedance\_erase\_at**](#function-listimpedance_erase_at) (ListImpedanceHandle handle, size\_t idx) <br> |
|  ListImpedanceHandle | [**ListImpedance\_fill\_value**](#function-listimpedance_fill_value) (size\_t count, ImpedanceHandle value) <br> |
|  ListImpedanceHandle | [**ListImpedance\_from\_json\_string**](#function-listimpedance_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListImpedance\_index**](#function-listimpedance_index) (ListImpedanceHandle handle, ImpedanceHandle value) <br> |
|  ListImpedanceHandle | [**ListImpedance\_intersection**](#function-listimpedance_intersection) (ListImpedanceHandle handle, ListImpedanceHandle other) <br> |
|  size\_t | [**ListImpedance\_items**](#function-listimpedance_items) (ListImpedanceHandle handle, ImpedanceHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListImpedance\_not\_equal**](#function-listimpedance_not_equal) (ListImpedanceHandle handle, ListImpedanceHandle other) <br> |
|  void | [**ListImpedance\_push\_back**](#function-listimpedance_push_back) (ListImpedanceHandle handle, ImpedanceHandle value) <br> |
|  size\_t | [**ListImpedance\_size**](#function-listimpedance_size) (ListImpedanceHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListImpedance\_to\_json\_string**](#function-listimpedance_to_json_string) (ListImpedanceHandle handle) <br> |




























## Public Types Documentation




### typedef ListImpedanceHandle 

```C++
typedef void* ListImpedanceHandle;
```




<hr>
## Public Functions Documentation




### function ListImpedance\_at 

```C++
ImpedanceHandle ListImpedance_at (
    ListImpedanceHandle handle,
    size_t idx
) 
```




<hr>



### function ListImpedance\_clear 

```C++
void ListImpedance_clear (
    ListImpedanceHandle handle
) 
```




<hr>



### function ListImpedance\_contains 

```C++
bool ListImpedance_contains (
    ListImpedanceHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function ListImpedance\_copy 

```C++
ListImpedanceHandle ListImpedance_copy (
    ListImpedanceHandle handle
) 
```




<hr>



### function ListImpedance\_create 

```C++
ListImpedanceHandle ListImpedance_create (
    ImpedanceHandle * data,
    size_t count
) 
```




<hr>



### function ListImpedance\_create\_empty 

```C++
ListImpedanceHandle ListImpedance_create_empty () 
```




<hr>



### function ListImpedance\_destroy 

```C++
void ListImpedance_destroy (
    ListImpedanceHandle handle
) 
```




<hr>



### function ListImpedance\_empty 

```C++
bool ListImpedance_empty (
    ListImpedanceHandle handle
) 
```




<hr>



### function ListImpedance\_equal 

```C++
bool ListImpedance_equal (
    ListImpedanceHandle handle,
    ListImpedanceHandle other
) 
```




<hr>



### function ListImpedance\_erase\_at 

```C++
void ListImpedance_erase_at (
    ListImpedanceHandle handle,
    size_t idx
) 
```




<hr>



### function ListImpedance\_fill\_value 

```C++
ListImpedanceHandle ListImpedance_fill_value (
    size_t count,
    ImpedanceHandle value
) 
```




<hr>



### function ListImpedance\_from\_json\_string 

```C++
ListImpedanceHandle ListImpedance_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListImpedance\_index 

```C++
size_t ListImpedance_index (
    ListImpedanceHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function ListImpedance\_intersection 

```C++
ListImpedanceHandle ListImpedance_intersection (
    ListImpedanceHandle handle,
    ListImpedanceHandle other
) 
```




<hr>



### function ListImpedance\_items 

```C++
size_t ListImpedance_items (
    ListImpedanceHandle handle,
    ImpedanceHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListImpedance\_not\_equal 

```C++
bool ListImpedance_not_equal (
    ListImpedanceHandle handle,
    ListImpedanceHandle other
) 
```




<hr>



### function ListImpedance\_push\_back 

```C++
void ListImpedance_push_back (
    ListImpedanceHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function ListImpedance\_size 

```C++
size_t ListImpedance_size (
    ListImpedanceHandle handle
) 
```




<hr>



### function ListImpedance\_to\_json\_string 

```C++
StringHandle ListImpedance_to_json_string (
    ListImpedanceHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListImpedance_c_api.h`

