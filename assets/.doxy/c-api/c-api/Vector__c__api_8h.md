

# File Vector\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Vector\_c\_api.h**](Vector__c__api_8h.md)

[Go to the source code of this file](Vector__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h"`
* `#include "falcon_core/generic/ListPairQuantityQuantity_c_api.h"`
* `#include "falcon_core/generic/PairQuantityQuantity_c_api.h"`
* `#include "falcon_core/math/Point_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`
* `#include <stdbool.h>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**VectorHandle**](#typedef-vectorhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  VectorHandle | [**Vector\_addition**](#function-vector_addition) (VectorHandle handle, VectorHandle other) <br> |
|  PairQuantityQuantityHandle | [**Vector\_at**](#function-vector_at) (VectorHandle handle, ConnectionHandle key) <br> |
|  void | [**Vector\_clear**](#function-vector_clear) (VectorHandle handle) <br> |
|  ListConnectionHandle | [**Vector\_connections**](#function-vector_connections) (VectorHandle handle) <br>_Returns the affected connections for this vector._  |
|  bool | [**Vector\_contains**](#function-vector_contains) (VectorHandle handle, ConnectionHandle key) <br> |
|  VectorHandle | [**Vector\_copy**](#function-vector_copy) (VectorHandle handle) <br> |
|  VectorHandle | [**Vector\_create**](#function-vector_create) (PointHandle start, PointHandle end) <br> |
|  VectorHandle | [**Vector\_create\_from\_doubles**](#function-vector_create_from_doubles) (MapConnectionDoubleHandle start, MapConnectionDoubleHandle end, SymbolUnitHandle unit) <br> |
|  VectorHandle | [**Vector\_create\_from\_end**](#function-vector_create_from_end) (PointHandle end) <br> |
|  VectorHandle | [**Vector\_create\_from\_end\_doubles**](#function-vector_create_from_end_doubles) (MapConnectionDoubleHandle end, SymbolUnitHandle unit) <br> |
|  VectorHandle | [**Vector\_create\_from\_end\_quantities**](#function-vector_create_from_end_quantities) (MapConnectionQuantityHandle end) <br> |
|  VectorHandle | [**Vector\_create\_from\_parent**](#function-vector_create_from_parent) (MapConnectionQuantityHandle items) <br> |
|  VectorHandle | [**Vector\_create\_from\_quantities**](#function-vector_create_from_quantities) (MapConnectionQuantityHandle start, MapConnectionQuantityHandle end) <br> |
|  void | [**Vector\_destroy**](#function-vector_destroy) (VectorHandle handle) <br> |
|  VectorHandle | [**Vector\_double\_division**](#function-vector_double_division) (VectorHandle handle, double scalar) <br> |
|  VectorHandle | [**Vector\_double\_extend**](#function-vector_double_extend) (VectorHandle handle, double extension) <br> |
|  VectorHandle | [**Vector\_double\_multiplication**](#function-vector_double_multiplication) (VectorHandle handle, double scalar) <br> |
|  VectorHandle | [**Vector\_double\_shrink**](#function-vector_double_shrink) (VectorHandle handle, double extension) <br> |
|  bool | [**Vector\_empty**](#function-vector_empty) (VectorHandle handle) <br> |
|  MapConnectionDoubleHandle | [**Vector\_end\_map**](#function-vector_end_map) (VectorHandle handle) <br>_Returns the raw unitless map of the ending point._  |
|  PointHandle | [**Vector\_end\_point**](#function-vector_end_point) (VectorHandle handle) <br>_Return the end point of a vector in device coordinates._  |
|  MapConnectionQuantityHandle | [**Vector\_end\_quantities**](#function-vector_end_quantities) (VectorHandle handle) <br>_Returns the raw map of the ending point._  |
|  bool | [**Vector\_equal**](#function-vector_equal) (VectorHandle handle, VectorHandle other) <br> |
|  void | [**Vector\_erase**](#function-vector_erase) (VectorHandle handle, ConnectionHandle key) <br> |
|  VectorHandle | [**Vector\_from\_json\_string**](#function-vector_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  void | [**Vector\_insert**](#function-vector_insert) (VectorHandle handle, ConnectionHandle key, PairQuantityQuantityHandle value) <br> |
|  void | [**Vector\_insert\_or\_assign**](#function-vector_insert_or_assign) (VectorHandle handle, ConnectionHandle key, PairQuantityQuantityHandle value) <br> |
|  VectorHandle | [**Vector\_int\_division**](#function-vector_int_division) (VectorHandle handle, int scalar) <br> |
|  VectorHandle | [**Vector\_int\_extend**](#function-vector_int_extend) (VectorHandle handle, int extension) <br> |
|  VectorHandle | [**Vector\_int\_multiplication**](#function-vector_int_multiplication) (VectorHandle handle, int scalar) <br> |
|  VectorHandle | [**Vector\_int\_shrink**](#function-vector_int_shrink) (VectorHandle handle, int extension) <br> |
|  ListPairConnectionPairQuantityQuantityHandle | [**Vector\_items**](#function-vector_items) (VectorHandle handle) <br> |
|  ListConnectionHandle | [**Vector\_keys**](#function-vector_keys) (VectorHandle handle) <br> |
|  double | [**Vector\_magnitude**](#function-vector_magnitude) (VectorHandle handle) <br>_The magnitude of the vector._  |
|  VectorHandle | [**Vector\_negation**](#function-vector_negation) (VectorHandle handle) <br> |
|  VectorHandle | [**Vector\_normalize**](#function-vector_normalize) (VectorHandle handle) <br>_Returns the normalized vector starting at the anchored starting point._  |
|  bool | [**Vector\_not\_equal**](#function-vector_not_equal) (VectorHandle handle, VectorHandle other) <br> |
|  ConnectionHandle | [**Vector\_principle\_connection**](#function-vector_principle_connection) (VectorHandle handle) <br>_returns the principle\_connection that is the largest._  |
|  VectorHandle | [**Vector\_project**](#function-vector_project) (VectorHandle handle, VectorHandle other) <br>_Projects this vector onto another._  |
|  size\_t | [**Vector\_size**](#function-vector_size) (VectorHandle handle) <br> |
|  MapConnectionDoubleHandle | [**Vector\_start\_map**](#function-vector_start_map) (VectorHandle handle) <br>_Returns the raw unitless map of the starting point._  |
|  PointHandle | [**Vector\_start\_point**](#function-vector_start_point) (VectorHandle handle) <br>_Returns the point at the start._  |
|  MapConnectionQuantityHandle | [**Vector\_start\_quantities**](#function-vector_start_quantities) (VectorHandle handle) <br>_Returns the raw map of the starting point._  |
|  VectorHandle | [**Vector\_subtraction**](#function-vector_subtraction) (VectorHandle handle, VectorHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**Vector\_to\_json\_string**](#function-vector_to_json_string) (VectorHandle handle) <br> |
|  VectorHandle | [**Vector\_translate**](#function-vector_translate) (VectorHandle handle, PointHandle point) <br>_Displaces the origin of a vector by a point._  |
|  VectorHandle | [**Vector\_translate\_doubles**](#function-vector_translate_doubles) (VectorHandle handle, MapConnectionDoubleHandle point, SymbolUnitHandle unit) <br> |
|  VectorHandle | [**Vector\_translate\_quantities**](#function-vector_translate_quantities) (VectorHandle handle, MapConnectionQuantityHandle point) <br> |
|  VectorHandle | [**Vector\_translate\_to\_origin**](#function-vector_translate_to_origin) (VectorHandle handle) <br>_Translates a vector to the origin._  |
|  SymbolUnitHandle | [**Vector\_unit**](#function-vector_unit) (VectorHandle handle) <br>_Returns the unit of this vector._  |
|  VectorHandle | [**Vector\_unit\_vector**](#function-vector_unit_vector) (VectorHandle handle) <br>_Generates the unit vector for the direction of this vector._  |
|  VectorHandle | [**Vector\_update\_start\_from\_states**](#function-vector_update_start_from_states) (VectorHandle handle, DeviceVoltageStatesHandle state) <br>_Updates the vector to start from teh given DeviceCVoltageStates._  |
|  void | [**Vector\_update\_unit**](#function-vector_update_unit) (VectorHandle handle, SymbolUnitHandle unit) <br>_Updates the unit of this vector._  |
|  ListPairQuantityQuantityHandle | [**Vector\_values**](#function-vector_values) (VectorHandle handle) <br> |




























## Public Types Documentation




### typedef VectorHandle 

```C++
typedef void* VectorHandle;
```




<hr>
## Public Functions Documentation




### function Vector\_addition 

```C++
VectorHandle Vector_addition (
    VectorHandle handle,
    VectorHandle other
) 
```




<hr>



### function Vector\_at 

```C++
PairQuantityQuantityHandle Vector_at (
    VectorHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Vector\_clear 

```C++
void Vector_clear (
    VectorHandle handle
) 
```




<hr>



### function Vector\_connections 

_Returns the affected connections for this vector._ 
```C++
ListConnectionHandle Vector_connections (
    VectorHandle handle
) 
```




<hr>



### function Vector\_contains 

```C++
bool Vector_contains (
    VectorHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Vector\_copy 

```C++
VectorHandle Vector_copy (
    VectorHandle handle
) 
```




<hr>



### function Vector\_create 

```C++
VectorHandle Vector_create (
    PointHandle start,
    PointHandle end
) 
```




<hr>



### function Vector\_create\_from\_doubles 

```C++
VectorHandle Vector_create_from_doubles (
    MapConnectionDoubleHandle start,
    MapConnectionDoubleHandle end,
    SymbolUnitHandle unit
) 
```




<hr>



### function Vector\_create\_from\_end 

```C++
VectorHandle Vector_create_from_end (
    PointHandle end
) 
```




<hr>



### function Vector\_create\_from\_end\_doubles 

```C++
VectorHandle Vector_create_from_end_doubles (
    MapConnectionDoubleHandle end,
    SymbolUnitHandle unit
) 
```




<hr>



### function Vector\_create\_from\_end\_quantities 

```C++
VectorHandle Vector_create_from_end_quantities (
    MapConnectionQuantityHandle end
) 
```




<hr>



### function Vector\_create\_from\_parent 

```C++
VectorHandle Vector_create_from_parent (
    MapConnectionQuantityHandle items
) 
```




<hr>



### function Vector\_create\_from\_quantities 

```C++
VectorHandle Vector_create_from_quantities (
    MapConnectionQuantityHandle start,
    MapConnectionQuantityHandle end
) 
```




<hr>



### function Vector\_destroy 

```C++
void Vector_destroy (
    VectorHandle handle
) 
```




<hr>



### function Vector\_double\_division 

```C++
VectorHandle Vector_double_division (
    VectorHandle handle,
    double scalar
) 
```




<hr>



### function Vector\_double\_extend 

```C++
VectorHandle Vector_double_extend (
    VectorHandle handle,
    double extension
) 
```




<hr>



### function Vector\_double\_multiplication 

```C++
VectorHandle Vector_double_multiplication (
    VectorHandle handle,
    double scalar
) 
```




<hr>



### function Vector\_double\_shrink 

```C++
VectorHandle Vector_double_shrink (
    VectorHandle handle,
    double extension
) 
```




<hr>



### function Vector\_empty 

```C++
bool Vector_empty (
    VectorHandle handle
) 
```




<hr>



### function Vector\_end\_map 

_Returns the raw unitless map of the ending point._ 
```C++
MapConnectionDoubleHandle Vector_end_map (
    VectorHandle handle
) 
```




<hr>



### function Vector\_end\_point 

_Return the end point of a vector in device coordinates._ 
```C++
PointHandle Vector_end_point (
    VectorHandle handle
) 
```



This function is part of the public C API. It returns the end point associated with the given vector handle, after applying the current device transform.




**Parameters:**


* `v` Handle to a valid Vector instance. 



**Returns:**

A handle to the end point Vector.


Documentation imported from C++: Returns the point at the end. 


        

<hr>



### function Vector\_end\_quantities 

_Returns the raw map of the ending point._ 
```C++
MapConnectionQuantityHandle Vector_end_quantities (
    VectorHandle handle
) 
```




<hr>



### function Vector\_equal 

```C++
bool Vector_equal (
    VectorHandle handle,
    VectorHandle other
) 
```




<hr>



### function Vector\_erase 

```C++
void Vector_erase (
    VectorHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Vector\_from\_json\_string 

```C++
VectorHandle Vector_from_json_string (
    StringHandle json
) 
```




<hr>



### function Vector\_insert 

```C++
void Vector_insert (
    VectorHandle handle,
    ConnectionHandle key,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function Vector\_insert\_or\_assign 

```C++
void Vector_insert_or_assign (
    VectorHandle handle,
    ConnectionHandle key,
    PairQuantityQuantityHandle value
) 
```




<hr>



### function Vector\_int\_division 

```C++
VectorHandle Vector_int_division (
    VectorHandle handle,
    int scalar
) 
```




<hr>



### function Vector\_int\_extend 

```C++
VectorHandle Vector_int_extend (
    VectorHandle handle,
    int extension
) 
```




<hr>



### function Vector\_int\_multiplication 

```C++
VectorHandle Vector_int_multiplication (
    VectorHandle handle,
    int scalar
) 
```




<hr>



### function Vector\_int\_shrink 

```C++
VectorHandle Vector_int_shrink (
    VectorHandle handle,
    int extension
) 
```




<hr>



### function Vector\_items 

```C++
ListPairConnectionPairQuantityQuantityHandle Vector_items (
    VectorHandle handle
) 
```




<hr>



### function Vector\_keys 

```C++
ListConnectionHandle Vector_keys (
    VectorHandle handle
) 
```




<hr>



### function Vector\_magnitude 

_The magnitude of the vector._ 
```C++
double Vector_magnitude (
    VectorHandle handle
) 
```




<hr>



### function Vector\_negation 

```C++
VectorHandle Vector_negation (
    VectorHandle handle
) 
```




<hr>



### function Vector\_normalize 

_Returns the normalized vector starting at the anchored starting point._ 
```C++
VectorHandle Vector_normalize (
    VectorHandle handle
) 
```




<hr>



### function Vector\_not\_equal 

```C++
bool Vector_not_equal (
    VectorHandle handle,
    VectorHandle other
) 
```




<hr>



### function Vector\_principle\_connection 

_returns the principle\_connection that is the largest._ 
```C++
ConnectionHandle Vector_principle_connection (
    VectorHandle handle
) 
```




<hr>



### function Vector\_project 

_Projects this vector onto another._ 
```C++
VectorHandle Vector_project (
    VectorHandle handle,
    VectorHandle other
) 
```




<hr>



### function Vector\_size 

```C++
size_t Vector_size (
    VectorHandle handle
) 
```




<hr>



### function Vector\_start\_map 

_Returns the raw unitless map of the starting point._ 
```C++
MapConnectionDoubleHandle Vector_start_map (
    VectorHandle handle
) 
```




<hr>



### function Vector\_start\_point 

_Returns the point at the start._ 
```C++
PointHandle Vector_start_point (
    VectorHandle handle
) 
```




<hr>



### function Vector\_start\_quantities 

_Returns the raw map of the starting point._ 
```C++
MapConnectionQuantityHandle Vector_start_quantities (
    VectorHandle handle
) 
```




<hr>



### function Vector\_subtraction 

```C++
VectorHandle Vector_subtraction (
    VectorHandle handle,
    VectorHandle other
) 
```




<hr>



### function Vector\_to\_json\_string 

```C++
StringHandle Vector_to_json_string (
    VectorHandle handle
) 
```




<hr>



### function Vector\_translate 

_Displaces the origin of a vector by a point._ 
```C++
VectorHandle Vector_translate (
    VectorHandle handle,
    PointHandle point
) 
```





**Parameters:**


* `point` the diplacement 
* `unit` the unit of displacement 




        

<hr>



### function Vector\_translate\_doubles 

```C++
VectorHandle Vector_translate_doubles (
    VectorHandle handle,
    MapConnectionDoubleHandle point,
    SymbolUnitHandle unit
) 
```




<hr>



### function Vector\_translate\_quantities 

```C++
VectorHandle Vector_translate_quantities (
    VectorHandle handle,
    MapConnectionQuantityHandle point
) 
```




<hr>



### function Vector\_translate\_to\_origin 

_Translates a vector to the origin._ 
```C++
VectorHandle Vector_translate_to_origin (
    VectorHandle handle
) 
```




<hr>



### function Vector\_unit 

_Returns the unit of this vector._ 
```C++
SymbolUnitHandle Vector_unit (
    VectorHandle handle
) 
```




<hr>



### function Vector\_unit\_vector 

_Generates the unit vector for the direction of this vector._ 
```C++
VectorHandle Vector_unit_vector (
    VectorHandle handle
) 
```




<hr>



### function Vector\_update\_start\_from\_states 

_Updates the vector to start from teh given DeviceCVoltageStates._ 
```C++
VectorHandle Vector_update_start_from_states (
    VectorHandle handle,
    DeviceVoltageStatesHandle state
) 
```





**Parameters:**


* `state` the new device voltage state. 



**Returns:**

the displaced vector which starts at the given state. 





        

<hr>



### function Vector\_update\_unit 

_Updates the unit of this vector._ 
```C++
void Vector_update_unit (
    VectorHandle handle,
    SymbolUnitHandle unit
) 
```




<hr>



### function Vector\_values 

```C++
ListPairQuantityQuantityHandle Vector_values (
    VectorHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/Vector_c_api.h`

