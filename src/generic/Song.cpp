#include "falcon_core/generic/Song.hpp"

#include <sstream>

using namespace falcon_core::generic;
std::string Song::to_json_string() const {
  std::ostringstream oss;
  to_json_stream(oss);
  return oss.str();
}

void Song::to_json_stream(std::ostream& os) const {
  cereal::JSONOutputArchive   archive(os);
  std::shared_ptr<const Song> ptr(this, [](const Song*) {});
  archive(ptr);
}

bool Song::operator==(const Song& other) const {
  return to_json_string() == other.to_json_string();
}

// Hash specialization for Song
namespace std {
template <>
struct hash<falcon_core::generic::Song> {
  std::size_t operator()(const falcon_core::generic::Song& s) const {
    return std::hash<std::string>()(s.to_json_string());
  }
};
}  // namespace std

CEREAL_REGISTER_TYPE(Song)
