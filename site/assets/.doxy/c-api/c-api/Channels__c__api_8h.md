

# File Channels\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Channels\_c\_api.h**](Channels__c__api_8h.md)

[Go to the source code of this file](Channels__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"`
* `#include "falcon_core/generic/ListChannel_c_api.h"`
* `#include "falcon_core/generic/ListString_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ChannelsHandle**](#typedef-channelshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ChannelHandle | [**Channels\_at**](#function-channels_at) (ChannelsHandle handle, size\_t idx) <br> |
|  void | [**Channels\_clear**](#function-channels_clear) (ChannelsHandle handle) <br> |
|  bool | [**Channels\_contains**](#function-channels_contains) (ChannelsHandle handle, ChannelHandle value) <br> |
|  ChannelsHandle | [**Channels\_copy**](#function-channels_copy) (ChannelsHandle handle) <br> |
|  ChannelsHandle | [**Channels\_create**](#function-channels_create) (ListChannelHandle items) <br> |
|  ChannelsHandle | [**Channels\_create\_empty**](#function-channels_create_empty) () <br> |
|  void | [**Channels\_destroy**](#function-channels_destroy) (ChannelsHandle handle) <br> |
|  bool | [**Channels\_empty**](#function-channels_empty) (ChannelsHandle handle) <br> |
|  bool | [**Channels\_equal**](#function-channels_equal) (ChannelsHandle handle, ChannelsHandle other) <br> |
|  void | [**Channels\_erase\_at**](#function-channels_erase_at) (ChannelsHandle handle, size\_t idx) <br> |
|  ChannelsHandle | [**Channels\_from\_json\_string**](#function-channels_from_json_string) (StringHandle json) <br> |
|  size\_t | [**Channels\_index**](#function-channels_index) (ChannelsHandle handle, ChannelHandle value) <br> |
|  ChannelsHandle | [**Channels\_intersection**](#function-channels_intersection) (ChannelsHandle handle, ChannelsHandle other) <br> |
|  ListStringHandle | [**Channels\_items**](#function-channels_items) (ChannelsHandle handle) <br> |
|  bool | [**Channels\_not\_equal**](#function-channels_not_equal) (ChannelsHandle handle, ChannelsHandle other) <br> |
|  void | [**Channels\_push\_back**](#function-channels_push_back) (ChannelsHandle handle, ChannelHandle value) <br> |
|  size\_t | [**Channels\_size**](#function-channels_size) (ChannelsHandle handle) <br> |
|  StringHandle | [**Channels\_to\_json\_string**](#function-channels_to_json_string) (ChannelsHandle handle) <br> |




























## Public Types Documentation




### typedef ChannelsHandle 

```C++
typedef void* ChannelsHandle;
```




<hr>
## Public Functions Documentation




### function Channels\_at 

```C++
ChannelHandle Channels_at (
    ChannelsHandle handle,
    size_t idx
) 
```




<hr>



### function Channels\_clear 

```C++
void Channels_clear (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_contains 

```C++
bool Channels_contains (
    ChannelsHandle handle,
    ChannelHandle value
) 
```




<hr>



### function Channels\_copy 

```C++
ChannelsHandle Channels_copy (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_create 

```C++
ChannelsHandle Channels_create (
    ListChannelHandle items
) 
```




<hr>



### function Channels\_create\_empty 

```C++
ChannelsHandle Channels_create_empty () 
```




<hr>



### function Channels\_destroy 

```C++
void Channels_destroy (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_empty 

```C++
bool Channels_empty (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_equal 

```C++
bool Channels_equal (
    ChannelsHandle handle,
    ChannelsHandle other
) 
```




<hr>



### function Channels\_erase\_at 

```C++
void Channels_erase_at (
    ChannelsHandle handle,
    size_t idx
) 
```




<hr>



### function Channels\_from\_json\_string 

```C++
ChannelsHandle Channels_from_json_string (
    StringHandle json
) 
```




<hr>



### function Channels\_index 

```C++
size_t Channels_index (
    ChannelsHandle handle,
    ChannelHandle value
) 
```




<hr>



### function Channels\_intersection 

```C++
ChannelsHandle Channels_intersection (
    ChannelsHandle handle,
    ChannelsHandle other
) 
```




<hr>



### function Channels\_items 

```C++
ListStringHandle Channels_items (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_not\_equal 

```C++
bool Channels_not_equal (
    ChannelsHandle handle,
    ChannelsHandle other
) 
```




<hr>



### function Channels\_push\_back 

```C++
void Channels_push_back (
    ChannelsHandle handle,
    ChannelHandle value
) 
```




<hr>



### function Channels\_size 

```C++
size_t Channels_size (
    ChannelsHandle handle
) 
```




<hr>



### function Channels\_to\_json\_string 

```C++
StringHandle Channels_to_json_string (
    ChannelsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/names/Channels_c_api.h`

