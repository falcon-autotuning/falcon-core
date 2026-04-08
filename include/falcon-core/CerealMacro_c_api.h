#pragma once

#define DEFINE_C_API_TO_JSON_TEMPLATE(CType, CPPType)                        \
  StringHandle CType##_to_json_string(CType##Handle handle) {                \
    FALCON_C_API_BEGIN                                                       \
    if (!handle) {                                                           \
      throw std::invalid_argument(#CType                                     \
                                  "_to_json_string: handle cannot be null"); \
    }                                                                        \
    std::shared_ptr<CPPType> self =                                          \
        *static_cast<std::shared_ptr<CPPType>*>(handle);                     \
    std::string json = self->to_json_string();                               \
    return String_create(json.c_str(), json.size());                         \
    FALCON_C_API_END(nullptr)                                                \
  }

#define DEFINE_C_API_TO_JSON(Type) DEFINE_C_API_TO_JSON_TEMPLATE(Type, Type)

#define DEFINE_C_API_FROM_JSON_TEMPLATE(CType, CPPType)                      \
  CType##Handle CType##_from_json_string(StringHandle json) {                \
    FALCON_C_API_BEGIN                                                       \
    if (!json) {                                                             \
      throw std::invalid_argument(#CType                                     \
                                  "_from_json_string: json cannot be null"); \
    }                                                                        \
    std::string raw_json(json->raw);                                         \
    auto        ptr = CPPType::from_json_string<CPPType>(raw_json);          \
    return new std::shared_ptr<CPPType>(ptr);                                \
    FALCON_C_API_END(nullptr)                                                \
  }

#define DEFINE_C_API_FROM_JSON(Type) \
  DEFINE_C_API_FROM_JSON_TEMPLATE(Type, Type)
