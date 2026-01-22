

# File PairIntFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairIntFloat\_c\_api.h**](PairIntFloat__c__api_8h.md)

[Go to the source code of this file](PairIntFloat__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairIntFloatHandle**](#typedef-pairintfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairIntFloatHandle | [**PairIntFloat\_copy**](#function-pairintfloat_copy) (PairIntFloatHandle handle) <br> |
|  PairIntFloatHandle | [**PairIntFloat\_create**](#function-pairintfloat_create) (int first, float second) <br> |
|  void | [**PairIntFloat\_destroy**](#function-pairintfloat_destroy) (PairIntFloatHandle handle) <br> |
|  bool | [**PairIntFloat\_equal**](#function-pairintfloat_equal) (PairIntFloatHandle handle, PairIntFloatHandle other) <br> |
|  int | [**PairIntFloat\_first**](#function-pairintfloat_first) (PairIntFloatHandle handle) <br> |
|  PairIntFloatHandle | [**PairIntFloat\_from\_json\_string**](#function-pairintfloat_from_json_string) (StringHandle json) <br> |
|  bool | [**PairIntFloat\_not\_equal**](#function-pairintfloat_not_equal) (PairIntFloatHandle handle, PairIntFloatHandle other) <br> |
|  float | [**PairIntFloat\_second**](#function-pairintfloat_second) (PairIntFloatHandle handle) <br> |
|  StringHandle | [**PairIntFloat\_to\_json\_string**](#function-pairintfloat_to_json_string) (PairIntFloatHandle handle) <br> |




























## Public Types Documentation




### typedef PairIntFloatHandle 

```C++
typedef void* PairIntFloatHandle;
```




<hr>
## Public Functions Documentation




### function PairIntFloat\_copy 

```C++
PairIntFloatHandle PairIntFloat_copy (
    PairIntFloatHandle handle
) 
```




<hr>



### function PairIntFloat\_create 

```C++
PairIntFloatHandle PairIntFloat_create (
    int first,
    float second
) 
```




<hr>



### function PairIntFloat\_destroy 

```C++
void PairIntFloat_destroy (
    PairIntFloatHandle handle
) 
```




<hr>



### function PairIntFloat\_equal 

```C++
bool PairIntFloat_equal (
    PairIntFloatHandle handle,
    PairIntFloatHandle other
) 
```




<hr>



### function PairIntFloat\_first 

```C++
int PairIntFloat_first (
    PairIntFloatHandle handle
) 
```




<hr>



### function PairIntFloat\_from\_json\_string 

```C++
PairIntFloatHandle PairIntFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairIntFloat\_not\_equal 

```C++
bool PairIntFloat_not_equal (
    PairIntFloatHandle handle,
    PairIntFloatHandle other
) 
```




<hr>



### function PairIntFloat\_second 

```C++
float PairIntFloat_second (
    PairIntFloatHandle handle
) 
```




<hr>



### function PairIntFloat\_to\_json\_string 

```C++
StringHandle PairIntFloat_to_json_string (
    PairIntFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairIntFloat_c_api.h`

