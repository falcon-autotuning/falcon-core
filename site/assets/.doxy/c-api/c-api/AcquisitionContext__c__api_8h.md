

# File AcquisitionContext\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**contexts**](dir_ab40c3cabb8cb545690339f76b9d4949.md) **>** [**AcquisitionContext\_c\_api.h**](AcquisitionContext__c__api_8h.md)

[Go to the source code of this file](AcquisitionContext__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AcquisitionContextHandle**](#typedef-acquisitioncontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionHandle | [**AcquisitionContext\_connection**](#function-acquisitioncontext_connection) (AcquisitionContextHandle handle) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_copy**](#function-acquisitioncontext_copy) (AcquisitionContextHandle handle) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_create**](#function-acquisitioncontext_create) (ConnectionHandle connection, StringHandle instrument\_type, SymbolUnitHandle units) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_create\_from\_port**](#function-acquisitioncontext_create_from_port) (InstrumentPortHandle port) <br> |
|  void | [**AcquisitionContext\_destroy**](#function-acquisitioncontext_destroy) (AcquisitionContextHandle handle) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_division**](#function-acquisitioncontext_division) (AcquisitionContextHandle handle, AcquisitionContextHandle other) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_division\_unit**](#function-acquisitioncontext_division_unit) (AcquisitionContextHandle handle, SymbolUnitHandle other) <br> |
|  bool | [**AcquisitionContext\_equal**](#function-acquisitioncontext_equal) (AcquisitionContextHandle handle, AcquisitionContextHandle other) <br> |
|  AcquisitionContextHandle | [**AcquisitionContext\_from\_json\_string**](#function-acquisitioncontext_from_json_string) (StringHandle json) <br> |
|  StringHandle | [**AcquisitionContext\_instrument\_type**](#function-acquisitioncontext_instrument_type) (AcquisitionContextHandle handle) <br> |
|  bool | [**AcquisitionContext\_match\_connection**](#function-acquisitioncontext_match_connection) (AcquisitionContextHandle handle, ConnectionHandle other) <br>_Divide the units. The context on the top keeps all other details._  |
|  bool | [**AcquisitionContext\_match\_instrument\_type**](#function-acquisitioncontext_match_instrument_type) (AcquisitionContextHandle handle, StringHandle other) <br>_Returns if the instrument type matches this context._  |
|  bool | [**AcquisitionContext\_not\_equal**](#function-acquisitioncontext_not_equal) (AcquisitionContextHandle handle, AcquisitionContextHandle other) <br> |
|  StringHandle | [**AcquisitionContext\_to\_json\_string**](#function-acquisitioncontext_to_json_string) (AcquisitionContextHandle handle) <br> |
|  SymbolUnitHandle | [**AcquisitionContext\_units**](#function-acquisitioncontext_units) (AcquisitionContextHandle handle) <br>_Returns the units of the context._  |




























## Public Types Documentation




### typedef AcquisitionContextHandle 

```C++
typedef void* AcquisitionContextHandle;
```




<hr>
## Public Functions Documentation




### function AcquisitionContext\_connection 

```C++
ConnectionHandle AcquisitionContext_connection (
    AcquisitionContextHandle handle
) 
```




<hr>



### function AcquisitionContext\_copy 

```C++
AcquisitionContextHandle AcquisitionContext_copy (
    AcquisitionContextHandle handle
) 
```




<hr>



### function AcquisitionContext\_create 

```C++
AcquisitionContextHandle AcquisitionContext_create (
    ConnectionHandle connection,
    StringHandle instrument_type,
    SymbolUnitHandle units
) 
```




<hr>



### function AcquisitionContext\_create\_from\_port 

```C++
AcquisitionContextHandle AcquisitionContext_create_from_port (
    InstrumentPortHandle port
) 
```




<hr>



### function AcquisitionContext\_destroy 

```C++
void AcquisitionContext_destroy (
    AcquisitionContextHandle handle
) 
```




<hr>



### function AcquisitionContext\_division 

```C++
AcquisitionContextHandle AcquisitionContext_division (
    AcquisitionContextHandle handle,
    AcquisitionContextHandle other
) 
```




<hr>



### function AcquisitionContext\_division\_unit 

```C++
AcquisitionContextHandle AcquisitionContext_division_unit (
    AcquisitionContextHandle handle,
    SymbolUnitHandle other
) 
```




<hr>



### function AcquisitionContext\_equal 

```C++
bool AcquisitionContext_equal (
    AcquisitionContextHandle handle,
    AcquisitionContextHandle other
) 
```




<hr>



### function AcquisitionContext\_from\_json\_string 

```C++
AcquisitionContextHandle AcquisitionContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function AcquisitionContext\_instrument\_type 

```C++
StringHandle AcquisitionContext_instrument_type (
    AcquisitionContextHandle handle
) 
```




<hr>



### function AcquisitionContext\_match\_connection 

_Divide the units. The context on the top keeps all other details._ 
```C++
bool AcquisitionContext_match_connection (
    AcquisitionContextHandle handle,
    ConnectionHandle other
) 
```





**Parameters:**


* `other` The unit to divide by. 



**Returns:**

A new context with the divided units. 





        

<hr>



### function AcquisitionContext\_match\_instrument\_type 

_Returns if the instrument type matches this context._ 
```C++
bool AcquisitionContext_match_instrument_type (
    AcquisitionContextHandle handle,
    StringHandle other
) 
```




<hr>



### function AcquisitionContext\_not\_equal 

```C++
bool AcquisitionContext_not_equal (
    AcquisitionContextHandle handle,
    AcquisitionContextHandle other
) 
```




<hr>



### function AcquisitionContext\_to\_json\_string 

```C++
StringHandle AcquisitionContext_to_json_string (
    AcquisitionContextHandle handle
) 
```




<hr>



### function AcquisitionContext\_units 

_Returns the units of the context._ 
```C++
SymbolUnitHandle AcquisitionContext_units (
    AcquisitionContextHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h`

