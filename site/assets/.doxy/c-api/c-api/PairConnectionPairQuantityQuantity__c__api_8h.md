

# File PairConnectionPairQuantityQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionPairQuantityQuantity\_c\_api.h**](PairConnectionPairQuantityQuantity__c__api_8h.md)

[Go to the source code of this file](PairConnectionPairQuantityQuantity__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/generic/PairQuantityQuantity_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionPairQuantityQuantityHandle**](#typedef-pairconnectionpairquantityquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionPairQuantityQuantityHandle | [**PairConnectionPairQuantityQuantity\_copy**](#function-pairconnectionpairquantityquantity_copy) (PairConnectionPairQuantityQuantityHandle handle) <br> |
|  PairConnectionPairQuantityQuantityHandle | [**PairConnectionPairQuantityQuantity\_create**](#function-pairconnectionpairquantityquantity_create) (ConnectionHandle first, PairQuantityQuantityHandle second) <br> |
|  void | [**PairConnectionPairQuantityQuantity\_destroy**](#function-pairconnectionpairquantityquantity_destroy) (PairConnectionPairQuantityQuantityHandle handle) <br> |
|  bool | [**PairConnectionPairQuantityQuantity\_equal**](#function-pairconnectionpairquantityquantity_equal) (PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other) <br> |
|  ConnectionHandle | [**PairConnectionPairQuantityQuantity\_first**](#function-pairconnectionpairquantityquantity_first) (PairConnectionPairQuantityQuantityHandle handle) <br> |
|  PairConnectionPairQuantityQuantityHandle | [**PairConnectionPairQuantityQuantity\_from\_json\_string**](#function-pairconnectionpairquantityquantity_from_json_string) (StringHandle json) <br> |
|  bool | [**PairConnectionPairQuantityQuantity\_not\_equal**](#function-pairconnectionpairquantityquantity_not_equal) (PairConnectionPairQuantityQuantityHandle handle, PairConnectionPairQuantityQuantityHandle other) <br> |
|  PairQuantityQuantityHandle | [**PairConnectionPairQuantityQuantity\_second**](#function-pairconnectionpairquantityquantity_second) (PairConnectionPairQuantityQuantityHandle handle) <br> |
|  StringHandle | [**PairConnectionPairQuantityQuantity\_to\_json\_string**](#function-pairconnectionpairquantityquantity_to_json_string) (PairConnectionPairQuantityQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionPairQuantityQuantityHandle 

```C++
typedef void* PairConnectionPairQuantityQuantityHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionPairQuantityQuantity\_copy 

```C++
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_copy (
    PairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_create 

```C++
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_create (
    ConnectionHandle first,
    PairQuantityQuantityHandle second
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_destroy 

```C++
void PairConnectionPairQuantityQuantity_destroy (
    PairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_equal 

```C++
bool PairConnectionPairQuantityQuantity_equal (
    PairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle other
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_first 

```C++
ConnectionHandle PairConnectionPairQuantityQuantity_first (
    PairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_from\_json\_string 

```C++
PairConnectionPairQuantityQuantityHandle PairConnectionPairQuantityQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_not\_equal 

```C++
bool PairConnectionPairQuantityQuantity_not_equal (
    PairConnectionPairQuantityQuantityHandle handle,
    PairConnectionPairQuantityQuantityHandle other
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_second 

```C++
PairQuantityQuantityHandle PairConnectionPairQuantityQuantity_second (
    PairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>



### function PairConnectionPairQuantityQuantity\_to\_json\_string 

```C++
StringHandle PairConnectionPairQuantityQuantity_to_json_string (
    PairConnectionPairQuantityQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionPairQuantityQuantity_c_api.h`

