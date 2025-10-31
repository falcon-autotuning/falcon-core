#include "falcon_core/physics/config/core/Adjacency_c_api.h"

#include <falcon_core/physics/config/core/Adjacency.hpp>
#include <string>

#include "falcon_core/generic/FArray.hpp"
#include "falcon_core/generic/Pair.hpp"
#include "falcon_core/generic/String_c_api.h"
#include "xtensor/xadapt.hpp"
using namespace falcon_core::physics::config::core;

AdjacencyHandle Adjacency_create(const int*        data,
                                 const size_t*     shape,
                                 size_t            ndim,
                                 ConnectionsHandle indexes) {
  if (!indexes) {
    throw std::invalid_argument("Adjacency_create: indexes cannot be null");
  }
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
  if (!handle) {
    throw std::invalid_argument("Adjacency_destroy: handle cannot be null");
  }
  delete static_cast<Adjacency*>(handle);
}

ConnectionsHandle Adjacency_indexes(AdjacencyHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_indexes: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.indexes()));
}
ListPairSizeTSizeTHandle Adjacency_get_true_pairs(AdjacencyHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_get_true_pairs: handle cannot be null");
  }
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
  if (!handle) {
    throw std::invalid_argument("Adjacency_size: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.size();
}

size_t Adjacency_dimension(AdjacencyHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_dimension: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.dimension();
}

size_t Adjacency_shape(AdjacencyHandle handle,
                       size_t*         out_buffer,
                       size_t          ndim) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_shape: handle cannot be null");
  }
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
  if (!handle) {
    throw std::invalid_argument("Adjacency_data: handle cannot be null");
  }
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
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_timesequals_farray: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Adjacency_timesequals_farray: other cannot be null");
  }
  Adjacency                         self = *static_cast<Adjacency*>(handle);
  falcon_core::generic::FArray<int> oarray =
      *static_cast<falcon_core::generic::FArray<int>*>(other);
  self *= oarray;
}

AdjacencyHandle Adjacency_times_farray(AdjacencyHandle handle,
                                       FArrayIntHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_times_farray: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Adjacency_times_farray: other cannot be null");
  }
  Adjacency                         self = *static_cast<Adjacency*>(handle);
  falcon_core::generic::FArray<int> oarray =
      *static_cast<falcon_core::generic::FArray<int>*>(other);
  return new Adjacency(
      *(self * std::make_shared<falcon_core::generic::FArray<int>>(oarray)),
      self.indexes());
}

bool Adjacency_equality(AdjacencyHandle handle, AdjacencyHandle other) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_equality: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Adjacency_equality: other cannot be null");
  }
  Adjacency self  = *static_cast<Adjacency*>(handle);
  Adjacency oself = *static_cast<Adjacency*>(other);
  return self == oself;
}

bool Adjacency_notequality(AdjacencyHandle handle, AdjacencyHandle other) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_notequality: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Adjacency_notequality: other cannot be null");
  }
  Adjacency self  = *static_cast<Adjacency*>(handle);
  Adjacency oself = *static_cast<Adjacency*>(other);
  return self != oself;
}

int Adjacency_sum(AdjacencyHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_sum: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  return self.sum();
}

ListListSizeTHandle Adjacency_where(AdjacencyHandle handle, const int value) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_where: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  auto      where_list =
      new falcon_core::generic::List<falcon_core::generic::List<size_t>>(
          *self.where(value));
  return where_list;
}

AdjacencyHandle Adjacency_flip(AdjacencyHandle handle, size_t axis) {
  if (!handle) {
    throw std::invalid_argument("Adjacency_flip: handle cannot be null");
  }
  Adjacency self = *static_cast<Adjacency*>(handle);
  return new Adjacency(*self.flip(axis), self.indexes());
}

StringHandle Adjacency_to_json_string(AdjacencyHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Adjacency_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<Adjacency*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

AdjacencyHandle Adjacency_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Adjacency_from_json_string: json cannot be null");
  }
  auto ptr = Adjacency::from_json_string<Adjacency>(json->raw);
  return new Adjacency(*ptr);
}
