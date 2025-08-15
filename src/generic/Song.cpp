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
template <typename T>
std::shared_ptr<T> Song::from_json_stream(std::istream& is) {
  cereal::JSONInputArchive archive(is);
  std::shared_ptr<Song>    ptr;
  archive(ptr);
  return std::dynamic_pointer_cast<T>(ptr);
}

template <typename T>
std::shared_ptr<T> Song::from_json_string(const std::string& json) {
  std::istringstream iss(json);
  return from_json_stream<T>(iss);
}

bool Song::operator==(const Song& other) const {
  return to_json_string() == other.to_json_string();
}
namespace std {
template <>
struct hash<Song> {
  std::size_t operator()(const falcon_core::generic::Song& s) const {
    return std::hash<std::string>()(s.to_json_string());
  };
};
}  // namespace std
CEREAL_REGISTER_TYPE(Song)
