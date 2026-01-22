

# File ErrorHandling\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ErrorHandling\_c\_api.h**](ErrorHandling__c__api_8h.md)

[Go to the documentation of this file](ErrorHandling__c__api_8h.md)


```C++
#define FALCON_C_API_BEGIN try {
#define FALCON_C_API_END(return_value)          \
  }                                             \
  catch (const std::exception& e) {             \
    set_last_error(1, e.what());                \
  }                                             \
  catch (...) {                                 \
    set_last_error(2, "Unknown C++ exception"); \
  }                                             \
  return return_value;

// Declare the thread-local variables as extern
extern int  last_error_code;
extern char last_error_msg[256];

#ifdef __cplusplus
extern "C" {
#endif

// Declare the setter/getter functions
void        set_last_error(int code, const char* msg);
int         get_last_error_code();
const char* get_last_error_msg();

#ifdef __cplusplus
}
#endif
```


