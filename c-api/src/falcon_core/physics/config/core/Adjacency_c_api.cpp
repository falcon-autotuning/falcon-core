#include "falcon_core/physics/config/core/Adjacency_c_api.h"

#include <falcon_core/physics/config/core/Adjacency.hpp>

#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/generic/Pair.hpp"
#include "xtensor/xadapt.hpp"
using namespace falcon_core::physics::config::core;

extern "C" {
DEFINE_C_API_COPY(Adjacency);
DEFINE_C_API_DESTROY(Adjacency);
DEFINE_C_API_EQUAL(Adjacency);
DEFINE_C_API_NOT_EQUAL(Adjacency);
DEFINE_C_API_TO_JSON(Adjacency);
DEFINE_C_API_FROM_JSON(Adjacency);
AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 size_t            ndim,
                                 ConnectionsHandle indexes) {
  FALCON_C_API_BEGIN
  if (!indexes) {
    throw std::invalid_argument("Adjacency_create: indexes cannot be null");
  }
  if (!data) {
    throw std::invalid_argument("Adjacency_create: data cannot be null");
  }
  if (!shape) {
    throw std::invalid_argument("Adjacency_create: shape cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionsSP real_indexes =
      *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(
          indexes);
  std::vector<std::vector<int>::size_type> shapeVec;
  size_t                                   total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<int> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new AdjacencySP(std::make_shared<Adjacency>(arr, real_indexes));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_indexes: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      (self->indexes()));
  FALCON_C_API_END(nullptr)
}
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_get_true_pairs: handle cannot be null");
  }
  AdjacencySP self  = *static_cast<AdjacencySP*>(handle);
  auto        pairs = self->get_true_pairs();
  auto        list_of_pairs =
      falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>(
          std::make_shared<falcon_core::generic::List<
              falcon_core::generic::Pair<size_t, size_t>>>());
  for (const auto& pair : pairs) {
    list_of_pairs->push_back(falcon_core::generic::PairSP<size_t, size_t>(
        std::make_shared<falcon_core::generic::Pair<size_t, size_t>>(
            pair.first, pair.second)));
  }
  return new falcon_core::generic::ListSP<
      falcon_core::generic::Pair<size_t, size_t>>(list_of_pairs);
  FALCON_C_API_END(nullptr)
}

size_t Adjacency_size(AdjacencyHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_size: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

size_t Adjacency_dimension(AdjacencyHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_dimension: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return self->dimension();
  FALCON_C_API_END(0)
}

size_t Adjacency_shape(AdjacencyHandle handle,
                       size_t*         out_buffer,
                       size_t          ndim) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_shape: handle cannot be null");
  }
  AdjacencySP self    = *static_cast<AdjacencySP*>(handle);
  auto        shape   = self->shape();
  size_t      count   = shape.size();
  size_t      to_copy = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
  FALCON_C_API_END(0)
}

size_t Adjacency_data(AdjacencyHandle handle, int* out_buffer, size_t numdata) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_data: handle cannot be null");
  }
  if (!out_buffer) {
    throw std::invalid_argument("Adjacency_data: out_buffer cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  if (numdata < self->size()) {
    throw std::runtime_error(
        "Trying to store more datapoints than buffer allocated.");
  }
  memcpy(out_buffer, self->raw_data(), self->size() * sizeof(int));
  return self->size();
  FALCON_C_API_END(0)
}

void Adjacency_times_equals_farray(AdjacencyHandle handle,
                                   FArrayIntHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_times_equals_farray: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Adjacency_times_equals_farray: other cannot be null");
  }
  AdjacencySP                         self = *static_cast<AdjacencySP*>(handle);
  falcon_core::generic::FArraySP<int> oarray =
      *static_cast<falcon_core::generic::FArraySP<int>*>(other);
  (*self) *= *oarray;
  FALCON_C_API_END()
}

AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_times_farray: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Adjacency_times_farray: other cannot be null");
  }
  AdjacencySP                         self = *static_cast<AdjacencySP*>(handle);
  falcon_core::generic::FArraySP<int> oarray =
      *static_cast<falcon_core::generic::FArraySP<int>*>(other);
  return new AdjacencySP(
      std::make_shared<Adjacency>(*(*(self)*oarray), self->indexes()));
  FALCON_C_API_END(nullptr)
}

int Adjacency_sum(AdjacencyHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_sum: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return self->sum();
  FALCON_C_API_END(0)
}

ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, int value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_where: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(
      self->where(value));
  FALCON_C_API_END(nullptr)
}

AdjacencyHandle Adjacency_flip(AdjacencyHandle handle, size_t axis) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Adjacency_flip: handle cannot be null");
  }
  AdjacencySP self = *static_cast<AdjacencySP*>(handle);
  return new AdjacencySP(
      std::make_shared<Adjacency>(*self->flip(axis), self->indexes()));
  FALCON_C_API_END(nullptr)
}
}
