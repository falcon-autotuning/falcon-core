

# File MapIntInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapIntInt\_c\_api.h**](MapIntInt__c__api_8h.md)

[Go to the source code of this file](MapIntInt__c__api_8h_source.md)



* `#include "falcon_core/generic/PairIntInt_c_api.h"`
* `#include "falcon_core/generic/ListInt_c_api.h"`
* `#include "falcon_core/generic/ListPairIntInt_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapIntIntHandle**](#typedef-mapintinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**MapIntInt\_at**](#function-mapintint_at) (MapIntIntHandle handle, int key) <br> |
|  void | [**MapIntInt\_clear**](#function-mapintint_clear) (MapIntIntHandle handle) <br> |
|  bool | [**MapIntInt\_contains**](#function-mapintint_contains) (MapIntIntHandle handle, int key) <br> |
|  MapIntIntHandle | [**MapIntInt\_copy**](#function-mapintint_copy) (MapIntIntHandle handle) <br> |
|  MapIntIntHandle | [**MapIntInt\_create**](#function-mapintint_create) (PairIntIntHandle \* data, size\_t count) <br> |
|  MapIntIntHandle | [**MapIntInt\_create\_empty**](#function-mapintint_create_empty) () <br> |
|  void | [**MapIntInt\_destroy**](#function-mapintint_destroy) (MapIntIntHandle handle) <br> |
|  bool | [**MapIntInt\_empty**](#function-mapintint_empty) (MapIntIntHandle handle) <br> |
|  bool | [**MapIntInt\_equal**](#function-mapintint_equal) (MapIntIntHandle handle, MapIntIntHandle other) <br> |
|  void | [**MapIntInt\_erase**](#function-mapintint_erase) (MapIntIntHandle handle, int key) <br> |
|  MapIntIntHandle | [**MapIntInt\_from\_json\_string**](#function-mapintint_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapIntInt\_insert**](#function-mapintint_insert) (MapIntIntHandle handle, int key, int value) <br> |
|  void | [**MapIntInt\_insert\_or\_assign**](#function-mapintint_insert_or_assign) (MapIntIntHandle handle, int key, int value) <br> |
|  ListPairIntIntHandle | [**MapIntInt\_items**](#function-mapintint_items) (MapIntIntHandle handle) <br> |
|  ListIntHandle | [**MapIntInt\_keys**](#function-mapintint_keys) (MapIntIntHandle handle) <br> |
|  bool | [**MapIntInt\_not\_equal**](#function-mapintint_not_equal) (MapIntIntHandle handle, MapIntIntHandle other) <br> |
|  size\_t | [**MapIntInt\_size**](#function-mapintint_size) (MapIntIntHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapIntInt\_to\_json\_string**](#function-mapintint_to_json_string) (MapIntIntHandle handle) <br> |
|  ListIntHandle | [**MapIntInt\_values**](#function-mapintint_values) (MapIntIntHandle handle) <br> |




























## Public Types Documentation




### typedef MapIntIntHandle 

```C++
typedef void* MapIntIntHandle;
```




<hr>
## Public Functions Documentation




### function MapIntInt\_at 

```C++
int MapIntInt_at (
    MapIntIntHandle handle,
    int key
) 
```




<hr>



### function MapIntInt\_clear 

```C++
void MapIntInt_clear (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_contains 

```C++
bool MapIntInt_contains (
    MapIntIntHandle handle,
    int key
) 
```




<hr>



### function MapIntInt\_copy 

```C++
MapIntIntHandle MapIntInt_copy (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_create 

```C++
MapIntIntHandle MapIntInt_create (
    PairIntIntHandle * data,
    size_t count
) 
```




<hr>



### function MapIntInt\_create\_empty 

```C++
MapIntIntHandle MapIntInt_create_empty () 
```




<hr>



### function MapIntInt\_destroy 

```C++
void MapIntInt_destroy (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_empty 

```C++
bool MapIntInt_empty (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_equal 

```C++
bool MapIntInt_equal (
    MapIntIntHandle handle,
    MapIntIntHandle other
) 
```




<hr>



### function MapIntInt\_erase 

```C++
void MapIntInt_erase (
    MapIntIntHandle handle,
    int key
) 
```




<hr>



### function MapIntInt\_from\_json\_string 

```C++
MapIntIntHandle MapIntInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapIntInt\_insert 

```C++
void MapIntInt_insert (
    MapIntIntHandle handle,
    int key,
    int value
) 
```




<hr>



### function MapIntInt\_insert\_or\_assign 

```C++
void MapIntInt_insert_or_assign (
    MapIntIntHandle handle,
    int key,
    int value
) 
```




<hr>



### function MapIntInt\_items 

```C++
ListPairIntIntHandle MapIntInt_items (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_keys 

```C++
ListIntHandle MapIntInt_keys (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_not\_equal 

```C++
bool MapIntInt_not_equal (
    MapIntIntHandle handle,
    MapIntIntHandle other
) 
```




<hr>



### function MapIntInt\_size 

```C++
size_t MapIntInt_size (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_to\_json\_string 

```C++
StringHandle MapIntInt_to_json_string (
    MapIntIntHandle handle
) 
```




<hr>



### function MapIntInt\_values 

```C++
ListIntHandle MapIntInt_values (
    MapIntIntHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapIntInt_c_api.h`

