#ifndef FRAY_H
#define FRAY_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t* ints_to_bytes_compressed(const int32_t *numbers, size_t count, size_t *out_size);
int32_t* bytes_to_ints_decompressed(const uint8_t *in_bytes, size_t in_size, size_t *out_count);

#ifdef __cplusplus
}
#endif

#endif // FRAY_H
