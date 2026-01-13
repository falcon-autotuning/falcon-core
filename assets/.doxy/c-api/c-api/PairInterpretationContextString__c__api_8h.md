

# File PairInterpretationContextString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextString\_c\_api.h**](PairInterpretationContextString__c__api_8h.md)

[Go to the source code of this file](PairInterpretationContextString__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairInterpretationContextStringHandle**](#typedef-pairinterpretationcontextstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInterpretationContextStringHandle | [**PairInterpretationContextString\_copy**](#function-pairinterpretationcontextstring_copy) (PairInterpretationContextStringHandle handle) <br> |
|  PairInterpretationContextStringHandle | [**PairInterpretationContextString\_create**](#function-pairinterpretationcontextstring_create) (InterpretationContextHandle first, [**StringHandle**](structstring.md) second) <br> |
|  void | [**PairInterpretationContextString\_destroy**](#function-pairinterpretationcontextstring_destroy) (PairInterpretationContextStringHandle handle) <br> |
|  bool | [**PairInterpretationContextString\_equal**](#function-pairinterpretationcontextstring_equal) (PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other) <br> |
|  InterpretationContextHandle | [**PairInterpretationContextString\_first**](#function-pairinterpretationcontextstring_first) (PairInterpretationContextStringHandle handle) <br> |
|  PairInterpretationContextStringHandle | [**PairInterpretationContextString\_from\_json\_string**](#function-pairinterpretationcontextstring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairInterpretationContextString\_not\_equal**](#function-pairinterpretationcontextstring_not_equal) (PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**PairInterpretationContextString\_second**](#function-pairinterpretationcontextstring_second) (PairInterpretationContextStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairInterpretationContextString\_to\_json\_string**](#function-pairinterpretationcontextstring_to_json_string) (PairInterpretationContextStringHandle handle) <br> |




























## Public Types Documentation




### typedef PairInterpretationContextStringHandle 

```C++
typedef void* PairInterpretationContextStringHandle;
```




<hr>
## Public Functions Documentation




### function PairInterpretationContextString\_copy 

```C++
PairInterpretationContextStringHandle PairInterpretationContextString_copy (
    PairInterpretationContextStringHandle handle
) 
```




<hr>



### function PairInterpretationContextString\_create 

```C++
PairInterpretationContextStringHandle PairInterpretationContextString_create (
    InterpretationContextHandle first,
    StringHandle second
) 
```




<hr>



### function PairInterpretationContextString\_destroy 

```C++
void PairInterpretationContextString_destroy (
    PairInterpretationContextStringHandle handle
) 
```




<hr>



### function PairInterpretationContextString\_equal 

```C++
bool PairInterpretationContextString_equal (
    PairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle other
) 
```




<hr>



### function PairInterpretationContextString\_first 

```C++
InterpretationContextHandle PairInterpretationContextString_first (
    PairInterpretationContextStringHandle handle
) 
```




<hr>



### function PairInterpretationContextString\_from\_json\_string 

```C++
PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairInterpretationContextString\_not\_equal 

```C++
bool PairInterpretationContextString_not_equal (
    PairInterpretationContextStringHandle handle,
    PairInterpretationContextStringHandle other
) 
```




<hr>



### function PairInterpretationContextString\_second 

```C++
StringHandle PairInterpretationContextString_second (
    PairInterpretationContextStringHandle handle
) 
```




<hr>



### function PairInterpretationContextString\_to\_json\_string 

```C++
StringHandle PairInterpretationContextString_to_json_string (
    PairInterpretationContextStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairInterpretationContextString_c_api.h`

