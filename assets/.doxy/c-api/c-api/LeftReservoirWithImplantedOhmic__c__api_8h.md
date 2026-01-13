

# File LeftReservoirWithImplantedOhmic\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**LeftReservoirWithImplantedOhmic\_c\_api.h**](LeftReservoirWithImplantedOhmic__c__api_8h.md)

[Go to the source code of this file](LeftReservoirWithImplantedOhmic__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LeftReservoirWithImplantedOhmicHandle**](#typedef-leftreservoirwithimplantedohmichandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LeftReservoirWithImplantedOhmicHandle | [**LeftReservoirWithImplantedOhmic\_copy**](#function-leftreservoirwithimplantedohmic_copy) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  LeftReservoirWithImplantedOhmicHandle | [**LeftReservoirWithImplantedOhmic\_create**](#function-leftreservoirwithimplantedohmic_create) ([**StringHandle**](structstring.md) name, ConnectionHandle right\_neighbor, ConnectionHandle ohmic) <br> |
|  void | [**LeftReservoirWithImplantedOhmic\_destroy**](#function-leftreservoirwithimplantedohmic_destroy) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  bool | [**LeftReservoirWithImplantedOhmic\_equal**](#function-leftreservoirwithimplantedohmic_equal) (LeftReservoirWithImplantedOhmicHandle handle, LeftReservoirWithImplantedOhmicHandle other) <br> |
|  LeftReservoirWithImplantedOhmicHandle | [**LeftReservoirWithImplantedOhmic\_from\_json\_string**](#function-leftreservoirwithimplantedohmic_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**LeftReservoirWithImplantedOhmic\_name**](#function-leftreservoirwithimplantedohmic_name) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  bool | [**LeftReservoirWithImplantedOhmic\_not\_equal**](#function-leftreservoirwithimplantedohmic_not_equal) (LeftReservoirWithImplantedOhmicHandle handle, LeftReservoirWithImplantedOhmicHandle other) <br> |
|  ConnectionHandle | [**LeftReservoirWithImplantedOhmic\_ohmic**](#function-leftreservoirwithimplantedohmic_ohmic) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  ConnectionHandle | [**LeftReservoirWithImplantedOhmic\_right\_neighbor**](#function-leftreservoirwithimplantedohmic_right_neighbor) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**LeftReservoirWithImplantedOhmic\_to\_json\_string**](#function-leftreservoirwithimplantedohmic_to_json_string) (LeftReservoirWithImplantedOhmicHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**LeftReservoirWithImplantedOhmic\_type**](#function-leftreservoirwithimplantedohmic_type) (LeftReservoirWithImplantedOhmicHandle handle) <br> |




























## Public Types Documentation




### typedef LeftReservoirWithImplantedOhmicHandle 

```C++
typedef void* LeftReservoirWithImplantedOhmicHandle;
```




<hr>
## Public Functions Documentation




### function LeftReservoirWithImplantedOhmic\_copy 

```C++
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_copy (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_create 

```C++
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create (
    StringHandle name,
    ConnectionHandle right_neighbor,
    ConnectionHandle ohmic
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_destroy 

```C++
void LeftReservoirWithImplantedOhmic_destroy (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_equal 

```C++
bool LeftReservoirWithImplantedOhmic_equal (
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_from\_json\_string 

```C++
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_from_json_string (
    StringHandle json
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_name 

```C++
StringHandle LeftReservoirWithImplantedOhmic_name (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_not\_equal 

```C++
bool LeftReservoirWithImplantedOhmic_not_equal (
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_ohmic 

```C++
ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_right\_neighbor 

```C++
ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_to\_json\_string 

```C++
StringHandle LeftReservoirWithImplantedOhmic_to_json_string (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>



### function LeftReservoirWithImplantedOhmic\_type 

```C++
StringHandle LeftReservoirWithImplantedOhmic_type (
    LeftReservoirWithImplantedOhmicHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic_c_api.h`

