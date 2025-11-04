#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"

#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>
#include <stdexcept>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

LabelledControlArray1DHandle LabelledControlArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
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
}

LabelledControlArray1DHandle LabelledControlArray1D_from_controlarray(
    ControlArrayHandle controlarray, AcquisitionContextHandle label) {
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
}

void LabelledControlArray1D_destroy(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_destroy");
  }
  delete static_cast<LabelledControlArray1D*>(handle);
}

bool LabelledControlArray1D_is_1D(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_1D");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->is_1D();
}

FArrayDoubleHandle LabelledControlArray1D_as_1D(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_as_1D");
  }
  auto labelled_control_array    = static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> data = labelled_control_array->as_1D();
  return new generic::FArray<double>(*data);
}

double LabelledControlArray1D_get_start(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_start");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_start();
}

double LabelledControlArray1D_get_end(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_end");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_end();
}

bool LabelledControlArray1D_is_decreasing(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_decreasing");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->is_decreasing();
}

bool LabelledControlArray1D_is_increasing(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_is_increasing");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->is_increasing();
}

double LabelledControlArray1D_get_distance(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_distance");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_distance();
}

double LabelledControlArray1D_get_mean(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_mean");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_mean();
}

double LabelledControlArray1D_get_std(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_std");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_std();
}

void LabelledControlArray1D_reverse(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_reverse");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->reverse();
}

size_t LabelledControlArray1D_get_closest_index(
    LabelledControlArray1DHandle handle, double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_closest_index");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_closest_index(value);
}

ListFArrayDoubleHandle LabelledControlArray1D_even_divisions(
    LabelledControlArray1DHandle handle, size_t divisions) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_even_divisions");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto divisions_arrays = labelled_control_array->even_divisions(divisions);
  return new generic::List<generic::FArray<double>>(*divisions_arrays);
}

AcquisitionContextHandle LabelledControlArray1D_label(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_label");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto label                  = labelled_control_array->label();
  return new autotuner_interfaces::contexts::AcquisitionContext(*label);
}

ConnectionHandle LabelledControlArray1D_connection(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_connection");
  }
  return new physics::device_structures::Connection(
      *(static_cast<LabelledControlArray1D*>(handle)->connection()));
}

StringHandle LabelledControlArray1D_instrument_type(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_instrument_type");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return String_create(labelled_control_array->instrument_type().c_str(),
                       labelled_control_array->instrument_type().size());
}

SymbolUnitHandle LabelledControlArray1D_units(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_units");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new physics::units::SymbolUnit(*(labelled_control_array->units()));
}

size_t LabelledControlArray1D_size(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_size");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->size();
}

size_t LabelledControlArray1D_dimension(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_dimension");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->dimension();
}

size_t LabelledControlArray1D_shape(LabelledControlArray1DHandle handle,
                                    size_t*                      out_buffer,
                                    size_t                       ndim) {
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
}

size_t LabelledControlArray1D_data(LabelledControlArray1DHandle handle,
                                   double*                      out_buffer,
                                   size_t                       numdata) {
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
}

void LabelledControlArray1D_plusequals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plusequals_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_control_array->operator+=(*real_other);
}

void LabelledControlArray1D_plusequals_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plusequals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator+=(other);
}

void LabelledControlArray1D_plusequals_int(LabelledControlArray1DHandle handle,
                                           const int                    other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plusequals_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator+=(other);
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator+(oarray));
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator+(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_plus_int(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_plus_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator+(other));
}

void LabelledControlArray1D_minusequals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minusequals_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  labelled_control_array->operator-=(*real_other);
}

void LabelledControlArray1D_minusequals_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minusequals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator-=(other);
}

void LabelledControlArray1D_minusequals_int(LabelledControlArray1DHandle handle,
                                            const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minusequals_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator-=(other);
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator-(oarray));
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator-(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_minus_int(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_minus_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator-(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_negation(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_negation");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*-*labelled_control_array);
}

void LabelledControlArray1D_timesequals_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_timesequals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator*=(other);
}

void LabelledControlArray1D_timesequals_int(LabelledControlArray1DHandle handle,
                                            const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_timesequals_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator*=(other);
}

LabelledControlArray1DHandle LabelledControlArray1D_times_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator*(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_times_int(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_times_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator*(other));
}

void LabelledControlArray1D_dividesequals_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_dividesequals_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator/=(other);
}

void LabelledControlArray1D_dividesequals_int(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_dividesequals_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->operator/=(other);
}

LabelledControlArray1DHandle LabelledControlArray1D_divides_double(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_double");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator/(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_divides_int(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_divides_int");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator/(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_pow(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_pow");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->operator^(other));
}

LabelledControlArray1DHandle LabelledControlArray1D_abs(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_abs");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->abs());
}

LabelledControlArray1DHandle LabelledControlArray1D_min_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
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
}

LabelledControlArray1DHandle LabelledControlArray1D_min_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_min_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator-(oarray));
}

LabelledControlArray1DHandle LabelledControlArray1D_max_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_farray");
  }
  LabelledControlArray1D* labelled_control_array =
      static_cast<LabelledControlArray1D*>(handle);
  generic::FArraySP<double> real_other =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(other));
  return new LabelledControlArray1D(
      *labelled_control_array->operator+(real_other));
}

LabelledControlArray1DHandle LabelledControlArray1D_max_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_max_control_array");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return new LabelledControlArray1D(*labelled_control_array->operator+(oarray));
}

bool LabelledControlArray1D_equality(LabelledControlArray1DHandle handle,
                                     LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_equality");
  }
  auto labelled_control_array   = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1D oarray = *static_cast<LabelledControlArray1D*>(other);
  return labelled_control_array->operator==(oarray);
}

bool LabelledControlArray1D_notequality(LabelledControlArray1DHandle handle,
                                        LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_notequality");
  }
  auto labelled_control_array   = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1D oarray = *static_cast<LabelledControlArray1D*>(other);
  return labelled_control_array->operator!=(oarray);
}

bool LabelledControlArray1D_greaterthan(LabelledControlArray1DHandle handle,
                                        const double                 value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_greaterthan");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->operator>(value);
}

bool LabelledControlArray1D_lessthan(LabelledControlArray1DHandle handle,
                                     const double                 value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_lessthan");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->operator<(value);
}

void LabelledControlArray1D_remove_offset(LabelledControlArray1DHandle handle,
                                          const double                 offset) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_remove_offset");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  labelled_control_array->remove_offset(offset);
}

double LabelledControlArray1D_sum(LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_sum");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->sum();
}

LabelledControlArray1DHandle LabelledControlArray1D_reshape(
    LabelledControlArray1DHandle handle, const size_t* shape, size_t ndims) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_reshape");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledControlArray1D(
      *labelled_control_array->reshape(new_shape));
}

ListListSizeTHandle LabelledControlArray1D_where(
    LabelledControlArray1DHandle handle, const double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_where");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto indices                = labelled_control_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
}

LabelledControlArray1DHandle LabelledControlArray1D_flip(
    LabelledControlArray1DHandle handle, size_t axis) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_flip");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(*labelled_control_array->flip(axis));
}

size_t LabelledControlArray1D_full_gradient(
    LabelledControlArray1DHandle  handle,
    LabelledControlArray1DHandle* out_buffer,
    size_t                        buffer_size) {
  if (!handle || !out_buffer) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_full_gradient");
  }
  auto   labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  auto   gradients              = labelled_control_array->gradient();
  size_t to_copy                = std::min(buffer_size, gradients->size());
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new LabelledControlArray1D((*gradients)[i],
                                               labelled_control_array->label());
  }
  return to_copy;
}

LabelledControlArray1DHandle LabelledControlArray1D_gradient(
    LabelledControlArray1DHandle handle, size_t axis) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_gradient");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return new LabelledControlArray1D(labelled_control_array->gradient(axis),
                                    labelled_control_array->label());
}

double LabelledControlArray1D_get_sum_of_squares(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_get_sum_of_squares");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_sum_of_squares();
}

double LabelledControlArray1D_get_summed_diff_int_of_squares(
    LabelledControlArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_int_of_squares");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
}

double LabelledControlArray1D_get_summed_diff_double_of_squares(
    LabelledControlArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_double_of_squares");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  return labelled_control_array->get_sum_of_squares(other);
}

double LabelledControlArray1D_get_summed_diff_array_of_squares(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray1D_get_summed_diff_array_of_squares");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  LabelledControlArray1DSP oarray = std::make_shared<LabelledControlArray1D>(
      *static_cast<LabelledControlArray1D*>(other));
  return labelled_control_array->get_sum_of_squares(oarray);
}

StringHandle LabelledControlArray1D_to_json_string(
    LabelledControlArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray1D_to_json_string");
  }
  auto labelled_control_array = static_cast<LabelledControlArray1D*>(handle);
  std::string json_string     = labelled_control_array->to_json_string();
  return String_create(json_string.c_str(), json_string.size());
}

LabelledControlArray1DHandle LabelledControlArray1D_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "LabelledControlArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto ptr = LabelledControlArray1D::from_json_string<LabelledControlArray1D>(
      raw_json);
  return new LabelledControlArray1D(*ptr);
}
