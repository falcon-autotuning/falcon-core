#pragma once
#ifdef __cplusplus
extern "C" {
#endif

typedef void* ChannelHandle;

// Constructors
ChannelHandle Channel_create(const char* name);

// Destructor
void Channel_destroy(ChannelHandle handle);

// Methods
const char* Channel_name(ChannelHandle handle);
bool        Channel_equal(ChannelHandle a, ChannelHandle b);
bool        Channel_not_equal(ChannelHandle a, ChannelHandle b);

// Serialization (from Song)
const char*   Channel_to_json_string(ChannelHandle handle);
ChannelHandle Channel_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
