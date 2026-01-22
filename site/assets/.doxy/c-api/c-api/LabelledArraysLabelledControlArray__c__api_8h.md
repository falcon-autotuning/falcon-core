

# File LabelledArraysLabelledControlArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledArraysLabelledControlArray\_c\_api.h**](LabelledArraysLabelledControlArray__c__api_8h.md)

[Go to the source code of this file](LabelledArraysLabelledControlArray__c__api_8h_source.md)



* `#include "falcon_core/generic/ListLabelledControlArray_c_api.h"`
* `#include "falcon_core/generic/ListAcquisitionContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledArraysLabelledControlArrayHandle**](#typedef-labelledarrayslabelledcontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListLabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_arrays**](#function-labelledarrayslabelledcontrolarray_arrays) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  LabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_at**](#function-labelledarrayslabelledcontrolarray_at) (LabelledArraysLabelledControlArrayHandle handle, size\_t idx) <br> |
|  void | [**LabelledArraysLabelledControlArray\_clear**](#function-labelledarrayslabelledcontrolarray_clear) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_contains**](#function-labelledarrayslabelledcontrolarray_contains) (LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  LabelledArraysLabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_copy**](#function-labelledarrayslabelledcontrolarray_copy) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  LabelledArraysLabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_create**](#function-labelledarrayslabelledcontrolarray_create) (ListLabelledControlArrayHandle arrays) <br> |
|  void | [**LabelledArraysLabelledControlArray\_destroy**](#function-labelledarrayslabelledcontrolarray_destroy) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_empty**](#function-labelledarrayslabelledcontrolarray_empty) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_equal**](#function-labelledarrayslabelledcontrolarray_equal) (LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) <br> |
|  void | [**LabelledArraysLabelledControlArray\_erase\_at**](#function-labelledarrayslabelledcontrolarray_erase_at) (LabelledArraysLabelledControlArrayHandle handle, size\_t idx) <br> |
|  LabelledArraysLabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_from\_json\_string**](#function-labelledarrayslabelledcontrolarray_from_json_string) (StringHandle json) <br> |
|  size\_t | [**LabelledArraysLabelledControlArray\_index**](#function-labelledarrayslabelledcontrolarray_index) (LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  LabelledArraysLabelledControlArrayHandle | [**LabelledArraysLabelledControlArray\_intersection**](#function-labelledarrayslabelledcontrolarray_intersection) (LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_is\_control\_arrays**](#function-labelledarrayslabelledcontrolarray_is_control_arrays) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_is\_measured\_arrays**](#function-labelledarrayslabelledcontrolarray_is_measured_arrays) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  ListAcquisitionContextHandle | [**LabelledArraysLabelledControlArray\_labels**](#function-labelledarrayslabelledcontrolarray_labels) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledArraysLabelledControlArray\_not\_equal**](#function-labelledarrayslabelledcontrolarray_not_equal) (LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) <br> |
|  void | [**LabelledArraysLabelledControlArray\_push\_back**](#function-labelledarrayslabelledcontrolarray_push_back) (LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  size\_t | [**LabelledArraysLabelledControlArray\_size**](#function-labelledarrayslabelledcontrolarray_size) (LabelledArraysLabelledControlArrayHandle handle) <br> |
|  StringHandle | [**LabelledArraysLabelledControlArray\_to\_json\_string**](#function-labelledarrayslabelledcontrolarray_to_json_string) (LabelledArraysLabelledControlArrayHandle handle) <br> |




























## Public Types Documentation




### typedef LabelledArraysLabelledControlArrayHandle 

```C++
typedef void* LabelledArraysLabelledControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function LabelledArraysLabelledControlArray\_arrays 

```C++
ListLabelledControlArrayHandle LabelledArraysLabelledControlArray_arrays (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_at 

```C++
LabelledControlArrayHandle LabelledArraysLabelledControlArray_at (
    LabelledArraysLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_clear 

```C++
void LabelledArraysLabelledControlArray_clear (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_contains 

```C++
bool LabelledArraysLabelledControlArray_contains (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_copy 

```C++
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_copy (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_create 

```C++
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_create (
    ListLabelledControlArrayHandle arrays
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_destroy 

```C++
void LabelledArraysLabelledControlArray_destroy (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_empty 

```C++
bool LabelledArraysLabelledControlArray_empty (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_equal 

```C++
bool LabelledArraysLabelledControlArray_equal (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_erase\_at 

```C++
void LabelledArraysLabelledControlArray_erase_at (
    LabelledArraysLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_from\_json\_string 

```C++
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_index 

```C++
size_t LabelledArraysLabelledControlArray_index (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_intersection 

```C++
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_intersection (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_is\_control\_arrays 

```C++
bool LabelledArraysLabelledControlArray_is_control_arrays (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_is\_measured\_arrays 

```C++
bool LabelledArraysLabelledControlArray_is_measured_arrays (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_labels 

```C++
ListAcquisitionContextHandle LabelledArraysLabelledControlArray_labels (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_not\_equal 

```C++
bool LabelledArraysLabelledControlArray_not_equal (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_push\_back 

```C++
void LabelledArraysLabelledControlArray_push_back (
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_size 

```C++
size_t LabelledArraysLabelledControlArray_size (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledArraysLabelledControlArray\_to\_json\_string 

```C++
StringHandle LabelledArraysLabelledControlArray_to_json_string (
    LabelledArraysLabelledControlArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledArraysLabelledControlArray_c_api.h`

