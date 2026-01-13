

# File Channel\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Channel\_c\_api.h**](Channel__c__api_8h.md)

[Go to the source code of this file](Channel__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ChannelHandle**](#typedef-channelhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ChannelHandle | [**Channel\_copy**](#function-channel_copy) (ChannelHandle handle) <br> |
|  ChannelHandle | [**Channel\_create**](#function-channel_create) ([**StringHandle**](structstring.md) name) <br> |
|  void | [**Channel\_destroy**](#function-channel_destroy) (ChannelHandle handle) <br> |
|  bool | [**Channel\_equal**](#function-channel_equal) (ChannelHandle handle, ChannelHandle other) <br> |
|  ChannelHandle | [**Channel\_from\_json\_string**](#function-channel_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**Channel\_name**](#function-channel_name) (ChannelHandle handle) <br> |
|  bool | [**Channel\_not\_equal**](#function-channel_not_equal) (ChannelHandle handle, ChannelHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**Channel\_to\_json\_string**](#function-channel_to_json_string) (ChannelHandle handle) <br> |




























## Public Types Documentation




### typedef ChannelHandle 

```C++
typedef void* ChannelHandle;
```




<hr>
## Public Functions Documentation




### function Channel\_copy 

```C++
ChannelHandle Channel_copy (
    ChannelHandle handle
) 
```




<hr>



### function Channel\_create 

```C++
ChannelHandle Channel_create (
    StringHandle name
) 
```




<hr>



### function Channel\_destroy 

```C++
void Channel_destroy (
    ChannelHandle handle
) 
```




<hr>



### function Channel\_equal 

```C++
bool Channel_equal (
    ChannelHandle handle,
    ChannelHandle other
) 
```




<hr>



### function Channel\_from\_json\_string 

```C++
ChannelHandle Channel_from_json_string (
    StringHandle json
) 
```




<hr>



### function Channel\_name 

```C++
StringHandle Channel_name (
    ChannelHandle handle
) 
```




<hr>



### function Channel\_not\_equal 

```C++
bool Channel_not_equal (
    ChannelHandle handle,
    ChannelHandle other
) 
```




<hr>



### function Channel\_to\_json\_string 

```C++
StringHandle Channel_to_json_string (
    ChannelHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/names/Channel_c_api.h`

