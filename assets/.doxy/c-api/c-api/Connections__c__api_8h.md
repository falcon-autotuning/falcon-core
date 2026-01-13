

# File Connections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Connections\_c\_api.h**](Connections__c__api_8h.md)

[Go to the source code of this file](Connections__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ConnectionsHandle**](#typedef-connectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionHandle | [**Connections\_at**](#function-connections_at) (ConnectionsHandle handle, size\_t idx) <br> |
|  void | [**Connections\_clear**](#function-connections_clear) (ConnectionsHandle handle) <br> |
|  bool | [**Connections\_contains**](#function-connections_contains) (ConnectionsHandle handle, ConnectionHandle value) <br> |
|  ConnectionsHandle | [**Connections\_copy**](#function-connections_copy) (ConnectionsHandle handle) <br> |
|  ConnectionsHandle | [**Connections\_create**](#function-connections_create) (ListConnectionHandle items) <br> |
|  ConnectionsHandle | [**Connections\_create\_empty**](#function-connections_create_empty) () <br> |
|  void | [**Connections\_destroy**](#function-connections_destroy) (ConnectionsHandle handle) <br> |
|  bool | [**Connections\_empty**](#function-connections_empty) (ConnectionsHandle handle) <br> |
|  bool | [**Connections\_equal**](#function-connections_equal) (ConnectionsHandle handle, ConnectionsHandle other) <br> |
|  void | [**Connections\_erase\_at**](#function-connections_erase_at) (ConnectionsHandle handle, size\_t idx) <br> |
|  ConnectionsHandle | [**Connections\_from\_json\_string**](#function-connections_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**Connections\_index**](#function-connections_index) (ConnectionsHandle handle, ConnectionHandle value) <br> |
|  ConnectionsHandle | [**Connections\_intersection**](#function-connections_intersection) (ConnectionsHandle handle, ConnectionsHandle other) <br>_Finds the intersection between this list and another._  |
|  bool | [**Connections\_is\_barrier\_gates**](#function-connections_is_barrier_gates) (ConnectionsHandle handle) <br>_Check if all connections are barrier gates._  |
|  bool | [**Connections\_is\_dot\_gates**](#function-connections_is_dot_gates) (ConnectionsHandle handle) <br>_Check if all connections are dot gates (plunger or barrier)._  |
|  bool | [**Connections\_is\_gates**](#function-connections_is_gates) (ConnectionsHandle handle) <br>_Check if all connections are gates (not ohmics)._  |
|  bool | [**Connections\_is\_ohmics**](#function-connections_is_ohmics) (ConnectionsHandle handle) <br>_Check if all connections are ohmics (not gates)._  |
|  bool | [**Connections\_is\_plunger\_gates**](#function-connections_is_plunger_gates) (ConnectionsHandle handle) <br>_Check if all connections are plunger gates._  |
|  bool | [**Connections\_is\_reservoir\_gates**](#function-connections_is_reservoir_gates) (ConnectionsHandle handle) <br>_Check if all connections are reservoir gates._  |
|  bool | [**Connections\_is\_screening\_gates**](#function-connections_is_screening_gates) (ConnectionsHandle handle) <br>_Check if all connections are screening gates._  |
|  ListConnectionHandle | [**Connections\_items**](#function-connections_items) (ConnectionsHandle handle) <br> |
|  bool | [**Connections\_not\_equal**](#function-connections_not_equal) (ConnectionsHandle handle, ConnectionsHandle other) <br> |
|  void | [**Connections\_push\_back**](#function-connections_push_back) (ConnectionsHandle handle, ConnectionHandle value) <br> |
|  size\_t | [**Connections\_size**](#function-connections_size) (ConnectionsHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**Connections\_to\_json\_string**](#function-connections_to_json_string) (ConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef ConnectionsHandle 

```C++
typedef void* ConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function Connections\_at 

```C++
ConnectionHandle Connections_at (
    ConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function Connections\_clear 

```C++
void Connections_clear (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_contains 

```C++
bool Connections_contains (
    ConnectionsHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function Connections\_copy 

```C++
ConnectionsHandle Connections_copy (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_create 

```C++
ConnectionsHandle Connections_create (
    ListConnectionHandle items
) 
```




<hr>



### function Connections\_create\_empty 

```C++
ConnectionsHandle Connections_create_empty () 
```




<hr>



### function Connections\_destroy 

```C++
void Connections_destroy (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_empty 

```C++
bool Connections_empty (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_equal 

```C++
bool Connections_equal (
    ConnectionsHandle handle,
    ConnectionsHandle other
) 
```




<hr>



### function Connections\_erase\_at 

```C++
void Connections_erase_at (
    ConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function Connections\_from\_json\_string 

```C++
ConnectionsHandle Connections_from_json_string (
    StringHandle json
) 
```




<hr>



### function Connections\_index 

```C++
size_t Connections_index (
    ConnectionsHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function Connections\_intersection 

_Finds the intersection between this list and another._ 
```C++
ConnectionsHandle Connections_intersection (
    ConnectionsHandle handle,
    ConnectionsHandle other
) 
```





**Parameters:**


* `other` the other list to compare again. 



**Returns:**

A list of values containing elements from both. 





        

<hr>



### function Connections\_is\_barrier\_gates 

_Check if all connections are barrier gates._ 
```C++
bool Connections_is_barrier_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_dot\_gates 

_Check if all connections are dot gates (plunger or barrier)._ 
```C++
bool Connections_is_dot_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_gates 

_Check if all connections are gates (not ohmics)._ 
```C++
bool Connections_is_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_ohmics 

_Check if all connections are ohmics (not gates)._ 
```C++
bool Connections_is_ohmics (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_plunger\_gates 

_Check if all connections are plunger gates._ 
```C++
bool Connections_is_plunger_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_reservoir\_gates 

_Check if all connections are reservoir gates._ 
```C++
bool Connections_is_reservoir_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_is\_screening\_gates 

_Check if all connections are screening gates._ 
```C++
bool Connections_is_screening_gates (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_items 

```C++
ListConnectionHandle Connections_items (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_not\_equal 

```C++
bool Connections_not_equal (
    ConnectionsHandle handle,
    ConnectionsHandle other
) 
```




<hr>



### function Connections\_push\_back 

```C++
void Connections_push_back (
    ConnectionsHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function Connections\_size 

```C++
size_t Connections_size (
    ConnectionsHandle handle
) 
```




<hr>



### function Connections\_to\_json\_string 

```C++
StringHandle Connections_to_json_string (
    ConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/device_structures/Connections_c_api.h`

