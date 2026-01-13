

# File IncreasingAlignment\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**IncreasingAlignment\_c\_api.h**](IncreasingAlignment__c__api_8h.md)

[Go to the source code of this file](IncreasingAlignment__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**IncreasingAlignmentHandle**](#typedef-increasingalignmenthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**IncreasingAlignment\_alignment**](#function-increasingalignment_alignment) (IncreasingAlignmentHandle handle) <br>_Return the alignment of the domain._  |
|  IncreasingAlignmentHandle | [**IncreasingAlignment\_copy**](#function-increasingalignment_copy) (IncreasingAlignmentHandle handle) <br> |
|  IncreasingAlignmentHandle | [**IncreasingAlignment\_create**](#function-increasingalignment_create) (bool alignment) <br> |
|  IncreasingAlignmentHandle | [**IncreasingAlignment\_create\_empty**](#function-increasingalignment_create_empty) () <br> |
|  void | [**IncreasingAlignment\_destroy**](#function-increasingalignment_destroy) (IncreasingAlignmentHandle handle) <br> |
|  bool | [**IncreasingAlignment\_equal**](#function-increasingalignment_equal) (IncreasingAlignmentHandle handle, IncreasingAlignmentHandle other) <br> |
|  IncreasingAlignmentHandle | [**IncreasingAlignment\_from\_json\_string**](#function-increasingalignment_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**IncreasingAlignment\_not\_equal**](#function-increasingalignment_not_equal) (IncreasingAlignmentHandle handle, IncreasingAlignmentHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**IncreasingAlignment\_to\_json\_string**](#function-increasingalignment_to_json_string) (IncreasingAlignmentHandle handle) <br> |




























## Public Types Documentation




### typedef IncreasingAlignmentHandle 

```C++
typedef void* IncreasingAlignmentHandle;
```




<hr>
## Public Functions Documentation




### function IncreasingAlignment\_alignment 

_Return the alignment of the domain._ 
```C++
int IncreasingAlignment_alignment (
    IncreasingAlignmentHandle handle
) 
```




<hr>



### function IncreasingAlignment\_copy 

```C++
IncreasingAlignmentHandle IncreasingAlignment_copy (
    IncreasingAlignmentHandle handle
) 
```




<hr>



### function IncreasingAlignment\_create 

```C++
IncreasingAlignmentHandle IncreasingAlignment_create (
    bool alignment
) 
```




<hr>



### function IncreasingAlignment\_create\_empty 

```C++
IncreasingAlignmentHandle IncreasingAlignment_create_empty () 
```




<hr>



### function IncreasingAlignment\_destroy 

```C++
void IncreasingAlignment_destroy (
    IncreasingAlignmentHandle handle
) 
```




<hr>



### function IncreasingAlignment\_equal 

```C++
bool IncreasingAlignment_equal (
    IncreasingAlignmentHandle handle,
    IncreasingAlignmentHandle other
) 
```




<hr>



### function IncreasingAlignment\_from\_json\_string 

```C++
IncreasingAlignmentHandle IncreasingAlignment_from_json_string (
    StringHandle json
) 
```




<hr>



### function IncreasingAlignment\_not\_equal 

```C++
bool IncreasingAlignment_not_equal (
    IncreasingAlignmentHandle handle,
    IncreasingAlignmentHandle other
) 
```




<hr>



### function IncreasingAlignment\_to\_json\_string 

```C++
StringHandle IncreasingAlignment_to_json_string (
    IncreasingAlignmentHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/IncreasingAlignment_c_api.h`

