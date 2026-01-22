

# File RightReservoirWithImplantedOhmic\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**RightReservoirWithImplantedOhmic\_c\_api.h**](RightReservoirWithImplantedOhmic__c__api_8h.md)

[Go to the source code of this file](RightReservoirWithImplantedOhmic__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**RightReservoirWithImplantedOhmicHandle**](#typedef-rightreservoirwithimplantedohmichandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  RightReservoirWithImplantedOhmicHandle | [**RightReservoirWithImplantedOhmic\_copy**](#function-rightreservoirwithimplantedohmic_copy) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  RightReservoirWithImplantedOhmicHandle | [**RightReservoirWithImplantedOhmic\_create**](#function-rightreservoirwithimplantedohmic_create) (StringHandle name, ConnectionHandle left\_neighbor, ConnectionHandle ohmic) <br> |
|  void | [**RightReservoirWithImplantedOhmic\_destroy**](#function-rightreservoirwithimplantedohmic_destroy) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  bool | [**RightReservoirWithImplantedOhmic\_equal**](#function-rightreservoirwithimplantedohmic_equal) (RightReservoirWithImplantedOhmicHandle handle, RightReservoirWithImplantedOhmicHandle other) <br> |
|  RightReservoirWithImplantedOhmicHandle | [**RightReservoirWithImplantedOhmic\_from\_json\_string**](#function-rightreservoirwithimplantedohmic_from_json_string) (StringHandle json) <br> |
|  ConnectionHandle | [**RightReservoirWithImplantedOhmic\_left\_neighbor**](#function-rightreservoirwithimplantedohmic_left_neighbor) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  StringHandle | [**RightReservoirWithImplantedOhmic\_name**](#function-rightreservoirwithimplantedohmic_name) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  bool | [**RightReservoirWithImplantedOhmic\_not\_equal**](#function-rightreservoirwithimplantedohmic_not_equal) (RightReservoirWithImplantedOhmicHandle handle, RightReservoirWithImplantedOhmicHandle other) <br> |
|  ConnectionHandle | [**RightReservoirWithImplantedOhmic\_ohmic**](#function-rightreservoirwithimplantedohmic_ohmic) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  StringHandle | [**RightReservoirWithImplantedOhmic\_to\_json\_string**](#function-rightreservoirwithimplantedohmic_to_json_string) (RightReservoirWithImplantedOhmicHandle handle) <br> |
|  StringHandle | [**RightReservoirWithImplantedOhmic\_type**](#function-rightreservoirwithimplantedohmic_type) (RightReservoirWithImplantedOhmicHandle handle) <br> |




























## Public Types Documentation




### typedef RightReservoirWithImplantedOhmicHandle 

```C++
typedef void* RightReservoirWithImplantedOhmicHandle;
```




<hr>
## Public Functions Documentation




### function RightReservoirWithImplantedOhmic\_copy 

```C++
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_copy (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_create 

```C++
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create (
    StringHandle name,
    ConnectionHandle left_neighbor,
    ConnectionHandle ohmic
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_destroy 

```C++
void RightReservoirWithImplantedOhmic_destroy (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_equal 

```C++
bool RightReservoirWithImplantedOhmic_equal (
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_from\_json\_string 

```C++
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_from_json_string (
    StringHandle json
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_left\_neighbor 

```C++
ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_name 

```C++
StringHandle RightReservoirWithImplantedOhmic_name (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_not\_equal 

```C++
bool RightReservoirWithImplantedOhmic_not_equal (
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_ohmic 

```C++
ConnectionHandle RightReservoirWithImplantedOhmic_ohmic (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_to\_json\_string 

```C++
StringHandle RightReservoirWithImplantedOhmic_to_json_string (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function RightReservoirWithImplantedOhmic\_type 

```C++
StringHandle RightReservoirWithImplantedOhmic_type (
    RightReservoirWithImplantedOhmicHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic_c_api.h`

