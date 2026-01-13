

# File Time\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**Time\_c\_api.h**](Time__c__api_8h.md)

[Go to the source code of this file](Time__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**TimeHandle**](#typedef-timehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  TimeHandle | [**Time\_copy**](#function-time_copy) (TimeHandle handle) <br> |
|  TimeHandle | [**Time\_create\_at**](#function-time_create_at) (long long micro\_seconds\_since\_epoch) <br> |
|  TimeHandle | [**Time\_create\_now**](#function-time_create_now) () <br> |
|  void | [**Time\_destroy**](#function-time_destroy) (TimeHandle handle) <br> |
|  bool | [**Time\_equal**](#function-time_equal) (TimeHandle handle, TimeHandle other) <br> |
|  TimeHandle | [**Time\_from\_json\_string**](#function-time_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  long long | [**Time\_micro\_seconds\_since\_epoch**](#function-time_micro_seconds_since_epoch) (TimeHandle handle) <br>_Get the time in microseconds since epoch._  |
|  bool | [**Time\_not\_equal**](#function-time_not_equal) (TimeHandle handle, TimeHandle other) <br> |
|  long long | [**Time\_time**](#function-time_time) (TimeHandle handle) <br>_Get the time in seconds since epoch._  |
|  [**StringHandle**](structstring.md) | [**Time\_to\_json\_string**](#function-time_to_json_string) (TimeHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**Time\_to\_string**](#function-time_to_string) (TimeHandle handle) <br>_Convert the Time to a human-readable string._  |




























## Public Types Documentation




### typedef TimeHandle 

```C++
typedef void* TimeHandle;
```




<hr>
## Public Functions Documentation




### function Time\_copy 

```C++
TimeHandle Time_copy (
    TimeHandle handle
) 
```




<hr>



### function Time\_create\_at 

```C++
TimeHandle Time_create_at (
    long long micro_seconds_since_epoch
) 
```




<hr>



### function Time\_create\_now 

```C++
TimeHandle Time_create_now () 
```




<hr>



### function Time\_destroy 

```C++
void Time_destroy (
    TimeHandle handle
) 
```




<hr>



### function Time\_equal 

```C++
bool Time_equal (
    TimeHandle handle,
    TimeHandle other
) 
```




<hr>



### function Time\_from\_json\_string 

```C++
TimeHandle Time_from_json_string (
    StringHandle json
) 
```




<hr>



### function Time\_micro\_seconds\_since\_epoch 

_Get the time in microseconds since epoch._ 
```C++
long long Time_micro_seconds_since_epoch (
    TimeHandle handle
) 
```





**Returns:**

The time in microseconds since epoch. 





        

<hr>



### function Time\_not\_equal 

```C++
bool Time_not_equal (
    TimeHandle handle,
    TimeHandle other
) 
```




<hr>



### function Time\_time 

_Get the time in seconds since epoch._ 
```C++
long long Time_time (
    TimeHandle handle
) 
```





**Returns:**

The time in seconds since epoch. 





        

<hr>



### function Time\_to\_json\_string 

```C++
StringHandle Time_to_json_string (
    TimeHandle handle
) 
```




<hr>



### function Time\_to\_string 

_Convert the Time to a human-readable string._ 
```C++
StringHandle Time_to_string (
    TimeHandle handle
) 
```





**Returns:**

A string representation of the Time. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/communications/Time_c_api.h`

