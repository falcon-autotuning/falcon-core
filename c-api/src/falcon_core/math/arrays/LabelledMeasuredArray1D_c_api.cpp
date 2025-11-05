#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"

#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>
#include <stdexcept>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_controlarray(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label) {
  if (!measuredarray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_from_controlarray");
  }
  MeasuredArraySP real_measuredarray = std::make_shared<MeasuredArray>(
      *static_cast<MeasuredArray*>(measuredarray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledMeasuredArray1D(real_measuredarray, real_label);
}

void LabelledMeasuredArray1D_destroy(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_destroy");
  }
  delete static_cast<LabelledMeasuredArray1D*>(handle);
}

bool LabelledMeasuredArray1D_is_1D(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_1D");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_1D();
}

FArrayDoubleHandle LabelledMeasuredArray1D_as_1D(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_as_1D");
  }
  auto labelled_measured_array  = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> arr = labelled_measured_array->as_1D();
  return new generic::FArray<double>(*arr);
}

double LabelledMeasuredArray1D_get_start(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_start");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_start();
}

double LabelledMeasuredArray1D_get_end(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_end");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_end();
}

bool LabelledMeasuredArray1D_is_decreasing(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_decreasing");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_decreasing();
}

bool LabelledMeasuredArray1D_is_increasing(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_is_decreasing");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->is_increasing();
}

double LabelledMeasuredArray1D_get_distance(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_distance");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_distance();
}

double LabelledMeasuredArray1D_get_mean(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_mean");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_mean();
}

double LabelledMeasuredArray1D_get_std(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_std");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_std();
}

void LabelledMeasuredArray1D_reverse(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_reverse");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->reverse();
}

size_t LabelledMeasuredArray1D_get_closest_index(
    LabelledMeasuredArray1DHandle handle, double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_closest_index");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_closest_index(value);
}

ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions(
    LabelledMeasuredArray1DHandle handle, size_t divisions) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_even_divisions");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::ListSP<generic::FArray<double>> divisions_array =
      labelled_measured_array->even_divisions(divisions);
  return new generic::List<generic::FArray<double>>(*divisions_array);
}

AcquisitionContextHandle LabelledMeasuredArray1D_label(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_label");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new autotuner_interfaces::contexts::AcquisitionContext(
      *labelled_measured_array->label());
}

ConnectionHandle LabelledMeasuredArray1D_connection(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_connection");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new physics::device_structures::Connection(
      *labelled_measured_array->connection());
}

StringHandle LabelledMeasuredArray1D_instrument_type(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_instrument_type");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::string instr_type       = labelled_measured_array->instrument_type();
  return String_create(instr_type.c_str(), instr_type.size());
}

SymbolUnitHandle LabelledMeasuredArray1D_units(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_units");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new physics::units::SymbolUnit(*(labelled_measured_array->units()));
}

size_t LabelledMeasuredArray1D_size(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_size");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->size();
}

size_t LabelledMeasuredArray1D_dimension(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_dimension");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->dimension();
}

size_t LabelledMeasuredArray1D_shape(LabelledMeasuredArray1DHandle handle,
                                     size_t*                       out_buffer,
                                     size_t                        ndim) {
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
}

size_t LabelledMeasuredArray1D_data(LabelledMeasuredArray1DHandle handle,
                                    double*                       out_buffer,
                                    size_t                        numdata) {
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
}

void LabelledMeasuredArray1D_plusequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plusequals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator+=(*real_other);
}

void LabelledMeasuredArray1D_plusequals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plusequals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator+=(other);
}

void LabelledMeasuredArray1D_plusequals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plusequals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator+=(other);
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_control_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(oarray));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_plus_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator+(other));
}

void LabelledMeasuredArray1D_minusequals_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_minusequals_control_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  labelled_measured_array->operator-=(oarray);
}

void LabelledMeasuredArray1D_minusequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minusequals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator-=(*real_other);
}

void LabelledMeasuredArray1D_minusequals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minusequals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator-=(other);
}

void LabelledMeasuredArray1D_minusequals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minusequals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator-=(other);
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_control_array(
    LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_control_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  MeasuredArraySP oarray =
      std::make_shared<MeasuredArray>(*static_cast<MeasuredArray*>(other));
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(oarray));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_minus_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator-(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_negation(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_negation");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*-*labelled_measured_array);
}

LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_timesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_timesequals_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      LabelledMeasuredArray1D(*static_cast<LabelledMeasuredArray1D*>(other));
  labelled_measured_array->operator*=(oarray);
  return handle;
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_timesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_timesequals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator*=(*real_other);
  return handle;
}

void LabelledMeasuredArray1D_timesequals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_timesequals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator*=(other);
}

void LabelledMeasuredArray1D_timesequals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_timesequals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator*=(other);
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_times_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator*(other));
}

LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_dividesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_dividesequals_measured_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      LabelledMeasuredArray1D(*static_cast<LabelledMeasuredArray1D*>(other));
  labelled_measured_array->operator/=(oarray);
  return handle;
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_dividesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_dividesequals_farray");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_measured_array->operator/=(*real_other);
  return handle;
}

void LabelledMeasuredArray1D_dividesequals_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_dividesequals_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator/=(other);
}

void LabelledMeasuredArray1D_dividesequals_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_dividesequals_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->operator/=(other);
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_double(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_double");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_int(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_divides_int");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator/(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_pow(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_pow");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->operator^(other));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_abs(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_abs");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*labelled_measured_array->abs());
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_min_control_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->min(oarray));
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_max_control_array");
  }
  LabelledMeasuredArray1D* labelled_measured_array =
      static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return new LabelledMeasuredArray1D(*labelled_measured_array->max(oarray));
}

bool LabelledMeasuredArray1D_equality(LabelledMeasuredArray1DHandle handle,
                                      LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_equality");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  return labelled_measured_array->operator==(oarray);
}

bool LabelledMeasuredArray1D_notequality(LabelledMeasuredArray1DHandle handle,
                                         LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_notequality");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1D oarray =
      *static_cast<LabelledMeasuredArray1D*>(other);
  return labelled_measured_array->operator!=(oarray);
}

bool LabelledMeasuredArray1D_greaterthan(LabelledMeasuredArray1DHandle handle,
                                         const double                  value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_greaterthan");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->operator>(value);
}

bool LabelledMeasuredArray1D_lessthan(LabelledMeasuredArray1DHandle handle,
                                      const double                  value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_lessthan");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->operator<(value);
}

void LabelledMeasuredArray1D_remove_offset(LabelledMeasuredArray1DHandle handle,
                                           const double offset) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_remove_offset");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  labelled_measured_array->remove_offset(offset);
}

double LabelledMeasuredArray1D_sum(LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_sum");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->sum();
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape(
    LabelledMeasuredArray1DHandle handle, const size_t* shape, size_t ndims) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_reshape");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::vector<size_t> shape_vec(shape, shape + ndims);
  return new LabelledMeasuredArray1D(
      *labelled_measured_array->reshape(shape_vec));
}

ListListSizeTHandle LabelledMeasuredArray1D_where(
    LabelledMeasuredArray1DHandle handle, const double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_where");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  generic::ListSP<generic::List<size_t>> where_indices =
      labelled_measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*where_indices);
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_flip(
    LabelledMeasuredArray1DHandle handle, size_t axis) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_flip");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(*labelled_measured_array->flip(axis));
}

size_t LabelledMeasuredArray1D_full_gradient(
    LabelledMeasuredArray1DHandle  handle,
    LabelledMeasuredArray1DHandle* out_buffer,
    size_t                         buffer_size) {
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
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_gradient(
    LabelledMeasuredArray1DHandle handle, size_t axis) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_gradient");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return new LabelledMeasuredArray1D(labelled_measured_array->gradient(axis),
                                     labelled_measured_array->label());
}

double LabelledMeasuredArray1D_get_sum_of_squares(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_get_sum_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares();
}

double LabelledMeasuredArray1D_get_summed_diff_int_of_squares(
    LabelledMeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_int_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
}

double LabelledMeasuredArray1D_get_summed_diff_double_of_squares(
    LabelledMeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_double_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
}

double LabelledMeasuredArray1D_get_summed_diff_array_of_squares(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray1D_get_summed_diff_array_of_squares");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  LabelledMeasuredArray1DSP oarray = std::make_shared<LabelledMeasuredArray1D>(
      *static_cast<LabelledMeasuredArray1D*>(other));
  return labelled_measured_array->get_sum_of_squares(oarray);
}

StringHandle LabelledMeasuredArray1D_to_json_string(
    LabelledMeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray1D_to_json_string");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray1D*>(handle);
  std::string json_str         = labelled_measured_array->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
}

LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "LabelledMeasuredArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto ptr = LabelledMeasuredArray1D::from_json_string<LabelledMeasuredArray1D>(
      raw_json);
  return new LabelledMeasuredArray1D(*ptr);
}
