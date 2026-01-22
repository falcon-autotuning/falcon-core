

# File DiscreteSpace\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**discrete\_spaces**](dir_4135ae89d8b25a1ab40962ee1784aac3.md) **>** [**DiscreteSpace\_c\_api.h**](DiscreteSpace__c__api_8h.md)

[Go to the source code of this file](DiscreteSpace__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"`
* `#include "falcon_core/math/AxesInstrumentPort_c_api.h"`
* `#include "falcon_core/math/AxesLabelledControlArray_c_api.h"`
* `#include "falcon_core/math/AxesMapStringBool_c_api.h"`
* `#include "falcon_core/math/UnitSpace_c_api.h"`
* `#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DiscreteSpaceHandle**](#typedef-discretespacehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  AxesCoupledLabelledDomainHandle | [**DiscreteSpace\_axes**](#function-discretespace_axes) (DiscreteSpaceHandle handle) <br>_Return the stored axes._  |
|  DiscreteSpaceHandle | [**DiscreteSpace\_copy**](#function-discretespace_copy) (DiscreteSpaceHandle handle) <br> |
|  DiscreteSpaceHandle | [**DiscreteSpace\_create**](#function-discretespace_create) (UnitSpaceHandle space, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing) <br> |
|  DiscreteSpaceHandle | [**DiscreteSpace\_create\_cartesian\_discrete\_space**](#function-discretespace_create_cartesian_discrete_space) (AxesIntHandle divisions, AxesCoupledLabelledDomainHandle axes, AxesMapStringBoolHandle increasing, DomainHandle domain) <br> |
|  DiscreteSpaceHandle | [**DiscreteSpace\_create\_cartesian\_discrete\_space\_1D**](#function-discretespace_create_cartesian_discrete_space_1d) (int division, CoupledLabelledDomainHandle shared\_domain, MapStringBoolHandle increasing, DomainHandle domain) <br> |
|  void | [**DiscreteSpace\_destroy**](#function-discretespace_destroy) (DiscreteSpaceHandle handle) <br> |
|  bool | [**DiscreteSpace\_equal**](#function-discretespace_equal) (DiscreteSpaceHandle handle, DiscreteSpaceHandle other) <br> |
|  DiscreteSpaceHandle | [**DiscreteSpace\_from\_json\_string**](#function-discretespace_from_json_string) (StringHandle json) <br> |
|  int | [**DiscreteSpace\_get\_axis**](#function-discretespace_get_axis) (DiscreteSpaceHandle handle, InstrumentPortHandle knob) <br>_Return the index of the axis containing the given knob._  |
|  DomainHandle | [**DiscreteSpace\_get\_domain**](#function-discretespace_get_domain) (DiscreteSpaceHandle handle, InstrumentPortHandle knob) <br>_Return the domain of the given knob._  |
|  AxesLabelledControlArrayHandle | [**DiscreteSpace\_get\_projection**](#function-discretespace_get_projection) (DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection) <br>_Return the projection of the unit space onto the given axes._  |
|  AxesMapStringBoolHandle | [**DiscreteSpace\_increasing**](#function-discretespace_increasing) (DiscreteSpaceHandle handle) <br>_Return the increasing properties._  |
|  PortsHandle | [**DiscreteSpace\_knobs**](#function-discretespace_knobs) (DiscreteSpaceHandle handle) <br>_Return the knobs._  |
|  bool | [**DiscreteSpace\_not\_equal**](#function-discretespace_not_equal) (DiscreteSpaceHandle handle, DiscreteSpaceHandle other) <br> |
|  UnitSpaceHandle | [**DiscreteSpace\_space**](#function-discretespace_space) (DiscreteSpaceHandle handle) <br>_Return the stored UnitSpace._  |
|  StringHandle | [**DiscreteSpace\_to\_json\_string**](#function-discretespace_to_json_string) (DiscreteSpaceHandle handle) <br> |
|  void | [**DiscreteSpace\_validate\_knob\_uniqueness**](#function-discretespace_validate_knob_uniqueness) (DiscreteSpaceHandle handle) <br>_Validate that the knobs are unique._  |
|  void | [**DiscreteSpace\_validate\_unit\_space\_dimensionality\_matches\_knobs**](#function-discretespace_validate_unit_space_dimensionality_matches_knobs) (DiscreteSpaceHandle handle) <br>_Validate that the unit space dimensionality matches the number of knobs._  |




























## Public Types Documentation




### typedef DiscreteSpaceHandle 

```C++
typedef void* DiscreteSpaceHandle;
```




<hr>
## Public Functions Documentation




### function DiscreteSpace\_axes 

_Return the stored axes._ 
```C++
AxesCoupledLabelledDomainHandle DiscreteSpace_axes (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_copy 

```C++
DiscreteSpaceHandle DiscreteSpace_copy (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_create 

```C++
DiscreteSpaceHandle DiscreteSpace_create (
    UnitSpaceHandle space,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing
) 
```




<hr>



### function DiscreteSpace\_create\_cartesian\_discrete\_space 

```C++
DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space (
    AxesIntHandle divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle increasing,
    DomainHandle domain
) 
```




<hr>



### function DiscreteSpace\_create\_cartesian\_discrete\_space\_1D 

```C++
DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space_1D (
    int division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle increasing,
    DomainHandle domain
) 
```




<hr>



### function DiscreteSpace\_destroy 

```C++
void DiscreteSpace_destroy (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_equal 

```C++
bool DiscreteSpace_equal (
    DiscreteSpaceHandle handle,
    DiscreteSpaceHandle other
) 
```




<hr>



### function DiscreteSpace\_from\_json\_string 

```C++
DiscreteSpaceHandle DiscreteSpace_from_json_string (
    StringHandle json
) 
```




<hr>



### function DiscreteSpace\_get\_axis 

_Return the index of the axis containing the given knob._ 
```C++
int DiscreteSpace_get_axis (
    DiscreteSpaceHandle handle,
    InstrumentPortHandle knob
) 
```





**Parameters:**


* `knob` The knob to search for. 



**Returns:**

The index of the axis containing the knob. 




**Exception:**


* `std::runtime_error` if the knob is not found. 




        

<hr>



### function DiscreteSpace\_get\_domain 

_Return the domain of the given knob._ 
```C++
DomainHandle DiscreteSpace_get_domain (
    DiscreteSpaceHandle handle,
    InstrumentPortHandle knob
) 
```





**Parameters:**


* `knob` The knob to search for. 



**Returns:**

The domain of the knob. 





        

<hr>



### function DiscreteSpace\_get\_projection 

_Return the projection of the unit space onto the given axes._ 
```C++
AxesLabelledControlArrayHandle DiscreteSpace_get_projection (
    DiscreteSpaceHandle handle,
    AxesInstrumentPortHandle projection
) 
```





**Parameters:**


* `projection` The axes to project onto. 



**Returns:**

The projection of th espace onto the given axes. 





        

<hr>



### function DiscreteSpace\_increasing 

_Return the increasing properties._ 
```C++
AxesMapStringBoolHandle DiscreteSpace_increasing (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_knobs 

_Return the knobs._ 
```C++
PortsHandle DiscreteSpace_knobs (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_not\_equal 

```C++
bool DiscreteSpace_not_equal (
    DiscreteSpaceHandle handle,
    DiscreteSpaceHandle other
) 
```




<hr>



### function DiscreteSpace\_space 

_Return the stored UnitSpace._ 
```C++
UnitSpaceHandle DiscreteSpace_space (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_to\_json\_string 

```C++
StringHandle DiscreteSpace_to_json_string (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_validate\_knob\_uniqueness 

_Validate that the knobs are unique._ 
```C++
void DiscreteSpace_validate_knob_uniqueness (
    DiscreteSpaceHandle handle
) 
```




<hr>



### function DiscreteSpace\_validate\_unit\_space\_dimensionality\_matches\_knobs 

_Validate that the unit space dimensionality matches the number of knobs._ 
```C++
void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs (
    DiscreteSpaceHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h`

