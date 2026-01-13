

# File PairFloatFloat\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairFloatFloat\_c\_api.h**](PairFloatFloat__c__api_8h.md)

[Go to the source code of this file](PairFloatFloat__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairFloatFloatHandle**](#typedef-pairfloatfloathandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairFloatFloatHandle | [**PairFloatFloat\_copy**](#function-pairfloatfloat_copy) (PairFloatFloatHandle handle) <br> |
|  PairFloatFloatHandle | [**PairFloatFloat\_create**](#function-pairfloatfloat_create) (float first, float second) <br> |
|  void | [**PairFloatFloat\_destroy**](#function-pairfloatfloat_destroy) (PairFloatFloatHandle handle) <br> |
|  bool | [**PairFloatFloat\_equal**](#function-pairfloatfloat_equal) (PairFloatFloatHandle handle, PairFloatFloatHandle other) <br> |
|  float | [**PairFloatFloat\_first**](#function-pairfloatfloat_first) (PairFloatFloatHandle handle) <br> |
|  PairFloatFloatHandle | [**PairFloatFloat\_from\_json\_string**](#function-pairfloatfloat_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairFloatFloat\_not\_equal**](#function-pairfloatfloat_not_equal) (PairFloatFloatHandle handle, PairFloatFloatHandle other) <br> |
|  float | [**PairFloatFloat\_second**](#function-pairfloatfloat_second) (PairFloatFloatHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairFloatFloat\_to\_json\_string**](#function-pairfloatfloat_to_json_string) (PairFloatFloatHandle handle) <br> |




























## Public Types Documentation




### typedef PairFloatFloatHandle 

```C++
typedef void* PairFloatFloatHandle;
```




<hr>
## Public Functions Documentation




### function PairFloatFloat\_copy 

```C++
PairFloatFloatHandle PairFloatFloat_copy (
    PairFloatFloatHandle handle
) 
```




<hr>



### function PairFloatFloat\_create 

```C++
PairFloatFloatHandle PairFloatFloat_create (
    float first,
    float second
) 
```




<hr>



### function PairFloatFloat\_destroy 

```C++
void PairFloatFloat_destroy (
    PairFloatFloatHandle handle
) 
```




<hr>



### function PairFloatFloat\_equal 

```C++
bool PairFloatFloat_equal (
    PairFloatFloatHandle handle,
    PairFloatFloatHandle other
) 
```




<hr>



### function PairFloatFloat\_first 

```C++
float PairFloatFloat_first (
    PairFloatFloatHandle handle
) 
```




<hr>



### function PairFloatFloat\_from\_json\_string 

```C++
PairFloatFloatHandle PairFloatFloat_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairFloatFloat\_not\_equal 

```C++
bool PairFloatFloat_not_equal (
    PairFloatFloatHandle handle,
    PairFloatFloatHandle other
) 
```




<hr>



### function PairFloatFloat\_second 

```C++
float PairFloatFloat_second (
    PairFloatFloatHandle handle
) 
```




<hr>



### function PairFloatFloat\_to\_json\_string 

```C++
StringHandle PairFloatFloat_to_json_string (
    PairFloatFloatHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairFloatFloat_c_api.h`

