

# File ListLabelledMeasuredArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledMeasuredArray\_c\_api.h**](ListLabelledMeasuredArray__c__api_8h.md)

[Go to the source code of this file](ListLabelledMeasuredArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListLabelledMeasuredArrayHandle**](#typedef-listlabelledmeasuredarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_at**](#function-listlabelledmeasuredarray_at) (ListLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  void | [**ListLabelledMeasuredArray\_clear**](#function-listlabelledmeasuredarray_clear) (ListLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray\_contains**](#function-listlabelledmeasuredarray_contains) (ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_copy**](#function-listlabelledmeasuredarray_copy) (ListLabelledMeasuredArrayHandle handle) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_create**](#function-listlabelledmeasuredarray_create) (LabelledMeasuredArrayHandle \* data, size\_t count) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_create\_empty**](#function-listlabelledmeasuredarray_create_empty) () <br> |
|  void | [**ListLabelledMeasuredArray\_destroy**](#function-listlabelledmeasuredarray_destroy) (ListLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray\_empty**](#function-listlabelledmeasuredarray_empty) (ListLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray\_equal**](#function-listlabelledmeasuredarray_equal) (ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) <br> |
|  void | [**ListLabelledMeasuredArray\_erase\_at**](#function-listlabelledmeasuredarray_erase_at) (ListLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_fill\_value**](#function-listlabelledmeasuredarray_fill_value) (size\_t count, LabelledMeasuredArrayHandle value) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_from\_json\_string**](#function-listlabelledmeasuredarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListLabelledMeasuredArray\_index**](#function-listlabelledmeasuredarray_index) (ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  ListLabelledMeasuredArrayHandle | [**ListLabelledMeasuredArray\_intersection**](#function-listlabelledmeasuredarray_intersection) (ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) <br> |
|  size\_t | [**ListLabelledMeasuredArray\_items**](#function-listlabelledmeasuredarray_items) (ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListLabelledMeasuredArray\_not\_equal**](#function-listlabelledmeasuredarray_not_equal) (ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other) <br> |
|  void | [**ListLabelledMeasuredArray\_push\_back**](#function-listlabelledmeasuredarray_push_back) (ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  size\_t | [**ListLabelledMeasuredArray\_size**](#function-listlabelledmeasuredarray_size) (ListLabelledMeasuredArrayHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListLabelledMeasuredArray\_to\_json\_string**](#function-listlabelledmeasuredarray_to_json_string) (ListLabelledMeasuredArrayHandle handle) <br> |




























## Public Types Documentation




### typedef ListLabelledMeasuredArrayHandle 

```C++
typedef void* ListLabelledMeasuredArrayHandle;
```




<hr>
## Public Functions Documentation




### function ListLabelledMeasuredArray\_at 

```C++
LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at (
    ListLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledMeasuredArray\_clear 

```C++
void ListLabelledMeasuredArray_clear (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray\_contains 

```C++
bool ListLabelledMeasuredArray_contains (
    ListLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray\_copy 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_copy (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray\_create 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create (
    LabelledMeasuredArrayHandle * data,
    size_t count
) 
```




<hr>



### function ListLabelledMeasuredArray\_create\_empty 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty () 
```




<hr>



### function ListLabelledMeasuredArray\_destroy 

```C++
void ListLabelledMeasuredArray_destroy (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray\_empty 

```C++
bool ListLabelledMeasuredArray_empty (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray\_equal 

```C++
bool ListLabelledMeasuredArray_equal (
    ListLabelledMeasuredArrayHandle handle,
    ListLabelledMeasuredArrayHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray\_erase\_at 

```C++
void ListLabelledMeasuredArray_erase_at (
    ListLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledMeasuredArray\_fill\_value 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value (
    size_t count,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray\_from\_json\_string 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListLabelledMeasuredArray\_index 

```C++
size_t ListLabelledMeasuredArray_index (
    ListLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray\_intersection 

```C++
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection (
    ListLabelledMeasuredArrayHandle handle,
    ListLabelledMeasuredArrayHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray\_items 

```C++
size_t ListLabelledMeasuredArray_items (
    ListLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListLabelledMeasuredArray\_not\_equal 

```C++
bool ListLabelledMeasuredArray_not_equal (
    ListLabelledMeasuredArrayHandle handle,
    ListLabelledMeasuredArrayHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray\_push\_back 

```C++
void ListLabelledMeasuredArray_push_back (
    ListLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray\_size 

```C++
size_t ListLabelledMeasuredArray_size (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray\_to\_json\_string 

```C++
StringHandle ListLabelledMeasuredArray_to_json_string (
    ListLabelledMeasuredArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListLabelledMeasuredArray_c_api.h`

