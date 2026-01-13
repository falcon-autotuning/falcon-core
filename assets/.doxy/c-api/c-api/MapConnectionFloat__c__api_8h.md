

# File MapConnectionFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionFloat\_c\_api.h**](MapConnectionFloat__c__api_8h.md)

[Go to the source code of this file](MapConnectionFloat__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionFloat_c_api.h"`
* `#include "falcon_core/generic/ListFloat_c_api.h"`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/ListPairConnectionFloat_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapConnectionFloatHandle**](#typedef-mapconnectionfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  float | [**MapConnectionFloat\_at**](#function-mapconnectionfloat_at) (MapConnectionFloatHandle handle, ConnectionHandle key) <br> |
|  void | [**MapConnectionFloat\_clear**](#function-mapconnectionfloat_clear) (MapConnectionFloatHandle handle) <br> |
|  bool | [**MapConnectionFloat\_contains**](#function-mapconnectionfloat_contains) (MapConnectionFloatHandle handle, ConnectionHandle key) <br> |
|  MapConnectionFloatHandle | [**MapConnectionFloat\_copy**](#function-mapconnectionfloat_copy) (MapConnectionFloatHandle handle) <br> |
|  MapConnectionFloatHandle | [**MapConnectionFloat\_create**](#function-mapconnectionfloat_create) (PairConnectionFloatHandle \* data, size\_t count) <br> |
|  MapConnectionFloatHandle | [**MapConnectionFloat\_create\_empty**](#function-mapconnectionfloat_create_empty) () <br> |
|  void | [**MapConnectionFloat\_destroy**](#function-mapconnectionfloat_destroy) (MapConnectionFloatHandle handle) <br> |
|  bool | [**MapConnectionFloat\_empty**](#function-mapconnectionfloat_empty) (MapConnectionFloatHandle handle) <br> |
|  bool | [**MapConnectionFloat\_equal**](#function-mapconnectionfloat_equal) (MapConnectionFloatHandle handle, MapConnectionFloatHandle other) <br> |
|  void | [**MapConnectionFloat\_erase**](#function-mapconnectionfloat_erase) (MapConnectionFloatHandle handle, ConnectionHandle key) <br> |
|  MapConnectionFloatHandle | [**MapConnectionFloat\_from\_json\_string**](#function-mapconnectionfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapConnectionFloat\_insert**](#function-mapconnectionfloat_insert) (MapConnectionFloatHandle handle, ConnectionHandle key, float value) <br> |
|  void | [**MapConnectionFloat\_insert\_or\_assign**](#function-mapconnectionfloat_insert_or_assign) (MapConnectionFloatHandle handle, ConnectionHandle key, float value) <br> |
|  ListPairConnectionFloatHandle | [**MapConnectionFloat\_items**](#function-mapconnectionfloat_items) (MapConnectionFloatHandle handle) <br> |
|  ListConnectionHandle | [**MapConnectionFloat\_keys**](#function-mapconnectionfloat_keys) (MapConnectionFloatHandle handle) <br> |
|  bool | [**MapConnectionFloat\_not\_equal**](#function-mapconnectionfloat_not_equal) (MapConnectionFloatHandle handle, MapConnectionFloatHandle other) <br> |
|  size\_t | [**MapConnectionFloat\_size**](#function-mapconnectionfloat_size) (MapConnectionFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapConnectionFloat\_to\_json\_string**](#function-mapconnectionfloat_to_json_string) (MapConnectionFloatHandle handle) <br> |
|  ListFloatHandle | [**MapConnectionFloat\_values**](#function-mapconnectionfloat_values) (MapConnectionFloatHandle handle) <br> |




























## Public Types Documentation




### typedef MapConnectionFloatHandle 

```C++
typedef void* MapConnectionFloatHandle;
```




<hr>
## Public Functions Documentation




### function MapConnectionFloat\_at 

```C++
float MapConnectionFloat_at (
    MapConnectionFloatHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionFloat\_clear 

```C++
void MapConnectionFloat_clear (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_contains 

```C++
bool MapConnectionFloat_contains (
    MapConnectionFloatHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionFloat\_copy 

```C++
MapConnectionFloatHandle MapConnectionFloat_copy (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_create 

```C++
MapConnectionFloatHandle MapConnectionFloat_create (
    PairConnectionFloatHandle * data,
    size_t count
) 
```




<hr>



### function MapConnectionFloat\_create\_empty 

```C++
MapConnectionFloatHandle MapConnectionFloat_create_empty () 
```




<hr>



### function MapConnectionFloat\_destroy 

```C++
void MapConnectionFloat_destroy (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_empty 

```C++
bool MapConnectionFloat_empty (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_equal 

```C++
bool MapConnectionFloat_equal (
    MapConnectionFloatHandle handle,
    MapConnectionFloatHandle other
) 
```




<hr>



### function MapConnectionFloat\_erase 

```C++
void MapConnectionFloat_erase (
    MapConnectionFloatHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionFloat\_from\_json\_string 

```C++
MapConnectionFloatHandle MapConnectionFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapConnectionFloat\_insert 

```C++
void MapConnectionFloat_insert (
    MapConnectionFloatHandle handle,
    ConnectionHandle key,
    float value
) 
```




<hr>



### function MapConnectionFloat\_insert\_or\_assign 

```C++
void MapConnectionFloat_insert_or_assign (
    MapConnectionFloatHandle handle,
    ConnectionHandle key,
    float value
) 
```




<hr>



### function MapConnectionFloat\_items 

```C++
ListPairConnectionFloatHandle MapConnectionFloat_items (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_keys 

```C++
ListConnectionHandle MapConnectionFloat_keys (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_not\_equal 

```C++
bool MapConnectionFloat_not_equal (
    MapConnectionFloatHandle handle,
    MapConnectionFloatHandle other
) 
```




<hr>



### function MapConnectionFloat\_size 

```C++
size_t MapConnectionFloat_size (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_to\_json\_string 

```C++
StringHandle MapConnectionFloat_to_json_string (
    MapConnectionFloatHandle handle
) 
```




<hr>



### function MapConnectionFloat\_values 

```C++
ListFloatHandle MapConnectionFloat_values (
    MapConnectionFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapConnectionFloat_c_api.h`

