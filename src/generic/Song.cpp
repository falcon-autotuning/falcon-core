#include "falcon_core/generic/Song.hpp"

#include <sstream>

namespace falcon_core::generic {
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
bool Song::operator!=(const Song& other) const { return !(*this == other); }

}  // namespace falcon_core::generic

CEREAL_REGISTER_TYPE(falcon_core::generic::Song)
