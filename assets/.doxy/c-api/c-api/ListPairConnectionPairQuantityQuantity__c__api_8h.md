

# File ListPairConnectionPairQuantityQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionPairQuantityQuantity\_c\_api.h**](ListPairConnectionPairQuantityQuantity__c__api_8h.md)

[Go to the source code of this file](ListPairConnectionPairQuantityQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairConnectionPairQuantityQuantityHandle**](#typedef-listpairconnectionpairquantityquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_at**](#function-listpairconnectionpairquantityquantity_at) (ListPairConnectionPairQuantityQuantityHandle handle, size\_t idx) <br> |
|  void | [**ListPairConnectionPairQuantityQuantity\_clear**](#function-listpairconnectionpairquantityquantity_clear) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionPairQuantityQuantity\_contains**](#function-listpairconnectionpairquantityquantity_contains) (ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_copy**](#function-listpairconnectionpairquantityquantity_copy) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_create**](#function-listpairconnectionpairquantityquantity_create) (PairConnectionPairQuantityQuantityHandle \* data, size\_t count) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_create\_empty**](#function-listpairconnectionpairquantityquantity_create_empty) () <br> |
|  void | [**ListPairConnectionPairQuantityQuantity\_destroy**](#function-listpairconnectionpairquantityquantity_destroy) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionPairQuantityQuantity\_empty**](#function-listpairconnectionpairquantityquantity_empty) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionPairQuantityQuantity\_equal**](#function-listpairconnectionpairquantityquantity_equal) (ListPairConnectionPairQuantityQuantityHandle handle, ListPairConnectionPairQuantityQuantityHandle other) <br> |
|  void | [**ListPairConnectionPairQuantityQuantity\_erase\_at**](#function-listpairconnectionpairquantityquantity_erase_at) (ListPairConnectionPairQuantityQuantityHandle handle, size\_t idx) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_fill\_value**](#function-listpairconnectionpairquantityquantity_fill_value) (size\_t count, PairConnectionPairQuantityQuantityHandle value) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_from\_json\_string**](#function-listpairconnectionpairquantityquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairConnectionPairQuantityQuantity\_index**](#function-listpairconnectionpairquantityquantity_index) (ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**ListPairConnectionPairQuantityQuantity\_intersection**](#function-listpairconnectionpairquantityquantity_intersection) (ListPairConnectionPairQuantityQuantityHandle handle, ListPairConnectionPairQuantityQuantityHandle other) <br> |
|  size\_t | [**ListPairConnectionPairQuantityQuantity\_items**](#function-listpairconnectionpairquantityquantity_items) (ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairConnectionPairQuantityQuantity\_not\_equal**](#function-listpairconnectionpairquantityquantity_not_equal) (ListPairConnectionPairQuantityQuantityHandle handle, ListPairConnectionPairQuantityQuantityHandle other) <br> |
|  void | [**ListPairConnectionPairQuantityQuantity\_push\_back**](#function-listpairconnectionpairquantityquantity_push_back) (ListPairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle value) <br> |
|  size\_t | [**ListPairConnectionPairQuantityQuantity\_size**](#function-listpairconnectionpairquantityquantity_size) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairConnectionPairQuantityQuantity\_to\_json\_string**](#function-listpairconnectionpairquantityquantity_to_json_string) (ListPairConnectionPairQuantityQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairConnectionPairQuantityQuantityHandle 

```C++
typedef void* ListPairConnectionPairQuantityQuantityHandle;
```




<hr>
## Public Functions Documentation




### function ListPairConnectionPairQuantityQuantity\_at 

```C++
PairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_at (
    ListPairConnectionPairQuantityQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_clear 

```C++
void ListPairConnectionPairQuantityQuantity_clear (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_contains 

```C++
bool ListPairConnectionPairQuantityQuantity_contains (
    ListPairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_copy 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_copy (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_create 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create (
    PairConnectionPairQuantityQuantityHandle * data,
    size_t count
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_create\_empty 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_create_empty () 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_destroy 

```C++
void ListPairConnectionPairQuantityQuantity_destroy (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_empty 

```C++
bool ListPairConnectionPairQuantityQuantity_empty (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_equal 

```C++
bool ListPairConnectionPairQuantityQuantity_equal (
    ListPairConnectionPairQuantityQuantityHandle handle,
    ListPairConnectionPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_erase\_at 

```C++
void ListPairConnectionPairQuantityQuantity_erase_at (
    ListPairConnectionPairQuantityQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_fill\_value 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_fill_value (
    size_t count,
    PairConnectionPairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_from\_json\_string 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_index 

```C++
size_t ListPairConnectionPairQuantityQuantity_index (
    ListPairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_intersection 

```C++
ListPairConnectionPairQuantityQuantityHandle ListPairConnectionPairQuantityQuantity_intersection (
    ListPairConnectionPairQuantityQuantityHandle handle,
    ListPairConnectionPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_items 

```C++
size_t ListPairConnectionPairQuantityQuantity_items (
    ListPairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_not\_equal 

```C++
bool ListPairConnectionPairQuantityQuantity_not_equal (
    ListPairConnectionPairQuantityQuantityHandle handle,
    ListPairConnectionPairQuantityQuantityHandle other
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_push\_back 

```C++
void ListPairConnectionPairQuantityQuantity_push_back (
    ListPairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle value
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_size 

```C++
size_t ListPairConnectionPairQuantityQuantity_size (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionPairQuantityQuantity\_to\_json\_string 

```C++
StringHandle ListPairConnectionPairQuantityQuantity_to_json_string (
    ListPairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h`

