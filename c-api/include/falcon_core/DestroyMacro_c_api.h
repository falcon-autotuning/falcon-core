#pragma once

#define DEFINE_C_API_DESTROY_TEMPLATE(CType, CPPType)                        \
  void CType##_destroy(CType##Handle handle) {                               \
    FALCON_C_API_BEGIN                                                       \
    if (!handle) {                                                           \
      throw std::invalid_argument(#CType "_destroy: handle cannot be null"); \
    }                                                                        \
    delete static_cast<std::shared_ptr<CPPType>*>(handle);                   \
    FALCON_C_API_END()                                                       \
  }

#define DEFINE_C_API_DESTROY(Type) DEFINE_C_API_DESTROY_TEMPLATE(Type, Type)
