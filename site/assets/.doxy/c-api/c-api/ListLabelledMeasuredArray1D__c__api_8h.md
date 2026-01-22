

# File ListLabelledMeasuredArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledMeasuredArray1D\_c\_api.h**](ListLabelledMeasuredArray1D__c__api_8h.md)

[Go to the source code of this file](ListLabelledMeasuredArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListLabelledMeasuredArray1DHandle**](#typedef-listlabelledmeasuredarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_at**](#function-listlabelledmeasuredarray1d_at) (ListLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  void | [**ListLabelledMeasuredArray1D\_clear**](#function-listlabelledmeasuredarray1d_clear) (ListLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray1D\_contains**](#function-listlabelledmeasuredarray1d_contains) (ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_copy**](#function-listlabelledmeasuredarray1d_copy) (ListLabelledMeasuredArray1DHandle handle) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_create**](#function-listlabelledmeasuredarray1d_create) (LabelledMeasuredArray1DHandle \* data, size\_t count) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_create\_empty**](#function-listlabelledmeasuredarray1d_create_empty) () <br> |
|  void | [**ListLabelledMeasuredArray1D\_destroy**](#function-listlabelledmeasuredarray1d_destroy) (ListLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray1D\_empty**](#function-listlabelledmeasuredarray1d_empty) (ListLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**ListLabelledMeasuredArray1D\_equal**](#function-listlabelledmeasuredarray1d_equal) (ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other) <br> |
|  void | [**ListLabelledMeasuredArray1D\_erase\_at**](#function-listlabelledmeasuredarray1d_erase_at) (ListLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_fill\_value**](#function-listlabelledmeasuredarray1d_fill_value) (size\_t count, LabelledMeasuredArray1DHandle value) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_from\_json\_string**](#function-listlabelledmeasuredarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListLabelledMeasuredArray1D\_index**](#function-listlabelledmeasuredarray1d_index) (ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  ListLabelledMeasuredArray1DHandle | [**ListLabelledMeasuredArray1D\_intersection**](#function-listlabelledmeasuredarray1d_intersection) (ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other) <br> |
|  size\_t | [**ListLabelledMeasuredArray1D\_items**](#function-listlabelledmeasuredarray1d_items) (ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListLabelledMeasuredArray1D\_not\_equal**](#function-listlabelledmeasuredarray1d_not_equal) (ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other) <br> |
|  void | [**ListLabelledMeasuredArray1D\_push\_back**](#function-listlabelledmeasuredarray1d_push_back) (ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  size\_t | [**ListLabelledMeasuredArray1D\_size**](#function-listlabelledmeasuredarray1d_size) (ListLabelledMeasuredArray1DHandle handle) <br> |
|  StringHandle | [**ListLabelledMeasuredArray1D\_to\_json\_string**](#function-listlabelledmeasuredarray1d_to_json_string) (ListLabelledMeasuredArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef ListLabelledMeasuredArray1DHandle 

```C++
typedef void* ListLabelledMeasuredArray1DHandle;
```




<hr>
## Public Functions Documentation




### function ListLabelledMeasuredArray1D\_at 

```C++
LabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_at (
    ListLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_clear 

```C++
void ListLabelledMeasuredArray1D_clear (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_contains 

```C++
bool ListLabelledMeasuredArray1D_contains (
    ListLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_copy 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_copy (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_create 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create (
    LabelledMeasuredArray1DHandle * data,
    size_t count
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_create\_empty 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create_empty () 
```




<hr>



### function ListLabelledMeasuredArray1D\_destroy 

```C++
void ListLabelledMeasuredArray1D_destroy (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_empty 

```C++
bool ListLabelledMeasuredArray1D_empty (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_equal 

```C++
bool ListLabelledMeasuredArray1D_equal (
    ListLabelledMeasuredArray1DHandle handle,
    ListLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_erase\_at 

```C++
void ListLabelledMeasuredArray1D_erase_at (
    ListLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_fill\_value 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_fill_value (
    size_t count,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_from\_json\_string 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_index 

```C++
size_t ListLabelledMeasuredArray1D_index (
    ListLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_intersection 

```C++
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_intersection (
    ListLabelledMeasuredArray1DHandle handle,
    ListLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_items 

```C++
size_t ListLabelledMeasuredArray1D_items (
    ListLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_not\_equal 

```C++
bool ListLabelledMeasuredArray1D_not_equal (
    ListLabelledMeasuredArray1DHandle handle,
    ListLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_push\_back 

```C++
void ListLabelledMeasuredArray1D_push_back (
    ListLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_size 

```C++
size_t ListLabelledMeasuredArray1D_size (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function ListLabelledMeasuredArray1D\_to\_json\_string 

```C++
StringHandle ListLabelledMeasuredArray1D_to_json_string (
    ListLabelledMeasuredArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h`

