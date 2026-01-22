

# File ListPairStringString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairStringString\_c\_api.h**](ListPairStringString__c__api_8h.md)

[Go to the source code of this file](ListPairStringString__c__api_8h_source.md)



* `#include "falcon_core/generic/PairStringString_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairStringStringHandle**](#typedef-listpairstringstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringStringHandle | [**ListPairStringString\_at**](#function-listpairstringstring_at) (ListPairStringStringHandle handle, size\_t idx) <br> |
|  void | [**ListPairStringString\_clear**](#function-listpairstringstring_clear) (ListPairStringStringHandle handle) <br> |
|  bool | [**ListPairStringString\_contains**](#function-listpairstringstring_contains) (ListPairStringStringHandle handle, PairStringStringHandle value) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_copy**](#function-listpairstringstring_copy) (ListPairStringStringHandle handle) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_create**](#function-listpairstringstring_create) (PairStringStringHandle \* data, size\_t count) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_create\_empty**](#function-listpairstringstring_create_empty) () <br> |
|  void | [**ListPairStringString\_destroy**](#function-listpairstringstring_destroy) (ListPairStringStringHandle handle) <br> |
|  bool | [**ListPairStringString\_empty**](#function-listpairstringstring_empty) (ListPairStringStringHandle handle) <br> |
|  bool | [**ListPairStringString\_equal**](#function-listpairstringstring_equal) (ListPairStringStringHandle handle, ListPairStringStringHandle other) <br> |
|  void | [**ListPairStringString\_erase\_at**](#function-listpairstringstring_erase_at) (ListPairStringStringHandle handle, size\_t idx) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_fill\_value**](#function-listpairstringstring_fill_value) (size\_t count, PairStringStringHandle value) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_from\_json\_string**](#function-listpairstringstring_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListPairStringString\_index**](#function-listpairstringstring_index) (ListPairStringStringHandle handle, PairStringStringHandle value) <br> |
|  ListPairStringStringHandle | [**ListPairStringString\_intersection**](#function-listpairstringstring_intersection) (ListPairStringStringHandle handle, ListPairStringStringHandle other) <br> |
|  size\_t | [**ListPairStringString\_items**](#function-listpairstringstring_items) (ListPairStringStringHandle handle, PairStringStringHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairStringString\_not\_equal**](#function-listpairstringstring_not_equal) (ListPairStringStringHandle handle, ListPairStringStringHandle other) <br> |
|  void | [**ListPairStringString\_push\_back**](#function-listpairstringstring_push_back) (ListPairStringStringHandle handle, PairStringStringHandle value) <br> |
|  size\_t | [**ListPairStringString\_size**](#function-listpairstringstring_size) (ListPairStringStringHandle handle) <br> |
|  StringHandle | [**ListPairStringString\_to\_json\_string**](#function-listpairstringstring_to_json_string) (ListPairStringStringHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairStringStringHandle 

```C++
typedef void* ListPairStringStringHandle;
```




<hr>
## Public Functions Documentation




### function ListPairStringString\_at 

```C++
PairStringStringHandle ListPairStringString_at (
    ListPairStringStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringString\_clear 

```C++
void ListPairStringString_clear (
    ListPairStringStringHandle handle
) 
```




<hr>



### function ListPairStringString\_contains 

```C++
bool ListPairStringString_contains (
    ListPairStringStringHandle handle,
    PairStringStringHandle value
) 
```




<hr>



### function ListPairStringString\_copy 

```C++
ListPairStringStringHandle ListPairStringString_copy (
    ListPairStringStringHandle handle
) 
```




<hr>



### function ListPairStringString\_create 

```C++
ListPairStringStringHandle ListPairStringString_create (
    PairStringStringHandle * data,
    size_t count
) 
```




<hr>



### function ListPairStringString\_create\_empty 

```C++
ListPairStringStringHandle ListPairStringString_create_empty () 
```




<hr>



### function ListPairStringString\_destroy 

```C++
void ListPairStringString_destroy (
    ListPairStringStringHandle handle
) 
```




<hr>



### function ListPairStringString\_empty 

```C++
bool ListPairStringString_empty (
    ListPairStringStringHandle handle
) 
```




<hr>



### function ListPairStringString\_equal 

```C++
bool ListPairStringString_equal (
    ListPairStringStringHandle handle,
    ListPairStringStringHandle other
) 
```




<hr>



### function ListPairStringString\_erase\_at 

```C++
void ListPairStringString_erase_at (
    ListPairStringStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairStringString\_fill\_value 

```C++
ListPairStringStringHandle ListPairStringString_fill_value (
    size_t count,
    PairStringStringHandle value
) 
```




<hr>



### function ListPairStringString\_from\_json\_string 

```C++
ListPairStringStringHandle ListPairStringString_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairStringString\_index 

```C++
size_t ListPairStringString_index (
    ListPairStringStringHandle handle,
    PairStringStringHandle value
) 
```




<hr>



### function ListPairStringString\_intersection 

```C++
ListPairStringStringHandle ListPairStringString_intersection (
    ListPairStringStringHandle handle,
    ListPairStringStringHandle other
) 
```




<hr>



### function ListPairStringString\_items 

```C++
size_t ListPairStringString_items (
    ListPairStringStringHandle handle,
    PairStringStringHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairStringString\_not\_equal 

```C++
bool ListPairStringString_not_equal (
    ListPairStringStringHandle handle,
    ListPairStringStringHandle other
) 
```




<hr>



### function ListPairStringString\_push\_back 

```C++
void ListPairStringString_push_back (
    ListPairStringStringHandle handle,
    PairStringStringHandle value
) 
```




<hr>



### function ListPairStringString\_size 

```C++
size_t ListPairStringString_size (
    ListPairStringStringHandle handle
) 
```




<hr>



### function ListPairStringString\_to\_json\_string 

```C++
StringHandle ListPairStringString_to_json_string (
    ListPairStringStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairStringString_c_api.h`

