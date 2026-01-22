

# File GateRelations\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**GateRelations\_c\_api.h**](GateRelations__c__api_8h.md)

[Go to the source code of this file](GateRelations__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListConnections_c_api.h"`
* `#include "falcon_core/generic/ListPairConnectionConnections_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**GateRelationsHandle**](#typedef-gaterelationshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionsHandle | [**GateRelations\_at**](#function-gaterelations_at) (GateRelationsHandle handle, ConnectionHandle key) <br> |
|  void | [**GateRelations\_clear**](#function-gaterelations_clear) (GateRelationsHandle handle) <br> |
|  bool | [**GateRelations\_contains**](#function-gaterelations_contains) (GateRelationsHandle handle, ConnectionHandle key) <br> |
|  GateRelationsHandle | [**GateRelations\_copy**](#function-gaterelations_copy) (GateRelationsHandle handle) <br> |
|  GateRelationsHandle | [**GateRelations\_create**](#function-gaterelations_create) (ListPairConnectionConnectionsHandle items) <br> |
|  GateRelationsHandle | [**GateRelations\_create\_empty**](#function-gaterelations_create_empty) () <br> |
|  void | [**GateRelations\_destroy**](#function-gaterelations_destroy) (GateRelationsHandle handle) <br> |
|  bool | [**GateRelations\_empty**](#function-gaterelations_empty) (GateRelationsHandle handle) <br> |
|  bool | [**GateRelations\_equal**](#function-gaterelations_equal) (GateRelationsHandle handle, GateRelationsHandle other) <br> |
|  void | [**GateRelations\_erase**](#function-gaterelations_erase) (GateRelationsHandle handle, ConnectionHandle key) <br> |
|  GateRelationsHandle | [**GateRelations\_from\_json\_string**](#function-gaterelations_from_json_string) (StringHandle json) <br> |
|  void | [**GateRelations\_insert**](#function-gaterelations_insert) (GateRelationsHandle handle, ConnectionHandle key, ConnectionsHandle value) <br> |
|  void | [**GateRelations\_insert\_or\_assign**](#function-gaterelations_insert_or_assign) (GateRelationsHandle handle, ConnectionHandle key, ConnectionsHandle value) <br>_Override the default Map assignment to force gate typing._  |
|  ListPairConnectionConnectionsHandle | [**GateRelations\_items**](#function-gaterelations_items) (GateRelationsHandle handle) <br> |
|  ListConnectionHandle | [**GateRelations\_keys**](#function-gaterelations_keys) (GateRelationsHandle handle) <br> |
|  bool | [**GateRelations\_not\_equal**](#function-gaterelations_not_equal) (GateRelationsHandle handle, GateRelationsHandle other) <br> |
|  size\_t | [**GateRelations\_size**](#function-gaterelations_size) (GateRelationsHandle handle) <br> |
|  StringHandle | [**GateRelations\_to\_json\_string**](#function-gaterelations_to_json_string) (GateRelationsHandle handle) <br> |
|  ListConnectionsHandle | [**GateRelations\_values**](#function-gaterelations_values) (GateRelationsHandle handle) <br> |




























## Public Types Documentation




### typedef GateRelationsHandle 

```C++
typedef void* GateRelationsHandle;
```




<hr>
## Public Functions Documentation




### function GateRelations\_at 

```C++
ConnectionsHandle GateRelations_at (
    GateRelationsHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function GateRelations\_clear 

```C++
void GateRelations_clear (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_contains 

```C++
bool GateRelations_contains (
    GateRelationsHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function GateRelations\_copy 

```C++
GateRelationsHandle GateRelations_copy (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_create 

```C++
GateRelationsHandle GateRelations_create (
    ListPairConnectionConnectionsHandle items
) 
```




<hr>



### function GateRelations\_create\_empty 

```C++
GateRelationsHandle GateRelations_create_empty () 
```




<hr>



### function GateRelations\_destroy 

```C++
void GateRelations_destroy (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_empty 

```C++
bool GateRelations_empty (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_equal 

```C++
bool GateRelations_equal (
    GateRelationsHandle handle,
    GateRelationsHandle other
) 
```




<hr>



### function GateRelations\_erase 

```C++
void GateRelations_erase (
    GateRelationsHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function GateRelations\_from\_json\_string 

```C++
GateRelationsHandle GateRelations_from_json_string (
    StringHandle json
) 
```




<hr>



### function GateRelations\_insert 

```C++
void GateRelations_insert (
    GateRelationsHandle handle,
    ConnectionHandle key,
    ConnectionsHandle value
) 
```




<hr>



### function GateRelations\_insert\_or\_assign 

_Override the default Map assignment to force gate typing._ 
```C++
void GateRelations_insert_or_assign (
    GateRelationsHandle handle,
    ConnectionHandle key,
    ConnectionsHandle value
) 
```




<hr>



### function GateRelations\_items 

```C++
ListPairConnectionConnectionsHandle GateRelations_items (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_keys 

```C++
ListConnectionHandle GateRelations_keys (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_not\_equal 

```C++
bool GateRelations_not_equal (
    GateRelationsHandle handle,
    GateRelationsHandle other
) 
```




<hr>



### function GateRelations\_size 

```C++
size_t GateRelations_size (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_to\_json\_string 

```C++
StringHandle GateRelations_to_json_string (
    GateRelationsHandle handle
) 
```




<hr>



### function GateRelations\_values 

```C++
ListConnectionsHandle GateRelations_values (
    GateRelationsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/device_structures/GateRelations_c_api.h`

