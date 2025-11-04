#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

#include <falcon_core/math/arrays/MeasuredArray.hpp>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

MeasuredArrayHandle MeasuredArray_from_data(const double* data,
                                            const size_t* shape,
                                            size_t        ndim) {
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new MeasuredArray(arr);
}

MeasuredArrayHandle MeasuredArray_from_farray(FArrayDoubleHandle farray) {
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_from_farray");
  }
  generic::FArray<double>* real_farray =
      static_cast<generic::FArray<double>*>(farray);
  return new MeasuredArray(
      MeasuredArray(std::make_shared<generic::FArray<double>>(*real_farray)));
}

void MeasuredArray_destroy(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_destroy");
  }
  delete static_cast<MeasuredArray*>(handle);
}

size_t MeasuredArray_size(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_size");
  }
  auto measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->size();
}

size_t MeasuredArray_dimension(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dimension");
  }
  auto measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->dimension();
}

size_t MeasuredArray_shape(MeasuredArrayHandle handle,
                           size_t*             out_buffer,
                           size_t              ndim) {
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
}

size_t MeasuredArray_data(MeasuredArrayHandle handle,
                          double*             out_buffer,
                          size_t              numdata) {
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
}

void MeasuredArray_plusequals_farray(MeasuredArrayHandle handle,
                                     FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plusequals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator+=(generic::FArray<double>(*oarray));
}

void MeasuredArray_plusequals_double(MeasuredArrayHandle handle,
                                     const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plusequals_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator+=(other);
}

void MeasuredArray_plusequals_int(MeasuredArrayHandle handle, const int other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plusequals_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator+=(other);
}

MeasuredArrayHandle MeasuredArray_plus_control_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_control_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator+(std::make_shared<MeasuredArray>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_plus_farray(MeasuredArrayHandle handle,
                                              FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator+(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_plus_double(MeasuredArrayHandle handle,
                                              const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_plus_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator+(other));
}

MeasuredArrayHandle MeasuredArray_plus_int(MeasuredArrayHandle handle,
                                           const int           other) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_plus_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator+(other));
}

void MeasuredArray_minusequals_farray(MeasuredArrayHandle handle,
                                      FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minusequals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator-=(generic::FArray<double>(*oarray));
}

void MeasuredArray_minusequals_double(MeasuredArrayHandle handle,
                                      const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minusequals_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator-=(other);
}

void MeasuredArray_minusequals_int(MeasuredArrayHandle handle,
                                   const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minusequals_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator-=(other);
}

MeasuredArrayHandle MeasuredArray_minus_control_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_control_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator-(std::make_shared<MeasuredArray>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_minus_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator-(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_minus_double(MeasuredArrayHandle handle,
                                               const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator-(other));
}

MeasuredArrayHandle MeasuredArray_minus_int(MeasuredArrayHandle handle,
                                            const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_minus_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator-(other));
}

MeasuredArrayHandle MeasuredArray_negation(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_negation");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(-*measured_array);
}

MeasuredArrayHandle MeasuredArray_timesequals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_timesequals_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  measured_array->operator*=(MeasuredArray(*oarray));
  return handle;
}

MeasuredArrayHandle MeasuredArray_timesequals_farray(MeasuredArrayHandle handle,
                                                     FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_timesequals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator*=(generic::FArray<double>(*oarray));
  return handle;
}

void MeasuredArray_timesequals_double(MeasuredArrayHandle handle,
                                      const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_timesequals_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator*=(other);
}

void MeasuredArray_timesequals_int(MeasuredArrayHandle handle,
                                   const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_timesequals_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator*=(other);
}

MeasuredArrayHandle MeasuredArray_times_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator*(std::make_shared<MeasuredArray>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_times_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator*(
      std::make_shared<generic::FArray<double>>(*oarray)));
}
MeasuredArrayHandle MeasuredArray_times_double(MeasuredArrayHandle handle,
                                               const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator*(other));
}

MeasuredArrayHandle MeasuredArray_times_int(MeasuredArrayHandle handle,
                                            const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_times_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator*(other));
}

MeasuredArrayHandle MeasuredArray_dividesequals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dividesequals_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  measured_array->operator/=(MeasuredArray(*oarray));
  return handle;
}

MeasuredArrayHandle MeasuredArray_dividesequals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dividesequals_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  measured_array->operator/=(generic::FArray<double>(*oarray));
  return handle;
}

void MeasuredArray_dividesequals_double(MeasuredArrayHandle handle,
                                        const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dividesequals_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator/=(other);
}

void MeasuredArray_dividesequals_int(MeasuredArrayHandle handle,
                                     const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_dividesequals_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->operator/=(other);
}

MeasuredArrayHandle MeasuredArray_divides_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_measured_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->operator/(std::make_shared<MeasuredArray>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_divides_farray(MeasuredArrayHandle handle,
                                                 FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(measured_array->operator/(
      std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_divides_double(MeasuredArrayHandle handle,
                                                 const double        other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_double");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator/(other));
}

MeasuredArrayHandle MeasuredArray_divides_int(MeasuredArrayHandle handle,
                                              const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_divides_int");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator/(other));
}

MeasuredArrayHandle MeasuredArray_pow(MeasuredArrayHandle handle,
                                      const double        other) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_pow");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->operator^(other));
}

MeasuredArrayHandle MeasuredArray_abs(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_abs");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->abs());
}

MeasuredArrayHandle MeasuredArray_min_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(
      measured_array->min(std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_min_control_array(MeasuredArrayHandle handle,
                                                    MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_min_control_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->min(std::make_shared<MeasuredArray>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_max_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_farray");
  }
  MeasuredArray*           measured_array = static_cast<MeasuredArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  return new MeasuredArray(
      measured_array->max(std::make_shared<generic::FArray<double>>(*oarray)));
}

MeasuredArrayHandle MeasuredArray_max_control_array(MeasuredArrayHandle handle,
                                                    MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_max_control_array");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return new MeasuredArray(
      measured_array->max(std::make_shared<MeasuredArray>(*oarray)));
}

bool MeasuredArray_equality(MeasuredArrayHandle handle,
                            MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_equality");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->operator==(MeasuredArray(*oarray));
}

bool MeasuredArray_notequality(MeasuredArrayHandle handle,
                               MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_notequality");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->operator!=(MeasuredArray(*oarray));
}

bool MeasuredArray_greaterthan(MeasuredArrayHandle handle, const double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_greaterthan");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->operator>(value);
}

bool MeasuredArray_lessthan(MeasuredArrayHandle handle, const double value) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_lessthan");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->operator<(value);
}
void MeasuredArray_remove_offset(MeasuredArrayHandle handle,
                                 const double        offset) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_remove_offset");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  measured_array->remove_offset(offset);
}

double MeasuredArray_sum(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_sum");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->sum();
}

MeasuredArrayHandle MeasuredArray_reshape(MeasuredArrayHandle handle,
                                          const size_t*       shape,
                                          size_t              ndims) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_reshape");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  std::vector<std::vector<double>::size_type> shapeVec;
  for (size_t i = 0; i < ndims; ++i) {
    shapeVec.push_back(shape[i]);
  }
  return new MeasuredArray(measured_array->reshape(shapeVec));
}

ListListSizeTHandle MeasuredArray_where(MeasuredArrayHandle handle,
                                        const double        value) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_where");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  auto           indices        = measured_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices);
}

MeasuredArrayHandle MeasuredArray_flip(MeasuredArrayHandle handle,
                                       size_t              axis) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_flip");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->flip(axis));
}

size_t MeasuredArray_full_gradient(MeasuredArrayHandle  handle,
                                   MeasuredArrayHandle* out_buffer,
                                   size_t               buffer_size) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_full_gradient");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  auto           gradients      = measured_array->gradient();
  size_t         count          = gradients->size();
  size_t         to_copy        = (buffer_size < count) ? buffer_size : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new MeasuredArray(gradients->items()[i]);
  }
  return to_copy;
}

MeasuredArrayHandle MeasuredArray_gradient(MeasuredArrayHandle handle,
                                           size_t              axis) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to MeasuredArray_gradient");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return new MeasuredArray(measured_array->gradient(axis));
}

double MeasuredArray_get_sum_of_squares(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_sum_of_squares");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->get_sum_of_squares();
}

double MeasuredArray_get_summed_diff_int_of_squares(MeasuredArrayHandle handle,
                                                    const int           other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_summed_diff_int_of_squares");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->get_sum_of_squares(other);
}

double MeasuredArray_get_summed_diff_double_of_squares(
    MeasuredArrayHandle handle, const double other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to "
        "MeasuredArray_get_summed_diff_double_of_squares");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  return measured_array->get_sum_of_squares(other);
}

double MeasuredArray_get_summed_diff_array_of_squares(
    MeasuredArrayHandle handle, MeasuredArrayHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_get_summed_diff_array_of_squares");
  }
  MeasuredArray* measured_array = static_cast<MeasuredArray*>(handle);
  MeasuredArray* oarray         = static_cast<MeasuredArray*>(other);
  return measured_array->get_sum_of_squares(
      std::make_shared<MeasuredArray>(*oarray));
}

StringHandle MeasuredArray_to_json_string(MeasuredArrayHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to MeasuredArray_to_json_string");
  }
  std::string json = static_cast<MeasuredArray*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MeasuredArrayHandle MeasuredArray_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to MeasuredArray_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = MeasuredArray::from_json_string<MeasuredArray>(raw_json);
  return new MeasuredArray(*ptr);
}
