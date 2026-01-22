

# File AxesMapStringBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesMapStringBool\_c\_api.h**](AxesMapStringBool__c__api_8h.md)

[Go to the source code of this file](AxesMapStringBool__c__api_8h_source.md)



* `#include "falcon_core/generic/ListMapStringBool_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesMapStringBoolHandle**](#typedef-axesmapstringboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MapStringBoolHandle | [**AxesMapStringBool\_at**](#function-axesmapstringbool_at) (AxesMapStringBoolHandle handle, size\_t idx) <br> |
|  void | [**AxesMapStringBool\_clear**](#function-axesmapstringbool_clear) (AxesMapStringBoolHandle handle) <br> |
|  bool | [**AxesMapStringBool\_contains**](#function-axesmapstringbool_contains) (AxesMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  AxesMapStringBoolHandle | [**AxesMapStringBool\_copy**](#function-axesmapstringbool_copy) (AxesMapStringBoolHandle handle) <br> |
|  AxesMapStringBoolHandle | [**AxesMapStringBool\_create**](#function-axesmapstringbool_create) (ListMapStringBoolHandle data) <br> |
|  AxesMapStringBoolHandle | [**AxesMapStringBool\_create\_empty**](#function-axesmapstringbool_create_empty) () <br> |
|  void | [**AxesMapStringBool\_destroy**](#function-axesmapstringbool_destroy) (AxesMapStringBoolHandle handle) <br> |
|  bool | [**AxesMapStringBool\_empty**](#function-axesmapstringbool_empty) (AxesMapStringBoolHandle handle) <br> |
|  bool | [**AxesMapStringBool\_equal**](#function-axesmapstringbool_equal) (AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other) <br> |
|  void | [**AxesMapStringBool\_erase\_at**](#function-axesmapstringbool_erase_at) (AxesMapStringBoolHandle handle, size\_t idx) <br> |
|  AxesMapStringBoolHandle | [**AxesMapStringBool\_from\_json\_string**](#function-axesmapstringbool_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesMapStringBool\_index**](#function-axesmapstringbool_index) (AxesMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  AxesMapStringBoolHandle | [**AxesMapStringBool\_intersection**](#function-axesmapstringbool_intersection) (AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other) <br> |
|  size\_t | [**AxesMapStringBool\_items**](#function-axesmapstringbool_items) (AxesMapStringBoolHandle handle, MapStringBoolHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesMapStringBool\_not\_equal**](#function-axesmapstringbool_not_equal) (AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other) <br> |
|  void | [**AxesMapStringBool\_push\_back**](#function-axesmapstringbool_push_back) (AxesMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  size\_t | [**AxesMapStringBool\_size**](#function-axesmapstringbool_size) (AxesMapStringBoolHandle handle) <br> |
|  StringHandle | [**AxesMapStringBool\_to\_json\_string**](#function-axesmapstringbool_to_json_string) (AxesMapStringBoolHandle handle) <br> |




























## Public Types Documentation




### typedef AxesMapStringBoolHandle 

```C++
typedef void* AxesMapStringBoolHandle;
```




<hr>
## Public Functions Documentation




### function AxesMapStringBool\_at 

```C++
MapStringBoolHandle AxesMapStringBool_at (
    AxesMapStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function AxesMapStringBool\_clear 

```C++
void AxesMapStringBool_clear (
    AxesMapStringBoolHandle handle
) 
```




<hr>



### function AxesMapStringBool\_contains 

```C++
bool AxesMapStringBool_contains (
    AxesMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function AxesMapStringBool\_copy 

```C++
AxesMapStringBoolHandle AxesMapStringBool_copy (
    AxesMapStringBoolHandle handle
) 
```




<hr>



### function AxesMapStringBool\_create 

```C++
AxesMapStringBoolHandle AxesMapStringBool_create (
    ListMapStringBoolHandle data
) 
```




<hr>



### function AxesMapStringBool\_create\_empty 

```C++
AxesMapStringBoolHandle AxesMapStringBool_create_empty () 
```




<hr>



### function AxesMapStringBool\_destroy 

```C++
void AxesMapStringBool_destroy (
    AxesMapStringBoolHandle handle
) 
```




<hr>



### function AxesMapStringBool\_empty 

```C++
bool AxesMapStringBool_empty (
    AxesMapStringBoolHandle handle
) 
```




<hr>



### function AxesMapStringBool\_equal 

```C++
bool AxesMapStringBool_equal (
    AxesMapStringBoolHandle handle,
    AxesMapStringBoolHandle other
) 
```




<hr>



### function AxesMapStringBool\_erase\_at 

```C++
void AxesMapStringBool_erase_at (
    AxesMapStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function AxesMapStringBool\_from\_json\_string 

```C++
AxesMapStringBoolHandle AxesMapStringBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesMapStringBool\_index 

```C++
size_t AxesMapStringBool_index (
    AxesMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function AxesMapStringBool\_intersection 

```C++
AxesMapStringBoolHandle AxesMapStringBool_intersection (
    AxesMapStringBoolHandle handle,
    AxesMapStringBoolHandle other
) 
```




<hr>



### function AxesMapStringBool\_items 

```C++
size_t AxesMapStringBool_items (
    AxesMapStringBoolHandle handle,
    MapStringBoolHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesMapStringBool\_not\_equal 

```C++
bool AxesMapStringBool_not_equal (
    AxesMapStringBoolHandle handle,
    AxesMapStringBoolHandle other
) 
```




<hr>



### function AxesMapStringBool\_push\_back 

```C++
void AxesMapStringBool_push_back (
    AxesMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function AxesMapStringBool\_size 

```C++
size_t AxesMapStringBool_size (
    AxesMapStringBoolHandle handle
) 
```




<hr>



### function AxesMapStringBool\_to\_json\_string 

```C++
StringHandle AxesMapStringBool_to_json_string (
    AxesMapStringBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesMapStringBool_c_api.h`

