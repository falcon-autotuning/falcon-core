#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArrays.hpp>

namespace falcon_core::communications::messages {

class MeasurementResponse : public BaseMessage {
  math::arrays::LabelledMeasuredArraysSP _arrays;

 public:
  MeasurementResponse(const math::arrays::LabelledMeasuredArraysSP& arrays);

  const math::arrays::LabelledMeasuredArraysSP& arrays() const;

 protected:
  MeasurementResponse();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this), _arrays);
  }
};
using MeasurementResponseSP = std::shared_ptr<MeasurementResponse>;
}  // namespace falcon_core::communications::messages
