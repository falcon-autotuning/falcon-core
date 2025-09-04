#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/math/labelled_arrays/LabelledMeasuredArrays.hpp>
#include <memory>

namespace falcon_core {
namespace communications {
namespace messages {

class MeasurementResponse : public BaseMessage {
 public:
  MeasurementResponse();
  MeasurementResponse(const std::shared_ptr<math::labelled_arrays::LabelledMeasuredArrays>& arrays);

  const std::shared_ptr<math::labelled_arrays::LabelledMeasuredArrays>& arrays() const;

 private:
  std::shared_ptr<math::labelled_arrays::LabelledMeasuredArrays> _arrays;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
