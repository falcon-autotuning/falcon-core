

# File Loader\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**Loader\_c\_api.h**](Loader__c__api_8h.md)

[Go to the source code of this file](Loader__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/config/core/Config_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LoaderHandle**](#typedef-loaderhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConfigHandle | [**Loader\_config**](#function-loader_config) (LoaderHandle handle) <br>_Returns the config._  |
|  LoaderHandle | [**Loader\_create**](#function-loader_create) (StringHandle config\_path) <br> |
|  void | [**Loader\_destroy**](#function-loader_destroy) (LoaderHandle handle) <br> |




























## Public Types Documentation




### typedef LoaderHandle 

```C++
typedef void* LoaderHandle;
```




<hr>
## Public Functions Documentation




### function Loader\_config 

_Returns the config._ 
```C++
ConfigHandle Loader_config (
    LoaderHandle handle
) 
```




<hr>



### function Loader\_create 

```C++
LoaderHandle Loader_create (
    StringHandle config_path
) 
```




<hr>



### function Loader\_destroy 

```C++
void Loader_destroy (
    LoaderHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/Loader_c_api.h`

