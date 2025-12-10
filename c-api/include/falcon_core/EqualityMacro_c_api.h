#pragma once

#define DECLARE_C_API_EQUAL(Type) \
  bool Type##_equal(Type##Handle handle, Type##Handle other);

#define DECLARE_C_API_NOT_EQUAL(Type) \
  bool Type##_equal(Type##Handle handle, Type##Handle other);

#define DEFINE_C_API_EQUAL(Type)                                          \
  bool Type##_equal(Type##Handle handle, Type##Handle other) {            \
    FALCON_C_API_BEGIN                                                    \
    if (!handle) {                                                        \
      throw std::invalid_argument(#Type "_equal: handle cannot be null"); \
    }                                                                     \
    if (!other) {                                                         \
      throw std::invalid_argument(#Type "_equal: handle cannot be null"); \
    }                                                                     \
    TypeSP self_handle = *static_cast<std::shared_ptr<Type>*>(handle);    \
    TypeSP self_other  = *static_cast<std::shared_ptr<Type>*>(other);     \
    return *self_handle == *self_other;                                   \
    FALCON_C_API_END(false)                                               \
  }

#define DEFINE_C_API_NOT_EQUAL(Type)                                      \
  bool Type##_not_equal(Type##Handle a, Type##Handle b) {                 \
    FALCON_C_API_BEGIN                                                    \
    if (!handle) {                                                        \
      throw std::invalid_argument(#Type "_equal: handle cannot be null"); \
    }                                                                     \
    if (!other) {                                                         \
      throw std::invalid_argument(#Type "_equal: handle cannot be null"); \
    }                                                                     \
    TypeSP self_handle = *static_cast<std::shared_ptr<Type>*>(handle);    \
    TypeSP self_other  = *static_cast<std::shared_ptr<Type>*>(other);     \
    return *self_handle != *self_other;                                   \
    FALCON_C_API_END(false)                                               \
  }
