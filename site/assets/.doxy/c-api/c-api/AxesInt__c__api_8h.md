

# File AxesInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesInt\_c\_api.h**](AxesInt__c__api_8h.md)

[Go to the source code of this file](AxesInt__c__api_8h_source.md)



* `#include "falcon_core/generic/ListInt_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesIntHandle**](#typedef-axesinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**AxesInt\_at**](#function-axesint_at) (AxesIntHandle handle, size\_t idx) <br> |
|  void | [**AxesInt\_clear**](#function-axesint_clear) (AxesIntHandle handle) <br> |
|  bool | [**AxesInt\_contains**](#function-axesint_contains) (AxesIntHandle handle, int value) <br> |
|  AxesIntHandle | [**AxesInt\_copy**](#function-axesint_copy) (AxesIntHandle handle) <br> |
|  AxesIntHandle | [**AxesInt\_create**](#function-axesint_create) (ListIntHandle data) <br> |
|  AxesIntHandle | [**AxesInt\_create\_empty**](#function-axesint_create_empty) () <br> |
|  void | [**AxesInt\_destroy**](#function-axesint_destroy) (AxesIntHandle handle) <br> |
|  bool | [**AxesInt\_empty**](#function-axesint_empty) (AxesIntHandle handle) <br> |
|  bool | [**AxesInt\_equal**](#function-axesint_equal) (AxesIntHandle handle, AxesIntHandle other) <br> |
|  void | [**AxesInt\_erase\_at**](#function-axesint_erase_at) (AxesIntHandle handle, size\_t idx) <br> |
|  AxesIntHandle | [**AxesInt\_from\_json\_string**](#function-axesint_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesInt\_index**](#function-axesint_index) (AxesIntHandle handle, int value) <br> |
|  AxesIntHandle | [**AxesInt\_intersection**](#function-axesint_intersection) (AxesIntHandle handle, AxesIntHandle other) <br> |
|  size\_t | [**AxesInt\_items**](#function-axesint_items) (AxesIntHandle handle, int \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesInt\_not\_equal**](#function-axesint_not_equal) (AxesIntHandle handle, AxesIntHandle other) <br> |
|  void | [**AxesInt\_push\_back**](#function-axesint_push_back) (AxesIntHandle handle, int value) <br> |
|  size\_t | [**AxesInt\_size**](#function-axesint_size) (AxesIntHandle handle) <br> |
|  StringHandle | [**AxesInt\_to\_json\_string**](#function-axesint_to_json_string) (AxesIntHandle handle) <br> |




























## Public Types Documentation




### typedef AxesIntHandle 

```C++
typedef void* AxesIntHandle;
```




<hr>
## Public Functions Documentation




### function AxesInt\_at 

```C++
int AxesInt_at (
    AxesIntHandle handle,
    size_t idx
) 
```




<hr>



### function AxesInt\_clear 

```C++
void AxesInt_clear (
    AxesIntHandle handle
) 
```




<hr>



### function AxesInt\_contains 

```C++
bool AxesInt_contains (
    AxesIntHandle handle,
    int value
) 
```




<hr>



### function AxesInt\_copy 

```C++
AxesIntHandle AxesInt_copy (
    AxesIntHandle handle
) 
```




<hr>



### function AxesInt\_create 

```C++
AxesIntHandle AxesInt_create (
    ListIntHandle data
) 
```




<hr>



### function AxesInt\_create\_empty 

```C++
AxesIntHandle AxesInt_create_empty () 
```




<hr>



### function AxesInt\_destroy 

```C++
void AxesInt_destroy (
    AxesIntHandle handle
) 
```




<hr>



### function AxesInt\_empty 

```C++
bool AxesInt_empty (
    AxesIntHandle handle
) 
```




<hr>



### function AxesInt\_equal 

```C++
bool AxesInt_equal (
    AxesIntHandle handle,
    AxesIntHandle other
) 
```




<hr>



### function AxesInt\_erase\_at 

```C++
void AxesInt_erase_at (
    AxesIntHandle handle,
    size_t idx
) 
```




<hr>



### function AxesInt\_from\_json\_string 

```C++
AxesIntHandle AxesInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesInt\_index 

```C++
size_t AxesInt_index (
    AxesIntHandle handle,
    int value
) 
```




<hr>



### function AxesInt\_intersection 

```C++
AxesIntHandle AxesInt_intersection (
    AxesIntHandle handle,
    AxesIntHandle other
) 
```




<hr>



### function AxesInt\_items 

```C++
size_t AxesInt_items (
    AxesIntHandle handle,
    int * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesInt\_not\_equal 

```C++
bool AxesInt_not_equal (
    AxesIntHandle handle,
    AxesIntHandle other
) 
```




<hr>



### function AxesInt\_push\_back 

```C++
void AxesInt_push_back (
    AxesIntHandle handle,
    int value
) 
```




<hr>



### function AxesInt\_size 

```C++
size_t AxesInt_size (
    AxesIntHandle handle
) 
```




<hr>



### function AxesInt\_to\_json\_string 

```C++
StringHandle AxesInt_to_json_string (
    AxesIntHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesInt_c_api.h`

