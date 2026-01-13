

# File PairConnectionQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionQuantity\_c\_api.h**](PairConnectionQuantity__c__api_8h.md)

[Go to the source code of this file](PairConnectionQuantity__c__api_8h_source.md)



* `#include "falcon_core/math/Quantity_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionQuantityHandle**](#typedef-pairconnectionquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionQuantityHandle | [**PairConnectionQuantity\_copy**](#function-pairconnectionquantity_copy) (PairConnectionQuantityHandle handle) <br> |
|  PairConnectionQuantityHandle | [**PairConnectionQuantity\_create**](#function-pairconnectionquantity_create) (ConnectionHandle first, QuantityHandle second) <br> |
|  void | [**PairConnectionQuantity\_destroy**](#function-pairconnectionquantity_destroy) (PairConnectionQuantityHandle handle) <br> |
|  bool | [**PairConnectionQuantity\_equal**](#function-pairconnectionquantity_equal) (PairConnectionQuantityHandle handle, PairConnectionQuantityHandle other) <br> |
|  ConnectionHandle | [**PairConnectionQuantity\_first**](#function-pairconnectionquantity_first) (PairConnectionQuantityHandle handle) <br> |
|  PairConnectionQuantityHandle | [**PairConnectionQuantity\_from\_json\_string**](#function-pairconnectionquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairConnectionQuantity\_not\_equal**](#function-pairconnectionquantity_not_equal) (PairConnectionQuantityHandle handle, PairConnectionQuantityHandle other) <br> |
|  QuantityHandle | [**PairConnectionQuantity\_second**](#function-pairconnectionquantity_second) (PairConnectionQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairConnectionQuantity\_to\_json\_string**](#function-pairconnectionquantity_to_json_string) (PairConnectionQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionQuantityHandle 

```C++
typedef void* PairConnectionQuantityHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionQuantity\_copy 

```C++
PairConnectionQuantityHandle PairConnectionQuantity_copy (
    PairConnectionQuantityHandle handle
) 
```




<hr>



### function PairConnectionQuantity\_create 

```C++
PairConnectionQuantityHandle PairConnectionQuantity_create (
    ConnectionHandle first,
    QuantityHandle second
) 
```




<hr>



### function PairConnectionQuantity\_destroy 

```C++
void PairConnectionQuantity_destroy (
    PairConnectionQuantityHandle handle
) 
```




<hr>



### function PairConnectionQuantity\_equal 

```C++
bool PairConnectionQuantity_equal (
    PairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle other
) 
```




<hr>



### function PairConnectionQuantity\_first 

```C++
ConnectionHandle PairConnectionQuantity_first (
    PairConnectionQuantityHandle handle
) 
```




<hr>



### function PairConnectionQuantity\_from\_json\_string 

```C++
PairConnectionQuantityHandle PairConnectionQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionQuantity\_not\_equal 

```C++
bool PairConnectionQuantity_not_equal (
    PairConnectionQuantityHandle handle,
    PairConnectionQuantityHandle other
) 
```




<hr>



### function PairConnectionQuantity\_second 

```C++
QuantityHandle PairConnectionQuantity_second (
    PairConnectionQuantityHandle handle
) 
```




<hr>



### function PairConnectionQuantity\_to\_json\_string 

```C++
StringHandle PairConnectionQuantity_to_json_string (
    PairConnectionQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionQuantity_c_api.h`

