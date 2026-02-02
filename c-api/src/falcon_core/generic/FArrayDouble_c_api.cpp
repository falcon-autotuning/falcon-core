#include <falcon_core\generic/FArray.hpp>
#include "falcon_core\generic\FArrayDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROFArraydouble= falcon_core::generic::FArray<double>;
DEFINE_C_API_COPY_TEMPLATE(FArrayDouble, MACROFArraydouble)
DEFINE_C_API_DESTROY_TEMPLATE(FArrayDouble, MACROFArraydouble);
DEFINE_C_API_EQUAL_TEMPLATE(FArrayDouble, MACROFArraydouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(FArrayDouble, MACROFArraydouble);
DEFINE_C_API_TO_JSON_TEMPLATE(FArrayDouble, MACROFArraydouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(FArrayDouble, MACROFArraydouble);
FArrayDoubleHandle FArrayDouble_create_empty(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_create_empty");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<double>(falcon_core::generic::FArray<double>::empty(vec));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_create_zeros(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_create_zeros");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<double>(falcon_core::generic::FArray<double>::zeros(vec));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_from_shape(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_from_shape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<double>(std::make_shared<falcon_core::generic::FArray<double>>(vec));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_from_data(const double* data, const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data passed to FArrayDouble_from_data");
}
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_from_data");
}
  std::vector<std::vector<double>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<double> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
    return new falcon_core::generic::FArraySP<double>(std::make_shared<falcon_core::generic::FArray<double>>(arr));
    FALCON_C_API_END(nullptr)
}

size_t FArrayDouble_size(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_size");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->size();
    FALCON_C_API_END(0)
}

size_t FArrayDouble_dimension(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dimension");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->dimension();
    FALCON_C_API_END(0)
}

size_t FArrayDouble_shape(FArrayDoubleHandle handle, size_t* out_buffer, size_t ndim) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_shape");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_shape");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {
        out_buffer[i] = shape[i];
    }
    return to_copy;
    FALCON_C_API_END(0)
}

size_t FArrayDouble_data(FArrayDoubleHandle handle, double* out_buffer, size_t numdata) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_data");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_shape");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    if (farray->size() > numdata) {
    throw std::runtime_error(
        std::string("Trying to store more datapoints than buffer allocated.") +
        "The buffer has " + std::to_string(numdata) +
        " elements, but the FArray has " + std::to_string(farray->size()) +
        " elements.");
    }
    memcpy(out_buffer, farray->raw_data(), farray->size() * sizeof(double));
    return farray->size();
    FALCON_C_API_END(0)
}
 
void FArrayDouble_plus_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_equals_farray");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    *farray += *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_plus_equals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_equals_double");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

void FArrayDouble_plus_equals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_equals_int");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_farray");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(*farray + oarray);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_double");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray + other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray + other);
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_minus_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_equals_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    *farray -= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_minus_equals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_equals_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

void FArrayDouble_minus_equals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_equals_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(*farray - oarray);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray - other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray - other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_negation");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(-*farray);
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_times_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_equals_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    *farray *= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_times_equals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_equals_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

void FArrayDouble_times_equals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_equals_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(*farray * oarray);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray * other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray * other);
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_divides_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_equals_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    *farray /= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_divides_equals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_equals_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

void FArrayDouble_divides_equals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_equals_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_farray");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(*farray / oarray);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_double");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray / other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_int");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray / other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_double_pow(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_pow_inplace(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    farray->pow_inplace(other);
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_abs");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(farray->abs());
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_min(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->min();
    FALCON_C_API_END(0.0)
}

FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min_arraywise");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(farray->min(oarray));
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_max(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->max();
    FALCON_C_API_END(0.0)
}

FArrayDoubleHandle FArrayDouble_max_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max_arraywise");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return new falcon_core::generic::FArraySP<double>(farray->max(oarray));
    FALCON_C_API_END(nullptr)
}

bool FArrayDouble_greater_than(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_greater_than");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return *farray > value;
    FALCON_C_API_END(false)
}

bool FArrayDouble_less_than(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_less_than");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return *farray < value;
    FALCON_C_API_END(false)
}

void FArrayDouble_remove_offset(FArrayDoubleHandle handle,  double offset) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_remove_offset");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    farray->remove_offset(offset);
    FALCON_C_API_END()
}

double FArrayDouble_sum(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_sum");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->sum();
    FALCON_C_API_END(0.0)
}

FArrayDoubleHandle FArrayDouble_reshape(FArrayDoubleHandle handle, const size_t* shape, size_t ndims) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_reshape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(farray->reshape(vec));
    FALCON_C_API_END(nullptr)
}

ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_where");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(farray->where(value));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_flip");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(farray->flip(axis));
    FALCON_C_API_END(nullptr)
}

size_t FArrayDouble_full_gradient(FArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_full_gradient");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayDouble_full_gradient");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more double gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = new falcon_core::generic::FArraySP<double>(many_gradients->items()[i]);
    }
    return many_gradients->size();
    FALCON_C_API_END(0)
}

FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_gradient");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return new falcon_core::generic::FArraySP<double>(farray->gradient(axis));
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_sum_of_squares");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->get_sum_of_squares();
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_int_of_squares");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_double_of_squares");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_array_of_squares");
}
    falcon_core::generic::FArraySP<double> farray = *static_cast<falcon_core::generic::FArraySP<double>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<double>*>(other);
    return farray->get_sum_of_squares(oarray);
    FALCON_C_API_END(0.0)
}
}
