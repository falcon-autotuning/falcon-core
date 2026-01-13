

# File MapConnectionDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionDouble\_c\_api.h**](MapConnectionDouble__c__api_8h.md)

[Go to the source code of this file](MapConnectionDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionDouble_c_api.h"`
* `#include "falcon_core/generic/ListDouble_c_api.h"`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapConnectionDoubleHandle**](#typedef-mapconnectiondoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**MapConnectionDouble\_at**](#function-mapconnectiondouble_at) (MapConnectionDoubleHandle handle, ConnectionHandle key) <br> |
|  void | [**MapConnectionDouble\_clear**](#function-mapconnectiondouble_clear) (MapConnectionDoubleHandle handle) <br> |
|  bool | [**MapConnectionDouble\_contains**](#function-mapconnectiondouble_contains) (MapConnectionDoubleHandle handle, ConnectionHandle key) <br> |
|  MapConnectionDoubleHandle | [**MapConnectionDouble\_copy**](#function-mapconnectiondouble_copy) (MapConnectionDoubleHandle handle) <br> |
|  MapConnectionDoubleHandle | [**MapConnectionDouble\_create**](#function-mapconnectiondouble_create) (PairConnectionDoubleHandle \* data, size\_t count) <br> |
|  MapConnectionDoubleHandle | [**MapConnectionDouble\_create\_empty**](#function-mapconnectiondouble_create_empty) () <br> |
|  void | [**MapConnectionDouble\_destroy**](#function-mapconnectiondouble_destroy) (MapConnectionDoubleHandle handle) <br> |
|  bool | [**MapConnectionDouble\_empty**](#function-mapconnectiondouble_empty) (MapConnectionDoubleHandle handle) <br> |
|  bool | [**MapConnectionDouble\_equal**](#function-mapconnectiondouble_equal) (MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other) <br> |
|  void | [**MapConnectionDouble\_erase**](#function-mapconnectiondouble_erase) (MapConnectionDoubleHandle handle, ConnectionHandle key) <br> |
|  MapConnectionDoubleHandle | [**MapConnectionDouble\_from\_json\_string**](#function-mapconnectiondouble_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapConnectionDouble\_insert**](#function-mapconnectiondouble_insert) (MapConnectionDoubleHandle handle, ConnectionHandle key, double value) <br> |
|  void | [**MapConnectionDouble\_insert\_or\_assign**](#function-mapconnectiondouble_insert_or_assign) (MapConnectionDoubleHandle handle, ConnectionHandle key, double value) <br> |
|  ListPairConnectionDoubleHandle | [**MapConnectionDouble\_items**](#function-mapconnectiondouble_items) (MapConnectionDoubleHandle handle) <br> |
|  ListConnectionHandle | [**MapConnectionDouble\_keys**](#function-mapconnectiondouble_keys) (MapConnectionDoubleHandle handle) <br> |
|  bool | [**MapConnectionDouble\_not\_equal**](#function-mapconnectiondouble_not_equal) (MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other) <br> |
|  size\_t | [**MapConnectionDouble\_size**](#function-mapconnectiondouble_size) (MapConnectionDoubleHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapConnectionDouble\_to\_json\_string**](#function-mapconnectiondouble_to_json_string) (MapConnectionDoubleHandle handle) <br> |
|  ListDoubleHandle | [**MapConnectionDouble\_values**](#function-mapconnectiondouble_values) (MapConnectionDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef MapConnectionDoubleHandle 

```C++
typedef void* MapConnectionDoubleHandle;
```




<hr>
## Public Functions Documentation




### function MapConnectionDouble\_at 

```C++
double MapConnectionDouble_at (
    MapConnectionDoubleHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionDouble\_clear 

```C++
void MapConnectionDouble_clear (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_contains 

```C++
bool MapConnectionDouble_contains (
    MapConnectionDoubleHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionDouble\_copy 

```C++
MapConnectionDoubleHandle MapConnectionDouble_copy (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_create 

```C++
MapConnectionDoubleHandle MapConnectionDouble_create (
    PairConnectionDoubleHandle * data,
    size_t count
) 
```




<hr>



### function MapConnectionDouble\_create\_empty 

```C++
MapConnectionDoubleHandle MapConnectionDouble_create_empty () 
```




<hr>



### function MapConnectionDouble\_destroy 

```C++
void MapConnectionDouble_destroy (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_empty 

```C++
bool MapConnectionDouble_empty (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_equal 

```C++
bool MapConnectionDouble_equal (
    MapConnectionDoubleHandle handle,
    MapConnectionDoubleHandle other
) 
```




<hr>



### function MapConnectionDouble\_erase 

```C++
void MapConnectionDouble_erase (
    MapConnectionDoubleHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionDouble\_from\_json\_string 

```C++
MapConnectionDoubleHandle MapConnectionDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapConnectionDouble\_insert 

```C++
void MapConnectionDouble_insert (
    MapConnectionDoubleHandle handle,
    ConnectionHandle key,
    double value
) 
```




<hr>



### function MapConnectionDouble\_insert\_or\_assign 

```C++
void MapConnectionDouble_insert_or_assign (
    MapConnectionDoubleHandle handle,
    ConnectionHandle key,
    double value
) 
```




<hr>



### function MapConnectionDouble\_items 

```C++
ListPairConnectionDoubleHandle MapConnectionDouble_items (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_keys 

```C++
ListConnectionHandle MapConnectionDouble_keys (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_not\_equal 

```C++
bool MapConnectionDouble_not_equal (
    MapConnectionDoubleHandle handle,
    MapConnectionDoubleHandle other
) 
```




<hr>



### function MapConnectionDouble\_size 

```C++
size_t MapConnectionDouble_size (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_to\_json\_string 

```C++
StringHandle MapConnectionDouble_to_json_string (
    MapConnectionDoubleHandle handle
) 
```




<hr>



### function MapConnectionDouble\_values 

```C++
ListDoubleHandle MapConnectionDouble_values (
    MapConnectionDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapConnectionDouble_c_api.h`

