

# File Connection\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Connection\_c\_api.h**](Connection__c__api_8h.md)

[Go to the source code of this file](Connection__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ConnectionHandle**](#typedef-connectionhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionHandle | [**Connection\_copy**](#function-connection_copy) (ConnectionHandle handle) <br> |
|  ConnectionHandle | [**Connection\_create\_barrier\_gate**](#function-connection_create_barrier_gate) (StringHandle name) <br> |
|  ConnectionHandle | [**Connection\_create\_ohmic**](#function-connection_create_ohmic) (StringHandle name) <br> |
|  ConnectionHandle | [**Connection\_create\_plunger\_gate**](#function-connection_create_plunger_gate) (StringHandle name) <br> |
|  ConnectionHandle | [**Connection\_create\_reservoir\_gate**](#function-connection_create_reservoir_gate) (StringHandle name) <br> |
|  ConnectionHandle | [**Connection\_create\_screening\_gate**](#function-connection_create_screening_gate) (StringHandle name) <br> |
|  void | [**Connection\_destroy**](#function-connection_destroy) (ConnectionHandle handle) <br> |
|  bool | [**Connection\_equal**](#function-connection_equal) (ConnectionHandle handle, ConnectionHandle other) <br> |
|  ConnectionHandle | [**Connection\_from\_json\_string**](#function-connection_from_json_string) (StringHandle json) <br> |
|  bool | [**Connection\_is\_barrier\_gate**](#function-connection_is_barrier_gate) (ConnectionHandle handle) <br>_Check if the connection is a barriergate._  |
|  bool | [**Connection\_is\_dot\_gate**](#function-connection_is_dot_gate) (ConnectionHandle handle) <br>_Check if the connection is a plungergate or barriergate._  |
|  bool | [**Connection\_is\_gate**](#function-connection_is_gate) (ConnectionHandle handle) <br>_Check if the connection is any type of gate (barrier, plunger, reservoir, screening)._  |
|  bool | [**Connection\_is\_ohmic**](#function-connection_is_ohmic) (ConnectionHandle handle) <br>_Check if the connection is an ohmic contact._  |
|  bool | [**Connection\_is\_plunger\_gate**](#function-connection_is_plunger_gate) (ConnectionHandle handle) <br>_Check if the connection is a plunger gate._  |
|  bool | [**Connection\_is\_reservoir\_gate**](#function-connection_is_reservoir_gate) (ConnectionHandle handle) <br>_Check if the connection is a reservoir gate._  |
|  bool | [**Connection\_is\_screening\_gate**](#function-connection_is_screening_gate) (ConnectionHandle handle) <br>_Check if the connection is a screening gate._  |
|  StringHandle | [**Connection\_name**](#function-connection_name) (ConnectionHandle handle) <br>_The name of the connection._  |
|  bool | [**Connection\_not\_equal**](#function-connection_not_equal) (ConnectionHandle handle, ConnectionHandle other) <br> |
|  StringHandle | [**Connection\_to\_json\_string**](#function-connection_to_json_string) (ConnectionHandle handle) <br> |
|  StringHandle | [**Connection\_type**](#function-connection_type) (ConnectionHandle handle) <br>_The type of the connection._  |




























## Public Types Documentation




### typedef ConnectionHandle 

```C++
typedef void* ConnectionHandle;
```




<hr>
## Public Functions Documentation




### function Connection\_copy 

```C++
ConnectionHandle Connection_copy (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_create\_barrier\_gate 

```C++
ConnectionHandle Connection_create_barrier_gate (
    StringHandle name
) 
```




<hr>



### function Connection\_create\_ohmic 

```C++
ConnectionHandle Connection_create_ohmic (
    StringHandle name
) 
```




<hr>



### function Connection\_create\_plunger\_gate 

```C++
ConnectionHandle Connection_create_plunger_gate (
    StringHandle name
) 
```




<hr>



### function Connection\_create\_reservoir\_gate 

```C++
ConnectionHandle Connection_create_reservoir_gate (
    StringHandle name
) 
```




<hr>



### function Connection\_create\_screening\_gate 

```C++
ConnectionHandle Connection_create_screening_gate (
    StringHandle name
) 
```




<hr>



### function Connection\_destroy 

```C++
void Connection_destroy (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_equal 

```C++
bool Connection_equal (
    ConnectionHandle handle,
    ConnectionHandle other
) 
```




<hr>



### function Connection\_from\_json\_string 

```C++
ConnectionHandle Connection_from_json_string (
    StringHandle json
) 
```




<hr>



### function Connection\_is\_barrier\_gate 

_Check if the connection is a barriergate._ 
```C++
bool Connection_is_barrier_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_dot\_gate 

_Check if the connection is a plungergate or barriergate._ 
```C++
bool Connection_is_dot_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_gate 

_Check if the connection is any type of gate (barrier, plunger, reservoir, screening)._ 
```C++
bool Connection_is_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_ohmic 

_Check if the connection is an ohmic contact._ 
```C++
bool Connection_is_ohmic (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_plunger\_gate 

_Check if the connection is a plunger gate._ 
```C++
bool Connection_is_plunger_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_reservoir\_gate 

_Check if the connection is a reservoir gate._ 
```C++
bool Connection_is_reservoir_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_is\_screening\_gate 

_Check if the connection is a screening gate._ 
```C++
bool Connection_is_screening_gate (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_name 

_The name of the connection._ 
```C++
StringHandle Connection_name (
    ConnectionHandle handle
) 
```





**Returns:**

The name as a string. 





        

<hr>



### function Connection\_not\_equal 

```C++
bool Connection_not_equal (
    ConnectionHandle handle,
    ConnectionHandle other
) 
```




<hr>



### function Connection\_to\_json\_string 

```C++
StringHandle Connection_to_json_string (
    ConnectionHandle handle
) 
```




<hr>



### function Connection\_type 

_The type of the connection._ 
```C++
StringHandle Connection_type (
    ConnectionHandle handle
) 
```





**Returns:**

The type as a string. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/device_structures/Connection_c_api.h`

