

# File ErrorHandling\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ErrorHandling\_c\_api.h**](ErrorHandling__c__api_8h.md)

[Go to the source code of this file](ErrorHandling__c__api_8h_source.md)
























## Public Attributes

| Type | Name |
| ---: | :--- |
|  int | [**last\_error\_code**](#variable-last_error_code)  <br> |
|  char | [**last\_error\_msg**](#variable-last_error_msg)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**get\_last\_error\_code**](#function-get_last_error_code) () <br> |
|  const char \* | [**get\_last\_error\_msg**](#function-get_last_error_msg) () <br> |
|  void | [**set\_last\_error**](#function-set_last_error) (int code, const char \* msg) <br> |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**FALCON\_C\_API\_BEGIN**](ErrorHandling__c__api_8h.md#define-falcon_c_api_begin)  `try {`<br> |
| define  | [**FALCON\_C\_API\_END**](ErrorHandling__c__api_8h.md#define-falcon_c_api_end) (return\_value) `/* multi line expression */`<br> |

## Public Attributes Documentation




### variable last\_error\_code 

```C++
int last_error_code;
```




<hr>



### variable last\_error\_msg 

```C++
char last_error_msg[256];
```




<hr>
## Public Functions Documentation




### function get\_last\_error\_code 

```C++
int get_last_error_code () 
```




<hr>



### function get\_last\_error\_msg 

```C++
const char * get_last_error_msg () 
```




<hr>



### function set\_last\_error 

```C++
void set_last_error (
    int code,
    const char * msg
) 
```




<hr>
## Macro Definition Documentation





### define FALCON\_C\_API\_BEGIN 

```C++
#define FALCON_C_API_BEGIN `try {`
```




<hr>



### define FALCON\_C\_API\_END 

```C++
#define FALCON_C_API_END (
    return_value
) `/* multi line expression */`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ErrorHandling_c_api.h`

