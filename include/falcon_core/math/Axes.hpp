#pragma once

#include <memory>
#include <vector>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace math {

template <typename T>
class Axes : public generic::Song {
 public:
  using value_type     = std::shared_ptr<T>;
  using container_type = std::vector<value_type>;

  Axes() = default;
  explicit Axes(container_type items) : _items(std::move(items)) {}

  void append(const value_type &item) { _items.push_back(item); }

  const value_type &at(size_t index) const { return _items.at(index); }

  size_t size() const { return _items.size(); }

  bool empty() const { return _items.empty(); }

  typename container_type::const_iterator begin() const {
    return _items.begin();
  }
  typename container_type::const_iterator end() const { return _items.end(); }

 private:
  container_type _items;
};
}  // namespace math
}  // namespace falcon_core
