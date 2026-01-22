

# File AxesMeasurementContext\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesMeasurementContext\_c\_api.h**](AxesMeasurementContext__c__api_8h.md)

[Go to the source code of this file](AxesMeasurementContext__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"`
* `#include "falcon_core/generic/ListMeasurementContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesMeasurementContextHandle**](#typedef-axesmeasurementcontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MeasurementContextHandle | [**AxesMeasurementContext\_at**](#function-axesmeasurementcontext_at) (AxesMeasurementContextHandle handle, size\_t idx) <br> |
|  void | [**AxesMeasurementContext\_clear**](#function-axesmeasurementcontext_clear) (AxesMeasurementContextHandle handle) <br> |
|  bool | [**AxesMeasurementContext\_contains**](#function-axesmeasurementcontext_contains) (AxesMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  AxesMeasurementContextHandle | [**AxesMeasurementContext\_copy**](#function-axesmeasurementcontext_copy) (AxesMeasurementContextHandle handle) <br> |
|  AxesMeasurementContextHandle | [**AxesMeasurementContext\_create**](#function-axesmeasurementcontext_create) (ListMeasurementContextHandle data) <br> |
|  AxesMeasurementContextHandle | [**AxesMeasurementContext\_create\_empty**](#function-axesmeasurementcontext_create_empty) () <br> |
|  void | [**AxesMeasurementContext\_destroy**](#function-axesmeasurementcontext_destroy) (AxesMeasurementContextHandle handle) <br> |
|  bool | [**AxesMeasurementContext\_empty**](#function-axesmeasurementcontext_empty) (AxesMeasurementContextHandle handle) <br> |
|  bool | [**AxesMeasurementContext\_equal**](#function-axesmeasurementcontext_equal) (AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) <br> |
|  void | [**AxesMeasurementContext\_erase\_at**](#function-axesmeasurementcontext_erase_at) (AxesMeasurementContextHandle handle, size\_t idx) <br> |
|  AxesMeasurementContextHandle | [**AxesMeasurementContext\_from\_json\_string**](#function-axesmeasurementcontext_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesMeasurementContext\_index**](#function-axesmeasurementcontext_index) (AxesMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  AxesMeasurementContextHandle | [**AxesMeasurementContext\_intersection**](#function-axesmeasurementcontext_intersection) (AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) <br> |
|  size\_t | [**AxesMeasurementContext\_items**](#function-axesmeasurementcontext_items) (AxesMeasurementContextHandle handle, MeasurementContextHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesMeasurementContext\_not\_equal**](#function-axesmeasurementcontext_not_equal) (AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) <br> |
|  void | [**AxesMeasurementContext\_push\_back**](#function-axesmeasurementcontext_push_back) (AxesMeasurementContextHandle handle, MeasurementContextHandle value) <br> |
|  size\_t | [**AxesMeasurementContext\_size**](#function-axesmeasurementcontext_size) (AxesMeasurementContextHandle handle) <br> |
|  StringHandle | [**AxesMeasurementContext\_to\_json\_string**](#function-axesmeasurementcontext_to_json_string) (AxesMeasurementContextHandle handle) <br> |




























## Public Types Documentation




### typedef AxesMeasurementContextHandle 

```C++
typedef void* AxesMeasurementContextHandle;
```




<hr>
## Public Functions Documentation




### function AxesMeasurementContext\_at 

```C++
MeasurementContextHandle AxesMeasurementContext_at (
    AxesMeasurementContextHandle handle,
    size_t idx
) 
```




<hr>



### function AxesMeasurementContext\_clear 

```C++
void AxesMeasurementContext_clear (
    AxesMeasurementContextHandle handle
) 
```




<hr>



### function AxesMeasurementContext\_contains 

```C++
bool AxesMeasurementContext_contains (
    AxesMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function AxesMeasurementContext\_copy 

```C++
AxesMeasurementContextHandle AxesMeasurementContext_copy (
    AxesMeasurementContextHandle handle
) 
```




<hr>



### function AxesMeasurementContext\_create 

```C++
AxesMeasurementContextHandle AxesMeasurementContext_create (
    ListMeasurementContextHandle data
) 
```




<hr>



### function AxesMeasurementContext\_create\_empty 

```C++
AxesMeasurementContextHandle AxesMeasurementContext_create_empty () 
```




<hr>



### function AxesMeasurementContext\_destroy 

```C++
void AxesMeasurementContext_destroy (
    AxesMeasurementContextHandle handle
) 
```




<hr>



### function AxesMeasurementContext\_empty 

```C++
bool AxesMeasurementContext_empty (
    AxesMeasurementContextHandle handle
) 
```




<hr>



### function AxesMeasurementContext\_equal 

```C++
bool AxesMeasurementContext_equal (
    AxesMeasurementContextHandle handle,
    AxesMeasurementContextHandle other
) 
```




<hr>



### function AxesMeasurementContext\_erase\_at 

```C++
void AxesMeasurementContext_erase_at (
    AxesMeasurementContextHandle handle,
    size_t idx
) 
```




<hr>



### function AxesMeasurementContext\_from\_json\_string 

```C++
AxesMeasurementContextHandle AxesMeasurementContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesMeasurementContext\_index 

```C++
size_t AxesMeasurementContext_index (
    AxesMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function AxesMeasurementContext\_intersection 

```C++
AxesMeasurementContextHandle AxesMeasurementContext_intersection (
    AxesMeasurementContextHandle handle,
    AxesMeasurementContextHandle other
) 
```




<hr>



### function AxesMeasurementContext\_items 

```C++
size_t AxesMeasurementContext_items (
    AxesMeasurementContextHandle handle,
    MeasurementContextHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesMeasurementContext\_not\_equal 

```C++
bool AxesMeasurementContext_not_equal (
    AxesMeasurementContextHandle handle,
    AxesMeasurementContextHandle other
) 
```




<hr>



### function AxesMeasurementContext\_push\_back 

```C++
void AxesMeasurementContext_push_back (
    AxesMeasurementContextHandle handle,
    MeasurementContextHandle value
) 
```




<hr>



### function AxesMeasurementContext\_size 

```C++
size_t AxesMeasurementContext_size (
    AxesMeasurementContextHandle handle
) 
```




<hr>



### function AxesMeasurementContext\_to\_json\_string 

```C++
StringHandle AxesMeasurementContext_to_json_string (
    AxesMeasurementContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesMeasurementContext_c_api.h`

