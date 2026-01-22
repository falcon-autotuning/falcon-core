

# File ListPairConnectionDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionDouble\_c\_api.h**](ListPairConnectionDouble__c__api_8h.md)

[Go to the source code of this file](ListPairConnectionDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairConnectionDoubleHandle**](#typedef-listpairconnectiondoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionDoubleHandle | [**ListPairConnectionDouble\_at**](#function-listpairconnectiondouble_at) (ListPairConnectionDoubleHandle handle, size\_t idx) <br> |
|  void | [**ListPairConnectionDouble\_clear**](#function-listpairconnectiondouble_clear) (ListPairConnectionDoubleHandle handle) <br> |
|  bool | [**ListPairConnectionDouble\_contains**](#function-listpairconnectiondouble_contains) (ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_copy**](#function-listpairconnectiondouble_copy) (ListPairConnectionDoubleHandle handle) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_create**](#function-listpairconnectiondouble_create) (PairConnectionDoubleHandle \* data, size\_t count) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_create\_empty**](#function-listpairconnectiondouble_create_empty) () <br> |
|  void | [**ListPairConnectionDouble\_destroy**](#function-listpairconnectiondouble_destroy) (ListPairConnectionDoubleHandle handle) <br> |
|  bool | [**ListPairConnectionDouble\_empty**](#function-listpairconnectiondouble_empty) (ListPairConnectionDoubleHandle handle) <br> |
|  bool | [**ListPairConnectionDouble\_equal**](#function-listpairconnectiondouble_equal) (ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) <br> |
|  void | [**ListPairConnectionDouble\_erase\_at**](#function-listpairconnectiondouble_erase_at) (ListPairConnectionDoubleHandle handle, size\_t idx) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_fill\_value**](#function-listpairconnectiondouble_fill_value) (size\_t count, PairConnectionDoubleHandle value) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_from\_json\_string**](#function-listpairconnectiondouble_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListPairConnectionDouble\_index**](#function-listpairconnectiondouble_index) (ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) <br> |
|  ListPairConnectionDoubleHandle | [**ListPairConnectionDouble\_intersection**](#function-listpairconnectiondouble_intersection) (ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) <br> |
|  size\_t | [**ListPairConnectionDouble\_items**](#function-listpairconnectiondouble_items) (ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairConnectionDouble\_not\_equal**](#function-listpairconnectiondouble_not_equal) (ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) <br> |
|  void | [**ListPairConnectionDouble\_push\_back**](#function-listpairconnectiondouble_push_back) (ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) <br> |
|  size\_t | [**ListPairConnectionDouble\_size**](#function-listpairconnectiondouble_size) (ListPairConnectionDoubleHandle handle) <br> |
|  StringHandle | [**ListPairConnectionDouble\_to\_json\_string**](#function-listpairconnectiondouble_to_json_string) (ListPairConnectionDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairConnectionDoubleHandle 

```C++
typedef void* ListPairConnectionDoubleHandle;
```




<hr>
## Public Functions Documentation




### function ListPairConnectionDouble\_at 

```C++
PairConnectionDoubleHandle ListPairConnectionDouble_at (
    ListPairConnectionDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionDouble\_clear 

```C++
void ListPairConnectionDouble_clear (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>



### function ListPairConnectionDouble\_contains 

```C++
bool ListPairConnectionDouble_contains (
    ListPairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle value
) 
```




<hr>



### function ListPairConnectionDouble\_copy 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_copy (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>



### function ListPairConnectionDouble\_create 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_create (
    PairConnectionDoubleHandle * data,
    size_t count
) 
```




<hr>



### function ListPairConnectionDouble\_create\_empty 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty () 
```




<hr>



### function ListPairConnectionDouble\_destroy 

```C++
void ListPairConnectionDouble_destroy (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>



### function ListPairConnectionDouble\_empty 

```C++
bool ListPairConnectionDouble_empty (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>



### function ListPairConnectionDouble\_equal 

```C++
bool ListPairConnectionDouble_equal (
    ListPairConnectionDoubleHandle handle,
    ListPairConnectionDoubleHandle other
) 
```




<hr>



### function ListPairConnectionDouble\_erase\_at 

```C++
void ListPairConnectionDouble_erase_at (
    ListPairConnectionDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionDouble\_fill\_value 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value (
    size_t count,
    PairConnectionDoubleHandle value
) 
```




<hr>



### function ListPairConnectionDouble\_from\_json\_string 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairConnectionDouble\_index 

```C++
size_t ListPairConnectionDouble_index (
    ListPairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle value
) 
```




<hr>



### function ListPairConnectionDouble\_intersection 

```C++
ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection (
    ListPairConnectionDoubleHandle handle,
    ListPairConnectionDoubleHandle other
) 
```




<hr>



### function ListPairConnectionDouble\_items 

```C++
size_t ListPairConnectionDouble_items (
    ListPairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairConnectionDouble\_not\_equal 

```C++
bool ListPairConnectionDouble_not_equal (
    ListPairConnectionDoubleHandle handle,
    ListPairConnectionDoubleHandle other
) 
```




<hr>



### function ListPairConnectionDouble\_push\_back 

```C++
void ListPairConnectionDouble_push_back (
    ListPairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle value
) 
```




<hr>



### function ListPairConnectionDouble\_size 

```C++
size_t ListPairConnectionDouble_size (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>



### function ListPairConnectionDouble\_to\_json\_string 

```C++
StringHandle ListPairConnectionDouble_to_json_string (
    ListPairConnectionDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairConnectionDouble_c_api.h`

