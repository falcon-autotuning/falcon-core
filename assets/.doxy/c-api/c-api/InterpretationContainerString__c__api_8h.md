

# File InterpretationContainerString\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerString\_c\_api.h**](InterpretationContainerString__c__api_8h.md)

[Go to the source code of this file](InterpretationContainerString__c__api_8h_source.md)



* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"`
* `#include "falcon_core/generic/MapInterpretationContextString_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**InterpretationContainerStringHandle**](#typedef-interpretationcontainerstringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  [**StringHandle**](structstring.md) | [**InterpretationContainerString\_at**](#function-interpretationcontainerstring_at) (InterpretationContainerStringHandle handle, InterpretationContextHandle key) <br> |
|  void | [**InterpretationContainerString\_clear**](#function-interpretationcontainerstring_clear) (InterpretationContainerStringHandle handle) <br> |
|  bool | [**InterpretationContainerString\_contains**](#function-interpretationcontainerstring_contains) (InterpretationContainerStringHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerStringHandle | [**InterpretationContainerString\_copy**](#function-interpretationcontainerstring_copy) (InterpretationContainerStringHandle handle) <br> |
|  InterpretationContainerStringHandle | [**InterpretationContainerString\_create**](#function-interpretationcontainerstring_create) (MapInterpretationContextStringHandle contextDoubleMap) <br> |
|  void | [**InterpretationContainerString\_destroy**](#function-interpretationcontainerstring_destroy) (InterpretationContainerStringHandle handle) <br> |
|  bool | [**InterpretationContainerString\_empty**](#function-interpretationcontainerstring_empty) (InterpretationContainerStringHandle handle) <br> |
|  bool | [**InterpretationContainerString\_equal**](#function-interpretationcontainerstring_equal) (InterpretationContainerStringHandle handle, InterpretationContainerStringHandle other) <br> |
|  void | [**InterpretationContainerString\_erase**](#function-interpretationcontainerstring_erase) (InterpretationContainerStringHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerStringHandle | [**InterpretationContainerString\_from\_json\_string**](#function-interpretationcontainerstring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**InterpretationContainerString\_insert**](#function-interpretationcontainerstring_insert) (InterpretationContainerStringHandle handle, InterpretationContextHandle key, [**StringHandle**](structstring.md) value) <br> |
|  void | [**InterpretationContainerString\_insert\_or\_assign**](#function-interpretationcontainerstring_insert_or_assign) (InterpretationContainerStringHandle handle, InterpretationContextHandle key, [**StringHandle**](structstring.md) value) <br> |
|  ListPairInterpretationContextStringHandle | [**InterpretationContainerString\_items**](#function-interpretationcontainerstring_items) (InterpretationContainerStringHandle handle) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_keys**](#function-interpretationcontainerstring_keys) (InterpretationContainerStringHandle handle) <br> |
|  bool | [**InterpretationContainerString\_not\_equal**](#function-interpretationcontainerstring_not_equal) (InterpretationContainerStringHandle handle, InterpretationContainerStringHandle other) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_select\_by\_connection**](#function-interpretationcontainerstring_select_by_connection) (InterpretationContainerStringHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_select\_by\_connections**](#function-interpretationcontainerstring_select_by_connections) (InterpretationContainerStringHandle handle, ConnectionsHandle connections) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_select\_by\_dependent\_connection**](#function-interpretationcontainerstring_select_by_dependent_connection) (InterpretationContainerStringHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_select\_by\_independent\_connection**](#function-interpretationcontainerstring_select_by_independent_connection) (InterpretationContainerStringHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerString\_select\_contexts**](#function-interpretationcontainerstring_select_contexts) (InterpretationContainerStringHandle handle, ListConnectionHandle independent\_connections, ListConnectionHandle dependent\_connections) <br> |
|  size\_t | [**InterpretationContainerString\_size**](#function-interpretationcontainerstring_size) (InterpretationContainerStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**InterpretationContainerString\_to\_json\_string**](#function-interpretationcontainerstring_to_json_string) (InterpretationContainerStringHandle handle) <br> |
|  SymbolUnitHandle | [**InterpretationContainerString\_unit**](#function-interpretationcontainerstring_unit) (InterpretationContainerStringHandle handle) <br> |
|  ListStringHandle | [**InterpretationContainerString\_values**](#function-interpretationcontainerstring_values) (InterpretationContainerStringHandle handle) <br> |




























## Public Types Documentation




### typedef InterpretationContainerStringHandle 

```C++
typedef void* InterpretationContainerStringHandle;
```




<hr>
## Public Functions Documentation




### function InterpretationContainerString\_at 

```C++
StringHandle InterpretationContainerString_at (
    InterpretationContainerStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerString\_clear 

```C++
void InterpretationContainerString_clear (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_contains 

```C++
bool InterpretationContainerString_contains (
    InterpretationContainerStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerString\_copy 

```C++
InterpretationContainerStringHandle InterpretationContainerString_copy (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_create 

```C++
InterpretationContainerStringHandle InterpretationContainerString_create (
    MapInterpretationContextStringHandle contextDoubleMap
) 
```




<hr>



### function InterpretationContainerString\_destroy 

```C++
void InterpretationContainerString_destroy (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_empty 

```C++
bool InterpretationContainerString_empty (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_equal 

```C++
bool InterpretationContainerString_equal (
    InterpretationContainerStringHandle handle,
    InterpretationContainerStringHandle other
) 
```




<hr>



### function InterpretationContainerString\_erase 

```C++
void InterpretationContainerString_erase (
    InterpretationContainerStringHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerString\_from\_json\_string 

```C++
InterpretationContainerStringHandle InterpretationContainerString_from_json_string (
    StringHandle json
) 
```




<hr>



### function InterpretationContainerString\_insert 

```C++
void InterpretationContainerString_insert (
    InterpretationContainerStringHandle handle,
    InterpretationContextHandle key,
    StringHandle value
) 
```




<hr>



### function InterpretationContainerString\_insert\_or\_assign 

```C++
void InterpretationContainerString_insert_or_assign (
    InterpretationContainerStringHandle handle,
    InterpretationContextHandle key,
    StringHandle value
) 
```




<hr>



### function InterpretationContainerString\_items 

```C++
ListPairInterpretationContextStringHandle InterpretationContainerString_items (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_keys 

```C++
ListInterpretationContextHandle InterpretationContainerString_keys (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_not\_equal 

```C++
bool InterpretationContainerString_not_equal (
    InterpretationContainerStringHandle handle,
    InterpretationContainerStringHandle other
) 
```




<hr>



### function InterpretationContainerString\_select\_by\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerString_select_by_connection (
    InterpretationContainerStringHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerString\_select\_by\_connections 

```C++
ListInterpretationContextHandle InterpretationContainerString_select_by_connections (
    InterpretationContainerStringHandle handle,
    ConnectionsHandle connections
) 
```




<hr>



### function InterpretationContainerString\_select\_by\_dependent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerString_select_by_dependent_connection (
    InterpretationContainerStringHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerString\_select\_by\_independent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerString_select_by_independent_connection (
    InterpretationContainerStringHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerString\_select\_contexts 

```C++
ListInterpretationContextHandle InterpretationContainerString_select_contexts (
    InterpretationContainerStringHandle handle,
    ListConnectionHandle independent_connections,
    ListConnectionHandle dependent_connections
) 
```




<hr>



### function InterpretationContainerString\_size 

```C++
size_t InterpretationContainerString_size (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_to\_json\_string 

```C++
StringHandle InterpretationContainerString_to_json_string (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_unit 

```C++
SymbolUnitHandle InterpretationContainerString_unit (
    InterpretationContainerStringHandle handle
) 
```




<hr>



### function InterpretationContainerString\_values 

```C++
ListStringHandle InterpretationContainerString_values (
    InterpretationContainerStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContainerString_c_api.h`

