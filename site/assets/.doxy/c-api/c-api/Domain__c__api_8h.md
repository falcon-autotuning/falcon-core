

# File Domain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**Domain\_c\_api.h**](Domain__c__api_8h.md)

[Go to the source code of this file](Domain__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DomainHandle**](#typedef-domainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**Domain\_center**](#function-domain_center) (DomainHandle handle) <br> |
|  bool | [**Domain\_contains\_domain**](#function-domain_contains_domain) (DomainHandle handle, DomainHandle other) <br>_Check if this domain completely contains another domain._  |
|  DomainHandle | [**Domain\_copy**](#function-domain_copy) (DomainHandle handle) <br> |
|  DomainHandle | [**Domain\_create**](#function-domain_create) (double min\_val, double max\_val, bool lesser\_bound\_contained, bool greater\_bound\_contained) <br> |
|  void | [**Domain\_destroy**](#function-domain_destroy) (DomainHandle handle) <br> |
|  bool | [**Domain\_equal**](#function-domain_equal) (DomainHandle handle, DomainHandle other) <br> |
|  DomainHandle | [**Domain\_from\_json\_string**](#function-domain_from_json_string) (StringHandle json) <br> |
|  double | [**Domain\_greater\_bound**](#function-domain_greater_bound) (DomainHandle handle) <br>_Get the greater bound of the domain._  |
|  bool | [**Domain\_greater\_bound\_contained**](#function-domain_greater_bound_contained) (DomainHandle handle) <br>_Check if the greater bound is contained in the domain._  |
|  bool | [**Domain\_in**](#function-domain_in) (DomainHandle handle, double value) <br>_Check if a value is in the domain._  |
|  DomainHandle | [**Domain\_intersection**](#function-domain_intersection) (DomainHandle handle, DomainHandle other) <br> |
|  bool | [**Domain\_is\_empty**](#function-domain_is_empty) (DomainHandle handle) <br>_Check if the domain is empty._  |
|  double | [**Domain\_lesser\_bound**](#function-domain_lesser_bound) (DomainHandle handle) <br>_Get the lesser bound of the domain._  |
|  bool | [**Domain\_lesser\_bound\_contained**](#function-domain_lesser_bound_contained) (DomainHandle handle) <br>_Check if the lesser bound is contained in the domain._  |
|  bool | [**Domain\_not\_equal**](#function-domain_not_equal) (DomainHandle handle, DomainHandle other) <br> |
|  double | [**Domain\_range**](#function-domain_range) (DomainHandle handle) <br>_Get the size of the domain._  |
|  DomainHandle | [**Domain\_scale**](#function-domain_scale) (DomainHandle handle, double scale) <br>_Scale the domain by a factor._  |
|  DomainHandle | [**Domain\_shift**](#function-domain_shift) (DomainHandle handle, double offset) <br>_Shift the domain by an offset._  |
|  StringHandle | [**Domain\_to\_json\_string**](#function-domain_to_json_string) (DomainHandle handle) <br> |
|  double | [**Domain\_transform**](#function-domain_transform) (DomainHandle handle, DomainHandle other, double value) <br>_Transform a value from this domain to another domain._  |
|  DomainHandle | [**Domain\_union**](#function-domain_union) (DomainHandle handle, DomainHandle other) <br> |




























## Public Types Documentation




### typedef DomainHandle 

```C++
typedef void* DomainHandle;
```




<hr>
## Public Functions Documentation




### function Domain\_center 

```C++
double Domain_center (
    DomainHandle handle
) 
```




<hr>



### function Domain\_contains\_domain 

_Check if this domain completely contains another domain._ 
```C++
bool Domain_contains_domain (
    DomainHandle handle,
    DomainHandle other
) 
```





**Parameters:**


* `other` The other domain. 



**Returns:**

True if this domain contains the other domain, false otherwise. 





        

<hr>



### function Domain\_copy 

```C++
DomainHandle Domain_copy (
    DomainHandle handle
) 
```




<hr>



### function Domain\_create 

```C++
DomainHandle Domain_create (
    double min_val,
    double max_val,
    bool lesser_bound_contained,
    bool greater_bound_contained
) 
```




<hr>



### function Domain\_destroy 

```C++
void Domain_destroy (
    DomainHandle handle
) 
```




<hr>



### function Domain\_equal 

```C++
bool Domain_equal (
    DomainHandle handle,
    DomainHandle other
) 
```




<hr>



### function Domain\_from\_json\_string 

```C++
DomainHandle Domain_from_json_string (
    StringHandle json
) 
```




<hr>



### function Domain\_greater\_bound 

_Get the greater bound of the domain._ 
```C++
double Domain_greater_bound (
    DomainHandle handle
) 
```





**Returns:**

The greater bound. 





        

<hr>



### function Domain\_greater\_bound\_contained 

_Check if the greater bound is contained in the domain._ 
```C++
bool Domain_greater_bound_contained (
    DomainHandle handle
) 
```





**Returns:**

True if the greater bound is contained, false otherwise. 





        

<hr>



### function Domain\_in 

_Check if a value is in the domain._ 
```C++
bool Domain_in (
    DomainHandle handle,
    double value
) 
```





**Parameters:**


* `value` The value to check. 



**Returns:**

True if the value is in the domain, false otherwise. 





        

<hr>



### function Domain\_intersection 

```C++
DomainHandle Domain_intersection (
    DomainHandle handle,
    DomainHandle other
) 
```




<hr>



### function Domain\_is\_empty 

_Check if the domain is empty._ 
```C++
bool Domain_is_empty (
    DomainHandle handle
) 
```





**Returns:**

True if the domain is empty, false otherwise. 





        

<hr>



### function Domain\_lesser\_bound 

_Get the lesser bound of the domain._ 
```C++
double Domain_lesser_bound (
    DomainHandle handle
) 
```





**Returns:**

The lesser bound. 





        

<hr>



### function Domain\_lesser\_bound\_contained 

_Check if the lesser bound is contained in the domain._ 
```C++
bool Domain_lesser_bound_contained (
    DomainHandle handle
) 
```





**Returns:**

True if the lesser bound is contained, false otherwise. 





        

<hr>



### function Domain\_not\_equal 

```C++
bool Domain_not_equal (
    DomainHandle handle,
    DomainHandle other
) 
```




<hr>



### function Domain\_range 

_Get the size of the domain._ 
```C++
double Domain_range (
    DomainHandle handle
) 
```





**Returns:**

The size of the domain. 





        

<hr>



### function Domain\_scale 

_Scale the domain by a factor._ 
```C++
DomainHandle Domain_scale (
    DomainHandle handle,
    double scale
) 
```





**Parameters:**


* `factor` The factor to scale by. 



**Returns:**

A new domain representing the scaled domain. 





        

<hr>



### function Domain\_shift 

_Shift the domain by an offset._ 
```C++
DomainHandle Domain_shift (
    DomainHandle handle,
    double offset
) 
```





**Parameters:**


* `offset` The offset to shift by. 



**Returns:**

A new domain representing the shifted domain. 





        

<hr>



### function Domain\_to\_json\_string 

```C++
StringHandle Domain_to_json_string (
    DomainHandle handle
) 
```




<hr>



### function Domain\_transform 

_Transform a value from this domain to another domain._ 
```C++
double Domain_transform (
    DomainHandle handle,
    DomainHandle other,
    double value
) 
```





**Parameters:**


* `other` The other domain to transform to. 
* `value` The value to transform. 



**Returns:**

The transformed value. 





        

<hr>



### function Domain\_union 

```C++
DomainHandle Domain_union (
    DomainHandle handle,
    DomainHandle other
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/domains/Domain_c_api.h`

