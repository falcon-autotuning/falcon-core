

# File HDF5Data\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**HDF5Data\_c\_api.h**](HDF5Data__c__api_8h.md)

[Go to the source code of this file](HDF5Data__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include <stdint.h>`
* `#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"`
* `#include "falcon_core/generic/MapStringString_c_api.h"`
* `#include "falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/AxesControlArray_c_api.h"`
* `#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"`
* `#include "falcon_core/math/AxesInt_c_api.h"`
* `#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**HDF5DataHandle**](#typedef-hdf5datahandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  HDF5DataHandle | [**HDF5Data\_copy**](#function-hdf5data_copy) (HDF5DataHandle handle) <br> |
|  HDF5DataHandle | [**HDF5Data\_create**](#function-hdf5data_create) (AxesIntHandle shape, AxesControlArrayHandle unit\_domain, AxesCoupledLabelledDomainHandle domain\_labels, LabelledArraysLabelledMeasuredArrayHandle ranges, MapStringStringHandle metadata, [**StringHandle**](structstring.md) measurement\_title, int unique\_id, int timestamp) <br> |
|  HDF5DataHandle | [**HDF5Data\_create\_from\_communications**](#function-hdf5data_create_from_communications) (MeasurementRequestHandle request, MeasurementResponseHandle response, DeviceVoltageStatesHandle device\_voltage\_states, int8\_t session\_id, [**StringHandle**](structstring.md) measurement\_title, int unique\_id, int timestamp) <br> |
|  HDF5DataHandle | [**HDF5Data\_create\_from\_file**](#function-hdf5data_create_from_file) ([**StringHandle**](structstring.md) path) <br> |
|  void | [**HDF5Data\_destroy**](#function-hdf5data_destroy) (HDF5DataHandle handle) <br> |
|  AxesCoupledLabelledDomainHandle | [**HDF5Data\_domain\_labels**](#function-hdf5data_domain_labels) (HDF5DataHandle handle) <br> |
|  bool | [**HDF5Data\_equal**](#function-hdf5data_equal) (HDF5DataHandle handle, HDF5DataHandle other) <br> |
|  HDF5DataHandle | [**HDF5Data\_from\_json\_string**](#function-hdf5data_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**HDF5Data\_measurement\_title**](#function-hdf5data_measurement_title) (HDF5DataHandle handle) <br> |
|  MapStringStringHandle | [**HDF5Data\_metadata**](#function-hdf5data_metadata) (HDF5DataHandle handle) <br> |
|  bool | [**HDF5Data\_not\_equal**](#function-hdf5data_not_equal) (HDF5DataHandle handle, HDF5DataHandle other) <br> |
|  LabelledArraysLabelledMeasuredArrayHandle | [**HDF5Data\_ranges**](#function-hdf5data_ranges) (HDF5DataHandle handle) <br> |
|  AxesIntHandle | [**HDF5Data\_shape**](#function-hdf5data_shape) (HDF5DataHandle handle) <br> |
|  int | [**HDF5Data\_timestamp**](#function-hdf5data_timestamp) (HDF5DataHandle handle) <br> |
|  PairMeasurementResponseMeasurementRequestHandle | [**HDF5Data\_to\_communications**](#function-hdf5data_to_communications) (HDF5DataHandle handle) <br>_Convert from an HDF5Data object to a MeasurementResponse and a Metadata._  |
|  void | [**HDF5Data\_to\_file**](#function-hdf5data_to_file) (HDF5DataHandle handle, [**StringHandle**](structstring.md) path) <br>_Convert from an HDF5Data object to a file._  |
|  [**StringHandle**](structstring.md) | [**HDF5Data\_to\_json\_string**](#function-hdf5data_to_json_string) (HDF5DataHandle handle) <br> |
|  int | [**HDF5Data\_unique\_id**](#function-hdf5data_unique_id) (HDF5DataHandle handle) <br> |
|  AxesControlArrayHandle | [**HDF5Data\_unit\_domain**](#function-hdf5data_unit_domain) (HDF5DataHandle handle) <br> |




























## Public Types Documentation




### typedef HDF5DataHandle 

```C++
typedef void* HDF5DataHandle;
```




<hr>
## Public Functions Documentation




### function HDF5Data\_copy 

```C++
HDF5DataHandle HDF5Data_copy (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_create 

```C++
HDF5DataHandle HDF5Data_create (
    AxesIntHandle shape,
    AxesControlArrayHandle unit_domain,
    AxesCoupledLabelledDomainHandle domain_labels,
    LabelledArraysLabelledMeasuredArrayHandle ranges,
    MapStringStringHandle metadata,
    StringHandle measurement_title,
    int unique_id,
    int timestamp
) 
```




<hr>



### function HDF5Data\_create\_from\_communications 

```C++
HDF5DataHandle HDF5Data_create_from_communications (
    MeasurementRequestHandle request,
    MeasurementResponseHandle response,
    DeviceVoltageStatesHandle device_voltage_states,
    int8_t session_id,
    StringHandle measurement_title,
    int unique_id,
    int timestamp
) 
```




<hr>



### function HDF5Data\_create\_from\_file 

```C++
HDF5DataHandle HDF5Data_create_from_file (
    StringHandle path
) 
```




<hr>



### function HDF5Data\_destroy 

```C++
void HDF5Data_destroy (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_domain\_labels 

```C++
AxesCoupledLabelledDomainHandle HDF5Data_domain_labels (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_equal 

```C++
bool HDF5Data_equal (
    HDF5DataHandle handle,
    HDF5DataHandle other
) 
```




<hr>



### function HDF5Data\_from\_json\_string 

```C++
HDF5DataHandle HDF5Data_from_json_string (
    StringHandle json
) 
```




<hr>



### function HDF5Data\_measurement\_title 

```C++
StringHandle HDF5Data_measurement_title (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_metadata 

```C++
MapStringStringHandle HDF5Data_metadata (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_not\_equal 

```C++
bool HDF5Data_not_equal (
    HDF5DataHandle handle,
    HDF5DataHandle other
) 
```




<hr>



### function HDF5Data\_ranges 

```C++
LabelledArraysLabelledMeasuredArrayHandle HDF5Data_ranges (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_shape 

```C++
AxesIntHandle HDF5Data_shape (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_timestamp 

```C++
int HDF5Data_timestamp (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_to\_communications 

_Convert from an HDF5Data object to a MeasurementResponse and a Metadata._ 
```C++
PairMeasurementResponseMeasurementRequestHandle HDF5Data_to_communications (
    HDF5DataHandle handle
) 
```





**Returns:**

A pair of MeasurementResponse and MeasurementRequest. 





        

<hr>



### function HDF5Data\_to\_file 

_Convert from an HDF5Data object to a file._ 
```C++
void HDF5Data_to_file (
    HDF5DataHandle handle,
    StringHandle path
) 
```





**Parameters:**


* `path` The path to write the HDF5 file at. 




        

<hr>



### function HDF5Data\_to\_json\_string 

```C++
StringHandle HDF5Data_to_json_string (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_unique\_id 

```C++
int HDF5Data_unique_id (
    HDF5DataHandle handle
) 
```




<hr>



### function HDF5Data\_unit\_domain 

```C++
AxesControlArrayHandle HDF5Data_unit_domain (
    HDF5DataHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/HDF5Data_c_api.h`

