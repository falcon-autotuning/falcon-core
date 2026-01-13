

# File ListWaveform\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListWaveform\_c\_api.h**](ListWaveform__c__api_8h.md)

[Go to the source code of this file](ListWaveform__c__api_8h_source.md)



* `#include "falcon_core/instrument_interfaces/Waveform_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListWaveformHandle**](#typedef-listwaveformhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  WaveformHandle | [**ListWaveform\_at**](#function-listwaveform_at) (ListWaveformHandle handle, size\_t idx) <br> |
|  void | [**ListWaveform\_clear**](#function-listwaveform_clear) (ListWaveformHandle handle) <br> |
|  bool | [**ListWaveform\_contains**](#function-listwaveform_contains) (ListWaveformHandle handle, WaveformHandle value) <br> |
|  ListWaveformHandle | [**ListWaveform\_copy**](#function-listwaveform_copy) (ListWaveformHandle handle) <br> |
|  ListWaveformHandle | [**ListWaveform\_create**](#function-listwaveform_create) (WaveformHandle \* data, size\_t count) <br> |
|  ListWaveformHandle | [**ListWaveform\_create\_empty**](#function-listwaveform_create_empty) () <br> |
|  void | [**ListWaveform\_destroy**](#function-listwaveform_destroy) (ListWaveformHandle handle) <br> |
|  bool | [**ListWaveform\_empty**](#function-listwaveform_empty) (ListWaveformHandle handle) <br> |
|  bool | [**ListWaveform\_equal**](#function-listwaveform_equal) (ListWaveformHandle handle, ListWaveformHandle other) <br> |
|  void | [**ListWaveform\_erase\_at**](#function-listwaveform_erase_at) (ListWaveformHandle handle, size\_t idx) <br> |
|  ListWaveformHandle | [**ListWaveform\_fill\_value**](#function-listwaveform_fill_value) (size\_t count, WaveformHandle value) <br> |
|  ListWaveformHandle | [**ListWaveform\_from\_json\_string**](#function-listwaveform_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListWaveform\_index**](#function-listwaveform_index) (ListWaveformHandle handle, WaveformHandle value) <br> |
|  ListWaveformHandle | [**ListWaveform\_intersection**](#function-listwaveform_intersection) (ListWaveformHandle handle, ListWaveformHandle other) <br> |
|  size\_t | [**ListWaveform\_items**](#function-listwaveform_items) (ListWaveformHandle handle, WaveformHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListWaveform\_not\_equal**](#function-listwaveform_not_equal) (ListWaveformHandle handle, ListWaveformHandle other) <br> |
|  void | [**ListWaveform\_push\_back**](#function-listwaveform_push_back) (ListWaveformHandle handle, WaveformHandle value) <br> |
|  size\_t | [**ListWaveform\_size**](#function-listwaveform_size) (ListWaveformHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListWaveform\_to\_json\_string**](#function-listwaveform_to_json_string) (ListWaveformHandle handle) <br> |




























## Public Types Documentation




### typedef ListWaveformHandle 

```C++
typedef void* ListWaveformHandle;
```




<hr>
## Public Functions Documentation




### function ListWaveform\_at 

```C++
WaveformHandle ListWaveform_at (
    ListWaveformHandle handle,
    size_t idx
) 
```




<hr>



### function ListWaveform\_clear 

```C++
void ListWaveform_clear (
    ListWaveformHandle handle
) 
```




<hr>



### function ListWaveform\_contains 

```C++
bool ListWaveform_contains (
    ListWaveformHandle handle,
    WaveformHandle value
) 
```




<hr>



### function ListWaveform\_copy 

```C++
ListWaveformHandle ListWaveform_copy (
    ListWaveformHandle handle
) 
```




<hr>



### function ListWaveform\_create 

```C++
ListWaveformHandle ListWaveform_create (
    WaveformHandle * data,
    size_t count
) 
```




<hr>



### function ListWaveform\_create\_empty 

```C++
ListWaveformHandle ListWaveform_create_empty () 
```




<hr>



### function ListWaveform\_destroy 

```C++
void ListWaveform_destroy (
    ListWaveformHandle handle
) 
```




<hr>



### function ListWaveform\_empty 

```C++
bool ListWaveform_empty (
    ListWaveformHandle handle
) 
```




<hr>



### function ListWaveform\_equal 

```C++
bool ListWaveform_equal (
    ListWaveformHandle handle,
    ListWaveformHandle other
) 
```




<hr>



### function ListWaveform\_erase\_at 

```C++
void ListWaveform_erase_at (
    ListWaveformHandle handle,
    size_t idx
) 
```




<hr>



### function ListWaveform\_fill\_value 

```C++
ListWaveformHandle ListWaveform_fill_value (
    size_t count,
    WaveformHandle value
) 
```




<hr>



### function ListWaveform\_from\_json\_string 

```C++
ListWaveformHandle ListWaveform_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListWaveform\_index 

```C++
size_t ListWaveform_index (
    ListWaveformHandle handle,
    WaveformHandle value
) 
```




<hr>



### function ListWaveform\_intersection 

```C++
ListWaveformHandle ListWaveform_intersection (
    ListWaveformHandle handle,
    ListWaveformHandle other
) 
```




<hr>



### function ListWaveform\_items 

```C++
size_t ListWaveform_items (
    ListWaveformHandle handle,
    WaveformHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListWaveform\_not\_equal 

```C++
bool ListWaveform_not_equal (
    ListWaveformHandle handle,
    ListWaveformHandle other
) 
```




<hr>



### function ListWaveform\_push\_back 

```C++
void ListWaveform_push_back (
    ListWaveformHandle handle,
    WaveformHandle value
) 
```




<hr>



### function ListWaveform\_size 

```C++
size_t ListWaveform_size (
    ListWaveformHandle handle
) 
```




<hr>



### function ListWaveform\_to\_json\_string 

```C++
StringHandle ListWaveform_to_json_string (
    ListWaveformHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListWaveform_c_api.h`

