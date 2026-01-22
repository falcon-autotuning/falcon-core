

# File Discretizer\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**discrete\_spaces**](dir_4135ae89d8b25a1ab40962ee1784aac3.md) **>** [**Discretizer\_c\_api.h**](Discretizer__c__api_8h.md)

[Go to the source code of this file](Discretizer__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/domains/Domain_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DiscretizerHandle**](#typedef-discretizerhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DiscretizerHandle | [**Discretizer\_copy**](#function-discretizer_copy) (DiscretizerHandle handle) <br> |
|  DiscretizerHandle | [**Discretizer\_create\_cartesian\_discretizer**](#function-discretizer_create_cartesian_discretizer) (double delta) <br> |
|  DiscretizerHandle | [**Discretizer\_create\_polar\_discretizer**](#function-discretizer_create_polar_discretizer) (double delta) <br> |
|  double | [**Discretizer\_delta**](#function-discretizer_delta) (DiscretizerHandle handle) <br> |
|  void | [**Discretizer\_destroy**](#function-discretizer_destroy) (DiscretizerHandle handle) <br> |
|  DomainHandle | [**Discretizer\_domain**](#function-discretizer_domain) (DiscretizerHandle handle) <br> |
|  bool | [**Discretizer\_equal**](#function-discretizer_equal) (DiscretizerHandle handle, DiscretizerHandle other) <br> |
|  DiscretizerHandle | [**Discretizer\_from\_json\_string**](#function-discretizer_from_json_string) (StringHandle json) <br> |
|  bool | [**Discretizer\_is\_cartesian**](#function-discretizer_is_cartesian) (DiscretizerHandle handle) <br>_Checks if the current Discretizer is Cartesian._  |
|  bool | [**Discretizer\_is\_polar**](#function-discretizer_is_polar) (DiscretizerHandle handle) <br>_Checks if the current Discretizer is Polar._  |
|  bool | [**Discretizer\_not\_equal**](#function-discretizer_not_equal) (DiscretizerHandle handle, DiscretizerHandle other) <br> |
|  void | [**Discretizer\_set\_delta**](#function-discretizer_set_delta) (DiscretizerHandle handle, double delta) <br> |
|  StringHandle | [**Discretizer\_to\_json\_string**](#function-discretizer_to_json_string) (DiscretizerHandle handle) <br> |




























## Public Types Documentation




### typedef DiscretizerHandle 

```C++
typedef void* DiscretizerHandle;
```




<hr>
## Public Functions Documentation




### function Discretizer\_copy 

```C++
DiscretizerHandle Discretizer_copy (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_create\_cartesian\_discretizer 

```C++
DiscretizerHandle Discretizer_create_cartesian_discretizer (
    double delta
) 
```




<hr>



### function Discretizer\_create\_polar\_discretizer 

```C++
DiscretizerHandle Discretizer_create_polar_discretizer (
    double delta
) 
```




<hr>



### function Discretizer\_delta 

```C++
double Discretizer_delta (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_destroy 

```C++
void Discretizer_destroy (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_domain 

```C++
DomainHandle Discretizer_domain (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_equal 

```C++
bool Discretizer_equal (
    DiscretizerHandle handle,
    DiscretizerHandle other
) 
```




<hr>



### function Discretizer\_from\_json\_string 

```C++
DiscretizerHandle Discretizer_from_json_string (
    StringHandle json
) 
```




<hr>



### function Discretizer\_is\_cartesian 

_Checks if the current Discretizer is Cartesian._ 
```C++
bool Discretizer_is_cartesian (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_is\_polar 

_Checks if the current Discretizer is Polar._ 
```C++
bool Discretizer_is_polar (
    DiscretizerHandle handle
) 
```




<hr>



### function Discretizer\_not\_equal 

```C++
bool Discretizer_not_equal (
    DiscretizerHandle handle,
    DiscretizerHandle other
) 
```




<hr>



### function Discretizer\_set\_delta 

```C++
void Discretizer_set_delta (
    DiscretizerHandle handle,
    double delta
) 
```




<hr>



### function Discretizer\_to\_json\_string 

```C++
StringHandle Discretizer_to_json_string (
    DiscretizerHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/discrete_spaces/Discretizer_c_api.h`

