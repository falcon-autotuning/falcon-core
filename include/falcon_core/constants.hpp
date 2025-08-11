#pragma once

#include <string_view>
#include <set>

namespace falcon_core::constants {

constexpr std::string_view JSONABLE_ATTRIBUTE_INDICATOR = "_";

constexpr std::string_view JSONABLE_CLASS_METADATA = "__class__";
constexpr std::string_view JSONABLE_MODULE_METADATA = "__module__";
constexpr std::string_view JSONABLE_KEY = "__jsonable_key__";
constexpr std::string_view JSONABLE_BLOB = "__binary_blob__";
constexpr std::string_view JSONABLE_TYPE_VAR = "__jsonable_type__";
constexpr std::string_view JSONABLE_FUNCTION = "__jsonable_function__";
constexpr std::string_view JSONABLE_FUNCTION_DILL = "__function_dill__";

// Cannot make a constexpr set easily before C++20. A function is fine.
inline std::set<std::string_view> get_jsonable_metadata() {
    return {
        JSONABLE_CLASS_METADATA,
        JSONABLE_MODULE_METADATA
    };
}

} // namespace falcon_core::constants
