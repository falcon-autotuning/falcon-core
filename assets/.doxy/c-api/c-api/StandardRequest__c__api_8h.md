

# File StandardRequest\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**StandardRequest\_c\_api.h**](StandardRequest__c__api_8h.md)

[Go to the source code of this file](StandardRequest__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**StandardRequestHandle**](#typedef-standardrequesthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  StandardRequestHandle | [**StandardRequest\_copy**](#function-standardrequest_copy) (StandardRequestHandle handle) <br> |
|  StandardRequestHandle | [**StandardRequest\_create**](#function-standardrequest_create) ([**StringHandle**](structstring.md) message) <br> |
|  void | [**StandardRequest\_destroy**](#function-standardrequest_destroy) (StandardRequestHandle handle) <br> |
|  bool | [**StandardRequest\_equal**](#function-standardrequest_equal) (StandardRequestHandle handle, StandardRequestHandle other) <br> |
|  StandardRequestHandle | [**StandardRequest\_from\_json\_string**](#function-standardrequest_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  [**StringHandle**](structstring.md) | [**StandardRequest\_message**](#function-standardrequest_message) (StandardRequestHandle handle) <br> |
|  bool | [**StandardRequest\_not\_equal**](#function-standardrequest_not_equal) (StandardRequestHandle handle, StandardRequestHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**StandardRequest\_to\_json\_string**](#function-standardrequest_to_json_string) (StandardRequestHandle handle) <br> |




























## Public Types Documentation




### typedef StandardRequestHandle 

```C++
typedef void* StandardRequestHandle;
```




<hr>
## Public Functions Documentation




### function StandardRequest\_copy 

```C++
StandardRequestHandle StandardRequest_copy (
    StandardRequestHandle handle
) 
```




<hr>



### function StandardRequest\_create 

```C++
StandardRequestHandle StandardRequest_create (
    StringHandle message
) 
```




<hr>



### function StandardRequest\_destroy 

```C++
void StandardRequest_destroy (
    StandardRequestHandle handle
) 
```




<hr>



### function StandardRequest\_equal 

```C++
bool StandardRequest_equal (
    StandardRequestHandle handle,
    StandardRequestHandle other
) 
```




<hr>



### function StandardRequest\_from\_json\_string 

```C++
StandardRequestHandle StandardRequest_from_json_string (
    StringHandle json
) 
```




<hr>



### function StandardRequest\_message 

```C++
StringHandle StandardRequest_message (
    StandardRequestHandle handle
) 
```




<hr>



### function StandardRequest\_not\_equal 

```C++
bool StandardRequest_not_equal (
    StandardRequestHandle handle,
    StandardRequestHandle other
) 
```




<hr>



### function StandardRequest\_to\_json\_string 

```C++
StringHandle StandardRequest_to_json_string (
    StandardRequestHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/messages/StandardRequest_c_api.h`

