

# File AxesLabelledMeasuredArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledMeasuredArray1D\_c\_api.h**](AxesLabelledMeasuredArray1D__c__api_8h.md)

[Go to the source code of this file](AxesLabelledMeasuredArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"`
* `#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesLabelledMeasuredArray1DHandle**](#typedef-axeslabelledmeasuredarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_at**](#function-axeslabelledmeasuredarray1d_at) (AxesLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  void | [**AxesLabelledMeasuredArray1D\_clear**](#function-axeslabelledmeasuredarray1d_clear) (AxesLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray1D\_contains**](#function-axeslabelledmeasuredarray1d_contains) (AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  AxesLabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_copy**](#function-axeslabelledmeasuredarray1d_copy) (AxesLabelledMeasuredArray1DHandle handle) <br> |
|  AxesLabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_create**](#function-axeslabelledmeasuredarray1d_create) (ListLabelledMeasuredArray1DHandle data) <br> |
|  AxesLabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_create\_empty**](#function-axeslabelledmeasuredarray1d_create_empty) () <br> |
|  void | [**AxesLabelledMeasuredArray1D\_destroy**](#function-axeslabelledmeasuredarray1d_destroy) (AxesLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray1D\_empty**](#function-axeslabelledmeasuredarray1d_empty) (AxesLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray1D\_equal**](#function-axeslabelledmeasuredarray1d_equal) (AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other) <br> |
|  void | [**AxesLabelledMeasuredArray1D\_erase\_at**](#function-axeslabelledmeasuredarray1d_erase_at) (AxesLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  AxesLabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_from\_json\_string**](#function-axeslabelledmeasuredarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesLabelledMeasuredArray1D\_index**](#function-axeslabelledmeasuredarray1d_index) (AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  AxesLabelledMeasuredArray1DHandle | [**AxesLabelledMeasuredArray1D\_intersection**](#function-axeslabelledmeasuredarray1d_intersection) (AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other) <br> |
|  size\_t | [**AxesLabelledMeasuredArray1D\_items**](#function-axeslabelledmeasuredarray1d_items) (AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesLabelledMeasuredArray1D\_not\_equal**](#function-axeslabelledmeasuredarray1d_not_equal) (AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other) <br> |
|  void | [**AxesLabelledMeasuredArray1D\_push\_back**](#function-axeslabelledmeasuredarray1d_push_back) (AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  size\_t | [**AxesLabelledMeasuredArray1D\_size**](#function-axeslabelledmeasuredarray1d_size) (AxesLabelledMeasuredArray1DHandle handle) <br> |
|  StringHandle | [**AxesLabelledMeasuredArray1D\_to\_json\_string**](#function-axeslabelledmeasuredarray1d_to_json_string) (AxesLabelledMeasuredArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef AxesLabelledMeasuredArray1DHandle 

```C++
typedef void* AxesLabelledMeasuredArray1DHandle;
```




<hr>
## Public Functions Documentation




### function AxesLabelledMeasuredArray1D\_at 

```C++
LabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_at (
    AxesLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_clear 

```C++
void AxesLabelledMeasuredArray1D_clear (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_contains 

```C++
bool AxesLabelledMeasuredArray1D_contains (
    AxesLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_copy 

```C++
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_copy (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_create 

```C++
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create (
    ListLabelledMeasuredArray1DHandle data
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_create\_empty 

```C++
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_empty () 
```




<hr>



### function AxesLabelledMeasuredArray1D\_destroy 

```C++
void AxesLabelledMeasuredArray1D_destroy (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_empty 

```C++
bool AxesLabelledMeasuredArray1D_empty (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_equal 

```C++
bool AxesLabelledMeasuredArray1D_equal (
    AxesLabelledMeasuredArray1DHandle handle,
    AxesLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_erase\_at 

```C++
void AxesLabelledMeasuredArray1D_erase_at (
    AxesLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_from\_json\_string 

```C++
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_index 

```C++
size_t AxesLabelledMeasuredArray1D_index (
    AxesLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_intersection 

```C++
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_intersection (
    AxesLabelledMeasuredArray1DHandle handle,
    AxesLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_items 

```C++
size_t AxesLabelledMeasuredArray1D_items (
    AxesLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_not\_equal 

```C++
bool AxesLabelledMeasuredArray1D_not_equal (
    AxesLabelledMeasuredArray1DHandle handle,
    AxesLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_push\_back 

```C++
void AxesLabelledMeasuredArray1D_push_back (
    AxesLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_size 

```C++
size_t AxesLabelledMeasuredArray1D_size (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray1D\_to\_json\_string 

```C++
StringHandle AxesLabelledMeasuredArray1D_to_json_string (
    AxesLabelledMeasuredArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesLabelledMeasuredArray1D_c_api.h`

