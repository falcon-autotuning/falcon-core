#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

#include <falcon_core/math/arrays/MeasuredArray.hpp>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
MeasuredArrayHandle MeasuredArray_from_data(const double* data,
                                            const size_t* shape,
                                            size_t        ndim) {
  FALCON_C_API_BEGIN
  if (!data) {
    throw std::invalid_argument(
        "Null data pointer passed to MeasuredArray_from_data");
  }
  if (!shape) {
    throw std::invalid_argument(
        "Null shape pointer passed to MeasuredArray_from_data");
  }
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new MeasuredArraySP(std::make_shared<MeasuredArray>(arr));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_from_farray(FArrayDoubleHandle farray) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_from_farray");
  }
  generic::FArraySP<double> real_farray =
      *static_cast<generic::FArraySP<double>*>(farray);
  return new MeasuredArraySP(std::make_shared<MeasuredArray>(real_farray));
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_destroy(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_destroy");
  }
  delete static_cast<MeasuredArraySP*>(handle);
  FALCON_C_API_END()
}

size_t MeasuredArray_size(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_size");
  }
  auto measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->size();
  FALCON_C_API_END(0)
}

size_t MeasuredArray_dimension(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dimension");
  }
  auto measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->dimension();
  FALCON_C_API_END(0)
}

size_t MeasuredArray_shape(MeasuredArrayHandle handle,
                           size_t*             out_buffer,
                           size_t              ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_shape");
  }
  auto   measured_array = *static_cast<MeasuredArraySP*>(handle);
  auto   shape          = measured_array->shape();
  size_t count          = shape.size();
  size_t to_copy        = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t MeasuredArray_data(MeasuredArrayHandle handle,
                          double*             out_buffer,
                          size_t              numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_data");
  }
  auto   measured_array = *static_cast<MeasuredArraySP*>(handle);
  auto   data           = measured_array->data();
  size_t count          = measured_array->size();
  size_t to_copy        = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void MeasuredArray_plus_equals_farray(MeasuredArrayHandle handle,
                                      FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_equals_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator+=(*oarray);
  FALCON_C_API_END()
}

void MeasuredArray_plus_equals_double(MeasuredArrayHandle handle,
                                      const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_equals_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator+=(other);
  FALCON_C_API_END()
}

void MeasuredArray_plus_equals_int(MeasuredArrayHandle handle,
                                   const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_equals_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator+=(other);
  FALCON_C_API_END()
}

MeasuredArrayHandle MeasuredArray_plus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_farray(MeasuredArrayHandle handle,
                                              FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_double(MeasuredArrayHandle handle,
                                              const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_int(MeasuredArrayHandle handle,
                                           const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_plus_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_minus_equals_farray(MeasuredArrayHandle handle,
                                       FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_equals_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator-=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void MeasuredArray_minus_equals_double(MeasuredArrayHandle handle,
                                       const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_equals_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator-=(other);
  FALCON_C_API_END()
}

void MeasuredArray_minus_equals_int(MeasuredArrayHandle handle,
                                    const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_equals_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator-=(other);
  FALCON_C_API_END()
}

MeasuredArrayHandle MeasuredArray_minus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_double(MeasuredArrayHandle handle,
                                               const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_int(MeasuredArrayHandle handle,
                                            const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_negation(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_negation");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(-*measured_array);
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  measured_array->operator*=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_equals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator*=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_times_equals_double(MeasuredArrayHandle handle,
                                       const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator*=(other);
  FALCON_C_API_END()
}

void MeasuredArray_times_equals_int(MeasuredArrayHandle handle,
                                    const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator*=(other);
  FALCON_C_API_END()
}

MeasuredArrayHandle MeasuredArray_times_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->operator*(oarray));
  FALCON_C_API_END(nullptr)
}
MeasuredArrayHandle MeasuredArray_times_double(MeasuredArrayHandle handle,
                                               const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_int(MeasuredArrayHandle handle,
                                            const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_equals_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  measured_array->operator/=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_equals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_equals_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  measured_array->operator/=(*oarray);
  return handle;
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_divides_equals_double(MeasuredArrayHandle handle,
                                         const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_equals_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator/=(other);
  FALCON_C_API_END()
}

void MeasuredArray_divides_equals_int(MeasuredArrayHandle handle,
                                      const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_equals_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->operator/=(other);
  FALCON_C_API_END()
}

MeasuredArrayHandle MeasuredArray_divides_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_farray(MeasuredArrayHandle handle,
                                                 FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->operator/(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_double(MeasuredArrayHandle handle,
                                                 const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_double");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_int(MeasuredArrayHandle handle,
                                              const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_int");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_pow(MeasuredArrayHandle handle,
                                      const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_pow");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_abs(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_abs");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->abs());
  FALCON_C_API_END(nullptr)
}

double MeasuredArray_min(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_min");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->min();
  FALCON_C_API_END(0.0)
}

MeasuredArrayHandle MeasuredArray_min_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_min_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

double MeasuredArray_max(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_max");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->max();
  FALCON_C_API_END(0.0)
}

MeasuredArrayHandle MeasuredArray_max_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_farray");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);

  generic::FArraySP<double> oarray =
      *static_cast<generic::FArraySP<double>*>(other);
  return new MeasuredArraySP(measured_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_max_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_measured_array");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return new MeasuredArraySP(measured_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

bool MeasuredArray_equal(MeasuredArrayHandle handle,
                         MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_equal");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return measured_array->operator==(*oarray);
  FALCON_C_API_END(false)
}

bool MeasuredArray_not_equal(MeasuredArrayHandle handle,
                             MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_not_equal");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return measured_array->operator!=(*oarray);
  FALCON_C_API_END(false)
}

bool MeasuredArray_greater_than(MeasuredArrayHandle handle,
                                const double        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_greater_than");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->operator>(value);
  FALCON_C_API_END(false)
}

bool MeasuredArray_less_than(MeasuredArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_less_than");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->operator<(value);
  FALCON_C_API_END(false)
}
void MeasuredArray_remove_offset(MeasuredArrayHandle handle,
                                 const double        offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_remove_offset");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  measured_array->remove_offset(offset);
  FALCON_C_API_END()
}

double MeasuredArray_sum(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_sum");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->sum();
  FALCON_C_API_END(0.0)
}

MeasuredArrayHandle MeasuredArray_reshape(MeasuredArrayHandle handle,
                                          const size_t*       shape,
                                          size_t              ndims) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_reshape");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  std::vector<std::vector<double>::size_type> shapeVec;
  for (size_t i = 0; i < ndims; ++i) {
    shapeVec.push_back(shape[i]);
  }
  return new MeasuredArraySP(measured_array->reshape(shapeVec));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle MeasuredArray_where(MeasuredArrayHandle handle,
                                        const double        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_where");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  auto            indices        = measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_flip(MeasuredArrayHandle handle,
                                       size_t              axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_flip");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(measured_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t MeasuredArray_full_gradient(MeasuredArrayHandle  handle,
                                   MeasuredArrayHandle* out_buffer,
                                   size_t               buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_full_gradient");
  }
  if (!out_buffer) {
    throw std::invalid_argument(
        "Null output buffer passed to MeasuredArray_full_gradient");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  auto            gradients      = measured_array->gradient();
  size_t          count          = gradients->size();
  size_t          to_copy        = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new MeasuredArraySP(
        std::make_shared<MeasuredArray>(gradients->items()[i]));
  }
  return to_copy;
  FALCON_C_API_END(0)
}

MeasuredArrayHandle MeasuredArray_gradient(MeasuredArrayHandle handle,
                                           size_t              axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_gradient");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return new MeasuredArraySP(
      std::make_shared<MeasuredArray>(measured_array->gradient(axis)));
  FALCON_C_API_END(nullptr)
}

double MeasuredArray_get_sum_of_squares(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_sum_of_squares");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double MeasuredArray_get_summed_diff_int_of_squares(MeasuredArrayHandle handle,
                                                    const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_summed_diff_int_of_squares");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double MeasuredArray_get_summed_diff_double_of_squares(
    MeasuredArrayHandle handle, const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray_get_summed_diff_double_of_squares");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  return measured_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double MeasuredArray_get_summed_diff_array_of_squares(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_summed_diff_array_of_squares");
  }
  MeasuredArraySP measured_array = *static_cast<MeasuredArraySP*>(handle);
  MeasuredArraySP oarray         = *static_cast<MeasuredArraySP*>(other);
  return measured_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle MeasuredArray_to_json_string(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_to_json_string");
  }
  std::string json = (*static_cast<MeasuredArraySP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to MeasuredArray_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = MeasuredArray::from_json_string<MeasuredArray>(raw_json);
  return new MeasuredArraySP(ptr);
  FALCON_C_API_END(nullptr)
}
}
