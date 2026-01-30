#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <stdexcept>

#include "falcon_core/communications/messages/BaseMessage.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core {
namespace communications {
namespace messages {
MeasurementResponse::MeasurementResponse(const MeasurementResponse& other)
    : BaseMessage(other) {
  std::unique_lock<std::shared_timed_mutex> lock_o(_mu_arrays);
  if (!other._arrays) {
    throw std::invalid_argument(
        "MeasurementResponse copy constructor: Other MeasurementResponse "
        "contains null shared pointer.");
  }
  _arrays = std::make_shared<
      math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
      *other.arrays());
}
MeasurementResponse& MeasurementResponse::operator=(
    const MeasurementResponse& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_o(_mu_arrays);
    if (!other._arrays) {
      throw std::invalid_argument(
          "MeasurementResponse copy constructor: Other MeasurementResponse "
          "contains null shared pointer.");
    }
    _arrays = std::make_shared<
        math::arrays::LabelledArrays<math::arrays::LabelledMeasuredArray>>(
        *other.arrays());
    BaseMessage::operator=(other);
  }
  return *this;
}
MeasurementResponse::MeasurementResponse() = default;
MeasurementResponse::MeasurementResponse(
    const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
        arrays)
    : _arrays(arrays), BaseMessage() {
  if (!arrays) {
    throw std::invalid_argument(
        "MeasurementResponse: The arrays must not be null.");
  }
}

const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
MeasurementResponse::arrays() const {
  std::shared_lock<std::shared_timed_mutex> lock_a(_mu_arrays);
  return _arrays;
}
bool MeasurementResponse::operator==(const MeasurementResponse& other) const {
  if (this == &other) return true;
  return (*arrays() == *other.arrays()) && BaseMessage::operator==(other);
}
bool MeasurementResponse::operator!=(const MeasurementResponse& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
