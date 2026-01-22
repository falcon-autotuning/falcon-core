

# File ListPairStringDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairStringDouble\_c\_api.h**](ListPairStringDouble__c__api_8h.md)

[Go to the source code of this file](ListPairStringDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/PairStringDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairStringDoubleHandle**](#typedef-listpairstringdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringDoubleHandle | [**ListPairStringDouble\_at**](#function-listpairstringdouble_at) (ListPairStringDoubleHandle handle, size\_t idx) <br> |
|  void | [**ListPairStringDouble\_clear**](#function-listpairstringdouble_clear) (ListPairStringDoubleHandle handle) <br> |
|  bool | [**ListPairStringDouble\_contains**](#function-listpairstringdouble_contains) (ListPairStringDoubleHandle handle, PairStringDoubleHandle value) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_copy**](#function-listpairstringdouble_copy) (ListPairStringDoubleHandle handle) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_create**](#function-listpairstringdouble_create) (PairStringDoubleHandle \* data, size\_t count) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_create\_empty**](#function-listpairstringdouble_create_empty) () <br> |
|  void | [**ListPairStringDouble\_destroy**](#function-listpairstringdouble_destroy) (ListPairStringDoubleHandle handle) <br> |
|  bool | [**ListPairStringDouble\_empty**](#function-listpairstringdouble_empty) (ListPairStringDoubleHandle handle) <br> |
|  bool | [**ListPairStringDouble\_equal**](#function-listpairstringdouble_equal) (ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) <br> |
|  void | [**ListPairStringDouble\_erase\_at**](#function-listpairstringdouble_erase_at) (ListPairStringDoubleHandle handle, size\_t idx) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_fill\_value**](#function-listpairstringdouble_fill_value) (size\_t count, PairStringDoubleHandle value) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_from\_json\_string**](#function-listpairstringdouble_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListPairStringDouble\_index**](#function-listpairstringdouble_index) (ListPairStringDoubleHandle handle, PairStringDoubleHandle value) <br> |
|  ListPairStringDoubleHandle | [**ListPairStringDouble\_intersection**](#function-listpairstringdouble_intersection) (ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) <br> |
|  size\_t | [**ListPairStringDouble\_items**](#function-listpairstringdouble_items) (ListPairStringDoubleHandle handle, PairStringDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairStringDouble\_not\_equal**](#function-listpairstringdouble_not_equal) (ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other) <br> |
|  void | [**ListPairStringDouble\_push\_back**](#function-listpairstringdouble_push_back) (ListPairStringDoubleHandle handle, PairStringDoubleHandle value) <br> |
|  size\_t | [**ListPairStringDouble\_size**](#function-listpairstringdouble_size) (ListPairStringDoubleHandle handle) <br> |
|  StringHandle | [**ListPairStringDouble\_to\_json\_string**](#function-listpairstringdouble_to_json_string) (ListPairStringDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairStringDoubleHandle 

```C++
typedef void* ListPairStringDoubleHandle;
```




<hr>
## Public Functions Documentation




### function ListPairStringDouble\_at 

```C++
PairStringDoubleHandle ListPairStringDouble_at (
    ListPairStringDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringDouble\_clear 

```C++
void ListPairStringDouble_clear (
    ListPairStringDoubleHandle handle
) 
```




<hr>



### function ListPairStringDouble\_contains 

```C++
bool ListPairStringDouble_contains (
    ListPairStringDoubleHandle handle,
    PairStringDoubleHandle value
) 
```




<hr>



### function ListPairStringDouble\_copy 

```C++
ListPairStringDoubleHandle ListPairStringDouble_copy (
    ListPairStringDoubleHandle handle
) 
```




<hr>



### function ListPairStringDouble\_create 

```C++
ListPairStringDoubleHandle ListPairStringDouble_create (
    PairStringDoubleHandle * data,
    size_t count
) 
```




<hr>



### function ListPairStringDouble\_create\_empty 

```C++
ListPairStringDoubleHandle ListPairStringDouble_create_empty () 
```




<hr>



### function ListPairStringDouble\_destroy 

```C++
void ListPairStringDouble_destroy (
    ListPairStringDoubleHandle handle
) 
```




<hr>



### function ListPairStringDouble\_empty 

```C++
bool ListPairStringDouble_empty (
    ListPairStringDoubleHandle handle
) 
```




<hr>



### function ListPairStringDouble\_equal 

```C++
bool ListPairStringDouble_equal (
    ListPairStringDoubleHandle handle,
    ListPairStringDoubleHandle other
) 
```




<hr>



### function ListPairStringDouble\_erase\_at 

```C++
void ListPairStringDouble_erase_at (
    ListPairStringDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringDouble\_fill\_value 

```C++
ListPairStringDoubleHandle ListPairStringDouble_fill_value (
    size_t count,
    PairStringDoubleHandle value
) 
```




<hr>



### function ListPairStringDouble\_from\_json\_string 

```C++
ListPairStringDoubleHandle ListPairStringDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairStringDouble\_index 

```C++
size_t ListPairStringDouble_index (
    ListPairStringDoubleHandle handle,
    PairStringDoubleHandle value
) 
```




<hr>



### function ListPairStringDouble\_intersection 

```C++
ListPairStringDoubleHandle ListPairStringDouble_intersection (
    ListPairStringDoubleHandle handle,
    ListPairStringDoubleHandle other
) 
```




<hr>



### function ListPairStringDouble\_items 

```C++
size_t ListPairStringDouble_items (
    ListPairStringDoubleHandle handle,
    PairStringDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairStringDouble\_not\_equal 

```C++
bool ListPairStringDouble_not_equal (
    ListPairStringDoubleHandle handle,
    ListPairStringDoubleHandle other
) 
```




<hr>



### function ListPairStringDouble\_push\_back 

```C++
void ListPairStringDouble_push_back (
    ListPairStringDoubleHandle handle,
    PairStringDoubleHandle value
) 
```




<hr>



### function ListPairStringDouble\_size 

```C++
size_t ListPairStringDouble_size (
    ListPairStringDoubleHandle handle
) 
```




<hr>



### function ListPairStringDouble\_to\_json\_string 

```C++
StringHandle ListPairStringDouble_to_json_string (
    ListPairStringDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairStringDouble_c_api.h`

