#pragma once

#include "falcon_core/generic/Song.hpp"

#include <memory>
#include <nlohmann/json.hpp>
#include <vector>

namespace falcon_core
{
namespace math
{

template <typename T> class Axes : public generic::Song
{
public:
  using value_type     = std::shared_ptr<T>;
  using container_type = std::vector<value_type>;

  Axes () = default;
  explicit Axes (container_type items) : _items (std::move (items)) {}

  void
  append (const value_type &item)
  {
    _items.push_back (item);
  }

  const value_type &
  at (size_t index) const
  {
    return _items.at (index);
  }

  size_t
  size () const
  {
    return _items.size ();
  }

  bool
  empty () const
  {
    return _items.empty ();
  }

  typename container_type::const_iterator
  begin () const
  {
    return _items.begin ();
  }
  typename container_type::const_iterator
  end () const
  {
    return _items.end ();
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j, "falcon_core.math.axes", "Axes");
    nlohmann::json items_json = nlohmann::json::array ();
    for (const auto &item : _items)
      {
        items_json.push_back (item->to_json ());
      }
    j["_items"] = items_json;
    return j;
  }

  size_t
  hash () const override
  {
    size_t seed = _items.size ();
    for (const auto &item : _items)
      {
        seed ^= item->hash () + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
    return seed;
  }

private:
  container_type _items;
};
}
} // namespace falcon_core
