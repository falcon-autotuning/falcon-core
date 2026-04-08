#include "falcon-core/math/domains/LabelledDomain_c_api.h"

#include <falcon-core/math/domains/LabelledDomain.hpp>

#include "falcon-core/Precompiled_c_api.h"
using namespace falcon_core::math::domains;

extern "C" {
DEFINE_C_API_COPY(LabelledDomain);
DEFINE_C_API_DESTROY(LabelledDomain);
DEFINE_C_API_EQUAL(LabelledDomain);
DEFINE_C_API_NOT_EQUAL(LabelledDomain);
DEFINE_C_API_TO_JSON(LabelledDomain);
DEFINE_C_API_FROM_JSON(LabelledDomain);
LabelledDomainHandle LabelledDomain_create_primitive_knob(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_knob: default_name cannot be null");
  }
  if (!psuedo_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_knob: psuedo_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_knob: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_knob: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_knob: description cannot be null");
  }
  return new LabelledDomainSP(std::make_shared<LabelledDomain>(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          psuedo_name),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(units),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::Knob));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_create_primitive_meter(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_meter: default_name cannot be null");
  }
  if (!psuedo_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_meter: psuedo_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_meter: instrument_type cannot be "
        "null");
  }
  if (!units) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_meter: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_meter: description cannot be null");
  }
  return new LabelledDomainSP(std::make_shared<LabelledDomain>(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          psuedo_name),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(units),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::Meter));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_create_primitive_port(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description) {
  FALCON_C_API_BEGIN
  if (!default_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_port: default_name cannot be null");
  }
  if (!psuedo_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_port: psuedo_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_port: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_port: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "LabelledDomain_create_primitive_port: description cannot be null");
  }
  return new LabelledDomainSP(std::make_shared<LabelledDomain>(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          psuedo_name),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(units),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::InstrumentPort));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_create_from_port(
    double               min_val,
    double               max_val,
    InstrumentPortHandle port,
    bool                 lesser_bound_contained,
    bool                 greater_bound_contained) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port: port cannot be null");
  }
  return new LabelledDomainSP(LabelledDomain::from_port(
      std::pair<double, double>(min_val, max_val),
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(port),
      lesser_bound_contained,
      greater_bound_contained));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_create_from_port_and_domain(
    InstrumentPortHandle port, DomainHandle domain) {
  FALCON_C_API_BEGIN
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port_and_domain: port cannot be null");
  }
  if (!domain) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port_and_domain: domain cannot be null");
  }
  return new LabelledDomainSP(LabelledDomain::from_port_and_domain(
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(port),
      *static_cast<DomainSP*>(domain)));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_create_from_domain(
    DomainHandle     domain,
    StringHandle     default_name,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    SymbolUnitHandle units,
    StringHandle     description) {
  FALCON_C_API_BEGIN
  if (!domain) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: domain cannot be null");
  }
  if (!default_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: default_name cannot be null");
  }
  if (!psuedo_name) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: psuedo_name cannot be null");
  }
  if (!instrument_type) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: instrument_type cannot be null");
  }
  if (!units) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: units cannot be null");
  }
  if (!description) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_domain: description cannot be null");
  }
  return new LabelledDomainSP(LabelledDomain::from_domain(
      *static_cast<DomainSP*>(domain),
      std::string(default_name->raw, default_name->length),
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          psuedo_name),
      std::string(instrument_type->raw, instrument_type->length),
      *static_cast<falcon_core::physics::units::SymbolUnitSP*>(units),
      std::string(description->raw, description->length)));
  FALCON_C_API_END(nullptr)
}

InstrumentPortHandle LabelledDomain_port(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_port: handle cannot be null");
  }
  falcon_core::instrument_interfaces::names::InstrumentPortSP port =
      (*static_cast<LabelledDomainSP*>(handle))->port();
  return new falcon_core::instrument_interfaces::names::InstrumentPortSP(port);
  FALCON_C_API_END(nullptr)
}

DomainHandle LabelledDomain_domain(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_domain: handle cannot be null");
  }
  auto domain = (*static_cast<LabelledDomainSP*>(handle))->domain();
  return new DomainSP(domain);
  FALCON_C_API_END(nullptr)
}

bool LabelledDomain_matching_port(LabelledDomainHandle handle,
                                  InstrumentPortHandle port) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_matching_port: handle cannot be null");
  }
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_matching_port: port cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_port =
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(port);
  return self->matching_port(real_port);
  FALCON_C_API_END(false)
}

double LabelledDomain_lesser_bound(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_lesser_bound: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->lesser_bound();
  FALCON_C_API_END(0.0)
}

double LabelledDomain_greater_bound(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_greater_bound: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->greater_bound();
  FALCON_C_API_END(0.0)
}

bool LabelledDomain_lesser_bound_contained(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_lesser_bound_contained: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->lesser_bound_contained();
  FALCON_C_API_END(false)
}

bool LabelledDomain_greater_bound_contained(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_greater_bound_contained: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->greater_bound_contained();
  FALCON_C_API_END(false)
}

bool LabelledDomain_in(LabelledDomainHandle handle, double value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_in: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->in(value);
  FALCON_C_API_END(false)
}

double LabelledDomain_range(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_range: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->range();
  FALCON_C_API_END(0.0)
}

double LabelledDomain_center(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_center: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->get_center();
  FALCON_C_API_END(0.0)
}

LabelledDomainHandle LabelledDomain_intersection(LabelledDomainHandle handle,
                                                 LabelledDomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_intersection: other cannot be null");
  }
  LabelledDomainSP lhs        = *static_cast<LabelledDomainSP*>(handle);
  LabelledDomainSP rhs        = *static_cast<LabelledDomainSP*>(other);
  DomainSP         result_ptr = *lhs & rhs;
  return new LabelledDomainSP(
      LabelledDomain::from_port_and_domain(lhs->port(), result_ptr));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_union(LabelledDomainHandle handle,
                                          LabelledDomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_union: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("LabelledDomain_union: other cannot be null");
  }
  LabelledDomainSP lhs        = *static_cast<LabelledDomainSP*>(handle);
  LabelledDomainSP rhs        = *static_cast<LabelledDomainSP*>(other);
  DomainSP         result_ptr = *lhs | rhs;
  return new LabelledDomainSP(
      LabelledDomain::from_port_and_domain(lhs->port(), result_ptr));
  FALCON_C_API_END(nullptr)
}

bool LabelledDomain_is_empty(LabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_is_empty: handle cannot be null");
  }
  LabelledDomainSP self = *static_cast<LabelledDomainSP*>(handle);
  return self->is_empty();
  FALCON_C_API_END(false)
}

bool LabelledDomain_contains_domain(LabelledDomainHandle handle,
                                    LabelledDomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_contains_domain: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_contains_domain: other cannot be null");
  }
  LabelledDomainSP self       = *static_cast<LabelledDomainSP*>(handle);
  LabelledDomainSP real_other = *static_cast<LabelledDomainSP*>(other);
  return self->contains_domain(real_other);
  FALCON_C_API_END(false)
}

LabelledDomainHandle LabelledDomain_shift(LabelledDomainHandle handle,
                                          double               offset) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_shift: handle cannot be null");
  }
  auto result_ptr = (*static_cast<LabelledDomainSP*>(handle))->shift(offset);
  return new LabelledDomainSP(LabelledDomain::from_port_and_domain(
      (*static_cast<LabelledDomainSP*>(handle))->port(), result_ptr));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle LabelledDomain_scale(LabelledDomainHandle handle,
                                          double               scale) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_scale: handle cannot be null");
  }
  auto result_ptr = (*static_cast<LabelledDomainSP*>(handle))->scale(scale);
  return new LabelledDomainSP(LabelledDomain::from_port_and_domain(
      (*static_cast<LabelledDomainSP*>(handle))->port(), result_ptr));
  FALCON_C_API_END(nullptr)
}

double LabelledDomain_transform(LabelledDomainHandle handle,
                                LabelledDomainHandle other,
                                double               value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_transform: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_transform: other cannot be null");
  }
  return (*static_cast<LabelledDomainSP*>(handle))
      ->transform(*static_cast<LabelledDomainSP*>(other), value);
  FALCON_C_API_END(0.0)
}
}
