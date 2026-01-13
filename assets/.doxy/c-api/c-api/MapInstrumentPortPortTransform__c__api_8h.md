

# File MapInstrumentPortPortTransform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInstrumentPortPortTransform\_c\_api.h**](MapInstrumentPortPortTransform__c__api_8h.md)

[Go to the source code of this file](MapInstrumentPortPortTransform__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"`
* `#include "falcon_core/generic/ListInstrumentPort_c_api.h"`
* `#include "falcon_core/generic/ListPortTransform_c_api.h"`
* `#include "falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapInstrumentPortPortTransformHandle**](#typedef-mapinstrumentportporttransformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PortTransformHandle | [**MapInstrumentPortPortTransform\_at**](#function-mapinstrumentportporttransform_at) (MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key) <br> |
|  void | [**MapInstrumentPortPortTransform\_clear**](#function-mapinstrumentportporttransform_clear) (MapInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**MapInstrumentPortPortTransform\_contains**](#function-mapinstrumentportporttransform_contains) (MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key) <br> |
|  MapInstrumentPortPortTransformHandle | [**MapInstrumentPortPortTransform\_copy**](#function-mapinstrumentportporttransform_copy) (MapInstrumentPortPortTransformHandle handle) <br> |
|  MapInstrumentPortPortTransformHandle | [**MapInstrumentPortPortTransform\_create**](#function-mapinstrumentportporttransform_create) (PairInstrumentPortPortTransformHandle \* data, size\_t count) <br> |
|  MapInstrumentPortPortTransformHandle | [**MapInstrumentPortPortTransform\_create\_empty**](#function-mapinstrumentportporttransform_create_empty) () <br> |
|  void | [**MapInstrumentPortPortTransform\_destroy**](#function-mapinstrumentportporttransform_destroy) (MapInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**MapInstrumentPortPortTransform\_empty**](#function-mapinstrumentportporttransform_empty) (MapInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**MapInstrumentPortPortTransform\_equal**](#function-mapinstrumentportporttransform_equal) (MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other) <br> |
|  void | [**MapInstrumentPortPortTransform\_erase**](#function-mapinstrumentportporttransform_erase) (MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key) <br> |
|  MapInstrumentPortPortTransformHandle | [**MapInstrumentPortPortTransform\_from\_json\_string**](#function-mapinstrumentportporttransform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**MapInstrumentPortPortTransform\_insert**](#function-mapinstrumentportporttransform_insert) (MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value) <br> |
|  void | [**MapInstrumentPortPortTransform\_insert\_or\_assign**](#function-mapinstrumentportporttransform_insert_or_assign) (MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value) <br> |
|  ListPairInstrumentPortPortTransformHandle | [**MapInstrumentPortPortTransform\_items**](#function-mapinstrumentportporttransform_items) (MapInstrumentPortPortTransformHandle handle) <br> |
|  ListInstrumentPortHandle | [**MapInstrumentPortPortTransform\_keys**](#function-mapinstrumentportporttransform_keys) (MapInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**MapInstrumentPortPortTransform\_not\_equal**](#function-mapinstrumentportporttransform_not_equal) (MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other) <br> |
|  size\_t | [**MapInstrumentPortPortTransform\_size**](#function-mapinstrumentportporttransform_size) (MapInstrumentPortPortTransformHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**MapInstrumentPortPortTransform\_to\_json\_string**](#function-mapinstrumentportporttransform_to_json_string) (MapInstrumentPortPortTransformHandle handle) <br> |
|  ListPortTransformHandle | [**MapInstrumentPortPortTransform\_values**](#function-mapinstrumentportporttransform_values) (MapInstrumentPortPortTransformHandle handle) <br> |




























## Public Types Documentation




### typedef MapInstrumentPortPortTransformHandle 

```C++
typedef void* MapInstrumentPortPortTransformHandle;
```




<hr>
## Public Functions Documentation




### function MapInstrumentPortPortTransform\_at 

```C++
PortTransformHandle MapInstrumentPortPortTransform_at (
    MapInstrumentPortPortTransformHandle handle,
    InstrumentPortHandle key
) 
```




<hr>



### function MapInstrumentPortPortTransform\_clear 

```C++
void MapInstrumentPortPortTransform_clear (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_contains 

```C++
bool MapInstrumentPortPortTransform_contains (
    MapInstrumentPortPortTransformHandle handle,
    InstrumentPortHandle key
) 
```




<hr>



### function MapInstrumentPortPortTransform\_copy 

```C++
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_copy (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_create 

```C++
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create (
    PairInstrumentPortPortTransformHandle * data,
    size_t count
) 
```




<hr>



### function MapInstrumentPortPortTransform\_create\_empty 

```C++
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty () 
```




<hr>



### function MapInstrumentPortPortTransform\_destroy 

```C++
void MapInstrumentPortPortTransform_destroy (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_empty 

```C++
bool MapInstrumentPortPortTransform_empty (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_equal 

```C++
bool MapInstrumentPortPortTransform_equal (
    MapInstrumentPortPortTransformHandle handle,
    MapInstrumentPortPortTransformHandle other
) 
```




<hr>



### function MapInstrumentPortPortTransform\_erase 

```C++
void MapInstrumentPortPortTransform_erase (
    MapInstrumentPortPortTransformHandle handle,
    InstrumentPortHandle key
) 
```




<hr>



### function MapInstrumentPortPortTransform\_from\_json\_string 

```C++
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapInstrumentPortPortTransform\_insert 

```C++
void MapInstrumentPortPortTransform_insert (
    MapInstrumentPortPortTransformHandle handle,
    InstrumentPortHandle key,
    PortTransformHandle value
) 
```




<hr>



### function MapInstrumentPortPortTransform\_insert\_or\_assign 

```C++
void MapInstrumentPortPortTransform_insert_or_assign (
    MapInstrumentPortPortTransformHandle handle,
    InstrumentPortHandle key,
    PortTransformHandle value
) 
```




<hr>



### function MapInstrumentPortPortTransform\_items 

```C++
ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_keys 

```C++
ListInstrumentPortHandle MapInstrumentPortPortTransform_keys (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_not\_equal 

```C++
bool MapInstrumentPortPortTransform_not_equal (
    MapInstrumentPortPortTransformHandle handle,
    MapInstrumentPortPortTransformHandle other
) 
```




<hr>



### function MapInstrumentPortPortTransform\_size 

```C++
size_t MapInstrumentPortPortTransform_size (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_to\_json\_string 

```C++
StringHandle MapInstrumentPortPortTransform_to_json_string (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function MapInstrumentPortPortTransform\_values 

```C++
ListPortTransformHandle MapInstrumentPortPortTransform_values (
    MapInstrumentPortPortTransformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapInstrumentPortPortTransform_c_api.h`

