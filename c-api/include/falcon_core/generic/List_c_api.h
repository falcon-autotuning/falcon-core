#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/generic/Pair_c_api.h"

// Forward declarations for opaque handles
typedef void* ListIntHandle;
typedef void* ListFloatHandle;
typedef void* ListPairIntIntHandle;
typedef void* ListPairFloatFloatHandle;
typedef void* ListPairIntFloatHandle;
typedef void* ListPairConnectionFloatHandle;
typedef void* ListConnectionHandle;

// Function declarations

ListIntHandle ListInt_create_empty();
ListIntHandle ListInt_allocate(size_t count);
ListIntHandle ListInt_fill_value(size_t count, int value);
ListIntHandle ListInt_create(const int* data, size_t count);
void ListInt_destroy(ListIntHandle handle);
void ListInt_push_back(ListIntHandle handle, int value);
size_t ListInt_size(ListIntHandle handle);
bool ListInt_empty(ListIntHandle handle);
void ListInt_erase_at(ListIntHandle handle, size_t idx);
void ListInt_clear(ListIntHandle handle);
int ListInt_const_at(ListIntHandle handle, size_t idx);
int ListInt_at(ListIntHandle handle, size_t idx);
size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size);
bool ListInt_contains(ListIntHandle handle, int value);
size_t ListInt_index(ListIntHandle handle, int value);
ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other);
bool ListInt_equal(ListIntHandle a, ListIntHandle b);
bool ListInt_not_equal(ListIntHandle a, ListIntHandle b);

ListFloatHandle ListFloat_create_empty();
ListFloatHandle ListFloat_allocate(size_t count);
ListFloatHandle ListFloat_fill_value(size_t count, float value);
ListFloatHandle ListFloat_create(const float* data, size_t count);
void ListFloat_destroy(ListFloatHandle handle);
void ListFloat_push_back(ListFloatHandle handle, float value);
size_t ListFloat_size(ListFloatHandle handle);
bool ListFloat_empty(ListFloatHandle handle);
void ListFloat_erase_at(ListFloatHandle handle, size_t idx);
void ListFloat_clear(ListFloatHandle handle);
float ListFloat_const_at(ListFloatHandle handle, size_t idx);
float ListFloat_at(ListFloatHandle handle, size_t idx);
size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size);
bool ListFloat_contains(ListFloatHandle handle, float value);
size_t ListFloat_index(ListFloatHandle handle, float value);
ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other);
bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b);
bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b);

ListPairIntIntHandle ListPairIntInt_create_empty();
ListPairIntIntHandle ListPairIntInt_allocate(size_t count);
ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value);
ListPairIntIntHandle ListPairIntInt_create(const PairIntIntHandle* data, size_t count);
void ListPairIntInt_destroy(ListPairIntIntHandle handle);
void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_size(ListPairIntIntHandle handle);
bool ListPairIntInt_empty(ListPairIntIntHandle handle);
void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx);
void ListPairIntInt_clear(ListPairIntIntHandle handle);
PairIntIntHandle ListPairIntInt_const_at(ListPairIntIntHandle handle, size_t idx);
PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx);
size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size);
bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value);
ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other);
bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);
bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);

ListPairFloatFloatHandle ListPairFloatFloat_create_empty();
ListPairFloatFloatHandle ListPairFloatFloat_allocate(size_t count);
ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value);
ListPairFloatFloatHandle ListPairFloatFloat_create(const PairFloatFloatHandle* data, size_t count);
void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle);
void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle);
bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle);
void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx);
void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle);
PairFloatFloatHandle ListPairFloatFloat_const_at(ListPairFloatFloatHandle handle, size_t idx);
PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx);
size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size);
bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
bool ListPairFloatFloat_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b);
bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b);

ListPairIntFloatHandle ListPairIntFloat_create_empty();
ListPairIntFloatHandle ListPairIntFloat_allocate(size_t count);
ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value);
ListPairIntFloatHandle ListPairIntFloat_create(const PairIntFloatHandle* data, size_t count);
void ListPairIntFloat_destroy(ListPairIntFloatHandle handle);
void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value);
size_t ListPairIntFloat_size(ListPairIntFloatHandle handle);
bool ListPairIntFloat_empty(ListPairIntFloatHandle handle);
void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx);
void ListPairIntFloat_clear(ListPairIntFloatHandle handle);
PairIntFloatHandle ListPairIntFloat_const_at(ListPairIntFloatHandle handle, size_t idx);
PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx);
size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size);
bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value);
size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value);
ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
bool ListPairIntFloat_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);
bool ListPairIntFloat_not_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);

ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty();
ListPairConnectionFloatHandle ListPairConnectionFloat_allocate(size_t count);
ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value);
ListPairConnectionFloatHandle ListPairConnectionFloat_create(const PairConnectionFloatHandle* data, size_t count);
void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle);
void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle);
bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle);
void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx);
void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle);
PairConnectionFloatHandle ListPairConnectionFloat_const_at(ListPairConnectionFloatHandle handle, size_t idx);
PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx);
size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);
bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);

ListConnectionHandle ListConnection_create_empty();
ListConnectionHandle ListConnection_allocate(size_t count);
ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value);
ListConnectionHandle ListConnection_create(const ConnectionHandle* data, size_t count);
void ListConnection_destroy(ListConnectionHandle handle);
void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_size(ListConnectionHandle handle);
bool ListConnection_empty(ListConnectionHandle handle);
void ListConnection_erase_at(ListConnectionHandle handle, size_t idx);
void ListConnection_clear(ListConnectionHandle handle);
ConnectionHandle ListConnection_const_at(ListConnectionHandle handle, size_t idx);
ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx);
size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size);
bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value);
ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other);
bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b);
bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b);

#ifdef __cplusplus
}
#endif
