

# File ListLabelledDomain\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledDomain\_c\_api.h**](ListLabelledDomain__c__api_8h.md)

[Go to the source code of this file](ListLabelledDomain__c__api_8h_source.md)



* `#include "falcon_core/math/domains/LabelledDomain_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListLabelledDomainHandle**](#typedef-listlabelleddomainhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledDomainHandle | [**ListLabelledDomain\_at**](#function-listlabelleddomain_at) (ListLabelledDomainHandle handle, size\_t idx) <br> |
|  void | [**ListLabelledDomain\_clear**](#function-listlabelleddomain_clear) (ListLabelledDomainHandle handle) <br> |
|  bool | [**ListLabelledDomain\_contains**](#function-listlabelleddomain_contains) (ListLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_copy**](#function-listlabelleddomain_copy) (ListLabelledDomainHandle handle) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_create**](#function-listlabelleddomain_create) (LabelledDomainHandle \* data, size\_t count) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_create\_empty**](#function-listlabelleddomain_create_empty) () <br> |
|  void | [**ListLabelledDomain\_destroy**](#function-listlabelleddomain_destroy) (ListLabelledDomainHandle handle) <br> |
|  bool | [**ListLabelledDomain\_empty**](#function-listlabelleddomain_empty) (ListLabelledDomainHandle handle) <br> |
|  bool | [**ListLabelledDomain\_equal**](#function-listlabelleddomain_equal) (ListLabelledDomainHandle handle, ListLabelledDomainHandle other) <br> |
|  void | [**ListLabelledDomain\_erase\_at**](#function-listlabelleddomain_erase_at) (ListLabelledDomainHandle handle, size\_t idx) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_fill\_value**](#function-listlabelleddomain_fill_value) (size\_t count, LabelledDomainHandle value) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_from\_json\_string**](#function-listlabelleddomain_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListLabelledDomain\_index**](#function-listlabelleddomain_index) (ListLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  ListLabelledDomainHandle | [**ListLabelledDomain\_intersection**](#function-listlabelleddomain_intersection) (ListLabelledDomainHandle handle, ListLabelledDomainHandle other) <br> |
|  size\_t | [**ListLabelledDomain\_items**](#function-listlabelleddomain_items) (ListLabelledDomainHandle handle, LabelledDomainHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListLabelledDomain\_not\_equal**](#function-listlabelleddomain_not_equal) (ListLabelledDomainHandle handle, ListLabelledDomainHandle other) <br> |
|  void | [**ListLabelledDomain\_push\_back**](#function-listlabelleddomain_push_back) (ListLabelledDomainHandle handle, LabelledDomainHandle value) <br> |
|  size\_t | [**ListLabelledDomain\_size**](#function-listlabelleddomain_size) (ListLabelledDomainHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListLabelledDomain\_to\_json\_string**](#function-listlabelleddomain_to_json_string) (ListLabelledDomainHandle handle) <br> |




























## Public Types Documentation




### typedef ListLabelledDomainHandle 

```C++
typedef void* ListLabelledDomainHandle;
```




<hr>
## Public Functions Documentation




### function ListLabelledDomain\_at 

```C++
LabelledDomainHandle ListLabelledDomain_at (
    ListLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledDomain\_clear 

```C++
void ListLabelledDomain_clear (
    ListLabelledDomainHandle handle
) 
```




<hr>



### function ListLabelledDomain\_contains 

```C++
bool ListLabelledDomain_contains (
    ListLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function ListLabelledDomain\_copy 

```C++
ListLabelledDomainHandle ListLabelledDomain_copy (
    ListLabelledDomainHandle handle
) 
```




<hr>



### function ListLabelledDomain\_create 

```C++
ListLabelledDomainHandle ListLabelledDomain_create (
    LabelledDomainHandle * data,
    size_t count
) 
```




<hr>



### function ListLabelledDomain\_create\_empty 

```C++
ListLabelledDomainHandle ListLabelledDomain_create_empty () 
```




<hr>



### function ListLabelledDomain\_destroy 

```C++
void ListLabelledDomain_destroy (
    ListLabelledDomainHandle handle
) 
```




<hr>



### function ListLabelledDomain\_empty 

```C++
bool ListLabelledDomain_empty (
    ListLabelledDomainHandle handle
) 
```




<hr>



### function ListLabelledDomain\_equal 

```C++
bool ListLabelledDomain_equal (
    ListLabelledDomainHandle handle,
    ListLabelledDomainHandle other
) 
```




<hr>



### function ListLabelledDomain\_erase\_at 

```C++
void ListLabelledDomain_erase_at (
    ListLabelledDomainHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledDomain\_fill\_value 

```C++
ListLabelledDomainHandle ListLabelledDomain_fill_value (
    size_t count,
    LabelledDomainHandle value
) 
```




<hr>



### function ListLabelledDomain\_from\_json\_string 

```C++
ListLabelledDomainHandle ListLabelledDomain_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListLabelledDomain\_index 

```C++
size_t ListLabelledDomain_index (
    ListLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function ListLabelledDomain\_intersection 

```C++
ListLabelledDomainHandle ListLabelledDomain_intersection (
    ListLabelledDomainHandle handle,
    ListLabelledDomainHandle other
) 
```




<hr>



### function ListLabelledDomain\_items 

```C++
size_t ListLabelledDomain_items (
    ListLabelledDomainHandle handle,
    LabelledDomainHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListLabelledDomain\_not\_equal 

```C++
bool ListLabelledDomain_not_equal (
    ListLabelledDomainHandle handle,
    ListLabelledDomainHandle other
) 
```




<hr>



### function ListLabelledDomain\_push\_back 

```C++
void ListLabelledDomain_push_back (
    ListLabelledDomainHandle handle,
    LabelledDomainHandle value
) 
```




<hr>



### function ListLabelledDomain\_size 

```C++
size_t ListLabelledDomain_size (
    ListLabelledDomainHandle handle
) 
```




<hr>



### function ListLabelledDomain\_to\_json\_string 

```C++
StringHandle ListLabelledDomain_to_json_string (
    ListLabelledDomainHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListLabelledDomain_c_api.h`

