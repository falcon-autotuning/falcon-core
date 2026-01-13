

# File ListPairInterpretationContextString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairInterpretationContextString\_c\_api.h**](ListPairInterpretationContextString__c__api_8h.md)

[Go to the source code of this file](ListPairInterpretationContextString__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextString_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairInterpretationContextStringHandle**](#typedef-listpairinterpretationcontextstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_at**](#function-listpairinterpretationcontextstring_at) (ListPairInterpretationContextStringHandle handle, size\_t idx) <br> |
|  void | [**ListPairInterpretationContextString\_clear**](#function-listpairinterpretationcontextstring_clear) (ListPairInterpretationContextStringHandle handle) <br> |
|  bool | [**ListPairInterpretationContextString\_contains**](#function-listpairinterpretationcontextstring_contains) (ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_copy**](#function-listpairinterpretationcontextstring_copy) (ListPairInterpretationContextStringHandle handle) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_create**](#function-listpairinterpretationcontextstring_create) (PairInterpretationContextStringHandle \* data, size\_t count) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_create\_empty**](#function-listpairinterpretationcontextstring_create_empty) () <br> |
|  void | [**ListPairInterpretationContextString\_destroy**](#function-listpairinterpretationcontextstring_destroy) (ListPairInterpretationContextStringHandle handle) <br> |
|  bool | [**ListPairInterpretationContextString\_empty**](#function-listpairinterpretationcontextstring_empty) (ListPairInterpretationContextStringHandle handle) <br> |
|  bool | [**ListPairInterpretationContextString\_equal**](#function-listpairinterpretationcontextstring_equal) (ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other) <br> |
|  void | [**ListPairInterpretationContextString\_erase\_at**](#function-listpairinterpretationcontextstring_erase_at) (ListPairInterpretationContextStringHandle handle, size\_t idx) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_fill\_value**](#function-listpairinterpretationcontextstring_fill_value) (size\_t count, PairInterpretationContextStringHandle value) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_from\_json\_string**](#function-listpairinterpretationcontextstring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairInterpretationContextString\_index**](#function-listpairinterpretationcontextstring_index) (ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) <br> |
|  ListPairInterpretationContextStringHandle | [**ListPairInterpretationContextString\_intersection**](#function-listpairinterpretationcontextstring_intersection) (ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other) <br> |
|  size\_t | [**ListPairInterpretationContextString\_items**](#function-listpairinterpretationcontextstring_items) (ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairInterpretationContextString\_not\_equal**](#function-listpairinterpretationcontextstring_not_equal) (ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other) <br> |
|  void | [**ListPairInterpretationContextString\_push\_back**](#function-listpairinterpretationcontextstring_push_back) (ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value) <br> |
|  size\_t | [**ListPairInterpretationContextString\_size**](#function-listpairinterpretationcontextstring_size) (ListPairInterpretationContextStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairInterpretationContextString\_to\_json\_string**](#function-listpairinterpretationcontextstring_to_json_string) (ListPairInterpretationContextStringHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairInterpretationContextStringHandle 

```C++
typedef void* ListPairInterpretationContextStringHandle;
```




<hr>
## Public Functions Documentation




### function ListPairInterpretationContextString\_at 

```C++
PairInterpretationContextStringHandle ListPairInterpretationContextString_at (
    ListPairInterpretationContextStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextString\_clear 

```C++
void ListPairInterpretationContextString_clear (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>



### function ListPairInterpretationContextString\_contains 

```C++
bool ListPairInterpretationContextString_contains (
    ListPairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle value
) 
```




<hr>



### function ListPairInterpretationContextString\_copy 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_copy (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>



### function ListPairInterpretationContextString\_create 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create (
    PairInterpretationContextStringHandle * data,
    size_t count
) 
```




<hr>



### function ListPairInterpretationContextString\_create\_empty 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty () 
```




<hr>



### function ListPairInterpretationContextString\_destroy 

```C++
void ListPairInterpretationContextString_destroy (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>



### function ListPairInterpretationContextString\_empty 

```C++
bool ListPairInterpretationContextString_empty (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>



### function ListPairInterpretationContextString\_equal 

```C++
bool ListPairInterpretationContextString_equal (
    ListPairInterpretationContextStringHandle handle,
    ListPairInterpretationContextStringHandle other
) 
```




<hr>



### function ListPairInterpretationContextString\_erase\_at 

```C++
void ListPairInterpretationContextString_erase_at (
    ListPairInterpretationContextStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextString\_fill\_value 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value (
    size_t count,
    PairInterpretationContextStringHandle value
) 
```




<hr>



### function ListPairInterpretationContextString\_from\_json\_string 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairInterpretationContextString\_index 

```C++
size_t ListPairInterpretationContextString_index (
    ListPairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle value
) 
```




<hr>



### function ListPairInterpretationContextString\_intersection 

```C++
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection (
    ListPairInterpretationContextStringHandle handle,
    ListPairInterpretationContextStringHandle other
) 
```




<hr>



### function ListPairInterpretationContextString\_items 

```C++
size_t ListPairInterpretationContextString_items (
    ListPairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairInterpretationContextString\_not\_equal 

```C++
bool ListPairInterpretationContextString_not_equal (
    ListPairInterpretationContextStringHandle handle,
    ListPairInterpretationContextStringHandle other
) 
```




<hr>



### function ListPairInterpretationContextString\_push\_back 

```C++
void ListPairInterpretationContextString_push_back (
    ListPairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle value
) 
```




<hr>



### function ListPairInterpretationContextString\_size 

```C++
size_t ListPairInterpretationContextString_size (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>



### function ListPairInterpretationContextString\_to\_json\_string 

```C++
StringHandle ListPairInterpretationContextString_to_json_string (
    ListPairInterpretationContextStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairInterpretationContextString_c_api.h`

