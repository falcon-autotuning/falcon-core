#include "falcon-core/math/UnitSpace.hpp"

#include <stdexcept>

#include "falcon-core/Constants.hpp"
#include "falcon-core/math/arrays/ControlArray1D.hpp"
#include "falcon-core/math/domains/Domain.hpp"

namespace falcon_core {
namespace generic {
template class List<math::discrete_spaces::Discretizer>;
}
namespace math {
template class Axes<discrete_spaces::Discretizer>;
UnitSpace::UnitSpace(const UnitSpace& other)
    : math::Axes<discrete_spaces::Discretizer>(other) {
  std::unique_lock<std::shared_timed_mutex> lock_domain(_mu_domain,
                                                        std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                        std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_ranges(other._mu_ranges,
                                                              std::defer_lock);
  std::lock(lock_domain, lock_ranges, lock_other_ranges);
  if (!other.domain() || !other._ranges) {
    throw std::invalid_argument(
        "UnitSpace copy constructor: Other UnitSpace contains null shared "
        "pointers.");
  }
  _domain = std::make_shared<domains::Domain>(*other.domain());
  _ranges =
      std::make_shared<math::Axes<arrays::ControlArray1D>>(*other._ranges);
}
UnitSpace& UnitSpace::operator=(const UnitSpace& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_domain(_mu_domain,
                                                          std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                          std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_ranges(
        other._mu_ranges, std::defer_lock);
    std::lock(lock_domain, lock_ranges, lock_other_ranges);
    if (!other.domain() || !other._ranges) {
      throw std::invalid_argument(
          "UnitSpace copy constructor: Other UnitSpace contains null shared "
          "pointers.");
    }
    _domain = std::make_shared<domains::Domain>(*other.domain());
    _ranges =
        std::make_shared<math::Axes<arrays::ControlArray1D>>(*other._ranges);
  }
  return *this;
}
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
const domains::DomainSP& UnitSpace::domain() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_domain);
  return _domain;
}
const generic::FArraySP<double>& UnitSpace::space() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_space);
  return _space;
}
const generic::ListSP<int> UnitSpace::shape() const {
  generic::ListSP<int>               shape  = std::make_shared<List<int>>();
  math::Axes<arrays::ControlArray1D> ranges = *this->_ranges;
  for (const arrays::ControlArray1DSP& array : ranges) {
    int size = array->size();
    shape->push_back(size);
  }
  return shape;
}
const int UnitSpace::dimension() const { return this->size(); }
void      UnitSpace::make_discrete_axes() {
  std::unique_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges);
  for (const discrete_spaces::DiscretizerSP& disc : items()) {
    double factor = 1.0;
    if (disc->is_cartesian()) {
      factor = 1.0;
    } else if (disc->is_polar()) {
      factor = PI / 2.0;
    } else {
      throw std::runtime_error("Discretizer type not supported.");
    }

    domains::DomainSP domain =
        *(this->domain()->scale(factor)) & (disc->domain());
    std::pair<double, double> bounds = domain->bounds();
    double                    delta  = disc->delta();

    double lower_bound =
        domain->lesser_bound_contained() ? bounds.first : bounds.first + delta;
    double upper_bound = domain->greater_bound_contained()
                                  ? bounds.second + delta
                                  : bounds.second;

    auto arr = xt::arange<double>(lower_bound, upper_bound, delta);
    arrays::ControlArray1DSP new_range =
        std::make_shared<arrays::ControlArray1D>(arr);
    _ranges->push_back(new_range);
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
    grids.push_back(_ranges->at(axes->at(i))->data());
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
  std::shared_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges);
  std::vector<xt::xarray<double>>           grids;
  int                                       range_num = _ranges->size();
  for (int i = range_num - 1; i >= 0; --i) {
    grids.push_back(_ranges->at(i)->data());
  }
  std::vector<xt::xarray<double>> mesh = meshgrid_xt(grids);

  // Flatten each broadcasted array and stack as rows
  std::vector<xt::xarray<double>> flat = std::vector<xt::xarray<double>>();
  for (const auto& arr : mesh) {
    xt::xarray<double> flat_array = xt::flatten(arr);
    flat.push_back(flat_array);
  }

  // Manually stack as rows (N x M, N = number of ranges, M = number of points)
  size_t             N     = flat.size();
  size_t             M     = flat[0].size();
  xt::xarray<double> space = xt::zeros<double>({M, N});
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < M; ++j) {
      space(j, i) = flat[i](j);
    }
  }

  // Reverse columns to match Python's [:, ::-1]
  auto                                      reversed = xt::flip(space, 0);
  std::unique_lock<std::shared_timed_mutex> lock_space(_mu_space);
  _space = std::make_shared<generic::FArray<double>>(reversed);
}
bool UnitSpace::operator==(const UnitSpace& other) const {
  if (this == &other) return true;
  std::shared_lock<std::shared_timed_mutex> lock_ranges(_mu_ranges,
                                                        std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_other_ranges(other._mu_ranges,
                                                              std::defer_lock);
  std::lock(lock_ranges, lock_other_ranges);
  return (*domain() == *other.domain()) && (*_ranges == *other._ranges);
}
bool UnitSpace::operator!=(const UnitSpace& other) const {
  return !(*this == other);
}

}  // namespace math
}  // namespace falcon_core
