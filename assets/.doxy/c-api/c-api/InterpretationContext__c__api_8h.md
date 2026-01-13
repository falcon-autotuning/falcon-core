

# File InterpretationContext\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**interpretations**](dir_13f1f114359a7e6b19216040e0da6abc.md) **>** [**InterpretationContext\_c\_api.h**](InterpretationContext__c__api_8h.md)

[Go to the source code of this file](InterpretationContext__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"`
* `#include "falcon_core/generic/ListMeasurementContext_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/AxesMeasurementContext_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**InterpretationContextHandle**](#typedef-interpretationcontexthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**InterpretationContext\_add\_dependent\_variable**](#function-interpretationcontext_add_dependent_variable) (InterpretationContextHandle handle, MeasurementContextHandle variable) <br>_Add a dependant variable to the measurement context._  |
|  InterpretationContextHandle | [**InterpretationContext\_copy**](#function-interpretationcontext_copy) (InterpretationContextHandle handle) <br> |
|  InterpretationContextHandle | [**InterpretationContext\_create**](#function-interpretationcontext_create) (AxesMeasurementContextHandle independant\_variables, ListMeasurementContextHandle dependant\_variables, SymbolUnitHandle unit) <br> |
|  ListMeasurementContextHandle | [**InterpretationContext\_dependent\_variables**](#function-interpretationcontext_dependent_variables) (InterpretationContextHandle handle) <br>_Return the dependent variables (measured parameters)._  |
|  void | [**InterpretationContext\_destroy**](#function-interpretationcontext_destroy) (InterpretationContextHandle handle) <br> |
|  int | [**InterpretationContext\_dimension**](#function-interpretationcontext_dimension) (InterpretationContextHandle handle) <br>_Return the dimensionality of the measurement (number of independent variables)._  |
|  bool | [**InterpretationContext\_equal**](#function-interpretationcontext_equal) (InterpretationContextHandle handle, InterpretationContextHandle other) <br> |
|  InterpretationContextHandle | [**InterpretationContext\_from\_json\_string**](#function-interpretationcontext_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  MeasurementContextHandle | [**InterpretationContext\_get\_independent\_variables**](#function-interpretationcontext_get_independent_variables) (InterpretationContextHandle handle, int index) <br> |
|  AxesMeasurementContextHandle | [**InterpretationContext\_independent\_variables**](#function-interpretationcontext_independent_variables) (InterpretationContextHandle handle) <br>_Return the independent variables (sweep parameters)._  |
|  bool | [**InterpretationContext\_not\_equal**](#function-interpretationcontext_not_equal) (InterpretationContextHandle handle, InterpretationContextHandle other) <br> |
|  void | [**InterpretationContext\_replace\_dependent\_variable**](#function-interpretationcontext_replace_dependent_variable) (InterpretationContextHandle handle, int index, MeasurementContextHandle variable) <br>_Replace a dependent variable at the specified index._  |
|  [**StringHandle**](structstring.md) | [**InterpretationContext\_to\_json\_string**](#function-interpretationcontext_to_json_string) (InterpretationContextHandle handle) <br> |
|  SymbolUnitHandle | [**InterpretationContext\_unit**](#function-interpretationcontext_unit) (InterpretationContextHandle handle) <br>_Return the unit for interpreting the values._  |
|  InterpretationContextHandle | [**InterpretationContext\_with\_unit**](#function-interpretationcontext_with_unit) (InterpretationContextHandle handle, SymbolUnitHandle unit) <br>_Create a new interpretation context with the given unit._  |




























## Public Types Documentation




### typedef InterpretationContextHandle 

```C++
typedef void* InterpretationContextHandle;
```




<hr>
## Public Functions Documentation




### function InterpretationContext\_add\_dependent\_variable 

_Add a dependant variable to the measurement context._ 
```C++
void InterpretationContext_add_dependent_variable (
    InterpretationContextHandle handle,
    MeasurementContextHandle variable
) 
```





**Parameters:**


* `variable` The dependent variable to add. 




        

<hr>



### function InterpretationContext\_copy 

```C++
InterpretationContextHandle InterpretationContext_copy (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_create 

```C++
InterpretationContextHandle InterpretationContext_create (
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle unit
) 
```




<hr>



### function InterpretationContext\_dependent\_variables 

_Return the dependent variables (measured parameters)._ 
```C++
ListMeasurementContextHandle InterpretationContext_dependent_variables (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_destroy 

```C++
void InterpretationContext_destroy (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_dimension 

_Return the dimensionality of the measurement (number of independent variables)._ 
```C++
int InterpretationContext_dimension (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_equal 

```C++
bool InterpretationContext_equal (
    InterpretationContextHandle handle,
    InterpretationContextHandle other
) 
```




<hr>



### function InterpretationContext\_from\_json\_string 

```C++
InterpretationContextHandle InterpretationContext_from_json_string (
    StringHandle json
) 
```




<hr>



### function InterpretationContext\_get\_independent\_variables 

```C++
MeasurementContextHandle InterpretationContext_get_independent_variables (
    InterpretationContextHandle handle,
    int index
) 
```




<hr>



### function InterpretationContext\_independent\_variables 

_Return the independent variables (sweep parameters)._ 
```C++
AxesMeasurementContextHandle InterpretationContext_independent_variables (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_not\_equal 

```C++
bool InterpretationContext_not_equal (
    InterpretationContextHandle handle,
    InterpretationContextHandle other
) 
```




<hr>



### function InterpretationContext\_replace\_dependent\_variable 

_Replace a dependent variable at the specified index._ 
```C++
void InterpretationContext_replace_dependent_variable (
    InterpretationContextHandle handle,
    int index,
    MeasurementContextHandle variable
) 
```





**Parameters:**


* `index` The count corresponding to the location of the variable to replace. 
* `variable` The varaible that is to be stored at the location. 




        

<hr>



### function InterpretationContext\_to\_json\_string 

```C++
StringHandle InterpretationContext_to_json_string (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_unit 

_Return the unit for interpreting the values._ 
```C++
SymbolUnitHandle InterpretationContext_unit (
    InterpretationContextHandle handle
) 
```




<hr>



### function InterpretationContext\_with\_unit 

_Create a new interpretation context with the given unit._ 
```C++
InterpretationContextHandle InterpretationContext_with_unit (
    InterpretationContextHandle handle,
    SymbolUnitHandle unit
) 
```





**Parameters:**


* `unit` The physical unit to use 



**Returns:**

A new interpretation context with the same variables but a different unit. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h`

