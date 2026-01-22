

# File MapStringBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapStringBool\_c\_api.h**](MapStringBool__c__api_8h.md)

[Go to the source code of this file](MapStringBool__c__api_8h_source.md)



* `#include "falcon_core/generic/ListPairStringBool_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/ListBool_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapStringBoolHandle**](#typedef-mapstringboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**MapStringBool\_at**](#function-mapstringbool_at) (MapStringBoolHandle handle, StringHandle key) <br> |
|  void | [**MapStringBool\_clear**](#function-mapstringbool_clear) (MapStringBoolHandle handle) <br> |
|  bool | [**MapStringBool\_contains**](#function-mapstringbool_contains) (MapStringBoolHandle handle, StringHandle key) <br> |
|  MapStringBoolHandle | [**MapStringBool\_copy**](#function-mapstringbool_copy) (MapStringBoolHandle handle) <br> |
|  MapStringBoolHandle | [**MapStringBool\_create**](#function-mapstringbool_create) (PairStringBoolHandle \* data, size\_t count) <br> |
|  MapStringBoolHandle | [**MapStringBool\_create\_empty**](#function-mapstringbool_create_empty) () <br> |
|  void | [**MapStringBool\_destroy**](#function-mapstringbool_destroy) (MapStringBoolHandle handle) <br> |
|  bool | [**MapStringBool\_empty**](#function-mapstringbool_empty) (MapStringBoolHandle handle) <br> |
|  bool | [**MapStringBool\_equal**](#function-mapstringbool_equal) (MapStringBoolHandle handle, MapStringBoolHandle other) <br> |
|  void | [**MapStringBool\_erase**](#function-mapstringbool_erase) (MapStringBoolHandle handle, StringHandle key) <br> |
|  MapStringBoolHandle | [**MapStringBool\_from\_json\_string**](#function-mapstringbool_from_json_string) (StringHandle json) <br> |
|  void | [**MapStringBool\_insert**](#function-mapstringbool_insert) (MapStringBoolHandle handle, StringHandle key, bool value) <br> |
|  void | [**MapStringBool\_insert\_or\_assign**](#function-mapstringbool_insert_or_assign) (MapStringBoolHandle handle, StringHandle key, bool value) <br> |
|  ListPairStringBoolHandle | [**MapStringBool\_items**](#function-mapstringbool_items) (MapStringBoolHandle handle) <br> |
|  ListStringHandle | [**MapStringBool\_keys**](#function-mapstringbool_keys) (MapStringBoolHandle handle) <br> |
|  bool | [**MapStringBool\_not\_equal**](#function-mapstringbool_not_equal) (MapStringBoolHandle handle, MapStringBoolHandle other) <br> |
|  size\_t | [**MapStringBool\_size**](#function-mapstringbool_size) (MapStringBoolHandle handle) <br> |
|  StringHandle | [**MapStringBool\_to\_json\_string**](#function-mapstringbool_to_json_string) (MapStringBoolHandle handle) <br> |
|  ListBoolHandle | [**MapStringBool\_values**](#function-mapstringbool_values) (MapStringBoolHandle handle) <br> |




























## Public Types Documentation




### typedef MapStringBoolHandle 

```C++
typedef void* MapStringBoolHandle;
```




<hr>
## Public Functions Documentation




### function MapStringBool\_at 

```C++
bool MapStringBool_at (
    MapStringBoolHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringBool\_clear 

```C++
void MapStringBool_clear (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_contains 

```C++
bool MapStringBool_contains (
    MapStringBoolHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringBool\_copy 

```C++
MapStringBoolHandle MapStringBool_copy (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_create 

```C++
MapStringBoolHandle MapStringBool_create (
    PairStringBoolHandle * data,
    size_t count
) 
```




<hr>



### function MapStringBool\_create\_empty 

```C++
MapStringBoolHandle MapStringBool_create_empty () 
```




<hr>



### function MapStringBool\_destroy 

```C++
void MapStringBool_destroy (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_empty 

```C++
bool MapStringBool_empty (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_equal 

```C++
bool MapStringBool_equal (
    MapStringBoolHandle handle,
    MapStringBoolHandle other
) 
```




<hr>



### function MapStringBool\_erase 

```C++
void MapStringBool_erase (
    MapStringBoolHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringBool\_from\_json\_string 

```C++
MapStringBoolHandle MapStringBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapStringBool\_insert 

```C++
void MapStringBool_insert (
    MapStringBoolHandle handle,
    StringHandle key,
    bool value
) 
```




<hr>



### function MapStringBool\_insert\_or\_assign 

```C++
void MapStringBool_insert_or_assign (
    MapStringBoolHandle handle,
    StringHandle key,
    bool value
) 
```




<hr>



### function MapStringBool\_items 

```C++
ListPairStringBoolHandle MapStringBool_items (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_keys 

```C++
ListStringHandle MapStringBool_keys (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_not\_equal 

```C++
bool MapStringBool_not_equal (
    MapStringBoolHandle handle,
    MapStringBoolHandle other
) 
```




<hr>



### function MapStringBool\_size 

```C++
size_t MapStringBool_size (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_to\_json\_string 

```C++
StringHandle MapStringBool_to_json_string (
    MapStringBoolHandle handle
) 
```




<hr>



### function MapStringBool\_values 

```C++
ListBoolHandle MapStringBool_values (
    MapStringBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapStringBool_c_api.h`

