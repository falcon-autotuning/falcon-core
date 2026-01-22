

# File AxesDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesDouble\_c\_api.h**](AxesDouble__c__api_8h.md)

[Go to the source code of this file](AxesDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/ListDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesDoubleHandle**](#typedef-axesdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**AxesDouble\_at**](#function-axesdouble_at) (AxesDoubleHandle handle, size\_t idx) <br> |
|  void | [**AxesDouble\_clear**](#function-axesdouble_clear) (AxesDoubleHandle handle) <br> |
|  bool | [**AxesDouble\_contains**](#function-axesdouble_contains) (AxesDoubleHandle handle, double value) <br> |
|  AxesDoubleHandle | [**AxesDouble\_copy**](#function-axesdouble_copy) (AxesDoubleHandle handle) <br> |
|  AxesDoubleHandle | [**AxesDouble\_create**](#function-axesdouble_create) (ListDoubleHandle data) <br> |
|  AxesDoubleHandle | [**AxesDouble\_create\_empty**](#function-axesdouble_create_empty) () <br> |
|  void | [**AxesDouble\_destroy**](#function-axesdouble_destroy) (AxesDoubleHandle handle) <br> |
|  bool | [**AxesDouble\_empty**](#function-axesdouble_empty) (AxesDoubleHandle handle) <br> |
|  bool | [**AxesDouble\_equal**](#function-axesdouble_equal) (AxesDoubleHandle handle, AxesDoubleHandle other) <br> |
|  void | [**AxesDouble\_erase\_at**](#function-axesdouble_erase_at) (AxesDoubleHandle handle, size\_t idx) <br> |
|  AxesDoubleHandle | [**AxesDouble\_from\_json\_string**](#function-axesdouble_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesDouble\_index**](#function-axesdouble_index) (AxesDoubleHandle handle, double value) <br> |
|  AxesDoubleHandle | [**AxesDouble\_intersection**](#function-axesdouble_intersection) (AxesDoubleHandle handle, AxesDoubleHandle other) <br> |
|  size\_t | [**AxesDouble\_items**](#function-axesdouble_items) (AxesDoubleHandle handle, double \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesDouble\_not\_equal**](#function-axesdouble_not_equal) (AxesDoubleHandle handle, AxesDoubleHandle other) <br> |
|  void | [**AxesDouble\_push\_back**](#function-axesdouble_push_back) (AxesDoubleHandle handle, double value) <br> |
|  size\_t | [**AxesDouble\_size**](#function-axesdouble_size) (AxesDoubleHandle handle) <br> |
|  StringHandle | [**AxesDouble\_to\_json\_string**](#function-axesdouble_to_json_string) (AxesDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef AxesDoubleHandle 

```C++
typedef void* AxesDoubleHandle;
```




<hr>
## Public Functions Documentation




### function AxesDouble\_at 

```C++
double AxesDouble_at (
    AxesDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function AxesDouble\_clear 

```C++
void AxesDouble_clear (
    AxesDoubleHandle handle
) 
```




<hr>



### function AxesDouble\_contains 

```C++
bool AxesDouble_contains (
    AxesDoubleHandle handle,
    double value
) 
```




<hr>



### function AxesDouble\_copy 

```C++
AxesDoubleHandle AxesDouble_copy (
    AxesDoubleHandle handle
) 
```




<hr>



### function AxesDouble\_create 

```C++
AxesDoubleHandle AxesDouble_create (
    ListDoubleHandle data
) 
```




<hr>



### function AxesDouble\_create\_empty 

```C++
AxesDoubleHandle AxesDouble_create_empty () 
```




<hr>



### function AxesDouble\_destroy 

```C++
void AxesDouble_destroy (
    AxesDoubleHandle handle
) 
```




<hr>



### function AxesDouble\_empty 

```C++
bool AxesDouble_empty (
    AxesDoubleHandle handle
) 
```




<hr>



### function AxesDouble\_equal 

```C++
bool AxesDouble_equal (
    AxesDoubleHandle handle,
    AxesDoubleHandle other
) 
```




<hr>



### function AxesDouble\_erase\_at 

```C++
void AxesDouble_erase_at (
    AxesDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function AxesDouble\_from\_json\_string 

```C++
AxesDoubleHandle AxesDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesDouble\_index 

```C++
size_t AxesDouble_index (
    AxesDoubleHandle handle,
    double value
) 
```




<hr>



### function AxesDouble\_intersection 

```C++
AxesDoubleHandle AxesDouble_intersection (
    AxesDoubleHandle handle,
    AxesDoubleHandle other
) 
```




<hr>



### function AxesDouble\_items 

```C++
size_t AxesDouble_items (
    AxesDoubleHandle handle,
    double * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesDouble\_not\_equal 

```C++
bool AxesDouble_not_equal (
    AxesDoubleHandle handle,
    AxesDoubleHandle other
) 
```




<hr>



### function AxesDouble\_push\_back 

```C++
void AxesDouble_push_back (
    AxesDoubleHandle handle,
    double value
) 
```




<hr>



### function AxesDouble\_size 

```C++
size_t AxesDouble_size (
    AxesDoubleHandle handle
) 
```




<hr>



### function AxesDouble\_to\_json\_string 

```C++
StringHandle AxesDouble_to_json_string (
    AxesDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesDouble_c_api.h`

