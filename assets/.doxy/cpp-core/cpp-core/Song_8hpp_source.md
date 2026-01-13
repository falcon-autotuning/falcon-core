

# File Song.hpp

[**File List**](files.md) **>** [**cpp**](dir_df511e5bd85cec96854b39d5e1c27aa8.md) **>** [**include**](dir_07f37e320deb3031a60f4b23b9c60eb5.md) **>** [**falcon\_core**](dir_87508f5a35e9f3ffde0c0c6a5e60051b.md) **>** [**generic**](dir_b58ad87d7b49f24215c248c1165fe6c1.md) **>** [**Song.hpp**](Song_8hpp.md)

[Go to the documentation of this file](Song_8hpp.md)


```C++
#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <sstream>
#include <string>

namespace falcon_core {
namespace generic {
class Song {
 public:
  virtual ~Song() = default;
  std::string to_json_string() const;
  template <typename T>
  static std::shared_ptr<T> from_json_string(const std::string& json) {
    std::istringstream iss(json);
    return from_json_stream<T>(iss);
  }

  template <class Archive>
  void serialize(Archive&) {}

 private:
  void to_json_stream(std::ostream& os) const;

  template <typename T>
  static std::shared_ptr<T> from_json_stream(std::istream& is) {
    cereal::JSONInputArchive archive(is);
    std::shared_ptr<Song>    ptr;
    archive(ptr);
    auto casted = std::dynamic_pointer_cast<T>(ptr);
    if (!casted) {
      throw std::runtime_error(
          "Song: Failed to cast Song to requested type from json stream");
    }
    return casted;
  }
};
using SongSP = std::shared_ptr<Song>;
}  // namespace generic
}  // namespace falcon_core
```


