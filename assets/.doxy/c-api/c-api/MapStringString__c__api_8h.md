

# File MapStringString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapStringString\_c\_api.h**](MapStringString__c__api_8h.md)

[Go to the source code of this file](MapStringString__c__api_8h_source.md)



* `#include "falcon_core/generic/ListPairStringString_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapStringStringHandle**](#typedef-mapstringstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  [**StringHandle**](structstring.md) | [**MapStringString\_at**](#function-mapstringstring_at) (MapStringStringHandle handle, [**StringHandle**](structstring.md) key) <br> |
|  void | [**MapStringString\_clear**](#function-mapstringstring_clear) (MapStringStringHandle handle) <br> |
|  bool | [**MapStringString\_contains**](#function-mapstringstring_contains) (MapStringStringHandle handle, [**StringHandle**](structstring.md) key) <br> |
|  MapStringStringHandle | [**MapStringString\_copy**](#function-mapstringstring_copy) (MapStringStringHandle handle) <br> |
|  MapStringStringHandle | [**MapStringString\_create**](#function-mapstringstring_create) (PairStringStringHandle \* data, size\_t count) <br> |
|  MapStringStringHandle | [**MapStringString\_create\_empty**](#function-mapstringstring_create_empty) () <br> |
|  void | [**MapStringString\_destroy**](#function-mapstringstring_destroy) (MapStringStringHandle handle) <br> |
|  bool | [**MapStringString\_empty**](#function-mapstringstring_empty) (MapStringStringHandle handle) <br> |
|  bool | [**MapStringString\_equal**](#function-mapstringstring_equal) (MapStringStringHandle handle, MapStringStringHandle other) <br> |
|  void | [**MapStringString\_erase**](#function-mapstringstring_erase) (MapStringStringHandle handle, [**StringHandle**](structstring.md) key) <br> |
|  MapStringStringHandle | [**MapStringString\_from\_json\_string**](#function-mapstringstring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapStringString\_insert**](#function-mapstringstring_insert) (MapStringStringHandle handle, [**StringHandle**](structstring.md) key, [**StringHandle**](structstring.md) value) <br> |
|  void | [**MapStringString\_insert\_or\_assign**](#function-mapstringstring_insert_or_assign) (MapStringStringHandle handle, [**StringHandle**](structstring.md) key, [**StringHandle**](structstring.md) value) <br> |
|  ListPairStringStringHandle | [**MapStringString\_items**](#function-mapstringstring_items) (MapStringStringHandle handle) <br> |
|  ListStringHandle | [**MapStringString\_keys**](#function-mapstringstring_keys) (MapStringStringHandle handle) <br> |
|  bool | [**MapStringString\_not\_equal**](#function-mapstringstring_not_equal) (MapStringStringHandle handle, MapStringStringHandle other) <br> |
|  size\_t | [**MapStringString\_size**](#function-mapstringstring_size) (MapStringStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapStringString\_to\_json\_string**](#function-mapstringstring_to_json_string) (MapStringStringHandle handle) <br> |
|  ListStringHandle | [**MapStringString\_values**](#function-mapstringstring_values) (MapStringStringHandle handle) <br> |




























## Public Types Documentation




### typedef MapStringStringHandle 

```C++
typedef void* MapStringStringHandle;
```




<hr>
## Public Functions Documentation




### function MapStringString\_at 

```C++
StringHandle MapStringString_at (
    MapStringStringHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringString\_clear 

```C++
void MapStringString_clear (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_contains 

```C++
bool MapStringString_contains (
    MapStringStringHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringString\_copy 

```C++
MapStringStringHandle MapStringString_copy (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_create 

```C++
MapStringStringHandle MapStringString_create (
    PairStringStringHandle * data,
    size_t count
) 
```




<hr>



### function MapStringString\_create\_empty 

```C++
MapStringStringHandle MapStringString_create_empty () 
```




<hr>



### function MapStringString\_destroy 

```C++
void MapStringString_destroy (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_empty 

```C++
bool MapStringString_empty (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_equal 

```C++
bool MapStringString_equal (
    MapStringStringHandle handle,
    MapStringStringHandle other
) 
```




<hr>



### function MapStringString\_erase 

```C++
void MapStringString_erase (
    MapStringStringHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringString\_from\_json\_string 

```C++
MapStringStringHandle MapStringString_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapStringString\_insert 

```C++
void MapStringString_insert (
    MapStringStringHandle handle,
    StringHandle key,
    StringHandle value
) 
```




<hr>



### function MapStringString\_insert\_or\_assign 

```C++
void MapStringString_insert_or_assign (
    MapStringStringHandle handle,
    StringHandle key,
    StringHandle value
) 
```




<hr>



### function MapStringString\_items 

```C++
ListPairStringStringHandle MapStringString_items (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_keys 

```C++
ListStringHandle MapStringString_keys (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_not\_equal 

```C++
bool MapStringString_not_equal (
    MapStringStringHandle handle,
    MapStringStringHandle other
) 
```




<hr>



### function MapStringString\_size 

```C++
size_t MapStringString_size (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_to\_json\_string 

```C++
StringHandle MapStringString_to_json_string (
    MapStringStringHandle handle
) 
```




<hr>



### function MapStringString\_values 

```C++
ListStringHandle MapStringString_values (
    MapStringStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapStringString_c_api.h`

