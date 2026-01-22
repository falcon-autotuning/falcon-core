

# File MeasurementResponse\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**MeasurementResponse\_c\_api.h**](MeasurementResponse__c__api_8h.md)

[Go to the source code of this file](MeasurementResponse__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MeasurementResponseHandle**](#typedef-measurementresponsehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledArraysLabelledMeasuredArrayHandle | [**MeasurementResponse\_arrays**](#function-measurementresponse_arrays) (MeasurementResponseHandle handle) <br> |
|  MeasurementResponseHandle | [**MeasurementResponse\_copy**](#function-measurementresponse_copy) (MeasurementResponseHandle handle) <br> |
|  MeasurementResponseHandle | [**MeasurementResponse\_create**](#function-measurementresponse_create) (LabelledArraysLabelledMeasuredArrayHandle arrays) <br> |
|  void | [**MeasurementResponse\_destroy**](#function-measurementresponse_destroy) (MeasurementResponseHandle handle) <br> |
|  bool | [**MeasurementResponse\_equal**](#function-measurementresponse_equal) (MeasurementResponseHandle handle, MeasurementResponseHandle other) <br> |
|  MeasurementResponseHandle | [**MeasurementResponse\_from\_json\_string**](#function-measurementresponse_from_json_string) (StringHandle json) <br> |
|  StringHandle | [**MeasurementResponse\_message**](#function-measurementresponse_message) (MeasurementResponseHandle handle) <br> |
|  bool | [**MeasurementResponse\_not\_equal**](#function-measurementresponse_not_equal) (MeasurementResponseHandle handle, MeasurementResponseHandle other) <br> |
|  StringHandle | [**MeasurementResponse\_to\_json\_string**](#function-measurementresponse_to_json_string) (MeasurementResponseHandle handle) <br> |




























## Public Types Documentation




### typedef MeasurementResponseHandle 

```C++
typedef void* MeasurementResponseHandle;
```




<hr>
## Public Functions Documentation




### function MeasurementResponse\_arrays 

```C++
LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays (
    MeasurementResponseHandle handle
) 
```




<hr>



### function MeasurementResponse\_copy 

```C++
MeasurementResponseHandle MeasurementResponse_copy (
    MeasurementResponseHandle handle
) 
```




<hr>



### function MeasurementResponse\_create 

```C++
MeasurementResponseHandle MeasurementResponse_create (
    LabelledArraysLabelledMeasuredArrayHandle arrays
) 
```




<hr>



### function MeasurementResponse\_destroy 

```C++
void MeasurementResponse_destroy (
    MeasurementResponseHandle handle
) 
```




<hr>



### function MeasurementResponse\_equal 

```C++
bool MeasurementResponse_equal (
    MeasurementResponseHandle handle,
    MeasurementResponseHandle other
) 
```




<hr>



### function MeasurementResponse\_from\_json\_string 

```C++
MeasurementResponseHandle MeasurementResponse_from_json_string (
    StringHandle json
) 
```




<hr>



### function MeasurementResponse\_message 

```C++
StringHandle MeasurementResponse_message (
    MeasurementResponseHandle handle
) 
```




<hr>



### function MeasurementResponse\_not\_equal 

```C++
bool MeasurementResponse_not_equal (
    MeasurementResponseHandle handle,
    MeasurementResponseHandle other
) 
```




<hr>



### function MeasurementResponse\_to\_json\_string 

```C++
StringHandle MeasurementResponse_to_json_string (
    MeasurementResponseHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/messages/MeasurementResponse_c_api.h`

