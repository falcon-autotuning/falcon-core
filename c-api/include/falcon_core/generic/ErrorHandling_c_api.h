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
