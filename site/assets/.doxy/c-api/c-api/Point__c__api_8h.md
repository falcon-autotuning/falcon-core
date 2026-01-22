

# File Point\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Point\_c\_api.h**](Point__c__api_8h.md)

[Go to the source code of this file](Point__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include <stddef.h>`
* `#include "falcon_core/generic/ListConnection_c_api.h"`
* `#include "falcon_core/generic/MapConnectionDouble_c_api.h"`
* `#include "falcon_core/generic/MapConnectionQuantity_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/Quantity_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PointHandle**](#typedef-pointhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PointHandle | [**Point\_addition**](#function-point_addition) (PointHandle handle, PointHandle other) <br> |
|  QuantityHandle | [**Point\_at**](#function-point_at) (PointHandle handle, ConnectionHandle key) <br> |
|  void | [**Point\_clear**](#function-point_clear) (PointHandle handle) <br> |
|  ListConnectionHandle | [**Point\_connections**](#function-point_connections) (PointHandle handle) <br>_Returns the connections for the point._  |
|  bool | [**Point\_contains**](#function-point_contains) (PointHandle handle, ConnectionHandle key) <br> |
|  MapConnectionQuantityHandle | [**Point\_coordinates**](#function-point_coordinates) (PointHandle handle) <br>_Returns the coordinates for the point._  |
|  PointHandle | [**Point\_copy**](#function-point_copy) (PointHandle handle) <br> |
|  PointHandle | [**Point\_create**](#function-point_create) (MapConnectionDoubleHandle items, SymbolUnitHandle unit) <br> |
|  PointHandle | [**Point\_create\_empty**](#function-point_create_empty) () <br> |
|  PointHandle | [**Point\_create\_from\_parent**](#function-point_create_from_parent) (MapConnectionQuantityHandle items) <br> |
|  void | [**Point\_destroy**](#function-point_destroy) (PointHandle handle) <br> |
|  PointHandle | [**Point\_division**](#function-point_division) (PointHandle handle, double scalar) <br> |
|  bool | [**Point\_empty**](#function-point_empty) (PointHandle handle) <br> |
|  bool | [**Point\_equal**](#function-point_equal) (PointHandle handle, PointHandle other) <br> |
|  void | [**Point\_erase**](#function-point_erase) (PointHandle handle, ConnectionHandle key) <br> |
|  PointHandle | [**Point\_from\_json\_string**](#function-point_from_json_string) (StringHandle json) <br> |
|  void | [**Point\_insert**](#function-point_insert) (PointHandle handle, ConnectionHandle key, QuantityHandle value) <br> |
|  void | [**Point\_insert\_or\_assign**](#function-point_insert_or_assign) (PointHandle handle, ConnectionHandle key, QuantityHandle value) <br>_an overide of insert to make sure units are fixed._  |
|  ListPairConnectionQuantityHandle | [**Point\_items**](#function-point_items) (PointHandle handle) <br> |
|  ListConnectionHandle | [**Point\_keys**](#function-point_keys) (PointHandle handle) <br> |
|  PointHandle | [**Point\_multiplication**](#function-point_multiplication) (PointHandle handle, double scalar) <br> |
|  PointHandle | [**Point\_negation**](#function-point_negation) (PointHandle handle) <br> |
|  bool | [**Point\_not\_equal**](#function-point_not_equal) (PointHandle handle, PointHandle other) <br> |
|  void | [**Point\_set\_unit**](#function-point_set_unit) (PointHandle handle, SymbolUnitHandle unit) <br> |
|  size\_t | [**Point\_size**](#function-point_size) (PointHandle handle) <br> |
|  PointHandle | [**Point\_subtraction**](#function-point_subtraction) (PointHandle handle, PointHandle other) <br> |
|  StringHandle | [**Point\_to\_json\_string**](#function-point_to_json_string) (PointHandle handle) <br> |
|  SymbolUnitHandle | [**Point\_unit**](#function-point_unit) (PointHandle handle) <br>_Returns the SI unit for the point._  |
|  ListQuantityHandle | [**Point\_values**](#function-point_values) (PointHandle handle) <br> |




























## Public Types Documentation




### typedef PointHandle 

```C++
typedef void* PointHandle;
```




<hr>
## Public Functions Documentation




### function Point\_addition 

```C++
PointHandle Point_addition (
    PointHandle handle,
    PointHandle other
) 
```




<hr>



### function Point\_at 

```C++
QuantityHandle Point_at (
    PointHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Point\_clear 

```C++
void Point_clear (
    PointHandle handle
) 
```




<hr>



### function Point\_connections 

_Returns the connections for the point._ 
```C++
ListConnectionHandle Point_connections (
    PointHandle handle
) 
```




<hr>



### function Point\_contains 

```C++
bool Point_contains (
    PointHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Point\_coordinates 

_Returns the coordinates for the point._ 
```C++
MapConnectionQuantityHandle Point_coordinates (
    PointHandle handle
) 
```




<hr>



### function Point\_copy 

```C++
PointHandle Point_copy (
    PointHandle handle
) 
```




<hr>



### function Point\_create 

```C++
PointHandle Point_create (
    MapConnectionDoubleHandle items,
    SymbolUnitHandle unit
) 
```




<hr>



### function Point\_create\_empty 

```C++
PointHandle Point_create_empty () 
```




<hr>



### function Point\_create\_from\_parent 

```C++
PointHandle Point_create_from_parent (
    MapConnectionQuantityHandle items
) 
```




<hr>



### function Point\_destroy 

```C++
void Point_destroy (
    PointHandle handle
) 
```




<hr>



### function Point\_division 

```C++
PointHandle Point_division (
    PointHandle handle,
    double scalar
) 
```




<hr>



### function Point\_empty 

```C++
bool Point_empty (
    PointHandle handle
) 
```




<hr>



### function Point\_equal 

```C++
bool Point_equal (
    PointHandle handle,
    PointHandle other
) 
```




<hr>



### function Point\_erase 

```C++
void Point_erase (
    PointHandle handle,
    ConnectionHandle key
) 
```




<hr>



### function Point\_from\_json\_string 

```C++
PointHandle Point_from_json_string (
    StringHandle json
) 
```




<hr>



### function Point\_insert 

```C++
void Point_insert (
    PointHandle handle,
    ConnectionHandle key,
    QuantityHandle value
) 
```




<hr>



### function Point\_insert\_or\_assign 

_an overide of insert to make sure units are fixed._ 
```C++
void Point_insert_or_assign (
    PointHandle handle,
    ConnectionHandle key,
    QuantityHandle value
) 
```




<hr>



### function Point\_items 

```C++
ListPairConnectionQuantityHandle Point_items (
    PointHandle handle
) 
```




<hr>



### function Point\_keys 

```C++
ListConnectionHandle Point_keys (
    PointHandle handle
) 
```




<hr>



### function Point\_multiplication 

```C++
PointHandle Point_multiplication (
    PointHandle handle,
    double scalar
) 
```




<hr>



### function Point\_negation 

```C++
PointHandle Point_negation (
    PointHandle handle
) 
```




<hr>



### function Point\_not\_equal 

```C++
bool Point_not_equal (
    PointHandle handle,
    PointHandle other
) 
```




<hr>



### function Point\_set\_unit 

```C++
void Point_set_unit (
    PointHandle handle,
    SymbolUnitHandle unit
) 
```




<hr>



### function Point\_size 

```C++
size_t Point_size (
    PointHandle handle
) 
```




<hr>



### function Point\_subtraction 

```C++
PointHandle Point_subtraction (
    PointHandle handle,
    PointHandle other
) 
```




<hr>



### function Point\_to\_json\_string 

```C++
StringHandle Point_to_json_string (
    PointHandle handle
) 
```




<hr>



### function Point\_unit 

_Returns the SI unit for the point._ 
```C++
SymbolUnitHandle Point_unit (
    PointHandle handle
) 
```




<hr>



### function Point\_values 

```C++
ListQuantityHandle Point_values (
    PointHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/Point_c_api.h`

