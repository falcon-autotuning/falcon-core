#include "falcon_core/physics/config/core/Adjacency_c_api.h"

#include <falcon_core/physics/config/core/Adjacency.hpp>
#include <string>

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/generic/String_c_api.h"
#include "xtensor/xadapt.hpp"
using namespace falcon_core::physics::config::core;

extern "C" {

AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 size_t            ndim,
                                 ConnectionsHandle indexes) {
  falcon_core::physics::device_structures::ConnectionsSP real_indexes =
      std::make_shared<falcon_core::physics::device_structures::Connections>(
          *static_cast<falcon_core::physics::device_structures::Connections*>(
              indexes));
  std::vector<std::vector<int>::size_type> shapeVec;
  size_t                                   total_size = 1;
  for (size_t i = 0; i < ndim; ++i) {
    shapeVec.push_back(shape[i]);
    total_size *= shape[i];
  }
  xt::xarray<int> arr =
      xt::adapt(data, total_size, xt::no_ownership(), shapeVec);
  return new Adjacency(arr, real_indexes);
}

void Adjacency_destroy(AdjacencyHandle handle) {
  delete static_cast<Adjacency*>(handle);
}

ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.indexes()));
}
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle) {
  Adjacency self          = *static_cast<Adjacency*>(handle);
  auto      pairs         = self.get_true_pairs();
  auto      list_of_pairs = new falcon_core::generic::List<
           falcon_core::generic::Pair<size_t, size_t>>();
  for (const auto& pair : pairs) {
    list_of_pairs->push_back(
        std::make_shared<falcon_core::generic::Pair<size_t, size_t>>(
            falcon_core::generic::Pair<size_t, size_t>(pair.first,
                                                       pair.second)));
  }
  return list_of_pairs;
}

size_t Adjacency_size(AdjacencyHandle handle) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.size();
}

size_t Adjacency_dimension(AdjacencyHandle handle) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.dimension();
}

size_t Adjacency_shape(AdjacencyHandle handle,
                       size_t*         out_buffer,
                       size_t          ndim) {
  Adjacency self    = *static_cast<Adjacency*>(handle);
  auto      shape   = self.shape();
  size_t    count   = shape.size();
  size_t    to_copy = (ndim < count) ? ndim : count;
  for (size_t i = 0; i < to_copy; ++i) {
    out_buffer[i] = shape[i];
  }
  return to_copy;
}

size_t Adjacency_data(AdjacencyHandle handle, int* out_buffer, size_t numdata) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  if (self.size() > numdata) {
    throw std::runtime_error(
        "Trying to store more datapoints than buffer allocated.");
  }
  out_buffer = self.xtensor().data();
  return self.size();
}

void Adjacency_timesequals_farray(AdjacencyHandle handle,
                                  FArrayIntHandle other) {
  Adjacency                         self = *static_cast<Adjacency*>(handle);
  falcon_core::generic::FArray<int> oarray =
      *static_cast<falcon_core::generic::FArray<int>*>(other);
  self *= oarray;
}

AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other) {
  Adjacency                         self = *static_cast<Adjacency*>(handle);
  falcon_core::generic::FArray<int> oarray =
      *static_cast<falcon_core::generic::FArray<int>*>(other);
  return new Adjacency(
      *(self * std::make_shared<falcon_core::generic::FArray<int>>(oarray)),
      self.indexes());
}

bool Adjacency_equality(AdjacencyHandle handle, AdjacencyHandle other) {
  Adjacency self  = *static_cast<Adjacency*>(handle);
  Adjacency oself = *static_cast<Adjacency*>(other);
  return self == oself;
}

bool Adjacency_notequality(AdjacencyHandle handle, AdjacencyHandle other) {
  Adjacency self  = *static_cast<Adjacency*>(handle);
  Adjacency oself = *static_cast<Adjacency*>(other);
  return self != oself;
}

int Adjacency_sum(AdjacencyHandle handle) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.sum();
}

ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, const int value) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  auto      where_list =
      new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
          *self.where(value));
  return where_list;
}

AdjacencyHandle Adjacency_flip(AdjacencyHandle handle, size_t axis) {
  Adjacency self = *static_cast<Adjacency*>(handle);
  return new Adjacency(*self.flip(axis), self.indexes());
}

StringHandle Adjacency_to_json_string(AdjacencyHandle handle) {
  std::string json = static_cast<Adjacency*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

AdjacencyHandle Adjacency_from_json_string(StringHandle json) {
  auto ptr = Adjacency::from_json_string<Adjacency>(json->raw);
  return new Adjacency(*ptr);
}

#ifdef __cplusplus
}
#endif
