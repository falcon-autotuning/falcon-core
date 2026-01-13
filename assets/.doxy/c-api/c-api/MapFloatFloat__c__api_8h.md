

# File MapFloatFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapFloatFloat\_c\_api.h**](MapFloatFloat__c__api_8h.md)

[Go to the source code of this file](MapFloatFloat__c__api_8h_source.md)



* `#include "falcon_core/generic/PairFloatFloat_c_api.h"`
* `#include "falcon_core/generic/ListFloat_c_api.h"`
* `#include "falcon_core/generic/ListPairFloatFloat_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapFloatFloatHandle**](#typedef-mapfloatfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  float | [**MapFloatFloat\_at**](#function-mapfloatfloat_at) (MapFloatFloatHandle handle, float key) <br> |
|  void | [**MapFloatFloat\_clear**](#function-mapfloatfloat_clear) (MapFloatFloatHandle handle) <br> |
|  bool | [**MapFloatFloat\_contains**](#function-mapfloatfloat_contains) (MapFloatFloatHandle handle, float key) <br> |
|  MapFloatFloatHandle | [**MapFloatFloat\_copy**](#function-mapfloatfloat_copy) (MapFloatFloatHandle handle) <br> |
|  MapFloatFloatHandle | [**MapFloatFloat\_create**](#function-mapfloatfloat_create) (PairFloatFloatHandle \* data, size\_t count) <br> |
|  MapFloatFloatHandle | [**MapFloatFloat\_create\_empty**](#function-mapfloatfloat_create_empty) () <br> |
|  void | [**MapFloatFloat\_destroy**](#function-mapfloatfloat_destroy) (MapFloatFloatHandle handle) <br> |
|  bool | [**MapFloatFloat\_empty**](#function-mapfloatfloat_empty) (MapFloatFloatHandle handle) <br> |
|  bool | [**MapFloatFloat\_equal**](#function-mapfloatfloat_equal) (MapFloatFloatHandle handle, MapFloatFloatHandle other) <br> |
|  void | [**MapFloatFloat\_erase**](#function-mapfloatfloat_erase) (MapFloatFloatHandle handle, float key) <br> |
|  MapFloatFloatHandle | [**MapFloatFloat\_from\_json\_string**](#function-mapfloatfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapFloatFloat\_insert**](#function-mapfloatfloat_insert) (MapFloatFloatHandle handle, float key, float value) <br> |
|  void | [**MapFloatFloat\_insert\_or\_assign**](#function-mapfloatfloat_insert_or_assign) (MapFloatFloatHandle handle, float key, float value) <br> |
|  ListPairFloatFloatHandle | [**MapFloatFloat\_items**](#function-mapfloatfloat_items) (MapFloatFloatHandle handle) <br> |
|  ListFloatHandle | [**MapFloatFloat\_keys**](#function-mapfloatfloat_keys) (MapFloatFloatHandle handle) <br> |
|  bool | [**MapFloatFloat\_not\_equal**](#function-mapfloatfloat_not_equal) (MapFloatFloatHandle handle, MapFloatFloatHandle other) <br> |
|  size\_t | [**MapFloatFloat\_size**](#function-mapfloatfloat_size) (MapFloatFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapFloatFloat\_to\_json\_string**](#function-mapfloatfloat_to_json_string) (MapFloatFloatHandle handle) <br> |
|  ListFloatHandle | [**MapFloatFloat\_values**](#function-mapfloatfloat_values) (MapFloatFloatHandle handle) <br> |




























## Public Types Documentation




### typedef MapFloatFloatHandle 

```C++
typedef void* MapFloatFloatHandle;
```




<hr>
## Public Functions Documentation




### function MapFloatFloat\_at 

```C++
float MapFloatFloat_at (
    MapFloatFloatHandle handle,
    float key
) 
```




<hr>



### function MapFloatFloat\_clear 

```C++
void MapFloatFloat_clear (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_contains 

```C++
bool MapFloatFloat_contains (
    MapFloatFloatHandle handle,
    float key
) 
```




<hr>



### function MapFloatFloat\_copy 

```C++
MapFloatFloatHandle MapFloatFloat_copy (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_create 

```C++
MapFloatFloatHandle MapFloatFloat_create (
    PairFloatFloatHandle * data,
    size_t count
) 
```




<hr>



### function MapFloatFloat\_create\_empty 

```C++
MapFloatFloatHandle MapFloatFloat_create_empty () 
```




<hr>



### function MapFloatFloat\_destroy 

```C++
void MapFloatFloat_destroy (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_empty 

```C++
bool MapFloatFloat_empty (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_equal 

```C++
bool MapFloatFloat_equal (
    MapFloatFloatHandle handle,
    MapFloatFloatHandle other
) 
```




<hr>



### function MapFloatFloat\_erase 

```C++
void MapFloatFloat_erase (
    MapFloatFloatHandle handle,
    float key
) 
```




<hr>



### function MapFloatFloat\_from\_json\_string 

```C++
MapFloatFloatHandle MapFloatFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapFloatFloat\_insert 

```C++
void MapFloatFloat_insert (
    MapFloatFloatHandle handle,
    float key,
    float value
) 
```




<hr>



### function MapFloatFloat\_insert\_or\_assign 

```C++
void MapFloatFloat_insert_or_assign (
    MapFloatFloatHandle handle,
    float key,
    float value
) 
```




<hr>



### function MapFloatFloat\_items 

```C++
ListPairFloatFloatHandle MapFloatFloat_items (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_keys 

```C++
ListFloatHandle MapFloatFloat_keys (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_not\_equal 

```C++
bool MapFloatFloat_not_equal (
    MapFloatFloatHandle handle,
    MapFloatFloatHandle other
) 
```




<hr>



### function MapFloatFloat\_size 

```C++
size_t MapFloatFloat_size (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_to\_json\_string 

```C++
StringHandle MapFloatFloat_to_json_string (
    MapFloatFloatHandle handle
) 
```




<hr>



### function MapFloatFloat\_values 

```C++
ListFloatHandle MapFloatFloat_values (
    MapFloatFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapFloatFloat_c_api.h`

