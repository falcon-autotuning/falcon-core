

# File ListDiscretizer\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDiscretizer\_c\_api.h**](ListDiscretizer__c__api_8h.md)

[Go to the source code of this file](ListDiscretizer__c__api_8h_source.md)



* `#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListDiscretizerHandle**](#typedef-listdiscretizerhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DiscretizerHandle | [**ListDiscretizer\_at**](#function-listdiscretizer_at) (ListDiscretizerHandle handle, size\_t idx) <br> |
|  void | [**ListDiscretizer\_clear**](#function-listdiscretizer_clear) (ListDiscretizerHandle handle) <br> |
|  bool | [**ListDiscretizer\_contains**](#function-listdiscretizer_contains) (ListDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_copy**](#function-listdiscretizer_copy) (ListDiscretizerHandle handle) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_create**](#function-listdiscretizer_create) (DiscretizerHandle \* data, size\_t count) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_create\_empty**](#function-listdiscretizer_create_empty) () <br> |
|  void | [**ListDiscretizer\_destroy**](#function-listdiscretizer_destroy) (ListDiscretizerHandle handle) <br> |
|  bool | [**ListDiscretizer\_empty**](#function-listdiscretizer_empty) (ListDiscretizerHandle handle) <br> |
|  bool | [**ListDiscretizer\_equal**](#function-listdiscretizer_equal) (ListDiscretizerHandle handle, ListDiscretizerHandle other) <br> |
|  void | [**ListDiscretizer\_erase\_at**](#function-listdiscretizer_erase_at) (ListDiscretizerHandle handle, size\_t idx) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_fill\_value**](#function-listdiscretizer_fill_value) (size\_t count, DiscretizerHandle value) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_from\_json\_string**](#function-listdiscretizer_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListDiscretizer\_index**](#function-listdiscretizer_index) (ListDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  ListDiscretizerHandle | [**ListDiscretizer\_intersection**](#function-listdiscretizer_intersection) (ListDiscretizerHandle handle, ListDiscretizerHandle other) <br> |
|  size\_t | [**ListDiscretizer\_items**](#function-listdiscretizer_items) (ListDiscretizerHandle handle, DiscretizerHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListDiscretizer\_not\_equal**](#function-listdiscretizer_not_equal) (ListDiscretizerHandle handle, ListDiscretizerHandle other) <br> |
|  void | [**ListDiscretizer\_push\_back**](#function-listdiscretizer_push_back) (ListDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  size\_t | [**ListDiscretizer\_size**](#function-listdiscretizer_size) (ListDiscretizerHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListDiscretizer\_to\_json\_string**](#function-listdiscretizer_to_json_string) (ListDiscretizerHandle handle) <br> |




























## Public Types Documentation




### typedef ListDiscretizerHandle 

```C++
typedef void* ListDiscretizerHandle;
```




<hr>
## Public Functions Documentation




### function ListDiscretizer\_at 

```C++
DiscretizerHandle ListDiscretizer_at (
    ListDiscretizerHandle handle,
    size_t idx
) 
```




<hr>



### function ListDiscretizer\_clear 

```C++
void ListDiscretizer_clear (
    ListDiscretizerHandle handle
) 
```




<hr>



### function ListDiscretizer\_contains 

```C++
bool ListDiscretizer_contains (
    ListDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function ListDiscretizer\_copy 

```C++
ListDiscretizerHandle ListDiscretizer_copy (
    ListDiscretizerHandle handle
) 
```




<hr>



### function ListDiscretizer\_create 

```C++
ListDiscretizerHandle ListDiscretizer_create (
    DiscretizerHandle * data,
    size_t count
) 
```




<hr>



### function ListDiscretizer\_create\_empty 

```C++
ListDiscretizerHandle ListDiscretizer_create_empty () 
```




<hr>



### function ListDiscretizer\_destroy 

```C++
void ListDiscretizer_destroy (
    ListDiscretizerHandle handle
) 
```




<hr>



### function ListDiscretizer\_empty 

```C++
bool ListDiscretizer_empty (
    ListDiscretizerHandle handle
) 
```




<hr>



### function ListDiscretizer\_equal 

```C++
bool ListDiscretizer_equal (
    ListDiscretizerHandle handle,
    ListDiscretizerHandle other
) 
```




<hr>



### function ListDiscretizer\_erase\_at 

```C++
void ListDiscretizer_erase_at (
    ListDiscretizerHandle handle,
    size_t idx
) 
```




<hr>



### function ListDiscretizer\_fill\_value 

```C++
ListDiscretizerHandle ListDiscretizer_fill_value (
    size_t count,
    DiscretizerHandle value
) 
```




<hr>



### function ListDiscretizer\_from\_json\_string 

```C++
ListDiscretizerHandle ListDiscretizer_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListDiscretizer\_index 

```C++
size_t ListDiscretizer_index (
    ListDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function ListDiscretizer\_intersection 

```C++
ListDiscretizerHandle ListDiscretizer_intersection (
    ListDiscretizerHandle handle,
    ListDiscretizerHandle other
) 
```




<hr>



### function ListDiscretizer\_items 

```C++
size_t ListDiscretizer_items (
    ListDiscretizerHandle handle,
    DiscretizerHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListDiscretizer\_not\_equal 

```C++
bool ListDiscretizer_not_equal (
    ListDiscretizerHandle handle,
    ListDiscretizerHandle other
) 
```




<hr>



### function ListDiscretizer\_push\_back 

```C++
void ListDiscretizer_push_back (
    ListDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function ListDiscretizer\_size 

```C++
size_t ListDiscretizer_size (
    ListDiscretizerHandle handle
) 
```




<hr>



### function ListDiscretizer\_to\_json\_string 

```C++
StringHandle ListDiscretizer_to_json_string (
    ListDiscretizerHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListDiscretizer_c_api.h`

