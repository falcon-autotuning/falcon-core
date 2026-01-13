

# File Adjacency\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**Adjacency\_c\_api.h**](Adjacency__c__api_8h.md)

[Go to the source code of this file](Adjacency__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayInt_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/ListPairSizeTSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AdjacencyHandle**](#typedef-adjacencyhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  AdjacencyHandle | [**Adjacency\_copy**](#function-adjacency_copy) (AdjacencyHandle handle) <br> |
|  AdjacencyHandle | [**Adjacency\_create**](#function-adjacency_create) (const int \* data, const size\_t \* shape, const size\_t ndim, ConnectionsHandle indexes) <br> |
|  size\_t | [**Adjacency\_data**](#function-adjacency_data) (AdjacencyHandle handle, int \* out\_buffer, size\_t numdata) <br> |
|  void | [**Adjacency\_destroy**](#function-adjacency_destroy) (AdjacencyHandle handle) <br> |
|  size\_t | [**Adjacency\_dimension**](#function-adjacency_dimension) (AdjacencyHandle handle) <br> |
|  bool | [**Adjacency\_equal**](#function-adjacency_equal) (AdjacencyHandle handle, AdjacencyHandle other) <br> |
|  AdjacencyHandle | [**Adjacency\_flip**](#function-adjacency_flip) (AdjacencyHandle handle, size\_t axis) <br> |
|  AdjacencyHandle | [**Adjacency\_from\_json\_string**](#function-adjacency_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  ListPairSizeTSizeTHandle | [**Adjacency\_get\_true\_pairs**](#function-adjacency_get_true_pairs) (AdjacencyHandle handle) <br>_Returns the pairs of indexes where the adjacency matrix is true (1)_  |
|  ConnectionsHandle | [**Adjacency\_indexes**](#function-adjacency_indexes) (AdjacencyHandle handle) <br> |
|  bool | [**Adjacency\_not\_equal**](#function-adjacency_not_equal) (AdjacencyHandle handle, AdjacencyHandle other) <br> |
|  size\_t | [**Adjacency\_shape**](#function-adjacency_shape) (AdjacencyHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**Adjacency\_size**](#function-adjacency_size) (AdjacencyHandle handle) <br> |
|  int | [**Adjacency\_sum**](#function-adjacency_sum) (AdjacencyHandle handle) <br> |
|  void | [**Adjacency\_times\_equals\_farray**](#function-adjacency_times_equals_farray) (AdjacencyHandle handle, FArrayIntHandle other) <br> |
|  AdjacencyHandle | [**Adjacency\_times\_farray**](#function-adjacency_times_farray) (AdjacencyHandle handle, FArrayIntHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**Adjacency\_to\_json\_string**](#function-adjacency_to_json_string) (AdjacencyHandle handle) <br> |
|  ListListSizeTHandle | [**Adjacency\_where**](#function-adjacency_where) (AdjacencyHandle handle, int value) <br> |




























## Public Types Documentation




### typedef AdjacencyHandle 

```C++
typedef void* AdjacencyHandle;
```




<hr>
## Public Functions Documentation




### function Adjacency\_copy 

```C++
AdjacencyHandle Adjacency_copy (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_create 

```C++
AdjacencyHandle Adjacency_create (
    const int * data,
    const size_t * shape,
    const size_t ndim,
    ConnectionsHandle indexes
) 
```




<hr>



### function Adjacency\_data 

```C++
size_t Adjacency_data (
    AdjacencyHandle handle,
    int * out_buffer,
    size_t numdata
) 
```




<hr>



### function Adjacency\_destroy 

```C++
void Adjacency_destroy (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_dimension 

```C++
size_t Adjacency_dimension (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_equal 

```C++
bool Adjacency_equal (
    AdjacencyHandle handle,
    AdjacencyHandle other
) 
```




<hr>



### function Adjacency\_flip 

```C++
AdjacencyHandle Adjacency_flip (
    AdjacencyHandle handle,
    size_t axis
) 
```




<hr>



### function Adjacency\_from\_json\_string 

```C++
AdjacencyHandle Adjacency_from_json_string (
    StringHandle json
) 
```




<hr>



### function Adjacency\_get\_true\_pairs 

_Returns the pairs of indexes where the adjacency matrix is true (1)_ 
```C++
ListPairSizeTSizeTHandle Adjacency_get_true_pairs (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_indexes 

```C++
ConnectionsHandle Adjacency_indexes (
    AdjacencyHandle handle
) 
```



## @brief Returns the indexes of the gates in the order for the adjacency



matrix 



        

<hr>



### function Adjacency\_not\_equal 

```C++
bool Adjacency_not_equal (
    AdjacencyHandle handle,
    AdjacencyHandle other
) 
```




<hr>



### function Adjacency\_shape 

```C++
size_t Adjacency_shape (
    AdjacencyHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function Adjacency\_size 

```C++
size_t Adjacency_size (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_sum 

```C++
int Adjacency_sum (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_times\_equals\_farray 

```C++
void Adjacency_times_equals_farray (
    AdjacencyHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function Adjacency\_times\_farray 

```C++
AdjacencyHandle Adjacency_times_farray (
    AdjacencyHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function Adjacency\_to\_json\_string 

```C++
StringHandle Adjacency_to_json_string (
    AdjacencyHandle handle
) 
```




<hr>



### function Adjacency\_where 

```C++
ListListSizeTHandle Adjacency_where (
    AdjacencyHandle handle,
    int value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/core/Adjacency_c_api.h`

