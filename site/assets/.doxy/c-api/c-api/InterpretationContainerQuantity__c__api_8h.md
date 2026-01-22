

# File InterpretationContainerQuantity\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContainerQuantity\_c\_api.h**](InterpretationContainerQuantity__c__api_8h.md)

[Go to the source code of this file](InterpretationContainerQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListQuantity_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"`
* `#include "falcon_core/generic/MapInterpretationContextQuantity_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**InterpretationContainerQuantityHandle**](#typedef-interpretationcontainerquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  QuantityHandle | [**InterpretationContainerQuantity\_at**](#function-interpretationcontainerquantity_at) (InterpretationContainerQuantityHandle handle, InterpretationContextHandle key) <br> |
|  void | [**InterpretationContainerQuantity\_clear**](#function-interpretationcontainerquantity_clear) (InterpretationContainerQuantityHandle handle) <br> |
|  bool | [**InterpretationContainerQuantity\_contains**](#function-interpretationcontainerquantity_contains) (InterpretationContainerQuantityHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerQuantityHandle | [**InterpretationContainerQuantity\_copy**](#function-interpretationcontainerquantity_copy) (InterpretationContainerQuantityHandle handle) <br> |
|  InterpretationContainerQuantityHandle | [**InterpretationContainerQuantity\_create**](#function-interpretationcontainerquantity_create) (MapInterpretationContextQuantityHandle contextDoubleMap) <br> |
|  void | [**InterpretationContainerQuantity\_destroy**](#function-interpretationcontainerquantity_destroy) (InterpretationContainerQuantityHandle handle) <br> |
|  bool | [**InterpretationContainerQuantity\_empty**](#function-interpretationcontainerquantity_empty) (InterpretationContainerQuantityHandle handle) <br> |
|  bool | [**InterpretationContainerQuantity\_equal**](#function-interpretationcontainerquantity_equal) (InterpretationContainerQuantityHandle handle, InterpretationContainerQuantityHandle other) <br> |
|  void | [**InterpretationContainerQuantity\_erase**](#function-interpretationcontainerquantity_erase) (InterpretationContainerQuantityHandle handle, InterpretationContextHandle key) <br> |
|  InterpretationContainerQuantityHandle | [**InterpretationContainerQuantity\_from\_json\_string**](#function-interpretationcontainerquantity_from_json_string) (StringHandle json) <br> |
|  void | [**InterpretationContainerQuantity\_insert**](#function-interpretationcontainerquantity_insert) (InterpretationContainerQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value) <br> |
|  void | [**InterpretationContainerQuantity\_insert\_or\_assign**](#function-interpretationcontainerquantity_insert_or_assign) (InterpretationContainerQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value) <br> |
|  ListPairInterpretationContextQuantityHandle | [**InterpretationContainerQuantity\_items**](#function-interpretationcontainerquantity_items) (InterpretationContainerQuantityHandle handle) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_keys**](#function-interpretationcontainerquantity_keys) (InterpretationContainerQuantityHandle handle) <br> |
|  bool | [**InterpretationContainerQuantity\_not\_equal**](#function-interpretationcontainerquantity_not_equal) (InterpretationContainerQuantityHandle handle, InterpretationContainerQuantityHandle other) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_select\_by\_connection**](#function-interpretationcontainerquantity_select_by_connection) (InterpretationContainerQuantityHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_select\_by\_connections**](#function-interpretationcontainerquantity_select_by_connections) (InterpretationContainerQuantityHandle handle, ConnectionsHandle connections) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_select\_by\_dependent\_connection**](#function-interpretationcontainerquantity_select_by_dependent_connection) (InterpretationContainerQuantityHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_select\_by\_independent\_connection**](#function-interpretationcontainerquantity_select_by_independent_connection) (InterpretationContainerQuantityHandle handle, ConnectionHandle connection) <br> |
|  ListInterpretationContextHandle | [**InterpretationContainerQuantity\_select\_contexts**](#function-interpretationcontainerquantity_select_contexts) (InterpretationContainerQuantityHandle handle, ListConnectionHandle independent\_connections, ListConnectionHandle dependent\_connections) <br> |
|  size\_t | [**InterpretationContainerQuantity\_size**](#function-interpretationcontainerquantity_size) (InterpretationContainerQuantityHandle handle) <br> |
|  StringHandle | [**InterpretationContainerQuantity\_to\_json\_string**](#function-interpretationcontainerquantity_to_json_string) (InterpretationContainerQuantityHandle handle) <br> |
|  SymbolUnitHandle | [**InterpretationContainerQuantity\_unit**](#function-interpretationcontainerquantity_unit) (InterpretationContainerQuantityHandle handle) <br> |
|  ListQuantityHandle | [**InterpretationContainerQuantity\_values**](#function-interpretationcontainerquantity_values) (InterpretationContainerQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef InterpretationContainerQuantityHandle 

```C++
typedef void* InterpretationContainerQuantityHandle;
```




<hr>
## Public Functions Documentation




### function InterpretationContainerQuantity\_at 

```C++
QuantityHandle InterpretationContainerQuantity_at (
    InterpretationContainerQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerQuantity\_clear 

```C++
void InterpretationContainerQuantity_clear (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_contains 

```C++
bool InterpretationContainerQuantity_contains (
    InterpretationContainerQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerQuantity\_copy 

```C++
InterpretationContainerQuantityHandle InterpretationContainerQuantity_copy (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_create 

```C++
InterpretationContainerQuantityHandle InterpretationContainerQuantity_create (
    MapInterpretationContextQuantityHandle contextDoubleMap
) 
```




<hr>



### function InterpretationContainerQuantity\_destroy 

```C++
void InterpretationContainerQuantity_destroy (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_empty 

```C++
bool InterpretationContainerQuantity_empty (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_equal 

```C++
bool InterpretationContainerQuantity_equal (
    InterpretationContainerQuantityHandle handle,
    InterpretationContainerQuantityHandle other
) 
```




<hr>



### function InterpretationContainerQuantity\_erase 

```C++
void InterpretationContainerQuantity_erase (
    InterpretationContainerQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function InterpretationContainerQuantity\_from\_json\_string 

```C++
InterpretationContainerQuantityHandle InterpretationContainerQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function InterpretationContainerQuantity\_insert 

```C++
void InterpretationContainerQuantity_insert (
    InterpretationContainerQuantityHandle handle,
    InterpretationContextHandle key,
    QuantityHandle value
) 
```




<hr>



### function InterpretationContainerQuantity\_insert\_or\_assign 

```C++
void InterpretationContainerQuantity_insert_or_assign (
    InterpretationContainerQuantityHandle handle,
    InterpretationContextHandle key,
    QuantityHandle value
) 
```




<hr>



### function InterpretationContainerQuantity\_items 

```C++
ListPairInterpretationContextQuantityHandle InterpretationContainerQuantity_items (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_keys 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_keys (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_not\_equal 

```C++
bool InterpretationContainerQuantity_not_equal (
    InterpretationContainerQuantityHandle handle,
    InterpretationContainerQuantityHandle other
) 
```




<hr>



### function InterpretationContainerQuantity\_select\_by\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connection (
    InterpretationContainerQuantityHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerQuantity\_select\_by\_connections 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_connections (
    InterpretationContainerQuantityHandle handle,
    ConnectionsHandle connections
) 
```




<hr>



### function InterpretationContainerQuantity\_select\_by\_dependent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_dependent_connection (
    InterpretationContainerQuantityHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerQuantity\_select\_by\_independent\_connection 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_select_by_independent_connection (
    InterpretationContainerQuantityHandle handle,
    ConnectionHandle connection
) 
```




<hr>



### function InterpretationContainerQuantity\_select\_contexts 

```C++
ListInterpretationContextHandle InterpretationContainerQuantity_select_contexts (
    InterpretationContainerQuantityHandle handle,
    ListConnectionHandle independent_connections,
    ListConnectionHandle dependent_connections
) 
```




<hr>



### function InterpretationContainerQuantity\_size 

```C++
size_t InterpretationContainerQuantity_size (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_to\_json\_string 

```C++
StringHandle InterpretationContainerQuantity_to_json_string (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_unit 

```C++
SymbolUnitHandle InterpretationContainerQuantity_unit (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>



### function InterpretationContainerQuantity\_values 

```C++
ListQuantityHandle InterpretationContainerQuantity_values (
    InterpretationContainerQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContainerQuantity_c_api.h`

