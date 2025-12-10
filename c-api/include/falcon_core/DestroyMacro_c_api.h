#pragma once

#define DECLARE_C_API_DESTROY(Type) void Type##_destroy(Type##Handle handle);

#define DEFINE_C_API_DESTROY(Type)                                          \
  extern "C" void Type##_destroy(Type##Handle handle) {                     \
    FALCON_C_API_BEGIN                                                      \
    if (!handle) {                                                          \
      throw std::invalid_argument(#Type "_destroy: handle cannot be null"); \
    }                                                                       \
    delete static_cast<std::shared_ptr<Type>*>(handle);                     \
    FALCON_C_API_END()                                                      \
  }
