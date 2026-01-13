

# File PortTransform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**port\_transforms**](dir_d9b7dfc8594864a30460f4237d4753dd.md) **>** [**PortTransform\_c\_api.h**](PortTransform__c__api_8h.md)

[Go to the source code of this file](PortTransform__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/MapStringDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/math/AnalyticFunction_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PortTransformHandle**](#typedef-porttransformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PortTransformHandle | [**PortTransform\_copy**](#function-porttransform_copy) (PortTransformHandle handle) <br> |
|  PortTransformHandle | [**PortTransform\_create**](#function-porttransform_create) (InstrumentPortHandle port, AnalyticFunctionHandle transform) <br> |
|  PortTransformHandle | [**PortTransform\_create\_constant\_transform**](#function-porttransform_create_constant_transform) (InstrumentPortHandle port, double value) <br> |
|  PortTransformHandle | [**PortTransform\_create\_identity\_transform**](#function-porttransform_create_identity_transform) (InstrumentPortHandle port) <br> |
|  void | [**PortTransform\_destroy**](#function-porttransform_destroy) (PortTransformHandle handle) <br> |
|  bool | [**PortTransform\_equal**](#function-porttransform_equal) (PortTransformHandle handle, PortTransformHandle other) <br> |
|  double | [**PortTransform\_evaluate**](#function-porttransform_evaluate) (PortTransformHandle handle, MapStringDoubleHandle args, double time) <br> |
|  FArrayDoubleHandle | [**PortTransform\_evaluate\_arraywise**](#function-porttransform_evaluate_arraywise) (PortTransformHandle handle, MapStringDoubleHandle args, double deltaT, double maxTime) <br> |
|  PortTransformHandle | [**PortTransform\_from\_json\_string**](#function-porttransform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  ListStringHandle | [**PortTransform\_labels**](#function-porttransform_labels) (PortTransformHandle handle) <br> |
|  bool | [**PortTransform\_not\_equal**](#function-porttransform_not_equal) (PortTransformHandle handle, PortTransformHandle other) <br> |
|  InstrumentPortHandle | [**PortTransform\_port**](#function-porttransform_port) (PortTransformHandle handle) <br>_Returns the port associated with the transform._  |
|  [**StringHandle**](structstring.md) | [**PortTransform\_to\_json\_string**](#function-porttransform_to_json_string) (PortTransformHandle handle) <br> |




























## Public Types Documentation




### typedef PortTransformHandle 

```C++
typedef void* PortTransformHandle;
```




<hr>
## Public Functions Documentation




### function PortTransform\_copy 

```C++
PortTransformHandle PortTransform_copy (
    PortTransformHandle handle
) 
```




<hr>



### function PortTransform\_create 

```C++
PortTransformHandle PortTransform_create (
    InstrumentPortHandle port,
    AnalyticFunctionHandle transform
) 
```




<hr>



### function PortTransform\_create\_constant\_transform 

```C++
PortTransformHandle PortTransform_create_constant_transform (
    InstrumentPortHandle port,
    double value
) 
```




<hr>



### function PortTransform\_create\_identity\_transform 

```C++
PortTransformHandle PortTransform_create_identity_transform (
    InstrumentPortHandle port
) 
```




<hr>



### function PortTransform\_destroy 

```C++
void PortTransform_destroy (
    PortTransformHandle handle
) 
```




<hr>



### function PortTransform\_equal 

```C++
bool PortTransform_equal (
    PortTransformHandle handle,
    PortTransformHandle other
) 
```




<hr>



### function PortTransform\_evaluate 

```C++
double PortTransform_evaluate (
    PortTransformHandle handle,
    MapStringDoubleHandle args,
    double time
) 
```




<hr>



### function PortTransform\_evaluate\_arraywise 

```C++
FArrayDoubleHandle PortTransform_evaluate_arraywise (
    PortTransformHandle handle,
    MapStringDoubleHandle args,
    double deltaT,
    double maxTime
) 
```




<hr>



### function PortTransform\_from\_json\_string 

```C++
PortTransformHandle PortTransform_from_json_string (
    StringHandle json
) 
```




<hr>



### function PortTransform\_labels 

```C++
ListStringHandle PortTransform_labels (
    PortTransformHandle handle
) 
```




<hr>



### function PortTransform\_not\_equal 

```C++
bool PortTransform_not_equal (
    PortTransformHandle handle,
    PortTransformHandle other
) 
```




<hr>



### function PortTransform\_port 

_Returns the port associated with the transform._ 
```C++
InstrumentPortHandle PortTransform_port (
    PortTransformHandle handle
) 
```




<hr>



### function PortTransform\_to\_json\_string 

```C++
StringHandle PortTransform_to_json_string (
    PortTransformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h`

