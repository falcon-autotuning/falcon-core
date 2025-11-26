#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include <xtensor/xadapt.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
FArrayDoubleHandle FArrayDouble_create_empty(const size_t* shape, size_t ndim) {
    FALCON_C_API_BEGIN
if (!shape) {
throw std::invalid_argument("Null shape passed to FArrayDouble_create_empty");
}
    std::vector<size_t> vec;
    for (size_t i =0; i < ndim; ++i) {
        vec.push_back(shape[i]);
    }
    return new falcon_core::generic::FArray<double>(*falcon_core::generic::FArray<double>::empty(vec));
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
    return new falcon_core::generic::FArray<double>(*falcon_core::generic::FArray<double>::zeros(vec));
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
    return new falcon_core::generic::FArray<double>(vec);
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
  return new falcon_core::generic::FArray<double>(arr);
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_destroy(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_destroy");
}
    delete static_cast<falcon_core::generic::FArray<double>*>(handle);
    FALCON_C_API_END()
}

size_t FArrayDouble_size(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_size");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->size();
    FALCON_C_API_END(0)
}

size_t FArrayDouble_dimension(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dimension");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
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
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
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
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    if (farray->size() > numdata) {
    throw std::runtime_error(
        std::string("Trying to store more datapoints than buffer allocated.") +
        "The buffer has " + std::to_string(numdata) +
        " elements, but the FArray has " + std::to_string(farray->size()) +
        " elements.");
    }
    memcpy(out_buffer, farray->data(), farray->size() * sizeof(double));
    return farray->size();
    FALCON_C_API_END(0)
}
 
void FArrayDouble_plusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray += *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_plusequals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

void FArrayDouble_plusequals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray += other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray +
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_plus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray + other));
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_minusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray -= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_minusequals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

void FArrayDouble_minusequals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minusequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray -= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray -
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_minus_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray - other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_negation");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(-*farray));
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_timesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray *= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_timesequals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

void FArrayDouble_timesequals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_timesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray *= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray *
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_times_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray * other));
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_dividesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    *farray /= *oarray;
    FALCON_C_API_END()
}

void FArrayDouble_dividesequals_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

void FArrayDouble_dividesequals_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_dividesequals_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    *farray /= other;
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_farray");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
        *(*farray /
            std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_double");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_divides_int");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray / other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
     falcon_core::generic::FArray<double>* farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray ^ other));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_double_pow(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
     falcon_core::generic::FArray<double>* farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*(*farray ^ other));
    FALCON_C_API_END(nullptr)
}

void FArrayDouble_pow_inplace(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_pow");
}
    falcon_core::generic::FArray<double>* farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    farray->pow_inplace(other);
    FALCON_C_API_END()
}

FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_abs");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->abs());
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_min(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->min();
    FALCON_C_API_END(0.0)
}

FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_min_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
    *farray->min(std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_max(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->max();
    FALCON_C_API_END(0.0)
}

FArrayDoubleHandle FArrayDouble_max_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_max_arraywise");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return new falcon_core::generic::FArray<double>(
    *farray->max(std::make_shared<falcon_core::generic::FArray<double>>(*oarray)));
    FALCON_C_API_END(nullptr)
}

bool FArrayDouble_equality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_equality");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray == *oarray;
    FALCON_C_API_END(false)
}

bool FArrayDouble_notequality(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_notequality");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray= static_cast<falcon_core::generic::FArray<double>*>(other);
    return *farray != *oarray;
    FALCON_C_API_END(false)
}

bool FArrayDouble_greaterthan(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_greaterthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray > value;
    FALCON_C_API_END(false)
}

bool FArrayDouble_lessthan(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_lessthan");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return *farray < value;
    FALCON_C_API_END(false)
}

void FArrayDouble_remove_offset(FArrayDoubleHandle handle,  double offset) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_remove_offset");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    farray->remove_offset(offset);
    FALCON_C_API_END()
}

double FArrayDouble_sum(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_sum");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
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
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->reshape(vec));
    FALCON_C_API_END(nullptr)
}

ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_where");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::List<falcon_core::generic::List<size_t>>(*farray->where(value));
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_flip");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->flip(axis));
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
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto many_gradients = farray->gradient();
    if (many_gradients->size() > buffer_size) {
        throw std::runtime_error("Trying to store more double gradients than buffer allocated.");
    }
    for (size_t i = 0; i < many_gradients->size(); ++i) {
        out_buffer[i] = new falcon_core::generic::FArray<double>(*(many_gradients->items()[i]));
    }
    return many_gradients->size();
    FALCON_C_API_END(0)
}

FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_gradient");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return new falcon_core::generic::FArray<double>(*farray->gradient(axis));
    FALCON_C_API_END(nullptr)
}

double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_sum_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares();
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle,  int other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_int_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle,  double other) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_double_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    return farray->get_sum_of_squares(other);
    FALCON_C_API_END(0.0)
}

double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to FArrayDouble_get_summed_diff_array_of_squares");
}
    auto farray = static_cast<falcon_core::generic::FArray<double>*>(handle);
    auto oarray = static_cast<falcon_core::generic::FArray<double>*>(other);
    return farray->get_sum_of_squares(std::make_shared<falcon_core::generic::FArray<double>>(*oarray));
    FALCON_C_API_END(0.0)
}

StringHandle      FArrayDouble_to_json_string(FArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to FArrayDouble_to_json_string");
}
  std::string json = static_cast<falcon_core::generic::FArray<double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

FArrayDoubleHandle FArrayDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to FArrayDouble_from_json_string");
}
  auto ptr = falcon_core::generic::FArray<double>::from_json_string<falcon_core::generic::FArray<double>>(json->raw);
  return new falcon_core::generic::FArray<double>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
