#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArrays.hpp>
#include <memory>

namespace falcon_core {
namespace communications {
namespace messages {

class MeasurementResponse : public BaseMessage {
 public:
  MeasurementResponse();
  MeasurementResponse(
      const std::shared_ptr<math::arrays::LabelledMeasuredArrays>& arrays);

  const std::shared_ptr<math::arrays::LabelledMeasuredArrays>& arrays() const;

 private:
  std::shared_ptr<math::arrays::LabelledMeasuredArrays> _arrays;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};
using MeasurementResponseSP = std::shared_ptr<MeasurementResponse>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
