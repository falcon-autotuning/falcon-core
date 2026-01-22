

# File MapInterpretationContextDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInterpretationContextDouble\_c\_api.h**](MapInterpretationContextDouble__c__api_8h.md)

[Go to the source code of this file](MapInterpretationContextDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"`
* `#include "falcon_core/generic/ListDouble_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapInterpretationContextDoubleHandle**](#typedef-mapinterpretationcontextdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**MapInterpretationContextDouble\_at**](#function-mapinterpretationcontextdouble_at) (MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key) <br> |
|  void | [**MapInterpretationContextDouble\_clear**](#function-mapinterpretationcontextdouble_clear) (MapInterpretationContextDoubleHandle handle) <br> |
|  bool | [**MapInterpretationContextDouble\_contains**](#function-mapinterpretationcontextdouble_contains) (MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextDoubleHandle | [**MapInterpretationContextDouble\_copy**](#function-mapinterpretationcontextdouble_copy) (MapInterpretationContextDoubleHandle handle) <br> |
|  MapInterpretationContextDoubleHandle | [**MapInterpretationContextDouble\_create**](#function-mapinterpretationcontextdouble_create) (PairInterpretationContextDoubleHandle \* data, size\_t count) <br> |
|  MapInterpretationContextDoubleHandle | [**MapInterpretationContextDouble\_create\_empty**](#function-mapinterpretationcontextdouble_create_empty) () <br> |
|  void | [**MapInterpretationContextDouble\_destroy**](#function-mapinterpretationcontextdouble_destroy) (MapInterpretationContextDoubleHandle handle) <br> |
|  bool | [**MapInterpretationContextDouble\_empty**](#function-mapinterpretationcontextdouble_empty) (MapInterpretationContextDoubleHandle handle) <br> |
|  bool | [**MapInterpretationContextDouble\_equal**](#function-mapinterpretationcontextdouble_equal) (MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other) <br> |
|  void | [**MapInterpretationContextDouble\_erase**](#function-mapinterpretationcontextdouble_erase) (MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextDoubleHandle | [**MapInterpretationContextDouble\_from\_json\_string**](#function-mapinterpretationcontextdouble_from_json_string) (StringHandle json) <br> |
|  void | [**MapInterpretationContextDouble\_insert**](#function-mapinterpretationcontextdouble_insert) (MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key, double value) <br> |
|  void | [**MapInterpretationContextDouble\_insert\_or\_assign**](#function-mapinterpretationcontextdouble_insert_or_assign) (MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key, double value) <br> |
|  ListPairInterpretationContextDoubleHandle | [**MapInterpretationContextDouble\_items**](#function-mapinterpretationcontextdouble_items) (MapInterpretationContextDoubleHandle handle) <br> |
|  ListInterpretationContextHandle | [**MapInterpretationContextDouble\_keys**](#function-mapinterpretationcontextdouble_keys) (MapInterpretationContextDoubleHandle handle) <br> |
|  bool | [**MapInterpretationContextDouble\_not\_equal**](#function-mapinterpretationcontextdouble_not_equal) (MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other) <br> |
|  size\_t | [**MapInterpretationContextDouble\_size**](#function-mapinterpretationcontextdouble_size) (MapInterpretationContextDoubleHandle handle) <br> |
|  StringHandle | [**MapInterpretationContextDouble\_to\_json\_string**](#function-mapinterpretationcontextdouble_to_json_string) (MapInterpretationContextDoubleHandle handle) <br> |
|  ListDoubleHandle | [**MapInterpretationContextDouble\_values**](#function-mapinterpretationcontextdouble_values) (MapInterpretationContextDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef MapInterpretationContextDoubleHandle 

```C++
typedef void* MapInterpretationContextDoubleHandle;
```




<hr>
## Public Functions Documentation




### function MapInterpretationContextDouble\_at 

```C++
double MapInterpretationContextDouble_at (
    MapInterpretationContextDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextDouble\_clear 

```C++
void MapInterpretationContextDouble_clear (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_contains 

```C++
bool MapInterpretationContextDouble_contains (
    MapInterpretationContextDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextDouble\_copy 

```C++
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_copy (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_create 

```C++
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create (
    PairInterpretationContextDoubleHandle * data,
    size_t count
) 
```




<hr>



### function MapInterpretationContextDouble\_create\_empty 

```C++
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create_empty () 
```




<hr>



### function MapInterpretationContextDouble\_destroy 

```C++
void MapInterpretationContextDouble_destroy (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_empty 

```C++
bool MapInterpretationContextDouble_empty (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_equal 

```C++
bool MapInterpretationContextDouble_equal (
    MapInterpretationContextDoubleHandle handle,
    MapInterpretationContextDoubleHandle other
) 
```




<hr>



### function MapInterpretationContextDouble\_erase 

```C++
void MapInterpretationContextDouble_erase (
    MapInterpretationContextDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextDouble\_from\_json\_string 

```C++
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapInterpretationContextDouble\_insert 

```C++
void MapInterpretationContextDouble_insert (
    MapInterpretationContextDoubleHandle handle,
    InterpretationContextHandle key,
    double value
) 
```




<hr>



### function MapInterpretationContextDouble\_insert\_or\_assign 

```C++
void MapInterpretationContextDouble_insert_or_assign (
    MapInterpretationContextDoubleHandle handle,
    InterpretationContextHandle key,
    double value
) 
```




<hr>



### function MapInterpretationContextDouble\_items 

```C++
ListPairInterpretationContextDoubleHandle MapInterpretationContextDouble_items (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_keys 

```C++
ListInterpretationContextHandle MapInterpretationContextDouble_keys (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_not\_equal 

```C++
bool MapInterpretationContextDouble_not_equal (
    MapInterpretationContextDoubleHandle handle,
    MapInterpretationContextDoubleHandle other
) 
```




<hr>



### function MapInterpretationContextDouble\_size 

```C++
size_t MapInterpretationContextDouble_size (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_to\_json\_string 

```C++
StringHandle MapInterpretationContextDouble_to_json_string (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>



### function MapInterpretationContextDouble\_values 

```C++
ListDoubleHandle MapInterpretationContextDouble_values (
    MapInterpretationContextDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapInterpretationContextDouble_c_api.h`

