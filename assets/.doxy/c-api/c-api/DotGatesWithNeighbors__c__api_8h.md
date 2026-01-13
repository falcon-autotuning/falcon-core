

# File DotGatesWithNeighbors\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**DotGatesWithNeighbors\_c\_api.h**](DotGatesWithNeighbors__c__api_8h.md)

[Go to the source code of this file](DotGatesWithNeighbors__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DotGatesWithNeighborsHandle**](#typedef-dotgateswithneighborshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DotGateWithNeighborsHandle | [**DotGatesWithNeighbors\_at**](#function-dotgateswithneighbors_at) (DotGatesWithNeighborsHandle handle, size\_t idx) <br> |
|  void | [**DotGatesWithNeighbors\_clear**](#function-dotgateswithneighbors_clear) (DotGatesWithNeighborsHandle handle) <br> |
|  bool | [**DotGatesWithNeighbors\_contains**](#function-dotgateswithneighbors_contains) (DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  DotGatesWithNeighborsHandle | [**DotGatesWithNeighbors\_copy**](#function-dotgateswithneighbors_copy) (DotGatesWithNeighborsHandle handle) <br> |
|  DotGatesWithNeighborsHandle | [**DotGatesWithNeighbors\_create**](#function-dotgateswithneighbors_create) (ListDotGateWithNeighborsHandle items) <br> |
|  DotGatesWithNeighborsHandle | [**DotGatesWithNeighbors\_create\_empty**](#function-dotgateswithneighbors_create_empty) () <br> |
|  void | [**DotGatesWithNeighbors\_destroy**](#function-dotgateswithneighbors_destroy) (DotGatesWithNeighborsHandle handle) <br> |
|  bool | [**DotGatesWithNeighbors\_empty**](#function-dotgateswithneighbors_empty) (DotGatesWithNeighborsHandle handle) <br> |
|  bool | [**DotGatesWithNeighbors\_equal**](#function-dotgateswithneighbors_equal) (DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other) <br> |
|  void | [**DotGatesWithNeighbors\_erase\_at**](#function-dotgateswithneighbors_erase_at) (DotGatesWithNeighborsHandle handle, size\_t idx) <br> |
|  DotGatesWithNeighborsHandle | [**DotGatesWithNeighbors\_from\_json\_string**](#function-dotgateswithneighbors_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**DotGatesWithNeighbors\_index**](#function-dotgateswithneighbors_index) (DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  DotGatesWithNeighborsHandle | [**DotGatesWithNeighbors\_intersection**](#function-dotgateswithneighbors_intersection) (DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other) <br> |
|  bool | [**DotGatesWithNeighbors\_is\_barrier\_gates**](#function-dotgateswithneighbors_is_barrier_gates) (DotGatesWithNeighborsHandle handle) <br>_Check if all connections are barrier gates._  |
|  bool | [**DotGatesWithNeighbors\_is\_plunger\_gates**](#function-dotgateswithneighbors_is_plunger_gates) (DotGatesWithNeighborsHandle handle) <br>_Check if all connections are plunger gates._  |
|  ListDotGateWithNeighborsHandle | [**DotGatesWithNeighbors\_items**](#function-dotgateswithneighbors_items) (DotGatesWithNeighborsHandle handle) <br> |
|  bool | [**DotGatesWithNeighbors\_not\_equal**](#function-dotgateswithneighbors_not_equal) (DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other) <br> |
|  void | [**DotGatesWithNeighbors\_push\_back**](#function-dotgateswithneighbors_push_back) (DotGatesWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  size\_t | [**DotGatesWithNeighbors\_size**](#function-dotgateswithneighbors_size) (DotGatesWithNeighborsHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**DotGatesWithNeighbors\_to\_json\_string**](#function-dotgateswithneighbors_to_json_string) (DotGatesWithNeighborsHandle handle) <br> |




























## Public Types Documentation




### typedef DotGatesWithNeighborsHandle 

```C++
typedef void* DotGatesWithNeighborsHandle;
```




<hr>
## Public Functions Documentation




### function DotGatesWithNeighbors\_at 

```C++
DotGateWithNeighborsHandle DotGatesWithNeighbors_at (
    DotGatesWithNeighborsHandle handle,
    size_t idx
) 
```




<hr>



### function DotGatesWithNeighbors\_clear 

```C++
void DotGatesWithNeighbors_clear (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_contains 

```C++
bool DotGatesWithNeighbors_contains (
    DotGatesWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function DotGatesWithNeighbors\_copy 

```C++
DotGatesWithNeighborsHandle DotGatesWithNeighbors_copy (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_create 

```C++
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create (
    ListDotGateWithNeighborsHandle items
) 
```




<hr>



### function DotGatesWithNeighbors\_create\_empty 

```C++
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty () 
```




<hr>



### function DotGatesWithNeighbors\_destroy 

```C++
void DotGatesWithNeighbors_destroy (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_empty 

```C++
bool DotGatesWithNeighbors_empty (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_equal 

```C++
bool DotGatesWithNeighbors_equal (
    DotGatesWithNeighborsHandle handle,
    DotGatesWithNeighborsHandle other
) 
```




<hr>



### function DotGatesWithNeighbors\_erase\_at 

```C++
void DotGatesWithNeighbors_erase_at (
    DotGatesWithNeighborsHandle handle,
    size_t idx
) 
```




<hr>



### function DotGatesWithNeighbors\_from\_json\_string 

```C++
DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string (
    StringHandle json
) 
```




<hr>



### function DotGatesWithNeighbors\_index 

```C++
size_t DotGatesWithNeighbors_index (
    DotGatesWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function DotGatesWithNeighbors\_intersection 

```C++
DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection (
    DotGatesWithNeighborsHandle handle,
    DotGatesWithNeighborsHandle other
) 
```




<hr>



### function DotGatesWithNeighbors\_is\_barrier\_gates 

_Check if all connections are barrier gates._ 
```C++
bool DotGatesWithNeighbors_is_barrier_gates (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_is\_plunger\_gates 

_Check if all connections are plunger gates._ 
```C++
bool DotGatesWithNeighbors_is_plunger_gates (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_items 

```C++
ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_not\_equal 

```C++
bool DotGatesWithNeighbors_not_equal (
    DotGatesWithNeighborsHandle handle,
    DotGatesWithNeighborsHandle other
) 
```




<hr>



### function DotGatesWithNeighbors\_push\_back 

```C++
void DotGatesWithNeighbors_push_back (
    DotGatesWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function DotGatesWithNeighbors\_size 

```C++
size_t DotGatesWithNeighbors_size (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>



### function DotGatesWithNeighbors\_to\_json\_string 

```C++
StringHandle DotGatesWithNeighbors_to_json_string (
    DotGatesWithNeighborsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/geometries/DotGatesWithNeighbors_c_api.h`

