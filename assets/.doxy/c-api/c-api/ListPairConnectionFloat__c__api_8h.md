

# File ListPairConnectionFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionFloat\_c\_api.h**](ListPairConnectionFloat__c__api_8h.md)

[Go to the source code of this file](ListPairConnectionFloat__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionFloat_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairConnectionFloatHandle**](#typedef-listpairconnectionfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionFloatHandle | [**ListPairConnectionFloat\_at**](#function-listpairconnectionfloat_at) (ListPairConnectionFloatHandle handle, size\_t idx) <br> |
|  void | [**ListPairConnectionFloat\_clear**](#function-listpairconnectionfloat_clear) (ListPairConnectionFloatHandle handle) <br> |
|  bool | [**ListPairConnectionFloat\_contains**](#function-listpairconnectionfloat_contains) (ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_copy**](#function-listpairconnectionfloat_copy) (ListPairConnectionFloatHandle handle) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_create**](#function-listpairconnectionfloat_create) (PairConnectionFloatHandle \* data, size\_t count) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_create\_empty**](#function-listpairconnectionfloat_create_empty) () <br> |
|  void | [**ListPairConnectionFloat\_destroy**](#function-listpairconnectionfloat_destroy) (ListPairConnectionFloatHandle handle) <br> |
|  bool | [**ListPairConnectionFloat\_empty**](#function-listpairconnectionfloat_empty) (ListPairConnectionFloatHandle handle) <br> |
|  bool | [**ListPairConnectionFloat\_equal**](#function-listpairconnectionfloat_equal) (ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other) <br> |
|  void | [**ListPairConnectionFloat\_erase\_at**](#function-listpairconnectionfloat_erase_at) (ListPairConnectionFloatHandle handle, size\_t idx) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_fill\_value**](#function-listpairconnectionfloat_fill_value) (size\_t count, PairConnectionFloatHandle value) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_from\_json\_string**](#function-listpairconnectionfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairConnectionFloat\_index**](#function-listpairconnectionfloat_index) (ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) <br> |
|  ListPairConnectionFloatHandle | [**ListPairConnectionFloat\_intersection**](#function-listpairconnectionfloat_intersection) (ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other) <br> |
|  size\_t | [**ListPairConnectionFloat\_items**](#function-listpairconnectionfloat_items) (ListPairConnectionFloatHandle handle, PairConnectionFloatHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairConnectionFloat\_not\_equal**](#function-listpairconnectionfloat_not_equal) (ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other) <br> |
|  void | [**ListPairConnectionFloat\_push\_back**](#function-listpairconnectionfloat_push_back) (ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value) <br> |
|  size\_t | [**ListPairConnectionFloat\_size**](#function-listpairconnectionfloat_size) (ListPairConnectionFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairConnectionFloat\_to\_json\_string**](#function-listpairconnectionfloat_to_json_string) (ListPairConnectionFloatHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairConnectionFloatHandle 

```C++
typedef void* ListPairConnectionFloatHandle;
```




<hr>
## Public Functions Documentation




### function ListPairConnectionFloat\_at 

```C++
PairConnectionFloatHandle ListPairConnectionFloat_at (
    ListPairConnectionFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionFloat\_clear 

```C++
void ListPairConnectionFloat_clear (
    ListPairConnectionFloatHandle handle
) 
```




<hr>



### function ListPairConnectionFloat\_contains 

```C++
bool ListPairConnectionFloat_contains (
    ListPairConnectionFloatHandle handle,
    PairConnectionFloatHandle value
) 
```




<hr>



### function ListPairConnectionFloat\_copy 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_copy (
    ListPairConnectionFloatHandle handle
) 
```




<hr>



### function ListPairConnectionFloat\_create 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_create (
    PairConnectionFloatHandle * data,
    size_t count
) 
```




<hr>



### function ListPairConnectionFloat\_create\_empty 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty () 
```




<hr>



### function ListPairConnectionFloat\_destroy 

```C++
void ListPairConnectionFloat_destroy (
    ListPairConnectionFloatHandle handle
) 
```




<hr>



### function ListPairConnectionFloat\_empty 

```C++
bool ListPairConnectionFloat_empty (
    ListPairConnectionFloatHandle handle
) 
```




<hr>



### function ListPairConnectionFloat\_equal 

```C++
bool ListPairConnectionFloat_equal (
    ListPairConnectionFloatHandle handle,
    ListPairConnectionFloatHandle other
) 
```




<hr>



### function ListPairConnectionFloat\_erase\_at 

```C++
void ListPairConnectionFloat_erase_at (
    ListPairConnectionFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionFloat\_fill\_value 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value (
    size_t count,
    PairConnectionFloatHandle value
) 
```




<hr>



### function ListPairConnectionFloat\_from\_json\_string 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairConnectionFloat\_index 

```C++
size_t ListPairConnectionFloat_index (
    ListPairConnectionFloatHandle handle,
    PairConnectionFloatHandle value
) 
```




<hr>



### function ListPairConnectionFloat\_intersection 

```C++
ListPairConnectionFloatHandle ListPairConnectionFloat_intersection (
    ListPairConnectionFloatHandle handle,
    ListPairConnectionFloatHandle other
) 
```




<hr>



### function ListPairConnectionFloat\_items 

```C++
size_t ListPairConnectionFloat_items (
    ListPairConnectionFloatHandle handle,
    PairConnectionFloatHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairConnectionFloat\_not\_equal 

```C++
bool ListPairConnectionFloat_not_equal (
    ListPairConnectionFloatHandle handle,
    ListPairConnectionFloatHandle other
) 
```




<hr>



### function ListPairConnectionFloat\_push\_back 

```C++
void ListPairConnectionFloat_push_back (
    ListPairConnectionFloatHandle handle,
    PairConnectionFloatHandle value
) 
```




<hr>



### function ListPairConnectionFloat\_size 

```C++
size_t ListPairConnectionFloat_size (
    ListPairConnectionFloatHandle handle
) 
```




<hr>



### function ListPairConnectionFloat\_to\_json\_string 

```C++
StringHandle ListPairConnectionFloat_to_json_string (
    ListPairConnectionFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairConnectionFloat_c_api.h`

