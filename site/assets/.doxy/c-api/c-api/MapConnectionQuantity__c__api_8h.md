

# File MapConnectionQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionQuantity\_c\_api.h**](MapConnectionQuantity__c__api_8h.md)

[Go to the source code of this file](MapConnectionQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionQuantity_c_api.h"`
* `#include "falcon_core/generic/ListQuantity_c_api.h"`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/ListPairConnectionQuantity_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapConnectionQuantityHandle**](#typedef-mapconnectionquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  QuantityHandle | [**MapConnectionQuantity\_at**](#function-mapconnectionquantity_at) (MapConnectionQuantityHandle handle, ConnectionHandle key) <br> |
|  void | [**MapConnectionQuantity\_clear**](#function-mapconnectionquantity_clear) (MapConnectionQuantityHandle handle) <br> |
|  bool | [**MapConnectionQuantity\_contains**](#function-mapconnectionquantity_contains) (MapConnectionQuantityHandle handle, ConnectionHandle key) <br> |
|  MapConnectionQuantityHandle | [**MapConnectionQuantity\_copy**](#function-mapconnectionquantity_copy) (MapConnectionQuantityHandle handle) <br> |
|  MapConnectionQuantityHandle | [**MapConnectionQuantity\_create**](#function-mapconnectionquantity_create) (PairConnectionQuantityHandle \* data, size\_t count) <br> |
|  MapConnectionQuantityHandle | [**MapConnectionQuantity\_create\_empty**](#function-mapconnectionquantity_create_empty) () <br> |
|  void | [**MapConnectionQuantity\_destroy**](#function-mapconnectionquantity_destroy) (MapConnectionQuantityHandle handle) <br> |
|  bool | [**MapConnectionQuantity\_empty**](#function-mapconnectionquantity_empty) (MapConnectionQuantityHandle handle) <br> |
|  bool | [**MapConnectionQuantity\_equal**](#function-mapconnectionquantity_equal) (MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other) <br> |
|  void | [**MapConnectionQuantity\_erase**](#function-mapconnectionquantity_erase) (MapConnectionQuantityHandle handle, ConnectionHandle key) <br> |
|  MapConnectionQuantityHandle | [**MapConnectionQuantity\_from\_json\_string**](#function-mapconnectionquantity_from_json_string) (StringHandle json) <br> |
|  void | [**MapConnectionQuantity\_insert**](#function-mapconnectionquantity_insert) (MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value) <br> |
|  void | [**MapConnectionQuantity\_insert\_or\_assign**](#function-mapconnectionquantity_insert_or_assign) (MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value) <br> |
|  ListPairConnectionQuantityHandle | [**MapConnectionQuantity\_items**](#function-mapconnectionquantity_items) (MapConnectionQuantityHandle handle) <br> |
|  ListConnectionHandle | [**MapConnectionQuantity\_keys**](#function-mapconnectionquantity_keys) (MapConnectionQuantityHandle handle) <br> |
|  bool | [**MapConnectionQuantity\_not\_equal**](#function-mapconnectionquantity_not_equal) (MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other) <br> |
|  size\_t | [**MapConnectionQuantity\_size**](#function-mapconnectionquantity_size) (MapConnectionQuantityHandle handle) <br> |
|  StringHandle | [**MapConnectionQuantity\_to\_json\_string**](#function-mapconnectionquantity_to_json_string) (MapConnectionQuantityHandle handle) <br> |
|  ListQuantityHandle | [**MapConnectionQuantity\_values**](#function-mapconnectionquantity_values) (MapConnectionQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef MapConnectionQuantityHandle 

```C++
typedef void* MapConnectionQuantityHandle;
```




<hr>
## Public Functions Documentation




### function MapConnectionQuantity\_at 

```C++
QuantityHandle MapConnectionQuantity_at (
    MapConnectionQuantityHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionQuantity\_clear 

```C++
void MapConnectionQuantity_clear (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_contains 

```C++
bool MapConnectionQuantity_contains (
    MapConnectionQuantityHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionQuantity\_copy 

```C++
MapConnectionQuantityHandle MapConnectionQuantity_copy (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_create 

```C++
MapConnectionQuantityHandle MapConnectionQuantity_create (
    PairConnectionQuantityHandle * data,
    size_t count
) 
```




<hr>



### function MapConnectionQuantity\_create\_empty 

```C++
MapConnectionQuantityHandle MapConnectionQuantity_create_empty () 
```




<hr>



### function MapConnectionQuantity\_destroy 

```C++
void MapConnectionQuantity_destroy (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_empty 

```C++
bool MapConnectionQuantity_empty (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_equal 

```C++
bool MapConnectionQuantity_equal (
    MapConnectionQuantityHandle handle,
    MapConnectionQuantityHandle other
) 
```




<hr>



### function MapConnectionQuantity\_erase 

```C++
void MapConnectionQuantity_erase (
    MapConnectionQuantityHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function MapConnectionQuantity\_from\_json\_string 

```C++
MapConnectionQuantityHandle MapConnectionQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapConnectionQuantity\_insert 

```C++
void MapConnectionQuantity_insert (
    MapConnectionQuantityHandle handle,
    ConnectionHandle key,
    QuantityHandle value
) 
```




<hr>



### function MapConnectionQuantity\_insert\_or\_assign 

```C++
void MapConnectionQuantity_insert_or_assign (
    MapConnectionQuantityHandle handle,
    ConnectionHandle key,
    QuantityHandle value
) 
```




<hr>



### function MapConnectionQuantity\_items 

```C++
ListPairConnectionQuantityHandle MapConnectionQuantity_items (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_keys 

```C++
ListConnectionHandle MapConnectionQuantity_keys (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_not\_equal 

```C++
bool MapConnectionQuantity_not_equal (
    MapConnectionQuantityHandle handle,
    MapConnectionQuantityHandle other
) 
```




<hr>



### function MapConnectionQuantity\_size 

```C++
size_t MapConnectionQuantity_size (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_to\_json\_string 

```C++
StringHandle MapConnectionQuantity_to_json_string (
    MapConnectionQuantityHandle handle
) 
```




<hr>



### function MapConnectionQuantity\_values 

```C++
ListQuantityHandle MapConnectionQuantity_values (
    MapConnectionQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapConnectionQuantity_c_api.h`

