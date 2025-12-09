#include "falcon_core/math/arrays/ControlArray1D_c_api.h"

#include <falcon_core/math/arrays/ControlArray1D.hpp>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
ControlArray1DHandle ControlArray1D_from_data(const double* data,
                                              const size_t* shape,
                                              size_t        ndim) {
  FALCON_C_API_BEGIN
  if (!data) {
    throw std::invalid_argument(
        "Null data pointer passed to ControlArray1D_from_data");
  }
  if (!shape) {
    throw std::invalid_argument(
        "Null shape pointer passed to ControlArray1D_from_data");
  }
  for (size_t i = 0; i < ndim; ++i) {
    if (shape[i] == 0) {
      throw std::invalid_argument(
          "Shape dimensions must be greater than zero in "
          "ControlArray1D_from_data");
    }
  }
  if (ndim != 1) {
    throw std::invalid_argument(
        "ControlArray1D_from_data requires ndim to be 1");
  }
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new ControlArray1DSP(std::make_shared<ControlArray1D>(arr));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_from_farray(FArrayDoubleHandle farray) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_from_farray");
  }
  generic::FArraySP<double> real_farray =
      *static_cast<generic::FArraySP<double>*>(farray);
  return new ControlArray1DSP(std::make_shared<ControlArray1D>(*real_farray));
  FALCON_C_API_END(nullptr)
}

void ControlArray1D_destroy(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_destroy");
  }
  delete static_cast<ControlArray1DSP*>(handle);
  FALCON_C_API_END()
}

bool ControlArray1D_is_1D(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_is_1D");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->is_1D();
  FALCON_C_API_END(false)
}

FArrayDoubleHandle ControlArray1D_as_1D(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_as_1D");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> arr  = control_array->as_1D();
  return new generic::FArraySP<double>(arr);
  FALCON_C_API_END(nullptr)
}

double ControlArray1D_get_start(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_start");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_start();
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_end(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_get_end");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_end();
  FALCON_C_API_END(0.0)
}

bool ControlArray1D_is_decreasing(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_is_decreasing");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->is_decreasing();
  FALCON_C_API_END(false)
}

bool ControlArray1D_is_increasing(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_is_increasing");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->is_increasing();
  FALCON_C_API_END(false)
}

double ControlArray1D_get_distance(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_distance");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_distance();
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_mean(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_mean");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_mean();
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_std(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_get_std");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_std();
  FALCON_C_API_END(0.0)
}

void ControlArray1D_reverse(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_reverse");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->reverse();
  FALCON_C_API_END()
}

size_t ControlArray1D_get_closest_index(ControlArray1DHandle handle,
                                        double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_closest_index");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_closest_index(value);
  FALCON_C_API_END(0)
}

ListFArrayDoubleHandle ControlArray1D_even_divisions(
    ControlArray1DHandle handle, size_t divisions) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_even_divisions");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::ListSP<generic::FArray<double>> divisions_arr =
      control_array->even_divisions(divisions);
  ListFArrayDoubleHandle out_handle =
      new generic::ListSP<generic::FArray<double>>(
          std::make_shared<generic::List<generic::FArray<double>>>());
  generic::ListSP<generic::FArray<double>> out_list =
      *static_cast<generic::ListSP<generic::FArray<double>>*>(out_handle);
  for (const auto& arr : divisions_arr->items()) {
    out_list->push_back(arr);
  }
  return out_handle;
  FALCON_C_API_END(nullptr)
}

size_t ControlArray1D_size(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_size");
  }
  auto control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->size();
  FALCON_C_API_END(0)
}

size_t ControlArray1D_dimension(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_dimension");
  }
  auto control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->dimension();
  FALCON_C_API_END(0)
}

size_t ControlArray1D_shape(ControlArray1DHandle handle,
                            size_t*              out_buffer,
                            size_t               ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_shape");
  }
  auto   control_array = *static_cast<ControlArray1DSP*>(handle);
  auto   shape         = control_array->shape();
  size_t count         = shape.size();
  size_t to_copy       = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t ControlArray1D_data(ControlArray1DHandle handle,
                           double*              out_buffer,
                           size_t               numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_data");
  }
  auto   control_array = *static_cast<ControlArray1DSP*>(handle);
  auto   data          = control_array->data();
  size_t count         = control_array->size();
  size_t to_copy       = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void ControlArray1D_plus_equals_farray(ControlArray1DHandle handle,
                                       FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_equals_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  *control_array += *oarray;
  FALCON_C_API_END()
}

void ControlArray1D_plus_equals_double(ControlArray1DHandle handle,
                                       const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_equals_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator+=(other);
  FALCON_C_API_END()
}

void ControlArray1D_plus_equals_int(ControlArray1DHandle handle,
                                    const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_equals_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator+=(other);
  FALCON_C_API_END()
}

ControlArray1DHandle ControlArray1D_plus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_control_array");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return new ControlArray1DSP(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_plus_farray(ControlArray1DHandle handle,
                                                FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new ControlArray1DSP(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_plus_double(ControlArray1DHandle handle,
                                                const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_plus_int(ControlArray1DHandle handle,
                                             const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_plus_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void ControlArray1D_minus_equals_farray(ControlArray1DHandle handle,
                                        FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_equals_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  control_array->operator-=(*oarray);
  FALCON_C_API_END()
}

void ControlArray1D_minus_equals_double(ControlArray1DHandle handle,
                                        const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_equals_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator-=(other);
  FALCON_C_API_END()
}

void ControlArray1D_minus_equals_int(ControlArray1DHandle handle,
                                     const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_equals_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator-=(other);
  FALCON_C_API_END()
}

ControlArray1DHandle ControlArray1D_minus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_control_array");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return new ControlArray1DSP(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_minus_farray(ControlArray1DHandle handle,
                                                 FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new ControlArray1DSP(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_minus_double(ControlArray1DHandle handle,
                                                 const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_minus_int(ControlArray1DHandle handle,
                                              const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_minus_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_negation(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_negation");
  }
  return new ControlArray1DSP(-*(*static_cast<ControlArray1DSP*>(handle)));
  FALCON_C_API_END(nullptr)
}

void ControlArray1D_times_equals_double(ControlArray1DHandle handle,
                                        const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_times_equals_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator*=(other);
  FALCON_C_API_END()
}

void ControlArray1D_times_equals_int(ControlArray1DHandle handle,
                                     const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_times_equals_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator*=(other);
  FALCON_C_API_END()
}

ControlArray1DHandle ControlArray1D_times_double(ControlArray1DHandle handle,
                                                 const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_times_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_times_int(ControlArray1DHandle handle,
                                              const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_times_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void ControlArray1D_divides_equals_double(ControlArray1DHandle handle,
                                          const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_divides_equals_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator/=(other);
  FALCON_C_API_END()
}

void ControlArray1D_divides_equals_int(ControlArray1DHandle handle,
                                       const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_divides_equals_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->operator/=(other);
  FALCON_C_API_END()
}

ControlArray1DHandle ControlArray1D_divides_double(ControlArray1DHandle handle,
                                                   const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_divides_double");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_divides_int(ControlArray1DHandle handle,
                                                const int            other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_divides_int");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_pow(ControlArray1DHandle handle,
                                        const double         other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_pow");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_abs(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_abs");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->abs());
  FALCON_C_API_END(nullptr)
}

double ControlArray1D_min(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_min");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->min();
  FALCON_C_API_END(0.0)
}

ControlArray1DHandle ControlArray1D_min_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_min_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new ControlArray1DSP(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_min_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_min_control_array");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return new ControlArray1DSP(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

double ControlArray1D_max(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_max");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->max();
  FALCON_C_API_END(0.0)
}

ControlArray1DHandle ControlArray1D_max_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_max_farray");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new ControlArray1DSP(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_max_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_max_control_array");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return new ControlArray1DSP(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

bool ControlArray1D_equal(ControlArray1DHandle handle,
                          ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_equal");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return control_array->operator==(*oarray);
  FALCON_C_API_END(false)
}

bool ControlArray1D_not_equal(ControlArray1DHandle handle,
                              ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_not_equal");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return control_array->operator!=(*oarray);
  FALCON_C_API_END(false)
}

bool ControlArray1D_greater_than(ControlArray1DHandle handle,
                                 const double         value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_greater_than");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->operator>(value);
  FALCON_C_API_END(false)
}

bool ControlArray1D_less_than(ControlArray1DHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_less_than");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->operator<(value);
  FALCON_C_API_END(false)
}

void ControlArray1D_remove_offset(ControlArray1DHandle handle,
                                  const double         offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_remove_offset");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double ControlArray1D_sum(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_sum");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->sum();
  FALCON_C_API_END(0.0)
}

ListListSizeTHandle ControlArray1D_where(ControlArray1DHandle handle,
                                         const double         value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_where");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::ListSP<generic::List<size_t>> where_result =
      control_array->where(value);
  ListListSizeTHandle out_handle = new generic::ListSP<generic::List<size_t>>(
      std::make_shared<generic::List<generic::List<size_t>>>());
  generic::ListSP<generic::List<size_t>> out_list =
      *static_cast<generic::ListSP<generic::List<size_t>>*>(out_handle);
  for (const auto& lst : where_result->items()) {
    out_list->push_back(lst);
  }
  return out_handle;
  FALCON_C_API_END(nullptr)
}
ControlArray1DHandle ControlArray1D_flip(ControlArray1DHandle handle,
                                         size_t               axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray1D_flip");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new ControlArray1DSP(control_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t ControlArray1D_full_gradient(ControlArray1DHandle handle,
                                    FArrayDoubleHandle*  out_buffer,
                                    size_t               buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_full_gradient");
  }
  if (!out_buffer) {
    throw std::invalid_argument(
        "Null output buffer passed to ControlArray1D_full_gradient");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  generic::ListSP<generic::FArray<double>> gradients =
      control_array->gradient();
  size_t count   = gradients->size();
  size_t to_copy = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArraySP<double>(gradients->items()[i]);
  }
  return to_copy;
  FALCON_C_API_END(0)
}

FArrayDoubleHandle ControlArray1D_gradient(ControlArray1DHandle handle,
                                           size_t               axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_gradient");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return new generic::FArraySP<double>(control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double ControlArray1D_get_sum_of_squares(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_sum_of_squares");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_summed_diff_int_of_squares(
    ControlArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_get_summed_diff_int_of_squares");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_summed_diff_double_of_squares(
    ControlArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "ControlArray1D_get_summed_diff_double_of_squares");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  return control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double ControlArray1D_get_summed_diff_array_of_squares(
    ControlArray1DHandle handle, ControlArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "ControlArray1D_get_summed_diff_array_of_squares");
  }
  ControlArray1DSP control_array = *static_cast<ControlArray1DSP*>(handle);
  ControlArray1DSP oarray        = *static_cast<ControlArray1DSP*>(other);
  return control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle ControlArray1D_to_json_string(ControlArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray1D_to_json_string");
  }
  std::string json =
      (*static_cast<ControlArray1DSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ControlArray1DHandle ControlArray1D_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to ControlArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = ControlArray1D::from_json_string<ControlArray1D>(raw_json);
  return new ControlArray1DSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
