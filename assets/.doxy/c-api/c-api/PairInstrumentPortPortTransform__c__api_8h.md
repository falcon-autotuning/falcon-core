

# File PairInstrumentPortPortTransform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInstrumentPortPortTransform\_c\_api.h**](PairInstrumentPortPortTransform__c__api_8h.md)

[Go to the source code of this file](PairInstrumentPortPortTransform__c__api_8h_source.md)



* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairInstrumentPortPortTransformHandle**](#typedef-pairinstrumentportporttransformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairInstrumentPortPortTransformHandle | [**PairInstrumentPortPortTransform\_copy**](#function-pairinstrumentportporttransform_copy) (PairInstrumentPortPortTransformHandle handle) <br> |
|  PairInstrumentPortPortTransformHandle | [**PairInstrumentPortPortTransform\_create**](#function-pairinstrumentportporttransform_create) (InstrumentPortHandle first, PortTransformHandle second) <br> |
|  void | [**PairInstrumentPortPortTransform\_destroy**](#function-pairinstrumentportporttransform_destroy) (PairInstrumentPortPortTransformHandle handle) <br> |
|  bool | [**PairInstrumentPortPortTransform\_equal**](#function-pairinstrumentportporttransform_equal) (PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other) <br> |
|  InstrumentPortHandle | [**PairInstrumentPortPortTransform\_first**](#function-pairinstrumentportporttransform_first) (PairInstrumentPortPortTransformHandle handle) <br> |
|  PairInstrumentPortPortTransformHandle | [**PairInstrumentPortPortTransform\_from\_json\_string**](#function-pairinstrumentportporttransform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairInstrumentPortPortTransform\_not\_equal**](#function-pairinstrumentportporttransform_not_equal) (PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other) <br> |
|  PortTransformHandle | [**PairInstrumentPortPortTransform\_second**](#function-pairinstrumentportporttransform_second) (PairInstrumentPortPortTransformHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairInstrumentPortPortTransform\_to\_json\_string**](#function-pairinstrumentportporttransform_to_json_string) (PairInstrumentPortPortTransformHandle handle) <br> |




























## Public Types Documentation




### typedef PairInstrumentPortPortTransformHandle 

```C++
typedef void* PairInstrumentPortPortTransformHandle;
```




<hr>
## Public Functions Documentation




### function PairInstrumentPortPortTransform\_copy 

```C++
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_copy (
    PairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function PairInstrumentPortPortTransform\_create 

```C++
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create (
    InstrumentPortHandle first,
    PortTransformHandle second
) 
```




<hr>



### function PairInstrumentPortPortTransform\_destroy 

```C++
void PairInstrumentPortPortTransform_destroy (
    PairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function PairInstrumentPortPortTransform\_equal 

```C++
bool PairInstrumentPortPortTransform_equal (
    PairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle other
) 
```




<hr>



### function PairInstrumentPortPortTransform\_first 

```C++
InstrumentPortHandle PairInstrumentPortPortTransform_first (
    PairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function PairInstrumentPortPortTransform\_from\_json\_string 

```C++
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairInstrumentPortPortTransform\_not\_equal 

```C++
bool PairInstrumentPortPortTransform_not_equal (
    PairInstrumentPortPortTransformHandle handle,
    PairInstrumentPortPortTransformHandle other
) 
```




<hr>



### function PairInstrumentPortPortTransform\_second 

```C++
PortTransformHandle PairInstrumentPortPortTransform_second (
    PairInstrumentPortPortTransformHandle handle
) 
```




<hr>



### function PairInstrumentPortPortTransform\_to\_json\_string 

```C++
StringHandle PairInstrumentPortPortTransform_to_json_string (
    PairInstrumentPortPortTransformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairInstrumentPortPortTransform_c_api.h`

