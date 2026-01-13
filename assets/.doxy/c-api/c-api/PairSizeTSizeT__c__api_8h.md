

# File PairSizeTSizeT\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairSizeTSizeT\_c\_api.h**](PairSizeTSizeT__c__api_8h.md)

[Go to the source code of this file](PairSizeTSizeT__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairSizeTSizeTHandle**](#typedef-pairsizetsizethandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairSizeTSizeTHandle | [**PairSizeTSizeT\_copy**](#function-pairsizetsizet_copy) (PairSizeTSizeTHandle handle) <br> |
|  PairSizeTSizeTHandle | [**PairSizeTSizeT\_create**](#function-pairsizetsizet_create) (size\_t first, size\_t second) <br> |
|  void | [**PairSizeTSizeT\_destroy**](#function-pairsizetsizet_destroy) (PairSizeTSizeTHandle handle) <br> |
|  bool | [**PairSizeTSizeT\_equal**](#function-pairsizetsizet_equal) (PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other) <br> |
|  size\_t | [**PairSizeTSizeT\_first**](#function-pairsizetsizet_first) (PairSizeTSizeTHandle handle) <br> |
|  PairSizeTSizeTHandle | [**PairSizeTSizeT\_from\_json\_string**](#function-pairsizetsizet_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairSizeTSizeT\_not\_equal**](#function-pairsizetsizet_not_equal) (PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other) <br> |
|  size\_t | [**PairSizeTSizeT\_second**](#function-pairsizetsizet_second) (PairSizeTSizeTHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairSizeTSizeT\_to\_json\_string**](#function-pairsizetsizet_to_json_string) (PairSizeTSizeTHandle handle) <br> |




























## Public Types Documentation




### typedef PairSizeTSizeTHandle 

```C++
typedef void* PairSizeTSizeTHandle;
```




<hr>
## Public Functions Documentation




### function PairSizeTSizeT\_copy 

```C++
PairSizeTSizeTHandle PairSizeTSizeT_copy (
    PairSizeTSizeTHandle handle
) 
```




<hr>



### function PairSizeTSizeT\_create 

```C++
PairSizeTSizeTHandle PairSizeTSizeT_create (
    size_t first,
    size_t second
) 
```




<hr>



### function PairSizeTSizeT\_destroy 

```C++
void PairSizeTSizeT_destroy (
    PairSizeTSizeTHandle handle
) 
```




<hr>



### function PairSizeTSizeT\_equal 

```C++
bool PairSizeTSizeT_equal (
    PairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle other
) 
```




<hr>



### function PairSizeTSizeT\_first 

```C++
size_t PairSizeTSizeT_first (
    PairSizeTSizeTHandle handle
) 
```




<hr>



### function PairSizeTSizeT\_from\_json\_string 

```C++
PairSizeTSizeTHandle PairSizeTSizeT_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairSizeTSizeT\_not\_equal 

```C++
bool PairSizeTSizeT_not_equal (
    PairSizeTSizeTHandle handle,
    PairSizeTSizeTHandle other
) 
```




<hr>



### function PairSizeTSizeT\_second 

```C++
size_t PairSizeTSizeT_second (
    PairSizeTSizeTHandle handle
) 
```




<hr>



### function PairSizeTSizeT\_to\_json\_string 

```C++
StringHandle PairSizeTSizeT_to_json_string (
    PairSizeTSizeTHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairSizeTSizeT_c_api.h`

