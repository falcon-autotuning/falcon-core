

# File ListChannel\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListChannel\_c\_api.h**](ListChannel__c__api_8h.md)

[Go to the source code of this file](ListChannel__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListChannelHandle**](#typedef-listchannelhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ChannelHandle | [**ListChannel\_at**](#function-listchannel_at) (ListChannelHandle handle, size\_t idx) <br> |
|  void | [**ListChannel\_clear**](#function-listchannel_clear) (ListChannelHandle handle) <br> |
|  bool | [**ListChannel\_contains**](#function-listchannel_contains) (ListChannelHandle handle, ChannelHandle value) <br> |
|  ListChannelHandle | [**ListChannel\_copy**](#function-listchannel_copy) (ListChannelHandle handle) <br> |
|  ListChannelHandle | [**ListChannel\_create**](#function-listchannel_create) (ChannelHandle \* data, size\_t count) <br> |
|  ListChannelHandle | [**ListChannel\_create\_empty**](#function-listchannel_create_empty) () <br> |
|  void | [**ListChannel\_destroy**](#function-listchannel_destroy) (ListChannelHandle handle) <br> |
|  bool | [**ListChannel\_empty**](#function-listchannel_empty) (ListChannelHandle handle) <br> |
|  bool | [**ListChannel\_equal**](#function-listchannel_equal) (ListChannelHandle handle, ListChannelHandle other) <br> |
|  void | [**ListChannel\_erase\_at**](#function-listchannel_erase_at) (ListChannelHandle handle, size\_t idx) <br> |
|  ListChannelHandle | [**ListChannel\_fill\_value**](#function-listchannel_fill_value) (size\_t count, ChannelHandle value) <br> |
|  ListChannelHandle | [**ListChannel\_from\_json\_string**](#function-listchannel_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListChannel\_index**](#function-listchannel_index) (ListChannelHandle handle, ChannelHandle value) <br> |
|  ListChannelHandle | [**ListChannel\_intersection**](#function-listchannel_intersection) (ListChannelHandle handle, ListChannelHandle other) <br> |
|  size\_t | [**ListChannel\_items**](#function-listchannel_items) (ListChannelHandle handle, ChannelHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListChannel\_not\_equal**](#function-listchannel_not_equal) (ListChannelHandle handle, ListChannelHandle other) <br> |
|  void | [**ListChannel\_push\_back**](#function-listchannel_push_back) (ListChannelHandle handle, ChannelHandle value) <br> |
|  size\_t | [**ListChannel\_size**](#function-listchannel_size) (ListChannelHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListChannel\_to\_json\_string**](#function-listchannel_to_json_string) (ListChannelHandle handle) <br> |




























## Public Types Documentation




### typedef ListChannelHandle 

```C++
typedef void* ListChannelHandle;
```




<hr>
## Public Functions Documentation




### function ListChannel\_at 

```C++
ChannelHandle ListChannel_at (
    ListChannelHandle handle,
    size_t idx
) 
```




<hr>



### function ListChannel\_clear 

```C++
void ListChannel_clear (
    ListChannelHandle handle
) 
```




<hr>



### function ListChannel\_contains 

```C++
bool ListChannel_contains (
    ListChannelHandle handle,
    ChannelHandle value
) 
```




<hr>



### function ListChannel\_copy 

```C++
ListChannelHandle ListChannel_copy (
    ListChannelHandle handle
) 
```




<hr>



### function ListChannel\_create 

```C++
ListChannelHandle ListChannel_create (
    ChannelHandle * data,
    size_t count
) 
```




<hr>



### function ListChannel\_create\_empty 

```C++
ListChannelHandle ListChannel_create_empty () 
```




<hr>



### function ListChannel\_destroy 

```C++
void ListChannel_destroy (
    ListChannelHandle handle
) 
```




<hr>



### function ListChannel\_empty 

```C++
bool ListChannel_empty (
    ListChannelHandle handle
) 
```




<hr>



### function ListChannel\_equal 

```C++
bool ListChannel_equal (
    ListChannelHandle handle,
    ListChannelHandle other
) 
```




<hr>



### function ListChannel\_erase\_at 

```C++
void ListChannel_erase_at (
    ListChannelHandle handle,
    size_t idx
) 
```




<hr>



### function ListChannel\_fill\_value 

```C++
ListChannelHandle ListChannel_fill_value (
    size_t count,
    ChannelHandle value
) 
```




<hr>



### function ListChannel\_from\_json\_string 

```C++
ListChannelHandle ListChannel_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListChannel\_index 

```C++
size_t ListChannel_index (
    ListChannelHandle handle,
    ChannelHandle value
) 
```




<hr>



### function ListChannel\_intersection 

```C++
ListChannelHandle ListChannel_intersection (
    ListChannelHandle handle,
    ListChannelHandle other
) 
```




<hr>



### function ListChannel\_items 

```C++
size_t ListChannel_items (
    ListChannelHandle handle,
    ChannelHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListChannel\_not\_equal 

```C++
bool ListChannel_not_equal (
    ListChannelHandle handle,
    ListChannelHandle other
) 
```




<hr>



### function ListChannel\_push\_back 

```C++
void ListChannel_push_back (
    ListChannelHandle handle,
    ChannelHandle value
) 
```




<hr>



### function ListChannel\_size 

```C++
size_t ListChannel_size (
    ListChannelHandle handle
) 
```




<hr>



### function ListChannel\_to\_json\_string 

```C++
StringHandle ListChannel_to_json_string (
    ListChannelHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListChannel_c_api.h`

