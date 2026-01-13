

# File ListPairStringBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairStringBool\_c\_api.h**](ListPairStringBool__c__api_8h.md)

[Go to the source code of this file](ListPairStringBool__c__api_8h_source.md)



* `#include "falcon_core/generic/PairStringBool_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairStringBoolHandle**](#typedef-listpairstringboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringBoolHandle | [**ListPairStringBool\_at**](#function-listpairstringbool_at) (ListPairStringBoolHandle handle, size\_t idx) <br> |
|  void | [**ListPairStringBool\_clear**](#function-listpairstringbool_clear) (ListPairStringBoolHandle handle) <br> |
|  bool | [**ListPairStringBool\_contains**](#function-listpairstringbool_contains) (ListPairStringBoolHandle handle, PairStringBoolHandle value) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_copy**](#function-listpairstringbool_copy) (ListPairStringBoolHandle handle) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_create**](#function-listpairstringbool_create) (PairStringBoolHandle \* data, size\_t count) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_create\_empty**](#function-listpairstringbool_create_empty) () <br> |
|  void | [**ListPairStringBool\_destroy**](#function-listpairstringbool_destroy) (ListPairStringBoolHandle handle) <br> |
|  bool | [**ListPairStringBool\_empty**](#function-listpairstringbool_empty) (ListPairStringBoolHandle handle) <br> |
|  bool | [**ListPairStringBool\_equal**](#function-listpairstringbool_equal) (ListPairStringBoolHandle handle, ListPairStringBoolHandle other) <br> |
|  void | [**ListPairStringBool\_erase\_at**](#function-listpairstringbool_erase_at) (ListPairStringBoolHandle handle, size\_t idx) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_fill\_value**](#function-listpairstringbool_fill_value) (size\_t count, PairStringBoolHandle value) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_from\_json\_string**](#function-listpairstringbool_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairStringBool\_index**](#function-listpairstringbool_index) (ListPairStringBoolHandle handle, PairStringBoolHandle value) <br> |
|  ListPairStringBoolHandle | [**ListPairStringBool\_intersection**](#function-listpairstringbool_intersection) (ListPairStringBoolHandle handle, ListPairStringBoolHandle other) <br> |
|  size\_t | [**ListPairStringBool\_items**](#function-listpairstringbool_items) (ListPairStringBoolHandle handle, PairStringBoolHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairStringBool\_not\_equal**](#function-listpairstringbool_not_equal) (ListPairStringBoolHandle handle, ListPairStringBoolHandle other) <br> |
|  void | [**ListPairStringBool\_push\_back**](#function-listpairstringbool_push_back) (ListPairStringBoolHandle handle, PairStringBoolHandle value) <br> |
|  size\_t | [**ListPairStringBool\_size**](#function-listpairstringbool_size) (ListPairStringBoolHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairStringBool\_to\_json\_string**](#function-listpairstringbool_to_json_string) (ListPairStringBoolHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairStringBoolHandle 

```C++
typedef void* ListPairStringBoolHandle;
```




<hr>
## Public Functions Documentation




### function ListPairStringBool\_at 

```C++
PairStringBoolHandle ListPairStringBool_at (
    ListPairStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringBool\_clear 

```C++
void ListPairStringBool_clear (
    ListPairStringBoolHandle handle
) 
```




<hr>



### function ListPairStringBool\_contains 

```C++
bool ListPairStringBool_contains (
    ListPairStringBoolHandle handle,
    PairStringBoolHandle value
) 
```




<hr>



### function ListPairStringBool\_copy 

```C++
ListPairStringBoolHandle ListPairStringBool_copy (
    ListPairStringBoolHandle handle
) 
```




<hr>



### function ListPairStringBool\_create 

```C++
ListPairStringBoolHandle ListPairStringBool_create (
    PairStringBoolHandle * data,
    size_t count
) 
```




<hr>



### function ListPairStringBool\_create\_empty 

```C++
ListPairStringBoolHandle ListPairStringBool_create_empty () 
```




<hr>



### function ListPairStringBool\_destroy 

```C++
void ListPairStringBool_destroy (
    ListPairStringBoolHandle handle
) 
```




<hr>



### function ListPairStringBool\_empty 

```C++
bool ListPairStringBool_empty (
    ListPairStringBoolHandle handle
) 
```




<hr>



### function ListPairStringBool\_equal 

```C++
bool ListPairStringBool_equal (
    ListPairStringBoolHandle handle,
    ListPairStringBoolHandle other
) 
```




<hr>



### function ListPairStringBool\_erase\_at 

```C++
void ListPairStringBool_erase_at (
    ListPairStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringBool\_fill\_value 

```C++
ListPairStringBoolHandle ListPairStringBool_fill_value (
    size_t count,
    PairStringBoolHandle value
) 
```




<hr>



### function ListPairStringBool\_from\_json\_string 

```C++
ListPairStringBoolHandle ListPairStringBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairStringBool\_index 

```C++
size_t ListPairStringBool_index (
    ListPairStringBoolHandle handle,
    PairStringBoolHandle value
) 
```




<hr>



### function ListPairStringBool\_intersection 

```C++
ListPairStringBoolHandle ListPairStringBool_intersection (
    ListPairStringBoolHandle handle,
    ListPairStringBoolHandle other
) 
```




<hr>



### function ListPairStringBool\_items 

```C++
size_t ListPairStringBool_items (
    ListPairStringBoolHandle handle,
    PairStringBoolHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairStringBool\_not\_equal 

```C++
bool ListPairStringBool_not_equal (
    ListPairStringBoolHandle handle,
    ListPairStringBoolHandle other
) 
```




<hr>



### function ListPairStringBool\_push\_back 

```C++
void ListPairStringBool_push_back (
    ListPairStringBoolHandle handle,
    PairStringBoolHandle value
) 
```




<hr>



### function ListPairStringBool\_size 

```C++
size_t ListPairStringBool_size (
    ListPairStringBoolHandle handle
) 
```




<hr>



### function ListPairStringBool\_to\_json\_string 

```C++
StringHandle ListPairStringBool_to_json_string (
    ListPairStringBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairStringBool_c_api.h`

