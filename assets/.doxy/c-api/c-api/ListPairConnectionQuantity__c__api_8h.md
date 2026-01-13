

# File ListPairConnectionQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionQuantity\_c\_api.h**](ListPairConnectionQuantity__c__api_8h.md)

[Go to the source code of this file](ListPairConnectionQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionQuantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairConnectionQuantityHandle**](#typedef-listpairconnectionquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionQuantityHandle | [**ListPairConnectionQuantity\_at**](#function-listpairconnectionquantity_at) (ListPairConnectionQuantityHandle handle, size\_t idx) <br> |
|  void | [**ListPairConnectionQuantity\_clear**](#function-listpairconnectionquantity_clear) (ListPairConnectionQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionQuantity\_contains**](#function-listpairconnectionquantity_contains) (ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_copy**](#function-listpairconnectionquantity_copy) (ListPairConnectionQuantityHandle handle) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_create**](#function-listpairconnectionquantity_create) (PairConnectionQuantityHandle \* data, size\_t count) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_create\_empty**](#function-listpairconnectionquantity_create_empty) () <br> |
|  void | [**ListPairConnectionQuantity\_destroy**](#function-listpairconnectionquantity_destroy) (ListPairConnectionQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionQuantity\_empty**](#function-listpairconnectionquantity_empty) (ListPairConnectionQuantityHandle handle) <br> |
|  bool | [**ListPairConnectionQuantity\_equal**](#function-listpairconnectionquantity_equal) (ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) <br> |
|  void | [**ListPairConnectionQuantity\_erase\_at**](#function-listpairconnectionquantity_erase_at) (ListPairConnectionQuantityHandle handle, size\_t idx) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_fill\_value**](#function-listpairconnectionquantity_fill_value) (size\_t count, PairConnectionQuantityHandle value) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_from\_json\_string**](#function-listpairconnectionquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairConnectionQuantity\_index**](#function-listpairconnectionquantity_index) (ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) <br> |
|  ListPairConnectionQuantityHandle | [**ListPairConnectionQuantity\_intersection**](#function-listpairconnectionquantity_intersection) (ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) <br> |
|  size\_t | [**ListPairConnectionQuantity\_items**](#function-listpairconnectionquantity_items) (ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairConnectionQuantity\_not\_equal**](#function-listpairconnectionquantity_not_equal) (ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other) <br> |
|  void | [**ListPairConnectionQuantity\_push\_back**](#function-listpairconnectionquantity_push_back) (ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value) <br> |
|  size\_t | [**ListPairConnectionQuantity\_size**](#function-listpairconnectionquantity_size) (ListPairConnectionQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairConnectionQuantity\_to\_json\_string**](#function-listpairconnectionquantity_to_json_string) (ListPairConnectionQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairConnectionQuantityHandle 

```C++
typedef void* ListPairConnectionQuantityHandle;
```




<hr>
## Public Functions Documentation




### function ListPairConnectionQuantity\_at 

```C++
PairConnectionQuantityHandle ListPairConnectionQuantity_at (
    ListPairConnectionQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionQuantity\_clear 

```C++
void ListPairConnectionQuantity_clear (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionQuantity\_contains 

```C++
bool ListPairConnectionQuantity_contains (
    ListPairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle value
) 
```




<hr>



### function ListPairConnectionQuantity\_copy 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_copy (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionQuantity\_create 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create (
    PairConnectionQuantityHandle * data,
    size_t count
) 
```




<hr>



### function ListPairConnectionQuantity\_create\_empty 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create_empty () 
```




<hr>



### function ListPairConnectionQuantity\_destroy 

```C++
void ListPairConnectionQuantity_destroy (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionQuantity\_empty 

```C++
bool ListPairConnectionQuantity_empty (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionQuantity\_equal 

```C++
bool ListPairConnectionQuantity_equal (
    ListPairConnectionQuantityHandle handle,
    ListPairConnectionQuantityHandle other
) 
```




<hr>



### function ListPairConnectionQuantity\_erase\_at 

```C++
void ListPairConnectionQuantity_erase_at (
    ListPairConnectionQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionQuantity\_fill\_value 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_fill_value (
    size_t count,
    PairConnectionQuantityHandle value
) 
```




<hr>



### function ListPairConnectionQuantity\_from\_json\_string 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairConnectionQuantity\_index 

```C++
size_t ListPairConnectionQuantity_index (
    ListPairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle value
) 
```




<hr>



### function ListPairConnectionQuantity\_intersection 

```C++
ListPairConnectionQuantityHandle ListPairConnectionQuantity_intersection (
    ListPairConnectionQuantityHandle handle,
    ListPairConnectionQuantityHandle other
) 
```




<hr>



### function ListPairConnectionQuantity\_items 

```C++
size_t ListPairConnectionQuantity_items (
    ListPairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairConnectionQuantity\_not\_equal 

```C++
bool ListPairConnectionQuantity_not_equal (
    ListPairConnectionQuantityHandle handle,
    ListPairConnectionQuantityHandle other
) 
```




<hr>



### function ListPairConnectionQuantity\_push\_back 

```C++
void ListPairConnectionQuantity_push_back (
    ListPairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle value
) 
```




<hr>



### function ListPairConnectionQuantity\_size 

```C++
size_t ListPairConnectionQuantity_size (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>



### function ListPairConnectionQuantity\_to\_json\_string 

```C++
StringHandle ListPairConnectionQuantity_to_json_string (
    ListPairConnectionQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairConnectionQuantity_c_api.h`

