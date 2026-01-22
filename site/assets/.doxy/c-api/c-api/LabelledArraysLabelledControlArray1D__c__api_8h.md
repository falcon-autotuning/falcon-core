

# File LabelledArraysLabelledControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledArraysLabelledControlArray1D\_c\_api.h**](LabelledArraysLabelledControlArray1D__c__api_8h.md)

[Go to the source code of this file](LabelledArraysLabelledControlArray1D__c__api_8h_source.md)



* `#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"`
* `#include "falcon_core/generic/ListAcquisitionContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledArraysLabelledControlArray1DHandle**](#typedef-labelledarrayslabelledcontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListLabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_arrays**](#function-labelledarrayslabelledcontrolarray1d_arrays) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  LabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_at**](#function-labelledarrayslabelledcontrolarray1d_at) (LabelledArraysLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  void | [**LabelledArraysLabelledControlArray1D\_clear**](#function-labelledarrayslabelledcontrolarray1d_clear) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_contains**](#function-labelledarrayslabelledcontrolarray1d_contains) (LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  LabelledArraysLabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_copy**](#function-labelledarrayslabelledcontrolarray1d_copy) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  LabelledArraysLabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_create**](#function-labelledarrayslabelledcontrolarray1d_create) (ListLabelledControlArray1DHandle arrays) <br> |
|  void | [**LabelledArraysLabelledControlArray1D\_destroy**](#function-labelledarrayslabelledcontrolarray1d_destroy) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_empty**](#function-labelledarrayslabelledcontrolarray1d_empty) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_equal**](#function-labelledarrayslabelledcontrolarray1d_equal) (LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) <br> |
|  void | [**LabelledArraysLabelledControlArray1D\_erase\_at**](#function-labelledarrayslabelledcontrolarray1d_erase_at) (LabelledArraysLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  LabelledArraysLabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_from\_json\_string**](#function-labelledarrayslabelledcontrolarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**LabelledArraysLabelledControlArray1D\_index**](#function-labelledarrayslabelledcontrolarray1d_index) (LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  LabelledArraysLabelledControlArray1DHandle | [**LabelledArraysLabelledControlArray1D\_intersection**](#function-labelledarrayslabelledcontrolarray1d_intersection) (LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_is\_control\_arrays**](#function-labelledarrayslabelledcontrolarray1d_is_control_arrays) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_is\_measured\_arrays**](#function-labelledarrayslabelledcontrolarray1d_is_measured_arrays) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  ListAcquisitionContextHandle | [**LabelledArraysLabelledControlArray1D\_labels**](#function-labelledarrayslabelledcontrolarray1d_labels) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray1D\_not\_equal**](#function-labelledarrayslabelledcontrolarray1d_not_equal) (LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) <br> |
|  void | [**LabelledArraysLabelledControlArray1D\_push\_back**](#function-labelledarrayslabelledcontrolarray1d_push_back) (LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  size\_t | [**LabelledArraysLabelledControlArray1D\_size**](#function-labelledarrayslabelledcontrolarray1d_size) (LabelledArraysLabelledControlArray1DHandle handle) <br> |
|  StringHandle | [**LabelledArraysLabelledControlArray1D\_to\_json\_string**](#function-labelledarrayslabelledcontrolarray1d_to_json_string) (LabelledArraysLabelledControlArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef LabelledArraysLabelledControlArray1DHandle 

```C++
typedef void* LabelledArraysLabelledControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function LabelledArraysLabelledControlArray1D\_arrays 

```C++
ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_at 

```C++
LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at (
    LabelledArraysLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_clear 

```C++
void LabelledArraysLabelledControlArray1D_clear (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_contains 

```C++
bool LabelledArraysLabelledControlArray1D_contains (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_copy 

```C++
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_copy (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_create 

```C++
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create (
    ListLabelledControlArray1DHandle arrays
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_destroy 

```C++
void LabelledArraysLabelledControlArray1D_destroy (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_empty 

```C++
bool LabelledArraysLabelledControlArray1D_empty (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_equal 

```C++
bool LabelledArraysLabelledControlArray1D_equal (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_erase\_at 

```C++
void LabelledArraysLabelledControlArray1D_erase_at (
    LabelledArraysLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_from\_json\_string 

```C++
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_index 

```C++
size_t LabelledArraysLabelledControlArray1D_index (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_intersection 

```C++
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_intersection (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_is\_control\_arrays 

```C++
bool LabelledArraysLabelledControlArray1D_is_control_arrays (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_is\_measured\_arrays 

```C++
bool LabelledArraysLabelledControlArray1D_is_measured_arrays (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_labels 

```C++
ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_not\_equal 

```C++
bool LabelledArraysLabelledControlArray1D_not_equal (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_push\_back 

```C++
void LabelledArraysLabelledControlArray1D_push_back (
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_size 

```C++
size_t LabelledArraysLabelledControlArray1D_size (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray1D\_to\_json\_string 

```C++
StringHandle LabelledArraysLabelledControlArray1D_to_json_string (
    LabelledArraysLabelledControlArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledArraysLabelledControlArray1D_c_api.h`

