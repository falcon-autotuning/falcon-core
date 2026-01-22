

# File MapInterpretationContextQuantity\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInterpretationContextQuantity\_c\_api.h**](MapInterpretationContextQuantity__c__api_8h.md)

[Go to the source code of this file](MapInterpretationContextQuantity__c__api_8h_source.md)



* `#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"`
* `#include "falcon_core/generic/ListQuantity_c_api.h"`
* `#include "falcon_core/generic/ListInterpretationContext_c_api.h"`
* `#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapInterpretationContextQuantityHandle**](#typedef-mapinterpretationcontextquantityhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  QuantityHandle | [**MapInterpretationContextQuantity\_at**](#function-mapinterpretationcontextquantity_at) (MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key) <br> |
|  void | [**MapInterpretationContextQuantity\_clear**](#function-mapinterpretationcontextquantity_clear) (MapInterpretationContextQuantityHandle handle) <br> |
|  bool | [**MapInterpretationContextQuantity\_contains**](#function-mapinterpretationcontextquantity_contains) (MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextQuantityHandle | [**MapInterpretationContextQuantity\_copy**](#function-mapinterpretationcontextquantity_copy) (MapInterpretationContextQuantityHandle handle) <br> |
|  MapInterpretationContextQuantityHandle | [**MapInterpretationContextQuantity\_create**](#function-mapinterpretationcontextquantity_create) (PairInterpretationContextQuantityHandle \* data, size\_t count) <br> |
|  MapInterpretationContextQuantityHandle | [**MapInterpretationContextQuantity\_create\_empty**](#function-mapinterpretationcontextquantity_create_empty) () <br> |
|  void | [**MapInterpretationContextQuantity\_destroy**](#function-mapinterpretationcontextquantity_destroy) (MapInterpretationContextQuantityHandle handle) <br> |
|  bool | [**MapInterpretationContextQuantity\_empty**](#function-mapinterpretationcontextquantity_empty) (MapInterpretationContextQuantityHandle handle) <br> |
|  bool | [**MapInterpretationContextQuantity\_equal**](#function-mapinterpretationcontextquantity_equal) (MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other) <br> |
|  void | [**MapInterpretationContextQuantity\_erase**](#function-mapinterpretationcontextquantity_erase) (MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key) <br> |
|  MapInterpretationContextQuantityHandle | [**MapInterpretationContextQuantity\_from\_json\_string**](#function-mapinterpretationcontextquantity_from_json_string) (StringHandle json) <br> |
|  void | [**MapInterpretationContextQuantity\_insert**](#function-mapinterpretationcontextquantity_insert) (MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value) <br> |
|  void | [**MapInterpretationContextQuantity\_insert\_or\_assign**](#function-mapinterpretationcontextquantity_insert_or_assign) (MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value) <br> |
|  ListPairInterpretationContextQuantityHandle | [**MapInterpretationContextQuantity\_items**](#function-mapinterpretationcontextquantity_items) (MapInterpretationContextQuantityHandle handle) <br> |
|  ListInterpretationContextHandle | [**MapInterpretationContextQuantity\_keys**](#function-mapinterpretationcontextquantity_keys) (MapInterpretationContextQuantityHandle handle) <br> |
|  bool | [**MapInterpretationContextQuantity\_not\_equal**](#function-mapinterpretationcontextquantity_not_equal) (MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other) <br> |
|  size\_t | [**MapInterpretationContextQuantity\_size**](#function-mapinterpretationcontextquantity_size) (MapInterpretationContextQuantityHandle handle) <br> |
|  StringHandle | [**MapInterpretationContextQuantity\_to\_json\_string**](#function-mapinterpretationcontextquantity_to_json_string) (MapInterpretationContextQuantityHandle handle) <br> |
|  ListQuantityHandle | [**MapInterpretationContextQuantity\_values**](#function-mapinterpretationcontextquantity_values) (MapInterpretationContextQuantityHandle handle) <br> |




























## Public Types Documentation




### typedef MapInterpretationContextQuantityHandle 

```C++
typedef void* MapInterpretationContextQuantityHandle;
```




<hr>
## Public Functions Documentation




### function MapInterpretationContextQuantity\_at 

```C++
QuantityHandle MapInterpretationContextQuantity_at (
    MapInterpretationContextQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextQuantity\_clear 

```C++
void MapInterpretationContextQuantity_clear (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_contains 

```C++
bool MapInterpretationContextQuantity_contains (
    MapInterpretationContextQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextQuantity\_copy 

```C++
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_copy (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_create 

```C++
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create (
    PairInterpretationContextQuantityHandle * data,
    size_t count
) 
```




<hr>



### function MapInterpretationContextQuantity\_create\_empty 

```C++
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty () 
```




<hr>



### function MapInterpretationContextQuantity\_destroy 

```C++
void MapInterpretationContextQuantity_destroy (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_empty 

```C++
bool MapInterpretationContextQuantity_empty (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_equal 

```C++
bool MapInterpretationContextQuantity_equal (
    MapInterpretationContextQuantityHandle handle,
    MapInterpretationContextQuantityHandle other
) 
```




<hr>



### function MapInterpretationContextQuantity\_erase 

```C++
void MapInterpretationContextQuantity_erase (
    MapInterpretationContextQuantityHandle handle,
    InterpretationContextHandle key
) 
```




<hr>



### function MapInterpretationContextQuantity\_from\_json\_string 

```C++
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapInterpretationContextQuantity\_insert 

```C++
void MapInterpretationContextQuantity_insert (
    MapInterpretationContextQuantityHandle handle,
    InterpretationContextHandle key,
    QuantityHandle value
) 
```




<hr>



### function MapInterpretationContextQuantity\_insert\_or\_assign 

```C++
void MapInterpretationContextQuantity_insert_or_assign (
    MapInterpretationContextQuantityHandle handle,
    InterpretationContextHandle key,
    QuantityHandle value
) 
```




<hr>



### function MapInterpretationContextQuantity\_items 

```C++
ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_keys 

```C++
ListInterpretationContextHandle MapInterpretationContextQuantity_keys (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_not\_equal 

```C++
bool MapInterpretationContextQuantity_not_equal (
    MapInterpretationContextQuantityHandle handle,
    MapInterpretationContextQuantityHandle other
) 
```




<hr>



### function MapInterpretationContextQuantity\_size 

```C++
size_t MapInterpretationContextQuantity_size (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_to\_json\_string 

```C++
StringHandle MapInterpretationContextQuantity_to_json_string (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>



### function MapInterpretationContextQuantity\_values 

```C++
ListQuantityHandle MapInterpretationContextQuantity_values (
    MapInterpretationContextQuantityHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapInterpretationContextQuantity_c_api.h`

