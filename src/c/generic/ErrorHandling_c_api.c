#include "falcon-core/generic/ErrorHandling_c_api.h"

#include <stdio.h>
#include <threads.h>

int  last_error_code     = 0;
char last_error_msg[256] = {0};

void set_last_error(int code, const char* msg) {
  last_error_code = code;
  if (msg) {
    snprintf(last_error_msg, sizeof(last_error_msg), "%s", msg);
  } else {
    last_error_msg[0] = '\0';
  }
}

int         get_last_error_code() { return last_error_code; }
const char* get_last_error_msg() { return last_error_msg; }
