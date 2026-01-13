

# File PairInterpretationContextQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextQuantity\_c\_api.h**](PairInterpretationContextQuantity__c__api_8h.md)

[Go to the source code of this file](PairInterpretationContextQuantity__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include "falcon_core/math/Quantity_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairInterpretationContextQuantityHandle**](#typedef-pairinterpretationcontextquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextQuantityHandle | [**PairInterpretationContextQuantity\_copy**](#function-pairinterpretationcontextquantity_copy) (PairInterpretationContextQuantityHandle handle) <br> |
|  PairInterpretationContextQuantityHandle | [**PairInterpretationContextQuantity\_create**](#function-pairinterpretationcontextquantity_create) (InterpretationContextHandle first, QuantityHandle second) <br> |
|  void | [**PairInterpretationContextQuantity\_destroy**](#function-pairinterpretationcontextquantity_destroy) (PairInterpretationContextQuantityHandle handle) <br> |
|  bool | [**PairInterpretationContextQuantity\_equal**](#function-pairinterpretationcontextquantity_equal) (PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other) <br> |
|  InterpretationContextHandle | [**PairInterpretationContextQuantity\_first**](#function-pairinterpretationcontextquantity_first) (PairInterpretationContextQuantityHandle handle) <br> |
|  PairInterpretationContextQuantityHandle | [**PairInterpretationContextQuantity\_from\_json\_string**](#function-pairinterpretationcontextquantity_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairInterpretationContextQuantity\_not\_equal**](#function-pairinterpretationcontextquantity_not_equal) (PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other) <br> |
|  QuantityHandle | [**PairInterpretationContextQuantity\_second**](#function-pairinterpretationcontextquantity_second) (PairInterpretationContextQuantityHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairInterpretationContextQuantity\_to\_json\_string**](#function-pairinterpretationcontextquantity_to_json_string) (PairInterpretationContextQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef PairInterpretationContextQuantityHandle 

```C++
typedef void* PairInterpretationContextQuantityHandle;
```




<hr>
## Public Functions Documentation




### function PairInterpretationContextQuantity\_copy 

```C++
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_copy (
    PairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function PairInterpretationContextQuantity\_create 

```C++
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create (
    InterpretationContextHandle first,
    QuantityHandle second
) 
```




<hr>



### function PairInterpretationContextQuantity\_destroy 

```C++
void PairInterpretationContextQuantity_destroy (
    PairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function PairInterpretationContextQuantity\_equal 

```C++
bool PairInterpretationContextQuantity_equal (
    PairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle other
) 
```




<hr>



### function PairInterpretationContextQuantity\_first 

```C++
InterpretationContextHandle PairInterpretationContextQuantity_first (
    PairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function PairInterpretationContextQuantity\_from\_json\_string 

```C++
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairInterpretationContextQuantity\_not\_equal 

```C++
bool PairInterpretationContextQuantity_not_equal (
    PairInterpretationContextQuantityHandle handle,
    PairInterpretationContextQuantityHandle other
) 
```




<hr>



### function PairInterpretationContextQuantity\_second 

```C++
QuantityHandle PairInterpretationContextQuantity_second (
    PairInterpretationContextQuantityHandle handle
) 
```




<hr>



### function PairInterpretationContextQuantity\_to\_json\_string 

```C++
StringHandle PairInterpretationContextQuantity_to_json_string (
    PairInterpretationContextQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairInterpretationContextQuantity_c_api.h`

