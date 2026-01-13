

# File String\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**String\_c\_api.h**](String__c__api_8h.md)

[Go to the source code of this file](String__c__api_8h_source.md)



* `#include <stddef.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**string**](structstring.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef struct [**string**](structstring.md) \* | [**StringHandle**](#typedef-stringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  [**StringHandle**](structstring.md) | [**String\_create**](#function-string_create) (const char \* raw, size\_t length) <br> |
|  void | [**String\_destroy**](#function-string_destroy) ([**StringHandle**](structstring.md) handle) <br> |
|  [**StringHandle**](structstring.md) | [**String\_wrap**](#function-string_wrap) (const char \* raw) <br> |




























## Public Types Documentation




### typedef StringHandle 

```C++
typedef struct string* StringHandle;
```




<hr>
## Public Functions Documentation




### function String\_create 

```C++
StringHandle String_create (
    const char * raw,
    size_t length
) 
```




<hr>



### function String\_destroy 

```C++
void String_destroy (
    StringHandle handle
) 
```




<hr>



### function String\_wrap 

```C++
StringHandle String_wrap (
    const char * raw
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/String_c_api.h`

