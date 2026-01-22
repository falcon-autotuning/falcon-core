

# File MapGnameGroup\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapGnameGroup\_c\_api.h**](MapGnameGroup__c__api_8h.md)

[Go to the source code of this file](MapGnameGroup__c__api_8h_source.md)



* `#include "falcon_core/generic/PairGnameGroup_c_api.h"`
* `#include "falcon_core/generic/ListGname_c_api.h"`
* `#include "falcon_core/generic/ListGroup_c_api.h"`
* `#include "falcon_core/generic/ListPairGnameGroup_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapGnameGroupHandle**](#typedef-mapgnamegrouphandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  GroupHandle | [**MapGnameGroup\_at**](#function-mapgnamegroup_at) (MapGnameGroupHandle handle, GnameHandle key) <br> |
|  void | [**MapGnameGroup\_clear**](#function-mapgnamegroup_clear) (MapGnameGroupHandle handle) <br> |
|  bool | [**MapGnameGroup\_contains**](#function-mapgnamegroup_contains) (MapGnameGroupHandle handle, GnameHandle key) <br> |
|  MapGnameGroupHandle | [**MapGnameGroup\_copy**](#function-mapgnamegroup_copy) (MapGnameGroupHandle handle) <br> |
|  MapGnameGroupHandle | [**MapGnameGroup\_create**](#function-mapgnamegroup_create) (PairGnameGroupHandle \* data, size\_t count) <br> |
|  MapGnameGroupHandle | [**MapGnameGroup\_create\_empty**](#function-mapgnamegroup_create_empty) () <br> |
|  void | [**MapGnameGroup\_destroy**](#function-mapgnamegroup_destroy) (MapGnameGroupHandle handle) <br> |
|  bool | [**MapGnameGroup\_empty**](#function-mapgnamegroup_empty) (MapGnameGroupHandle handle) <br> |
|  bool | [**MapGnameGroup\_equal**](#function-mapgnamegroup_equal) (MapGnameGroupHandle handle, MapGnameGroupHandle other) <br> |
|  void | [**MapGnameGroup\_erase**](#function-mapgnamegroup_erase) (MapGnameGroupHandle handle, GnameHandle key) <br> |
|  MapGnameGroupHandle | [**MapGnameGroup\_from\_json\_string**](#function-mapgnamegroup_from_json_string) (StringHandle json) <br> |
|  void | [**MapGnameGroup\_insert**](#function-mapgnamegroup_insert) (MapGnameGroupHandle handle, GnameHandle key, GroupHandle value) <br> |
|  void | [**MapGnameGroup\_insert\_or\_assign**](#function-mapgnamegroup_insert_or_assign) (MapGnameGroupHandle handle, GnameHandle key, GroupHandle value) <br> |
|  ListPairGnameGroupHandle | [**MapGnameGroup\_items**](#function-mapgnamegroup_items) (MapGnameGroupHandle handle) <br> |
|  ListGnameHandle | [**MapGnameGroup\_keys**](#function-mapgnamegroup_keys) (MapGnameGroupHandle handle) <br> |
|  bool | [**MapGnameGroup\_not\_equal**](#function-mapgnamegroup_not_equal) (MapGnameGroupHandle handle, MapGnameGroupHandle other) <br> |
|  size\_t | [**MapGnameGroup\_size**](#function-mapgnamegroup_size) (MapGnameGroupHandle handle) <br> |
|  StringHandle | [**MapGnameGroup\_to\_json\_string**](#function-mapgnamegroup_to_json_string) (MapGnameGroupHandle handle) <br> |
|  ListGroupHandle | [**MapGnameGroup\_values**](#function-mapgnamegroup_values) (MapGnameGroupHandle handle) <br> |




























## Public Types Documentation




### typedef MapGnameGroupHandle 

```C++
typedef void* MapGnameGroupHandle;
```




<hr>
## Public Functions Documentation




### function MapGnameGroup\_at 

```C++
GroupHandle MapGnameGroup_at (
    MapGnameGroupHandle handle,
    GnameHandle key
) 
```




<hr>



### function MapGnameGroup\_clear 

```C++
void MapGnameGroup_clear (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_contains 

```C++
bool MapGnameGroup_contains (
    MapGnameGroupHandle handle,
    GnameHandle key
) 
```




<hr>



### function MapGnameGroup\_copy 

```C++
MapGnameGroupHandle MapGnameGroup_copy (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_create 

```C++
MapGnameGroupHandle MapGnameGroup_create (
    PairGnameGroupHandle * data,
    size_t count
) 
```




<hr>



### function MapGnameGroup\_create\_empty 

```C++
MapGnameGroupHandle MapGnameGroup_create_empty () 
```




<hr>



### function MapGnameGroup\_destroy 

```C++
void MapGnameGroup_destroy (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_empty 

```C++
bool MapGnameGroup_empty (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_equal 

```C++
bool MapGnameGroup_equal (
    MapGnameGroupHandle handle,
    MapGnameGroupHandle other
) 
```




<hr>



### function MapGnameGroup\_erase 

```C++
void MapGnameGroup_erase (
    MapGnameGroupHandle handle,
    GnameHandle key
) 
```




<hr>



### function MapGnameGroup\_from\_json\_string 

```C++
MapGnameGroupHandle MapGnameGroup_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapGnameGroup\_insert 

```C++
void MapGnameGroup_insert (
    MapGnameGroupHandle handle,
    GnameHandle key,
    GroupHandle value
) 
```




<hr>



### function MapGnameGroup\_insert\_or\_assign 

```C++
void MapGnameGroup_insert_or_assign (
    MapGnameGroupHandle handle,
    GnameHandle key,
    GroupHandle value
) 
```




<hr>



### function MapGnameGroup\_items 

```C++
ListPairGnameGroupHandle MapGnameGroup_items (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_keys 

```C++
ListGnameHandle MapGnameGroup_keys (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_not\_equal 

```C++
bool MapGnameGroup_not_equal (
    MapGnameGroupHandle handle,
    MapGnameGroupHandle other
) 
```




<hr>



### function MapGnameGroup\_size 

```C++
size_t MapGnameGroup_size (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_to\_json\_string 

```C++
StringHandle MapGnameGroup_to_json_string (
    MapGnameGroupHandle handle
) 
```




<hr>



### function MapGnameGroup\_values 

```C++
ListGroupHandle MapGnameGroup_values (
    MapGnameGroupHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapGnameGroup_c_api.h`

