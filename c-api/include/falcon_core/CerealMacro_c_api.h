#pragma once

#define DECLARE_C_API_TO_JSON(Type) \
  StringHandle Type##_to_json_string(Type##Handle handle);

#define DECLARE_C_API_FROM_JSON(Type) \
  Type##Handle Type##_from_json_string(StringHandle json);

#define DEFINE_C_API_TO_JSON(Type)                                             \
  StringHandle Type##_to_json_string(Type##Handle handle) {                    \
    FALCON_C_API_BEGIN                                                         \
    if (!handle) {                                                             \
      throw std::invalid_argument(#Type                                        \
                                  "_to_json_string: handle cannot be null");   \
    }                                                                          \
    std::shared_ptr<Type> self = *static_cast<std::shared_ptr<Type>*>(handle); \
    std::string           json = self->to_json_string();                       \
    return String_create(json.c_str(), json.size());                           \
    FALCON_C_API_END(nullptr)                                                  \
  }

#define DEFINE_C_API_FROM_JSON(Type)                                         \
  Type##Handle Type##_from_json_string(StringHandle json) {                  \
    FALCON_C_API_BEGIN                                                       \
    if (!json) {                                                             \
      throw std::invalid_argument(#Type                                      \
                                  "_from_json_string: json cannot be null"); \
    }                                                                        \
    std::string raw_json(json->raw);                                         \
    auto        ptr = Type::from_json_string<Type>(raw_json);                \
    return new std::shared_ptr<Type>(ptr);                                   \
    FALCON_C_API_END(nullptr)                                                \
  }
