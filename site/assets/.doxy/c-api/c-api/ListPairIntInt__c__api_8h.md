

# File ListPairIntInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairIntInt\_c\_api.h**](ListPairIntInt__c__api_8h.md)

[Go to the source code of this file](ListPairIntInt__c__api_8h_source.md)



* `#include "falcon_core/generic/PairIntInt_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairIntIntHandle**](#typedef-listpairintinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairIntIntHandle | [**ListPairIntInt\_at**](#function-listpairintint_at) (ListPairIntIntHandle handle, size\_t idx) <br> |
|  void | [**ListPairIntInt\_clear**](#function-listpairintint_clear) (ListPairIntIntHandle handle) <br> |
|  bool | [**ListPairIntInt\_contains**](#function-listpairintint_contains) (ListPairIntIntHandle handle, PairIntIntHandle value) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_copy**](#function-listpairintint_copy) (ListPairIntIntHandle handle) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_create**](#function-listpairintint_create) (PairIntIntHandle \* data, size\_t count) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_create\_empty**](#function-listpairintint_create_empty) () <br> |
|  void | [**ListPairIntInt\_destroy**](#function-listpairintint_destroy) (ListPairIntIntHandle handle) <br> |
|  bool | [**ListPairIntInt\_empty**](#function-listpairintint_empty) (ListPairIntIntHandle handle) <br> |
|  bool | [**ListPairIntInt\_equal**](#function-listpairintint_equal) (ListPairIntIntHandle handle, ListPairIntIntHandle other) <br> |
|  void | [**ListPairIntInt\_erase\_at**](#function-listpairintint_erase_at) (ListPairIntIntHandle handle, size\_t idx) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_fill\_value**](#function-listpairintint_fill_value) (size\_t count, PairIntIntHandle value) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_from\_json\_string**](#function-listpairintint_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListPairIntInt\_index**](#function-listpairintint_index) (ListPairIntIntHandle handle, PairIntIntHandle value) <br> |
|  ListPairIntIntHandle | [**ListPairIntInt\_intersection**](#function-listpairintint_intersection) (ListPairIntIntHandle handle, ListPairIntIntHandle other) <br> |
|  size\_t | [**ListPairIntInt\_items**](#function-listpairintint_items) (ListPairIntIntHandle handle, PairIntIntHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairIntInt\_not\_equal**](#function-listpairintint_not_equal) (ListPairIntIntHandle handle, ListPairIntIntHandle other) <br> |
|  void | [**ListPairIntInt\_push\_back**](#function-listpairintint_push_back) (ListPairIntIntHandle handle, PairIntIntHandle value) <br> |
|  size\_t | [**ListPairIntInt\_size**](#function-listpairintint_size) (ListPairIntIntHandle handle) <br> |
|  StringHandle | [**ListPairIntInt\_to\_json\_string**](#function-listpairintint_to_json_string) (ListPairIntIntHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairIntIntHandle 

```C++
typedef void* ListPairIntIntHandle;
```




<hr>
## Public Functions Documentation




### function ListPairIntInt\_at 

```C++
PairIntIntHandle ListPairIntInt_at (
    ListPairIntIntHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairIntInt\_clear 

```C++
void ListPairIntInt_clear (
    ListPairIntIntHandle handle
) 
```




<hr>



### function ListPairIntInt\_contains 

```C++
bool ListPairIntInt_contains (
    ListPairIntIntHandle handle,
    PairIntIntHandle value
) 
```




<hr>



### function ListPairIntInt\_copy 

```C++
ListPairIntIntHandle ListPairIntInt_copy (
    ListPairIntIntHandle handle
) 
```




<hr>



### function ListPairIntInt\_create 

```C++
ListPairIntIntHandle ListPairIntInt_create (
    PairIntIntHandle * data,
    size_t count
) 
```




<hr>



### function ListPairIntInt\_create\_empty 

```C++
ListPairIntIntHandle ListPairIntInt_create_empty () 
```




<hr>



### function ListPairIntInt\_destroy 

```C++
void ListPairIntInt_destroy (
    ListPairIntIntHandle handle
) 
```




<hr>



### function ListPairIntInt\_empty 

```C++
bool ListPairIntInt_empty (
    ListPairIntIntHandle handle
) 
```




<hr>



### function ListPairIntInt\_equal 

```C++
bool ListPairIntInt_equal (
    ListPairIntIntHandle handle,
    ListPairIntIntHandle other
) 
```




<hr>



### function ListPairIntInt\_erase\_at 

```C++
void ListPairIntInt_erase_at (
    ListPairIntIntHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairIntInt\_fill\_value 

```C++
ListPairIntIntHandle ListPairIntInt_fill_value (
    size_t count,
    PairIntIntHandle value
) 
```




<hr>



### function ListPairIntInt\_from\_json\_string 

```C++
ListPairIntIntHandle ListPairIntInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairIntInt\_index 

```C++
size_t ListPairIntInt_index (
    ListPairIntIntHandle handle,
    PairIntIntHandle value
) 
```




<hr>



### function ListPairIntInt\_intersection 

```C++
ListPairIntIntHandle ListPairIntInt_intersection (
    ListPairIntIntHandle handle,
    ListPairIntIntHandle other
) 
```




<hr>



### function ListPairIntInt\_items 

```C++
size_t ListPairIntInt_items (
    ListPairIntIntHandle handle,
    PairIntIntHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairIntInt\_not\_equal 

```C++
bool ListPairIntInt_not_equal (
    ListPairIntIntHandle handle,
    ListPairIntIntHandle other
) 
```




<hr>



### function ListPairIntInt\_push\_back 

```C++
void ListPairIntInt_push_back (
    ListPairIntIntHandle handle,
    PairIntIntHandle value
) 
```




<hr>



### function ListPairIntInt\_size 

```C++
size_t ListPairIntInt_size (
    ListPairIntIntHandle handle
) 
```




<hr>



### function ListPairIntInt\_to\_json\_string 

```C++
StringHandle ListPairIntInt_to_json_string (
    ListPairIntIntHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairIntInt_c_api.h`

