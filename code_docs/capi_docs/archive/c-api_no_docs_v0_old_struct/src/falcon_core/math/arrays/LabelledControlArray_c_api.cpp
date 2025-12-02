#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"

#include <falcon_core/math/arrays/LabelledControlArray.hpp>
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
      std::make_shared<generic::FArray<double>>(
          *static_cast<generic::FArray<double>*>(farray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledControlArray(real_farray, real_label);
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
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(controlarray));
  autotuner_interfaces::contexts::AcquisitionContextSP real_label =
      std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
          *static_cast<autotuner_interfaces::contexts::AcquisitionContext*>(
              label));
  return new LabelledControlArray(real_controlarray, real_label);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_destroy(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_destroy");
  }
  delete static_cast<LabelledControlArray*>(handle);
  FALCON_C_API_END()
}

AcquisitionContextHandle LabelledControlArray_label(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_label");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new autotuner_interfaces::contexts::AcquisitionContext(
      *labelled_control_array->label());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle LabelledControlArray_connection(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_connection");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new physics::device_structures::Connection(
      *(labelled_control_array->connection()));
  FALCON_C_API_END(nullptr)
}

StringHandle LabelledControlArray_instrument_type(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_instrument_type");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new physics::units::SymbolUnit(*(labelled_control_array->units()));
  FALCON_C_API_END(nullptr)
}

size_t LabelledControlArray_size(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_size");
  }
  auto labelled_control_array = static_cast<LabelledControlArray*>(handle);
  return labelled_control_array->size();
  FALCON_C_API_END(0)
}

size_t LabelledControlArray_dimension(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_dimension");
  }
  auto labelled_control_array = static_cast<LabelledControlArray*>(handle);
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
  auto   labelled_control_array = static_cast<LabelledControlArray*>(handle);
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
  auto   labelled_control_array = static_cast<LabelledControlArray*>(handle);
  auto   data                   = labelled_control_array->data();
  size_t count                  = labelled_control_array->size();
  size_t to_copy                = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void LabelledControlArray_plusequals_farray(LabelledControlArrayHandle handle,
                                            FArrayDoubleHandle         other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plusequals_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_control_array->operator+=(*oarray);
  FALCON_C_API_END()
}

void LabelledControlArray_plusequals_double(LabelledControlArrayHandle handle,
                                            const double               other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plusequals_double");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  labelled_control_array->operator+=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_plusequals_int(LabelledControlArrayHandle handle,
                                         const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plusequals_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArraySP oarray = std::make_shared<LabelledControlArray>(
      *static_cast<LabelledControlArray*>(other));
  return new LabelledControlArray(*labelled_control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_plus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledControlArray(*labelled_control_array->operator+(
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_plus_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_plus_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_minusequals_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "LabelledControlArray_minusequals_control_array");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArray oarray = *static_cast<LabelledControlArray*>(other);
  labelled_control_array->operator-=(oarray);
  FALCON_C_API_END()
}

void LabelledControlArray_minusequals_farray(LabelledControlArrayHandle handle,
                                             FArrayDoubleHandle         other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minusequals_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  labelled_control_array->operator-=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void LabelledControlArray_minusequals_double(LabelledControlArrayHandle handle,
                                             const double               other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minusequals_double");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  labelled_control_array->operator-=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_minusequals_int(LabelledControlArrayHandle handle,
                                          const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minusequals_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArraySP oarray = std::make_shared<LabelledControlArray>(
      *static_cast<LabelledControlArray*>(other));
  return new LabelledControlArray(*labelled_control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_minus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledControlArray(*labelled_control_array->operator-(
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_minus_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_minus_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_negation(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_negation");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*-*labelled_control_array);
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_timesequals_double(LabelledControlArrayHandle handle,
                                             const double               other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_timesequals_double");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  labelled_control_array->operator*=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_timesequals_int(LabelledControlArrayHandle handle,
                                          const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_timesequals_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_times_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_times_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void LabelledControlArray_dividesequals_double(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_dividesequals_double");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  labelled_control_array->operator/=(other);
  FALCON_C_API_END()
}

void LabelledControlArray_dividesequals_int(LabelledControlArrayHandle handle,
                                            const int                  other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_dividesequals_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_divides_int(
    LabelledControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_divides_int");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_pow(
    LabelledControlArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_pow");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_abs(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_abs");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->abs());
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_min_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_min_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledControlArray(*labelled_control_array->min(
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArraySP oarray = std::make_shared<LabelledControlArray>(
      *static_cast<LabelledControlArray*>(other));
  return new LabelledControlArray(*labelled_control_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_max_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_max_farray");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new LabelledControlArray(*labelled_control_array->max(
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArraySP oarray = std::make_shared<LabelledControlArray>(
      *static_cast<LabelledControlArray*>(other));
  return new LabelledControlArray(*labelled_control_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

bool LabelledControlArray_equality(LabelledControlArrayHandle handle,
                                   LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_equality");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return labelled_control_array->operator==(
      *static_cast<LabelledControlArray*>(other));
  FALCON_C_API_END(false)
}

bool LabelledControlArray_notequality(LabelledControlArrayHandle handle,
                                      LabelledControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_notequality");
  }
  return !LabelledControlArray_equality(handle, other);
  FALCON_C_API_END(false)
}

bool LabelledControlArray_greaterthan(LabelledControlArrayHandle handle,
                                      const double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_greaterthan");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return labelled_control_array->operator>(value);
  FALCON_C_API_END(false)
}

bool LabelledControlArray_lessthan(LabelledControlArrayHandle handle,
                                   const double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_lessthan");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  labelled_control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double LabelledControlArray_sum(LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_sum");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  std::vector<size_t> new_shape(shape, shape + ndims);
  return new LabelledControlArray(*labelled_control_array->reshape(new_shape));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle LabelledControlArray_where(
    LabelledControlArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_where");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  auto indices = labelled_control_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_flip(
    LabelledControlArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_flip");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new LabelledControlArray(*labelled_control_array->flip(axis));
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  auto   gradients = labelled_control_array->gradient();
  size_t count     = gradients->size();
  size_t to_copy   = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArray<double>(*gradients->items()[i]);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  return new generic::FArray<double>(*labelled_control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double LabelledControlArray_get_sum_of_squares(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_get_sum_of_squares");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
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
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  LabelledControlArraySP oarray = std::make_shared<LabelledControlArray>(
      *static_cast<LabelledControlArray*>(other));
  return labelled_control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle LabelledControlArray_to_json_string(
    LabelledControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to LabelledControlArray_to_json_string");
  }
  LabelledControlArray* labelled_control_array =
      static_cast<LabelledControlArray*>(handle);
  std::string json_str = labelled_control_array->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

LabelledControlArrayHandle LabelledControlArray_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to LabelledControlArray_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      LabelledControlArray::from_json_string<LabelledControlArray>(raw_json);
  return new LabelledControlArray(*ptr);
  FALCON_C_API_END(nullptr)
}
}
