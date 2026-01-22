

# File PairStringString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringString\_c\_api.h**](PairStringString__c__api_8h.md)

[Go to the source code of this file](PairStringString__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairStringStringHandle**](#typedef-pairstringstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairStringStringHandle | [**PairStringString\_copy**](#function-pairstringstring_copy) (PairStringStringHandle handle) <br> |
|  PairStringStringHandle | [**PairStringString\_create**](#function-pairstringstring_create) (StringHandle first, StringHandle second) <br> |
|  void | [**PairStringString\_destroy**](#function-pairstringstring_destroy) (PairStringStringHandle handle) <br> |
|  bool | [**PairStringString\_equal**](#function-pairstringstring_equal) (PairStringStringHandle handle, PairStringStringHandle other) <br> |
|  StringHandle | [**PairStringString\_first**](#function-pairstringstring_first) (PairStringStringHandle handle) <br> |
|  PairStringStringHandle | [**PairStringString\_from\_json\_string**](#function-pairstringstring_from_json_string) (StringHandle json) <br> |
|  bool | [**PairStringString\_not\_equal**](#function-pairstringstring_not_equal) (PairStringStringHandle handle, PairStringStringHandle other) <br> |
|  StringHandle | [**PairStringString\_second**](#function-pairstringstring_second) (PairStringStringHandle handle) <br> |
|  StringHandle | [**PairStringString\_to\_json\_string**](#function-pairstringstring_to_json_string) (PairStringStringHandle handle) <br> |




























## Public Types Documentation




### typedef PairStringStringHandle 

```C++
typedef void* PairStringStringHandle;
```




<hr>
## Public Functions Documentation




### function PairStringString\_copy 

```C++
PairStringStringHandle PairStringString_copy (
    PairStringStringHandle handle
) 
```




<hr>



### function PairStringString\_create 

```C++
PairStringStringHandle PairStringString_create (
    StringHandle first,
    StringHandle second
) 
```




<hr>



### function PairStringString\_destroy 

```C++
void PairStringString_destroy (
    PairStringStringHandle handle
) 
```




<hr>



### function PairStringString\_equal 

```C++
bool PairStringString_equal (
    PairStringStringHandle handle,
    PairStringStringHandle other
) 
```




<hr>



### function PairStringString\_first 

```C++
StringHandle PairStringString_first (
    PairStringStringHandle handle
) 
```




<hr>



### function PairStringString\_from\_json\_string 

```C++
PairStringStringHandle PairStringString_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairStringString\_not\_equal 

```C++
bool PairStringString_not_equal (
    PairStringStringHandle handle,
    PairStringStringHandle other
) 
```




<hr>



### function PairStringString\_second 

```C++
StringHandle PairStringString_second (
    PairStringStringHandle handle
) 
```




<hr>



### function PairStringString\_to\_json\_string 

```C++
StringHandle PairStringString_to_json_string (
    PairStringStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairStringString_c_api.h`

