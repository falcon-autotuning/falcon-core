

# File MeasurementContext\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**contexts**](dir_ab40c3cabb8cb545690339f76b9d4949.md) **>** [**MeasurementContext\_c\_api.h**](MeasurementContext__c__api_8h.md)

[Go to the source code of this file](MeasurementContext__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MeasurementContextHandle**](#typedef-measurementcontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionHandle | [**MeasurementContext\_connection**](#function-measurementcontext_connection) (MeasurementContextHandle handle) <br> |
|  MeasurementContextHandle | [**MeasurementContext\_copy**](#function-measurementcontext_copy) (MeasurementContextHandle handle) <br> |
|  MeasurementContextHandle | [**MeasurementContext\_create**](#function-measurementcontext_create) (ConnectionHandle connection, [**StringHandle**](structstring.md) instrument\_type) <br> |
|  MeasurementContextHandle | [**MeasurementContext\_create\_from\_port**](#function-measurementcontext_create_from_port) (InstrumentPortHandle port) <br> |
|  void | [**MeasurementContext\_destroy**](#function-measurementcontext_destroy) (MeasurementContextHandle handle) <br> |
|  bool | [**MeasurementContext\_equal**](#function-measurementcontext_equal) (MeasurementContextHandle handle, MeasurementContextHandle other) <br> |
|  MeasurementContextHandle | [**MeasurementContext\_from\_json\_string**](#function-measurementcontext_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**MeasurementContext\_instrument\_type**](#function-measurementcontext_instrument_type) (MeasurementContextHandle handle) <br> |
|  bool | [**MeasurementContext\_not\_equal**](#function-measurementcontext_not_equal) (MeasurementContextHandle handle, MeasurementContextHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**MeasurementContext\_to\_json\_string**](#function-measurementcontext_to_json_string) (MeasurementContextHandle handle) <br> |




























## Public Types Documentation




### typedef MeasurementContextHandle 

```C++
typedef void* MeasurementContextHandle;
```




<hr>
## Public Functions Documentation




### function MeasurementContext\_connection 

```C++
ConnectionHandle MeasurementContext_connection (
    MeasurementContextHandle handle
) 
```




<hr>



### function MeasurementContext\_copy 

```C++
MeasurementContextHandle MeasurementContext_copy (
    MeasurementContextHandle handle
) 
```




<hr>



### function MeasurementContext\_create 

```C++
MeasurementContextHandle MeasurementContext_create (
    ConnectionHandle connection,
    StringHandle instrument_type
) 
```




<hr>



### function MeasurementContext\_create\_from\_port 

```C++
MeasurementContextHandle MeasurementContext_create_from_port (
    InstrumentPortHandle port
) 
```




<hr>



### function MeasurementContext\_destroy 

```C++
void MeasurementContext_destroy (
    MeasurementContextHandle handle
) 
```




<hr>



### function MeasurementContext\_equal 

```C++
bool MeasurementContext_equal (
    MeasurementContextHandle handle,
    MeasurementContextHandle other
) 
```




<hr>



### function MeasurementContext\_from\_json\_string 

```C++
MeasurementContextHandle MeasurementContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function MeasurementContext\_instrument\_type 

```C++
StringHandle MeasurementContext_instrument_type (
    MeasurementContextHandle handle
) 
```




<hr>



### function MeasurementContext\_not\_equal 

```C++
bool MeasurementContext_not_equal (
    MeasurementContextHandle handle,
    MeasurementContextHandle other
) 
```




<hr>



### function MeasurementContext\_to\_json\_string 

```C++
StringHandle MeasurementContext_to_json_string (
    MeasurementContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h`

