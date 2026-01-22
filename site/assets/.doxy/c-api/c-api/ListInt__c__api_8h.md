

# File ListInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListInt\_c\_api.h**](ListInt__c__api_8h.md)

[Go to the source code of this file](ListInt__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListIntHandle**](#typedef-listinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListIntHandle | [**ListInt\_allocate**](#function-listint_allocate) (size\_t count) <br> |
|  int | [**ListInt\_at**](#function-listint_at) (ListIntHandle handle, size\_t idx) <br> |
|  void | [**ListInt\_clear**](#function-listint_clear) (ListIntHandle handle) <br> |
|  bool | [**ListInt\_contains**](#function-listint_contains) (ListIntHandle handle, int value) <br> |
|  ListIntHandle | [**ListInt\_copy**](#function-listint_copy) (ListIntHandle handle) <br> |
|  ListIntHandle | [**ListInt\_create**](#function-listint_create) (int \* data, size\_t count) <br> |
|  ListIntHandle | [**ListInt\_create\_empty**](#function-listint_create_empty) () <br> |
|  void | [**ListInt\_destroy**](#function-listint_destroy) (ListIntHandle handle) <br> |
|  bool | [**ListInt\_empty**](#function-listint_empty) (ListIntHandle handle) <br> |
|  bool | [**ListInt\_equal**](#function-listint_equal) (ListIntHandle handle, ListIntHandle other) <br> |
|  void | [**ListInt\_erase\_at**](#function-listint_erase_at) (ListIntHandle handle, size\_t idx) <br> |
|  ListIntHandle | [**ListInt\_fill\_value**](#function-listint_fill_value) (size\_t count, int value) <br> |
|  ListIntHandle | [**ListInt\_from\_json\_string**](#function-listint_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListInt\_index**](#function-listint_index) (ListIntHandle handle, int value) <br> |
|  ListIntHandle | [**ListInt\_intersection**](#function-listint_intersection) (ListIntHandle handle, ListIntHandle other) <br> |
|  size\_t | [**ListInt\_items**](#function-listint_items) (ListIntHandle handle, int \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListInt\_not\_equal**](#function-listint_not_equal) (ListIntHandle handle, ListIntHandle other) <br> |
|  void | [**ListInt\_push\_back**](#function-listint_push_back) (ListIntHandle handle, int value) <br> |
|  size\_t | [**ListInt\_size**](#function-listint_size) (ListIntHandle handle) <br> |
|  StringHandle | [**ListInt\_to\_json\_string**](#function-listint_to_json_string) (ListIntHandle handle) <br> |




























## Public Types Documentation




### typedef ListIntHandle 

```C++
typedef void* ListIntHandle;
```




<hr>
## Public Functions Documentation




### function ListInt\_allocate 

```C++
ListIntHandle ListInt_allocate (
    size_t count
) 
```




<hr>



### function ListInt\_at 

```C++
int ListInt_at (
    ListIntHandle handle,
    size_t idx
) 
```




<hr>



### function ListInt\_clear 

```C++
void ListInt_clear (
    ListIntHandle handle
) 
```




<hr>



### function ListInt\_contains 

```C++
bool ListInt_contains (
    ListIntHandle handle,
    int value
) 
```




<hr>



### function ListInt\_copy 

```C++
ListIntHandle ListInt_copy (
    ListIntHandle handle
) 
```




<hr>



### function ListInt\_create 

```C++
ListIntHandle ListInt_create (
    int * data,
    size_t count
) 
```




<hr>



### function ListInt\_create\_empty 

```C++
ListIntHandle ListInt_create_empty () 
```




<hr>



### function ListInt\_destroy 

```C++
void ListInt_destroy (
    ListIntHandle handle
) 
```




<hr>



### function ListInt\_empty 

```C++
bool ListInt_empty (
    ListIntHandle handle
) 
```




<hr>



### function ListInt\_equal 

```C++
bool ListInt_equal (
    ListIntHandle handle,
    ListIntHandle other
) 
```




<hr>



### function ListInt\_erase\_at 

```C++
void ListInt_erase_at (
    ListIntHandle handle,
    size_t idx
) 
```




<hr>



### function ListInt\_fill\_value 

```C++
ListIntHandle ListInt_fill_value (
    size_t count,
    int value
) 
```




<hr>



### function ListInt\_from\_json\_string 

```C++
ListIntHandle ListInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListInt\_index 

```C++
size_t ListInt_index (
    ListIntHandle handle,
    int value
) 
```




<hr>



### function ListInt\_intersection 

```C++
ListIntHandle ListInt_intersection (
    ListIntHandle handle,
    ListIntHandle other
) 
```




<hr>



### function ListInt\_items 

```C++
size_t ListInt_items (
    ListIntHandle handle,
    int * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListInt\_not\_equal 

```C++
bool ListInt_not_equal (
    ListIntHandle handle,
    ListIntHandle other
) 
```




<hr>



### function ListInt\_push\_back 

```C++
void ListInt_push_back (
    ListIntHandle handle,
    int value
) 
```




<hr>



### function ListInt\_size 

```C++
size_t ListInt_size (
    ListIntHandle handle
) 
```




<hr>



### function ListInt\_to\_json\_string 

```C++
StringHandle ListInt_to_json_string (
    ListIntHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListInt_c_api.h`

