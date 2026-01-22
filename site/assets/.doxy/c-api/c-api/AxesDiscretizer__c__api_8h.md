

# File AxesDiscretizer\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesDiscretizer\_c\_api.h**](AxesDiscretizer__c__api_8h.md)

[Go to the source code of this file](AxesDiscretizer__c__api_8h_source.md)



* `#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"`
* `#include "falcon_core/generic/ListDiscretizer_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesDiscretizerHandle**](#typedef-axesdiscretizerhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DiscretizerHandle | [**AxesDiscretizer\_at**](#function-axesdiscretizer_at) (AxesDiscretizerHandle handle, size\_t idx) <br> |
|  void | [**AxesDiscretizer\_clear**](#function-axesdiscretizer_clear) (AxesDiscretizerHandle handle) <br> |
|  bool | [**AxesDiscretizer\_contains**](#function-axesdiscretizer_contains) (AxesDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  AxesDiscretizerHandle | [**AxesDiscretizer\_copy**](#function-axesdiscretizer_copy) (AxesDiscretizerHandle handle) <br> |
|  AxesDiscretizerHandle | [**AxesDiscretizer\_create**](#function-axesdiscretizer_create) (ListDiscretizerHandle data) <br> |
|  AxesDiscretizerHandle | [**AxesDiscretizer\_create\_empty**](#function-axesdiscretizer_create_empty) () <br> |
|  void | [**AxesDiscretizer\_destroy**](#function-axesdiscretizer_destroy) (AxesDiscretizerHandle handle) <br> |
|  bool | [**AxesDiscretizer\_empty**](#function-axesdiscretizer_empty) (AxesDiscretizerHandle handle) <br> |
|  bool | [**AxesDiscretizer\_equal**](#function-axesdiscretizer_equal) (AxesDiscretizerHandle handle, AxesDiscretizerHandle other) <br> |
|  void | [**AxesDiscretizer\_erase\_at**](#function-axesdiscretizer_erase_at) (AxesDiscretizerHandle handle, size\_t idx) <br> |
|  AxesDiscretizerHandle | [**AxesDiscretizer\_from\_json\_string**](#function-axesdiscretizer_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesDiscretizer\_index**](#function-axesdiscretizer_index) (AxesDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  AxesDiscretizerHandle | [**AxesDiscretizer\_intersection**](#function-axesdiscretizer_intersection) (AxesDiscretizerHandle handle, AxesDiscretizerHandle other) <br> |
|  size\_t | [**AxesDiscretizer\_items**](#function-axesdiscretizer_items) (AxesDiscretizerHandle handle, DiscretizerHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesDiscretizer\_not\_equal**](#function-axesdiscretizer_not_equal) (AxesDiscretizerHandle handle, AxesDiscretizerHandle other) <br> |
|  void | [**AxesDiscretizer\_push\_back**](#function-axesdiscretizer_push_back) (AxesDiscretizerHandle handle, DiscretizerHandle value) <br> |
|  size\_t | [**AxesDiscretizer\_size**](#function-axesdiscretizer_size) (AxesDiscretizerHandle handle) <br> |
|  StringHandle | [**AxesDiscretizer\_to\_json\_string**](#function-axesdiscretizer_to_json_string) (AxesDiscretizerHandle handle) <br> |




























## Public Types Documentation




### typedef AxesDiscretizerHandle 

```C++
typedef void* AxesDiscretizerHandle;
```




<hr>
## Public Functions Documentation




### function AxesDiscretizer\_at 

```C++
DiscretizerHandle AxesDiscretizer_at (
    AxesDiscretizerHandle handle,
    size_t idx
) 
```




<hr>



### function AxesDiscretizer\_clear 

```C++
void AxesDiscretizer_clear (
    AxesDiscretizerHandle handle
) 
```




<hr>



### function AxesDiscretizer\_contains 

```C++
bool AxesDiscretizer_contains (
    AxesDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function AxesDiscretizer\_copy 

```C++
AxesDiscretizerHandle AxesDiscretizer_copy (
    AxesDiscretizerHandle handle
) 
```




<hr>



### function AxesDiscretizer\_create 

```C++
AxesDiscretizerHandle AxesDiscretizer_create (
    ListDiscretizerHandle data
) 
```




<hr>



### function AxesDiscretizer\_create\_empty 

```C++
AxesDiscretizerHandle AxesDiscretizer_create_empty () 
```




<hr>



### function AxesDiscretizer\_destroy 

```C++
void AxesDiscretizer_destroy (
    AxesDiscretizerHandle handle
) 
```




<hr>



### function AxesDiscretizer\_empty 

```C++
bool AxesDiscretizer_empty (
    AxesDiscretizerHandle handle
) 
```




<hr>



### function AxesDiscretizer\_equal 

```C++
bool AxesDiscretizer_equal (
    AxesDiscretizerHandle handle,
    AxesDiscretizerHandle other
) 
```




<hr>



### function AxesDiscretizer\_erase\_at 

```C++
void AxesDiscretizer_erase_at (
    AxesDiscretizerHandle handle,
    size_t idx
) 
```




<hr>



### function AxesDiscretizer\_from\_json\_string 

```C++
AxesDiscretizerHandle AxesDiscretizer_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesDiscretizer\_index 

```C++
size_t AxesDiscretizer_index (
    AxesDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function AxesDiscretizer\_intersection 

```C++
AxesDiscretizerHandle AxesDiscretizer_intersection (
    AxesDiscretizerHandle handle,
    AxesDiscretizerHandle other
) 
```




<hr>



### function AxesDiscretizer\_items 

```C++
size_t AxesDiscretizer_items (
    AxesDiscretizerHandle handle,
    DiscretizerHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesDiscretizer\_not\_equal 

```C++
bool AxesDiscretizer_not_equal (
    AxesDiscretizerHandle handle,
    AxesDiscretizerHandle other
) 
```




<hr>



### function AxesDiscretizer\_push\_back 

```C++
void AxesDiscretizer_push_back (
    AxesDiscretizerHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function AxesDiscretizer\_size 

```C++
size_t AxesDiscretizer_size (
    AxesDiscretizerHandle handle
) 
```




<hr>



### function AxesDiscretizer\_to\_json\_string 

```C++
StringHandle AxesDiscretizer_to_json_string (
    AxesDiscretizerHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesDiscretizer_c_api.h`

