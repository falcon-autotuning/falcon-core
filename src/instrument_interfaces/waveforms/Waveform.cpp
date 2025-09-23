#include "falcon_core/instrument_interfaces/waveforms/Waveform.hpp"

namespace falcon_core::instrument_interfaces::waveforms {
Waveform::Waveform() : BaseWaveform() {}
Waveform::Waveform(
    const math::discrete_spaces::BaseDiscreteSpaceSP      space,
    const generic::ListSP<port_transforms::PortTransform> transforms)
    : BaseWaveform<falcon_core::math::discrete_spaces::BaseDiscreteSpace>(
          space, transforms) {}
}  // namespace falcon_core::instrument_interfaces::waveforms
CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::waveforms::Waveform)
CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::BaseDiscreteSpace>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::waveforms::BaseWaveform<
        falcon_core::math::discrete_spaces::BaseDiscreteSpace>,
    falcon_core::instrument_interfaces::waveforms::Waveform)
