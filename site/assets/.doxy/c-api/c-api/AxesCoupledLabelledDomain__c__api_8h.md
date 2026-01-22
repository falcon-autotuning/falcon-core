

# File AxesCoupledLabelledDomain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesCoupledLabelledDomain\_c\_api.h**](AxesCoupledLabelledDomain__c__api_8h.md)

[Go to the source code of this file](AxesCoupledLabelledDomain__c__api_8h_source.md)



* `#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"`
* `#include "falcon_core/generic/ListCoupledLabelledDomain_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesCoupledLabelledDomainHandle**](#typedef-axescoupledlabelleddomainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  CoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_at**](#function-axescoupledlabelleddomain_at) (AxesCoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  void | [**AxesCoupledLabelledDomain\_clear**](#function-axescoupledlabelleddomain_clear) (AxesCoupledLabelledDomainHandle handle) <br> |
|  bool | [**AxesCoupledLabelledDomain\_contains**](#function-axescoupledlabelleddomain_contains) (AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  AxesCoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_copy**](#function-axescoupledlabelleddomain_copy) (AxesCoupledLabelledDomainHandle handle) <br> |
|  AxesCoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_create**](#function-axescoupledlabelleddomain_create) (ListCoupledLabelledDomainHandle data) <br> |
|  AxesCoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_create\_empty**](#function-axescoupledlabelleddomain_create_empty) () <br> |
|  void | [**AxesCoupledLabelledDomain\_destroy**](#function-axescoupledlabelleddomain_destroy) (AxesCoupledLabelledDomainHandle handle) <br> |
|  bool | [**AxesCoupledLabelledDomain\_empty**](#function-axescoupledlabelleddomain_empty) (AxesCoupledLabelledDomainHandle handle) <br> |
|  bool | [**AxesCoupledLabelledDomain\_equal**](#function-axescoupledlabelleddomain_equal) (AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) <br> |
|  void | [**AxesCoupledLabelledDomain\_erase\_at**](#function-axescoupledlabelleddomain_erase_at) (AxesCoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  AxesCoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_from\_json\_string**](#function-axescoupledlabelleddomain_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesCoupledLabelledDomain\_index**](#function-axescoupledlabelleddomain_index) (AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  AxesCoupledLabelledDomainHandle | [**AxesCoupledLabelledDomain\_intersection**](#function-axescoupledlabelleddomain_intersection) (AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) <br> |
|  size\_t | [**AxesCoupledLabelledDomain\_items**](#function-axescoupledlabelleddomain_items) (AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesCoupledLabelledDomain\_not\_equal**](#function-axescoupledlabelleddomain_not_equal) (AxesCoupledLabelledDomainHandle handle, AxesCoupledLabelledDomainHandle other) <br> |
|  void | [**AxesCoupledLabelledDomain\_push\_back**](#function-axescoupledlabelleddomain_push_back) (AxesCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  size\_t | [**AxesCoupledLabelledDomain\_size**](#function-axescoupledlabelleddomain_size) (AxesCoupledLabelledDomainHandle handle) <br> |
|  StringHandle | [**AxesCoupledLabelledDomain\_to\_json\_string**](#function-axescoupledlabelleddomain_to_json_string) (AxesCoupledLabelledDomainHandle handle) <br> |




























## Public Types Documentation




### typedef AxesCoupledLabelledDomainHandle 

```C++
typedef void* AxesCoupledLabelledDomainHandle;
```




<hr>
## Public Functions Documentation




### function AxesCoupledLabelledDomain\_at 

```C++
CoupledLabelledDomainHandle AxesCoupledLabelledDomain_at (
    AxesCoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function AxesCoupledLabelledDomain\_clear 

```C++
void AxesCoupledLabelledDomain_clear (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>



### function AxesCoupledLabelledDomain\_contains 

```C++
bool AxesCoupledLabelledDomain_contains (
    AxesCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function AxesCoupledLabelledDomain\_copy 

```C++
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_copy (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>



### function AxesCoupledLabelledDomain\_create 

```C++
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create (
    ListCoupledLabelledDomainHandle data
) 
```




<hr>



### function AxesCoupledLabelledDomain\_create\_empty 

```C++
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_create_empty () 
```




<hr>



### function AxesCoupledLabelledDomain\_destroy 

```C++
void AxesCoupledLabelledDomain_destroy (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>



### function AxesCoupledLabelledDomain\_empty 

```C++
bool AxesCoupledLabelledDomain_empty (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>



### function AxesCoupledLabelledDomain\_equal 

```C++
bool AxesCoupledLabelledDomain_equal (
    AxesCoupledLabelledDomainHandle handle,
    AxesCoupledLabelledDomainHandle other
) 
```




<hr>



### function AxesCoupledLabelledDomain\_erase\_at 

```C++
void AxesCoupledLabelledDomain_erase_at (
    AxesCoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function AxesCoupledLabelledDomain\_from\_json\_string 

```C++
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesCoupledLabelledDomain\_index 

```C++
size_t AxesCoupledLabelledDomain_index (
    AxesCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function AxesCoupledLabelledDomain\_intersection 

```C++
AxesCoupledLabelledDomainHandle AxesCoupledLabelledDomain_intersection (
    AxesCoupledLabelledDomainHandle handle,
    AxesCoupledLabelledDomainHandle other
) 
```




<hr>



### function AxesCoupledLabelledDomain\_items 

```C++
size_t AxesCoupledLabelledDomain_items (
    AxesCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesCoupledLabelledDomain\_not\_equal 

```C++
bool AxesCoupledLabelledDomain_not_equal (
    AxesCoupledLabelledDomainHandle handle,
    AxesCoupledLabelledDomainHandle other
) 
```




<hr>



### function AxesCoupledLabelledDomain\_push\_back 

```C++
void AxesCoupledLabelledDomain_push_back (
    AxesCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function AxesCoupledLabelledDomain\_size 

```C++
size_t AxesCoupledLabelledDomain_size (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>



### function AxesCoupledLabelledDomain\_to\_json\_string 

```C++
StringHandle AxesCoupledLabelledDomain_to_json_string (
    AxesCoupledLabelledDomainHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesCoupledLabelledDomain_c_api.h`

