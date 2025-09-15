#include "falcon_core/math/spaces/UnitSpace.hpp"

#include <xtensor/containers/xadapt.hpp>

#include "falcon_core/Constants.hpp"
#include "falcon_core/math/discretizers/BaseDiscretizer.hpp"
#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/math/discretizers/PolarDiscretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core::math::spaces {
UnitSpace::UnitSpace() = default;
UnitSpace::UnitSpace(const AxesSP<discretizers::BaseDiscretizer>& axes,
                     const domains::DomainSP&                     domain)
    : math::Axes<discretizers::BaseDiscretizer>(*axes), _domain(domain) {
  make_discrete_axes();
}
const AxesSP<discretizers::BaseDiscretizer> UnitSpace::axes() const {
  return std::make_shared<Axes<discretizers::BaseDiscretizer>>(items());
}
const domains::DomainSP&         UnitSpace::domain() const { return _domain; }
const generic::FArraySP<double>& UnitSpace::space() const { return _space; }
const generic::ListSP<int>       UnitSpace::shape() const {
  generic::ListSP<int> shape;
  for (const arrays::ControlArray1DSP& array : *_ranges) {
    shape->push_back(array->size());
  }
  return shape;
}
const int UnitSpace::dimension() const { return this->size(); }
void      UnitSpace::make_discrete_axes() const {
  for (const discretizers::BaseDiscretizerSP& disc : items()) {
    double factor = 1.0;
    if (auto cart =
            std::dynamic_pointer_cast<discretizers::CartesianDiscretizer>(
                disc)) {
      factor = 1.0;
    } else if (auto polar =
                   std::dynamic_pointer_cast<discretizers::PolarDiscretizer>(
                       disc)) {
      factor = PI / 2.0;
    } else {
      throw std::runtime_error("Discretizer type not supported.");
    }

    domains::DomainSP domain = *(_domain->scale(factor)) & (disc->domain());
    std::pair<double, double> bounds = domain->bounds();
    double                    delta  = disc->delta();

    double lower_bound =
        domain->lesser_bound_contained() ? bounds.first : bounds.first + delta;
    double upper_bound = domain->greater_bound_contained()
                                  ? bounds.second + delta
                                  : bounds.second;

    // Assuming ControlArray1D takes a std::vector<double>
    std::vector<double> values;
    for (double v = lower_bound; v < upper_bound; v += delta) {
      values.push_back(v);
    }
    _ranges->push_back(std::make_shared<arrays::ControlArray1D>(values));
  }
}

std::vector<xt::xarray<double>> meshgrid_xt(
    const std::vector<xt::xarray<double>>& inputs) {
  size_t              ndim = inputs.size();
  std::vector<size_t> shape(ndim);
  for (size_t i = 0; i < ndim; ++i) shape[i] = inputs[i].shape()[0];

  std::vector<xt::xarray<double>> grids;
  for (size_t axis = 0; axis < ndim; ++axis) {
    // Prepare reshape shape: 1 for all dims except axis
    std::vector<size_t> reshape_shape(ndim, 1);
    reshape_shape[axis] = shape[axis];
    auto reshaped       = xt::reshape_view(inputs[axis], reshape_shape);
    auto broadcasted    = xt::broadcast(reshaped, shape);
    grids.push_back(broadcasted);
  }
  return grids;
}
const AxesSP<arrays::ControlArray> UnitSpace::create_array(
    const AxesSP<int>& axes) const {
  std::vector<xt::xarray<double>> grids;
  for (int i = 0; i < axes->size(); ++i) {
    grids.push_back(_ranges->at(axes->at(i))->xtensor());
  }
  std::vector<xt::xarray<double>> mesh = meshgrid_xt(grids);
  return std::make_shared<math::Axes<arrays::ControlArray>>(mesh);
}
void UnitSpace::compile() {
  // Collect xtensor arrays from _ranges, reversed
  std::vector<xt::xarray<double>> grids;
  for (int i = _ranges->size() - 1; i >= 0; --i) {
    grids.push_back(_ranges->at(i)->xtensor());
  }
  std::vector<xt::xarray<double>> mesh = meshgrid_xt(grids);

  // Flatten each broadcasted array and stack as rows
  std::vector<xt::xarray<double>> flat;
  for (const auto& arr : mesh) {
    flat.push_back(xt::flatten(arr));
  }

  // Manually stack as rows (N x M, N = number of ranges, M = number of points)
  size_t             N     = flat.size();
  size_t             M     = flat[0].size();
  xt::xarray<double> space = xt::zeros<double>({N, M});
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      space(i, j) = flat[i](j);
    }
  }

  // Reverse columns to match Python's [:, ::-1]
  auto reversed = xt::view(space, xt::all(), xt::range(M - 1, -1, -1));

  // Assign to _space (assuming BaseArray accepts xt::xarray<double>)
  _space = std::make_shared<generic::FArray<double>>(reversed);
}

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::UnitSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Axes<falcon_core::math::discretizers::BaseDiscretizer>,
    falcon_core::math::spaces::UnitSpace)
