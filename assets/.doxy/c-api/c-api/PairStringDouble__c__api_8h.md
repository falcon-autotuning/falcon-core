

# File PairStringDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringDouble\_c\_api.h**](PairStringDouble__c__api_8h.md)

[Go to the source code of this file](PairStringDouble__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairStringDoubleHandle**](#typedef-pairstringdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringDoubleHandle | [**PairStringDouble\_copy**](#function-pairstringdouble_copy) (PairStringDoubleHandle handle) <br> |
|  PairStringDoubleHandle | [**PairStringDouble\_create**](#function-pairstringdouble_create) ([**StringHandle**](structstring.md) first, double second) <br> |
|  void | [**PairStringDouble\_destroy**](#function-pairstringdouble_destroy) (PairStringDoubleHandle handle) <br> |
|  bool | [**PairStringDouble\_equal**](#function-pairstringdouble_equal) (PairStringDoubleHandle handle, PairStringDoubleHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**PairStringDouble\_first**](#function-pairstringdouble_first) (PairStringDoubleHandle handle) <br> |
|  PairStringDoubleHandle | [**PairStringDouble\_from\_json\_string**](#function-pairstringdouble_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairStringDouble\_not\_equal**](#function-pairstringdouble_not_equal) (PairStringDoubleHandle handle, PairStringDoubleHandle other) <br> |
|  double | [**PairStringDouble\_second**](#function-pairstringdouble_second) (PairStringDoubleHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairStringDouble\_to\_json\_string**](#function-pairstringdouble_to_json_string) (PairStringDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef PairStringDoubleHandle 

```C++
typedef void* PairStringDoubleHandle;
```




<hr>
## Public Functions Documentation




### function PairStringDouble\_copy 

```C++
PairStringDoubleHandle PairStringDouble_copy (
    PairStringDoubleHandle handle
) 
```




<hr>



### function PairStringDouble\_create 

```C++
PairStringDoubleHandle PairStringDouble_create (
    StringHandle first,
    double second
) 
```




<hr>



### function PairStringDouble\_destroy 

```C++
void PairStringDouble_destroy (
    PairStringDoubleHandle handle
) 
```




<hr>



### function PairStringDouble\_equal 

```C++
bool PairStringDouble_equal (
    PairStringDoubleHandle handle,
    PairStringDoubleHandle other
) 
```




<hr>



### function PairStringDouble\_first 

```C++
StringHandle PairStringDouble_first (
    PairStringDoubleHandle handle
) 
```




<hr>



### function PairStringDouble\_from\_json\_string 

```C++
PairStringDoubleHandle PairStringDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairStringDouble\_not\_equal 

```C++
bool PairStringDouble_not_equal (
    PairStringDoubleHandle handle,
    PairStringDoubleHandle other
) 
```




<hr>



### function PairStringDouble\_second 

```C++
double PairStringDouble_second (
    PairStringDoubleHandle handle
) 
```




<hr>



### function PairStringDouble\_to\_json\_string 

```C++
StringHandle PairStringDouble_to_json_string (
    PairStringDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairStringDouble_c_api.h`

