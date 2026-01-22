

# File DeviceVoltageState\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**voltage\_states**](dir_743932565a10589fd03e44dab2fde07e.md) **>** [**DeviceVoltageState\_c\_api.h**](DeviceVoltageState__c__api_8h.md)

[Go to the source code of this file](DeviceVoltageState__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DeviceVoltageStateHandle**](#typedef-devicevoltagestatehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_abs**](#function-devicevoltagestate_abs) (DeviceVoltageStateHandle handle) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_add\_equals\_quantity**](#function-devicevoltagestate_add_equals_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_add\_quantity**](#function-devicevoltagestate_add_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  ConnectionHandle | [**DeviceVoltageState\_connection**](#function-devicevoltagestate_connection) (DeviceVoltageStateHandle handle) <br> |
|  void | [**DeviceVoltageState\_convert\_to**](#function-devicevoltagestate_convert_to) (DeviceVoltageStateHandle handle, SymbolUnitHandle target\_unit) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_create**](#function-devicevoltagestate_create) (ConnectionHandle connection, double voltage, SymbolUnitHandle unit) <br> |
|  void | [**DeviceVoltageState\_destroy**](#function-devicevoltagestate_destroy) (DeviceVoltageStateHandle handle) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_double**](#function-devicevoltagestate_divide_double) (DeviceVoltageStateHandle handle, double other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_equals\_double**](#function-devicevoltagestate_divide_equals_double) (DeviceVoltageStateHandle handle, double other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_equals\_int**](#function-devicevoltagestate_divide_equals_int) (DeviceVoltageStateHandle handle, int other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_equals\_quantity**](#function-devicevoltagestate_divide_equals_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_int**](#function-devicevoltagestate_divide_int) (DeviceVoltageStateHandle handle, int other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_divide\_quantity**](#function-devicevoltagestate_divide_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  bool | [**DeviceVoltageState\_equal**](#function-devicevoltagestate_equal) (DeviceVoltageStateHandle a, DeviceVoltageStateHandle b) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_from\_json\_string**](#function-devicevoltagestate_from_json_string) (StringHandle json) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_double**](#function-devicevoltagestate_multiply_double) (DeviceVoltageStateHandle handle, double other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_equals\_double**](#function-devicevoltagestate_multiply_equals_double) (DeviceVoltageStateHandle handle, double other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_equals\_int**](#function-devicevoltagestate_multiply_equals_int) (DeviceVoltageStateHandle handle, int other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_equals\_quantity**](#function-devicevoltagestate_multiply_equals_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_int**](#function-devicevoltagestate_multiply_int) (DeviceVoltageStateHandle handle, int other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_multiply\_quantity**](#function-devicevoltagestate_multiply_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_negate**](#function-devicevoltagestate_negate) (DeviceVoltageStateHandle handle) <br> |
|  bool | [**DeviceVoltageState\_not\_equal**](#function-devicevoltagestate_not_equal) (DeviceVoltageStateHandle a, DeviceVoltageStateHandle b) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_power**](#function-devicevoltagestate_power) (DeviceVoltageStateHandle handle, int other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_subtract\_equals\_quantity**](#function-devicevoltagestate_subtract_equals_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  DeviceVoltageStateHandle | [**DeviceVoltageState\_subtract\_quantity**](#function-devicevoltagestate_subtract_quantity) (DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other) <br> |
|  StringHandle | [**DeviceVoltageState\_to\_json\_string**](#function-devicevoltagestate_to_json_string) (DeviceVoltageStateHandle handle) <br> |
|  SymbolUnitHandle | [**DeviceVoltageState\_unit**](#function-devicevoltagestate_unit) (DeviceVoltageStateHandle handle) <br> |
|  double | [**DeviceVoltageState\_value**](#function-devicevoltagestate_value) (DeviceVoltageStateHandle handle) <br> |
|  double | [**DeviceVoltageState\_voltage**](#function-devicevoltagestate_voltage) (DeviceVoltageStateHandle handle) <br> |




























## Public Types Documentation




### typedef DeviceVoltageStateHandle 

```C++
typedef void* DeviceVoltageStateHandle;
```




<hr>
## Public Functions Documentation




### function DeviceVoltageState\_abs 

```C++
DeviceVoltageStateHandle DeviceVoltageState_abs (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_add\_equals\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_add_equals_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_add\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_add_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_connection 

```C++
ConnectionHandle DeviceVoltageState_connection (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_convert\_to 

```C++
void DeviceVoltageState_convert_to (
    DeviceVoltageStateHandle handle,
    SymbolUnitHandle target_unit
) 
```




<hr>



### function DeviceVoltageState\_create 

```C++
DeviceVoltageStateHandle DeviceVoltageState_create (
    ConnectionHandle connection,
    double voltage,
    SymbolUnitHandle unit
) 
```




<hr>



### function DeviceVoltageState\_destroy 

```C++
void DeviceVoltageState_destroy (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_divide\_double 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_double (
    DeviceVoltageStateHandle handle,
    double other
) 
```




<hr>



### function DeviceVoltageState\_divide\_equals\_double 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_double (
    DeviceVoltageStateHandle handle,
    double other
) 
```




<hr>



### function DeviceVoltageState\_divide\_equals\_int 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int (
    DeviceVoltageStateHandle handle,
    int other
) 
```




<hr>



### function DeviceVoltageState\_divide\_equals\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_divide\_int 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_int (
    DeviceVoltageStateHandle handle,
    int other
) 
```




<hr>



### function DeviceVoltageState\_divide\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_divide_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_equal 

```C++
bool DeviceVoltageState_equal (
    DeviceVoltageStateHandle a,
    DeviceVoltageStateHandle b
) 
```




<hr>



### function DeviceVoltageState\_from\_json\_string 

```C++
DeviceVoltageStateHandle DeviceVoltageState_from_json_string (
    StringHandle json
) 
```




<hr>



### function DeviceVoltageState\_multiply\_double 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_double (
    DeviceVoltageStateHandle handle,
    double other
) 
```




<hr>



### function DeviceVoltageState\_multiply\_equals\_double 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_double (
    DeviceVoltageStateHandle handle,
    double other
) 
```




<hr>



### function DeviceVoltageState\_multiply\_equals\_int 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_int (
    DeviceVoltageStateHandle handle,
    int other
) 
```




<hr>



### function DeviceVoltageState\_multiply\_equals\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_multiply\_int 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_int (
    DeviceVoltageStateHandle handle,
    int other
) 
```




<hr>



### function DeviceVoltageState\_multiply\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_negate 

```C++
DeviceVoltageStateHandle DeviceVoltageState_negate (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_not\_equal 

```C++
bool DeviceVoltageState_not_equal (
    DeviceVoltageStateHandle a,
    DeviceVoltageStateHandle b
) 
```




<hr>



### function DeviceVoltageState\_power 

```C++
DeviceVoltageStateHandle DeviceVoltageState_power (
    DeviceVoltageStateHandle handle,
    int other
) 
```




<hr>



### function DeviceVoltageState\_subtract\_equals\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_subtract\_quantity 

```C++
DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity (
    DeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle other
) 
```




<hr>



### function DeviceVoltageState\_to\_json\_string 

```C++
StringHandle DeviceVoltageState_to_json_string (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_unit 

```C++
SymbolUnitHandle DeviceVoltageState_unit (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_value 

```C++
double DeviceVoltageState_value (
    DeviceVoltageStateHandle handle
) 
```




<hr>



### function DeviceVoltageState\_voltage 

```C++
double DeviceVoltageState_voltage (
    DeviceVoltageStateHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h`

