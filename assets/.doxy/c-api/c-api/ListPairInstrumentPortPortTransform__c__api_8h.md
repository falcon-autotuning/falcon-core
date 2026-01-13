

# File ListPairInstrumentPortPortTransform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairInstrumentPortPortTransform\_c\_api.h**](ListPairInstrumentPortPortTransform__c__api_8h.md)

[Go to the source code of this file](ListPairInstrumentPortPortTransform__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairInstrumentPortPortTransformHandle**](#typedef-listpairinstrumentportporttransformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_at**](#function-listpairinstrumentportporttransform_at) (ListPairInstrumentPortPortTransformHandle handle, size\_t idx) <br> |
|  void | [**ListPairInstrumentPortPortTransform\_clear**](#function-listpairinstrumentportporttransform_clear) (ListPairInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**ListPairInstrumentPortPortTransform\_contains**](#function-listpairinstrumentportporttransform_contains) (ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_copy**](#function-listpairinstrumentportporttransform_copy) (ListPairInstrumentPortPortTransformHandle handle) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_create**](#function-listpairinstrumentportporttransform_create) (PairInstrumentPortPortTransformHandle \* data, size\_t count) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_create\_empty**](#function-listpairinstrumentportporttransform_create_empty) () <br> |
|  void | [**ListPairInstrumentPortPortTransform\_destroy**](#function-listpairinstrumentportporttransform_destroy) (ListPairInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**ListPairInstrumentPortPortTransform\_empty**](#function-listpairinstrumentportporttransform_empty) (ListPairInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**ListPairInstrumentPortPortTransform\_equal**](#function-listpairinstrumentportporttransform_equal) (ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) <br> |
|  void | [**ListPairInstrumentPortPortTransform\_erase\_at**](#function-listpairinstrumentportporttransform_erase_at) (ListPairInstrumentPortPortTransformHandle handle, size\_t idx) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_fill\_value**](#function-listpairinstrumentportporttransform_fill_value) (size\_t count, PairInstrumentPortPortTransformHandle value) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_from\_json\_string**](#function-listpairinstrumentportporttransform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairInstrumentPortPortTransform\_index**](#function-listpairinstrumentportporttransform_index) (ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**ListPairInstrumentPortPortTransform\_intersection**](#function-listpairinstrumentportporttransform_intersection) (ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) <br> |
|  size\_t | [**ListPairInstrumentPortPortTransform\_items**](#function-listpairinstrumentportporttransform_items) (ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairInstrumentPortPortTransform\_not\_equal**](#function-listpairinstrumentportporttransform_not_equal) (ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) <br> |
|  void | [**ListPairInstrumentPortPortTransform\_push\_back**](#function-listpairinstrumentportporttransform_push_back) (ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) <br> |
|  size\_t | [**ListPairInstrumentPortPortTransform\_size**](#function-listpairinstrumentportporttransform_size) (ListPairInstrumentPortPortTransformHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairInstrumentPortPortTransform\_to\_json\_string**](#function-listpairinstrumentportporttransform_to_json_string) (ListPairInstrumentPortPortTransformHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairInstrumentPortPortTransformHandle 

```C++
typedef void* ListPairInstrumentPortPortTransformHandle;
```




<hr>
## Public Functions Documentation




### function ListPairInstrumentPortPortTransform\_at 

```C++
PairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_at (
    ListPairInstrumentPortPortTransformHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_clear 

```C++
void ListPairInstrumentPortPortTransform_clear (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_contains 

```C++
bool ListPairInstrumentPortPortTransform_contains (
    ListPairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle value
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_copy 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_copy (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_create 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create (
    PairInstrumentPortPortTransformHandle * data,
    size_t count
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_create\_empty 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create_empty () 
```




<hr>



### function ListPairInstrumentPortPortTransform\_destroy 

```C++
void ListPairInstrumentPortPortTransform_destroy (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_empty 

```C++
bool ListPairInstrumentPortPortTransform_empty (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_equal 

```C++
bool ListPairInstrumentPortPortTransform_equal (
    ListPairInstrumentPortPortTransformHandle handle,
    ListPairInstrumentPortPortTransformHandle other
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_erase\_at 

```C++
void ListPairInstrumentPortPortTransform_erase_at (
    ListPairInstrumentPortPortTransformHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_fill\_value 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_fill_value (
    size_t count,
    PairInstrumentPortPortTransformHandle value
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_from\_json\_string 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_index 

```C++
size_t ListPairInstrumentPortPortTransform_index (
    ListPairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle value
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_intersection 

```C++
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_intersection (
    ListPairInstrumentPortPortTransformHandle handle,
    ListPairInstrumentPortPortTransformHandle other
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_items 

```C++
size_t ListPairInstrumentPortPortTransform_items (
    ListPairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_not\_equal 

```C++
bool ListPairInstrumentPortPortTransform_not_equal (
    ListPairInstrumentPortPortTransformHandle handle,
    ListPairInstrumentPortPortTransformHandle other
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_push\_back 

```C++
void ListPairInstrumentPortPortTransform_push_back (
    ListPairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle value
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_size 

```C++
size_t ListPairInstrumentPortPortTransform_size (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function ListPairInstrumentPortPortTransform\_to\_json\_string 

```C++
StringHandle ListPairInstrumentPortPortTransform_to_json_string (
    ListPairInstrumentPortPortTransformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h`

