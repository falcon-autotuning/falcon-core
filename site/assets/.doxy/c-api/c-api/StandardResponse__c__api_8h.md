

# File StandardResponse\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**StandardResponse\_c\_api.h**](StandardResponse__c__api_8h.md)

[Go to the source code of this file](StandardResponse__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**StandardResponseHandle**](#typedef-standardresponsehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  StandardResponseHandle | [**StandardResponse\_copy**](#function-standardresponse_copy) (StandardResponseHandle handle) <br> |
|  StandardResponseHandle | [**StandardResponse\_create**](#function-standardresponse_create) (StringHandle message) <br> |
|  void | [**StandardResponse\_destroy**](#function-standardresponse_destroy) (StandardResponseHandle handle) <br> |
|  bool | [**StandardResponse\_equal**](#function-standardresponse_equal) (StandardResponseHandle handle, StandardResponseHandle other) <br> |
|  StandardResponseHandle | [**StandardResponse\_from\_json\_string**](#function-standardresponse_from_json_string) (StringHandle json) <br> |
|  StringHandle | [**StandardResponse\_message**](#function-standardresponse_message) (StandardResponseHandle handle) <br> |
|  bool | [**StandardResponse\_not\_equal**](#function-standardresponse_not_equal) (StandardResponseHandle handle, StandardResponseHandle other) <br> |
|  StringHandle | [**StandardResponse\_to\_json\_string**](#function-standardresponse_to_json_string) (StandardResponseHandle handle) <br> |




























## Public Types Documentation




### typedef StandardResponseHandle 

```C++
typedef void* StandardResponseHandle;
```




<hr>
## Public Functions Documentation




### function StandardResponse\_copy 

```C++
StandardResponseHandle StandardResponse_copy (
    StandardResponseHandle handle
) 
```




<hr>



### function StandardResponse\_create 

```C++
StandardResponseHandle StandardResponse_create (
    StringHandle message
) 
```




<hr>



### function StandardResponse\_destroy 

```C++
void StandardResponse_destroy (
    StandardResponseHandle handle
) 
```




<hr>



### function StandardResponse\_equal 

```C++
bool StandardResponse_equal (
    StandardResponseHandle handle,
    StandardResponseHandle other
) 
```




<hr>



### function StandardResponse\_from\_json\_string 

```C++
StandardResponseHandle StandardResponse_from_json_string (
    StringHandle json
) 
```




<hr>



### function StandardResponse\_message 

```C++
StringHandle StandardResponse_message (
    StandardResponseHandle handle
) 
```




<hr>



### function StandardResponse\_not\_equal 

```C++
bool StandardResponse_not_equal (
    StandardResponseHandle handle,
    StandardResponseHandle other
) 
```




<hr>



### function StandardResponse\_to\_json\_string 

```C++
StringHandle StandardResponse_to_json_string (
    StandardResponseHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/messages/StandardResponse_c_api.h`

