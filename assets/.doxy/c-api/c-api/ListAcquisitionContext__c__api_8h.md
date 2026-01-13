

# File ListAcquisitionContext\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListAcquisitionContext\_c\_api.h**](ListAcquisitionContext__c__api_8h.md)

[Go to the source code of this file](ListAcquisitionContext__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListAcquisitionContextHandle**](#typedef-listacquisitioncontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  AcquisitionContextHandle | [**ListAcquisitionContext\_at**](#function-listacquisitioncontext_at) (ListAcquisitionContextHandle handle, size\_t idx) <br> |
|  void | [**ListAcquisitionContext\_clear**](#function-listacquisitioncontext_clear) (ListAcquisitionContextHandle handle) <br> |
|  bool | [**ListAcquisitionContext\_contains**](#function-listacquisitioncontext_contains) (ListAcquisitionContextHandle handle, AcquisitionContextHandle value) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_copy**](#function-listacquisitioncontext_copy) (ListAcquisitionContextHandle handle) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_create**](#function-listacquisitioncontext_create) (AcquisitionContextHandle \* data, size\_t count) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_create\_empty**](#function-listacquisitioncontext_create_empty) () <br> |
|  void | [**ListAcquisitionContext\_destroy**](#function-listacquisitioncontext_destroy) (ListAcquisitionContextHandle handle) <br> |
|  bool | [**ListAcquisitionContext\_empty**](#function-listacquisitioncontext_empty) (ListAcquisitionContextHandle handle) <br> |
|  bool | [**ListAcquisitionContext\_equal**](#function-listacquisitioncontext_equal) (ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other) <br> |
|  void | [**ListAcquisitionContext\_erase\_at**](#function-listacquisitioncontext_erase_at) (ListAcquisitionContextHandle handle, size\_t idx) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_fill\_value**](#function-listacquisitioncontext_fill_value) (size\_t count, AcquisitionContextHandle value) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_from\_json\_string**](#function-listacquisitioncontext_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListAcquisitionContext\_index**](#function-listacquisitioncontext_index) (ListAcquisitionContextHandle handle, AcquisitionContextHandle value) <br> |
|  ListAcquisitionContextHandle | [**ListAcquisitionContext\_intersection**](#function-listacquisitioncontext_intersection) (ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other) <br> |
|  size\_t | [**ListAcquisitionContext\_items**](#function-listacquisitioncontext_items) (ListAcquisitionContextHandle handle, AcquisitionContextHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListAcquisitionContext\_not\_equal**](#function-listacquisitioncontext_not_equal) (ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other) <br> |
|  void | [**ListAcquisitionContext\_push\_back**](#function-listacquisitioncontext_push_back) (ListAcquisitionContextHandle handle, AcquisitionContextHandle value) <br> |
|  size\_t | [**ListAcquisitionContext\_size**](#function-listacquisitioncontext_size) (ListAcquisitionContextHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListAcquisitionContext\_to\_json\_string**](#function-listacquisitioncontext_to_json_string) (ListAcquisitionContextHandle handle) <br> |




























## Public Types Documentation




### typedef ListAcquisitionContextHandle 

```C++
typedef void* ListAcquisitionContextHandle;
```




<hr>
## Public Functions Documentation




### function ListAcquisitionContext\_at 

```C++
AcquisitionContextHandle ListAcquisitionContext_at (
    ListAcquisitionContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListAcquisitionContext\_clear 

```C++
void ListAcquisitionContext_clear (
    ListAcquisitionContextHandle handle
) 
```




<hr>



### function ListAcquisitionContext\_contains 

```C++
bool ListAcquisitionContext_contains (
    ListAcquisitionContextHandle handle,
    AcquisitionContextHandle value
) 
```




<hr>



### function ListAcquisitionContext\_copy 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_copy (
    ListAcquisitionContextHandle handle
) 
```




<hr>



### function ListAcquisitionContext\_create 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_create (
    AcquisitionContextHandle * data,
    size_t count
) 
```




<hr>



### function ListAcquisitionContext\_create\_empty 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_create_empty () 
```




<hr>



### function ListAcquisitionContext\_destroy 

```C++
void ListAcquisitionContext_destroy (
    ListAcquisitionContextHandle handle
) 
```




<hr>



### function ListAcquisitionContext\_empty 

```C++
bool ListAcquisitionContext_empty (
    ListAcquisitionContextHandle handle
) 
```




<hr>



### function ListAcquisitionContext\_equal 

```C++
bool ListAcquisitionContext_equal (
    ListAcquisitionContextHandle handle,
    ListAcquisitionContextHandle other
) 
```




<hr>



### function ListAcquisitionContext\_erase\_at 

```C++
void ListAcquisitionContext_erase_at (
    ListAcquisitionContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListAcquisitionContext\_fill\_value 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_fill_value (
    size_t count,
    AcquisitionContextHandle value
) 
```




<hr>



### function ListAcquisitionContext\_from\_json\_string 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListAcquisitionContext\_index 

```C++
size_t ListAcquisitionContext_index (
    ListAcquisitionContextHandle handle,
    AcquisitionContextHandle value
) 
```




<hr>



### function ListAcquisitionContext\_intersection 

```C++
ListAcquisitionContextHandle ListAcquisitionContext_intersection (
    ListAcquisitionContextHandle handle,
    ListAcquisitionContextHandle other
) 
```




<hr>



### function ListAcquisitionContext\_items 

```C++
size_t ListAcquisitionContext_items (
    ListAcquisitionContextHandle handle,
    AcquisitionContextHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListAcquisitionContext\_not\_equal 

```C++
bool ListAcquisitionContext_not_equal (
    ListAcquisitionContextHandle handle,
    ListAcquisitionContextHandle other
) 
```




<hr>



### function ListAcquisitionContext\_push\_back 

```C++
void ListAcquisitionContext_push_back (
    ListAcquisitionContextHandle handle,
    AcquisitionContextHandle value
) 
```




<hr>



### function ListAcquisitionContext\_size 

```C++
size_t ListAcquisitionContext_size (
    ListAcquisitionContextHandle handle
) 
```




<hr>



### function ListAcquisitionContext\_to\_json\_string 

```C++
StringHandle ListAcquisitionContext_to_json_string (
    ListAcquisitionContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListAcquisitionContext_c_api.h`

