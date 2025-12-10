#pragma once

#define DECLARE_C_API_COPY(Type) Type##Handle Type##_copy(Type##Handle handle);

#define DEFINE_C_API_COPY(Type)                                                \
  extern "C" Type##Handle Type##_copy(Type##Handle handle) {                   \
    FALCON_C_API_BEGIN                                                         \
    if (!handle) {                                                             \
      throw std::invalid_argument(#Type "_copy: handle cannot be null");       \
    }                                                                          \
    std::shared_ptr<Type> self = *static_cast<std::shared_ptr<Type>*>(handle); \
    return new std::shared_ptr<Type>(std::make_shared<Type>(*self));           \
    FALCON_C_API_END(nullptr)                                                  \
  }
