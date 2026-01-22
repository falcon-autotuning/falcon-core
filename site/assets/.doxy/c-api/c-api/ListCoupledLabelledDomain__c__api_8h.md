

# File ListCoupledLabelledDomain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListCoupledLabelledDomain\_c\_api.h**](ListCoupledLabelledDomain__c__api_8h.md)

[Go to the source code of this file](ListCoupledLabelledDomain__c__api_8h_source.md)



* `#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListCoupledLabelledDomainHandle**](#typedef-listcoupledlabelleddomainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  CoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_at**](#function-listcoupledlabelleddomain_at) (ListCoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  void | [**ListCoupledLabelledDomain\_clear**](#function-listcoupledlabelleddomain_clear) (ListCoupledLabelledDomainHandle handle) <br> |
|  bool | [**ListCoupledLabelledDomain\_contains**](#function-listcoupledlabelleddomain_contains) (ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_copy**](#function-listcoupledlabelleddomain_copy) (ListCoupledLabelledDomainHandle handle) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_create**](#function-listcoupledlabelleddomain_create) (CoupledLabelledDomainHandle \* data, size\_t count) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_create\_empty**](#function-listcoupledlabelleddomain_create_empty) () <br> |
|  void | [**ListCoupledLabelledDomain\_destroy**](#function-listcoupledlabelleddomain_destroy) (ListCoupledLabelledDomainHandle handle) <br> |
|  bool | [**ListCoupledLabelledDomain\_empty**](#function-listcoupledlabelleddomain_empty) (ListCoupledLabelledDomainHandle handle) <br> |
|  bool | [**ListCoupledLabelledDomain\_equal**](#function-listcoupledlabelleddomain_equal) (ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) <br> |
|  void | [**ListCoupledLabelledDomain\_erase\_at**](#function-listcoupledlabelleddomain_erase_at) (ListCoupledLabelledDomainHandle handle, size\_t idx) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_fill\_value**](#function-listcoupledlabelleddomain_fill_value) (size\_t count, CoupledLabelledDomainHandle value) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_from\_json\_string**](#function-listcoupledlabelleddomain_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListCoupledLabelledDomain\_index**](#function-listcoupledlabelleddomain_index) (ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  ListCoupledLabelledDomainHandle | [**ListCoupledLabelledDomain\_intersection**](#function-listcoupledlabelleddomain_intersection) (ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) <br> |
|  size\_t | [**ListCoupledLabelledDomain\_items**](#function-listcoupledlabelleddomain_items) (ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListCoupledLabelledDomain\_not\_equal**](#function-listcoupledlabelleddomain_not_equal) (ListCoupledLabelledDomainHandle handle, ListCoupledLabelledDomainHandle other) <br> |
|  void | [**ListCoupledLabelledDomain\_push\_back**](#function-listcoupledlabelleddomain_push_back) (ListCoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle value) <br> |
|  size\_t | [**ListCoupledLabelledDomain\_size**](#function-listcoupledlabelleddomain_size) (ListCoupledLabelledDomainHandle handle) <br> |
|  StringHandle | [**ListCoupledLabelledDomain\_to\_json\_string**](#function-listcoupledlabelleddomain_to_json_string) (ListCoupledLabelledDomainHandle handle) <br> |




























## Public Types Documentation




### typedef ListCoupledLabelledDomainHandle 

```C++
typedef void* ListCoupledLabelledDomainHandle;
```




<hr>
## Public Functions Documentation




### function ListCoupledLabelledDomain\_at 

```C++
CoupledLabelledDomainHandle ListCoupledLabelledDomain_at (
    ListCoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function ListCoupledLabelledDomain\_clear 

```C++
void ListCoupledLabelledDomain_clear (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>



### function ListCoupledLabelledDomain\_contains 

```C++
bool ListCoupledLabelledDomain_contains (
    ListCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function ListCoupledLabelledDomain\_copy 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_copy (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>



### function ListCoupledLabelledDomain\_create 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create (
    CoupledLabelledDomainHandle * data,
    size_t count
) 
```




<hr>



### function ListCoupledLabelledDomain\_create\_empty 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_create_empty () 
```




<hr>



### function ListCoupledLabelledDomain\_destroy 

```C++
void ListCoupledLabelledDomain_destroy (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>



### function ListCoupledLabelledDomain\_empty 

```C++
bool ListCoupledLabelledDomain_empty (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>



### function ListCoupledLabelledDomain\_equal 

```C++
bool ListCoupledLabelledDomain_equal (
    ListCoupledLabelledDomainHandle handle,
    ListCoupledLabelledDomainHandle other
) 
```




<hr>



### function ListCoupledLabelledDomain\_erase\_at 

```C++
void ListCoupledLabelledDomain_erase_at (
    ListCoupledLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function ListCoupledLabelledDomain\_fill\_value 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_fill_value (
    size_t count,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function ListCoupledLabelledDomain\_from\_json\_string 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListCoupledLabelledDomain\_index 

```C++
size_t ListCoupledLabelledDomain_index (
    ListCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function ListCoupledLabelledDomain\_intersection 

```C++
ListCoupledLabelledDomainHandle ListCoupledLabelledDomain_intersection (
    ListCoupledLabelledDomainHandle handle,
    ListCoupledLabelledDomainHandle other
) 
```




<hr>



### function ListCoupledLabelledDomain\_items 

```C++
size_t ListCoupledLabelledDomain_items (
    ListCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListCoupledLabelledDomain\_not\_equal 

```C++
bool ListCoupledLabelledDomain_not_equal (
    ListCoupledLabelledDomainHandle handle,
    ListCoupledLabelledDomainHandle other
) 
```




<hr>



### function ListCoupledLabelledDomain\_push\_back 

```C++
void ListCoupledLabelledDomain_push_back (
    ListCoupledLabelledDomainHandle handle,
    CoupledLabelledDomainHandle value
) 
```




<hr>



### function ListCoupledLabelledDomain\_size 

```C++
size_t ListCoupledLabelledDomain_size (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>



### function ListCoupledLabelledDomain\_to\_json\_string 

```C++
StringHandle ListCoupledLabelledDomain_to_json_string (
    ListCoupledLabelledDomainHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListCoupledLabelledDomain_c_api.h`

