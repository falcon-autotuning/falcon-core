

# File AnalyticFunction\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AnalyticFunction\_c\_api.h**](AnalyticFunction__c__api_8h.md)

[Go to the source code of this file](AnalyticFunction__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`
* `#include "falcon_core/generic/MapStringDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AnalyticFunctionHandle**](#typedef-analyticfunctionhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  AnalyticFunctionHandle | [**AnalyticFunction\_copy**](#function-analyticfunction_copy) (AnalyticFunctionHandle handle) <br> |
|  AnalyticFunctionHandle | [**AnalyticFunction\_create**](#function-analyticfunction_create) (ListStringHandle labels, [**StringHandle**](structstring.md) expression) <br> |
|  AnalyticFunctionHandle | [**AnalyticFunction\_create\_constant**](#function-analyticfunction_create_constant) (double value) <br> |
|  AnalyticFunctionHandle | [**AnalyticFunction\_create\_identity**](#function-analyticfunction_create_identity) () <br> |
|  void | [**AnalyticFunction\_destroy**](#function-analyticfunction_destroy) (AnalyticFunctionHandle handle) <br> |
|  bool | [**AnalyticFunction\_equal**](#function-analyticfunction_equal) (AnalyticFunctionHandle handle, AnalyticFunctionHandle other) <br> |
|  double | [**AnalyticFunction\_evaluate**](#function-analyticfunction_evaluate) (AnalyticFunctionHandle handle, MapStringDoubleHandle args, double time) <br>_Returns the evaluated analytic function._  |
|  FArrayDoubleHandle | [**AnalyticFunction\_evaluate\_arraywise**](#function-analyticfunction_evaluate_arraywise) (AnalyticFunctionHandle handle, MapStringDoubleHandle args, double deltaT, double maxTime) <br> |
|  AnalyticFunctionHandle | [**AnalyticFunction\_from\_json\_string**](#function-analyticfunction_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  ListStringHandle | [**AnalyticFunction\_labels**](#function-analyticfunction_labels) (AnalyticFunctionHandle handle) <br>_Return the set of labels in proper order of the function's arguments to their names._  |
|  bool | [**AnalyticFunction\_not\_equal**](#function-analyticfunction_not_equal) (AnalyticFunctionHandle handle, AnalyticFunctionHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**AnalyticFunction\_to\_json\_string**](#function-analyticfunction_to_json_string) (AnalyticFunctionHandle handle) <br> |




























## Public Types Documentation




### typedef AnalyticFunctionHandle 

```C++
typedef void* AnalyticFunctionHandle;
```




<hr>
## Public Functions Documentation




### function AnalyticFunction\_copy 

```C++
AnalyticFunctionHandle AnalyticFunction_copy (
    AnalyticFunctionHandle handle
) 
```




<hr>



### function AnalyticFunction\_create 

```C++
AnalyticFunctionHandle AnalyticFunction_create (
    ListStringHandle labels,
    StringHandle expression
) 
```




<hr>



### function AnalyticFunction\_create\_constant 

```C++
AnalyticFunctionHandle AnalyticFunction_create_constant (
    double value
) 
```




<hr>



### function AnalyticFunction\_create\_identity 

```C++
AnalyticFunctionHandle AnalyticFunction_create_identity () 
```




<hr>



### function AnalyticFunction\_destroy 

```C++
void AnalyticFunction_destroy (
    AnalyticFunctionHandle handle
) 
```




<hr>



### function AnalyticFunction\_equal 

```C++
bool AnalyticFunction_equal (
    AnalyticFunctionHandle handle,
    AnalyticFunctionHandle other
) 
```




<hr>



### function AnalyticFunction\_evaluate 

_Returns the evaluated analytic function._ 
```C++
double AnalyticFunction_evaluate (
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle args,
    double time
) 
```





**Parameters:**


* `args` The vector arguments supplied with human readable names 
* `time` The time to evaluate the function at.. 




        

<hr>



### function AnalyticFunction\_evaluate\_arraywise 

```C++
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise (
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle args,
    double deltaT,
    double maxTime
) 
```




<hr>



### function AnalyticFunction\_from\_json\_string 

```C++
AnalyticFunctionHandle AnalyticFunction_from_json_string (
    StringHandle json
) 
```




<hr>



### function AnalyticFunction\_labels 

_Return the set of labels in proper order of the function's arguments to their names._ 
```C++
ListStringHandle AnalyticFunction_labels (
    AnalyticFunctionHandle handle
) 
```




<hr>



### function AnalyticFunction\_not\_equal 

```C++
bool AnalyticFunction_not_equal (
    AnalyticFunctionHandle handle,
    AnalyticFunctionHandle other
) 
```




<hr>



### function AnalyticFunction\_to\_json\_string 

```C++
StringHandle AnalyticFunction_to_json_string (
    AnalyticFunctionHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AnalyticFunction_c_api.h`

