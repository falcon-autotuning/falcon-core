
#include <string.h>
#include <threads.h>

thread_local int  last_error_code     = 0;
thread_local char last_error_msg[256] = {0};

void set_last_error(int code, const char* msg) {
  last_error_code = code;
  if (msg) {
    strncpy(last_error_msg, msg, sizeof(last_error_msg) - 1);
    last_error_msg[sizeof(last_error_msg) - 1] = '\0';
  } else {
    last_error_msg[0] = '\0';
  }
}

int get_last_error_code() { return last_error_code; }

const char* get_last_error_msg() { return last_error_msg; }
