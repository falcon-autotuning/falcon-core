#include "falcon_core/math/domains/LabelledDomain_c_api.h"

#include <falcon_core/math/domains/LabelledDomain.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
using namespace falcon_core::math::domains;

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
  return new LabelledDomain(LabelledDomain(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      std::shared_ptr<falcon_core::physics::device_structures::Connection>(
          static_cast<falcon_core::physics::device_structures::Connection*>(
              psuedo_name),
          [](falcon_core::physics::device_structures::Connection*) {}),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      std::shared_ptr<falcon_core::physics::units::SymbolUnit>(
          static_cast<falcon_core::physics::units::SymbolUnit*>(units),
          [](falcon_core::physics::units::SymbolUnit*) {}),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::Knob));
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
  return new LabelledDomain(LabelledDomain(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      std::shared_ptr<falcon_core::physics::device_structures::Connection>(
          static_cast<falcon_core::physics::device_structures::Connection*>(
              psuedo_name),
          [](falcon_core::physics::device_structures::Connection*) {}),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      std::shared_ptr<falcon_core::physics::units::SymbolUnit>(
          static_cast<falcon_core::physics::units::SymbolUnit*>(units),
          [](falcon_core::physics::units::SymbolUnit*) {}),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::Meter));
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
  return new LabelledDomain(LabelledDomain(
      std::string(default_name->raw, default_name->length),
      std::pair<double, double>(min_val, max_val),
      std::shared_ptr<falcon_core::physics::device_structures::Connection>(
          static_cast<falcon_core::physics::device_structures::Connection*>(
              psuedo_name),
          [](falcon_core::physics::device_structures::Connection*) {}),
      std::string(instrument_type->raw, instrument_type->length),
      lesser_bound_contained,
      greater_bound_contained,
      std::shared_ptr<falcon_core::physics::units::SymbolUnit>(
          static_cast<falcon_core::physics::units::SymbolUnit*>(units),
          [](falcon_core::physics::units::SymbolUnit*) {}),
      std::string(description->raw, description->length),
      falcon_core::instrument_interfaces::names::PortType::InstrumentPort));
}

LabelledDomainHandle LabelledDomain_create_from_port(
    double               min_val,
    double               max_val,
    StringHandle         instrument_type,
    InstrumentPortHandle port,
    bool                 lesser_bound_contained,
    bool                 greater_bound_contained) {
  if (!instrument_type) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port: instrument_type cannot be null");
  }
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port: port cannot be null");
  }
  return new LabelledDomain(*LabelledDomain::from_port(
      std::pair<double, double>(min_val, max_val),
      std::shared_ptr<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(port),
          [](falcon_core::instrument_interfaces::names::InstrumentPort*) {}),
      lesser_bound_contained,
      greater_bound_contained));
}

LabelledDomainHandle LabelledDomain_create_from_port_and_domain(
    InstrumentPortHandle port, DomainHandle domain) {
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port_and_domain: port cannot be null");
  }
  if (!domain) {
    throw std::invalid_argument(
        "LabelledDomain_create_from_port_and_domain: domain cannot be null");
  }
  return new LabelledDomain(*LabelledDomain::from_port_and_domain(
      std::shared_ptr<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(port),
          [](falcon_core::instrument_interfaces::names::InstrumentPort*) {}),
      std::shared_ptr<Domain>(static_cast<Domain*>(domain), [](Domain*) {})));
}

LabelledDomainHandle LabelledDomain_create_from_domain(
    DomainHandle     domain,
    StringHandle     default_name,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    SymbolUnitHandle units,
    StringHandle     description) {
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
  return new LabelledDomain(*LabelledDomain::from_domain(
      std::shared_ptr<Domain>(static_cast<Domain*>(domain), [](Domain*) {}),
      std::string(default_name->raw, default_name->length),
      std::shared_ptr<falcon_core::physics::device_structures::Connection>(
          static_cast<falcon_core::physics::device_structures::Connection*>(
              psuedo_name),
          [](falcon_core::physics::device_structures::Connection*) {}),
      std::string(instrument_type->raw, instrument_type->length),
      std::shared_ptr<falcon_core::physics::units::SymbolUnit>(
          static_cast<falcon_core::physics::units::SymbolUnit*>(units),
          [](falcon_core::physics::units::SymbolUnit*) {}),
      std::string(description->raw, description->length)));
}

void LabelledDomain_destroy(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_destroy: handle cannot be null");
  }
  delete static_cast<LabelledDomain*>(handle);
}

InstrumentPortHandle LabelledDomain_port(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_port: handle cannot be null");
  }
  const auto port = static_cast<LabelledDomain*>(handle)->port();
  return static_cast<InstrumentPortHandle>(port.get());
}

DomainHandle LabelledDomain_domain(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_domain: handle cannot be null");
  }
  const auto domain = static_cast<LabelledDomain*>(handle)->domain();
  return static_cast<DomainHandle>(domain.get());
}

bool LabelledDomain_matching_port(LabelledDomainHandle handle,
                                  InstrumentPortHandle port) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_matching_port: handle cannot be null");
  }
  if (!port) {
    throw std::invalid_argument(
        "LabelledDomain_matching_port: port cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_port =
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              port));
  return self.matching_port(real_port);
}

double LabelledDomain_lesser_bound(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_lesser_bound: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.lesser_bound();
}

double LabelledDomain_greater_bound(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_greater_bound: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.greater_bound();
}

bool LabelledDomain_lesser_bound_contained(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_lesser_bound_contained: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.lesser_bound_contained();
}

bool LabelledDomain_greater_bound_contained(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_greater_bound_contained: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.greater_bound_contained();
}

bool LabelledDomain_in(LabelledDomainHandle handle, double value) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_in: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.in(value);
}

double LabelledDomain_range(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_range: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.range();
}

double LabelledDomain_center(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_center: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.get_center();
}

LabelledDomainHandle LabelledDomain_intersection(LabelledDomainHandle handle,
                                                 LabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_intersection: other cannot be null");
  }
  auto lhs = static_cast<LabelledDomain*>(handle);
  auto rhs = static_cast<LabelledDomain*>(other);
  auto result_ptr =
      *lhs & std::shared_ptr<LabelledDomain>(rhs, [](LabelledDomain*) {});
  return result_ptr.get();
}

LabelledDomainHandle LabelledDomain_union(LabelledDomainHandle handle,
                                          LabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_union: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("LabelledDomain_union: other cannot be null");
  }
  auto lhs = static_cast<LabelledDomain*>(handle);
  auto rhs = static_cast<LabelledDomain*>(other);
  auto result_ptr =
      *lhs | std::shared_ptr<LabelledDomain>(rhs, [](LabelledDomain*) {});
  return result_ptr.get();
}

bool LabelledDomain_is_empty(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_is_empty: handle cannot be null");
  }
  LabelledDomain self = *static_cast<LabelledDomain*>(handle);
  return self.is_empty();
}

bool LabelledDomain_contains_domain(LabelledDomainHandle handle,
                                    LabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_contains_domain: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_contains_domain: other cannot be null");
  }
  LabelledDomain   self = *static_cast<LabelledDomain*>(handle);
  LabelledDomainSP real_other =
      std::make_shared<LabelledDomain>(*static_cast<LabelledDomain*>(other));
  return self.contains_domain(real_other);
}

LabelledDomainHandle LabelledDomain_shift(LabelledDomainHandle handle,
                                          double               offset) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_shift: handle cannot be null");
  }
  auto result_ptr = static_cast<LabelledDomain*>(handle)->shift(offset);
  return result_ptr.get();
}

LabelledDomainHandle LabelledDomain_scale(LabelledDomainHandle handle,
                                          double               scale) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_scale: handle cannot be null");
  }
  auto result_ptr = static_cast<LabelledDomain*>(handle)->scale(scale);
  return result_ptr.get();
}

double LabelledDomain_transform(LabelledDomainHandle handle,
                                LabelledDomainHandle other,
                                double               value) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_transform: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_transform: other cannot be null");
  }
  return static_cast<LabelledDomain*>(handle)->transform(
      std::shared_ptr<LabelledDomain>(static_cast<LabelledDomain*>(other),
                                      [](LabelledDomain*) {}),
      value);
}

bool LabelledDomain_equal(LabelledDomainHandle handle,
                          LabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument("LabelledDomain_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("LabelledDomain_equal: other cannot be null");
  }
  return *(static_cast<LabelledDomain*>(handle)) ==
         *(static_cast<LabelledDomain*>(other));
}

bool LabelledDomain_not_equal(LabelledDomainHandle handle,
                              LabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "LabelledDomain_not_equal: other cannot be null");
  }
  return *(static_cast<LabelledDomain*>(handle)) !=
         *(static_cast<LabelledDomain*>(other));
}

StringHandle LabelledDomain_to_json_string(LabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "LabelledDomain_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<LabelledDomain*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
LabelledDomainHandle LabelledDomain_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "LabelledDomain_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new LabelledDomain(
      *LabelledDomain::from_json_string<LabelledDomain>(json_str));
}
