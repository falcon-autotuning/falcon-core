

# File Quantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Quantity\_c\_api.h**](Quantity__c__api_8h.md)

[Go to the source code of this file](Quantity__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**QuantityHandle**](#typedef-quantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  QuantityHandle | [**Quantity\_abs**](#function-quantity_abs) (QuantityHandle handle) <br> |
|  QuantityHandle | [**Quantity\_add\_equals\_quantity**](#function-quantity_add_equals_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_add\_quantity**](#function-quantity_add_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  void | [**Quantity\_convert\_to**](#function-quantity_convert_to) (QuantityHandle handle, SymbolUnitHandle target\_unit) <br>_Convert the quantity to a different unit._  |
|  QuantityHandle | [**Quantity\_copy**](#function-quantity_copy) (QuantityHandle handle) <br> |
|  QuantityHandle | [**Quantity\_create**](#function-quantity_create) (double value, SymbolUnitHandle unit) <br> |
|  void | [**Quantity\_destroy**](#function-quantity_destroy) (QuantityHandle handle) <br> |
|  QuantityHandle | [**Quantity\_divide\_double**](#function-quantity_divide_double) (QuantityHandle handle, double other) <br> |
|  QuantityHandle | [**Quantity\_divide\_equals\_double**](#function-quantity_divide_equals_double) (QuantityHandle handle, double other) <br> |
|  QuantityHandle | [**Quantity\_divide\_equals\_int**](#function-quantity_divide_equals_int) (QuantityHandle handle, int other) <br> |
|  QuantityHandle | [**Quantity\_divide\_equals\_quantity**](#function-quantity_divide_equals_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_divide\_int**](#function-quantity_divide_int) (QuantityHandle handle, int other) <br> |
|  QuantityHandle | [**Quantity\_divide\_quantity**](#function-quantity_divide_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  bool | [**Quantity\_equal**](#function-quantity_equal) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_from\_json\_string**](#function-quantity_from_json_string) (StringHandle json) <br> |
|  QuantityHandle | [**Quantity\_multiply\_double**](#function-quantity_multiply_double) (QuantityHandle handle, double other) <br> |
|  QuantityHandle | [**Quantity\_multiply\_equals\_double**](#function-quantity_multiply_equals_double) (QuantityHandle handle, double other) <br> |
|  QuantityHandle | [**Quantity\_multiply\_equals\_int**](#function-quantity_multiply_equals_int) (QuantityHandle handle, int other) <br> |
|  QuantityHandle | [**Quantity\_multiply\_equals\_quantity**](#function-quantity_multiply_equals_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_multiply\_int**](#function-quantity_multiply_int) (QuantityHandle handle, int other) <br> |
|  QuantityHandle | [**Quantity\_multiply\_quantity**](#function-quantity_multiply_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_negate**](#function-quantity_negate) (QuantityHandle handle) <br> |
|  bool | [**Quantity\_not\_equal**](#function-quantity_not_equal) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_power**](#function-quantity_power) (QuantityHandle handle, int other) <br> |
|  QuantityHandle | [**Quantity\_subtract\_equals\_quantity**](#function-quantity_subtract_equals_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  QuantityHandle | [**Quantity\_subtract\_quantity**](#function-quantity_subtract_quantity) (QuantityHandle handle, QuantityHandle other) <br> |
|  StringHandle | [**Quantity\_to\_json\_string**](#function-quantity_to_json_string) (QuantityHandle handle) <br> |
|  SymbolUnitHandle | [**Quantity\_unit**](#function-quantity_unit) (QuantityHandle handle) <br>_Return the unit of the quantity._  |
|  double | [**Quantity\_value**](#function-quantity_value) (QuantityHandle handle) <br>_Return the value of the quantity._  |




























## Public Types Documentation




### typedef QuantityHandle 

```C++
typedef void* QuantityHandle;
```




<hr>
## Public Functions Documentation




### function Quantity\_abs 

```C++
QuantityHandle Quantity_abs (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_add\_equals\_quantity 

```C++
QuantityHandle Quantity_add_equals_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_add\_quantity 

```C++
QuantityHandle Quantity_add_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_convert\_to 

_Convert the quantity to a different unit._ 
```C++
void Quantity_convert_to (
    QuantityHandle handle,
    SymbolUnitHandle target_unit
) 
```





**Parameters:**


* `target_unit` the raget unit to convert to. 




        

<hr>



### function Quantity\_copy 

```C++
QuantityHandle Quantity_copy (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_create 

```C++
QuantityHandle Quantity_create (
    double value,
    SymbolUnitHandle unit
) 
```




<hr>



### function Quantity\_destroy 

```C++
void Quantity_destroy (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_divide\_double 

```C++
QuantityHandle Quantity_divide_double (
    QuantityHandle handle,
    double other
) 
```




<hr>



### function Quantity\_divide\_equals\_double 

```C++
QuantityHandle Quantity_divide_equals_double (
    QuantityHandle handle,
    double other
) 
```




<hr>



### function Quantity\_divide\_equals\_int 

```C++
QuantityHandle Quantity_divide_equals_int (
    QuantityHandle handle,
    int other
) 
```




<hr>



### function Quantity\_divide\_equals\_quantity 

```C++
QuantityHandle Quantity_divide_equals_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_divide\_int 

```C++
QuantityHandle Quantity_divide_int (
    QuantityHandle handle,
    int other
) 
```




<hr>



### function Quantity\_divide\_quantity 

```C++
QuantityHandle Quantity_divide_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_equal 

```C++
bool Quantity_equal (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_from\_json\_string 

```C++
QuantityHandle Quantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function Quantity\_multiply\_double 

```C++
QuantityHandle Quantity_multiply_double (
    QuantityHandle handle,
    double other
) 
```




<hr>



### function Quantity\_multiply\_equals\_double 

```C++
QuantityHandle Quantity_multiply_equals_double (
    QuantityHandle handle,
    double other
) 
```




<hr>



### function Quantity\_multiply\_equals\_int 

```C++
QuantityHandle Quantity_multiply_equals_int (
    QuantityHandle handle,
    int other
) 
```




<hr>



### function Quantity\_multiply\_equals\_quantity 

```C++
QuantityHandle Quantity_multiply_equals_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_multiply\_int 

```C++
QuantityHandle Quantity_multiply_int (
    QuantityHandle handle,
    int other
) 
```




<hr>



### function Quantity\_multiply\_quantity 

```C++
QuantityHandle Quantity_multiply_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_negate 

```C++
QuantityHandle Quantity_negate (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_not\_equal 

```C++
bool Quantity_not_equal (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_power 

```C++
QuantityHandle Quantity_power (
    QuantityHandle handle,
    int other
) 
```




<hr>



### function Quantity\_subtract\_equals\_quantity 

```C++
QuantityHandle Quantity_subtract_equals_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_subtract\_quantity 

```C++
QuantityHandle Quantity_subtract_quantity (
    QuantityHandle handle,
    QuantityHandle other
) 
```




<hr>



### function Quantity\_to\_json\_string 

```C++
StringHandle Quantity_to_json_string (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_unit 

_Return the unit of the quantity._ 
```C++
SymbolUnitHandle Quantity_unit (
    QuantityHandle handle
) 
```




<hr>



### function Quantity\_value 

_Return the value of the quantity._ 
```C++
double Quantity_value (
    QuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/Quantity_c_api.h`

