

# File PairConnectionConnection\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionConnection\_c\_api.h**](PairConnectionConnection__c__api_8h.md)

[Go to the source code of this file](PairConnectionConnection__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionConnectionHandle**](#typedef-pairconnectionconnectionhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionConnectionHandle | [**PairConnectionConnection\_copy**](#function-pairconnectionconnection_copy) (PairConnectionConnectionHandle handle) <br> |
|  PairConnectionConnectionHandle | [**PairConnectionConnection\_create**](#function-pairconnectionconnection_create) (ConnectionHandle first, ConnectionHandle second) <br> |
|  void | [**PairConnectionConnection\_destroy**](#function-pairconnectionconnection_destroy) (PairConnectionConnectionHandle handle) <br> |
|  bool | [**PairConnectionConnection\_equal**](#function-pairconnectionconnection_equal) (PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other) <br> |
|  ConnectionHandle | [**PairConnectionConnection\_first**](#function-pairconnectionconnection_first) (PairConnectionConnectionHandle handle) <br> |
|  PairConnectionConnectionHandle | [**PairConnectionConnection\_from\_json\_string**](#function-pairconnectionconnection_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairConnectionConnection\_not\_equal**](#function-pairconnectionconnection_not_equal) (PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other) <br> |
|  ConnectionHandle | [**PairConnectionConnection\_second**](#function-pairconnectionconnection_second) (PairConnectionConnectionHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairConnectionConnection\_to\_json\_string**](#function-pairconnectionconnection_to_json_string) (PairConnectionConnectionHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionConnectionHandle 

```C++
typedef void* PairConnectionConnectionHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionConnection\_copy 

```C++
PairConnectionConnectionHandle PairConnectionConnection_copy (
    PairConnectionConnectionHandle handle
) 
```




<hr>



### function PairConnectionConnection\_create 

```C++
PairConnectionConnectionHandle PairConnectionConnection_create (
    ConnectionHandle first,
    ConnectionHandle second
) 
```




<hr>



### function PairConnectionConnection\_destroy 

```C++
void PairConnectionConnection_destroy (
    PairConnectionConnectionHandle handle
) 
```




<hr>



### function PairConnectionConnection\_equal 

```C++
bool PairConnectionConnection_equal (
    PairConnectionConnectionHandle handle,
    PairConnectionConnectionHandle other
) 
```




<hr>



### function PairConnectionConnection\_first 

```C++
ConnectionHandle PairConnectionConnection_first (
    PairConnectionConnectionHandle handle
) 
```




<hr>



### function PairConnectionConnection\_from\_json\_string 

```C++
PairConnectionConnectionHandle PairConnectionConnection_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionConnection\_not\_equal 

```C++
bool PairConnectionConnection_not_equal (
    PairConnectionConnectionHandle handle,
    PairConnectionConnectionHandle other
) 
```




<hr>



### function PairConnectionConnection\_second 

```C++
ConnectionHandle PairConnectionConnection_second (
    PairConnectionConnectionHandle handle
) 
```




<hr>



### function PairConnectionConnection\_to\_json\_string 

```C++
StringHandle PairConnectionConnection_to_json_string (
    PairConnectionConnectionHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionConnection_c_api.h`

