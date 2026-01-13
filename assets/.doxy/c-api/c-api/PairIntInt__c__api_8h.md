

# File PairIntInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairIntInt\_c\_api.h**](PairIntInt__c__api_8h.md)

[Go to the source code of this file](PairIntInt__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairIntIntHandle**](#typedef-pairintinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairIntIntHandle | [**PairIntInt\_copy**](#function-pairintint_copy) (PairIntIntHandle handle) <br> |
|  PairIntIntHandle | [**PairIntInt\_create**](#function-pairintint_create) (int first, int second) <br> |
|  void | [**PairIntInt\_destroy**](#function-pairintint_destroy) (PairIntIntHandle handle) <br> |
|  bool | [**PairIntInt\_equal**](#function-pairintint_equal) (PairIntIntHandle handle, PairIntIntHandle other) <br> |
|  int | [**PairIntInt\_first**](#function-pairintint_first) (PairIntIntHandle handle) <br> |
|  PairIntIntHandle | [**PairIntInt\_from\_json\_string**](#function-pairintint_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairIntInt\_not\_equal**](#function-pairintint_not_equal) (PairIntIntHandle handle, PairIntIntHandle other) <br> |
|  int | [**PairIntInt\_second**](#function-pairintint_second) (PairIntIntHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairIntInt\_to\_json\_string**](#function-pairintint_to_json_string) (PairIntIntHandle handle) <br> |




























## Public Types Documentation




### typedef PairIntIntHandle 

```C++
typedef void* PairIntIntHandle;
```




<hr>
## Public Functions Documentation




### function PairIntInt\_copy 

```C++
PairIntIntHandle PairIntInt_copy (
    PairIntIntHandle handle
) 
```




<hr>



### function PairIntInt\_create 

```C++
PairIntIntHandle PairIntInt_create (
    int first,
    int second
) 
```




<hr>



### function PairIntInt\_destroy 

```C++
void PairIntInt_destroy (
    PairIntIntHandle handle
) 
```




<hr>



### function PairIntInt\_equal 

```C++
bool PairIntInt_equal (
    PairIntIntHandle handle,
    PairIntIntHandle other
) 
```




<hr>



### function PairIntInt\_first 

```C++
int PairIntInt_first (
    PairIntIntHandle handle
) 
```




<hr>



### function PairIntInt\_from\_json\_string 

```C++
PairIntIntHandle PairIntInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairIntInt\_not\_equal 

```C++
bool PairIntInt_not_equal (
    PairIntIntHandle handle,
    PairIntIntHandle other
) 
```




<hr>



### function PairIntInt\_second 

```C++
int PairIntInt_second (
    PairIntIntHandle handle
) 
```




<hr>



### function PairIntInt\_to\_json\_string 

```C++
StringHandle PairIntInt_to_json_string (
    PairIntIntHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairIntInt_c_api.h`

