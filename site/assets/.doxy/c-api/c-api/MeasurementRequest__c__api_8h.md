

# File MeasurementRequest\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**MeasurementRequest\_c\_api.h**](MeasurementRequest__c__api_8h.md)

[Go to the source code of this file](MeasurementRequest__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListWaveform_c_api.h"`
* `#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"`
* `#include "falcon_core/math/domains/LabelledDomain_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MeasurementRequestHandle**](#typedef-measurementrequesthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MeasurementRequestHandle | [**MeasurementRequest\_copy**](#function-measurementrequest_copy) (MeasurementRequestHandle handle) <br> |
|  MeasurementRequestHandle | [**MeasurementRequest\_create**](#function-measurementrequest_create) (StringHandle message, StringHandle measurement\_name, ListWaveformHandle waveforms, PortsHandle getters, MapInstrumentPortPortTransformHandle meter\_transforms, LabelledDomainHandle time\_domain) <br> |
|  void | [**MeasurementRequest\_destroy**](#function-measurementrequest_destroy) (MeasurementRequestHandle handle) <br> |
|  bool | [**MeasurementRequest\_equal**](#function-measurementrequest_equal) (MeasurementRequestHandle handle, MeasurementRequestHandle other) <br> |
|  MeasurementRequestHandle | [**MeasurementRequest\_from\_json\_string**](#function-measurementrequest_from_json_string) (StringHandle json) <br> |
|  PortsHandle | [**MeasurementRequest\_getters**](#function-measurementrequest_getters) (MeasurementRequestHandle handle) <br> |
|  StringHandle | [**MeasurementRequest\_measurement\_name**](#function-measurementrequest_measurement_name) (MeasurementRequestHandle handle) <br> |
|  StringHandle | [**MeasurementRequest\_message**](#function-measurementrequest_message) (MeasurementRequestHandle handle) <br> |
|  MapInstrumentPortPortTransformHandle | [**MeasurementRequest\_meter\_transforms**](#function-measurementrequest_meter_transforms) (MeasurementRequestHandle handle) <br> |
|  bool | [**MeasurementRequest\_not\_equal**](#function-measurementrequest_not_equal) (MeasurementRequestHandle handle, MeasurementRequestHandle other) <br> |
|  LabelledDomainHandle | [**MeasurementRequest\_time\_domain**](#function-measurementrequest_time_domain) (MeasurementRequestHandle handle) <br> |
|  StringHandle | [**MeasurementRequest\_to\_json\_string**](#function-measurementrequest_to_json_string) (MeasurementRequestHandle handle) <br> |
|  ListWaveformHandle | [**MeasurementRequest\_waveforms**](#function-measurementrequest_waveforms) (MeasurementRequestHandle handle) <br> |




























## Public Types Documentation




### typedef MeasurementRequestHandle 

```C++
typedef void* MeasurementRequestHandle;
```




<hr>
## Public Functions Documentation




### function MeasurementRequest\_copy 

```C++
MeasurementRequestHandle MeasurementRequest_copy (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_create 

```C++
MeasurementRequestHandle MeasurementRequest_create (
    StringHandle message,
    StringHandle measurement_name,
    ListWaveformHandle waveforms,
    PortsHandle getters,
    MapInstrumentPortPortTransformHandle meter_transforms,
    LabelledDomainHandle time_domain
) 
```




<hr>



### function MeasurementRequest\_destroy 

```C++
void MeasurementRequest_destroy (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_equal 

```C++
bool MeasurementRequest_equal (
    MeasurementRequestHandle handle,
    MeasurementRequestHandle other
) 
```




<hr>



### function MeasurementRequest\_from\_json\_string 

```C++
MeasurementRequestHandle MeasurementRequest_from_json_string (
    StringHandle json
) 
```




<hr>



### function MeasurementRequest\_getters 

```C++
PortsHandle MeasurementRequest_getters (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_measurement\_name 

```C++
StringHandle MeasurementRequest_measurement_name (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_message 

```C++
StringHandle MeasurementRequest_message (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_meter\_transforms 

```C++
MapInstrumentPortPortTransformHandle MeasurementRequest_meter_transforms (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_not\_equal 

```C++
bool MeasurementRequest_not_equal (
    MeasurementRequestHandle handle,
    MeasurementRequestHandle other
) 
```




<hr>



### function MeasurementRequest\_time\_domain 

```C++
LabelledDomainHandle MeasurementRequest_time_domain (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_to\_json\_string 

```C++
StringHandle MeasurementRequest_to_json_string (
    MeasurementRequestHandle handle
) 
```




<hr>



### function MeasurementRequest\_waveforms 

```C++
ListWaveformHandle MeasurementRequest_waveforms (
    MeasurementRequestHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/messages/MeasurementRequest_c_api.h`

