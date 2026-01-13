

# File ListFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListFloat\_c\_api.h**](ListFloat__c__api_8h.md)

[Go to the source code of this file](ListFloat__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListFloatHandle**](#typedef-listfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListFloatHandle | [**ListFloat\_allocate**](#function-listfloat_allocate) (size\_t count) <br> |
|  float | [**ListFloat\_at**](#function-listfloat_at) (ListFloatHandle handle, size\_t idx) <br> |
|  void | [**ListFloat\_clear**](#function-listfloat_clear) (ListFloatHandle handle) <br> |
|  bool | [**ListFloat\_contains**](#function-listfloat_contains) (ListFloatHandle handle, float value) <br> |
|  ListFloatHandle | [**ListFloat\_copy**](#function-listfloat_copy) (ListFloatHandle handle) <br> |
|  ListFloatHandle | [**ListFloat\_create**](#function-listfloat_create) (float \* data, size\_t count) <br> |
|  ListFloatHandle | [**ListFloat\_create\_empty**](#function-listfloat_create_empty) () <br> |
|  void | [**ListFloat\_destroy**](#function-listfloat_destroy) (ListFloatHandle handle) <br> |
|  bool | [**ListFloat\_empty**](#function-listfloat_empty) (ListFloatHandle handle) <br> |
|  bool | [**ListFloat\_equal**](#function-listfloat_equal) (ListFloatHandle handle, ListFloatHandle other) <br> |
|  void | [**ListFloat\_erase\_at**](#function-listfloat_erase_at) (ListFloatHandle handle, size\_t idx) <br> |
|  ListFloatHandle | [**ListFloat\_fill\_value**](#function-listfloat_fill_value) (size\_t count, float value) <br> |
|  ListFloatHandle | [**ListFloat\_from\_json\_string**](#function-listfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListFloat\_index**](#function-listfloat_index) (ListFloatHandle handle, float value) <br> |
|  ListFloatHandle | [**ListFloat\_intersection**](#function-listfloat_intersection) (ListFloatHandle handle, ListFloatHandle other) <br> |
|  size\_t | [**ListFloat\_items**](#function-listfloat_items) (ListFloatHandle handle, float \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListFloat\_not\_equal**](#function-listfloat_not_equal) (ListFloatHandle handle, ListFloatHandle other) <br> |
|  void | [**ListFloat\_push\_back**](#function-listfloat_push_back) (ListFloatHandle handle, float value) <br> |
|  size\_t | [**ListFloat\_size**](#function-listfloat_size) (ListFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListFloat\_to\_json\_string**](#function-listfloat_to_json_string) (ListFloatHandle handle) <br> |




























## Public Types Documentation




### typedef ListFloatHandle 

```C++
typedef void* ListFloatHandle;
```




<hr>
## Public Functions Documentation




### function ListFloat\_allocate 

```C++
ListFloatHandle ListFloat_allocate (
    size_t count
) 
```




<hr>



### function ListFloat\_at 

```C++
float ListFloat_at (
    ListFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListFloat\_clear 

```C++
void ListFloat_clear (
    ListFloatHandle handle
) 
```




<hr>



### function ListFloat\_contains 

```C++
bool ListFloat_contains (
    ListFloatHandle handle,
    float value
) 
```




<hr>



### function ListFloat\_copy 

```C++
ListFloatHandle ListFloat_copy (
    ListFloatHandle handle
) 
```




<hr>



### function ListFloat\_create 

```C++
ListFloatHandle ListFloat_create (
    float * data,
    size_t count
) 
```




<hr>



### function ListFloat\_create\_empty 

```C++
ListFloatHandle ListFloat_create_empty () 
```




<hr>



### function ListFloat\_destroy 

```C++
void ListFloat_destroy (
    ListFloatHandle handle
) 
```




<hr>



### function ListFloat\_empty 

```C++
bool ListFloat_empty (
    ListFloatHandle handle
) 
```




<hr>



### function ListFloat\_equal 

```C++
bool ListFloat_equal (
    ListFloatHandle handle,
    ListFloatHandle other
) 
```




<hr>



### function ListFloat\_erase\_at 

```C++
void ListFloat_erase_at (
    ListFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListFloat\_fill\_value 

```C++
ListFloatHandle ListFloat_fill_value (
    size_t count,
    float value
) 
```




<hr>



### function ListFloat\_from\_json\_string 

```C++
ListFloatHandle ListFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListFloat\_index 

```C++
size_t ListFloat_index (
    ListFloatHandle handle,
    float value
) 
```




<hr>



### function ListFloat\_intersection 

```C++
ListFloatHandle ListFloat_intersection (
    ListFloatHandle handle,
    ListFloatHandle other
) 
```




<hr>



### function ListFloat\_items 

```C++
size_t ListFloat_items (
    ListFloatHandle handle,
    float * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListFloat\_not\_equal 

```C++
bool ListFloat_not_equal (
    ListFloatHandle handle,
    ListFloatHandle other
) 
```




<hr>



### function ListFloat\_push\_back 

```C++
void ListFloat_push_back (
    ListFloatHandle handle,
    float value
) 
```




<hr>



### function ListFloat\_size 

```C++
size_t ListFloat_size (
    ListFloatHandle handle
) 
```




<hr>



### function ListFloat\_to\_json\_string 

```C++
StringHandle ListFloat_to_json_string (
    ListFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListFloat_c_api.h`

