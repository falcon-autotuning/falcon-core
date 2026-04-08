#include "falcon-core/math/arrays/LabelledControlArray_c_api.h"

#include <falcon-core/math/arrays/LabelledControlArray.hpp>
#include <xtensor/xadapt.hpp>

#include "falcon-core/Precompiled_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
DEFINE_C_API_COPY(LabelledControlArray);
DEFINE_C_API_DESTROY(LabelledControlArray);
DEFINE_C_API_EQUAL(LabelledControlArray);
DEFINE_C_API_NOT_EQUAL(LabelledControlArray);
DEFINE_C_API_TO_JSON(LabelledControlArray);
DEFINE_C_API_FROM_JSON(LabelledControlArray);
LabelledControlArrayHandle LabelledControlArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_from_farray");
  }
  if (!label) {
    throw std::invalid_argument(
        "Null label handle passed to LabelledControlArray_from_farray");
  }
  generic::FArraySP<double> real_farray =
      *static_cast<generic::FArraySP<double>*>(farray);
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      *static_cast<autotuner_interfaces::contexts::AcquisitionContextSP*>(
          label);
  return new LabelledControlArraySP(
      std::make_shared<LabelledControlArray>(real_farray, real_label));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!controlarray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_from_controlarray");
  }
  if (!label) {
    throw std::invalid_argument(
        "Null label handle passed to LabelledControlArray_from_controlarray");
  }
  ControlArraySP real_controlarray =
      *static_cast<ControlArraySP*>(controlarray);
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      *static_cast<autotuner_interfaces::contexts::AcquisitionContextSP*>(
          label);
  return new LabelledControlArraySP(
      std::make_shared<LabelledControlArray>(real_controlarray, real_label));
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle LabelledControlArray_label(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_label");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new autotuner_interfaces::contexts::AcquisitionContextSP(
      labelled_control_array->label());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledControlArray_connection(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_connection");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new physics::device_structures::ConnectionSP(
      labelled_control_array->connection());
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledControlArray_instrument_type(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_instrument_type");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return String_create(labelled_control_array->instrument_type().c_str(),
                       labelled_control_array->instrument_type().size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle LabelledControlArray_units(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_units");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new physics::units::SymbolUnitSP(labelled_control_array->units());
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray_size(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_size");
  }
  auto labelled_control_array = *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray_dimension(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_dimension");
  }
  auto labelled_control_array = *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->dimension();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray_shape(LabelledControlArrayHandle handle,
                                  size_t*                    out_buffer,
                                  size_t                     ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_shape");
  }
  auto   labelled_control_array = *static_cast<LabelledControlArraySP*>(handle);
  auto   shape                  = labelled_control_array->shape();
  size_t count                  = shape.size();
  size_t to_copy                = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t LabelledControlArray_data(LabelledControlArrayHandle handle,
                                 double*                    out_buffer,
                                 size_t                     numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_data");
  }
  auto   labelled_control_array = *static_cast<LabelledControlArraySP*>(handle);
  auto   data                   = labelled_control_array->data();
  size_t count                  = labelled_control_array->size();
  size_t to_copy                = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void LabelledControlArray_plus_equals_farray(LabelledControlArrayHandle handle,
                                             FArrayDoubleHandle         other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_equals_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  labelled_control_array->operator+=(*oarray);
  FALCON_C_API_END()
}

void LabelledControlArray_plus_equals_double(LabelledControlArrayHandle handle,
                                             const double               other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_equals_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator+=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_plus_equals_int(LabelledControlArrayHandle handle,
                                          const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_equals_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator+=(other);
  FALCON_C_API_END()
}

LabelledControlArrayHandle LabelledControlArray_plus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_control_array");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  return new LabelledControlArraySP(labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_plus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArraySP(labelled_control_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_plus_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_plus_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_minus_equals_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray_minus_equals_control_array");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  labelled_control_array->operator-=(*oarray);
  FALCON_C_API_END()
}

void LabelledControlArray_minus_equals_farray(LabelledControlArrayHandle handle,
                                              FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_equals_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  labelled_control_array->operator-=(*oarray);
  FALCON_C_API_END()
}

void LabelledControlArray_minus_equals_double(LabelledControlArrayHandle handle,
                                              const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_equals_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator-=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_minus_equals_int(LabelledControlArrayHandle handle,
                                           const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_equals_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator-=(other);
  FALCON_C_API_END()
}

LabelledControlArrayHandle LabelledControlArray_minus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_control_array");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  return new LabelledControlArraySP(labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_minus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArraySP(labelled_control_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_minus_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_minus_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_negation(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_negation");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(-*labelled_control_array);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_times_equals_double(LabelledControlArrayHandle handle,
                                              const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_times_equals_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator*=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_times_equals_int(LabelledControlArrayHandle handle,
                                           const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_times_equals_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator*=(other);
  FALCON_C_API_END()
}

LabelledControlArrayHandle LabelledControlArray_times_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_times_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_times_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_times_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_divides_equals_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_divides_equals_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator/=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_divides_equals_int(LabelledControlArrayHandle handle,
                                             const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_divides_equals_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->operator/=(other);
  FALCON_C_API_END()
}

LabelledControlArrayHandle LabelledControlArray_divides_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_divides_double");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_divides_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_divides_int");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_pow(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_pow");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_abs(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_abs");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->abs());
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray_min(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_min");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->min();
  FALCON_C_API_END(0.0)
}

LabelledControlArrayHandle LabelledControlArray_min_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_min_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArraySP(labelled_control_array->min(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_min_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_min_control_array");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  return new LabelledControlArraySP(labelled_control_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray_max(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_max");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->max();
  FALCON_C_API_END(0.0)
}

LabelledControlArrayHandle LabelledControlArray_max_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_max_farray");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArraySP(labelled_control_array->max(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_max_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_max_control_array");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  return new LabelledControlArraySP(labelled_control_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

bool LabelledControlArray_greater_than(LabelledControlArrayHandle handle,
                                       const double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_greater_than");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->operator>(value);
  FALCON_C_API_END(false)
}

bool LabelledControlArray_less_than(LabelledControlArrayHandle handle,
                                    const double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_less_than");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->operator<(value);
  FALCON_C_API_END(false)
}

void LabelledControlArray_remove_offset(LabelledControlArrayHandle handle,
                                        const double               offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_remove_offset");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  labelled_control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledControlArray_sum(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_sum");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->sum();
  FALCON_C_API_END(0.0)
}

LabelledControlArrayHandle LabelledControlArray_reshape(
    LabelledControlArrayHandle handle, const size_t* shape, size_t ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_reshape");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledControlArraySP(labelled_control_array->reshape(new_shape));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle LabelledControlArray_where(
    LabelledControlArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_where");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  auto indices = labelled_control_array->where(value);
  return new generic::ListSP<generic::List<size_t>>(indices);
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_flip(
    LabelledControlArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_flip");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new LabelledControlArraySP(labelled_control_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray_full_gradient(LabelledControlArrayHandle handle,
                                          FArrayDoubleHandle*        out_buffer,
                                          size_t buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_full_gradient");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  auto   gradients = labelled_control_array->gradient();
  size_t count     = gradients->size();
  size_t to_copy   = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArraySP<double>(gradients->items()[i]);
  }
  return to_copy;
  FALCON_C_API_END(0)
}

FArrayDoubleHandle LabelledControlArray_gradient(
    LabelledControlArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_gradient");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return new generic::FArraySP<double>(labelled_control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray_get_sum_of_squares(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_get_sum_of_squares");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray_get_summed_diff_int_of_squares(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray_get_summed_diff_int_of_squares");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledControlArray_get_summed_diff_double_of_squares(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray_get_summed_diff_double_of_squares");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledControlArray_get_summed_diff_array_of_squares(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray_get_summed_diff_array_of_squares");
  }
  LabelledControlArraySP labelled_control_array =
      *static_cast<LabelledControlArraySP*>(handle);
  LabelledControlArraySP oarray = *static_cast<LabelledControlArraySP*>(other);
  return labelled_control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}
}
