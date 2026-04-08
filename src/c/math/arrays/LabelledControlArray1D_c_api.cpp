#include "falcon-core/math/arrays/LabelledControlArray1D_c_api.h"

#include <falcon-core/math/arrays/LabelledControlArray1D.hpp>
#include <xtensor/xadapt.hpp>

#include "falcon-core/Precompiled_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
DEFINE_C_API_COPY(LabelledControlArray1D);
DEFINE_C_API_DESTROY(LabelledControlArray1D);
DEFINE_C_API_EQUAL(LabelledControlArray1D);
DEFINE_C_API_NOT_EQUAL(LabelledControlArray1D);
DEFINE_C_API_TO_JSON(LabelledControlArray1D);
DEFINE_C_API_FROM_JSON(LabelledControlArray1D);
LabelledControlArray1DHandle LabelledControlArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_from_farray");
  }
  if (!label) {
    throw std::invalid_argument(
        "Null label handle passed to LabelledControlArray1D_from_farray");
  }
  generic::FArraySP<double> real_farray =
      *static_cast<generic::FArraySP<double>*>(farray);
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      *static_cast<autotuner_interfaces::contexts::AcquisitionContextSP*>(
          label);
  return new LabelledControlArray1DSP(
      std::make_shared<LabelledControlArray1D>(real_farray, real_label));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!controlarray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_from_controlarray");
  }
  if (!label) {
    throw std::invalid_argument(
        "Null label handle passed to LabelledControlArray1D_from_controlarray");
  }
  ControlArraySP real_controlarray =
      *static_cast<ControlArraySP*>(controlarray);
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      *static_cast<autotuner_interfaces::contexts::AcquisitionContextSP*>(
          label);
  return new LabelledControlArray1DSP(
      std::make_shared<LabelledControlArray1D>(real_controlarray, real_label));
  FALCON_C_API_END(nullptr)
}

bool LabelledControlArray1D_is_1D(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_1D");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->is_1D();
  FALCON_C_API_END(false)
}

FArrayDoubleHandle LabelledControlArray1D_as_1D(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_as_1D");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> data = labelled_control_array->as_1D();
  return new generic::FArraySP<double>(data);
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_get_start(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_start");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_start();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_end(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_end");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_end();
  FALCON_C_API_END(0.0)
}

bool LabelledControlArray1D_is_decreasing(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_decreasing");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->is_decreasing();
  FALCON_C_API_END(false)
}

bool LabelledControlArray1D_is_increasing(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_increasing");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->is_increasing();
  FALCON_C_API_END(false)
}

double LabelledControlArray1D_get_distance(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_distance");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_distance();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_mean(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_mean");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_mean();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_std(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_std");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_std();
  FALCON_C_API_END(0.0)
}

void LabelledControlArray1D_reverse(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_reverse");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->reverse();
  FALCON_C_API_END()
}

size_t LabelledControlArray1D_get_closest_index(
    LabelledControlArray1DHandle handle, double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_closest_index");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_closest_index(value);
  FALCON_C_API_END(0)
}

ListFArrayDoubleHandle LabelledControlArray1D_even_divisions(
    LabelledControlArray1DHandle handle, size_t divisions) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_even_divisions");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto divisions_arrays = labelled_control_array->even_divisions(divisions);
  return new generic::ListSP<generic::FArray<double>>(divisions_arrays);
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle LabelledControlArray1D_label(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_label");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto label                  = labelled_control_array->label();
  return new autotuner_interfaces::contexts::AcquisitionContextSP(label);
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledControlArray1D_connection(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_connection");
  }
  return new physics::device_structures::ConnectionSP(
      (*static_cast<LabelledControlArray1DSP*>(handle))->connection());
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledControlArray1D_instrument_type(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_instrument_type");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return String_create(labelled_control_array->instrument_type().c_str(),
                       labelled_control_array->instrument_type().size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle LabelledControlArray1D_units(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_units");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return new physics::units::SymbolUnitSP(labelled_control_array->units());
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray1D_size(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_size");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray1D_dimension(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_dimension");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->dimension();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray1D_shape(LabelledControlArray1DHandle handle,
                                    size_t*                      out_buffer,
                                    size_t                       ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_shape");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto shape                  = labelled_control_array->shape();
  size_t to_copy              = std::min(ndim, shape.size());
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t LabelledControlArray1D_data(LabelledControlArray1DHandle handle,
                                   double*                      out_buffer,
                                   size_t                       numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_data");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto data                   = labelled_control_array->data();
  size_t count                = labelled_control_array->size();
  size_t to_copy              = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void LabelledControlArray1D_plus_equals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_equals_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  labelled_control_array->operator+=(*real_other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_plus_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_equals_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator+=(other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_plus_equals_int(LabelledControlArray1DHandle handle,
                                            const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_equals_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator+=(other);
  FALCON_C_API_END()
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_control_array");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  LabelledControlArray1DSP oarray =
      *static_cast<LabelledControlArray1DSP*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator+(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_minus_equals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_equals_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  labelled_control_array->operator-=(*real_other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_minus_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_equals_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator-=(other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_minus_equals_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_equals_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator-=(other);
  FALCON_C_API_END()
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_control_array");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  LabelledControlArray1DSP oarray =
      *static_cast<LabelledControlArray1DSP*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator-(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_negation(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_negation");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(-*labelled_control_array);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_times_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_equals_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator*=(other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_times_equals_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_equals_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator*=(other);
  FALCON_C_API_END()
}

LabelledControlArray1DHandle LabelledControlArray1D_times_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_times_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_divides_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_equals_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator/=(other);
  FALCON_C_API_END()
}

void LabelledControlArray1D_divides_equals_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_equals_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->operator/=(other);
  FALCON_C_API_END()
}

LabelledControlArray1DHandle LabelledControlArray1D_divides_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_double");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_divides_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_int");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_pow(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_pow");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_abs(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_abs");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->abs());
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_min(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->min();
  FALCON_C_API_END(0.0)
}

LabelledControlArray1DHandle LabelledControlArray1D_min_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator-(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_min_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min_control_array");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  LabelledControlArray1DSP oarray =
      *static_cast<LabelledControlArray1DSP*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_max(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->max();
  FALCON_C_API_END(0.0)
}

LabelledControlArray1DHandle LabelledControlArray1D_max_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_farray");
  }
  LabelledControlArray1DSP labelled_control_array =
      *static_cast<LabelledControlArray1DSP*>(handle);
  generic::FArraySP<double> real_other =
      *static_cast<generic::FArraySP<double>*>(other);
  return new LabelledControlArray1DSP(labelled_control_array->max(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_max_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_control_array");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  LabelledControlArray1DSP oarray =
      *static_cast<LabelledControlArray1DSP*>(other);
  return new LabelledControlArray1DSP(
      labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

bool LabelledControlArray1D_greater_than(LabelledControlArray1DHandle handle,
                                         const double                 value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_greater_than");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->operator>(value);
  FALCON_C_API_END(false)
}

bool LabelledControlArray1D_less_than(LabelledControlArray1DHandle handle,
                                      const double                 value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_less_than");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->operator<(value);
  FALCON_C_API_END(false)
}

void LabelledControlArray1D_remove_offset(LabelledControlArray1DHandle handle,
                                          const double                 offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_remove_offset");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  labelled_control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledControlArray1D_sum(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_sum");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->sum();
  FALCON_C_API_END(0.0)
}

LabelledControlArray1DHandle LabelledControlArray1D_reshape(
    LabelledControlArray1DHandle handle, const size_t* shape, size_t ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_reshape");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledControlArray1DSP(
      labelled_control_array->reshape(new_shape));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle LabelledControlArray1D_where(
    LabelledControlArray1DHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_where");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto indices                = labelled_control_array->where(value);
  return new generic::ListSP<generic::List<size_t>>(indices);
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_flip(
    LabelledControlArray1DHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_flip");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return new LabelledControlArray1DSP(labelled_control_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray1D_full_gradient(LabelledControlArray1DHandle handle,
                                            FArrayDoubleHandle* out_buffer,
                                            size_t              buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle || !out_buffer) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_full_gradient");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  auto gradients              = labelled_control_array->gradient();
  size_t to_copy              = std::min(buffer_size, gradients->size());
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArraySP<double>(gradients->items()[i]);
  }
  return to_copy;
  FALCON_C_API_END(0)
}

FArrayDoubleHandle LabelledControlArray1D_gradient(
    LabelledControlArray1DHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_gradient");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return new generic::FArraySP<double>(labelled_control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_get_sum_of_squares(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_sum_of_squares");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_summed_diff_int_of_squares(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_int_of_squares");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_summed_diff_double_of_squares(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_double_of_squares");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_summed_diff_array_of_squares(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_array_of_squares");
  }
  auto labelled_control_array = *static_cast<LabelledControlArray1DSP*>(handle);
  LabelledControlArray1DSP oarray =
      *static_cast<LabelledControlArray1DSP*>(other);
  return labelled_control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}
}
