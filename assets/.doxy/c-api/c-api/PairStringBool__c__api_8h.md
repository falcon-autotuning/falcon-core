

# File PairStringBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringBool\_c\_api.h**](PairStringBool__c__api_8h.md)

[Go to the source code of this file](PairStringBool__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairStringBoolHandle**](#typedef-pairstringboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringBoolHandle | [**PairStringBool\_copy**](#function-pairstringbool_copy) (PairStringBoolHandle handle) <br> |
|  PairStringBoolHandle | [**PairStringBool\_create**](#function-pairstringbool_create) ([**StringHandle**](structstring.md) first, bool second) <br> |
|  void | [**PairStringBool\_destroy**](#function-pairstringbool_destroy) (PairStringBoolHandle handle) <br> |
|  bool | [**PairStringBool\_equal**](#function-pairstringbool_equal) (PairStringBoolHandle handle, PairStringBoolHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**PairStringBool\_first**](#function-pairstringbool_first) (PairStringBoolHandle handle) <br> |
|  PairStringBoolHandle | [**PairStringBool\_from\_json\_string**](#function-pairstringbool_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairStringBool\_not\_equal**](#function-pairstringbool_not_equal) (PairStringBoolHandle handle, PairStringBoolHandle other) <br> |
|  bool | [**PairStringBool\_second**](#function-pairstringbool_second) (PairStringBoolHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairStringBool\_to\_json\_string**](#function-pairstringbool_to_json_string) (PairStringBoolHandle handle) <br> |




























## Public Types Documentation




### typedef PairStringBoolHandle 

```C++
typedef void* PairStringBoolHandle;
```




<hr>
## Public Functions Documentation




### function PairStringBool\_copy 

```C++
PairStringBoolHandle PairStringBool_copy (
    PairStringBoolHandle handle
) 
```




<hr>



### function PairStringBool\_create 

```C++
PairStringBoolHandle PairStringBool_create (
    StringHandle first,
    bool second
) 
```




<hr>



### function PairStringBool\_destroy 

```C++
void PairStringBool_destroy (
    PairStringBoolHandle handle
) 
```




<hr>



### function PairStringBool\_equal 

```C++
bool PairStringBool_equal (
    PairStringBoolHandle handle,
    PairStringBoolHandle other
) 
```




<hr>



### function PairStringBool\_first 

```C++
StringHandle PairStringBool_first (
    PairStringBoolHandle handle
) 
```




<hr>



### function PairStringBool\_from\_json\_string 

```C++
PairStringBoolHandle PairStringBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairStringBool\_not\_equal 

```C++
bool PairStringBool_not_equal (
    PairStringBoolHandle handle,
    PairStringBoolHandle other
) 
```




<hr>



### function PairStringBool\_second 

```C++
bool PairStringBool_second (
    PairStringBoolHandle handle
) 
```




<hr>



### function PairStringBool\_to\_json\_string 

```C++
StringHandle PairStringBool_to_json_string (
    PairStringBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairStringBool_c_api.h`

