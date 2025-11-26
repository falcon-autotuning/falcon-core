#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"

#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>
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
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_from_farray");
  }
  generic::FArraySP<double> real_farray =
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(farray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledMeasuredArray(real_farray, real_label);
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_from_measured_array(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label) {
  FALCON_C_API_BEGIN
  if (!measuredarray) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_from_measuredarray");
  }
  MeasuredArraySP real_measuredarray = std::make_shared<MeasuredArray>(
      *static_cast<MeasuredArray*>(measuredarray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledMeasuredArray(real_measuredarray, real_label);
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray_destroy(LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_destroy");
  }
  delete static_cast<LabelledMeasuredArray*>(handle);
  FALCON_C_API_END()
}

AcquisitionContextHandle LabelledMeasuredArray_label(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_label");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new autotuner_interfaces::contexts::AcquisitionContext(
      *(labelled_measured_array->label()));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledMeasuredArray_connection(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_connection");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new physics::device_structures::Connection(
      *(labelled_measured_array->connection()));
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledMeasuredArray_instrument_type(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_instrument_type");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  std::string instr_type = labelled_measured_array->instrument_type();
  return String_create(instr_type.c_str(), instr_type.size());
  FALCON_C_API_END(nullptr)
}

SymbolUnitHandle LabelledMeasuredArray_units(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_units");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new physics::units::SymbolUnit(*(labelled_measured_array->units()));
  FALCON_C_API_END(nullptr)
}

size_t LabelledMeasuredArray_size(LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_size");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray_dimension(LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_dimension");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->dimension();
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray_shape(LabelledMeasuredArrayHandle handle,
                                   size_t*                     out_buffer,
                                   size_t                      ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_shape");
  }
  auto   labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  auto   shape                   = labelled_measured_array->shape();
  size_t count                   = shape.size();
  size_t to_copy                 = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t LabelledMeasuredArray_data(LabelledMeasuredArrayHandle handle,
                                  double*                     out_buffer,
                                  size_t                      numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_data");
  }
  if (!out_buffer) {
    throw std::invalid_argument(
        "Null output buffer passed to LabelledMeasuredArray_data");
  }
  auto   labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  auto   data                    = labelled_measured_array->data();
  size_t count                   = labelled_measured_array->size();
  size_t to_copy                 = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void LabelledMeasuredArray_plus_equals_farray(LabelledMeasuredArrayHandle handle,
                                             FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_equals_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_measured_array->operator+=(*oarray);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_plus_equals_double(LabelledMeasuredArrayHandle handle,
                                             const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_equals_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator+=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_plus_equals_int(LabelledMeasuredArrayHandle handle,
                                          const int                   other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_equals_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator+=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_int(
    LabelledMeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_plus_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray_minus_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_minus_equals_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArray oarray = *static_cast<LabelledMeasuredArray*>(other);
  labelled_measured_array->operator-=(oarray);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_minus_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_equals_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_measured_array->operator-=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void LabelledMeasuredArray_minus_equals_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_equals_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator-=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_minus_equals_int(LabelledMeasuredArrayHandle handle,
                                           const int                   other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_equals_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator-=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_measured_array(
    LabelledMeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  MeasuredArraySP oarray =
      std::make_shared<MeasuredArray>(*static_cast<MeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_int(
    LabelledMeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_minus_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_negation(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_negation");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*-*labelled_measured_array);
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_times_equals_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArray oarray = *static_cast<LabelledMeasuredArray*>(other);
  labelled_measured_array->operator*=(oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_equals_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_measured_array->operator*=(generic::FArray<double>(*oarray));
  return handle;
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray_times_equals_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_equals_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator*=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_times_equals_int(LabelledMeasuredArrayHandle handle,
                                           const int                   other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_equals_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator*=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator*(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_times_int(
    LabelledMeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_times_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_divides_equals_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArray oarray = *static_cast<LabelledMeasuredArray*>(other);
  labelled_measured_array->operator/=(oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_equals_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_measured_array->operator/=(generic::FArray<double>(*oarray));
  return handle;
  FALCON_C_API_END(nullptr)
}

void LabelledMeasuredArray_divides_equals_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_equals_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator/=(other);
  FALCON_C_API_END()
}

void LabelledMeasuredArray_divides_equals_int(LabelledMeasuredArrayHandle handle,
                                             const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_equals_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->operator/=(other);
  FALCON_C_API_END()
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator/(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_double(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_double");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_int(
    LabelledMeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_divides_int");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_pow(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_pow");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_abs(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_abs");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(*labelled_measured_array->abs());
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_min_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_min_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_min_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_min_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_max_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_max_farray");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_max_measured_array");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return new LabelledMeasuredArray(*labelled_measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}
bool LabelledMeasuredArray_equality(LabelledMeasuredArrayHandle handle,
                                    LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_equality");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArray oarray = *static_cast<LabelledMeasuredArray*>(other);
  return labelled_measured_array->operator==(oarray);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray_notequality(LabelledMeasuredArrayHandle handle,
                                       LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_notequality");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArray oarray = *static_cast<LabelledMeasuredArray*>(other);
  return labelled_measured_array->operator!=(oarray);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray_greaterthan(LabelledMeasuredArrayHandle handle,
                                       const double                value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_greaterhan");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->operator>(value);
  FALCON_C_API_END(false)
}

bool LabelledMeasuredArray_lessthan(LabelledMeasuredArrayHandle handle,
                                    const double                value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_lessthan");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->operator<(value);
  FALCON_C_API_END(false)
}
void LabelledMeasuredArray_remove_offset(LabelledMeasuredArrayHandle handle,
                                         const double                offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_remove_offset");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  labelled_measured_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledMeasuredArray_sum(LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_sum");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->sum();
  FALCON_C_API_END(0.0)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_reshape(
    LabelledMeasuredArrayHandle handle, const size_t* shape, size_t ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_reshape");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledMeasuredArray(
      *labelled_measured_array->reshape(new_shape));
  FALCON_C_API_END(nullptr)
}
ListListSizeTHandle LabelledMeasuredArray_where(
    LabelledMeasuredArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_where");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  auto indices = labelled_measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
  FALCON_C_API_END(nullptr)
}
LabelledMeasuredArrayHandle LabelledMeasuredArray_flip(
    LabelledMeasuredArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_flip");
  }
  return new LabelledMeasuredArray(
      *static_cast<LabelledMeasuredArray*>(handle)->flip(axis));
  FALCON_C_API_END(nullptr)
}
size_t LabelledMeasuredArray_full_gradient(
    LabelledMeasuredArrayHandle  handle,
    LabelledMeasuredArrayHandle* out_buffer,
    size_t                       buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_full_gradient");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  generic::ListSP<generic::FArray<double>> gradients =
      labelled_measured_array->gradient();
  size_t count   = gradients->size();
  size_t to_copy = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new LabelledMeasuredArray(gradients->items()[i],
                                              labelled_measured_array->label());
  }
  return to_copy;
  FALCON_C_API_END(0)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_gradient(
    LabelledMeasuredArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_gradient");
  }
  auto labelled_measured_array = static_cast<LabelledMeasuredArray*>(handle);
  return new LabelledMeasuredArray(labelled_measured_array->gradient(axis),
                                   labelled_measured_array->label());
  FALCON_C_API_END(nullptr)
}

double LabelledMeasuredArray_get_sum_of_squares(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_get_sum_of_squares");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray_get_summed_diff_int_of_squares(
    LabelledMeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_get_summed_diff_int_of_squares");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray_get_summed_diff_double_of_squares(
    LabelledMeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_get_summed_diff_double_of_squares");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  return labelled_measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double LabelledMeasuredArray_get_summed_diff_array_of_squares(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledMeasuredArray_get_summed_diff_array_of_squares");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  LabelledMeasuredArraySP oarray = std::make_shared<LabelledMeasuredArray>(
      *static_cast<LabelledMeasuredArray*>(other));
  return labelled_measured_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle LabelledMeasuredArray_to_json_string(
    LabelledMeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledMeasuredArray_to_json_string");
  }
  LabelledMeasuredArray* labelled_measured_array =
      static_cast<LabelledMeasuredArray*>(handle);
  std::string json_str = labelled_measured_array->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

LabelledMeasuredArrayHandle LabelledMeasuredArray_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to LabelledMeasuredArray_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      LabelledMeasuredArray::from_json_string<LabelledMeasuredArray>(raw_json);
  return new LabelledMeasuredArray(*ptr);
  FALCON_C_API_END(nullptr)
}
}
