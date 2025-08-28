#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

template <typename LabelType>
LabelledMeasuredArray<LabelType>::LabelledMeasuredArray(
    std::shared_ptr<arrays::MeasuredArray<double>> array,
    std::shared_ptr<LabelType> label)
    : BaseLabelledArray<arrays::MeasuredArray<double>, LabelType>(array, label) {}

template <typename LabelType>
LabelledMeasuredArray<LabelType>::LabelledMeasuredArray() = default;

template <typename LabelType>
template <class Archive>
void LabelledMeasuredArray<LabelType>::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledArray<arrays::MeasuredArray<double>, LabelType>>(this));
}

// Explicit instantiation for Gate label
using GateLabel = falcon_core::instrument_interfaces::names::InstrumentPort<
    falcon_core::physics::device_structures::Gate>;
template class LabelledMeasuredArray<GateLabel>;
template void LabelledMeasuredArray<GateLabel>::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive&);
template void LabelledMeasuredArray<GateLabel>::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive&);

}}} // namespace

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledMeasuredArray<
    falcon_core::instrument_interfaces::names::InstrumentPort<
        falcon_core::physics::device_structures::Gate>>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledMeasuredArray<
        falcon_core::instrument_interfaces::names::InstrumentPort<
            falcon_core::physics::device_structures::Gate>>)
