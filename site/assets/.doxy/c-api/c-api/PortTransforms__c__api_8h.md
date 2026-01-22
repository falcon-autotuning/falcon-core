

# File PortTransforms\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**port\_transforms**](dir_d9b7dfc8594864a30460f4237d4753dd.md) **>** [**PortTransforms\_c\_api.h**](PortTransforms__c__api_8h.md)

[Go to the source code of this file](PortTransforms__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/ListPortTransform_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PortTransformsHandle**](#typedef-porttransformshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PortTransformHandle | [**PortTransforms\_at**](#function-porttransforms_at) (PortTransformsHandle handle, size\_t idx) <br> |
|  void | [**PortTransforms\_clear**](#function-porttransforms_clear) (PortTransformsHandle handle) <br> |
|  bool | [**PortTransforms\_contains**](#function-porttransforms_contains) (PortTransformsHandle handle, PortTransformHandle value) <br> |
|  PortTransformsHandle | [**PortTransforms\_copy**](#function-porttransforms_copy) (PortTransformsHandle handle) <br> |
|  PortTransformHandle | [**PortTransforms\_create**](#function-porttransforms_create) (ListPortTransformHandle handle) <br> |
|  PortTransformsHandle | [**PortTransforms\_create\_empty**](#function-porttransforms_create_empty) () <br> |
|  void | [**PortTransforms\_destroy**](#function-porttransforms_destroy) (PortTransformsHandle handle) <br> |
|  bool | [**PortTransforms\_empty**](#function-porttransforms_empty) (PortTransformsHandle handle) <br> |
|  bool | [**PortTransforms\_equal**](#function-porttransforms_equal) (PortTransformsHandle handle, PortTransformsHandle other) <br> |
|  void | [**PortTransforms\_erase\_at**](#function-porttransforms_erase_at) (PortTransformsHandle handle, size\_t idx) <br> |
|  PortTransformsHandle | [**PortTransforms\_from\_json\_string**](#function-porttransforms_from_json_string) (StringHandle json) <br> |
|  size\_t | [**PortTransforms\_index**](#function-porttransforms_index) (PortTransformsHandle handle, PortTransformHandle value) <br> |
|  PortTransformsHandle | [**PortTransforms\_intersection**](#function-porttransforms_intersection) (PortTransformsHandle handle, PortTransformsHandle other) <br> |
|  ListPortTransformHandle | [**PortTransforms\_items**](#function-porttransforms_items) (PortTransformsHandle handle) <br> |
|  bool | [**PortTransforms\_not\_equal**](#function-porttransforms_not_equal) (PortTransformsHandle handle, PortTransformsHandle other) <br> |
|  void | [**PortTransforms\_push\_back**](#function-porttransforms_push_back) (PortTransformsHandle handle, PortTransformHandle value) <br> |
|  size\_t | [**PortTransforms\_size**](#function-porttransforms_size) (PortTransformsHandle handle) <br> |
|  StringHandle | [**PortTransforms\_to\_json\_string**](#function-porttransforms_to_json_string) (PortTransformsHandle handle) <br> |
|  ListPortTransformHandle | [**PortTransforms\_transforms**](#function-porttransforms_transforms) (PortTransformsHandle handle) <br> |




























## Public Types Documentation




### typedef PortTransformsHandle 

```C++
typedef void* PortTransformsHandle;
```




<hr>
## Public Functions Documentation




### function PortTransforms\_at 

```C++
PortTransformHandle PortTransforms_at (
    PortTransformsHandle handle,
    size_t idx
) 
```




<hr>



### function PortTransforms\_clear 

```C++
void PortTransforms_clear (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_contains 

```C++
bool PortTransforms_contains (
    PortTransformsHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function PortTransforms\_copy 

```C++
PortTransformsHandle PortTransforms_copy (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_create 

```C++
PortTransformHandle PortTransforms_create (
    ListPortTransformHandle handle
) 
```




<hr>



### function PortTransforms\_create\_empty 

```C++
PortTransformsHandle PortTransforms_create_empty () 
```




<hr>



### function PortTransforms\_destroy 

```C++
void PortTransforms_destroy (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_empty 

```C++
bool PortTransforms_empty (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_equal 

```C++
bool PortTransforms_equal (
    PortTransformsHandle handle,
    PortTransformsHandle other
) 
```




<hr>



### function PortTransforms\_erase\_at 

```C++
void PortTransforms_erase_at (
    PortTransformsHandle handle,
    size_t idx
) 
```




<hr>



### function PortTransforms\_from\_json\_string 

```C++
PortTransformsHandle PortTransforms_from_json_string (
    StringHandle json
) 
```




<hr>



### function PortTransforms\_index 

```C++
size_t PortTransforms_index (
    PortTransformsHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function PortTransforms\_intersection 

```C++
PortTransformsHandle PortTransforms_intersection (
    PortTransformsHandle handle,
    PortTransformsHandle other
) 
```




<hr>



### function PortTransforms\_items 

```C++
ListPortTransformHandle PortTransforms_items (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_not\_equal 

```C++
bool PortTransforms_not_equal (
    PortTransformsHandle handle,
    PortTransformsHandle other
) 
```




<hr>



### function PortTransforms\_push\_back 

```C++
void PortTransforms_push_back (
    PortTransformsHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function PortTransforms\_size 

```C++
size_t PortTransforms_size (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_to\_json\_string 

```C++
StringHandle PortTransforms_to_json_string (
    PortTransformsHandle handle
) 
```




<hr>



### function PortTransforms\_transforms 

```C++
ListPortTransformHandle PortTransforms_transforms (
    PortTransformsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/instrument_interfaces/port_transforms/PortTransforms_c_api.h`

