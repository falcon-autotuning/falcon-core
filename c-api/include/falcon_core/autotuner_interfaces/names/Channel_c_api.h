#pragma once
#ifdef __cplusplus
#include "falcon_core/generic/String_c_api.h"
extern "C" {
#endif

typedef void* ChannelHandle;

// Constructors
ChannelHandle Channel_create(StringHandle name);

// Destructor
void Channel_destroy(ChannelHandle handle);

// Methods
StringHandle Channel_name(ChannelHandle handle);
bool         Channel_equal(ChannelHandle a, ChannelHandle b);
bool         Channel_not_equal(ChannelHandle a, ChannelHandle b);

// Serialization (from Song)
StringHandle  Channel_to_json_string(ChannelHandle handle);
ChannelHandle Channel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
