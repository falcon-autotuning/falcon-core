

# File ListPairIntFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairIntFloat\_c\_api.h**](ListPairIntFloat__c__api_8h.md)

[Go to the source code of this file](ListPairIntFloat__c__api_8h_source.md)



* `#include "falcon_core/generic/PairIntFloat_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairIntFloatHandle**](#typedef-listpairintfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairIntFloatHandle | [**ListPairIntFloat\_at**](#function-listpairintfloat_at) (ListPairIntFloatHandle handle, size\_t idx) <br> |
|  void | [**ListPairIntFloat\_clear**](#function-listpairintfloat_clear) (ListPairIntFloatHandle handle) <br> |
|  bool | [**ListPairIntFloat\_contains**](#function-listpairintfloat_contains) (ListPairIntFloatHandle handle, PairIntFloatHandle value) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_copy**](#function-listpairintfloat_copy) (ListPairIntFloatHandle handle) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_create**](#function-listpairintfloat_create) (PairIntFloatHandle \* data, size\_t count) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_create\_empty**](#function-listpairintfloat_create_empty) () <br> |
|  void | [**ListPairIntFloat\_destroy**](#function-listpairintfloat_destroy) (ListPairIntFloatHandle handle) <br> |
|  bool | [**ListPairIntFloat\_empty**](#function-listpairintfloat_empty) (ListPairIntFloatHandle handle) <br> |
|  bool | [**ListPairIntFloat\_equal**](#function-listpairintfloat_equal) (ListPairIntFloatHandle handle, ListPairIntFloatHandle other) <br> |
|  void | [**ListPairIntFloat\_erase\_at**](#function-listpairintfloat_erase_at) (ListPairIntFloatHandle handle, size\_t idx) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_fill\_value**](#function-listpairintfloat_fill_value) (size\_t count, PairIntFloatHandle value) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_from\_json\_string**](#function-listpairintfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairIntFloat\_index**](#function-listpairintfloat_index) (ListPairIntFloatHandle handle, PairIntFloatHandle value) <br> |
|  ListPairIntFloatHandle | [**ListPairIntFloat\_intersection**](#function-listpairintfloat_intersection) (ListPairIntFloatHandle handle, ListPairIntFloatHandle other) <br> |
|  size\_t | [**ListPairIntFloat\_items**](#function-listpairintfloat_items) (ListPairIntFloatHandle handle, PairIntFloatHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairIntFloat\_not\_equal**](#function-listpairintfloat_not_equal) (ListPairIntFloatHandle handle, ListPairIntFloatHandle other) <br> |
|  void | [**ListPairIntFloat\_push\_back**](#function-listpairintfloat_push_back) (ListPairIntFloatHandle handle, PairIntFloatHandle value) <br> |
|  size\_t | [**ListPairIntFloat\_size**](#function-listpairintfloat_size) (ListPairIntFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairIntFloat\_to\_json\_string**](#function-listpairintfloat_to_json_string) (ListPairIntFloatHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairIntFloatHandle 

```C++
typedef void* ListPairIntFloatHandle;
```




<hr>
## Public Functions Documentation




### function ListPairIntFloat\_at 

```C++
PairIntFloatHandle ListPairIntFloat_at (
    ListPairIntFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairIntFloat\_clear 

```C++
void ListPairIntFloat_clear (
    ListPairIntFloatHandle handle
) 
```




<hr>



### function ListPairIntFloat\_contains 

```C++
bool ListPairIntFloat_contains (
    ListPairIntFloatHandle handle,
    PairIntFloatHandle value
) 
```




<hr>



### function ListPairIntFloat\_copy 

```C++
ListPairIntFloatHandle ListPairIntFloat_copy (
    ListPairIntFloatHandle handle
) 
```




<hr>



### function ListPairIntFloat\_create 

```C++
ListPairIntFloatHandle ListPairIntFloat_create (
    PairIntFloatHandle * data,
    size_t count
) 
```




<hr>



### function ListPairIntFloat\_create\_empty 

```C++
ListPairIntFloatHandle ListPairIntFloat_create_empty () 
```




<hr>



### function ListPairIntFloat\_destroy 

```C++
void ListPairIntFloat_destroy (
    ListPairIntFloatHandle handle
) 
```




<hr>



### function ListPairIntFloat\_empty 

```C++
bool ListPairIntFloat_empty (
    ListPairIntFloatHandle handle
) 
```




<hr>



### function ListPairIntFloat\_equal 

```C++
bool ListPairIntFloat_equal (
    ListPairIntFloatHandle handle,
    ListPairIntFloatHandle other
) 
```




<hr>



### function ListPairIntFloat\_erase\_at 

```C++
void ListPairIntFloat_erase_at (
    ListPairIntFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairIntFloat\_fill\_value 

```C++
ListPairIntFloatHandle ListPairIntFloat_fill_value (
    size_t count,
    PairIntFloatHandle value
) 
```




<hr>



### function ListPairIntFloat\_from\_json\_string 

```C++
ListPairIntFloatHandle ListPairIntFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairIntFloat\_index 

```C++
size_t ListPairIntFloat_index (
    ListPairIntFloatHandle handle,
    PairIntFloatHandle value
) 
```




<hr>



### function ListPairIntFloat\_intersection 

```C++
ListPairIntFloatHandle ListPairIntFloat_intersection (
    ListPairIntFloatHandle handle,
    ListPairIntFloatHandle other
) 
```




<hr>



### function ListPairIntFloat\_items 

```C++
size_t ListPairIntFloat_items (
    ListPairIntFloatHandle handle,
    PairIntFloatHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairIntFloat\_not\_equal 

```C++
bool ListPairIntFloat_not_equal (
    ListPairIntFloatHandle handle,
    ListPairIntFloatHandle other
) 
```




<hr>



### function ListPairIntFloat\_push\_back 

```C++
void ListPairIntFloat_push_back (
    ListPairIntFloatHandle handle,
    PairIntFloatHandle value
) 
```




<hr>



### function ListPairIntFloat\_size 

```C++
size_t ListPairIntFloat_size (
    ListPairIntFloatHandle handle
) 
```




<hr>



### function ListPairIntFloat\_to\_json\_string 

```C++
StringHandle ListPairIntFloat_to_json_string (
    ListPairIntFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairIntFloat_c_api.h`

