#include "falcon_core/math/domains/Domain_c_api.h"

#include <falcon_core/math/domains/Domain.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::math::domains;

DomainHandle Domain_create(double min_val,
                           double max_val,
                           bool   lesser_bound_contained,
                           bool   greater_bound_contained) {
  return new Domain(Domain(
      min_val, max_val, lesser_bound_contained, greater_bound_contained));
}

void Domain_destroy(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_destroy: handle cannot be null");
  }
  delete static_cast<Domain*>(handle);
}

double Domain_lesser_bound(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_lesser_bound: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.lesser_bound();
}

double Domain_greater_bound(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_greater_bound: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.greater_bound();
}

bool Domain_lesser_bound_contained(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_lesser_bound_contained: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.lesser_bound_contained();
}

bool Domain_greater_bound_contained(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_greater_bound_contained: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.greater_bound_contained();
}

bool Domain_in(DomainHandle handle, double value) {
  if (!handle) {
    throw std::invalid_argument("Domain_in: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.in(value);
}

double Domain_range(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_range: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.range();
}

double Domain_center(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_center: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return self.get_center();
}

DomainHandle Domain_intersection(DomainHandle handle, DomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_intersection: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_intersection: second handle cannot be null");
  }
  Domain   self       = *static_cast<Domain*>(handle);
  DomainSP real_other = std::make_shared<Domain>(*static_cast<Domain*>(other));
  DomainSP result     = self & real_other;
  return new Domain(*result);
}

DomainHandle Domain_union(DomainHandle handle, DomainHandle other) {
  if (!handle) {
    throw std::invalid_argument("Domain_union: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Domain_union: second handle cannot be null");
  }
  Domain   self       = *static_cast<Domain*>(handle);
  DomainSP real_other = std::make_shared<Domain>(*static_cast<Domain*>(other));
  DomainSP result     = self | real_other;
  return new Domain(*result);
}

bool Domain_is_empty(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_is_empty: handle cannot be null");
  }
  Domain* self = static_cast<Domain*>(handle);
  return self->is_empty();
}

bool Domain_contains_domain(DomainHandle handle, DomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_contains_domain: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_contains_domain: second handle cannot be null");
  }
  Domain*  self       = static_cast<Domain*>(handle);
  DomainSP real_other = std::make_shared<Domain>(*static_cast<Domain*>(other));
  return self->contains_domain(real_other);
}

DomainHandle Domain_shift(DomainHandle handle, double offset) {
  if (!handle) {
    throw std::invalid_argument("Domain_shift: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return new Domain(*self.shift(offset));
}

DomainHandle Domain_scale(DomainHandle handle, double scale) {
  if (!handle) {
    throw std::invalid_argument("Domain_scale: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return new Domain(*self.scale(scale));
}

double Domain_transform(DomainHandle handle, DomainHandle other, double value) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_transform: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_transform: second handle cannot be null");
  }
  Domain   self       = *static_cast<Domain*>(handle);
  DomainSP real_other = std::make_shared<Domain>(*static_cast<Domain*>(other));
  return self.transform(real_other, value);
}

bool Domain_equal(DomainHandle handle, DomainHandle other) {
  if (!handle) {
    throw std::invalid_argument("Domain_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Domain_equal: second handle cannot be null");
  }
  return *(static_cast<Domain*>(handle)) == *(static_cast<Domain*>(other));
}

bool Domain_not_equal(DomainHandle handle, DomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Domain_not_equal: first handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Domain_not_equal: second handle cannot be null");
  }
  return *(static_cast<Domain*>(handle)) != *(static_cast<Domain*>(other));
}

StringHandle Domain_to_json_string(DomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("Domain_to_json_string: handle cannot be null");
  }
  Domain self = *static_cast<Domain*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

DomainHandle Domain_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument("Domain_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new Domain(*Domain::from_json_string<Domain>(json_str));
}
