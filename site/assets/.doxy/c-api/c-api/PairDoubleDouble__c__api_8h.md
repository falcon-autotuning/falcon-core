

# File PairDoubleDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairDoubleDouble\_c\_api.h**](PairDoubleDouble__c__api_8h.md)

[Go to the source code of this file](PairDoubleDouble__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairDoubleDoubleHandle**](#typedef-pairdoubledoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairDoubleDoubleHandle | [**PairDoubleDouble\_copy**](#function-pairdoubledouble_copy) (PairDoubleDoubleHandle handle) <br> |
|  PairDoubleDoubleHandle | [**PairDoubleDouble\_create**](#function-pairdoubledouble_create) (double first, double second) <br> |
|  void | [**PairDoubleDouble\_destroy**](#function-pairdoubledouble_destroy) (PairDoubleDoubleHandle handle) <br> |
|  bool | [**PairDoubleDouble\_equal**](#function-pairdoubledouble_equal) (PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other) <br> |
|  double | [**PairDoubleDouble\_first**](#function-pairdoubledouble_first) (PairDoubleDoubleHandle handle) <br> |
|  PairDoubleDoubleHandle | [**PairDoubleDouble\_from\_json\_string**](#function-pairdoubledouble_from_json_string) (StringHandle json) <br> |
|  bool | [**PairDoubleDouble\_not\_equal**](#function-pairdoubledouble_not_equal) (PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other) <br> |
|  double | [**PairDoubleDouble\_second**](#function-pairdoubledouble_second) (PairDoubleDoubleHandle handle) <br> |
|  StringHandle | [**PairDoubleDouble\_to\_json\_string**](#function-pairdoubledouble_to_json_string) (PairDoubleDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef PairDoubleDoubleHandle 

```C++
typedef void* PairDoubleDoubleHandle;
```




<hr>
## Public Functions Documentation




### function PairDoubleDouble\_copy 

```C++
PairDoubleDoubleHandle PairDoubleDouble_copy (
    PairDoubleDoubleHandle handle
) 
```




<hr>



### function PairDoubleDouble\_create 

```C++
PairDoubleDoubleHandle PairDoubleDouble_create (
    double first,
    double second
) 
```




<hr>



### function PairDoubleDouble\_destroy 

```C++
void PairDoubleDouble_destroy (
    PairDoubleDoubleHandle handle
) 
```




<hr>



### function PairDoubleDouble\_equal 

```C++
bool PairDoubleDouble_equal (
    PairDoubleDoubleHandle handle,
    PairDoubleDoubleHandle other
) 
```




<hr>



### function PairDoubleDouble\_first 

```C++
double PairDoubleDouble_first (
    PairDoubleDoubleHandle handle
) 
```




<hr>



### function PairDoubleDouble\_from\_json\_string 

```C++
PairDoubleDoubleHandle PairDoubleDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairDoubleDouble\_not\_equal 

```C++
bool PairDoubleDouble_not_equal (
    PairDoubleDoubleHandle handle,
    PairDoubleDoubleHandle other
) 
```




<hr>



### function PairDoubleDouble\_second 

```C++
double PairDoubleDouble_second (
    PairDoubleDoubleHandle handle
) 
```




<hr>



### function PairDoubleDouble\_to\_json\_string 

```C++
StringHandle PairDoubleDouble_to_json_string (
    PairDoubleDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairDoubleDouble_c_api.h`

