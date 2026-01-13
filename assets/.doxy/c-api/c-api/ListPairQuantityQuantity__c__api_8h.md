

# File ListPairQuantityQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairQuantityQuantity\_c\_api.h**](ListPairQuantityQuantity__c__api_8h.md)

[Go to the source code of this file](ListPairQuantityQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairQuantityQuantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairQuantityQuantityHandle**](#typedef-listpairquantityquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairQuantityQuantityHandle | [**ListPairQuantityQuantity\_at**](#function-listpairquantityquantity_at) (ListPairQuantityQuantityHandle handle, size\_t idx) <br> |
|  void | [**ListPairQuantityQuantity\_clear**](#function-listpairquantityquantity_clear) (ListPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairQuantityQuantity\_contains**](#function-listpairquantityquantity_contains) (ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_copy**](#function-listpairquantityquantity_copy) (ListPairQuantityQuantityHandle handle) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_create**](#function-listpairquantityquantity_create) (PairQuantityQuantityHandle \* data, size\_t count) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_create\_empty**](#function-listpairquantityquantity_create_empty) () <br> |
|  void | [**ListPairQuantityQuantity\_destroy**](#function-listpairquantityquantity_destroy) (ListPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairQuantityQuantity\_empty**](#function-listpairquantityquantity_empty) (ListPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairQuantityQuantity\_equal**](#function-listpairquantityquantity_equal) (ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other) <br> |
|  void | [**ListPairQuantityQuantity\_erase\_at**](#function-listpairquantityquantity_erase_at) (ListPairQuantityQuantityHandle handle, size\_t idx) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_fill\_value**](#function-listpairquantityquantity_fill_value) (size\_t count, PairQuantityQuantityHandle value) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_from\_json\_string**](#function-listpairquantityquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairQuantityQuantity\_index**](#function-listpairquantityquantity_index) (ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) <br> |
|  ListPairQuantityQuantityHandle | [**ListPairQuantityQuantity\_intersection**](#function-listpairquantityquantity_intersection) (ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other) <br> |
|  size\_t | [**ListPairQuantityQuantity\_items**](#function-listpairquantityquantity_items) (ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairQuantityQuantity\_not\_equal**](#function-listpairquantityquantity_not_equal) (ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other) <br> |
|  void | [**ListPairQuantityQuantity\_push\_back**](#function-listpairquantityquantity_push_back) (ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value) <br> |
|  size\_t | [**ListPairQuantityQuantity\_size**](#function-listpairquantityquantity_size) (ListPairQuantityQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairQuantityQuantity\_to\_json\_string**](#function-listpairquantityquantity_to_json_string) (ListPairQuantityQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairQuantityQuantityHandle 

```C++
typedef void* ListPairQuantityQuantityHandle;
```




<hr>
## Public Functions Documentation




### function ListPairQuantityQuantity\_at 

```C++
PairQuantityQuantityHandle ListPairQuantityQuantity_at (
    ListPairQuantityQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairQuantityQuantity\_clear 

```C++
void ListPairQuantityQuantity_clear (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairQuantityQuantity\_contains 

```C++
bool ListPairQuantityQuantity_contains (
    ListPairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairQuantityQuantity\_copy 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_copy (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairQuantityQuantity\_create 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create (
    PairQuantityQuantityHandle * data,
    size_t count
) 
```




<hr>



### function ListPairQuantityQuantity\_create\_empty 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty () 
```




<hr>



### function ListPairQuantityQuantity\_destroy 

```C++
void ListPairQuantityQuantity_destroy (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairQuantityQuantity\_empty 

```C++
bool ListPairQuantityQuantity_empty (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairQuantityQuantity\_equal 

```C++
bool ListPairQuantityQuantity_equal (
    ListPairQuantityQuantityHandle handle,
    ListPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairQuantityQuantity\_erase\_at 

```C++
void ListPairQuantityQuantity_erase_at (
    ListPairQuantityQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairQuantityQuantity\_fill\_value 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value (
    size_t count,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairQuantityQuantity\_from\_json\_string 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairQuantityQuantity\_index 

```C++
size_t ListPairQuantityQuantity_index (
    ListPairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairQuantityQuantity\_intersection 

```C++
ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection (
    ListPairQuantityQuantityHandle handle,
    ListPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairQuantityQuantity\_items 

```C++
size_t ListPairQuantityQuantity_items (
    ListPairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairQuantityQuantity\_not\_equal 

```C++
bool ListPairQuantityQuantity_not_equal (
    ListPairQuantityQuantityHandle handle,
    ListPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairQuantityQuantity\_push\_back 

```C++
void ListPairQuantityQuantity_push_back (
    ListPairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairQuantityQuantity\_size 

```C++
size_t ListPairQuantityQuantity_size (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairQuantityQuantity\_to\_json\_string 

```C++
StringHandle ListPairQuantityQuantity_to_json_string (
    ListPairQuantityQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairQuantityQuantity_c_api.h`

