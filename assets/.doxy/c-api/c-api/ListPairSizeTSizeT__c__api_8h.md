

# File ListPairSizeTSizeT\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairSizeTSizeT\_c\_api.h**](ListPairSizeTSizeT__c__api_8h.md)

[Go to the source code of this file](ListPairSizeTSizeT__c__api_8h_source.md)



* `#include "falcon_core/generic/PairSizeTSizeT_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairSizeTSizeTHandle**](#typedef-listpairsizetsizethandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairSizeTSizeTHandle | [**ListPairSizeTSizeT\_at**](#function-listpairsizetsizet_at) (ListPairSizeTSizeTHandle handle, size\_t idx) <br> |
|  void | [**ListPairSizeTSizeT\_clear**](#function-listpairsizetsizet_clear) (ListPairSizeTSizeTHandle handle) <br> |
|  bool | [**ListPairSizeTSizeT\_contains**](#function-listpairsizetsizet_contains) (ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_copy**](#function-listpairsizetsizet_copy) (ListPairSizeTSizeTHandle handle) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_create**](#function-listpairsizetsizet_create) (PairSizeTSizeTHandle \* data, size\_t count) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_create\_empty**](#function-listpairsizetsizet_create_empty) () <br> |
|  void | [**ListPairSizeTSizeT\_destroy**](#function-listpairsizetsizet_destroy) (ListPairSizeTSizeTHandle handle) <br> |
|  bool | [**ListPairSizeTSizeT\_empty**](#function-listpairsizetsizet_empty) (ListPairSizeTSizeTHandle handle) <br> |
|  bool | [**ListPairSizeTSizeT\_equal**](#function-listpairsizetsizet_equal) (ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other) <br> |
|  void | [**ListPairSizeTSizeT\_erase\_at**](#function-listpairsizetsizet_erase_at) (ListPairSizeTSizeTHandle handle, size\_t idx) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_fill\_value**](#function-listpairsizetsizet_fill_value) (size\_t count, PairSizeTSizeTHandle value) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_from\_json\_string**](#function-listpairsizetsizet_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairSizeTSizeT\_index**](#function-listpairsizetsizet_index) (ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) <br> |
|  ListPairSizeTSizeTHandle | [**ListPairSizeTSizeT\_intersection**](#function-listpairsizetsizet_intersection) (ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other) <br> |
|  size\_t | [**ListPairSizeTSizeT\_items**](#function-listpairsizetsizet_items) (ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairSizeTSizeT\_not\_equal**](#function-listpairsizetsizet_not_equal) (ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other) <br> |
|  void | [**ListPairSizeTSizeT\_push\_back**](#function-listpairsizetsizet_push_back) (ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) <br> |
|  size\_t | [**ListPairSizeTSizeT\_size**](#function-listpairsizetsizet_size) (ListPairSizeTSizeTHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairSizeTSizeT\_to\_json\_string**](#function-listpairsizetsizet_to_json_string) (ListPairSizeTSizeTHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairSizeTSizeTHandle 

```C++
typedef void* ListPairSizeTSizeTHandle;
```




<hr>
## Public Functions Documentation




### function ListPairSizeTSizeT\_at 

```C++
PairSizeTSizeTHandle ListPairSizeTSizeT_at (
    ListPairSizeTSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairSizeTSizeT\_clear 

```C++
void ListPairSizeTSizeT_clear (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>



### function ListPairSizeTSizeT\_contains 

```C++
bool ListPairSizeTSizeT_contains (
    ListPairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle value
) 
```




<hr>



### function ListPairSizeTSizeT\_copy 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_copy (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>



### function ListPairSizeTSizeT\_create 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create (
    PairSizeTSizeTHandle * data,
    size_t count
) 
```




<hr>



### function ListPairSizeTSizeT\_create\_empty 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty () 
```




<hr>



### function ListPairSizeTSizeT\_destroy 

```C++
void ListPairSizeTSizeT_destroy (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>



### function ListPairSizeTSizeT\_empty 

```C++
bool ListPairSizeTSizeT_empty (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>



### function ListPairSizeTSizeT\_equal 

```C++
bool ListPairSizeTSizeT_equal (
    ListPairSizeTSizeTHandle handle,
    ListPairSizeTSizeTHandle other
) 
```




<hr>



### function ListPairSizeTSizeT\_erase\_at 

```C++
void ListPairSizeTSizeT_erase_at (
    ListPairSizeTSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairSizeTSizeT\_fill\_value 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value (
    size_t count,
    PairSizeTSizeTHandle value
) 
```




<hr>



### function ListPairSizeTSizeT\_from\_json\_string 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairSizeTSizeT\_index 

```C++
size_t ListPairSizeTSizeT_index (
    ListPairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle value
) 
```




<hr>



### function ListPairSizeTSizeT\_intersection 

```C++
ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection (
    ListPairSizeTSizeTHandle handle,
    ListPairSizeTSizeTHandle other
) 
```




<hr>



### function ListPairSizeTSizeT\_items 

```C++
size_t ListPairSizeTSizeT_items (
    ListPairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairSizeTSizeT\_not\_equal 

```C++
bool ListPairSizeTSizeT_not_equal (
    ListPairSizeTSizeTHandle handle,
    ListPairSizeTSizeTHandle other
) 
```




<hr>



### function ListPairSizeTSizeT\_push\_back 

```C++
void ListPairSizeTSizeT_push_back (
    ListPairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle value
) 
```




<hr>



### function ListPairSizeTSizeT\_size 

```C++
size_t ListPairSizeTSizeT_size (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>



### function ListPairSizeTSizeT\_to\_json\_string 

```C++
StringHandle ListPairSizeTSizeT_to_json_string (
    ListPairSizeTSizeTHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairSizeTSizeT_c_api.h`

