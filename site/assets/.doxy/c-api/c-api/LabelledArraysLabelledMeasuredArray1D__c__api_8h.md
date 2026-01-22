

# File LabelledArraysLabelledMeasuredArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledArraysLabelledMeasuredArray1D\_c\_api.h**](LabelledArraysLabelledMeasuredArray1D__c__api_8h.md)

[Go to the source code of this file](LabelledArraysLabelledMeasuredArray1D__c__api_8h_source.md)



* `#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"`
* `#include "falcon_core/generic/ListAcquisitionContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledArraysLabelledMeasuredArray1DHandle**](#typedef-labelledarrayslabelledmeasuredarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListLabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_arrays**](#function-labelledarrayslabelledmeasuredarray1d_arrays) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_at**](#function-labelledarrayslabelledmeasuredarray1d_at) (LabelledArraysLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray1D\_clear**](#function-labelledarrayslabelledmeasuredarray1d_clear) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_contains**](#function-labelledarrayslabelledmeasuredarray1d_contains) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  LabelledArraysLabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_copy**](#function-labelledarrayslabelledmeasuredarray1d_copy) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  LabelledArraysLabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_create**](#function-labelledarrayslabelledmeasuredarray1d_create) (ListLabelledMeasuredArray1DHandle arrays) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray1D\_destroy**](#function-labelledarrayslabelledmeasuredarray1d_destroy) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_empty**](#function-labelledarrayslabelledmeasuredarray1d_empty) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_equal**](#function-labelledarrayslabelledmeasuredarray1d_equal) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray1D\_erase\_at**](#function-labelledarrayslabelledmeasuredarray1d_erase_at) (LabelledArraysLabelledMeasuredArray1DHandle handle, size\_t idx) <br> |
|  LabelledArraysLabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_from\_json\_string**](#function-labelledarrayslabelledmeasuredarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**LabelledArraysLabelledMeasuredArray1D\_index**](#function-labelledarrayslabelledmeasuredarray1d_index) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  LabelledArraysLabelledMeasuredArray1DHandle | [**LabelledArraysLabelledMeasuredArray1D\_intersection**](#function-labelledarrayslabelledmeasuredarray1d_intersection) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_is\_control\_arrays**](#function-labelledarrayslabelledmeasuredarray1d_is_control_arrays) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_is\_measured\_arrays**](#function-labelledarrayslabelledmeasuredarray1d_is_measured_arrays) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  ListAcquisitionContextHandle | [**LabelledArraysLabelledMeasuredArray1D\_labels**](#function-labelledarrayslabelledmeasuredarray1d_labels) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray1D\_not\_equal**](#function-labelledarrayslabelledmeasuredarray1d_not_equal) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray1D\_push\_back**](#function-labelledarrayslabelledmeasuredarray1d_push_back) (LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) <br> |
|  size\_t | [**LabelledArraysLabelledMeasuredArray1D\_size**](#function-labelledarrayslabelledmeasuredarray1d_size) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |
|  StringHandle | [**LabelledArraysLabelledMeasuredArray1D\_to\_json\_string**](#function-labelledarrayslabelledmeasuredarray1d_to_json_string) (LabelledArraysLabelledMeasuredArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef LabelledArraysLabelledMeasuredArray1DHandle 

```C++
typedef void* LabelledArraysLabelledMeasuredArray1DHandle;
```




<hr>
## Public Functions Documentation




### function LabelledArraysLabelledMeasuredArray1D\_arrays 

```C++
ListLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_arrays (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_at 

```C++
LabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_at (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_clear 

```C++
void LabelledArraysLabelledMeasuredArray1D_clear (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_contains 

```C++
bool LabelledArraysLabelledMeasuredArray1D_contains (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_copy 

```C++
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_copy (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_create 

```C++
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_create (
    ListLabelledMeasuredArray1DHandle arrays
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_destroy 

```C++
void LabelledArraysLabelledMeasuredArray1D_destroy (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_empty 

```C++
bool LabelledArraysLabelledMeasuredArray1D_empty (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_equal 

```C++
bool LabelledArraysLabelledMeasuredArray1D_equal (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_erase\_at 

```C++
void LabelledArraysLabelledMeasuredArray1D_erase_at (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_from\_json\_string 

```C++
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_index 

```C++
size_t LabelledArraysLabelledMeasuredArray1D_index (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_intersection 

```C++
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_intersection (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_is\_control\_arrays 

```C++
bool LabelledArraysLabelledMeasuredArray1D_is_control_arrays (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_is\_measured\_arrays 

```C++
bool LabelledArraysLabelledMeasuredArray1D_is_measured_arrays (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_labels 

```C++
ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray1D_labels (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_not\_equal 

```C++
bool LabelledArraysLabelledMeasuredArray1D_not_equal (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_push\_back 

```C++
void LabelledArraysLabelledMeasuredArray1D_push_back (
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_size 

```C++
size_t LabelledArraysLabelledMeasuredArray1D_size (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray1D\_to\_json\_string 

```C++
StringHandle LabelledArraysLabelledMeasuredArray1D_to_json_string (
    LabelledArraysLabelledMeasuredArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray1D_c_api.h`

