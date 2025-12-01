#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"

#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>
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
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(farray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledControlArray1D(real_farray, real_label);
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
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(controlarray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledControlArray1D(real_controlarray, real_label);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_destroy(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_destroy");
  }
  delete static_cast<LabelledControlArray1D*>(handle);
  FALCON_C_API_END()
}

bool LabelledControlArray1D_is_1D(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_1D");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array    = static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> data = labelled_control_array->as_1D();
  return new generic::FArray<double>(*data);
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_get_start(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_start");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_start();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_end(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_end");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_end();
  FALCON_C_API_END(0.0)
}

bool LabelledControlArray1D_is_decreasing(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_decreasing");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->is_decreasing();
  FALCON_C_API_END(false)
}

bool LabelledControlArray1D_is_increasing(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_increasing");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_distance();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_mean(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_mean");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_mean();
  FALCON_C_API_END(0.0)
}

double LabelledControlArray1D_get_std(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_std");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_std();
  FALCON_C_API_END(0.0)
}

void LabelledControlArray1D_reverse(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_reverse");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto divisions_arrays = labelled_control_array->even_divisions(divisions);
  return new generic::List<generic::FArray<double>>(*divisions_arrays);
  FALCON_C_API_END(nullptr)
}

AcquisitionContextHandle LabelledControlArray1D_label(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_label");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto label                  = labelled_control_array->label();
  return new autotuner_interfaces::contexts::AcquisitionContext(*label);
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledControlArray1D_connection(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_connection");
  }
  return new physics::device_structures::Connection(
      *(static_cast<LabelledControlArray1D*>(handle)->connection()));
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledControlArray1D_instrument_type(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_instrument_type");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new physics::units::SymbolUnit(*(labelled_control_array->units()));
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray1D_size(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_size");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray1D_dimension(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_dimension");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto   labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto   shape                  = labelled_control_array->shape();
  size_t to_copy                = std::min(ndim, shape.size());
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
  auto   labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto   data                   = labelled_control_array->data();
  size_t count                  = labelled_control_array->size();
  size_t to_copy                = (numdata < count) ? numdata : count;
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledControlArray1D(
      *labelled_control_array->operator+(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_minus_equals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_equals_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledControlArray1D(
      *labelled_control_array->operator-(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_negation(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_negation");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*-*labelled_control_array);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_times_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_equals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_times_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray1D_divides_equals_double(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_equals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
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
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_divides_int(
    LabelledControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_pow(
    LabelledControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_pow");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_abs(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_abs");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->abs());
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_min(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->min();
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_min_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledControlArray1D(
      *labelled_control_array->operator-(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_min_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_max(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->max();
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_max_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledControlArray1D(*labelled_control_array->max(real_other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_max_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

bool LabelledControlArray1D_equal(LabelledControlArray1DHandle handle,
                                  LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_equal");
  }
  auto labelled_control_array   = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1D oarray = *static_cast<LabelledControlArray1D*>(other);
  return labelled_control_array->operator==(oarray);
  FALCON_C_API_END(false)
}

bool LabelledControlArray1D_not_equal(LabelledControlArray1DHandle handle,
                                      LabelledControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_not_equal");
  }
  auto labelled_control_array   = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1D oarray = *static_cast<LabelledControlArray1D*>(other);
  return labelled_control_array->operator!=(oarray);
  FALCON_C_API_END(false)
}

bool LabelledControlArray1D_greater_than(LabelledControlArray1DHandle handle,
                                         const double                 value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_greater_than");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledControlArray1D_sum(LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_sum");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledControlArray1D(
      *labelled_control_array->reshape(new_shape));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle LabelledControlArray1D_where(
    LabelledControlArray1DHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_where");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto indices                = labelled_control_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_flip(
    LabelledControlArray1DHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_flip");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->flip(axis));
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
  auto   labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto   gradients              = labelled_control_array->gradient();
  size_t to_copy                = std::min(buffer_size, gradients->size());
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArray<double>(*gradients->items()[i]);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new generic::FArray<double>(*labelled_control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray1D_get_sum_of_squares(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_sum_of_squares");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
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
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return labelled_control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle LabelledControlArray1D_to_json_string(
    LabelledControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_to_json_string");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  std::string json_string     = labelled_control_array->to_json_string();
  return String_create(json_string.c_str(), json_string.size());
  FALCON_C_API_END(nullptr)
}

LabelledControlArray1DHandle LabelledControlArray1D_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "LabelledControlArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto ptr = LabelledControlArray1D::from_json_string<LabelledControlArray1D>(
      raw_json);
  return new LabelledControlArray1D(*ptr);
  FALCON_C_API_END(nullptr)
}
}
