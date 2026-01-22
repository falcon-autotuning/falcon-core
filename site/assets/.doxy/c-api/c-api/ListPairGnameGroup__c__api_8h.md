

# File ListPairGnameGroup\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairGnameGroup\_c\_api.h**](ListPairGnameGroup__c__api_8h.md)

[Go to the source code of this file](ListPairGnameGroup__c__api_8h_source.md)



* `#include "falcon_core/generic/PairGnameGroup_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairGnameGroupHandle**](#typedef-listpairgnamegrouphandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairGnameGroupHandle | [**ListPairGnameGroup\_at**](#function-listpairgnamegroup_at) (ListPairGnameGroupHandle handle, size\_t idx) <br> |
|  void | [**ListPairGnameGroup\_clear**](#function-listpairgnamegroup_clear) (ListPairGnameGroupHandle handle) <br> |
|  bool | [**ListPairGnameGroup\_contains**](#function-listpairgnamegroup_contains) (ListPairGnameGroupHandle handle, PairGnameGroupHandle value) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_copy**](#function-listpairgnamegroup_copy) (ListPairGnameGroupHandle handle) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_create**](#function-listpairgnamegroup_create) (PairGnameGroupHandle \* data, size\_t count) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_create\_empty**](#function-listpairgnamegroup_create_empty) () <br> |
|  void | [**ListPairGnameGroup\_destroy**](#function-listpairgnamegroup_destroy) (ListPairGnameGroupHandle handle) <br> |
|  bool | [**ListPairGnameGroup\_empty**](#function-listpairgnamegroup_empty) (ListPairGnameGroupHandle handle) <br> |
|  bool | [**ListPairGnameGroup\_equal**](#function-listpairgnamegroup_equal) (ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) <br> |
|  void | [**ListPairGnameGroup\_erase\_at**](#function-listpairgnamegroup_erase_at) (ListPairGnameGroupHandle handle, size\_t idx) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_fill\_value**](#function-listpairgnamegroup_fill_value) (size\_t count, PairGnameGroupHandle value) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_from\_json\_string**](#function-listpairgnamegroup_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListPairGnameGroup\_index**](#function-listpairgnamegroup_index) (ListPairGnameGroupHandle handle, PairGnameGroupHandle value) <br> |
|  ListPairGnameGroupHandle | [**ListPairGnameGroup\_intersection**](#function-listpairgnamegroup_intersection) (ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) <br> |
|  size\_t | [**ListPairGnameGroup\_items**](#function-listpairgnamegroup_items) (ListPairGnameGroupHandle handle, PairGnameGroupHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairGnameGroup\_not\_equal**](#function-listpairgnamegroup_not_equal) (ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other) <br> |
|  void | [**ListPairGnameGroup\_push\_back**](#function-listpairgnamegroup_push_back) (ListPairGnameGroupHandle handle, PairGnameGroupHandle value) <br> |
|  size\_t | [**ListPairGnameGroup\_size**](#function-listpairgnamegroup_size) (ListPairGnameGroupHandle handle) <br> |
|  StringHandle | [**ListPairGnameGroup\_to\_json\_string**](#function-listpairgnamegroup_to_json_string) (ListPairGnameGroupHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairGnameGroupHandle 

```C++
typedef void* ListPairGnameGroupHandle;
```




<hr>
## Public Functions Documentation




### function ListPairGnameGroup\_at 

```C++
PairGnameGroupHandle ListPairGnameGroup_at (
    ListPairGnameGroupHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairGnameGroup\_clear 

```C++
void ListPairGnameGroup_clear (
    ListPairGnameGroupHandle handle
) 
```




<hr>



### function ListPairGnameGroup\_contains 

```C++
bool ListPairGnameGroup_contains (
    ListPairGnameGroupHandle handle,
    PairGnameGroupHandle value
) 
```




<hr>



### function ListPairGnameGroup\_copy 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_copy (
    ListPairGnameGroupHandle handle
) 
```




<hr>



### function ListPairGnameGroup\_create 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_create (
    PairGnameGroupHandle * data,
    size_t count
) 
```




<hr>



### function ListPairGnameGroup\_create\_empty 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_create_empty () 
```




<hr>



### function ListPairGnameGroup\_destroy 

```C++
void ListPairGnameGroup_destroy (
    ListPairGnameGroupHandle handle
) 
```




<hr>



### function ListPairGnameGroup\_empty 

```C++
bool ListPairGnameGroup_empty (
    ListPairGnameGroupHandle handle
) 
```




<hr>



### function ListPairGnameGroup\_equal 

```C++
bool ListPairGnameGroup_equal (
    ListPairGnameGroupHandle handle,
    ListPairGnameGroupHandle other
) 
```




<hr>



### function ListPairGnameGroup\_erase\_at 

```C++
void ListPairGnameGroup_erase_at (
    ListPairGnameGroupHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairGnameGroup\_fill\_value 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_fill_value (
    size_t count,
    PairGnameGroupHandle value
) 
```




<hr>



### function ListPairGnameGroup\_from\_json\_string 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairGnameGroup\_index 

```C++
size_t ListPairGnameGroup_index (
    ListPairGnameGroupHandle handle,
    PairGnameGroupHandle value
) 
```




<hr>



### function ListPairGnameGroup\_intersection 

```C++
ListPairGnameGroupHandle ListPairGnameGroup_intersection (
    ListPairGnameGroupHandle handle,
    ListPairGnameGroupHandle other
) 
```




<hr>



### function ListPairGnameGroup\_items 

```C++
size_t ListPairGnameGroup_items (
    ListPairGnameGroupHandle handle,
    PairGnameGroupHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairGnameGroup\_not\_equal 

```C++
bool ListPairGnameGroup_not_equal (
    ListPairGnameGroupHandle handle,
    ListPairGnameGroupHandle other
) 
```




<hr>



### function ListPairGnameGroup\_push\_back 

```C++
void ListPairGnameGroup_push_back (
    ListPairGnameGroupHandle handle,
    PairGnameGroupHandle value
) 
```




<hr>



### function ListPairGnameGroup\_size 

```C++
size_t ListPairGnameGroup_size (
    ListPairGnameGroupHandle handle
) 
```




<hr>



### function ListPairGnameGroup\_to\_json\_string 

```C++
StringHandle ListPairGnameGroup_to_json_string (
    ListPairGnameGroupHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairGnameGroup_c_api.h`

