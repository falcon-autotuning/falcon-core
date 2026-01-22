

# File PairQuantityQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairQuantityQuantity\_c\_api.h**](PairQuantityQuantity__c__api_8h.md)

[Go to the source code of this file](PairQuantityQuantity__c__api_8h_source.md)



* `#include "falcon_core/math/Quantity_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairQuantityQuantityHandle**](#typedef-pairquantityquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairQuantityQuantityHandle | [**PairQuantityQuantity\_copy**](#function-pairquantityquantity_copy) (PairQuantityQuantityHandle handle) <br> |
|  PairQuantityQuantityHandle | [**PairQuantityQuantity\_create**](#function-pairquantityquantity_create) (QuantityHandle first, QuantityHandle second) <br> |
|  void | [**PairQuantityQuantity\_destroy**](#function-pairquantityquantity_destroy) (PairQuantityQuantityHandle handle) <br> |
|  bool | [**PairQuantityQuantity\_equal**](#function-pairquantityquantity_equal) (PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other) <br> |
|  QuantityHandle | [**PairQuantityQuantity\_first**](#function-pairquantityquantity_first) (PairQuantityQuantityHandle handle) <br> |
|  PairQuantityQuantityHandle | [**PairQuantityQuantity\_from\_json\_string**](#function-pairquantityquantity_from_json_string) (StringHandle json) <br> |
|  bool | [**PairQuantityQuantity\_not\_equal**](#function-pairquantityquantity_not_equal) (PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other) <br> |
|  QuantityHandle | [**PairQuantityQuantity\_second**](#function-pairquantityquantity_second) (PairQuantityQuantityHandle handle) <br> |
|  StringHandle | [**PairQuantityQuantity\_to\_json\_string**](#function-pairquantityquantity_to_json_string) (PairQuantityQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef PairQuantityQuantityHandle 

```C++
typedef void* PairQuantityQuantityHandle;
```




<hr>
## Public Functions Documentation




### function PairQuantityQuantity\_copy 

```C++
PairQuantityQuantityHandle PairQuantityQuantity_copy (
    PairQuantityQuantityHandle handle
) 
```




<hr>



### function PairQuantityQuantity\_create 

```C++
PairQuantityQuantityHandle PairQuantityQuantity_create (
    QuantityHandle first,
    QuantityHandle second
) 
```




<hr>



### function PairQuantityQuantity\_destroy 

```C++
void PairQuantityQuantity_destroy (
    PairQuantityQuantityHandle handle
) 
```




<hr>



### function PairQuantityQuantity\_equal 

```C++
bool PairQuantityQuantity_equal (
    PairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle other
) 
```




<hr>



### function PairQuantityQuantity\_first 

```C++
QuantityHandle PairQuantityQuantity_first (
    PairQuantityQuantityHandle handle
) 
```




<hr>



### function PairQuantityQuantity\_from\_json\_string 

```C++
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairQuantityQuantity\_not\_equal 

```C++
bool PairQuantityQuantity_not_equal (
    PairQuantityQuantityHandle handle,
    PairQuantityQuantityHandle other
) 
```




<hr>



### function PairQuantityQuantity\_second 

```C++
QuantityHandle PairQuantityQuantity_second (
    PairQuantityQuantityHandle handle
) 
```




<hr>



### function PairQuantityQuantity\_to\_json\_string 

```C++
StringHandle PairQuantityQuantity_to_json_string (
    PairQuantityQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairQuantityQuantity_c_api.h`

