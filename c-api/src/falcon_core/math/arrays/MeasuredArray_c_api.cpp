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
  return new MeasuredArray(arr);
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_from_farray(FArrayDoubleHandle farray) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_from_farray");
  }
  generic::FArray<double>* real_farray =
      static_cast<generic::FArray<double>*>(farray);
  return new MeasuredArray(
      MeasuredArray(std::make_shared<generic::FArray<double>>(*real_farray)));
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_destroy(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_destroy");
  }
  delete static_cast<MeasuredArray*>(handle);
  FALCON_C_API_END()
}

size_t MeasuredArray_size(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_size");
  }
  auto measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->size();
  FALCON_C_API_END(0)
}

size_t MeasuredArray_dimension(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dimension");
  }
  auto measured_array = static_cast<MeasuredArray*>(handle);
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
  auto   measured_array = static_cast<MeasuredArray*>(handle);
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
  auto   measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator+=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void MeasuredArray_plus_equals_double(MeasuredArrayHandle handle,
                                     const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_equals_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator+=(other);
  FALCON_C_API_END()
}

void MeasuredArray_plus_equals_int(MeasuredArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_equals_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator+(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_farray(MeasuredArrayHandle handle,
                                              FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_double(MeasuredArrayHandle handle,
                                              const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_plus_int(MeasuredArrayHandle handle,
                                           const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_plus_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void MeasuredArray_minus_equals_farray(MeasuredArrayHandle handle,
                                      FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_equals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator-(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_double(MeasuredArrayHandle handle,
                                               const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_minus_int(MeasuredArrayHandle handle,
                                            const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_negation(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_negation");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(-*measured_array);
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  measured_array->operator*=(MeasuredArray(*oarray));
  return handle;
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_equals_farray(MeasuredArrayHandle handle,
                                                     FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_equals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator*=(generic::FArray<double>(*oarray));
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator*(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator*(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}
MeasuredArrayHandle MeasuredArray_times_double(MeasuredArrayHandle handle,
                                               const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_times_int(MeasuredArrayHandle handle,
                                            const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_equals_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  measured_array->operator/=(MeasuredArray(*oarray));
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
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator/=(generic::FArray<double>(*oarray));
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator/(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_farray(MeasuredArrayHandle handle,
                                                 FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator/(
      std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_double(MeasuredArrayHandle handle,
                                                 const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_divides_int(MeasuredArrayHandle handle,
                                              const int           other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_pow(MeasuredArrayHandle handle,
                                      const double        other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_pow");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_abs(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_abs");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->abs());
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_min_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(
      measured_array->min(std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_min_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->min(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_max_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(
      measured_array->max(std::make_shared<generic::FArray<double>>(*oarray)));
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_max_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->max(std::make_shared<MeasuredArray>(*oarray)));
  FALCON_C_API_END(nullptr)
}

bool MeasuredArray_equality(MeasuredArrayHandle handle,
                            MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_equality");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->operator==(MeasuredArray(*oarray));
  FALCON_C_API_END(false)
}

bool MeasuredArray_notequality(MeasuredArrayHandle handle,
                               MeasuredArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_notequality");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->operator!=(MeasuredArray(*oarray));
  FALCON_C_API_END(false)
}

bool MeasuredArray_greaterthan(MeasuredArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_greaterthan");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->operator>(value);
  FALCON_C_API_END(false)
}

bool MeasuredArray_lessthan(MeasuredArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_lessthan");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->remove_offset(offset);
  FALCON_C_API_END()
}

double MeasuredArray_sum(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_sum");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  std::vector<std::vector<double>::size_type> shapeVec;
  for (size_t i = 0; i < ndims; ++i) {
    shapeVec.push_back(shape[i]);
  }
  return new MeasuredArray(measured_array->reshape(shapeVec));
  FALCON_C_API_END(nullptr)
}

ListListSizeTHandle MeasuredArray_where(MeasuredArrayHandle handle,
                                        const double        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_where");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  auto           indices        = measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
  FALCON_C_API_END(nullptr)
}

MeasuredArrayHandle MeasuredArray_flip(MeasuredArrayHandle handle,
                                       size_t              axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_flip");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->flip(axis));
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  auto           gradients      = measured_array->gradient();
  size_t         count          = gradients->size();
  size_t         to_copy        = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new MeasuredArray(*gradients->items()[i]);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double MeasuredArray_get_sum_of_squares(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_sum_of_squares");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
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
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->get_sum_of_squares(
      std::make_shared<MeasuredArray>(*oarray));
  FALCON_C_API_END(0.0)
}

StringHandle MeasuredArray_to_json_string(MeasuredArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_to_json_string");
  }
  std::string json = static_cast<MeasuredArray*>(handle)->to_json_string();
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
  return new MeasuredArray(*ptr);
  FALCON_C_API_END(nullptr)
}
}
