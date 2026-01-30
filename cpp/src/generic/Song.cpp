#include "falcon_core/generic/Song.hpp"

#include <sstream>

namespace falcon_core {
namespace generic {
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

}  // namespace generic
}  // namespace falcon_core
