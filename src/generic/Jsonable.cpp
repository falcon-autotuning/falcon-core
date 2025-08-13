#include "falcon_core/generic/Jsonable.hpp"

#include "falcon_core/constants.hpp"

namespace falcon_core
{

std::string
Jsonable::to_json_string () const
{
  return to_json ().dump (4);
}

void
Jsonable::add_metadata (nlohmann::json    &j,
                        const std::string &module_name,
                        const std::string &class_name) const
{
  j[constants::JSONABLE_MODULE_METADATA] = module_name;
  j[constants::JSONABLE_CLASS_METADATA]  = class_name;
}

} // namespace falcon_core
