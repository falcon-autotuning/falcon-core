

# File Impedances\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Impedances\_c\_api.h**](Impedances__c__api_8h.md)

[Go to the source code of this file](Impedances__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListImpedance_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ImpedancesHandle**](#typedef-impedanceshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ImpedanceHandle | [**Impedances\_at**](#function-impedances_at) (ImpedancesHandle handle, size\_t idx) <br> |
|  void | [**Impedances\_clear**](#function-impedances_clear) (ImpedancesHandle handle) <br> |
|  bool | [**Impedances\_contains**](#function-impedances_contains) (ImpedancesHandle handle, ImpedanceHandle value) <br> |
|  ImpedancesHandle | [**Impedances\_copy**](#function-impedances_copy) (ImpedancesHandle handle) <br> |
|  ImpedancesHandle | [**Impedances\_create**](#function-impedances_create) (ListImpedanceHandle items) <br> |
|  ImpedancesHandle | [**Impedances\_create\_empty**](#function-impedances_create_empty) () <br> |
|  void | [**Impedances\_destroy**](#function-impedances_destroy) (ImpedancesHandle handle) <br> |
|  bool | [**Impedances\_empty**](#function-impedances_empty) (ImpedancesHandle handle) <br> |
|  bool | [**Impedances\_equal**](#function-impedances_equal) (ImpedancesHandle handle, ImpedancesHandle other) <br> |
|  void | [**Impedances\_erase\_at**](#function-impedances_erase_at) (ImpedancesHandle handle, size\_t idx) <br> |
|  ImpedancesHandle | [**Impedances\_from\_json\_string**](#function-impedances_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**Impedances\_index**](#function-impedances_index) (ImpedancesHandle handle, ImpedanceHandle value) <br> |
|  ImpedancesHandle | [**Impedances\_intersection**](#function-impedances_intersection) (ImpedancesHandle handle, ImpedancesHandle other) <br> |
|  ListImpedanceHandle | [**Impedances\_items**](#function-impedances_items) (ImpedancesHandle handle) <br> |
|  bool | [**Impedances\_not\_equal**](#function-impedances_not_equal) (ImpedancesHandle handle, ImpedancesHandle other) <br> |
|  void | [**Impedances\_push\_back**](#function-impedances_push_back) (ImpedancesHandle handle, ImpedanceHandle value) <br> |
|  size\_t | [**Impedances\_size**](#function-impedances_size) (ImpedancesHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**Impedances\_to\_json\_string**](#function-impedances_to_json_string) (ImpedancesHandle handle) <br> |




























## Public Types Documentation




### typedef ImpedancesHandle 

```C++
typedef void* ImpedancesHandle;
```




<hr>
## Public Functions Documentation




### function Impedances\_at 

```C++
ImpedanceHandle Impedances_at (
    ImpedancesHandle handle,
    size_t idx
) 
```




<hr>



### function Impedances\_clear 

```C++
void Impedances_clear (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_contains 

```C++
bool Impedances_contains (
    ImpedancesHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function Impedances\_copy 

```C++
ImpedancesHandle Impedances_copy (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_create 

```C++
ImpedancesHandle Impedances_create (
    ListImpedanceHandle items
) 
```




<hr>



### function Impedances\_create\_empty 

```C++
ImpedancesHandle Impedances_create_empty () 
```




<hr>



### function Impedances\_destroy 

```C++
void Impedances_destroy (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_empty 

```C++
bool Impedances_empty (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_equal 

```C++
bool Impedances_equal (
    ImpedancesHandle handle,
    ImpedancesHandle other
) 
```




<hr>



### function Impedances\_erase\_at 

```C++
void Impedances_erase_at (
    ImpedancesHandle handle,
    size_t idx
) 
```




<hr>



### function Impedances\_from\_json\_string 

```C++
ImpedancesHandle Impedances_from_json_string (
    StringHandle json
) 
```




<hr>



### function Impedances\_index 

```C++
size_t Impedances_index (
    ImpedancesHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function Impedances\_intersection 

```C++
ImpedancesHandle Impedances_intersection (
    ImpedancesHandle handle,
    ImpedancesHandle other
) 
```




<hr>



### function Impedances\_items 

```C++
ListImpedanceHandle Impedances_items (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_not\_equal 

```C++
bool Impedances_not_equal (
    ImpedancesHandle handle,
    ImpedancesHandle other
) 
```




<hr>



### function Impedances\_push\_back 

```C++
void Impedances_push_back (
    ImpedancesHandle handle,
    ImpedanceHandle value
) 
```




<hr>



### function Impedances\_size 

```C++
size_t Impedances_size (
    ImpedancesHandle handle
) 
```




<hr>



### function Impedances\_to\_json\_string 

```C++
StringHandle Impedances_to_json_string (
    ImpedancesHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/device_structures/Impedances_c_api.h`

