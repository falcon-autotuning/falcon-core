

# File LabelledArraysLabelledMeasuredArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledArraysLabelledMeasuredArray\_c\_api.h**](LabelledArraysLabelledMeasuredArray__c__api_8h.md)

[Go to the source code of this file](LabelledArraysLabelledMeasuredArray__c__api_8h_source.md)



* `#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"`
* `#include "falcon_core/generic/ListAcquisitionContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledArraysLabelledMeasuredArrayHandle**](#typedef-labelledarrayslabelledmeasuredarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListLabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_arrays**](#function-labelledarrayslabelledmeasuredarray_arrays) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_at**](#function-labelledarrayslabelledmeasuredarray_at) (LabelledArraysLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray\_clear**](#function-labelledarrayslabelledmeasuredarray_clear) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_contains**](#function-labelledarrayslabelledmeasuredarray_contains) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  LabelledArraysLabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_copy**](#function-labelledarrayslabelledmeasuredarray_copy) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  LabelledArraysLabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_create**](#function-labelledarrayslabelledmeasuredarray_create) (ListLabelledMeasuredArrayHandle arrays) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray\_destroy**](#function-labelledarrayslabelledmeasuredarray_destroy) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_empty**](#function-labelledarrayslabelledmeasuredarray_empty) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_equal**](#function-labelledarrayslabelledmeasuredarray_equal) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray\_erase\_at**](#function-labelledarrayslabelledmeasuredarray_erase_at) (LabelledArraysLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  LabelledArraysLabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_from\_json\_string**](#function-labelledarrayslabelledmeasuredarray_from_json_string) (StringHandle json) <br> |
|  size\_t | [**LabelledArraysLabelledMeasuredArray\_index**](#function-labelledarrayslabelledmeasuredarray_index) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  LabelledArraysLabelledMeasuredArrayHandle | [**LabelledArraysLabelledMeasuredArray\_intersection**](#function-labelledarrayslabelledmeasuredarray_intersection) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_is\_control\_arrays**](#function-labelledarrayslabelledmeasuredarray_is_control_arrays) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_is\_measured\_arrays**](#function-labelledarrayslabelledmeasuredarray_is_measured_arrays) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  ListAcquisitionContextHandle | [**LabelledArraysLabelledMeasuredArray\_labels**](#function-labelledarrayslabelledmeasuredarray_labels) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledMeasuredArray\_not\_equal**](#function-labelledarrayslabelledmeasuredarray_not_equal) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) <br> |
|  void | [**LabelledArraysLabelledMeasuredArray\_push\_back**](#function-labelledarrayslabelledmeasuredarray_push_back) (LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  size\_t | [**LabelledArraysLabelledMeasuredArray\_size**](#function-labelledarrayslabelledmeasuredarray_size) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |
|  StringHandle | [**LabelledArraysLabelledMeasuredArray\_to\_json\_string**](#function-labelledarrayslabelledmeasuredarray_to_json_string) (LabelledArraysLabelledMeasuredArrayHandle handle) <br> |




























## Public Types Documentation




### typedef LabelledArraysLabelledMeasuredArrayHandle 

```C++
typedef void* LabelledArraysLabelledMeasuredArrayHandle;
```




<hr>
## Public Functions Documentation




### function LabelledArraysLabelledMeasuredArray\_arrays 

```C++
ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_at 

```C++
LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_clear 

```C++
void LabelledArraysLabelledMeasuredArray_clear (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_contains 

```C++
bool LabelledArraysLabelledMeasuredArray_contains (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_copy 

```C++
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_copy (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_create 

```C++
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create (
    ListLabelledMeasuredArrayHandle arrays
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_destroy 

```C++
void LabelledArraysLabelledMeasuredArray_destroy (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_empty 

```C++
bool LabelledArraysLabelledMeasuredArray_empty (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_equal 

```C++
bool LabelledArraysLabelledMeasuredArray_equal (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_erase\_at 

```C++
void LabelledArraysLabelledMeasuredArray_erase_at (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_from\_json\_string 

```C++
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_index 

```C++
size_t LabelledArraysLabelledMeasuredArray_index (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_intersection 

```C++
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_intersection (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_is\_control\_arrays 

```C++
bool LabelledArraysLabelledMeasuredArray_is_control_arrays (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_is\_measured\_arrays 

```C++
bool LabelledArraysLabelledMeasuredArray_is_measured_arrays (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_labels 

```C++
ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_not\_equal 

```C++
bool LabelledArraysLabelledMeasuredArray_not_equal (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_push\_back 

```C++
void LabelledArraysLabelledMeasuredArray_push_back (
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_size 

```C++
size_t LabelledArraysLabelledMeasuredArray_size (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledMeasuredArray\_to\_json\_string 

```C++
StringHandle LabelledArraysLabelledMeasuredArray_to_json_string (
    LabelledArraysLabelledMeasuredArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h`

