#include "falcon_core/generic/Song.hpp"

#include "falcon_core/constants.hpp"

namespace falcon_core
{

using generic::Song;
std::string
Song::to_json_string () const
{
  return to_json ().dump (4);
}

void
Song::add_metadata (nlohmann::json    &j,
                    const std::string &module_name,
                    const std::string &class_name) const
{
  j[JSONABLE_MODULE_METADATA] = module_name;
  j[JSONABLE_CLASS_METADATA]  = class_name;
}

} // namespace falcon_core
