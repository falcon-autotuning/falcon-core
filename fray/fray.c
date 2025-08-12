#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

// Compresses an array of int32_t. Allocates output buffer.
// Returns pointer to compressed data and sets *out_size. Caller must free the buffer.
uint8_t* ints_to_bytes_compressed(const int32_t *numbers, size_t count, size_t *out_size) {
    size_t raw_size = count * sizeof(int32_t);
    uLongf max_compressed_size = compressBound(raw_size);
    uint8_t *out_bytes = malloc(max_compressed_size);
    if (!out_bytes) return NULL;

    int res = compress(out_bytes, &max_compressed_size, (const Bytef*)numbers, raw_size);
    if (res != Z_OK) {
        free(out_bytes);
        return NULL;
    }
    *out_size = max_compressed_size;
    return out_bytes;
}

// Decompresses bytes to int32_t array. Allocates output buffer.
// Returns pointer to int32_t array and sets *out_count. Caller must free the buffer.
int32_t* bytes_to_ints_decompressed(const uint8_t *in_bytes, size_t in_size, size_t *out_count) {
    // You must know or store the original count somewhere; here, we assume it's stored externally.
    // For demonstration, let's decompress to a buffer large enough for a reasonable number of ints.
    size_t max_count = 1024 * 1024; // 1 million ints max
    size_t raw_size = max_count * sizeof(int32_t);
    int32_t *out_numbers = malloc(raw_size);
    if (!out_numbers) return NULL;

    uLongf dest_len = raw_size;
    int res = uncompress((Bytef*)out_numbers, &dest_len, in_bytes, in_size);
    if (res != Z_OK) {
        free(out_numbers);
        return NULL;
    }
    *out_count = dest_len / sizeof(int32_t);
    return out_numbers;
}
