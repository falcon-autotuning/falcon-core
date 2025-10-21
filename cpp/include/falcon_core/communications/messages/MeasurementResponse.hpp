#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>

#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

class MeasurementResponse : public BaseMessage {
  math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray> _arrays;

 public:
  MeasurementResponse(
      const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
          arrays);

  const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
       arrays() const;
  bool operator==(const MeasurementResponse& other) const;
  bool operator!=(const MeasurementResponse& other) const;

 protected:
  MeasurementResponse();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this), _arrays);
  }
};
using MeasurementResponseSP = std::shared_ptr<MeasurementResponse>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
