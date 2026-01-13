

# File VoltageConstraints\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**VoltageConstraints\_c\_api.h**](VoltageConstraints__c__api_8h.md)

[Go to the source code of this file](VoltageConstraints__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/PairDoubleDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/config/core/Adjacency_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**VoltageConstraintsHandle**](#typedef-voltageconstraintshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  AdjacencyHandle | [**VoltageConstraints\_adjacency**](#function-voltageconstraints_adjacency) (VoltageConstraintsHandle handle) <br>_The adjacency matrix used to understand the device layout._  |
|  VoltageConstraintsHandle | [**VoltageConstraints\_copy**](#function-voltageconstraints_copy) (VoltageConstraintsHandle handle) <br> |
|  VoltageConstraintsHandle | [**VoltageConstraints\_create**](#function-voltageconstraints_create) (AdjacencyHandle adjacency, double max\_safe\_diff, PairDoubleDoubleHandle bounds) <br> |
|  void | [**VoltageConstraints\_destroy**](#function-voltageconstraints_destroy) (VoltageConstraintsHandle handle) <br> |
|  bool | [**VoltageConstraints\_equal**](#function-voltageconstraints_equal) (VoltageConstraintsHandle handle, VoltageConstraintsHandle other) <br> |
|  VoltageConstraintsHandle | [**VoltageConstraints\_from\_json\_string**](#function-voltageconstraints_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  FArrayDoubleHandle | [**VoltageConstraints\_limits**](#function-voltageconstraints_limits) (VoltageConstraintsHandle handle) <br>_The y axis vector safe voltage limits for each constraint._  |
|  FArrayDoubleHandle | [**VoltageConstraints\_matrix**](#function-voltageconstraints_matrix) (VoltageConstraintsHandle handle) <br>_The constraint matrix._  |
|  bool | [**VoltageConstraints\_not\_equal**](#function-voltageconstraints_not_equal) (VoltageConstraintsHandle handle, VoltageConstraintsHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**VoltageConstraints\_to\_json\_string**](#function-voltageconstraints_to_json_string) (VoltageConstraintsHandle handle) <br> |




























## Public Types Documentation




### typedef VoltageConstraintsHandle 

```C++
typedef void* VoltageConstraintsHandle;
```




<hr>
## Public Functions Documentation




### function VoltageConstraints\_adjacency 

_The adjacency matrix used to understand the device layout._ 
```C++
AdjacencyHandle VoltageConstraints_adjacency (
    VoltageConstraintsHandle handle
) 
```




<hr>



### function VoltageConstraints\_copy 

```C++
VoltageConstraintsHandle VoltageConstraints_copy (
    VoltageConstraintsHandle handle
) 
```




<hr>



### function VoltageConstraints\_create 

```C++
VoltageConstraintsHandle VoltageConstraints_create (
    AdjacencyHandle adjacency,
    double max_safe_diff,
    PairDoubleDoubleHandle bounds
) 
```




<hr>



### function VoltageConstraints\_destroy 

```C++
void VoltageConstraints_destroy (
    VoltageConstraintsHandle handle
) 
```




<hr>



### function VoltageConstraints\_equal 

```C++
bool VoltageConstraints_equal (
    VoltageConstraintsHandle handle,
    VoltageConstraintsHandle other
) 
```




<hr>



### function VoltageConstraints\_from\_json\_string 

```C++
VoltageConstraintsHandle VoltageConstraints_from_json_string (
    StringHandle json
) 
```




<hr>



### function VoltageConstraints\_limits 

_The y axis vector safe voltage limits for each constraint._ 
```C++
FArrayDoubleHandle VoltageConstraints_limits (
    VoltageConstraintsHandle handle
) 
```




<hr>



### function VoltageConstraints\_matrix 

_The constraint matrix._ 
```C++
FArrayDoubleHandle VoltageConstraints_matrix (
    VoltageConstraintsHandle handle
) 
```




<hr>



### function VoltageConstraints\_not\_equal 

```C++
bool VoltageConstraints_not_equal (
    VoltageConstraintsHandle handle,
    VoltageConstraintsHandle other
) 
```




<hr>



### function VoltageConstraints\_to\_json\_string 

```C++
StringHandle VoltageConstraints_to_json_string (
    VoltageConstraintsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/core/VoltageConstraints_c_api.h`

