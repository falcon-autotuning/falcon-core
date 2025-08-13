#pragma once

#include <set>
#include <string>

namespace falcon_core
{

const char *const JSONABLE_ATTRIBUTE_INDICATOR = "_";

const char *const JSONABLE_CLASS_METADATA  = "__class__";
const char *const JSONABLE_MODULE_METADATA = "__module__";
const char *const JSONABLE_KEY             = "__jsonable_key__";
const char *const JSONABLE_BLOB            = "__binary_blob__";
const char *const JSONABLE_TYPE_VAR        = "__jsonable_type__";
const char *const JSONABLE_FUNCTION        = "__jsonable_function__";
const char *const JSONABLE_FUNCTION_DILL   = "__function_dill__";

// Cannot make a constexpr set easily before C++20. A function is fine.
inline std::set<std::string>
get_jsonable_metadata ()
{
  return { JSONABLE_CLASS_METADATA, JSONABLE_MODULE_METADATA };
}

} // namespace falcon_core::constants
