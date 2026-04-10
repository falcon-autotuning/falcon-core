#include "falcon-core/autotuner_interfaces/names/Channels.hpp"

namespace falcon_core {
namespace generic {
template class List<autotuner_interfaces::names::Channel>;
}
namespace autotuner_interfaces {
namespace names {

Channels::Channels() = default;
Channels::Channels(const std::vector<std::shared_ptr<Channel>>& vec)
    : falcon_core::generic::List<Channel>(vec) {}

bool Channels::operator==(const Channels& other) const {
  if (this == &other) return true;
  return generic::List<Channel>::operator==(other);
}

bool Channels::operator!=(const Channels& other) const {
  return !(*this == other);
}

}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
