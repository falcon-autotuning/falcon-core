#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"

#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>
#include <memory>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
using namespace falcon_core::math::domains;

CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty() {
  return new CoupledLabelledDomain(CoupledLabelledDomain());
}

CoupledLabelledDomainHandle CoupledLabelledDomain_create(
    const ListLabelledDomainHandle items) {
  if (!items) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_create: items cannot be null");
  }
  falcon_core::generic::ListSP<LabelledDomain> list =
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          *static_cast<falcon_core::generic::List<LabelledDomain>*>(items));
  return new CoupledLabelledDomain(list->items());
}

void CoupledLabelledDomain_destroy(CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_destroy: handle cannot be null");
  }
  delete static_cast<CoupledLabelledDomain*>(handle);
}

ListLabelledDomainHandle CoupledLabelledDomain_domains(
    CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_domains: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  auto list = std::make_shared<falcon_core::generic::List<LabelledDomain>>(
      self.domains());
  return new falcon_core::generic::List<LabelledDomain>(list->items());
}

PortsHandle CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_labels: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  falcon_core::generic::ListSP<
      falcon_core::instrument_interfaces::names::InstrumentPort>
      list = (self.labels());
  return new falcon_core::generic::List<
      falcon_core::instrument_interfaces::names::InstrumentPort>(list->items());
}

LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_get_domain: handle cannot be null");
  }
  if (!search) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_get_domain: search cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_search =
      std::make_shared<
          falcon_core::instrument_interfaces::names::InstrumentPort>(
          *static_cast<
              falcon_core::instrument_interfaces::names::InstrumentPort*>(
              search));
  LabelledDomainSP result = self.get_domain(real_search);
  return result.get();
}

CoupledLabelledDomainHandle CoupledLabelledDomain_intersection(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_intersection: other cannot be null");
  }
  CoupledLabelledDomain   self = *static_cast<CoupledLabelledDomain*>(handle);
  CoupledLabelledDomainSP real_other = std::make_shared<CoupledLabelledDomain>(
      *static_cast<CoupledLabelledDomain*>(other));
  return new CoupledLabelledDomain(self.intersection(real_other)->items());
}

void CoupledLabelledDomain_push_back(CoupledLabelledDomainHandle handle,
                                     LabelledDomainHandle        value) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_push_back: value cannot be null");
  }
  CoupledLabelledDomain* self = static_cast<CoupledLabelledDomain*>(handle);
  falcon_core::generic::ListSP<LabelledDomain> real_value =
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          *static_cast<falcon_core::generic::List<LabelledDomain>*>(value));
  self->push_back(real_value->at(0));
}

size_t CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_size: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  return self.size();
}

bool CoupledLabelledDomain_empty(CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_empty: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  return self.empty();
}

void CoupledLabelledDomain_erase_at(CoupledLabelledDomainHandle handle,
                                    size_t                      idx) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_erase_at: handle cannot be null");
  }
  CoupledLabelledDomain* self = static_cast<CoupledLabelledDomain*>(handle);
  self->erase_at(idx);
}

void CoupledLabelledDomain_clear(CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_clear: handle cannot be null");
  }
  CoupledLabelledDomain* self = static_cast<CoupledLabelledDomain*>(handle);
  self->clear();
}

LabelledDomainHandle CoupledLabelledDomain_const_at(
    CoupledLabelledDomainHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_const_at: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  return self.at(idx).get();
}

LabelledDomainHandle CoupledLabelledDomain_at(
    CoupledLabelledDomainHandle handle, size_t idx) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_at: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  return self.at(idx).get();
}

ListLabelledDomainHandle CoupledLabelledDomain_items(
    CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_items: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  auto list = std::make_shared<falcon_core::generic::List<LabelledDomain>>(
      self.items());
  return new falcon_core::generic::List<LabelledDomain>(list->items());
}

bool CoupledLabelledDomain_contains(CoupledLabelledDomainHandle handle,
                                    LabelledDomainHandle        value) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_contains: value cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  falcon_core::generic::ListSP<LabelledDomain> real_value =
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          *static_cast<falcon_core::generic::List<LabelledDomain>*>(value));
  return self.contains(real_value->at(0));
}

size_t CoupledLabelledDomain_index(CoupledLabelledDomainHandle handle,
                                   LabelledDomainHandle        value) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_index: value cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  falcon_core::generic::ListSP<LabelledDomain> real_value =
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          *static_cast<falcon_core::generic::List<LabelledDomain>*>(value));
  return self.index(real_value->at(0));
}

bool CoupledLabelledDomain_equal(CoupledLabelledDomainHandle a,
                                 CoupledLabelledDomainHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_equal: handle b cannot be null");
  }
  return *(static_cast<CoupledLabelledDomain*>(a)) ==
         *(static_cast<CoupledLabelledDomain*>(b));
}

bool CoupledLabelledDomain_not_equal(CoupledLabelledDomainHandle a,
                                     CoupledLabelledDomainHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_not_equal: handle b cannot be null");
  }
  return *(static_cast<CoupledLabelledDomain*>(a)) !=
         *(static_cast<CoupledLabelledDomain*>(b));
}

StringHandle CoupledLabelledDomain_to_json_string(
    CoupledLabelledDomainHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_to_json_string: handle cannot be null");
  }
  CoupledLabelledDomain self = *static_cast<CoupledLabelledDomain*>(handle);
  std::string           json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

CoupledLabelledDomainHandle CoupledLabelledDomain_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_from_json_string: json cannot be null");
  }
  std::string json_str = json->raw;
  return new CoupledLabelledDomain(
      *CoupledLabelledDomain::from_json_string<CoupledLabelledDomain>(
          json_str));
}
