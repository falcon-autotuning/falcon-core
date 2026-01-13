

# File Waveform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**Waveform\_c\_api.h**](Waveform__c__api_8h.md)

[Go to the source code of this file](Waveform__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/ListPortTransform_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"`
* `#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"`
* `#include "falcon_core/math/AxesInt_c_api.h"`
* `#include "falcon_core/math/AxesMapStringBool_c_api.h"`
* `#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**WaveformHandle**](#typedef-waveformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PortTransformHandle | [**Waveform\_at**](#function-waveform_at) (WaveformHandle handle, size\_t idx) <br> |
|  void | [**Waveform\_clear**](#function-waveform_clear) (WaveformHandle handle) <br> |
|  bool | [**Waveform\_contains**](#function-waveform_contains) (WaveformHandle handle, PortTransformHandle value) <br> |
|  WaveformHandle | [**Waveform\_copy**](#function-waveform_copy) (WaveformHandle handle) <br> |
|  WaveformHandle | [**Waveform\_create**](#function-waveform_create) (DiscreteSpaceHandle space, ListPortTransformHandle transforms) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_identity\_waveform**](#function-waveform_create_cartesian_identity_waveform) (AxesIntHandle divisions, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing, DomainHandle domain) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_identity\_waveform\_1D**](#function-waveform_create_cartesian_identity_waveform_1d) (int division, CoupledLabelledDomainHandle shared\_domain, MapStringBoolHandle increasing, DomainHandle domain) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_identity\_waveform\_2D**](#function-waveform_create_cartesian_identity_waveform_2d) (AxesIntHandle divisions, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing, DomainHandle domain) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_waveform**](#function-waveform_create_cartesian_waveform) (AxesIntHandle divisions, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing, ListPortTransformHandle transforms, DomainHandle domain) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_waveform\_1D**](#function-waveform_create_cartesian_waveform_1d) (int division, CoupledLabelledDomainHandle shared\_domain, MapStringBoolHandle increasing, ListPortTransformHandle transforms, DomainHandle domain) <br> |
|  WaveformHandle | [**Waveform\_create\_cartesian\_waveform\_2D**](#function-waveform_create_cartesian_waveform_2d) (AxesIntHandle divisions, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing, ListPortTransformHandle transforms, DomainHandle domain) <br> |
|  void | [**Waveform\_destroy**](#function-waveform_destroy) (WaveformHandle handle) <br> |
|  bool | [**Waveform\_empty**](#function-waveform_empty) (WaveformHandle handle) <br> |
|  bool | [**Waveform\_equal**](#function-waveform_equal) (WaveformHandle handle, WaveformHandle other) <br> |
|  void | [**Waveform\_erase\_at**](#function-waveform_erase_at) (WaveformHandle handle, size\_t idx) <br> |
|  WaveformHandle | [**Waveform\_from\_json\_string**](#function-waveform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**Waveform\_index**](#function-waveform_index) (WaveformHandle handle, PortTransformHandle value) <br> |
|  WaveformHandle | [**Waveform\_intersection**](#function-waveform_intersection) (WaveformHandle handle, WaveformHandle other) <br> |
|  ListPortTransformHandle | [**Waveform\_items**](#function-waveform_items) (WaveformHandle handle) <br> |
|  bool | [**Waveform\_not\_equal**](#function-waveform_not_equal) (WaveformHandle handle, WaveformHandle other) <br> |
|  void | [**Waveform\_push\_back**](#function-waveform_push_back) (WaveformHandle handle, PortTransformHandle value) <br> |
|  size\_t | [**Waveform\_size**](#function-waveform_size) (WaveformHandle handle) <br> |
|  DiscreteSpaceHandle | [**Waveform\_space**](#function-waveform_space) (WaveformHandle handle) <br>_Get the measurement space._  |
|  [**StringHandle**](structstring.md) | [**Waveform\_to\_json\_string**](#function-waveform_to_json_string) (WaveformHandle handle) <br> |
|  ListPortTransformHandle | [**Waveform\_transforms**](#function-waveform_transforms) (WaveformHandle handle) <br> |




























## Public Types Documentation




### typedef WaveformHandle 

```C++
typedef void* WaveformHandle;
```




<hr>
## Public Functions Documentation




### function Waveform\_at 

```C++
PortTransformHandle Waveform_at (
    WaveformHandle handle,
    size_t idx
) 
```




<hr>



### function Waveform\_clear 

```C++
void Waveform_clear (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_contains 

```C++
bool Waveform_contains (
    WaveformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function Waveform\_copy 

```C++
WaveformHandle Waveform_copy (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_create 

```C++
WaveformHandle Waveform_create (
    DiscreteSpaceHandle space,
    ListPortTransformHandle transforms
) 
```




<hr>



### function Waveform\_create\_cartesian\_identity\_waveform 

```C++
WaveformHandle Waveform_create_cartesian_identity_waveform (
    AxesIntHandle divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_create\_cartesian\_identity\_waveform\_1D 

```C++
WaveformHandle Waveform_create_cartesian_identity_waveform_1D (
    int division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle increasing,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_create\_cartesian\_identity\_waveform\_2D 

```C++
WaveformHandle Waveform_create_cartesian_identity_waveform_2D (
    AxesIntHandle divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_create\_cartesian\_waveform 

```C++
WaveformHandle Waveform_create_cartesian_waveform (
    AxesIntHandle divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing,
    ListPortTransformHandle transforms,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_create\_cartesian\_waveform\_1D 

```C++
WaveformHandle Waveform_create_cartesian_waveform_1D (
    int division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle increasing,
    ListPortTransformHandle transforms,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_create\_cartesian\_waveform\_2D 

```C++
WaveformHandle Waveform_create_cartesian_waveform_2D (
    AxesIntHandle divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing,
    ListPortTransformHandle transforms,
    DomainHandle domain
) 
```




<hr>



### function Waveform\_destroy 

```C++
void Waveform_destroy (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_empty 

```C++
bool Waveform_empty (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_equal 

```C++
bool Waveform_equal (
    WaveformHandle handle,
    WaveformHandle other
) 
```




<hr>



### function Waveform\_erase\_at 

```C++
void Waveform_erase_at (
    WaveformHandle handle,
    size_t idx
) 
```




<hr>



### function Waveform\_from\_json\_string 

```C++
WaveformHandle Waveform_from_json_string (
    StringHandle json
) 
```




<hr>



### function Waveform\_index 

```C++
size_t Waveform_index (
    WaveformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function Waveform\_intersection 

```C++
WaveformHandle Waveform_intersection (
    WaveformHandle handle,
    WaveformHandle other
) 
```




<hr>



### function Waveform\_items 

```C++
ListPortTransformHandle Waveform_items (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_not\_equal 

```C++
bool Waveform_not_equal (
    WaveformHandle handle,
    WaveformHandle other
) 
```




<hr>



### function Waveform\_push\_back 

```C++
void Waveform_push_back (
    WaveformHandle handle,
    PortTransformHandle value
) 
```




<hr>



### function Waveform\_size 

```C++
size_t Waveform_size (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_space 

_Get the measurement space._ 
```C++
DiscreteSpaceHandle Waveform_space (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_to\_json\_string 

```C++
StringHandle Waveform_to_json_string (
    WaveformHandle handle
) 
```




<hr>



### function Waveform\_transforms 

```C++
ListPortTransformHandle Waveform_transforms (
    WaveformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/instrument_interfaces/Waveform_c_api.h`

