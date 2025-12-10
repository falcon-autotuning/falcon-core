#pragma once

#define DEFINE_C_API_COPY_TEMPLATE(CType, CPPType)                         \
  CType##Handle CType##_copy(CType##Handle handle) {                       \
    FALCON_C_API_BEGIN                                                     \
    if (!handle) {                                                         \
      throw std::invalid_argument(#CType "_copy: handle cannot be null");  \
    }                                                                      \
    std::shared_ptr<CPPType> self =                                        \
        *static_cast<std::shared_ptr<CPPType>*>(handle);                   \
    return new std::shared_ptr<CPPType>(std::make_shared<CPPType>(*self)); \
    FALCON_C_API_END(nullptr)                                              \
  }

#define DEFINE_C_API_COPY(Type) DEFINE_C_API_COPY_TEMPLATE(Type, Type)
