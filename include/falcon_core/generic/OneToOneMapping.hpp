#pragma once

#include "falcon_core/generic/Jsonable.hpp"

#include <map>
#include <nlohmann/json.hpp>
#include <stdexcept>

namespace falcon_core
{

template <typename K, typename V> class OneToOneMapping : public Jsonable
{
public:
  OneToOneMapping () = default;

  void
  insert (const K &key, const V &value)
  {
    if (_forward.count (key))
      {
        throw std::invalid_argument ("Key already exists.");
      }
    if (_backward.count (value))
      {
        throw std::invalid_argument ("Value already exists.");
      }
    _forward[key]    = value;
    _backward[value] = key;
  }

  const V &
  at_key (const K &key) const
  {
    return _forward.at (key);
  }

  const K &
  at_value (const V &value) const
  {
    return _backward.at (value);
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (
        j, "falcon_core.generic.one_to_one_mapping", "OneToOneMapping");
    // Note: JSON keys must be strings. This serialization is a simplification.
    // A full implementation would need to handle non-string-convertible keys.
    for (const auto &pair : _forward)
      {
        j[pair.first] = pair.second;
      }
    return j;
  }

  size_t
  hash () const override
  {
    // A proper hash would iterate over elements. This is a placeholder.
    return _forward.size ();
  }

private:
  std::map<K, V> _forward;
  std::map<V, K> _backward;
};

} // namespace falcon_core
