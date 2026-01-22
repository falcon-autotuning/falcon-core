

# File CoupledLabelledDomain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**CoupledLabelledDomain\_c\_api.h**](CoupledLabelledDomain__c__api_8h.md)

[Go to the source code of this file](CoupledLabelledDomain__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListLabelledDomain_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"`
* `#include "falcon_core/math/domains/LabelledDomain_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**CoupledLabelledDomainHandle**](#typedef-coupledlabelleddomainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledDomainHandle | [**CoupledLabelledDomain\_at**](#function-coupledlabelleddomain_at) (CoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  void | [**CoupledLabelledDomain\_clear**](#function-coupledlabelleddomain_clear) (CoupledLabelledDomainHandle handle) <br> |
|  LabelledDomainHandle | [**CoupledLabelledDomain\_const\_at**](#function-coupledlabelleddomain_const_at) (CoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  bool | [**CoupledLabelledDomain\_contains**](#function-coupledlabelleddomain_contains) (CoupledLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  CoupledLabelledDomainHandle | [**CoupledLabelledDomain\_copy**](#function-coupledlabelleddomain_copy) (CoupledLabelledDomainHandle handle) <br> |
|  CoupledLabelledDomainHandle | [**CoupledLabelledDomain\_create**](#function-coupledlabelleddomain_create) (ListLabelledDomainHandle items) <br> |
|  CoupledLabelledDomainHandle | [**CoupledLabelledDomain\_create\_empty**](#function-coupledlabelleddomain_create_empty) () <br> |
|  void | [**CoupledLabelledDomain\_destroy**](#function-coupledlabelleddomain_destroy) (CoupledLabelledDomainHandle handle) <br> |
|  ListLabelledDomainHandle | [**CoupledLabelledDomain\_domains**](#function-coupledlabelleddomain_domains) (CoupledLabelledDomainHandle handle) <br>_Get all domains._  |
|  bool | [**CoupledLabelledDomain\_empty**](#function-coupledlabelleddomain_empty) (CoupledLabelledDomainHandle handle) <br> |
|  bool | [**CoupledLabelledDomain\_equal**](#function-coupledlabelleddomain_equal) (CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other) <br> |
|  void | [**CoupledLabelledDomain\_erase\_at**](#function-coupledlabelleddomain_erase_at) (CoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  CoupledLabelledDomainHandle | [**CoupledLabelledDomain\_from\_json\_string**](#function-coupledlabelleddomain_from_json_string) (StringHandle json) <br> |
|  LabelledDomainHandle | [**CoupledLabelledDomain\_get\_domain**](#function-coupledlabelleddomain_get_domain) (CoupledLabelledDomainHandle handle, InstrumentPortHandle search) <br>_Get domain by label._  |
|  size\_t | [**CoupledLabelledDomain\_index**](#function-coupledlabelleddomain_index) (CoupledLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  CoupledLabelledDomainHandle | [**CoupledLabelledDomain\_intersection**](#function-coupledlabelleddomain_intersection) (CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other) <br> |
|  ListLabelledDomainHandle | [**CoupledLabelledDomain\_items**](#function-coupledlabelleddomain_items) (CoupledLabelledDomainHandle handle) <br> |
|  PortsHandle | [**CoupledLabelledDomain\_labels**](#function-coupledlabelleddomain_labels) (CoupledLabelledDomainHandle handle) <br>_Get all labels._  |
|  bool | [**CoupledLabelledDomain\_not\_equal**](#function-coupledlabelleddomain_not_equal) (CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other) <br> |
|  void | [**CoupledLabelledDomain\_push\_back**](#function-coupledlabelleddomain_push_back) (CoupledLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  size\_t | [**CoupledLabelledDomain\_size**](#function-coupledlabelleddomain_size) (CoupledLabelledDomainHandle handle) <br> |
|  StringHandle | [**CoupledLabelledDomain\_to\_json\_string**](#function-coupledlabelleddomain_to_json_string) (CoupledLabelledDomainHandle handle) <br> |




























## Public Types Documentation




### typedef CoupledLabelledDomainHandle 

```C++
typedef void* CoupledLabelledDomainHandle;
```




<hr>
## Public Functions Documentation




### function CoupledLabelledDomain\_at 

```C++
LabelledDomainHandle CoupledLabelledDomain_at (
    CoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function CoupledLabelledDomain\_clear 

```C++
void CoupledLabelledDomain_clear (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_const\_at 

```C++
LabelledDomainHandle CoupledLabelledDomain_const_at (
    CoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function CoupledLabelledDomain\_contains 

```C++
bool CoupledLabelledDomain_contains (
    CoupledLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function CoupledLabelledDomain\_copy 

```C++
CoupledLabelledDomainHandle CoupledLabelledDomain_copy (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_create 

```C++
CoupledLabelledDomainHandle CoupledLabelledDomain_create (
    ListLabelledDomainHandle items
) 
```




<hr>



### function CoupledLabelledDomain\_create\_empty 

```C++
CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty () 
```




<hr>



### function CoupledLabelledDomain\_destroy 

```C++
void CoupledLabelledDomain_destroy (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_domains 

_Get all domains._ 
```C++
ListLabelledDomainHandle CoupledLabelledDomain_domains (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_empty 

```C++
bool CoupledLabelledDomain_empty (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_equal 

```C++
bool CoupledLabelledDomain_equal (
    CoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle other
) 
```




<hr>



### function CoupledLabelledDomain\_erase\_at 

```C++
void CoupledLabelledDomain_erase_at (
    CoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function CoupledLabelledDomain\_from\_json\_string 

```C++
CoupledLabelledDomainHandle CoupledLabelledDomain_from_json_string (
    StringHandle json
) 
```




<hr>



### function CoupledLabelledDomain\_get\_domain 

_Get domain by label._ 
```C++
LabelledDomainHandle CoupledLabelledDomain_get_domain (
    CoupledLabelledDomainHandle handle,
    InstrumentPortHandle search
) 
```





**Parameters:**


* `search` Shared pointer to label to search for. 



**Returns:**

Shared pointer to the matching domain. 




**Exception:**


* `std::runtime_error` if not found. 




        

<hr>



### function CoupledLabelledDomain\_index 

```C++
size_t CoupledLabelledDomain_index (
    CoupledLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function CoupledLabelledDomain\_intersection 

```C++
CoupledLabelledDomainHandle CoupledLabelledDomain_intersection (
    CoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle other
) 
```




<hr>



### function CoupledLabelledDomain\_items 

```C++
ListLabelledDomainHandle CoupledLabelledDomain_items (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_labels 

_Get all labels._ 
```C++
PortsHandle CoupledLabelledDomain_labels (
    CoupledLabelledDomainHandle handle
) 
```





**Returns:**

Vector of shared pointers to labels. 





        

<hr>



### function CoupledLabelledDomain\_not\_equal 

```C++
bool CoupledLabelledDomain_not_equal (
    CoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle other
) 
```




<hr>



### function CoupledLabelledDomain\_push\_back 

```C++
void CoupledLabelledDomain_push_back (
    CoupledLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function CoupledLabelledDomain\_size 

```C++
size_t CoupledLabelledDomain_size (
    CoupledLabelledDomainHandle handle
) 
```




<hr>



### function CoupledLabelledDomain\_to\_json\_string 

```C++
StringHandle CoupledLabelledDomain_to_json_string (
    CoupledLabelledDomainHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/domains/CoupledLabelledDomain_c_api.h`

