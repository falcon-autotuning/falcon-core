

# File ListPairInterpretationContextDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairInterpretationContextDouble\_c\_api.h**](ListPairInterpretationContextDouble__c__api_8h.md)

[Go to the source code of this file](ListPairInterpretationContextDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairInterpretationContextDoubleHandle**](#typedef-listpairinterpretationcontextdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_at**](#function-listpairinterpretationcontextdouble_at) (ListPairInterpretationContextDoubleHandle handle, size\_t idx) <br> |
|  void | [**ListPairInterpretationContextDouble\_clear**](#function-listpairinterpretationcontextdouble_clear) (ListPairInterpretationContextDoubleHandle handle) <br> |
|  bool | [**ListPairInterpretationContextDouble\_contains**](#function-listpairinterpretationcontextdouble_contains) (ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_copy**](#function-listpairinterpretationcontextdouble_copy) (ListPairInterpretationContextDoubleHandle handle) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_create**](#function-listpairinterpretationcontextdouble_create) (PairInterpretationContextDoubleHandle \* data, size\_t count) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_create\_empty**](#function-listpairinterpretationcontextdouble_create_empty) () <br> |
|  void | [**ListPairInterpretationContextDouble\_destroy**](#function-listpairinterpretationcontextdouble_destroy) (ListPairInterpretationContextDoubleHandle handle) <br> |
|  bool | [**ListPairInterpretationContextDouble\_empty**](#function-listpairinterpretationcontextdouble_empty) (ListPairInterpretationContextDoubleHandle handle) <br> |
|  bool | [**ListPairInterpretationContextDouble\_equal**](#function-listpairinterpretationcontextdouble_equal) (ListPairInterpretationContextDoubleHandle handle, ListPairInterpretationContextDoubleHandle other) <br> |
|  void | [**ListPairInterpretationContextDouble\_erase\_at**](#function-listpairinterpretationcontextdouble_erase_at) (ListPairInterpretationContextDoubleHandle handle, size\_t idx) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_fill\_value**](#function-listpairinterpretationcontextdouble_fill_value) (size\_t count, PairInterpretationContextDoubleHandle value) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_from\_json\_string**](#function-listpairinterpretationcontextdouble_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairInterpretationContextDouble\_index**](#function-listpairinterpretationcontextdouble_index) (ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) <br> |
|  ListPairInterpretationContextDoubleHandle | [**ListPairInterpretationContextDouble\_intersection**](#function-listpairinterpretationcontextdouble_intersection) (ListPairInterpretationContextDoubleHandle handle, ListPairInterpretationContextDoubleHandle other) <br> |
|  size\_t | [**ListPairInterpretationContextDouble\_items**](#function-listpairinterpretationcontextdouble_items) (ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairInterpretationContextDouble\_not\_equal**](#function-listpairinterpretationcontextdouble_not_equal) (ListPairInterpretationContextDoubleHandle handle, ListPairInterpretationContextDoubleHandle other) <br> |
|  void | [**ListPairInterpretationContextDouble\_push\_back**](#function-listpairinterpretationcontextdouble_push_back) (ListPairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle value) <br> |
|  size\_t | [**ListPairInterpretationContextDouble\_size**](#function-listpairinterpretationcontextdouble_size) (ListPairInterpretationContextDoubleHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairInterpretationContextDouble\_to\_json\_string**](#function-listpairinterpretationcontextdouble_to_json_string) (ListPairInterpretationContextDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairInterpretationContextDoubleHandle 

```C++
typedef void* ListPairInterpretationContextDoubleHandle;
```




<hr>
## Public Functions Documentation




### function ListPairInterpretationContextDouble\_at 

```C++
PairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_at (
    ListPairInterpretationContextDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextDouble\_clear 

```C++
void ListPairInterpretationContextDouble_clear (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function ListPairInterpretationContextDouble\_contains 

```C++
bool ListPairInterpretationContextDouble_contains (
    ListPairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle value
) 
```




<hr>



### function ListPairInterpretationContextDouble\_copy 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_copy (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function ListPairInterpretationContextDouble\_create 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create (
    PairInterpretationContextDoubleHandle * data,
    size_t count
) 
```




<hr>



### function ListPairInterpretationContextDouble\_create\_empty 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_create_empty () 
```




<hr>



### function ListPairInterpretationContextDouble\_destroy 

```C++
void ListPairInterpretationContextDouble_destroy (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function ListPairInterpretationContextDouble\_empty 

```C++
bool ListPairInterpretationContextDouble_empty (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function ListPairInterpretationContextDouble\_equal 

```C++
bool ListPairInterpretationContextDouble_equal (
    ListPairInterpretationContextDoubleHandle handle,
    ListPairInterpretationContextDoubleHandle other
) 
```




<hr>



### function ListPairInterpretationContextDouble\_erase\_at 

```C++
void ListPairInterpretationContextDouble_erase_at (
    ListPairInterpretationContextDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextDouble\_fill\_value 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_fill_value (
    size_t count,
    PairInterpretationContextDoubleHandle value
) 
```




<hr>



### function ListPairInterpretationContextDouble\_from\_json\_string 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairInterpretationContextDouble\_index 

```C++
size_t ListPairInterpretationContextDouble_index (
    ListPairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle value
) 
```




<hr>



### function ListPairInterpretationContextDouble\_intersection 

```C++
ListPairInterpretationContextDoubleHandle ListPairInterpretationContextDouble_intersection (
    ListPairInterpretationContextDoubleHandle handle,
    ListPairInterpretationContextDoubleHandle other
) 
```




<hr>



### function ListPairInterpretationContextDouble\_items 

```C++
size_t ListPairInterpretationContextDouble_items (
    ListPairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairInterpretationContextDouble\_not\_equal 

```C++
bool ListPairInterpretationContextDouble_not_equal (
    ListPairInterpretationContextDoubleHandle handle,
    ListPairInterpretationContextDoubleHandle other
) 
```




<hr>



### function ListPairInterpretationContextDouble\_push\_back 

```C++
void ListPairInterpretationContextDouble_push_back (
    ListPairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle value
) 
```




<hr>



### function ListPairInterpretationContextDouble\_size 

```C++
size_t ListPairInterpretationContextDouble_size (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function ListPairInterpretationContextDouble\_to\_json\_string 

```C++
StringHandle ListPairInterpretationContextDouble_to_json_string (
    ListPairInterpretationContextDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairInterpretationContextDouble_c_api.h`

