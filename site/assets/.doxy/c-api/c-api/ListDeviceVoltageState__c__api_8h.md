

# File ListDeviceVoltageState\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDeviceVoltageState\_c\_api.h**](ListDeviceVoltageState__c__api_8h.md)

[Go to the source code of this file](ListDeviceVoltageState__c__api_8h_source.md)



* `#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListDeviceVoltageStateHandle**](#typedef-listdevicevoltagestatehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DeviceVoltageStateHandle | [**ListDeviceVoltageState\_at**](#function-listdevicevoltagestate_at) (ListDeviceVoltageStateHandle handle, size\_t idx) <br> |
|  void | [**ListDeviceVoltageState\_clear**](#function-listdevicevoltagestate_clear) (ListDeviceVoltageStateHandle handle) <br> |
|  bool | [**ListDeviceVoltageState\_contains**](#function-listdevicevoltagestate_contains) (ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_copy**](#function-listdevicevoltagestate_copy) (ListDeviceVoltageStateHandle handle) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_create**](#function-listdevicevoltagestate_create) (DeviceVoltageStateHandle \* data, size\_t count) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_create\_empty**](#function-listdevicevoltagestate_create_empty) () <br> |
|  void | [**ListDeviceVoltageState\_destroy**](#function-listdevicevoltagestate_destroy) (ListDeviceVoltageStateHandle handle) <br> |
|  bool | [**ListDeviceVoltageState\_empty**](#function-listdevicevoltagestate_empty) (ListDeviceVoltageStateHandle handle) <br> |
|  bool | [**ListDeviceVoltageState\_equal**](#function-listdevicevoltagestate_equal) (ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other) <br> |
|  void | [**ListDeviceVoltageState\_erase\_at**](#function-listdevicevoltagestate_erase_at) (ListDeviceVoltageStateHandle handle, size\_t idx) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_fill\_value**](#function-listdevicevoltagestate_fill_value) (size\_t count, DeviceVoltageStateHandle value) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_from\_json\_string**](#function-listdevicevoltagestate_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListDeviceVoltageState\_index**](#function-listdevicevoltagestate_index) (ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) <br> |
|  ListDeviceVoltageStateHandle | [**ListDeviceVoltageState\_intersection**](#function-listdevicevoltagestate_intersection) (ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other) <br> |
|  size\_t | [**ListDeviceVoltageState\_items**](#function-listdevicevoltagestate_items) (ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListDeviceVoltageState\_not\_equal**](#function-listdevicevoltagestate_not_equal) (ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other) <br> |
|  void | [**ListDeviceVoltageState\_push\_back**](#function-listdevicevoltagestate_push_back) (ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value) <br> |
|  size\_t | [**ListDeviceVoltageState\_size**](#function-listdevicevoltagestate_size) (ListDeviceVoltageStateHandle handle) <br> |
|  StringHandle | [**ListDeviceVoltageState\_to\_json\_string**](#function-listdevicevoltagestate_to_json_string) (ListDeviceVoltageStateHandle handle) <br> |




























## Public Types Documentation




### typedef ListDeviceVoltageStateHandle 

```C++
typedef void* ListDeviceVoltageStateHandle;
```




<hr>
## Public Functions Documentation




### function ListDeviceVoltageState\_at 

```C++
DeviceVoltageStateHandle ListDeviceVoltageState_at (
    ListDeviceVoltageStateHandle handle,
    size_t idx
) 
```




<hr>



### function ListDeviceVoltageState\_clear 

```C++
void ListDeviceVoltageState_clear (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>



### function ListDeviceVoltageState\_contains 

```C++
bool ListDeviceVoltageState_contains (
    ListDeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function ListDeviceVoltageState\_copy 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_copy (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>



### function ListDeviceVoltageState\_create 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_create (
    DeviceVoltageStateHandle * data,
    size_t count
) 
```




<hr>



### function ListDeviceVoltageState\_create\_empty 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty () 
```




<hr>



### function ListDeviceVoltageState\_destroy 

```C++
void ListDeviceVoltageState_destroy (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>



### function ListDeviceVoltageState\_empty 

```C++
bool ListDeviceVoltageState_empty (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>



### function ListDeviceVoltageState\_equal 

```C++
bool ListDeviceVoltageState_equal (
    ListDeviceVoltageStateHandle handle,
    ListDeviceVoltageStateHandle other
) 
```




<hr>



### function ListDeviceVoltageState\_erase\_at 

```C++
void ListDeviceVoltageState_erase_at (
    ListDeviceVoltageStateHandle handle,
    size_t idx
) 
```




<hr>



### function ListDeviceVoltageState\_fill\_value 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value (
    size_t count,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function ListDeviceVoltageState\_from\_json\_string 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListDeviceVoltageState\_index 

```C++
size_t ListDeviceVoltageState_index (
    ListDeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function ListDeviceVoltageState\_intersection 

```C++
ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection (
    ListDeviceVoltageStateHandle handle,
    ListDeviceVoltageStateHandle other
) 
```




<hr>



### function ListDeviceVoltageState\_items 

```C++
size_t ListDeviceVoltageState_items (
    ListDeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListDeviceVoltageState\_not\_equal 

```C++
bool ListDeviceVoltageState_not_equal (
    ListDeviceVoltageStateHandle handle,
    ListDeviceVoltageStateHandle other
) 
```




<hr>



### function ListDeviceVoltageState\_push\_back 

```C++
void ListDeviceVoltageState_push_back (
    ListDeviceVoltageStateHandle handle,
    DeviceVoltageStateHandle value
) 
```




<hr>



### function ListDeviceVoltageState\_size 

```C++
size_t ListDeviceVoltageState_size (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>



### function ListDeviceVoltageState\_to\_json\_string 

```C++
StringHandle ListDeviceVoltageState_to_json_string (
    ListDeviceVoltageStateHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListDeviceVoltageState_c_api.h`

