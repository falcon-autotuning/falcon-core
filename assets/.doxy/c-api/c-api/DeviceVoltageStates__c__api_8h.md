

# File DeviceVoltageStates\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**voltage\_states**](dir_743932565a10589fd03e44dab2fde07e.md) **>** [**DeviceVoltageStates\_c\_api.h**](DeviceVoltageStates__c__api_8h.md)

[Go to the source code of this file](DeviceVoltageStates__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListDeviceVoltageState_c_api.h"`
* `#include "falcon_core/math/Point_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DeviceVoltageStatesHandle**](#typedef-devicevoltagestateshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**DeviceVoltageStates\_add\_state**](#function-devicevoltagestates_add_state) (DeviceVoltageStatesHandle handle, DeviceVoltageStateHandle state) <br>_Add a voltage state to the collection._  |
|  DeviceVoltageStateHandle | [**DeviceVoltageStates\_at**](#function-devicevoltagestates_at) (DeviceVoltageStatesHandle handle, size\_t idx) <br> |
|  void | [**DeviceVoltageStates\_clear**](#function-devicevoltagestates_clear) (DeviceVoltageStatesHandle handle) <br> |
|  bool | [**DeviceVoltageStates\_contains**](#function-devicevoltagestates_contains) (DeviceVoltageStatesHandle handle, DeviceVoltageStateHandle value) <br> |
|  DeviceVoltageStatesHandle | [**DeviceVoltageStates\_create**](#function-devicevoltagestates_create) (ListDeviceVoltageStateHandle items) <br> |
|  DeviceVoltageStatesHandle | [**DeviceVoltageStates\_create\_empty**](#function-devicevoltagestates_create_empty) () <br> |
|  void | [**DeviceVoltageStates\_destroy**](#function-devicevoltagestates_destroy) (DeviceVoltageStatesHandle handle) <br> |
|  bool | [**DeviceVoltageStates\_empty**](#function-devicevoltagestates_empty) (DeviceVoltageStatesHandle handle) <br> |
|  bool | [**DeviceVoltageStates\_equal**](#function-devicevoltagestates_equal) (DeviceVoltageStatesHandle a, DeviceVoltageStatesHandle b) <br> |
|  void | [**DeviceVoltageStates\_erase\_at**](#function-devicevoltagestates_erase_at) (DeviceVoltageStatesHandle handle, size\_t idx) <br> |
|  DeviceVoltageStatesHandle | [**DeviceVoltageStates\_find\_state**](#function-devicevoltagestates_find_state) (DeviceVoltageStatesHandle handle, ConnectionHandle connection) <br>_Find a voltage state by its connection._  |
|  DeviceVoltageStatesHandle | [**DeviceVoltageStates\_from\_json\_string**](#function-devicevoltagestates_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**DeviceVoltageStates\_index**](#function-devicevoltagestates_index) (DeviceVoltageStatesHandle handle, DeviceVoltageStateHandle value) <br> |
|  DeviceVoltageStatesHandle | [**DeviceVoltageStates\_intersection**](#function-devicevoltagestates_intersection) (DeviceVoltageStatesHandle handle, DeviceVoltageStatesHandle other) <br> |
|  ListDeviceVoltageStateHandle | [**DeviceVoltageStates\_items**](#function-devicevoltagestates_items) (DeviceVoltageStatesHandle handle) <br> |
|  bool | [**DeviceVoltageStates\_not\_equal**](#function-devicevoltagestates_not_equal) (DeviceVoltageStatesHandle a, DeviceVoltageStatesHandle b) <br> |
|  void | [**DeviceVoltageStates\_push\_back**](#function-devicevoltagestates_push_back) (DeviceVoltageStatesHandle handle, DeviceVoltageStateHandle value) <br> |
|  size\_t | [**DeviceVoltageStates\_size**](#function-devicevoltagestates_size) (DeviceVoltageStatesHandle handle) <br> |
|  ListDeviceVoltageStateHandle | [**DeviceVoltageStates\_states**](#function-devicevoltagestates_states) (DeviceVoltageStatesHandle handle) <br>_Returns the list of voltage states._  |
|  [**StringHandle**](structstring.md) | [**DeviceVoltageStates\_to\_json\_string**](#function-devicevoltagestates_to_json_string) (DeviceVoltageStatesHandle handle) <br> |
|  PointHandle | [**DeviceVoltageStates\_to\_point**](#function-devicevoltagestates_to_point) (DeviceVoltageStatesHandle handle) <br>_Conversion to the Point datatype._  |




























## Public Types Documentation




### typedef DeviceVoltageStatesHandle 

```C++
typedef void* DeviceVoltageStatesHandle;
```




<hr>
## Public Functions Documentation




### function DeviceVoltageStates\_add\_state 

_Add a voltage state to the collection._ 
```C++
void DeviceVoltageStates_add_state (
    DeviceVoltageStatesHandle handle,
    DeviceVoltageStateHandle state
) 
```





**Parameters:**


* `state` The voltage state to add. 




        

<hr>



### function DeviceVoltageStates\_at 

```C++
DeviceVoltageStateHandle DeviceVoltageStates_at (
    DeviceVoltageStatesHandle handle,
    size_t idx
) 
```




<hr>



### function DeviceVoltageStates\_clear 

```C++
void DeviceVoltageStates_clear (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_contains 

```C++
bool DeviceVoltageStates_contains (
    DeviceVoltageStatesHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function DeviceVoltageStates\_create 

```C++
DeviceVoltageStatesHandle DeviceVoltageStates_create (
    ListDeviceVoltageStateHandle items
) 
```




<hr>



### function DeviceVoltageStates\_create\_empty 

```C++
DeviceVoltageStatesHandle DeviceVoltageStates_create_empty () 
```




<hr>



### function DeviceVoltageStates\_destroy 

```C++
void DeviceVoltageStates_destroy (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_empty 

```C++
bool DeviceVoltageStates_empty (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_equal 

```C++
bool DeviceVoltageStates_equal (
    DeviceVoltageStatesHandle a,
    DeviceVoltageStatesHandle b
) 
```




<hr>



### function DeviceVoltageStates\_erase\_at 

```C++
void DeviceVoltageStates_erase_at (
    DeviceVoltageStatesHandle handle,
    size_t idx
) 
```




<hr>



### function DeviceVoltageStates\_find\_state 

_Find a voltage state by its connection._ 
```C++
DeviceVoltageStatesHandle DeviceVoltageStates_find_state (
    DeviceVoltageStatesHandle handle,
    ConnectionHandle connection
) 
```





**Parameters:**


* `connection` The connection to find. 



**Returns:**

the voltage state if found. 





        

<hr>



### function DeviceVoltageStates\_from\_json\_string 

```C++
DeviceVoltageStatesHandle DeviceVoltageStates_from_json_string (
    StringHandle json
) 
```




<hr>



### function DeviceVoltageStates\_index 

```C++
size_t DeviceVoltageStates_index (
    DeviceVoltageStatesHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function DeviceVoltageStates\_intersection 

```C++
DeviceVoltageStatesHandle DeviceVoltageStates_intersection (
    DeviceVoltageStatesHandle handle,
    DeviceVoltageStatesHandle other
) 
```




<hr>



### function DeviceVoltageStates\_items 

```C++
ListDeviceVoltageStateHandle DeviceVoltageStates_items (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_not\_equal 

```C++
bool DeviceVoltageStates_not_equal (
    DeviceVoltageStatesHandle a,
    DeviceVoltageStatesHandle b
) 
```




<hr>



### function DeviceVoltageStates\_push\_back 

```C++
void DeviceVoltageStates_push_back (
    DeviceVoltageStatesHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function DeviceVoltageStates\_size 

```C++
size_t DeviceVoltageStates_size (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_states 

_Returns the list of voltage states._ 
```C++
ListDeviceVoltageStateHandle DeviceVoltageStates_states (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_to\_json\_string 

```C++
StringHandle DeviceVoltageStates_to_json_string (
    DeviceVoltageStatesHandle handle
) 
```




<hr>



### function DeviceVoltageStates\_to\_point 

_Conversion to the Point datatype._ 
```C++
PointHandle DeviceVoltageStates_to_point (
    DeviceVoltageStatesHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h`

