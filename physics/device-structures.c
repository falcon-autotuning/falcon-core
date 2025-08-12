#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
} BaseConnection;

BaseConnection *baseConnectionCreate(const char *input) {
  BaseConnection *s = malloc(sizeof(BaseConnection));
  if (!s)
    return NULL;
  s->name = strdup(input);
  if (!s->name) {
    free(s);
    return NULL;
  }
  return s;
}

BaseConnection *name() {}
