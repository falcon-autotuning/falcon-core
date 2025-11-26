#include "falcon_core/math/arrays/ControlArray_c_api.h"

#include <falcon_core/math/arrays/ControlArray.hpp>
#include <stdexcept>
#include <string>
#include <xtensor/xadapt.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core;
using namespace falcon_core::math;
using namespace falcon_core::math::arrays;

extern "C" {
ControlArrayHandle ControlArray_from_data(const double* data,
                                          const size_t* shape,
                                          size_t        ndim) {
  FALCON_C_API_BEGIN
  if (!data) {
    throw std::invalid_argument("Null data passed to ControlArray_from_data");
  }
  if (!shape) {
    throw std::invalid_argument("Null shape passed to ControlArray_from_data");
  }
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new ControlArray(arr);
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_from_farray(FArrayDoubleHandle farray) {
  FALCON_C_API_BEGIN
  if (!farray) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_from_farray");
  }
  generic::FArray<double>* real_farray =
      static_cast<generic::FArray<double>*>(farray);
  return new ControlArray(
      ControlArray(std::make_shared<generic::FArray<double>>(*real_farray)));
  FALCON_C_API_END(nullptr)
}

void ControlArray_destroy(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_destroy");
  }
  delete static_cast<ControlArray*>(handle);
  FALCON_C_API_END()
}

size_t ControlArray_size(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_size");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->size();
  FALCON_C_API_END(0)
}

size_t ControlArray_dimension(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_dimension");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->dimension();
  FALCON_C_API_END(0)
}

size_t ControlArray_shape(ControlArrayHandle handle,
                          size_t*            out_buffer,
                          size_t             ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_shape");
  }
  auto   control_array = static_cast<ControlArray*>(handle);
  auto   shape         = control_array->shape();
  size_t count         = shape.size();
  size_t to_copy       = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t ControlArray_data(ControlArrayHandle handle,
                         double*            out_buffer,
                         size_t             numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_data");
  }
  auto   control_array = static_cast<ControlArray*>(handle);
  auto   data          = control_array->data();
  size_t count         = control_array->size();
  size_t to_copy       = (numdata < count) ? numdata : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = data[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

void ControlArray_plus_equals_farray(ControlArrayHandle handle,
                                    FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_equals_farray");
  }
  ControlArray*            control_array = static_cast<ControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  control_array->operator+=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void ControlArray_plus_equals_double(ControlArrayHandle handle,
                                    const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_equals_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator+=(other);
  FALCON_C_API_END()
}

void ControlArray_plus_equals_int(ControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_equals_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator+=(other);
  FALCON_C_API_END()
}

ControlArrayHandle ControlArray_plus_control_array(ControlArrayHandle handle,
                                                   ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_control_array");
  }
  ControlArray*  control_array = static_cast<ControlArray*>(handle);
  ControlArraySP oarray =
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(other));
  return new ControlArray(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_plus_farray(ControlArrayHandle handle,
                                            FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_farray");
  }
  ControlArray*             control_array = static_cast<ControlArray*>(handle);
  generic::FArraySP<double> oarray = std::make_shared<generic::FArray<double>>(
      *static_cast<generic::FArray<double>*>(other));
  return new ControlArray(control_array->operator+(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_plus_double(ControlArrayHandle handle,
                                            const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_plus_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_plus_int(ControlArrayHandle handle,
                                         const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_plus_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator+(other));
  FALCON_C_API_END(nullptr)
}

void ControlArray_minus_equals_farray(ControlArrayHandle handle,
                                     FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_equals_farray");
  }
  ControlArray*            control_array = static_cast<ControlArray*>(handle);
  generic::FArray<double>* oarray =
      static_cast<generic::FArray<double>*>(other);
  control_array->operator-=(generic::FArray<double>(*oarray));
  FALCON_C_API_END()
}

void ControlArray_minus_equals_double(ControlArrayHandle handle,
                                     const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_equals_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator-=(other);
  FALCON_C_API_END()
}

void ControlArray_minus_equals_int(ControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_equals_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator-=(other);
  FALCON_C_API_END()
}

ControlArrayHandle ControlArray_minus_control_array(ControlArrayHandle handle,
                                                    ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_control_array");
  }
  ControlArray*  control_array = static_cast<ControlArray*>(handle);
  ControlArraySP oarray =
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(other));
  return new ControlArray(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_minus_farray(ControlArrayHandle handle,
                                             FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_farray");
  }
  ControlArray*             control_array = static_cast<ControlArray*>(handle);
  generic::FArraySP<double> oarray = std::make_shared<generic::FArray<double>>(
      *static_cast<generic::FArray<double>*>(other));
  return new ControlArray(control_array->operator-(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_minus_double(ControlArrayHandle handle,
                                             const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_minus_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_minus_int(ControlArrayHandle handle,
                                          const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_minus_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator-(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_negation(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_negation");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator-());
  FALCON_C_API_END(nullptr)
}

void ControlArray_times_equals_double(ControlArrayHandle handle,
                                     const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_times_equals_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator*=(other);
  FALCON_C_API_END()
}

void ControlArray_times_equals_int(ControlArrayHandle handle, const int other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_times_equals_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator*=(other);
  FALCON_C_API_END()
}

ControlArrayHandle ControlArray_times_double(ControlArrayHandle handle,
                                             const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_times_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_times_int(ControlArrayHandle handle,
                                          const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_times_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator*(other));
  FALCON_C_API_END(nullptr)
}

void ControlArray_divides_equals_double(ControlArrayHandle handle,
                                       const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_divides_equals_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator/=(other);
  FALCON_C_API_END()
}

void ControlArray_divides_equals_int(ControlArrayHandle handle,
                                    const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_divides_equals_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  control_array->operator/=(other);
  FALCON_C_API_END()
}

ControlArrayHandle ControlArray_divides_double(ControlArrayHandle handle,
                                               const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_divides_double");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_divides_int(ControlArrayHandle handle,
                                            const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_divides_int");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator/(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_pow(ControlArrayHandle handle,
                                    const double       other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_pow");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->operator^(other));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_abs(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_abs");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->abs());
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_min_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_min_farray");
  }
  ControlArray*             control_array = static_cast<ControlArray*>(handle);
  generic::FArraySP<double> oarray = std::make_shared<generic::FArray<double>>(
      *static_cast<generic::FArray<double>*>(other));
  return new ControlArray(control_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_min_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_min_control_array");
  }
  ControlArray*  control_array = static_cast<ControlArray*>(handle);
  ControlArraySP oarray =
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(other));
  return new ControlArray(control_array->min(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_max_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_max_farray");
  }
  ControlArray*             control_array = static_cast<ControlArray*>(handle);
  generic::FArraySP<double> oarray = std::make_shared<generic::FArray<double>>(
      *static_cast<generic::FArray<double>*>(other));
  return new ControlArray(control_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_max_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_max_control_array");
  }
  ControlArray*  control_array = static_cast<ControlArray*>(handle);
  ControlArraySP oarray =
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(other));
  return new ControlArray(control_array->max(oarray));
  FALCON_C_API_END(nullptr)
}

bool ControlArray_Equal(ControlArrayHandle handle,
                           ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument("Null handle passed to ControlArray_Equal");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  auto oarray        = static_cast<ControlArray*>(other);
  return *control_array == *oarray;
  FALCON_C_API_END(false)
}

bool ControlArray_NotEqual(ControlArrayHandle handle,
                              ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_NotEqual");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  auto oarray        = static_cast<ControlArray*>(other);
  return *control_array != *oarray;
  FALCON_C_API_END(false)
}

bool ControlArray_greaterthan(ControlArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_greaterthan");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->operator>(value);
  FALCON_C_API_END(false)
}

bool ControlArray_lessthan(ControlArrayHandle handle, const double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_lessthan");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->operator<(value);
  FALCON_C_API_END(false)
}

void ControlArray_remove_offset(ControlArrayHandle handle,
                                const double       offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_remove_offset");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  control_array->remove_offset(offset);
  FALCON_C_API_END()
}

double ControlArray_sum(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_sum");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->sum();
  FALCON_C_API_END(0.0)
}

ListListSizeTHandle ControlArray_where(ControlArrayHandle handle,
                                       const double       value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_where");
  }
  ControlArray* control_array = static_cast<ControlArray*>(handle);
  generic::ListSP<generic::List<size_t>> indices_sp =
      control_array->where(value);
  return new generic::List<generic::List<size_t>>(*indices_sp);
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_flip(ControlArrayHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_flip");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return new ControlArray(control_array->flip(axis));
  FALCON_C_API_END(nullptr)
}

size_t ControlArray_full_gradient(ControlArrayHandle  handle,
                                  FArrayDoubleHandle* out_buffer,
                                  size_t              buffer_size) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_full_gradient");
  }
  if (!out_buffer) {
    throw std::invalid_argument(
        "Null output buffer passed to ControlArray_full_gradient");
  }
  auto   control_array  = static_cast<ControlArray*>(handle);
  auto   many_gradients = control_array->gradient();
  size_t to_copy        = (buffer_size < many_gradients->size())
                              ? buffer_size
                              : many_gradients->size();
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = new generic::FArray<double>(*many_gradients->items()[i]);
  }
  return to_copy;
  FALCON_C_API_END(0)
}

FArrayDoubleHandle ControlArray_gradient(ControlArrayHandle handle,
                                         size_t             axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to ControlArray_gradient");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return new generic::FArray<double>(*control_array->gradient(axis));
  FALCON_C_API_END(nullptr)
}

double ControlArray_get_sum_of_squares(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_get_sum_of_squares");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->get_sum_of_squares();
  FALCON_C_API_END(0.0)
}

double ControlArray_get_summed_diff_int_of_squares(ControlArrayHandle handle,
                                                   const int          other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_get_summed_diff_int_of_squares");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double ControlArray_get_summed_diff_double_of_squares(ControlArrayHandle handle,
                                                      const double other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_get_summed_diff_double_of_squares");
  }
  auto control_array = static_cast<ControlArray*>(handle);
  return control_array->get_sum_of_squares(other);
  FALCON_C_API_END(0.0)
}

double ControlArray_get_summed_diff_array_of_squares(ControlArrayHandle handle,
                                                     ControlArrayHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_get_summed_diff_array_of_squares");
  }
  ControlArray*  control_array = static_cast<ControlArray*>(handle);
  ControlArraySP oarray =
      std::make_shared<ControlArray>(*static_cast<ControlArray*>(other));
  return control_array->get_sum_of_squares(oarray);
  FALCON_C_API_END(0.0)
}

StringHandle ControlArray_to_json_string(ControlArrayHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to ControlArray_to_json_string");
  }
  std::string json = static_cast<ControlArray*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ControlArrayHandle ControlArray_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to ControlArray_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr = ControlArray::from_json_string<ControlArray>(raw_json);
  return new ControlArray(*ptr);
  FALCON_C_API_END(nullptr)
}
}
