

# File PairGnameGroup\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairGnameGroup\_c\_api.h**](PairGnameGroup__c__api_8h.md)

[Go to the source code of this file](PairGnameGroup__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"`
* `#include "falcon_core/physics/config/core/Group_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairGnameGroupHandle**](#typedef-pairgnamegrouphandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairGnameGroupHandle | [**PairGnameGroup\_copy**](#function-pairgnamegroup_copy) (PairGnameGroupHandle handle) <br> |
|  PairGnameGroupHandle | [**PairGnameGroup\_create**](#function-pairgnamegroup_create) (GnameHandle first, GroupHandle second) <br> |
|  void | [**PairGnameGroup\_destroy**](#function-pairgnamegroup_destroy) (PairGnameGroupHandle handle) <br> |
|  bool | [**PairGnameGroup\_equal**](#function-pairgnamegroup_equal) (PairGnameGroupHandle handle, PairGnameGroupHandle other) <br> |
|  GnameHandle | [**PairGnameGroup\_first**](#function-pairgnamegroup_first) (PairGnameGroupHandle handle) <br> |
|  PairGnameGroupHandle | [**PairGnameGroup\_from\_json\_string**](#function-pairgnamegroup_from_json_string) (StringHandle json) <br> |
|  bool | [**PairGnameGroup\_not\_equal**](#function-pairgnamegroup_not_equal) (PairGnameGroupHandle handle, PairGnameGroupHandle other) <br> |
|  GroupHandle | [**PairGnameGroup\_second**](#function-pairgnamegroup_second) (PairGnameGroupHandle handle) <br> |
|  StringHandle | [**PairGnameGroup\_to\_json\_string**](#function-pairgnamegroup_to_json_string) (PairGnameGroupHandle handle) <br> |




























## Public Types Documentation




### typedef PairGnameGroupHandle 

```C++
typedef void* PairGnameGroupHandle;
```




<hr>
## Public Functions Documentation




### function PairGnameGroup\_copy 

```C++
PairGnameGroupHandle PairGnameGroup_copy (
    PairGnameGroupHandle handle
) 
```




<hr>



### function PairGnameGroup\_create 

```C++
PairGnameGroupHandle PairGnameGroup_create (
    GnameHandle first,
    GroupHandle second
) 
```




<hr>



### function PairGnameGroup\_destroy 

```C++
void PairGnameGroup_destroy (
    PairGnameGroupHandle handle
) 
```




<hr>



### function PairGnameGroup\_equal 

```C++
bool PairGnameGroup_equal (
    PairGnameGroupHandle handle,
    PairGnameGroupHandle other
) 
```




<hr>



### function PairGnameGroup\_first 

```C++
GnameHandle PairGnameGroup_first (
    PairGnameGroupHandle handle
) 
```




<hr>



### function PairGnameGroup\_from\_json\_string 

```C++
PairGnameGroupHandle PairGnameGroup_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairGnameGroup\_not\_equal 

```C++
bool PairGnameGroup_not_equal (
    PairGnameGroupHandle handle,
    PairGnameGroupHandle other
) 
```




<hr>



### function PairGnameGroup\_second 

```C++
GroupHandle PairGnameGroup_second (
    PairGnameGroupHandle handle
) 
```




<hr>



### function PairGnameGroup\_to\_json\_string 

```C++
StringHandle PairGnameGroup_to_json_string (
    PairGnameGroupHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairGnameGroup_c_api.h`

