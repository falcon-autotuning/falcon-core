

# File MapStringDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapStringDouble\_c\_api.h**](MapStringDouble__c__api_8h.md)

[Go to the source code of this file](MapStringDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/ListPairStringDouble_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/ListDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapStringDoubleHandle**](#typedef-mapstringdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**MapStringDouble\_at**](#function-mapstringdouble_at) (MapStringDoubleHandle handle, StringHandle key) <br> |
|  void | [**MapStringDouble\_clear**](#function-mapstringdouble_clear) (MapStringDoubleHandle handle) <br> |
|  bool | [**MapStringDouble\_contains**](#function-mapstringdouble_contains) (MapStringDoubleHandle handle, StringHandle key) <br> |
|  MapStringDoubleHandle | [**MapStringDouble\_copy**](#function-mapstringdouble_copy) (MapStringDoubleHandle handle) <br> |
|  MapStringDoubleHandle | [**MapStringDouble\_create**](#function-mapstringdouble_create) (PairStringDoubleHandle \* data, size\_t count) <br> |
|  MapStringDoubleHandle | [**MapStringDouble\_create\_empty**](#function-mapstringdouble_create_empty) () <br> |
|  void | [**MapStringDouble\_destroy**](#function-mapstringdouble_destroy) (MapStringDoubleHandle handle) <br> |
|  bool | [**MapStringDouble\_empty**](#function-mapstringdouble_empty) (MapStringDoubleHandle handle) <br> |
|  bool | [**MapStringDouble\_equal**](#function-mapstringdouble_equal) (MapStringDoubleHandle handle, MapStringDoubleHandle other) <br> |
|  void | [**MapStringDouble\_erase**](#function-mapstringdouble_erase) (MapStringDoubleHandle handle, StringHandle key) <br> |
|  MapStringDoubleHandle | [**MapStringDouble\_from\_json\_string**](#function-mapstringdouble_from_json_string) (StringHandle json) <br> |
|  void | [**MapStringDouble\_insert**](#function-mapstringdouble_insert) (MapStringDoubleHandle handle, StringHandle key, double value) <br> |
|  void | [**MapStringDouble\_insert\_or\_assign**](#function-mapstringdouble_insert_or_assign) (MapStringDoubleHandle handle, StringHandle key, double value) <br> |
|  ListPairStringDoubleHandle | [**MapStringDouble\_items**](#function-mapstringdouble_items) (MapStringDoubleHandle handle) <br> |
|  ListStringHandle | [**MapStringDouble\_keys**](#function-mapstringdouble_keys) (MapStringDoubleHandle handle) <br> |
|  bool | [**MapStringDouble\_not\_equal**](#function-mapstringdouble_not_equal) (MapStringDoubleHandle handle, MapStringDoubleHandle other) <br> |
|  size\_t | [**MapStringDouble\_size**](#function-mapstringdouble_size) (MapStringDoubleHandle handle) <br> |
|  StringHandle | [**MapStringDouble\_to\_json\_string**](#function-mapstringdouble_to_json_string) (MapStringDoubleHandle handle) <br> |
|  ListDoubleHandle | [**MapStringDouble\_values**](#function-mapstringdouble_values) (MapStringDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef MapStringDoubleHandle 

```C++
typedef void* MapStringDoubleHandle;
```




<hr>
## Public Functions Documentation




### function MapStringDouble\_at 

```C++
double MapStringDouble_at (
    MapStringDoubleHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringDouble\_clear 

```C++
void MapStringDouble_clear (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_contains 

```C++
bool MapStringDouble_contains (
    MapStringDoubleHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringDouble\_copy 

```C++
MapStringDoubleHandle MapStringDouble_copy (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_create 

```C++
MapStringDoubleHandle MapStringDouble_create (
    PairStringDoubleHandle * data,
    size_t count
) 
```




<hr>



### function MapStringDouble\_create\_empty 

```C++
MapStringDoubleHandle MapStringDouble_create_empty () 
```




<hr>



### function MapStringDouble\_destroy 

```C++
void MapStringDouble_destroy (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_empty 

```C++
bool MapStringDouble_empty (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_equal 

```C++
bool MapStringDouble_equal (
    MapStringDoubleHandle handle,
    MapStringDoubleHandle other
) 
```




<hr>



### function MapStringDouble\_erase 

```C++
void MapStringDouble_erase (
    MapStringDoubleHandle handle,
    StringHandle key
) 
```




<hr>



### function MapStringDouble\_from\_json\_string 

```C++
MapStringDoubleHandle MapStringDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapStringDouble\_insert 

```C++
void MapStringDouble_insert (
    MapStringDoubleHandle handle,
    StringHandle key,
    double value
) 
```




<hr>



### function MapStringDouble\_insert\_or\_assign 

```C++
void MapStringDouble_insert_or_assign (
    MapStringDoubleHandle handle,
    StringHandle key,
    double value
) 
```




<hr>



### function MapStringDouble\_items 

```C++
ListPairStringDoubleHandle MapStringDouble_items (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_keys 

```C++
ListStringHandle MapStringDouble_keys (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_not\_equal 

```C++
bool MapStringDouble_not_equal (
    MapStringDoubleHandle handle,
    MapStringDoubleHandle other
) 
```




<hr>



### function MapStringDouble\_size 

```C++
size_t MapStringDouble_size (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_to\_json\_string 

```C++
StringHandle MapStringDouble_to_json_string (
    MapStringDoubleHandle handle
) 
```




<hr>



### function MapStringDouble\_values 

```C++
ListDoubleHandle MapStringDouble_values (
    MapStringDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapStringDouble_c_api.h`

