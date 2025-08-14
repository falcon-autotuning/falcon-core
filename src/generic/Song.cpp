#include "falcon_core/generic/Song.hpp"

using namespace falcon_core::generic;
std::string Song::to_json_string() const {
  std::ostringstream oss;
  to_json_stream(oss);
  return oss.str();
}

void Song::to_json_stream(std::ostream& os) const {
  cereal::JSONOutputArchive archive(os);
  archive(*this);
}

std::shared_ptr<Song> Song::from_json_string(const std::string& json) {
  std::istringstream iss(json);
  return from_json_stream(iss);
}

std::shared_ptr<Song> Song::from_json_stream(std::istream& is) {
  cereal::JSONInputArchive archive(is);
  std::shared_ptr<Song>    ptr;
  archive(ptr);
  return ptr;
}
CEREAL_REGISTER_TYPE(Song)
