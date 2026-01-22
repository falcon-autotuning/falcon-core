

# File Gname\_c\_api.h



[**FileList**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Gname\_c\_api.h**](Gname__c__api_8h.md)

[Go to the source code of this file](Gname__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**GnameHandle**](#typedef-gnamehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  GnameHandle | [**Gname\_copy**](#function-gname_copy) (GnameHandle handle) <br> |
|  GnameHandle | [**Gname\_create**](#function-gname_create) (StringHandle name) <br> |
|  GnameHandle | [**Gname\_create\_from\_num**](#function-gname_create_from_num) (int num) <br> |
|  void | [**Gname\_destroy**](#function-gname_destroy) (GnameHandle handle) <br> |
|  bool | [**Gname\_equal**](#function-gname_equal) (GnameHandle handle, GnameHandle other) <br> |
|  GnameHandle | [**Gname\_from\_json\_string**](#function-gname_from_json_string) (StringHandle json) <br> |
|  StringHandle | [**Gname\_gname**](#function-gname_gname) (GnameHandle handle) <br>_Collect the gname as a string._  |
|  bool | [**Gname\_not\_equal**](#function-gname_not_equal) (GnameHandle handle, GnameHandle other) <br> |
|  StringHandle | [**Gname\_to\_json\_string**](#function-gname_to_json_string) (GnameHandle handle) <br> |




























## Public Types Documentation




### typedef GnameHandle 

```C++
typedef void* GnameHandle;
```




<hr>
## Public Functions Documentation




### function Gname\_copy 

```C++
GnameHandle Gname_copy (
    GnameHandle handle
) 
```




<hr>



### function Gname\_create 

```C++
GnameHandle Gname_create (
    StringHandle name
) 
```




<hr>



### function Gname\_create\_from\_num 

```C++
GnameHandle Gname_create_from_num (
    int num
) 
```




<hr>



### function Gname\_destroy 

```C++
void Gname_destroy (
    GnameHandle handle
) 
```




<hr>



### function Gname\_equal 

```C++
bool Gname_equal (
    GnameHandle handle,
    GnameHandle other
) 
```




<hr>



### function Gname\_from\_json\_string 

```C++
GnameHandle Gname_from_json_string (
    StringHandle json
) 
```




<hr>



### function Gname\_gname 

_Collect the gname as a string._ 
```C++
StringHandle Gname_gname (
    GnameHandle handle
) 
```




<hr>



### function Gname\_not\_equal 

```C++
bool Gname_not_equal (
    GnameHandle handle,
    GnameHandle other
) 
```




<hr>



### function Gname\_to\_json\_string 

```C++
StringHandle Gname_to_json_string (
    GnameHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/autotuner_interfaces/names/Gname_c_api.h`

