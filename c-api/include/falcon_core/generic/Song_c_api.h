#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void* SongHandle;

// Creation/destruction
void Song_destroy(SongHandle handle);

// Serialization
const char* Song_to_json_string(SongHandle handle);

// Deserialization
SongHandle Song_from_json_string(const char* json);

// Equality
int Song_equal(SongHandle a, SongHandle b);
int Song_not_equal(SongHandle a, SongHandle b);

#ifdef __cplusplus
}
#endif
