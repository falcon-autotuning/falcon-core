

# File ListInterpretationContext\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListInterpretationContext\_c\_api.h**](ListInterpretationContext__c__api_8h.md)

[Go to the source code of this file](ListInterpretationContext__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListInterpretationContextHandle**](#typedef-listinterpretationcontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  InterpretationContextHandle | [**ListInterpretationContext\_at**](#function-listinterpretationcontext_at) (ListInterpretationContextHandle handle, size\_t idx) <br> |
|  void | [**ListInterpretationContext\_clear**](#function-listinterpretationcontext_clear) (ListInterpretationContextHandle handle) <br> |
|  bool | [**ListInterpretationContext\_contains**](#function-listinterpretationcontext_contains) (ListInterpretationContextHandle handle, InterpretationContextHandle value) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_copy**](#function-listinterpretationcontext_copy) (ListInterpretationContextHandle handle) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_create**](#function-listinterpretationcontext_create) (InterpretationContextHandle \* data, size\_t count) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_create\_empty**](#function-listinterpretationcontext_create_empty) () <br> |
|  void | [**ListInterpretationContext\_destroy**](#function-listinterpretationcontext_destroy) (ListInterpretationContextHandle handle) <br> |
|  bool | [**ListInterpretationContext\_empty**](#function-listinterpretationcontext_empty) (ListInterpretationContextHandle handle) <br> |
|  bool | [**ListInterpretationContext\_equal**](#function-listinterpretationcontext_equal) (ListInterpretationContextHandle handle, ListInterpretationContextHandle other) <br> |
|  void | [**ListInterpretationContext\_erase\_at**](#function-listinterpretationcontext_erase_at) (ListInterpretationContextHandle handle, size\_t idx) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_fill\_value**](#function-listinterpretationcontext_fill_value) (size\_t count, InterpretationContextHandle value) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_from\_json\_string**](#function-listinterpretationcontext_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListInterpretationContext\_index**](#function-listinterpretationcontext_index) (ListInterpretationContextHandle handle, InterpretationContextHandle value) <br> |
|  ListInterpretationContextHandle | [**ListInterpretationContext\_intersection**](#function-listinterpretationcontext_intersection) (ListInterpretationContextHandle handle, ListInterpretationContextHandle other) <br> |
|  size\_t | [**ListInterpretationContext\_items**](#function-listinterpretationcontext_items) (ListInterpretationContextHandle handle, InterpretationContextHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListInterpretationContext\_not\_equal**](#function-listinterpretationcontext_not_equal) (ListInterpretationContextHandle handle, ListInterpretationContextHandle other) <br> |
|  void | [**ListInterpretationContext\_push\_back**](#function-listinterpretationcontext_push_back) (ListInterpretationContextHandle handle, InterpretationContextHandle value) <br> |
|  size\_t | [**ListInterpretationContext\_size**](#function-listinterpretationcontext_size) (ListInterpretationContextHandle handle) <br> |
|  StringHandle | [**ListInterpretationContext\_to\_json\_string**](#function-listinterpretationcontext_to_json_string) (ListInterpretationContextHandle handle) <br> |




























## Public Types Documentation




### typedef ListInterpretationContextHandle 

```C++
typedef void* ListInterpretationContextHandle;
```




<hr>
## Public Functions Documentation




### function ListInterpretationContext\_at 

```C++
InterpretationContextHandle ListInterpretationContext_at (
    ListInterpretationContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListInterpretationContext\_clear 

```C++
void ListInterpretationContext_clear (
    ListInterpretationContextHandle handle
) 
```




<hr>



### function ListInterpretationContext\_contains 

```C++
bool ListInterpretationContext_contains (
    ListInterpretationContextHandle handle,
    InterpretationContextHandle value
) 
```




<hr>



### function ListInterpretationContext\_copy 

```C++
ListInterpretationContextHandle ListInterpretationContext_copy (
    ListInterpretationContextHandle handle
) 
```




<hr>



### function ListInterpretationContext\_create 

```C++
ListInterpretationContextHandle ListInterpretationContext_create (
    InterpretationContextHandle * data,
    size_t count
) 
```




<hr>



### function ListInterpretationContext\_create\_empty 

```C++
ListInterpretationContextHandle ListInterpretationContext_create_empty () 
```




<hr>



### function ListInterpretationContext\_destroy 

```C++
void ListInterpretationContext_destroy (
    ListInterpretationContextHandle handle
) 
```




<hr>



### function ListInterpretationContext\_empty 

```C++
bool ListInterpretationContext_empty (
    ListInterpretationContextHandle handle
) 
```




<hr>



### function ListInterpretationContext\_equal 

```C++
bool ListInterpretationContext_equal (
    ListInterpretationContextHandle handle,
    ListInterpretationContextHandle other
) 
```




<hr>



### function ListInterpretationContext\_erase\_at 

```C++
void ListInterpretationContext_erase_at (
    ListInterpretationContextHandle handle,
    size_t idx
) 
```




<hr>



### function ListInterpretationContext\_fill\_value 

```C++
ListInterpretationContextHandle ListInterpretationContext_fill_value (
    size_t count,
    InterpretationContextHandle value
) 
```




<hr>



### function ListInterpretationContext\_from\_json\_string 

```C++
ListInterpretationContextHandle ListInterpretationContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListInterpretationContext\_index 

```C++
size_t ListInterpretationContext_index (
    ListInterpretationContextHandle handle,
    InterpretationContextHandle value
) 
```




<hr>



### function ListInterpretationContext\_intersection 

```C++
ListInterpretationContextHandle ListInterpretationContext_intersection (
    ListInterpretationContextHandle handle,
    ListInterpretationContextHandle other
) 
```




<hr>



### function ListInterpretationContext\_items 

```C++
size_t ListInterpretationContext_items (
    ListInterpretationContextHandle handle,
    InterpretationContextHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListInterpretationContext\_not\_equal 

```C++
bool ListInterpretationContext_not_equal (
    ListInterpretationContextHandle handle,
    ListInterpretationContextHandle other
) 
```




<hr>



### function ListInterpretationContext\_push\_back 

```C++
void ListInterpretationContext_push_back (
    ListInterpretationContextHandle handle,
    InterpretationContextHandle value
) 
```




<hr>



### function ListInterpretationContext\_size 

```C++
size_t ListInterpretationContext_size (
    ListInterpretationContextHandle handle
) 
```




<hr>



### function ListInterpretationContext\_to\_json\_string 

```C++
StringHandle ListInterpretationContext_to_json_string (
    ListInterpretationContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListInterpretationContext_c_api.h`

