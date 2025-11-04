#include "falcon_core/math/arrays/MeasuredArray1D_c_api.h"

#include <falcon_core/math/arrays/MeasuredArray1D.hpp>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

MeasuredArray1DHandle MeasuredArray1D_from_data(const double* data,
                                                const size_t* shape,
                                                size_t        ndim) {
  if (!data) {
    throw std::invalid_argument(
        "Null data pointer passed to MeasuredArray1D_from_data");
  }
  if (!shape) {
    throw std::invalid_argument(
        "Null shape pointer passed to MeasuredArray1D_from_data");
  }
  for (size_t i = 0; i < ndim; ++i) {
    if (shape[i] == 0) {
      throw std::invalid_argument(
          "Shape dimensions must be greater than zero in "
          "MeasuredArray1D_from_data");
    }
  }
  if (ndim != 1) {
    throw std::invalid_argument(
        "MeasuredArray1D_from_data requires ndim to be 1");
  }
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new MeasuredArray1D(arr);
}

MeasuredArray1DHandle MeasuredArray1D_from_farray(FArrayDoubleHandle farray) {
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_from_farray");
  }
  generic::FArray<double>* real_farray =
      static_cast<generic::FArray<double>*>(farray);
  return new MeasuredArray1D(
      MeasuredArray1D(std::make_shared<generic::FArray<double>>(*real_farray)));
}

void MeasuredArray1D_destroy(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_destroy");
  }
  delete static_cast<MeasuredArray1D*>(handle);
}

bool MeasuredArray1D_is_1D(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_is_1D");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->is_1D();
}

FArrayDoubleHandle MeasuredArray1D_as_1D(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_as_1D");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  auto             farray         = measured_array->as_1D();
  return new generic::FArray<double>(farray->xtensor());
}

double MeasuredArray1D_get_start(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_start");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_start();
}

double MeasuredArray1D_get_end(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_end");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_end();
}

bool MeasuredArray1D_is_decreasing(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_is_decreasing");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->is_decreasing();
}

bool MeasuredArray1D_is_increasing(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_is_decreasing");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->is_increasing();
}

double MeasuredArray1D_get_distance(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_distance");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_distance();
}

double MeasuredArray1D_get_mean(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_mean");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_mean();
}

double MeasuredArray1D_get_std(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_std");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_std();
}

void MeasuredArray1D_reverse(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_reverse");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->reverse();
}

size_t MeasuredArray1D_get_closest_index(MeasuredArray1DHandle handle,
                                         double                value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_closest_index");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_closest_index(value);
}

ListFArrayDoubleHandle MeasuredArray1D_even_divisions(
    MeasuredArray1DHandle handle, size_t divisions) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_even_divisions");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  auto             farrays        = measured_array->even_divisions(divisions);
  return new generic::List<generic::FArray<double>>(*farrays);
}

size_t MeasuredArray1D_size(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_size");
  }
  auto measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->size();
}

size_t MeasuredArray1D_dimension(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dimension");
  }
  auto measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->dimension();
}

size_t MeasuredArray1D_shape(MeasuredArray1DHandle handle,
                             size_t*               out_buffer,
                             size_t                ndim) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_shape");
  }
  auto   measured_array = static_cast<MeasuredArray1D*>(handle);
  auto   shape          = measured_array->shape();
  size_t count          = shape.size();
  size_t to_copy        = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
}

size_t MeasuredArray1D_data(MeasuredArray1DHandle handle,
                            double*               out_buffer,
                            size_t                numdata) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_data");
  }
  auto   measured_array = static_cast<MeasuredArray1D*>(handle);
  auto   data           = measured_array->data();
  size_t count          = measured_array->size();
  size_t to_copy        = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
}

void MeasuredArray1D_plusequals_farray(MeasuredArray1DHandle handle,
                                       FArrayDoubleHandle    other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plusequals_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator+=(generic::FArray<double>(*oarray));
}

void MeasuredArray1D_plusequals_double(MeasuredArray1DHandle handle,
                                       const double          other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plusequals_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator+=(other);
}

void MeasuredArray1D_plusequals_int(MeasuredArray1DHandle handle,
                                    const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plusequals_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator+=(other);
}

MeasuredArray1DHandle MeasuredArray1D_plus_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_control_array");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  return new MeasuredArray1D(*measured_array->operator+(oarray));
}

MeasuredArray1DHandle MeasuredArray1D_plus_farray(MeasuredArray1DHandle handle,
                                                  FArrayDoubleHandle    other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_plus_double(MeasuredArray1DHandle handle,
                                                  const double          other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator+(other));
}

MeasuredArray1DHandle MeasuredArray1D_plus_int(MeasuredArray1DHandle handle,
                                               const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator+(other));
}

void MeasuredArray1D_minusequals_farray(MeasuredArray1DHandle handle,
                                        FArrayDoubleHandle    other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minusequals_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator-=(generic::FArray<double>(*oarray));
}

void MeasuredArray1D_minusequals_double(MeasuredArray1DHandle handle,
                                        const double          other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minusequals_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator-=(other);
}

void MeasuredArray1D_minusequals_int(MeasuredArray1DHandle handle,
                                     const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minusequals_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator-=(other);
}

MeasuredArray1DHandle MeasuredArray1D_minus_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_control_array");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  return new MeasuredArray1D(*measured_array->operator-(oarray));
}

MeasuredArray1DHandle MeasuredArray1D_minus_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_minus_double(MeasuredArray1DHandle handle,
                                                   const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator-(other));
}

MeasuredArray1DHandle MeasuredArray1D_minus_int(MeasuredArray1DHandle handle,
                                                const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator-(other));
}

MeasuredArray1DHandle MeasuredArray1D_negation(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_negation");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*-*measured_array);
}

MeasuredArray1DHandle MeasuredArray1D_timesequals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_timesequals_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator*=(generic::FArray<double>(*oarray));
  return handle;
}

void MeasuredArray1D_timesequals_double(MeasuredArray1DHandle handle,
                                        const double          other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_timesequals_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator*=(other);
}

void MeasuredArray1D_timesequals_int(MeasuredArray1DHandle handle,
                                     const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_timesequals_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator*=(other);
}

MeasuredArray1DHandle MeasuredArray1D_times_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_measured_array");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  return new MeasuredArray1D(*measured_array->operator*(oarray));
}

MeasuredArray1DHandle MeasuredArray1D_times_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator*(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_times_double(MeasuredArray1DHandle handle,
                                                   const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator*(other));
}

MeasuredArray1DHandle MeasuredArray1D_times_int(MeasuredArray1DHandle handle,
                                                const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator*(other));
}

MeasuredArray1DHandle MeasuredArray1D_dividesequals_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dividesequals_measured_array");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  measured_array->operator/=(MeasuredArray1D(*oarray));
  return handle;
}

MeasuredArray1DHandle MeasuredArray1D_dividesequals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dividesequals_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator/=(generic::FArray<double>(*oarray));
  return handle;
}

void MeasuredArray1D_dividesequals_double(MeasuredArray1DHandle handle,
                                          const double          other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dividesequals_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator/=(other);
}

void MeasuredArray1D_dividesequals_int(MeasuredArray1DHandle handle,
                                       const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dividesequals_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->operator/=(other);
}

MeasuredArray1DHandle MeasuredArray1D_divides_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_measured_array");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  return new MeasuredArray1D(*measured_array->operator/(oarray));
}

MeasuredArray1DHandle MeasuredArray1D_divides_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator/(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_divides_double(
    MeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_double");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator/(other));
}

MeasuredArray1DHandle MeasuredArray1D_divides_int(MeasuredArray1DHandle handle,
                                                  const int             other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_int");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator/(other));
}

MeasuredArray1DHandle MeasuredArray1D_pow(MeasuredArray1DHandle handle,
                                          const double          other) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_pow");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->operator^(other));
}

MeasuredArray1DHandle MeasuredArray1D_abs(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_abs");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->abs());
}

MeasuredArray1DHandle MeasuredArray1D_min_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_min_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_min_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_min_control_array");
  }
  return new MeasuredArray1D(*static_cast<MeasuredArray1D*>(handle)->min(
      std::make_shared<MeasuredArray1D>(
          *static_cast<MeasuredArray1D*>(other))));
}

MeasuredArray1DHandle MeasuredArray1D_max_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_max_farray");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray1D(*measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArray1DHandle MeasuredArray1D_max_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_max_control_array");
  }
  return new MeasuredArray1D(*static_cast<MeasuredArray1D*>(handle)->max(
      std::make_shared<MeasuredArray1D>(
          *static_cast<MeasuredArray1D*>(other))));
}

bool MeasuredArray1D_equality(MeasuredArray1DHandle handle,
                              MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_equality");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1D* oarray         = static_cast<MeasuredArray1D*>(other);
  return measured_array->operator==(*oarray);
}

bool MeasuredArray1D_notequality(MeasuredArray1DHandle handle,
                                 MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_notequality");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1D* oarray         = static_cast<MeasuredArray1D*>(other);
  return measured_array->operator!=(*oarray);
}

bool MeasuredArray1D_greaterthan(MeasuredArray1DHandle handle,
                                 const double          value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_greaterthan");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->operator>(value);
}

bool MeasuredArray1D_lessthan(MeasuredArray1DHandle handle,
                              const double          value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_lessthan");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->operator<(value);
}

void MeasuredArray1D_remove_offset(MeasuredArray1DHandle handle,
                                   const double          offset) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_remove_offset");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  measured_array->remove_offset(offset);
}

double MeasuredArray1D_sum(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_sum");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->sum();
}

MeasuredArray1DHandle MeasuredArray1D_reshape(MeasuredArray1DHandle handle,
                                              const size_t*         shape,
                                              size_t                ndims) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_reshape");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  std::vector<std::vector<double>::size_type> shapeVec;
  for (size_t i = 0; i < ndims; ++i) {
    shapeVec.push_back(shape[i]);
  }
  return new MeasuredArray1D(*measured_array->reshape(shapeVec));
}

ListListSizeTHandle MeasuredArray1D_where(MeasuredArray1DHandle handle,
                                          const double          value) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_where");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  auto             locations      = measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*locations);
}

MeasuredArray1DHandle MeasuredArray1D_flip(MeasuredArray1DHandle handle,
                                           size_t                axis) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_flip");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->flip(axis));
}

size_t MeasuredArray1D_full_gradient(MeasuredArray1DHandle  handle,
                                     MeasuredArray1DHandle* out_buffer,
                                     size_t                 buffer_size) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_full_gradient");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  auto             gradients      = measured_array->gradient();
  size_t           count          = gradients->size();
  size_t           to_copy        = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new MeasuredArray1D(*gradients->items()[i]);
  }
  return to_copy;
}

MeasuredArray1DHandle MeasuredArray1D_gradient(MeasuredArray1DHandle handle,
                                               size_t                axis) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_gradient");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return new MeasuredArray1D(*measured_array->gradient(axis));
}
double MeasuredArray1D_get_sum_of_squares(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_sum_of_squares");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_sum_of_squares();
}

double MeasuredArray1D_get_summed_diff_int_of_squares(
    MeasuredArray1DHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_summed_diff_int_of_squares");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_sum_of_squares(other);
}

double MeasuredArray1D_get_summed_diff_double_of_squares(
    MeasuredArray1DHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray1D_get_summed_diff_double_of_squares");
  }
  MeasuredArray1D* measured_array = static_cast<MeasuredArray1D*>(handle);
  return measured_array->get_sum_of_squares(other);
}

double MeasuredArray1D_get_summed_diff_array_of_squares(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray1D_get_summed_diff_array_of_squares");
  }
  MeasuredArray1D*  measured_array = static_cast<MeasuredArray1D*>(handle);
  MeasuredArray1DSP oarray =
      std::make_shared<MeasuredArray1D>(*static_cast<MeasuredArray1D*>(other));
  return measured_array->get_sum_of_squares(oarray);
}

StringHandle MeasuredArray1D_to_json_string(MeasuredArray1DHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_to_json_string");
  }
  std::string json = static_cast<MeasuredArray1D*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MeasuredArray1DHandle MeasuredArray1D_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to MeasuredArray1D_from_json_string");
  }
  std::string raw_json(json->raw);
  auto ptr = MeasuredArray1D::from_json_string<MeasuredArray1D>(raw_json);
  return new MeasuredArray1D(*ptr);
}
