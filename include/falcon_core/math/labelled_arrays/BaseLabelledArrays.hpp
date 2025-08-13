#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"

#include <memory>
#include <vector>

namespace falcon_core
{
namespace math
{
namespace labelled_arrays
{
template <typename T> class BaseLabelledArrays : public generic::Song
{
public:
  using value_type     = T;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  BaseLabelledArrays () = default;

  void
  append (const std::shared_ptr<value_type> &labelled_array)
  {
    _arrays.push_back (labelled_array);
  }

  const container_type &
  get_arrays () const
  {
    return _arrays;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j,
                  "falcon_core.math.labelled_arrays.base_labelled_arrays",
                  "BaseLabelledArrays");
    nlohmann::json arrays_json = nlohmann::json::array ();
    for (const auto &arr : _arrays)
      {
        arrays_json.push_back (arr->to_json ());
      }
    j["_arrays"] = arrays_json;
    return j;
  }

  size_t
  hash () const override
  {
    size_t seed = _arrays.size ();
    for (const auto &arr : _arrays)
      {
        seed ^= arr->hash () + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
    return seed;
  }

private:
  container_type _arrays;
};
}
}
} // namespace falcon_core
