

# File ListPairInterpretationContextQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairInterpretationContextQuantity\_c\_api.h**](ListPairInterpretationContextQuantity__c__api_8h.md)

[Go to the source code of this file](ListPairInterpretationContextQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairInterpretationContextQuantityHandle**](#typedef-listpairinterpretationcontextquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_at**](#function-listpairinterpretationcontextquantity_at) (ListPairInterpretationContextQuantityHandle handle, size\_t idx) <br> |
|  void | [**ListPairInterpretationContextQuantity\_clear**](#function-listpairinterpretationcontextquantity_clear) (ListPairInterpretationContextQuantityHandle handle) <br> |
|  bool | [**ListPairInterpretationContextQuantity\_contains**](#function-listpairinterpretationcontextquantity_contains) (ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_copy**](#function-listpairinterpretationcontextquantity_copy) (ListPairInterpretationContextQuantityHandle handle) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_create**](#function-listpairinterpretationcontextquantity_create) (PairInterpretationContextQuantityHandle \* data, size\_t count) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_create\_empty**](#function-listpairinterpretationcontextquantity_create_empty) () <br> |
|  void | [**ListPairInterpretationContextQuantity\_destroy**](#function-listpairinterpretationcontextquantity_destroy) (ListPairInterpretationContextQuantityHandle handle) <br> |
|  bool | [**ListPairInterpretationContextQuantity\_empty**](#function-listpairinterpretationcontextquantity_empty) (ListPairInterpretationContextQuantityHandle handle) <br> |
|  bool | [**ListPairInterpretationContextQuantity\_equal**](#function-listpairinterpretationcontextquantity_equal) (ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) <br> |
|  void | [**ListPairInterpretationContextQuantity\_erase\_at**](#function-listpairinterpretationcontextquantity_erase_at) (ListPairInterpretationContextQuantityHandle handle, size\_t idx) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_fill\_value**](#function-listpairinterpretationcontextquantity_fill_value) (size\_t count, PairInterpretationContextQuantityHandle value) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_from\_json\_string**](#function-listpairinterpretationcontextquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairInterpretationContextQuantity\_index**](#function-listpairinterpretationcontextquantity_index) (ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) <br> |
|  ListPairInterpretationContextQuantityHandle | [**ListPairInterpretationContextQuantity\_intersection**](#function-listpairinterpretationcontextquantity_intersection) (ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) <br> |
|  size\_t | [**ListPairInterpretationContextQuantity\_items**](#function-listpairinterpretationcontextquantity_items) (ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairInterpretationContextQuantity\_not\_equal**](#function-listpairinterpretationcontextquantity_not_equal) (ListPairInterpretationContextQuantityHandle handle, ListPairInterpretationContextQuantityHandle other) <br> |
|  void | [**ListPairInterpretationContextQuantity\_push\_back**](#function-listpairinterpretationcontextquantity_push_back) (ListPairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle value) <br> |
|  size\_t | [**ListPairInterpretationContextQuantity\_size**](#function-listpairinterpretationcontextquantity_size) (ListPairInterpretationContextQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairInterpretationContextQuantity\_to\_json\_string**](#function-listpairinterpretationcontextquantity_to_json_string) (ListPairInterpretationContextQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairInterpretationContextQuantityHandle 

```C++
typedef void* ListPairInterpretationContextQuantityHandle;
```




<hr>
## Public Functions Documentation




### function ListPairInterpretationContextQuantity\_at 

```C++
PairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_at (
    ListPairInterpretationContextQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_clear 

```C++
void ListPairInterpretationContextQuantity_clear (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_contains 

```C++
bool ListPairInterpretationContextQuantity_contains (
    ListPairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle value
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_copy 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_copy (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_create 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create (
    PairInterpretationContextQuantityHandle * data,
    size_t count
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_create\_empty 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_create_empty () 
```




<hr>



### function ListPairInterpretationContextQuantity\_destroy 

```C++
void ListPairInterpretationContextQuantity_destroy (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_empty 

```C++
bool ListPairInterpretationContextQuantity_empty (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_equal 

```C++
bool ListPairInterpretationContextQuantity_equal (
    ListPairInterpretationContextQuantityHandle handle,
    ListPairInterpretationContextQuantityHandle other
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_erase\_at 

```C++
void ListPairInterpretationContextQuantity_erase_at (
    ListPairInterpretationContextQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_fill\_value 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_fill_value (
    size_t count,
    PairInterpretationContextQuantityHandle value
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_from\_json\_string 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_index 

```C++
size_t ListPairInterpretationContextQuantity_index (
    ListPairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle value
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_intersection 

```C++
ListPairInterpretationContextQuantityHandle ListPairInterpretationContextQuantity_intersection (
    ListPairInterpretationContextQuantityHandle handle,
    ListPairInterpretationContextQuantityHandle other
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_items 

```C++
size_t ListPairInterpretationContextQuantity_items (
    ListPairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_not\_equal 

```C++
bool ListPairInterpretationContextQuantity_not_equal (
    ListPairInterpretationContextQuantityHandle handle,
    ListPairInterpretationContextQuantityHandle other
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_push\_back 

```C++
void ListPairInterpretationContextQuantity_push_back (
    ListPairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle value
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_size 

```C++
size_t ListPairInterpretationContextQuantity_size (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function ListPairInterpretationContextQuantity\_to\_json\_string 

```C++
StringHandle ListPairInterpretationContextQuantity_to_json_string (
    ListPairInterpretationContextQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h`

