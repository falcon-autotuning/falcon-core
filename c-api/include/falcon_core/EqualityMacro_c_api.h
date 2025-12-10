#pragma once

#define DEFINE_C_API_EQUAL_TEMPLATE(CType, CPPType)                        \
  bool CType##_equal(CType##Handle handle, CType##Handle other) {          \
    FALCON_C_API_BEGIN                                                     \
    if (!handle) {                                                         \
      throw std::invalid_argument(#CType "_equal: handle cannot be null"); \
    }                                                                      \
    if (!other) {                                                          \
      throw std::invalid_argument(#CType "_equal: handle cannot be null"); \
    }                                                                      \
    std::shared_ptr<CPPType> self_handle =                                 \
        *static_cast<std::shared_ptr<CPPType>*>(handle);                   \
    std::shared_ptr<CPPType> self_other =                                  \
        *static_cast<std::shared_ptr<CPPType>*>(other);                    \
    return *self_handle == *self_other;                                    \
    FALCON_C_API_END(false)                                                \
  }

#define DEFINE_C_API_EQUAL(Type) DEFINE_C_API_EQUAL_TEMPLATE(Type, Type)

#define DEFINE_C_API_NOT_EQUAL_TEMPLATE(CType, CPPType)                        \
  bool CType##_not_equal(CType##Handle handle, CType##Handle other) {          \
    FALCON_C_API_BEGIN                                                         \
    if (!handle) {                                                             \
      throw std::invalid_argument(#CType "_not_equal: handle cannot be null"); \
    }                                                                          \
    if (!other) {                                                              \
      throw std::invalid_argument(#CType "_not_equal: handle cannot be null"); \
    }                                                                          \
    std::shared_ptr<CPPType> self_handle =                                     \
        *static_cast<std::shared_ptr<CPPType>*>(handle);                       \
    std::shared_ptr<CPPType> self_other =                                      \
        *static_cast<std::shared_ptr<CPPType>*>(other);                        \
    return *self_handle != *self_other;                                        \
    FALCON_C_API_END(false)                                                    \
  }

#define DEFINE_C_API_NOT_EQUAL(Type) DEFINE_C_API_NOT_EQUAL_TEMPLATE(Type, Type)
