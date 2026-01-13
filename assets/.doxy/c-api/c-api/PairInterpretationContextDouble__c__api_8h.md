

# File PairInterpretationContextDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextDouble\_c\_api.h**](PairInterpretationContextDouble__c__api_8h.md)

[Go to the source code of this file](PairInterpretationContextDouble__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairInterpretationContextDoubleHandle**](#typedef-pairinterpretationcontextdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextDoubleHandle | [**PairInterpretationContextDouble\_copy**](#function-pairinterpretationcontextdouble_copy) (PairInterpretationContextDoubleHandle handle) <br> |
|  PairInterpretationContextDoubleHandle | [**PairInterpretationContextDouble\_create**](#function-pairinterpretationcontextdouble_create) (InterpretationContextHandle first, double second) <br> |
|  void | [**PairInterpretationContextDouble\_destroy**](#function-pairinterpretationcontextdouble_destroy) (PairInterpretationContextDoubleHandle handle) <br> |
|  bool | [**PairInterpretationContextDouble\_equal**](#function-pairinterpretationcontextdouble_equal) (PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other) <br> |
|  InterpretationContextHandle | [**PairInterpretationContextDouble\_first**](#function-pairinterpretationcontextdouble_first) (PairInterpretationContextDoubleHandle handle) <br> |
|  PairInterpretationContextDoubleHandle | [**PairInterpretationContextDouble\_from\_json\_string**](#function-pairinterpretationcontextdouble_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairInterpretationContextDouble\_not\_equal**](#function-pairinterpretationcontextdouble_not_equal) (PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other) <br> |
|  double | [**PairInterpretationContextDouble\_second**](#function-pairinterpretationcontextdouble_second) (PairInterpretationContextDoubleHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairInterpretationContextDouble\_to\_json\_string**](#function-pairinterpretationcontextdouble_to_json_string) (PairInterpretationContextDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef PairInterpretationContextDoubleHandle 

```C++
typedef void* PairInterpretationContextDoubleHandle;
```




<hr>
## Public Functions Documentation




### function PairInterpretationContextDouble\_copy 

```C++
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_copy (
    PairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function PairInterpretationContextDouble\_create 

```C++
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create (
    InterpretationContextHandle first,
    double second
) 
```




<hr>



### function PairInterpretationContextDouble\_destroy 

```C++
void PairInterpretationContextDouble_destroy (
    PairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function PairInterpretationContextDouble\_equal 

```C++
bool PairInterpretationContextDouble_equal (
    PairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle other
) 
```




<hr>



### function PairInterpretationContextDouble\_first 

```C++
InterpretationContextHandle PairInterpretationContextDouble_first (
    PairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function PairInterpretationContextDouble\_from\_json\_string 

```C++
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairInterpretationContextDouble\_not\_equal 

```C++
bool PairInterpretationContextDouble_not_equal (
    PairInterpretationContextDoubleHandle handle,
    PairInterpretationContextDoubleHandle other
) 
```




<hr>



### function PairInterpretationContextDouble\_second 

```C++
double PairInterpretationContextDouble_second (
    PairInterpretationContextDoubleHandle handle
) 
```




<hr>



### function PairInterpretationContextDouble\_to\_json\_string 

```C++
StringHandle PairInterpretationContextDouble_to_json_string (
    PairInterpretationContextDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairInterpretationContextDouble_c_api.h`

