#include "falcon_core/math/arrays/MeasuredArray1D_c_api.h"

#include <falcon_core/math/arrays/MeasuredArray1D.hpp>
#include <xtensor/xadapt.hpp>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
DEFINE_C_API_COPY(MeasuredArray1D);
DEFINE_C_API_DESTROY(MeasuredArray1D);
DEFINE_C_API_EQUAL(MeasuredArray1D);
DEFINE_C_API_NOT_EQUAL(MeasuredArray1D);
DEFINE_C_API_TO_JSON(MeasuredArray1D);
DEFINE_C_API_FROM_JSON(MeasuredArray1D);
MeasuredArray1DHandle MeasuredArray1D_from_data(const double* data,
                                                const size_t* shape,
                                                size_t        ndim) {
  FALCON_C_API_BEGIN
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
  return new MeasuredArray1DSP(std::make_shared<MeasuredArray1D>(arr));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_from_farray(FArrayDoubleHandle farray) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_from_farray");
  }
  generic::FArraySP<double> real_farray =
      *static_cast<generic::FArraySP<double>*>(farray);
  return new MeasuredArray1DSP(std::make_shared<MeasuredArray1D>(real_farray));
  FALCON_C_API_END(nullptr)
}

bool MeasuredArray1D_is_1D(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_is_1D");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->is_1D();
  FALCON_C_API_END(false)
}

FArrayDoubleHandle MeasuredArray1D_as_1D(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_as_1D");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto              farray         = measured_array->as_1D();
  return new generic::FArraySP<double>(
      std::make_shared<generic::FArray<double>>(farray->data()));
  FALCON_C_API_END(nullptr)
}

double MeasuredArray1D_get_start(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_start");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_start();
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_end(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_end");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_end();
  FALCON_C_API_END(0.0)
}

bool MeasuredArray1D_is_decreasing(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_is_decreasing");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->is_decreasing();
  FALCON_C_API_END(false)
}

bool MeasuredArray1D_is_increasing(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_is_decreasing");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->is_increasing();
  FALCON_C_API_END(false)
}

double MeasuredArray1D_get_distance(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_distance");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_distance();
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_mean(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_mean");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_mean();
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_std(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_std");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_std();
  FALCON_C_API_END(0.0)
}

void MeasuredArray1D_reverse(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_reverse");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->reverse();
  FALCON_C_API_END()
}

size_t MeasuredArray1D_get_closest_index(MeasuredArray1DHandle handle,
                                         double                value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_closest_index");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_closest_index(value);
  FALCON_C_API_END(0)
}

ListFArrayDoubleHandle MeasuredArray1D_even_divisions(
    MeasuredArray1DHandle handle, size_t divisions) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_even_divisions");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto              farrays        = measured_array->even_divisions(divisions);
  return new generic::ListSP<generic::FArray<double>>(farrays);
  FALCON_C_API_END(nullptr)
}

size_t MeasuredArray1D_size(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_size");
  }
  auto measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->size();
  FALCON_C_API_END(0)
}

size_t MeasuredArray1D_dimension(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_dimension");
  }
  auto measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->dimension();
  FALCON_C_API_END(0)
}

size_t MeasuredArray1D_shape(MeasuredArray1DHandle handle,
                             size_t*               out_buffer,
                             size_t                ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_shape");
  }
  auto   measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto   shape          = measured_array->shape();
  size_t count          = shape.size();
  size_t to_copy        = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t MeasuredArray1D_data(MeasuredArray1DHandle handle,
                            double*               out_buffer,
                            size_t                numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_data");
  }
  auto   measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto   data           = measured_array->data();
  size_t count          = measured_array->size();
  size_t to_copy        = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void MeasuredArray1D_plus_equals_farray(MeasuredArray1DHandle handle,
                                        FArrayDoubleHandle    other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_equals_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator+=(*oarray);
  FALCON_C_API_END()
}

void MeasuredArray1D_plus_equals_double(MeasuredArray1DHandle handle,
                                        const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_equals_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator+=(other);
  FALCON_C_API_END()
}

void MeasuredArray1D_plus_equals_int(MeasuredArray1DHandle handle,
                                     const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_equals_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator+=(other);
  FALCON_C_API_END()
}

MeasuredArray1DHandle MeasuredArray1D_plus_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_measured_array");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  return new MeasuredArray1DSP(measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_plus_farray(MeasuredArray1DHandle handle,
                                                  FArrayDoubleHandle    other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_plus_double(MeasuredArray1DHandle handle,
                                                  const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_plus_int(MeasuredArray1DHandle handle,
                                               const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_plus_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void MeasuredArray1D_minus_equals_farray(MeasuredArray1DHandle handle,
                                         FArrayDoubleHandle    other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_equals_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator-=(*oarray);
  FALCON_C_API_END()
}

void MeasuredArray1D_minus_equals_double(MeasuredArray1DHandle handle,
                                         const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_equals_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator-=(other);
  FALCON_C_API_END()
}

void MeasuredArray1D_minus_equals_int(MeasuredArray1DHandle handle,
                                      const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_equals_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator-=(other);
  FALCON_C_API_END()
}

MeasuredArray1DHandle MeasuredArray1D_minus_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_measured_array");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  return new MeasuredArray1DSP(measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_minus_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_minus_double(MeasuredArray1DHandle handle,
                                                   const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_minus_int(MeasuredArray1DHandle handle,
                                                const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_minus_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_negation(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_negation");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(-*measured_array);
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_times_equals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_equals_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator*=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

void MeasuredArray1D_times_equals_double(MeasuredArray1DHandle handle,
                                         const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_equals_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator*=(other);
  FALCON_C_API_END()
}

void MeasuredArray1D_times_equals_int(MeasuredArray1DHandle handle,
                                      const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_equals_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator*=(other);
  FALCON_C_API_END()
}

MeasuredArray1DHandle MeasuredArray1D_times_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_measured_array");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  return new MeasuredArray1DSP(measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_times_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_times_double(MeasuredArray1DHandle handle,
                                                   const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_times_int(MeasuredArray1DHandle handle,
                                                const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_times_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_divides_equals_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_equals_measured_array");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  measured_array->operator/=(MeasuredArray1D(*oarray));
  return handle;
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_divides_equals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_equals_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator/=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

void MeasuredArray1D_divides_equals_double(MeasuredArray1DHandle handle,
                                           const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_equals_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator/=(other);
  FALCON_C_API_END()
}

void MeasuredArray1D_divides_equals_int(MeasuredArray1DHandle handle,
                                        const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_equals_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->operator/=(other);
  FALCON_C_API_END()
}

MeasuredArray1DHandle MeasuredArray1D_divides_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_measured_array");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  return new MeasuredArray1DSP(measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_divides_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_divides_double(
    MeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_double");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_divides_int(MeasuredArray1DHandle handle,
                                                  const int             other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_divides_int");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_pow(MeasuredArray1DHandle handle,
                                          const double          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_pow");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_abs(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_abs");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->abs());
  FALCON_C_API_END(nullptr)
}

double MeasuredArray1D_min(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_min");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->min();
  FALCON_C_API_END(0.0)
}

MeasuredArray1DHandle MeasuredArray1D_min_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_min_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_min_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_min_measured_array");
  }
  return new MeasuredArray1DSP(
      (*static_cast<MeasuredArray1DSP*>(handle))
          ->min(*static_cast<MeasuredArray1DSP*>(other)));
  FALCON_C_API_END(nullptr)
}

double MeasuredArray1D_max(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_max");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->max();
  FALCON_C_API_END(0.0)
}

MeasuredArray1DHandle MeasuredArray1D_max_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_max_farray");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArray1DSP(measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_max_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_max_measured_array");
  }
  return new MeasuredArray1DSP(
      (*static_cast<MeasuredArray1DSP*>(handle))
          ->max(*static_cast<MeasuredArray1DSP*>(other)));
  FALCON_C_API_END(nullptr)
}

bool MeasuredArray1D_greater_than(MeasuredArray1DHandle handle,
                                  const double          value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_greater_than");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->operator>(value);
  FALCON_C_API_END(false)
}

bool MeasuredArray1D_less_than(MeasuredArray1DHandle handle,
                               const double          value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_less_than");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->operator<(value);
  FALCON_C_API_END(false)
}

void MeasuredArray1D_remove_offset(MeasuredArray1DHandle handle,
                                   const double          offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_remove_offset");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  measured_array->remove_offset(offset);
  FALCON_C_API_END()
}

double MeasuredArray1D_sum(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_sum");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->sum();
  FALCON_C_API_END(0.0)
}

MeasuredArray1DHandle MeasuredArray1D_reshape(MeasuredArray1DHandle handle,
                                              const size_t*         shape,
                                              size_t                ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_reshape");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  std::vector<std::vector<double>::size_type> shapeVec;
  for (size_t i = 0; i < ndims; ++i) {
    shapeVec.push_back(shape[i]);
  }
  return new MeasuredArray1DSP(measured_array->reshape(shapeVec));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle MeasuredArray1D_where(MeasuredArray1DHandle handle,
                                          const double          value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_where");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto              locations      = measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*locations);
  FALCON_C_API_END(nullptr)
}

MeasuredArray1DHandle MeasuredArray1D_flip(MeasuredArray1DHandle handle,
                                           size_t                axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray1D_flip");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(measured_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t MeasuredArray1D_full_gradient(MeasuredArray1DHandle  handle,
                                     MeasuredArray1DHandle* out_buffer,
                                     size_t                 buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_full_gradient");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  auto              gradients      = measured_array->gradient();
  size_t            count          = gradients->size();
  size_t            to_copy = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new MeasuredArray1DSP(
        std::make_shared<MeasuredArray1D>(gradients->items()[i]));
  }
  return to_copy;
  FALCON_C_API_END(0)
}

MeasuredArray1DHandle MeasuredArray1D_gradient(MeasuredArray1DHandle handle,
                                               size_t                axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_gradient");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return new MeasuredArray1DSP(
      std::make_shared<MeasuredArray1D>(measured_array->gradient(axis)));
  FALCON_C_API_END(nullptr)
}
double MeasuredArray1D_get_sum_of_squares(MeasuredArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_sum_of_squares");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_summed_diff_int_of_squares(
    MeasuredArray1DHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray1D_get_summed_diff_int_of_squares");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_summed_diff_double_of_squares(
    MeasuredArray1DHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray1D_get_summed_diff_double_of_squares");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  return measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double MeasuredArray1D_get_summed_diff_array_of_squares(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray1D_get_summed_diff_array_of_squares");
  }
  MeasuredArray1DSP measured_array = *static_cast<MeasuredArray1DSP*>(handle);
  MeasuredArray1DSP oarray         = *static_cast<MeasuredArray1DSP*>(other);
  return measured_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}
}
