

# File InterpretationContainerDouble\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerDouble\_c\_api.h**](InterpretationContainerDouble__c__api_8h.md)

[Go to the source code of this file](InterpretationContainerDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListDouble_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"`
* `#include "falcon_core/generic/MapInterpretationContextDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**InterpretationContainerDoubleHandle**](#typedef-interpretationcontainerdoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**InterpretationContainerDouble\_at**](#function-interpretationcontainerdouble_at) (InterpretationContainerDoubleHandle handle, InterpretationContextHandle key) <br> |
|  void | [**InterpretationContainerDouble\_clear**](#function-interpretationcontainerdouble_clear) (InterpretationContainerDoubleHandle handle) <br> |
|  bool | [**InterpretationContainerDouble\_contains**](#function-interpretationcontainerdouble_contains) (InterpretationContainerDoubleHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerDoubleHandle | [**InterpretationContainerDouble\_copy**](#function-interpretationcontainerdouble_copy) (InterpretationContainerDoubleHandle handle) <br> |
|  InterpretationContainerDoubleHandle | [**InterpretationContainerDouble\_create**](#function-interpretationcontainerdouble_create) (MapInterpretationContextDoubleHandle contextDoubleMap) <br> |
|  void | [**InterpretationContainerDouble\_destroy**](#function-interpretationcontainerdouble_destroy) (InterpretationContainerDoubleHandle handle) <br> |
|  bool | [**InterpretationContainerDouble\_empty**](#function-interpretationcontainerdouble_empty) (InterpretationContainerDoubleHandle handle) <br> |
|  bool | [**InterpretationContainerDouble\_equal**](#function-interpretationcontainerdouble_equal) (InterpretationContainerDoubleHandle handle, InterpretationContainerDoubleHandle other) <br> |
|  void | [**InterpretationContainerDouble\_erase**](#function-interpretationcontainerdouble_erase) (InterpretationContainerDoubleHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerDoubleHandle | [**InterpretationContainerDouble\_from\_json\_string**](#function-interpretationcontainerdouble_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**InterpretationContainerDouble\_insert**](#function-interpretationcontainerdouble_insert) (InterpretationContainerDoubleHandle handle, InterpretationContextHandle key, double value) <br> |
|  void | [**InterpretationContainerDouble\_insert\_or\_assign**](#function-interpretationcontainerdouble_insert_or_assign) (InterpretationContainerDoubleHandle handle, InterpretationContextHandle key, double value) <br> |
|  ListPairInterpretationContextDoubleHandle | [**InterpretationContainerDouble\_items**](#function-interpretationcontainerdouble_items) (InterpretationContainerDoubleHandle handle) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_keys**](#function-interpretationcontainerdouble_keys) (InterpretationContainerDoubleHandle handle) <br> |
|  bool | [**InterpretationContainerDouble\_not\_equal**](#function-interpretationcontainerdouble_not_equal) (InterpretationContainerDoubleHandle handle, InterpretationContainerDoubleHandle other) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_select\_by\_connection**](#function-interpretationcontainerdouble_select_by_connection) (InterpretationContainerDoubleHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_select\_by\_connections**](#function-interpretationcontainerdouble_select_by_connections) (InterpretationContainerDoubleHandle handle, ConnectionsHandle connections) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_select\_by\_dependent\_connection**](#function-interpretationcontainerdouble_select_by_dependent_connection) (InterpretationContainerDoubleHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_select\_by\_independent\_connection**](#function-interpretationcontainerdouble_select_by_independent_connection) (InterpretationContainerDoubleHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerDouble\_select\_contexts**](#function-interpretationcontainerdouble_select_contexts) (InterpretationContainerDoubleHandle handle, ListConnectionHandle independent\_connections, ListConnectionHandle dependent\_connections) <br> |
|  size\_t | [**InterpretationContainerDouble\_size**](#function-interpretationcontainerdouble_size) (InterpretationContainerDoubleHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**InterpretationContainerDouble\_to\_json\_string**](#function-interpretationcontainerdouble_to_json_string) (InterpretationContainerDoubleHandle handle) <br> |
|  SymbolUnitHandle | [**InterpretationContainerDouble\_unit**](#function-interpretationcontainerdouble_unit) (InterpretationContainerDoubleHandle handle) <br> |
|  ListDoubleHandle | [**InterpretationContainerDouble\_values**](#function-interpretationcontainerdouble_values) (InterpretationContainerDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef InterpretationContainerDoubleHandle 

```C++
typedef void* InterpretationContainerDoubleHandle;
```




<hr>
## Public Functions Documentation




### function InterpretationContainerDouble\_at 

```C++
double InterpretationContainerDouble_at (
    InterpretationContainerDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerDouble\_clear 

```C++
void InterpretationContainerDouble_clear (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_contains 

```C++
bool InterpretationContainerDouble_contains (
    InterpretationContainerDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerDouble\_copy 

```C++
InterpretationContainerDoubleHandle InterpretationContainerDouble_copy (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_create 

```C++
InterpretationContainerDoubleHandle InterpretationContainerDouble_create (
    MapInterpretationContextDoubleHandle contextDoubleMap
) 
```




<hr>



### function InterpretationContainerDouble\_destroy 

```C++
void InterpretationContainerDouble_destroy (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_empty 

```C++
bool InterpretationContainerDouble_empty (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_equal 

```C++
bool InterpretationContainerDouble_equal (
    InterpretationContainerDoubleHandle handle,
    InterpretationContainerDoubleHandle other
) 
```




<hr>



### function InterpretationContainerDouble\_erase 

```C++
void InterpretationContainerDouble_erase (
    InterpretationContainerDoubleHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerDouble\_from\_json\_string 

```C++
InterpretationContainerDoubleHandle InterpretationContainerDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function InterpretationContainerDouble\_insert 

```C++
void InterpretationContainerDouble_insert (
    InterpretationContainerDoubleHandle handle,
    InterpretationContextHandle key,
    double value
) 
```




<hr>



### function InterpretationContainerDouble\_insert\_or\_assign 

```C++
void InterpretationContainerDouble_insert_or_assign (
    InterpretationContainerDoubleHandle handle,
    InterpretationContextHandle key,
    double value
) 
```




<hr>



### function InterpretationContainerDouble\_items 

```C++
ListPairInterpretationContextDoubleHandle InterpretationContainerDouble_items (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_keys 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_keys (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_not\_equal 

```C++
bool InterpretationContainerDouble_not_equal (
    InterpretationContainerDoubleHandle handle,
    InterpretationContainerDoubleHandle other
) 
```




<hr>



### function InterpretationContainerDouble\_select\_by\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connection (
    InterpretationContainerDoubleHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerDouble\_select\_by\_connections 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_select_by_connections (
    InterpretationContainerDoubleHandle handle,
    ConnectionsHandle connections
) 
```




<hr>



### function InterpretationContainerDouble\_select\_by\_dependent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_select_by_dependent_connection (
    InterpretationContainerDoubleHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerDouble\_select\_by\_independent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_select_by_independent_connection (
    InterpretationContainerDoubleHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerDouble\_select\_contexts 

```C++
ListInterpretationContextHandle InterpretationContainerDouble_select_contexts (
    InterpretationContainerDoubleHandle handle,
    ListConnectionHandle independent_connections,
    ListConnectionHandle dependent_connections
) 
```




<hr>



### function InterpretationContainerDouble\_size 

```C++
size_t InterpretationContainerDouble_size (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_to\_json\_string 

```C++
StringHandle InterpretationContainerDouble_to_json_string (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_unit 

```C++
SymbolUnitHandle InterpretationContainerDouble_unit (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>



### function InterpretationContainerDouble\_values 

```C++
ListDoubleHandle InterpretationContainerDouble_values (
    InterpretationContainerDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContainerDouble_c_api.h`

