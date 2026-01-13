

# File ListPairFloatFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairFloatFloat\_c\_api.h**](ListPairFloatFloat__c__api_8h.md)

[Go to the source code of this file](ListPairFloatFloat__c__api_8h_source.md)



* `#include "falcon_core/generic/PairFloatFloat_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairFloatFloatHandle**](#typedef-listpairfloatfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairFloatFloatHandle | [**ListPairFloatFloat\_at**](#function-listpairfloatfloat_at) (ListPairFloatFloatHandle handle, size\_t idx) <br> |
|  void | [**ListPairFloatFloat\_clear**](#function-listpairfloatfloat_clear) (ListPairFloatFloatHandle handle) <br> |
|  bool | [**ListPairFloatFloat\_contains**](#function-listpairfloatfloat_contains) (ListPairFloatFloatHandle handle, PairFloatFloatHandle value) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_copy**](#function-listpairfloatfloat_copy) (ListPairFloatFloatHandle handle) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_create**](#function-listpairfloatfloat_create) (PairFloatFloatHandle \* data, size\_t count) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_create\_empty**](#function-listpairfloatfloat_create_empty) () <br> |
|  void | [**ListPairFloatFloat\_destroy**](#function-listpairfloatfloat_destroy) (ListPairFloatFloatHandle handle) <br> |
|  bool | [**ListPairFloatFloat\_empty**](#function-listpairfloatfloat_empty) (ListPairFloatFloatHandle handle) <br> |
|  bool | [**ListPairFloatFloat\_equal**](#function-listpairfloatfloat_equal) (ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) <br> |
|  void | [**ListPairFloatFloat\_erase\_at**](#function-listpairfloatfloat_erase_at) (ListPairFloatFloatHandle handle, size\_t idx) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_fill\_value**](#function-listpairfloatfloat_fill_value) (size\_t count, PairFloatFloatHandle value) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_from\_json\_string**](#function-listpairfloatfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairFloatFloat\_index**](#function-listpairfloatfloat_index) (ListPairFloatFloatHandle handle, PairFloatFloatHandle value) <br> |
|  ListPairFloatFloatHandle | [**ListPairFloatFloat\_intersection**](#function-listpairfloatfloat_intersection) (ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) <br> |
|  size\_t | [**ListPairFloatFloat\_items**](#function-listpairfloatfloat_items) (ListPairFloatFloatHandle handle, PairFloatFloatHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairFloatFloat\_not\_equal**](#function-listpairfloatfloat_not_equal) (ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) <br> |
|  void | [**ListPairFloatFloat\_push\_back**](#function-listpairfloatfloat_push_back) (ListPairFloatFloatHandle handle, PairFloatFloatHandle value) <br> |
|  size\_t | [**ListPairFloatFloat\_size**](#function-listpairfloatfloat_size) (ListPairFloatFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairFloatFloat\_to\_json\_string**](#function-listpairfloatfloat_to_json_string) (ListPairFloatFloatHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairFloatFloatHandle 

```C++
typedef void* ListPairFloatFloatHandle;
```




<hr>
## Public Functions Documentation




### function ListPairFloatFloat\_at 

```C++
PairFloatFloatHandle ListPairFloatFloat_at (
    ListPairFloatFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairFloatFloat\_clear 

```C++
void ListPairFloatFloat_clear (
    ListPairFloatFloatHandle handle
) 
```




<hr>



### function ListPairFloatFloat\_contains 

```C++
bool ListPairFloatFloat_contains (
    ListPairFloatFloatHandle handle,
    PairFloatFloatHandle value
) 
```




<hr>



### function ListPairFloatFloat\_copy 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_copy (
    ListPairFloatFloatHandle handle
) 
```




<hr>



### function ListPairFloatFloat\_create 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_create (
    PairFloatFloatHandle * data,
    size_t count
) 
```




<hr>



### function ListPairFloatFloat\_create\_empty 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_create_empty () 
```




<hr>



### function ListPairFloatFloat\_destroy 

```C++
void ListPairFloatFloat_destroy (
    ListPairFloatFloatHandle handle
) 
```




<hr>



### function ListPairFloatFloat\_empty 

```C++
bool ListPairFloatFloat_empty (
    ListPairFloatFloatHandle handle
) 
```




<hr>



### function ListPairFloatFloat\_equal 

```C++
bool ListPairFloatFloat_equal (
    ListPairFloatFloatHandle handle,
    ListPairFloatFloatHandle other
) 
```




<hr>



### function ListPairFloatFloat\_erase\_at 

```C++
void ListPairFloatFloat_erase_at (
    ListPairFloatFloatHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairFloatFloat\_fill\_value 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_fill_value (
    size_t count,
    PairFloatFloatHandle value
) 
```




<hr>



### function ListPairFloatFloat\_from\_json\_string 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairFloatFloat\_index 

```C++
size_t ListPairFloatFloat_index (
    ListPairFloatFloatHandle handle,
    PairFloatFloatHandle value
) 
```




<hr>



### function ListPairFloatFloat\_intersection 

```C++
ListPairFloatFloatHandle ListPairFloatFloat_intersection (
    ListPairFloatFloatHandle handle,
    ListPairFloatFloatHandle other
) 
```




<hr>



### function ListPairFloatFloat\_items 

```C++
size_t ListPairFloatFloat_items (
    ListPairFloatFloatHandle handle,
    PairFloatFloatHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairFloatFloat\_not\_equal 

```C++
bool ListPairFloatFloat_not_equal (
    ListPairFloatFloatHandle handle,
    ListPairFloatFloatHandle other
) 
```




<hr>



### function ListPairFloatFloat\_push\_back 

```C++
void ListPairFloatFloat_push_back (
    ListPairFloatFloatHandle handle,
    PairFloatFloatHandle value
) 
```




<hr>



### function ListPairFloatFloat\_size 

```C++
size_t ListPairFloatFloat_size (
    ListPairFloatFloatHandle handle
) 
```




<hr>



### function ListPairFloatFloat\_to\_json\_string 

```C++
StringHandle ListPairFloatFloat_to_json_string (
    ListPairFloatFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairFloatFloat_c_api.h`

