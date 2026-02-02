#include <falcon_core\generic/FArray.hpp>
#include "falcon_core\generic\FArrayInt_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROFArrayint= falcon_core::generic::FArray<int>;
DEFINE_C_API_COPY_TEMPLATE(FArrayInt, MACROFArrayint)
DEFINE_C_API_DESTROY_TEMPLATE(FArrayInt, MACROFArrayint);
DEFINE_C_API_EQUAL_TEMPLATE(FArrayInt, MACROFArrayint);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(FArrayInt, MACROFArrayint);
DEFINE_C_API_TO_JSON_TEMPLATE(FArrayInt, MACROFArrayint);
DEFINE_C_API_FROM_JSON_TEMPLATE(FArrayInt, MACROFArrayint);
FArrayIntHandle FArrayInt_create_empty(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_create_empty");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<int>(falcon_core::generic::FArray<int>::empty(vec));
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_create_zeros(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_create_zeros");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<int>(falcon_core::generic::FArray<int>::zeros(vec));
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_from_shape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArraySP<int>(std::make_shared<falcon_core::generic::FArray<int>>(vec));
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data passed to FArrayInt_from_data");
}
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayInt_from_data");
}
  std::vector<std::vector<int>::size_type> shapeVec;
  size_t                                      total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<int> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
    return new falcon_core::generic::FArraySP<int>(std::make_shared<falcon_core::generic::FArray<int>>(arr));
    FALCON_C_API_END(nullptr)
}

size_t FArrayInt_size(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_size");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->size();
    FALCON_C_API_END(0)
}

size_t FArrayInt_dimension(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_dimension");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->dimension();
    FALCON_C_API_END(0)
}

size_t FArrayInt_shape(FArrayIntHandle handle, size_t* out_buffer, size_t ndim) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_shape");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_shape");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto shape = farray->shape();
    size_t count   = shape.size();
    size_t to_copy = (ndim < count) ? ndim : count;
    for (size_t i = 0; i < to_copy; ++i) {
        out_buffer[i] = shape[i];
    }
    return to_copy;
    FALCON_C_API_END(0)
}

size_t FArrayInt_data(FArrayIntHandle handle, int* out_buffer, size_t numdata) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_data");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_shape");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    if (farray->size() > numdata) {
    throw std::runtime_error(
        std::string("Trying to store more datapoints than buffer allocated.") +
        "The buffer has " + std::to_string(numdata) +
        " elements, but the FArray has " + std::to_string(farray->size()) +
        " elements.");
    }
    memcpy(out_buffer, farray->raw_data(), farray->size() * sizeof(int));
    return farray->size();
    FALCON_C_API_END(0)
}
 
void FArrayInt_plus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_equals_farray");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    *farray += *oarray;
    FALCON_C_API_END()
}

void FArrayInt_plus_equals_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_equals_double");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

void FArrayInt_plus_equals_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_equals_int");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_farray");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(*farray + oarray);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_double");
}
    auto farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray + other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_plus_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray + other);
    FALCON_C_API_END(nullptr)
}

void FArrayInt_minus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_equals_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    *farray -= *oarray;
    FALCON_C_API_END()
}

void FArrayInt_minus_equals_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_equals_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

void FArrayInt_minus_equals_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_equals_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(*farray - oarray);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray - other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_minus_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray - other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_negation");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(-*farray);
    FALCON_C_API_END(nullptr)
}

void FArrayInt_times_equals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_equals_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    *farray *= *oarray;
    FALCON_C_API_END()
}

void FArrayInt_times_equals_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_equals_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

void FArrayInt_times_equals_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_equals_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(*farray * oarray);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray * other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_times_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray * other);
    FALCON_C_API_END(nullptr)
}

void FArrayInt_divides_equals_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_equals_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    *farray /= *oarray;
    FALCON_C_API_END()
}

void FArrayInt_divides_equals_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_equals_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

void FArrayInt_divides_equals_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_equals_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_farray");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(*farray / oarray);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_double");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray / other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_divides_int");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray / other);
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_pow");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayInt_double_pow(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_pow");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<double>(*farray ^ other);
    FALCON_C_API_END(nullptr)
}

void FArrayInt_pow_inplace(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_pow");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    farray->pow_inplace(other);
    FALCON_C_API_END()
}

FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_abs");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(farray->abs());
    FALCON_C_API_END(nullptr)
}

int FArrayInt_min(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_min");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->min();
    FALCON_C_API_END(0)
}

FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_min_arraywise");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(farray->min(oarray));
    FALCON_C_API_END(nullptr)
}

int FArrayInt_max(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_max");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->max();
    FALCON_C_API_END(0)
}

FArrayIntHandle FArrayInt_max_arraywise(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_max_arraywise");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray= *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return new falcon_core::generic::FArraySP<int>(farray->max(oarray));
    FALCON_C_API_END(nullptr)
}

bool FArrayInt_greater_than(FArrayIntHandle handle,  int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_greater_than");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return *farray > value;
    FALCON_C_API_END(false)
}

bool FArrayInt_less_than(FArrayIntHandle handle,  int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_less_than");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return *farray < value;
    FALCON_C_API_END(false)
}

void FArrayInt_remove_offset(FArrayIntHandle handle,  int offset) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_remove_offset");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    farray->remove_offset(offset);
    FALCON_C_API_END()
}

int FArrayInt_sum(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_sum");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->sum();
    FALCON_C_API_END(0)
}

FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_reshape");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndims; ++i) {
        vec.push_back(shape[i]);
    }
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(farray->reshape(vec));
    FALCON_C_API_END(nullptr)
}

ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle,  int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_where");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(farray->where(value));
    FALCON_C_API_END(nullptr)
}

FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_flip");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(farray->flip(axis));
    FALCON_C_API_END(nullptr)
}

size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_full_gradient");
}
if (!out_buffer) {
throw std::invalid_argument("Null out_buffer passed to FArrayInt_full_gradient");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more int gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = new falcon_core::generic::FArraySP<int>(many_gradients->items()[i]);
    }
    return many_gradients->size();
    FALCON_C_API_END(0)
}

FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_gradient");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return new falcon_core::generic::FArraySP<int>(farray->gradient(axis));
    FALCON_C_API_END(nullptr)
}

double FArrayInt_get_sum_of_squares(FArrayIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_sum_of_squares");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->get_sum_of_squares();
    FALCON_C_API_END(0.0)
}

double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_int_of_squares");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_double_of_squares");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayInt_get_summed_diff_array_of_squares");
}
    falcon_core::generic::FArraySP<int> farray = *static_cast<falcon_core::generic::FArraySP<int>*>(handle);
    auto oarray = *static_cast<falcon_core::generic::FArraySP<int>*>(other);
    return farray->get_sum_of_squares(oarray);
    FALCON_C_API_END(0.0)
}
}
