

# File PairConnectionFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionFloat\_c\_api.h**](PairConnectionFloat__c__api_8h.md)

[Go to the source code of this file](PairConnectionFloat__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionFloatHandle**](#typedef-pairconnectionfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionFloatHandle | [**PairConnectionFloat\_copy**](#function-pairconnectionfloat_copy) (PairConnectionFloatHandle handle) <br> |
|  PairConnectionFloatHandle | [**PairConnectionFloat\_create**](#function-pairconnectionfloat_create) (ConnectionHandle first, float second) <br> |
|  void | [**PairConnectionFloat\_destroy**](#function-pairconnectionfloat_destroy) (PairConnectionFloatHandle handle) <br> |
|  bool | [**PairConnectionFloat\_equal**](#function-pairconnectionfloat_equal) (PairConnectionFloatHandle handle, PairConnectionFloatHandle other) <br> |
|  ConnectionHandle | [**PairConnectionFloat\_first**](#function-pairconnectionfloat_first) (PairConnectionFloatHandle handle) <br> |
|  PairConnectionFloatHandle | [**PairConnectionFloat\_from\_json\_string**](#function-pairconnectionfloat_from_json_string) (StringHandle json) <br> |
|  bool | [**PairConnectionFloat\_not\_equal**](#function-pairconnectionfloat_not_equal) (PairConnectionFloatHandle handle, PairConnectionFloatHandle other) <br> |
|  float | [**PairConnectionFloat\_second**](#function-pairconnectionfloat_second) (PairConnectionFloatHandle handle) <br> |
|  StringHandle | [**PairConnectionFloat\_to\_json\_string**](#function-pairconnectionfloat_to_json_string) (PairConnectionFloatHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionFloatHandle 

```C++
typedef void* PairConnectionFloatHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionFloat\_copy 

```C++
PairConnectionFloatHandle PairConnectionFloat_copy (
    PairConnectionFloatHandle handle
) 
```




<hr>



### function PairConnectionFloat\_create 

```C++
PairConnectionFloatHandle PairConnectionFloat_create (
    ConnectionHandle first,
    float second
) 
```




<hr>



### function PairConnectionFloat\_destroy 

```C++
void PairConnectionFloat_destroy (
    PairConnectionFloatHandle handle
) 
```




<hr>



### function PairConnectionFloat\_equal 

```C++
bool PairConnectionFloat_equal (
    PairConnectionFloatHandle handle,
    PairConnectionFloatHandle other
) 
```




<hr>



### function PairConnectionFloat\_first 

```C++
ConnectionHandle PairConnectionFloat_first (
    PairConnectionFloatHandle handle
) 
```




<hr>



### function PairConnectionFloat\_from\_json\_string 

```C++
PairConnectionFloatHandle PairConnectionFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionFloat\_not\_equal 

```C++
bool PairConnectionFloat_not_equal (
    PairConnectionFloatHandle handle,
    PairConnectionFloatHandle other
) 
```




<hr>



### function PairConnectionFloat\_second 

```C++
float PairConnectionFloat_second (
    PairConnectionFloatHandle handle
) 
```




<hr>



### function PairConnectionFloat\_to\_json\_string 

```C++
StringHandle PairConnectionFloat_to_json_string (
    PairConnectionFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionFloat_c_api.h`

