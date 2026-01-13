

# File VoltageStatesResponse\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**VoltageStatesResponse\_c\_api.h**](VoltageStatesResponse__c__api_8h.md)

[Go to the source code of this file](VoltageStatesResponse__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**VoltageStatesResponseHandle**](#typedef-voltagestatesresponsehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  VoltageStatesResponseHandle | [**VoltageStatesResponse\_copy**](#function-voltagestatesresponse_copy) (VoltageStatesResponseHandle handle) <br> |
|  VoltageStatesResponseHandle | [**VoltageStatesResponse\_create**](#function-voltagestatesresponse_create) ([**StringHandle**](structstring.md) message, DeviceVoltageStatesHandle states) <br> |
|  void | [**VoltageStatesResponse\_destroy**](#function-voltagestatesresponse_destroy) (VoltageStatesResponseHandle handle) <br> |
|  bool | [**VoltageStatesResponse\_equal**](#function-voltagestatesresponse_equal) (VoltageStatesResponseHandle handle, VoltageStatesResponseHandle other) <br> |
|  VoltageStatesResponseHandle | [**VoltageStatesResponse\_from\_json\_string**](#function-voltagestatesresponse_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**VoltageStatesResponse\_message**](#function-voltagestatesresponse_message) (VoltageStatesResponseHandle handle) <br> |
|  bool | [**VoltageStatesResponse\_not\_equal**](#function-voltagestatesresponse_not_equal) (VoltageStatesResponseHandle handle, VoltageStatesResponseHandle other) <br> |
|  DeviceVoltageStatesHandle | [**VoltageStatesResponse\_states**](#function-voltagestatesresponse_states) (VoltageStatesResponseHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**VoltageStatesResponse\_to\_json\_string**](#function-voltagestatesresponse_to_json_string) (VoltageStatesResponseHandle handle) <br> |




























## Public Types Documentation




### typedef VoltageStatesResponseHandle 

```C++
typedef void* VoltageStatesResponseHandle;
```




<hr>
## Public Functions Documentation




### function VoltageStatesResponse\_copy 

```C++
VoltageStatesResponseHandle VoltageStatesResponse_copy (
    VoltageStatesResponseHandle handle
) 
```




<hr>



### function VoltageStatesResponse\_create 

```C++
VoltageStatesResponseHandle VoltageStatesResponse_create (
    StringHandle message,
    DeviceVoltageStatesHandle states
) 
```




<hr>



### function VoltageStatesResponse\_destroy 

```C++
void VoltageStatesResponse_destroy (
    VoltageStatesResponseHandle handle
) 
```




<hr>



### function VoltageStatesResponse\_equal 

```C++
bool VoltageStatesResponse_equal (
    VoltageStatesResponseHandle handle,
    VoltageStatesResponseHandle other
) 
```




<hr>



### function VoltageStatesResponse\_from\_json\_string 

```C++
VoltageStatesResponseHandle VoltageStatesResponse_from_json_string (
    StringHandle json
) 
```




<hr>



### function VoltageStatesResponse\_message 

```C++
StringHandle VoltageStatesResponse_message (
    VoltageStatesResponseHandle handle
) 
```




<hr>



### function VoltageStatesResponse\_not\_equal 

```C++
bool VoltageStatesResponse_not_equal (
    VoltageStatesResponseHandle handle,
    VoltageStatesResponseHandle other
) 
```




<hr>



### function VoltageStatesResponse\_states 

```C++
DeviceVoltageStatesHandle VoltageStatesResponse_states (
    VoltageStatesResponseHandle handle
) 
```




<hr>



### function VoltageStatesResponse\_to\_json\_string 

```C++
StringHandle VoltageStatesResponse_to_json_string (
    VoltageStatesResponseHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/messages/VoltageStatesResponse_c_api.h`

