

# File GateGeometryArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**GateGeometryArray1D\_c\_api.h**](GateGeometryArray1D__c__api_8h.md)

[Go to the source code of this file](GateGeometryArray1D__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h"`
* `#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h"`
* `#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**GateGeometryArray1DHandle**](#typedef-gategeometryarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DotGatesWithNeighborsHandle | [**GateGeometryArray1D\_all\_dot\_gates**](#function-gategeometryarray1d_all_dot_gates) (GateGeometryArray1DHandle handle) <br>_Gets all of the dot gates in the geometry._  |
|  void | [**GateGeometryArray1D\_append\_central\_gate**](#function-gategeometryarray1d_append_central_gate) (GateGeometryArray1DHandle handle, ConnectionHandle left\_neighbor, ConnectionHandle selected\_gate, ConnectionHandle right\_neighbor) <br>_Appends a central gate to the geometry._  |
|  DotGatesWithNeighborsHandle | [**GateGeometryArray1D\_central\_dot\_gates**](#function-gategeometryarray1d_central_dot_gates) (GateGeometryArray1DHandle handle) <br>_Gets the central gates with localities._  |
|  GateGeometryArray1DHandle | [**GateGeometryArray1D\_copy**](#function-gategeometryarray1d_copy) (GateGeometryArray1DHandle handle) <br> |
|  GateGeometryArray1DHandle | [**GateGeometryArray1D\_create**](#function-gategeometryarray1d_create) (ConnectionsHandle lineararray, ConnectionsHandle screening\_gates) <br> |
|  void | [**GateGeometryArray1D\_destroy**](#function-gategeometryarray1d_destroy) (GateGeometryArray1DHandle handle) <br> |
|  bool | [**GateGeometryArray1D\_equal**](#function-gategeometryarray1d_equal) (GateGeometryArray1DHandle handle, GateGeometryArray1DHandle other) <br> |
|  GateGeometryArray1DHandle | [**GateGeometryArray1D\_from\_json\_string**](#function-gategeometryarray1d_from_json_string) (StringHandle json) <br> |
|  DotGateWithNeighborsHandle | [**GateGeometryArray1D\_left\_barrier**](#function-gategeometryarray1d_left_barrier) (GateGeometryArray1DHandle handle) <br>_Gets the leftmost barrier gate in the array._  |
|  LeftReservoirWithImplantedOhmicHandle | [**GateGeometryArray1D\_left\_reservoir**](#function-gategeometryarray1d_left_reservoir) (GateGeometryArray1DHandle handle) <br>_Gets the left reservoir with implanted ohmic contact._  |
|  ConnectionsHandle | [**GateGeometryArray1D\_linear\_array**](#function-gategeometryarray1d_linear_array) (GateGeometryArray1DHandle handle) <br> |
|  bool | [**GateGeometryArray1D\_not\_equal**](#function-gategeometryarray1d_not_equal) (GateGeometryArray1DHandle handle, GateGeometryArray1DHandle other) <br> |
|  ConnectionsHandle | [**GateGeometryArray1D\_ohmics**](#function-gategeometryarray1d_ohmics) (GateGeometryArray1DHandle handle) <br>_Gets the ohmics attached the the quantum dot geometry._  |
|  ConnectionsHandle | [**GateGeometryArray1D\_query\_neighbors**](#function-gategeometryarray1d_query_neighbors) (GateGeometryArray1DHandle handle, ConnectionHandle gate) <br>_Queries the neighbors of a gate._  |
|  ConnectionsHandle | [**GateGeometryArray1D\_raw\_central\_gates**](#function-gategeometryarray1d_raw_central_gates) (GateGeometryArray1DHandle handle) <br>_Gets the central gates without localities._  |
|  DotGateWithNeighborsHandle | [**GateGeometryArray1D\_right\_barrier**](#function-gategeometryarray1d_right_barrier) (GateGeometryArray1DHandle handle) <br>_Gets the rightmost barrier gate in the array._  |
|  RightReservoirWithImplantedOhmicHandle | [**GateGeometryArray1D\_right\_reservoir**](#function-gategeometryarray1d_right_reservoir) (GateGeometryArray1DHandle handle) <br>_Gets the right reservoir with implanted ohmic contact._  |
|  ConnectionsHandle | [**GateGeometryArray1D\_screening\_gates**](#function-gategeometryarray1d_screening_gates) (GateGeometryArray1DHandle handle) <br>_Gets the screening gates in the geometry._  |
|  StringHandle | [**GateGeometryArray1D\_to\_json\_string**](#function-gategeometryarray1d_to_json_string) (GateGeometryArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef GateGeometryArray1DHandle 

```C++
typedef void* GateGeometryArray1DHandle;
```




<hr>
## Public Functions Documentation




### function GateGeometryArray1D\_all\_dot\_gates 

_Gets all of the dot gates in the geometry._ 
```C++
DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

A collection of all dot gates in the array with localities. 





        

<hr>



### function GateGeometryArray1D\_append\_central\_gate 

_Appends a central gate to the geometry._ 
```C++
void GateGeometryArray1D_append_central_gate (
    GateGeometryArray1DHandle handle,
    ConnectionHandle left_neighbor,
    ConnectionHandle selected_gate,
    ConnectionHandle right_neighbor
) 
```





**Parameters:**


* `gate` The gate to append. 




        

<hr>



### function GateGeometryArray1D\_central\_dot\_gates 

_Gets the central gates with localities._ 
```C++
DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The central gates with localities. 





        

<hr>



### function GateGeometryArray1D\_copy 

```C++
GateGeometryArray1DHandle GateGeometryArray1D_copy (
    GateGeometryArray1DHandle handle
) 
```




<hr>



### function GateGeometryArray1D\_create 

```C++
GateGeometryArray1DHandle GateGeometryArray1D_create (
    ConnectionsHandle lineararray,
    ConnectionsHandle screening_gates
) 
```




<hr>



### function GateGeometryArray1D\_destroy 

```C++
void GateGeometryArray1D_destroy (
    GateGeometryArray1DHandle handle
) 
```




<hr>



### function GateGeometryArray1D\_equal 

```C++
bool GateGeometryArray1D_equal (
    GateGeometryArray1DHandle handle,
    GateGeometryArray1DHandle other
) 
```




<hr>



### function GateGeometryArray1D\_from\_json\_string 

```C++
GateGeometryArray1DHandle GateGeometryArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function GateGeometryArray1D\_left\_barrier 

_Gets the leftmost barrier gate in the array._ 
```C++
DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The leftmost barrier gate. 





        

<hr>



### function GateGeometryArray1D\_left\_reservoir 

_Gets the left reservoir with implanted ohmic contact._ 
```C++
LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The left reservoir with implanted ohmic contact. 





        

<hr>



### function GateGeometryArray1D\_linear\_array 

```C++
ConnectionsHandle GateGeometryArray1D_linear_array (
    GateGeometryArray1DHandle handle
) 
```




<hr>



### function GateGeometryArray1D\_not\_equal 

```C++
bool GateGeometryArray1D_not_equal (
    GateGeometryArray1DHandle handle,
    GateGeometryArray1DHandle other
) 
```




<hr>



### function GateGeometryArray1D\_ohmics 

_Gets the ohmics attached the the quantum dot geometry._ 
```C++
ConnectionsHandle GateGeometryArray1D_ohmics (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The ohmics attached to the quantum dot geometry. 





        

<hr>



### function GateGeometryArray1D\_query\_neighbors 

_Queries the neighbors of a gate._ 
```C++
ConnectionsHandle GateGeometryArray1D_query_neighbors (
    GateGeometryArray1DHandle handle,
    ConnectionHandle gate
) 
```





**Parameters:**


* `gate` The gate to query neighbors for 



**Returns:**

The collection of neighboring gates 





        

<hr>



### function GateGeometryArray1D\_raw\_central\_gates 

_Gets the central gates without localities._ 
```C++
ConnectionsHandle GateGeometryArray1D_raw_central_gates (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The central gates without localities. 





        

<hr>



### function GateGeometryArray1D\_right\_barrier 

_Gets the rightmost barrier gate in the array._ 
```C++
DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The rightmost barrier gate. 





        

<hr>



### function GateGeometryArray1D\_right\_reservoir 

_Gets the right reservoir with implanted ohmic contact._ 
```C++
RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The right reservoir with implanted ohmic contact. 





        

<hr>



### function GateGeometryArray1D\_screening\_gates 

_Gets the screening gates in the geometry._ 
```C++
ConnectionsHandle GateGeometryArray1D_screening_gates (
    GateGeometryArray1DHandle handle
) 
```





**Returns:**

The screening gates in the geometry. 





        

<hr>



### function GateGeometryArray1D\_to\_json\_string 

```C++
StringHandle GateGeometryArray1D_to_json_string (
    GateGeometryArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h`

