#include <falcon_core/communications/messages/MeasurementResponse.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

MeasurementResponse::MeasurementResponse() = default;
MeasurementResponse::MeasurementResponse(
    const std::shared_ptr<math::arrays::LabelledMeasuredArrays>& arrays)
    : _arrays(arrays) {}

const std::shared_ptr<math::arrays::LabelledMeasuredArrays>&
MeasurementResponse::arrays() const {
  return _arrays;
}

template <class Archive>
void MeasurementResponse::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this), _arrays);
}

template void MeasurementResponse::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive& ar);
template void MeasurementResponse::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
