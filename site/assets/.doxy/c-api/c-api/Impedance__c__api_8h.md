

# File Impedance\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Impedance\_c\_api.h**](Impedance__c__api_8h.md)

[Go to the source code of this file](Impedance__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ImpedanceHandle**](#typedef-impedancehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**Impedance\_capacitance**](#function-impedance_capacitance) (ImpedanceHandle handle) <br>_Gets the capacitance of the impedance._  |
|  ConnectionHandle | [**Impedance\_connection**](#function-impedance_connection) (ImpedanceHandle handle) <br>_Gets the connection leading to the fridge with this impedance._  |
|  ImpedanceHandle | [**Impedance\_copy**](#function-impedance_copy) (ImpedanceHandle handle) <br> |
|  ImpedanceHandle | [**Impedance\_create**](#function-impedance_create) (ConnectionHandle connection, double resistance, double capacitance) <br> |
|  void | [**Impedance\_destroy**](#function-impedance_destroy) (ImpedanceHandle handle) <br> |
|  bool | [**Impedance\_equal**](#function-impedance_equal) (ImpedanceHandle handle, ImpedanceHandle other) <br> |
|  ImpedanceHandle | [**Impedance\_from\_json\_string**](#function-impedance_from_json_string) (StringHandle json) <br> |
|  bool | [**Impedance\_not\_equal**](#function-impedance_not_equal) (ImpedanceHandle handle, ImpedanceHandle other) <br> |
|  double | [**Impedance\_resistance**](#function-impedance_resistance) (ImpedanceHandle handle) <br>_Gets the resistance of the impedance._  |
|  StringHandle | [**Impedance\_to\_json\_string**](#function-impedance_to_json_string) (ImpedanceHandle handle) <br> |




























## Public Types Documentation




### typedef ImpedanceHandle 

```C++
typedef void* ImpedanceHandle;
```




<hr>
## Public Functions Documentation




### function Impedance\_capacitance 

_Gets the capacitance of the impedance._ 
```C++
double Impedance_capacitance (
    ImpedanceHandle handle
) 
```





**Returns:**

The capacitance in farads 





        

<hr>



### function Impedance\_connection 

_Gets the connection leading to the fridge with this impedance._ 
```C++
ConnectionHandle Impedance_connection (
    ImpedanceHandle handle
) 
```





**Returns:**

A shared pointer to the BaseConnection 





        

<hr>



### function Impedance\_copy 

```C++
ImpedanceHandle Impedance_copy (
    ImpedanceHandle handle
) 
```




<hr>



### function Impedance\_create 

```C++
ImpedanceHandle Impedance_create (
    ConnectionHandle connection,
    double resistance,
    double capacitance
) 
```




<hr>



### function Impedance\_destroy 

```C++
void Impedance_destroy (
    ImpedanceHandle handle
) 
```




<hr>



### function Impedance\_equal 

```C++
bool Impedance_equal (
    ImpedanceHandle handle,
    ImpedanceHandle other
) 
```




<hr>



### function Impedance\_from\_json\_string 

```C++
ImpedanceHandle Impedance_from_json_string (
    StringHandle json
) 
```




<hr>



### function Impedance\_not\_equal 

```C++
bool Impedance_not_equal (
    ImpedanceHandle handle,
    ImpedanceHandle other
) 
```




<hr>



### function Impedance\_resistance 

_Gets the resistance of the impedance._ 
```C++
double Impedance_resistance (
    ImpedanceHandle handle
) 
```





**Returns:**

The resistance in ohms 





        

<hr>



### function Impedance\_to\_json\_string 

```C++
StringHandle Impedance_to_json_string (
    ImpedanceHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/device_structures/Impedance_c_api.h`

