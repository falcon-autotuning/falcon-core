

# File MapInterpretationContextString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInterpretationContextString\_c\_api.h**](MapInterpretationContextString__c__api_8h.md)

[Go to the source code of this file](MapInterpretationContextString__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextString_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapInterpretationContextStringHandle**](#typedef-mapinterpretationcontextstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  [**StringHandle**](structstring.md) | [**MapInterpretationContextString\_at**](#function-mapinterpretationcontextstring_at) (MapInterpretationContextStringHandle handle, InterpretationContextHandle key) <br> |
|  void | [**MapInterpretationContextString\_clear**](#function-mapinterpretationcontextstring_clear) (MapInterpretationContextStringHandle handle) <br> |
|  bool | [**MapInterpretationContextString\_contains**](#function-mapinterpretationcontextstring_contains) (MapInterpretationContextStringHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextStringHandle | [**MapInterpretationContextString\_copy**](#function-mapinterpretationcontextstring_copy) (MapInterpretationContextStringHandle handle) <br> |
|  MapInterpretationContextStringHandle | [**MapInterpretationContextString\_create**](#function-mapinterpretationcontextstring_create) (PairInterpretationContextStringHandle \* data, size\_t count) <br> |
|  MapInterpretationContextStringHandle | [**MapInterpretationContextString\_create\_empty**](#function-mapinterpretationcontextstring_create_empty) () <br> |
|  void | [**MapInterpretationContextString\_destroy**](#function-mapinterpretationcontextstring_destroy) (MapInterpretationContextStringHandle handle) <br> |
|  bool | [**MapInterpretationContextString\_empty**](#function-mapinterpretationcontextstring_empty) (MapInterpretationContextStringHandle handle) <br> |
|  bool | [**MapInterpretationContextString\_equal**](#function-mapinterpretationcontextstring_equal) (MapInterpretationContextStringHandle handle, MapInterpretationContextStringHandle other) <br> |
|  void | [**MapInterpretationContextString\_erase**](#function-mapinterpretationcontextstring_erase) (MapInterpretationContextStringHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextStringHandle | [**MapInterpretationContextString\_from\_json\_string**](#function-mapinterpretationcontextstring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapInterpretationContextString\_insert**](#function-mapinterpretationcontextstring_insert) (MapInterpretationContextStringHandle handle, InterpretationContextHandle key, [**StringHandle**](structstring.md) value) <br> |
|  void | [**MapInterpretationContextString\_insert\_or\_assign**](#function-mapinterpretationcontextstring_insert_or_assign) (MapInterpretationContextStringHandle handle, InterpretationContextHandle key, [**StringHandle**](structstring.md) value) <br> |
|  ListPairInterpretationContextStringHandle | [**MapInterpretationContextString\_items**](#function-mapinterpretationcontextstring_items) (MapInterpretationContextStringHandle handle) <br> |
|  ListInterpretationContextHandle | [**MapInterpretationContextString\_keys**](#function-mapinterpretationcontextstring_keys) (MapInterpretationContextStringHandle handle) <br> |
|  bool | [**MapInterpretationContextString\_not\_equal**](#function-mapinterpretationcontextstring_not_equal) (MapInterpretationContextStringHandle handle, MapInterpretationContextStringHandle other) <br> |
|  size\_t | [**MapInterpretationContextString\_size**](#function-mapinterpretationcontextstring_size) (MapInterpretationContextStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapInterpretationContextString\_to\_json\_string**](#function-mapinterpretationcontextstring_to_json_string) (MapInterpretationContextStringHandle handle) <br> |
|  ListStringHandle | [**MapInterpretationContextString\_values**](#function-mapinterpretationcontextstring_values) (MapInterpretationContextStringHandle handle) <br> |




























## Public Types Documentation




### typedef MapInterpretationContextStringHandle 

```C++
typedef void* MapInterpretationContextStringHandle;
```




<hr>
## Public Functions Documentation




### function MapInterpretationContextString\_at 

```C++
StringHandle MapInterpretationContextString_at (
    MapInterpretationContextStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextString\_clear 

```C++
void MapInterpretationContextString_clear (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_contains 

```C++
bool MapInterpretationContextString_contains (
    MapInterpretationContextStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextString\_copy 

```C++
MapInterpretationContextStringHandle MapInterpretationContextString_copy (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_create 

```C++
MapInterpretationContextStringHandle MapInterpretationContextString_create (
    PairInterpretationContextStringHandle * data,
    size_t count
) 
```




<hr>



### function MapInterpretationContextString\_create\_empty 

```C++
MapInterpretationContextStringHandle MapInterpretationContextString_create_empty () 
```




<hr>



### function MapInterpretationContextString\_destroy 

```C++
void MapInterpretationContextString_destroy (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_empty 

```C++
bool MapInterpretationContextString_empty (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_equal 

```C++
bool MapInterpretationContextString_equal (
    MapInterpretationContextStringHandle handle,
    MapInterpretationContextStringHandle other
) 
```




<hr>



### function MapInterpretationContextString\_erase 

```C++
void MapInterpretationContextString_erase (
    MapInterpretationContextStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextString\_from\_json\_string 

```C++
MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapInterpretationContextString\_insert 

```C++
void MapInterpretationContextString_insert (
    MapInterpretationContextStringHandle handle,
    InterpretationContextHandle key,
    StringHandle value
) 
```




<hr>



### function MapInterpretationContextString\_insert\_or\_assign 

```C++
void MapInterpretationContextString_insert_or_assign (
    MapInterpretationContextStringHandle handle,
    InterpretationContextHandle key,
    StringHandle value
) 
```




<hr>



### function MapInterpretationContextString\_items 

```C++
ListPairInterpretationContextStringHandle MapInterpretationContextString_items (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_keys 

```C++
ListInterpretationContextHandle MapInterpretationContextString_keys (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_not\_equal 

```C++
bool MapInterpretationContextString_not_equal (
    MapInterpretationContextStringHandle handle,
    MapInterpretationContextStringHandle other
) 
```




<hr>



### function MapInterpretationContextString\_size 

```C++
size_t MapInterpretationContextString_size (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_to\_json\_string 

```C++
StringHandle MapInterpretationContextString_to_json_string (
    MapInterpretationContextStringHandle handle
) 
```




<hr>



### function MapInterpretationContextString\_values 

```C++
ListStringHandle MapInterpretationContextString_values (
    MapInterpretationContextStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapInterpretationContextString_c_api.h`

