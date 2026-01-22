

# File ListDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDouble\_c\_api.h**](ListDouble__c__api_8h.md)

[Go to the source code of this file](ListDouble__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListDoubleHandle**](#typedef-listdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListDoubleHandle | [**ListDouble\_allocate**](#function-listdouble_allocate) (size\_t count) <br> |
|  double | [**ListDouble\_at**](#function-listdouble_at) (ListDoubleHandle handle, size\_t idx) <br> |
|  void | [**ListDouble\_clear**](#function-listdouble_clear) (ListDoubleHandle handle) <br> |
|  bool | [**ListDouble\_contains**](#function-listdouble_contains) (ListDoubleHandle handle, double value) <br> |
|  ListDoubleHandle | [**ListDouble\_copy**](#function-listdouble_copy) (ListDoubleHandle handle) <br> |
|  ListDoubleHandle | [**ListDouble\_create**](#function-listdouble_create) (double \* data, size\_t count) <br> |
|  ListDoubleHandle | [**ListDouble\_create\_empty**](#function-listdouble_create_empty) () <br> |
|  void | [**ListDouble\_destroy**](#function-listdouble_destroy) (ListDoubleHandle handle) <br> |
|  bool | [**ListDouble\_empty**](#function-listdouble_empty) (ListDoubleHandle handle) <br> |
|  bool | [**ListDouble\_equal**](#function-listdouble_equal) (ListDoubleHandle handle, ListDoubleHandle other) <br> |
|  void | [**ListDouble\_erase\_at**](#function-listdouble_erase_at) (ListDoubleHandle handle, size\_t idx) <br> |
|  ListDoubleHandle | [**ListDouble\_fill\_value**](#function-listdouble_fill_value) (size\_t count, double value) <br> |
|  ListDoubleHandle | [**ListDouble\_from\_json\_string**](#function-listdouble_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListDouble\_index**](#function-listdouble_index) (ListDoubleHandle handle, double value) <br> |
|  ListDoubleHandle | [**ListDouble\_intersection**](#function-listdouble_intersection) (ListDoubleHandle handle, ListDoubleHandle other) <br> |
|  size\_t | [**ListDouble\_items**](#function-listdouble_items) (ListDoubleHandle handle, double \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListDouble\_not\_equal**](#function-listdouble_not_equal) (ListDoubleHandle handle, ListDoubleHandle other) <br> |
|  void | [**ListDouble\_push\_back**](#function-listdouble_push_back) (ListDoubleHandle handle, double value) <br> |
|  size\_t | [**ListDouble\_size**](#function-listdouble_size) (ListDoubleHandle handle) <br> |
|  StringHandle | [**ListDouble\_to\_json\_string**](#function-listdouble_to_json_string) (ListDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef ListDoubleHandle 

```C++
typedef void* ListDoubleHandle;
```




<hr>
## Public Functions Documentation




### function ListDouble\_allocate 

```C++
ListDoubleHandle ListDouble_allocate (
    size_t count
) 
```




<hr>



### function ListDouble\_at 

```C++
double ListDouble_at (
    ListDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListDouble\_clear 

```C++
void ListDouble_clear (
    ListDoubleHandle handle
) 
```




<hr>



### function ListDouble\_contains 

```C++
bool ListDouble_contains (
    ListDoubleHandle handle,
    double value
) 
```




<hr>



### function ListDouble\_copy 

```C++
ListDoubleHandle ListDouble_copy (
    ListDoubleHandle handle
) 
```




<hr>



### function ListDouble\_create 

```C++
ListDoubleHandle ListDouble_create (
    double * data,
    size_t count
) 
```




<hr>



### function ListDouble\_create\_empty 

```C++
ListDoubleHandle ListDouble_create_empty () 
```




<hr>



### function ListDouble\_destroy 

```C++
void ListDouble_destroy (
    ListDoubleHandle handle
) 
```




<hr>



### function ListDouble\_empty 

```C++
bool ListDouble_empty (
    ListDoubleHandle handle
) 
```




<hr>



### function ListDouble\_equal 

```C++
bool ListDouble_equal (
    ListDoubleHandle handle,
    ListDoubleHandle other
) 
```




<hr>



### function ListDouble\_erase\_at 

```C++
void ListDouble_erase_at (
    ListDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListDouble\_fill\_value 

```C++
ListDoubleHandle ListDouble_fill_value (
    size_t count,
    double value
) 
```




<hr>



### function ListDouble\_from\_json\_string 

```C++
ListDoubleHandle ListDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListDouble\_index 

```C++
size_t ListDouble_index (
    ListDoubleHandle handle,
    double value
) 
```




<hr>



### function ListDouble\_intersection 

```C++
ListDoubleHandle ListDouble_intersection (
    ListDoubleHandle handle,
    ListDoubleHandle other
) 
```




<hr>



### function ListDouble\_items 

```C++
size_t ListDouble_items (
    ListDoubleHandle handle,
    double * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListDouble\_not\_equal 

```C++
bool ListDouble_not_equal (
    ListDoubleHandle handle,
    ListDoubleHandle other
) 
```




<hr>



### function ListDouble\_push\_back 

```C++
void ListDouble_push_back (
    ListDoubleHandle handle,
    double value
) 
```




<hr>



### function ListDouble\_size 

```C++
size_t ListDouble_size (
    ListDoubleHandle handle
) 
```




<hr>



### function ListDouble\_to\_json\_string 

```C++
StringHandle ListDouble_to_json_string (
    ListDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListDouble_c_api.h`

