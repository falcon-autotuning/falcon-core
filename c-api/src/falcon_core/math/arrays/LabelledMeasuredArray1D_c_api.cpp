#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"

#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>
#include <stdexcept>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_from_farray");
  }
  generic::FArraySP<double> real_farray =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(farray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledMeasuredArray1D(real_farray, real_label);
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_measured_array(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!measuredarray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_from_measuredarray");
  }
  MeasuredArraySP real_measuredarray = std::make_shared<MeasuredArray>(
      *static_cast<MeasuredArray*>(measuredarray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledMeasuredArray1D(real_measuredarray, real_label);
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray1D_destroy(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_destroy");
  }
  delete static_cast<LabelledMeasuredArray1D*>(handle);
  FALCON_C_API_END()
}

bool LabelledMeasuredArray1D_is_1D(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_1D");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_1D();
  FALCON_C_API_END(false)
}

FArrayDoubleHandle LabelledMeasuredArray1D_as_1D(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_as_1D");
  }
  auto labelled_measured_array  = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> arr = labelled_measured_array->as_1D();
  return new generic::FArray<double>(*arr);
  FALCON_C_API_END(nullptr)
}

double LabelledMeasuredArray1D_get_start(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_start");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_start();
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_end(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_end");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_end();
  FALCON_C_API_END(0.0)
}

bool LabelledMeasuredArray1D_is_decreasing(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_decreasing");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_decreasing();
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray1D_is_increasing(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_decreasing");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_increasing();
  FALCON_C_API_END(false)
}

double LabelledMeasuredArray1D_get_distance(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_distance");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_distance();
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_mean(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_mean");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_mean();
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_std(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_std");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_std();
  FALCON_C_API_END(0.0)
}

void LabelledMeasuredArray1D_reverse(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_reverse");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->reverse();
  FALCON_C_API_END()
}

size_t LabelledMeasuredArray1D_get_closest_index(
    LabelledMeasuredArray1DHandle handle, double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_closest_index");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_closest_index(value);
  FALCON_C_API_END(0)
}

ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions(
    LabelledMeasuredArray1DHandle handle, size_t divisions) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_even_divisions");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::ListSP<generic::FArray<double>> divisions_array =
      labelled_measured_array->even_divisions(divisions);
  return new generic::List<generic::FArray<double>>(*divisions_array);
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle LabelledMeasuredArray1D_label(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_label");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new autotuner_interfaces::contexts::AcquisitionContext(
      *labelled_measured_array->label());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledMeasuredArray1D_connection(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_connection");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new physics::device_structures::Connection(
      *labelled_measured_array->connection());
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledMeasuredArray1D_instrument_type(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_instrument_type");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::string instr_type       = labelled_measured_array->instrument_type();
  return String_create(instr_type.c_str(), instr_type.size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle LabelledMeasuredArray1D_units(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_units");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new physics::units::SymbolUnit(*(labelled_measured_array->units()));
  FALCON_C_API_END(nullptr)
}

size_t LabelledMeasuredArray1D_size(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_size");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray1D_dimension(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_dimension");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->dimension();
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray1D_shape(LabelledMeasuredArray1DHandle handle,
                                     size_t*                       out_buffer,
                                     size_t                        ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_shape");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  auto shape                   = labelled_measured_array->shape();
  size_t count                 = shape.size();
  size_t to_copy               = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray1D_data(LabelledMeasuredArray1DHandle handle,
                                    double*                       out_buffer,
                                    size_t                        numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_data");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  auto data                    = labelled_measured_array->data();
  size_t count                 = labelled_measured_array->size();
  size_t to_copy               = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void LabelledMeasuredArray1D_plus_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_equals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator+=(*real_other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_plus_equals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_equals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator+=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_plus_equals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_equals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator+=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray1D_minus_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_minus_equals_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  labelled_measured_array->operator-=(oarray);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_minus_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_equals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator-=(*real_other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_minus_equals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_equals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator-=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_minus_equals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_equals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator-=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_measured_array(
    LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  MeasuredArraySP oarray =
      std::make_shared<MeasuredArray>(*static_cast<MeasuredArray*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_negation(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_negation");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*-*labelled_measured_array);
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_times_equals_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      LabelledMeasuredArray1D(*static_cast<LabelledMeasuredArray1D*>(other));
  labelled_measured_array->operator*=(oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_equals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator*=(*real_other);
  return handle;
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray1D_times_equals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_equals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator*=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_times_equals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_equals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator*=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_divides_equals_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      LabelledMeasuredArray1D(*static_cast<LabelledMeasuredArray1D*>(other));
  labelled_measured_array->operator/=(oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_equals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator/=(*real_other);
  return handle;
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray1D_divides_equals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_equals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator/=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray1D_divides_equals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_equals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator/=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_pow(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_pow");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_abs(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_abs");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*labelled_measured_array->abs());
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_min_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->min(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_min_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_max_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->max(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_max_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

bool LabelledMeasuredArray1D_equal(LabelledMeasuredArray1DHandle handle,
                                      LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_equal");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  return labelled_measured_array->operator==(oarray);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray1D_not_equal(LabelledMeasuredArray1DHandle handle,
                                         LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_not_equal");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  return labelled_measured_array->operator!=(oarray);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray1D_greater_than(LabelledMeasuredArray1DHandle handle,
                                         const double                  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_greater_than");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->operator>(value);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray1D_less_than(LabelledMeasuredArray1DHandle handle,
                                      const double                  value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_less_than");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->operator<(value);
  FALCON_C_API_END(false)
}

void LabelledMeasuredArray1D_remove_offset(LabelledMeasuredArray1DHandle handle,
                                           const double offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_remove_offset");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledMeasuredArray1D_sum(LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_sum");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->sum();
  FALCON_C_API_END(0.0)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape(
    LabelledMeasuredArray1DHandle handle, const size_t* shape, size_t ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_reshape");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::vector<size_t> shape_vec(shape, shape + ndims);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->reshape(shape_vec));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle LabelledMeasuredArray1D_where(
    LabelledMeasuredArray1DHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_where");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::ListSP<generic::List<size_t>> where_indices =
      labelled_measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*where_indices);
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_flip(
    LabelledMeasuredArray1DHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_flip");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*labelled_measured_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t LabelledMeasuredArray1D_full_gradient(
    LabelledMeasuredArray1DHandle  handle,
    LabelledMeasuredArray1DHandle* out_buffer,
    size_t                         buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle || !out_buffer) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_full_gradient");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::ListSP<generic::FArray<double>> gradients =
      labelled_measured_array->gradient();
  size_t count   = gradients->size();
  size_t to_copy = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new LabelledMeasuredArray1D(
        (*gradients)[i], labelled_measured_array->label());
  }
  return to_copy;
  FALCON_C_API_END(0)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_gradient(
    LabelledMeasuredArray1DHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_gradient");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(labelled_measured_array->gradient(axis),
                                     labelled_measured_array->label());
  FALCON_C_API_END(nullptr)
}

double LabelledMeasuredArray1D_get_sum_of_squares(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_sum_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_summed_diff_int_of_squares(
    LabelledMeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_int_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_summed_diff_double_of_squares(
    LabelledMeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_double_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray1D_get_summed_diff_array_of_squares(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_array_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return labelled_measured_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle LabelledMeasuredArray1D_to_json_string(
    LabelledMeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_to_json_string");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::string json_str         = labelled_measured_array->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "LabelledMeasuredArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto ptr = LabelledMeasuredArray1D::from_json_string<LabelledMeasuredArray1D>(
      raw_json);
  return new LabelledMeasuredArray1D(*ptr);
  FALCON_C_API_END(nullptr)
}
}
