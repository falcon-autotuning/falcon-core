#include "falcon_core/math/UnitSpace.hpp"

#include <stdexcept>

#include "falcon_core/Constants.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core::math {
UnitSpace::UnitSpace() = default;
UnitSpace::UnitSpace(const AxesSP<discrete_spaces::Discretizer>& axes,
                     const domains::DomainSP&                    domain)
    : math::Axes<discrete_spaces::Discretizer>(
          axes ? *axes : math::Axes<discrete_spaces::Discretizer>()),
      _domain(domain),
      _ranges(std::make_shared<Axes<arrays::ControlArray1D>>()) {
  if (!axes || !domain) {
    throw std::invalid_argument(
        "UnitSpace: The axes and domain must not be null.");
  }
  make_discrete_axes();
}
UnitSpaceSP UnitSpace::RaySpace(const double&            dr,
                                const double&            dtheta,
                                const domains::DomainSP& domain) {
  if (!domain) {
    throw std::invalid_argument("UnitSpace: The domain must not be null.");
  }
  AxesSP<discrete_spaces::Discretizer> axes =
      std::make_shared<Axes<discrete_spaces::Discretizer>>();
  axes->push_back(discrete_spaces::Discretizer::CartesianDiscretizer(dr));
  axes->push_back(discrete_spaces::Discretizer::PolarDiscretizer(dtheta));
  return std::make_shared<UnitSpace>(axes, domain);
}
UnitSpaceSP UnitSpace::CartesianSpace(const AxesSP<double>&    deltas,
                                      const domains::DomainSP& domain) {
  if (!deltas || !domain) {
    throw std::invalid_argument(
        "UnitSpace: The deltas and domain must not be null.");
  }
  AxesSP<discrete_spaces::Discretizer> axes =
      std::make_shared<Axes<discrete_spaces::Discretizer>>();
  for (double delta : *deltas) {
    axes->push_back(discrete_spaces::Discretizer::CartesianDiscretizer(delta));
  }
  return std::make_shared<UnitSpace>(axes, domain);
}
UnitSpaceSP UnitSpace::Cartesian2DSpace(const AxesSP<double>&    deltas,
                                        const domains::DomainSP& domain) {
  if (!deltas || !domain) {
    throw std::invalid_argument(
        "UnitSpace: The deltas and domain must not be null.");
  }
  if (!(deltas->size() == 2)) {
    throw std::runtime_error(
        "Expected for a 2D space that there would only be two dimensions "
        "specified");
  }
  return UnitSpace::CartesianSpace(deltas, domain);
}
UnitSpaceSP UnitSpace::Cartesian1DSpace(const double&            delta,
                                        const domains::DomainSP& domain) {
  if (!domain) {
    throw std::invalid_argument("UnitSpace: The domain must not be null.");
  }
  AxesSP<discrete_spaces::Discretizer> axes =
      std::make_shared<Axes<discrete_spaces::Discretizer>>();
  axes->push_back(discrete_spaces::Discretizer::CartesianDiscretizer(delta));
  return std::make_shared<UnitSpace>(axes, domain);
}
const AxesSP<discrete_spaces::Discretizer> UnitSpace::axes() const {
  return std::make_shared<Axes<discrete_spaces::Discretizer>>(items());
}
const domains::DomainSP&         UnitSpace::domain() const { return _domain; }
const generic::FArraySP<double>& UnitSpace::space() const { return _space; }
const generic::ListSP<int>       UnitSpace::shape() const {
  generic::ListSP<int> shape = std::make_shared<List<int>>();
  for (const arrays::ControlArray1DSP& array : *_ranges) {
    shape->push_back(array->size());
  }
  return shape;
}
const int UnitSpace::dimension() const { return this->size(); }
void      UnitSpace::make_discrete_axes() const {
  for (const discrete_spaces::DiscretizerSP& disc : items()) {
    double factor = 1.0;
    if (disc->is_cartesian()) {
      factor = 1.0;
    } else if (disc->is_polar()) {
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

    auto arr = xt::arange<double>(lower_bound, upper_bound, delta);
    _ranges->push_back(std::make_shared<arrays::ControlArray1D>(arr));
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
  if (!axes) {
    throw std::invalid_argument("UnitSpace: The axes must not be null.");
  }
  std::vector<xt::xarray<double>> grids;
  for (int i = 0; i < axes->size(); ++i) {
    grids.push_back(_ranges->at(axes->at(i))->xtensor());
  }
  std::vector<xt::xarray<double>>                    mesh = meshgrid_xt(grids);
  std::vector<std::shared_ptr<arrays::ControlArray>> mesh_ptrs;
  for (auto& arr : mesh) {
    mesh_ptrs.push_back(std::make_shared<arrays::ControlArray>(arr));
  }
  return std::make_shared<math::Axes<arrays::ControlArray>>(mesh_ptrs);
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
bool UnitSpace::operator==(const UnitSpace& other) const {
  return (*domain() == *other.domain()) && (*_ranges == *other._ranges);
}
bool UnitSpace::operator!=(const UnitSpace& other) const {
  return !(*this == other);
}

}  // namespace falcon_core::math

CEREAL_REGISTER_TYPE(falcon_core::math::UnitSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>,
    falcon_core::math::UnitSpace)
