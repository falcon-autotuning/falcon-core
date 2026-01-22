

# File PairConnectionDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionDouble\_c\_api.h**](PairConnectionDouble__c__api_8h.md)

[Go to the source code of this file](PairConnectionDouble__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionDoubleHandle**](#typedef-pairconnectiondoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionDoubleHandle | [**PairConnectionDouble\_copy**](#function-pairconnectiondouble_copy) (PairConnectionDoubleHandle handle) <br> |
|  PairConnectionDoubleHandle | [**PairConnectionDouble\_create**](#function-pairconnectiondouble_create) (ConnectionHandle first, double second) <br> |
|  void | [**PairConnectionDouble\_destroy**](#function-pairconnectiondouble_destroy) (PairConnectionDoubleHandle handle) <br> |
|  bool | [**PairConnectionDouble\_equal**](#function-pairconnectiondouble_equal) (PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other) <br> |
|  ConnectionHandle | [**PairConnectionDouble\_first**](#function-pairconnectiondouble_first) (PairConnectionDoubleHandle handle) <br> |
|  PairConnectionDoubleHandle | [**PairConnectionDouble\_from\_json\_string**](#function-pairconnectiondouble_from_json_string) (StringHandle json) <br> |
|  bool | [**PairConnectionDouble\_not\_equal**](#function-pairconnectiondouble_not_equal) (PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other) <br> |
|  double | [**PairConnectionDouble\_second**](#function-pairconnectiondouble_second) (PairConnectionDoubleHandle handle) <br> |
|  StringHandle | [**PairConnectionDouble\_to\_json\_string**](#function-pairconnectiondouble_to_json_string) (PairConnectionDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionDoubleHandle 

```C++
typedef void* PairConnectionDoubleHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionDouble\_copy 

```C++
PairConnectionDoubleHandle PairConnectionDouble_copy (
    PairConnectionDoubleHandle handle
) 
```




<hr>



### function PairConnectionDouble\_create 

```C++
PairConnectionDoubleHandle PairConnectionDouble_create (
    ConnectionHandle first,
    double second
) 
```




<hr>



### function PairConnectionDouble\_destroy 

```C++
void PairConnectionDouble_destroy (
    PairConnectionDoubleHandle handle
) 
```




<hr>



### function PairConnectionDouble\_equal 

```C++
bool PairConnectionDouble_equal (
    PairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle other
) 
```




<hr>



### function PairConnectionDouble\_first 

```C++
ConnectionHandle PairConnectionDouble_first (
    PairConnectionDoubleHandle handle
) 
```




<hr>



### function PairConnectionDouble\_from\_json\_string 

```C++
PairConnectionDoubleHandle PairConnectionDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionDouble\_not\_equal 

```C++
bool PairConnectionDouble_not_equal (
    PairConnectionDoubleHandle handle,
    PairConnectionDoubleHandle other
) 
```




<hr>



### function PairConnectionDouble\_second 

```C++
double PairConnectionDouble_second (
    PairConnectionDoubleHandle handle
) 
```




<hr>



### function PairConnectionDouble\_to\_json\_string 

```C++
StringHandle PairConnectionDouble_to_json_string (
    PairConnectionDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionDouble_c_api.h`

