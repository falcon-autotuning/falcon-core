

# File ListQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListQuantity\_c\_api.h**](ListQuantity__c__api_8h.md)

[Go to the source code of this file](ListQuantity__c__api_8h_source.md)



* `#include "falcon_core/math/Quantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListQuantityHandle**](#typedef-listquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  QuantityHandle | [**ListQuantity\_at**](#function-listquantity_at) (ListQuantityHandle handle, size\_t idx) <br> |
|  void | [**ListQuantity\_clear**](#function-listquantity_clear) (ListQuantityHandle handle) <br> |
|  bool | [**ListQuantity\_contains**](#function-listquantity_contains) (ListQuantityHandle handle, QuantityHandle value) <br> |
|  ListQuantityHandle | [**ListQuantity\_copy**](#function-listquantity_copy) (ListQuantityHandle handle) <br> |
|  ListQuantityHandle | [**ListQuantity\_create**](#function-listquantity_create) (QuantityHandle \* data, size\_t count) <br> |
|  ListQuantityHandle | [**ListQuantity\_create\_empty**](#function-listquantity_create_empty) () <br> |
|  void | [**ListQuantity\_destroy**](#function-listquantity_destroy) (ListQuantityHandle handle) <br> |
|  bool | [**ListQuantity\_empty**](#function-listquantity_empty) (ListQuantityHandle handle) <br> |
|  bool | [**ListQuantity\_equal**](#function-listquantity_equal) (ListQuantityHandle handle, ListQuantityHandle other) <br> |
|  void | [**ListQuantity\_erase\_at**](#function-listquantity_erase_at) (ListQuantityHandle handle, size\_t idx) <br> |
|  ListQuantityHandle | [**ListQuantity\_fill\_value**](#function-listquantity_fill_value) (size\_t count, QuantityHandle value) <br> |
|  ListQuantityHandle | [**ListQuantity\_from\_json\_string**](#function-listquantity_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListQuantity\_index**](#function-listquantity_index) (ListQuantityHandle handle, QuantityHandle value) <br> |
|  ListQuantityHandle | [**ListQuantity\_intersection**](#function-listquantity_intersection) (ListQuantityHandle handle, ListQuantityHandle other) <br> |
|  size\_t | [**ListQuantity\_items**](#function-listquantity_items) (ListQuantityHandle handle, QuantityHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListQuantity\_not\_equal**](#function-listquantity_not_equal) (ListQuantityHandle handle, ListQuantityHandle other) <br> |
|  void | [**ListQuantity\_push\_back**](#function-listquantity_push_back) (ListQuantityHandle handle, QuantityHandle value) <br> |
|  size\_t | [**ListQuantity\_size**](#function-listquantity_size) (ListQuantityHandle handle) <br> |
|  StringHandle | [**ListQuantity\_to\_json\_string**](#function-listquantity_to_json_string) (ListQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef ListQuantityHandle 

```C++
typedef void* ListQuantityHandle;
```




<hr>
## Public Functions Documentation




### function ListQuantity\_at 

```C++
QuantityHandle ListQuantity_at (
    ListQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListQuantity\_clear 

```C++
void ListQuantity_clear (
    ListQuantityHandle handle
) 
```




<hr>



### function ListQuantity\_contains 

```C++
bool ListQuantity_contains (
    ListQuantityHandle handle,
    QuantityHandle value
) 
```




<hr>



### function ListQuantity\_copy 

```C++
ListQuantityHandle ListQuantity_copy (
    ListQuantityHandle handle
) 
```




<hr>



### function ListQuantity\_create 

```C++
ListQuantityHandle ListQuantity_create (
    QuantityHandle * data,
    size_t count
) 
```




<hr>



### function ListQuantity\_create\_empty 

```C++
ListQuantityHandle ListQuantity_create_empty () 
```




<hr>



### function ListQuantity\_destroy 

```C++
void ListQuantity_destroy (
    ListQuantityHandle handle
) 
```




<hr>



### function ListQuantity\_empty 

```C++
bool ListQuantity_empty (
    ListQuantityHandle handle
) 
```




<hr>



### function ListQuantity\_equal 

```C++
bool ListQuantity_equal (
    ListQuantityHandle handle,
    ListQuantityHandle other
) 
```




<hr>



### function ListQuantity\_erase\_at 

```C++
void ListQuantity_erase_at (
    ListQuantityHandle handle,
    size_t idx
) 
```




<hr>



### function ListQuantity\_fill\_value 

```C++
ListQuantityHandle ListQuantity_fill_value (
    size_t count,
    QuantityHandle value
) 
```




<hr>



### function ListQuantity\_from\_json\_string 

```C++
ListQuantityHandle ListQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListQuantity\_index 

```C++
size_t ListQuantity_index (
    ListQuantityHandle handle,
    QuantityHandle value
) 
```




<hr>



### function ListQuantity\_intersection 

```C++
ListQuantityHandle ListQuantity_intersection (
    ListQuantityHandle handle,
    ListQuantityHandle other
) 
```




<hr>



### function ListQuantity\_items 

```C++
size_t ListQuantity_items (
    ListQuantityHandle handle,
    QuantityHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListQuantity\_not\_equal 

```C++
bool ListQuantity_not_equal (
    ListQuantityHandle handle,
    ListQuantityHandle other
) 
```




<hr>



### function ListQuantity\_push\_back 

```C++
void ListQuantity_push_back (
    ListQuantityHandle handle,
    QuantityHandle value
) 
```




<hr>



### function ListQuantity\_size 

```C++
size_t ListQuantity_size (
    ListQuantityHandle handle
) 
```




<hr>



### function ListQuantity\_to\_json\_string 

```C++
StringHandle ListQuantity_to_json_string (
    ListQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListQuantity_c_api.h`

