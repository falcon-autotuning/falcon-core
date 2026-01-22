

# File ListLabelledControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledControlArray1D\_c\_api.h**](ListLabelledControlArray1D__c__api_8h.md)

[Go to the source code of this file](ListLabelledControlArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListLabelledControlArray1DHandle**](#typedef-listlabelledcontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArray1DHandle | [**ListLabelledControlArray1D\_at**](#function-listlabelledcontrolarray1d_at) (ListLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  void | [**ListLabelledControlArray1D\_clear**](#function-listlabelledcontrolarray1d_clear) (ListLabelledControlArray1DHandle handle) <br> |
|  bool | [**ListLabelledControlArray1D\_contains**](#function-listlabelledcontrolarray1d_contains) (ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_copy**](#function-listlabelledcontrolarray1d_copy) (ListLabelledControlArray1DHandle handle) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_create**](#function-listlabelledcontrolarray1d_create) (LabelledControlArray1DHandle \* data, size\_t count) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_create\_empty**](#function-listlabelledcontrolarray1d_create_empty) () <br> |
|  void | [**ListLabelledControlArray1D\_destroy**](#function-listlabelledcontrolarray1d_destroy) (ListLabelledControlArray1DHandle handle) <br> |
|  bool | [**ListLabelledControlArray1D\_empty**](#function-listlabelledcontrolarray1d_empty) (ListLabelledControlArray1DHandle handle) <br> |
|  bool | [**ListLabelledControlArray1D\_equal**](#function-listlabelledcontrolarray1d_equal) (ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other) <br> |
|  void | [**ListLabelledControlArray1D\_erase\_at**](#function-listlabelledcontrolarray1d_erase_at) (ListLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_fill\_value**](#function-listlabelledcontrolarray1d_fill_value) (size\_t count, LabelledControlArray1DHandle value) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_from\_json\_string**](#function-listlabelledcontrolarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListLabelledControlArray1D\_index**](#function-listlabelledcontrolarray1d_index) (ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  ListLabelledControlArray1DHandle | [**ListLabelledControlArray1D\_intersection**](#function-listlabelledcontrolarray1d_intersection) (ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other) <br> |
|  size\_t | [**ListLabelledControlArray1D\_items**](#function-listlabelledcontrolarray1d_items) (ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListLabelledControlArray1D\_not\_equal**](#function-listlabelledcontrolarray1d_not_equal) (ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other) <br> |
|  void | [**ListLabelledControlArray1D\_push\_back**](#function-listlabelledcontrolarray1d_push_back) (ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  size\_t | [**ListLabelledControlArray1D\_size**](#function-listlabelledcontrolarray1d_size) (ListLabelledControlArray1DHandle handle) <br> |
|  StringHandle | [**ListLabelledControlArray1D\_to\_json\_string**](#function-listlabelledcontrolarray1d_to_json_string) (ListLabelledControlArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef ListLabelledControlArray1DHandle 

```C++
typedef void* ListLabelledControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function ListLabelledControlArray1D\_at 

```C++
LabelledControlArray1DHandle ListLabelledControlArray1D_at (
    ListLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledControlArray1D\_clear 

```C++
void ListLabelledControlArray1D_clear (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>



### function ListLabelledControlArray1D\_contains 

```C++
bool ListLabelledControlArray1D_contains (
    ListLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function ListLabelledControlArray1D\_copy 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_copy (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>



### function ListLabelledControlArray1D\_create 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create (
    LabelledControlArray1DHandle * data,
    size_t count
) 
```




<hr>



### function ListLabelledControlArray1D\_create\_empty 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty () 
```




<hr>



### function ListLabelledControlArray1D\_destroy 

```C++
void ListLabelledControlArray1D_destroy (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>



### function ListLabelledControlArray1D\_empty 

```C++
bool ListLabelledControlArray1D_empty (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>



### function ListLabelledControlArray1D\_equal 

```C++
bool ListLabelledControlArray1D_equal (
    ListLabelledControlArray1DHandle handle,
    ListLabelledControlArray1DHandle other
) 
```




<hr>



### function ListLabelledControlArray1D\_erase\_at 

```C++
void ListLabelledControlArray1D_erase_at (
    ListLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledControlArray1D\_fill\_value 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value (
    size_t count,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function ListLabelledControlArray1D\_from\_json\_string 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListLabelledControlArray1D\_index 

```C++
size_t ListLabelledControlArray1D_index (
    ListLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function ListLabelledControlArray1D\_intersection 

```C++
ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection (
    ListLabelledControlArray1DHandle handle,
    ListLabelledControlArray1DHandle other
) 
```




<hr>



### function ListLabelledControlArray1D\_items 

```C++
size_t ListLabelledControlArray1D_items (
    ListLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListLabelledControlArray1D\_not\_equal 

```C++
bool ListLabelledControlArray1D_not_equal (
    ListLabelledControlArray1DHandle handle,
    ListLabelledControlArray1DHandle other
) 
```




<hr>



### function ListLabelledControlArray1D\_push\_back 

```C++
void ListLabelledControlArray1D_push_back (
    ListLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function ListLabelledControlArray1D\_size 

```C++
size_t ListLabelledControlArray1D_size (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>



### function ListLabelledControlArray1D\_to\_json\_string 

```C++
StringHandle ListLabelledControlArray1D_to_json_string (
    ListLabelledControlArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListLabelledControlArray1D_c_api.h`

