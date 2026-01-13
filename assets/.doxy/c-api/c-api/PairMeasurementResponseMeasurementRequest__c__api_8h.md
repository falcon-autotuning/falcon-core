

# File PairMeasurementResponseMeasurementRequest\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairMeasurementResponseMeasurementRequest\_c\_api.h**](PairMeasurementResponseMeasurementRequest__c__api_8h.md)

[Go to the source code of this file](PairMeasurementResponseMeasurementRequest__c__api_8h_source.md)



* `#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"`
* `#include "falcon_core/communications/messages/MeasurementRequest_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairMeasurementResponseMeasurementRequestHandle**](#typedef-pairmeasurementresponsemeasurementrequesthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairMeasurementResponseMeasurementRequestHandle | [**PairMeasurementResponseMeasurementRequest\_copy**](#function-pairmeasurementresponsemeasurementrequest_copy) (PairMeasurementResponseMeasurementRequestHandle handle) <br> |
|  PairMeasurementResponseMeasurementRequestHandle | [**PairMeasurementResponseMeasurementRequest\_create**](#function-pairmeasurementresponsemeasurementrequest_create) (MeasurementResponseHandle first, MeasurementRequestHandle second) <br> |
|  void | [**PairMeasurementResponseMeasurementRequest\_destroy**](#function-pairmeasurementresponsemeasurementrequest_destroy) (PairMeasurementResponseMeasurementRequestHandle handle) <br> |
|  bool | [**PairMeasurementResponseMeasurementRequest\_equal**](#function-pairmeasurementresponsemeasurementrequest_equal) (PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other) <br> |
|  MeasurementResponseHandle | [**PairMeasurementResponseMeasurementRequest\_first**](#function-pairmeasurementresponsemeasurementrequest_first) (PairMeasurementResponseMeasurementRequestHandle handle) <br> |
|  PairMeasurementResponseMeasurementRequestHandle | [**PairMeasurementResponseMeasurementRequest\_from\_json\_string**](#function-pairmeasurementresponsemeasurementrequest_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairMeasurementResponseMeasurementRequest\_not\_equal**](#function-pairmeasurementresponsemeasurementrequest_not_equal) (PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other) <br> |
|  MeasurementRequestHandle | [**PairMeasurementResponseMeasurementRequest\_second**](#function-pairmeasurementresponsemeasurementrequest_second) (PairMeasurementResponseMeasurementRequestHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairMeasurementResponseMeasurementRequest\_to\_json\_string**](#function-pairmeasurementresponsemeasurementrequest_to_json_string) (PairMeasurementResponseMeasurementRequestHandle handle) <br> |




























## Public Types Documentation




### typedef PairMeasurementResponseMeasurementRequestHandle 

```C++
typedef void* PairMeasurementResponseMeasurementRequestHandle;
```




<hr>
## Public Functions Documentation




### function PairMeasurementResponseMeasurementRequest\_copy 

```C++
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_copy (
    PairMeasurementResponseMeasurementRequestHandle handle
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_create 

```C++
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create (
    MeasurementResponseHandle first,
    MeasurementRequestHandle second
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_destroy 

```C++
void PairMeasurementResponseMeasurementRequest_destroy (
    PairMeasurementResponseMeasurementRequestHandle handle
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_equal 

```C++
bool PairMeasurementResponseMeasurementRequest_equal (
    PairMeasurementResponseMeasurementRequestHandle handle,
    PairMeasurementResponseMeasurementRequestHandle other
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_first 

```C++
MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first (
    PairMeasurementResponseMeasurementRequestHandle handle
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_from\_json\_string 

```C++
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_not\_equal 

```C++
bool PairMeasurementResponseMeasurementRequest_not_equal (
    PairMeasurementResponseMeasurementRequestHandle handle,
    PairMeasurementResponseMeasurementRequestHandle other
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_second 

```C++
MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second (
    PairMeasurementResponseMeasurementRequestHandle handle
) 
```




<hr>



### function PairMeasurementResponseMeasurementRequest\_to\_json\_string 

```C++
StringHandle PairMeasurementResponseMeasurementRequest_to_json_string (
    PairMeasurementResponseMeasurementRequestHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairMeasurementResponseMeasurementRequest_c_api.h`

