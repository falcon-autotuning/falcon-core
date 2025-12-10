#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"

#include <falcon_core/math/domains/CoupledLabelledDomain.hpp>

#include "falcon_core/Precompiled_c_api.h"
using namespace falcon_core::math::domains;

extern "C" {
DEFINE_C_API_COPY(CoupledLabelledDomain);
DEFINE_C_API_DESTROY(CoupledLabelledDomain);
DEFINE_C_API_EQUAL(CoupledLabelledDomain);
DEFINE_C_API_NOT_EQUAL(CoupledLabelledDomain);
DEFINE_C_API_TO_JSON(CoupledLabelledDomain);
DEFINE_C_API_FROM_JSON(CoupledLabelledDomain);
CoupledLabelledDomainHandle CoupledLabelledDomain_create_empty() {
  FALCON_C_API_BEGIN
  return new CoupledLabelledDomainSP(std::make_shared<CoupledLabelledDomain>());
  FALCON_C_API_END(nullptr)
}

CoupledLabelledDomainHandle CoupledLabelledDomain_create(
    const ListLabelledDomainHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_create: items cannot be null");
  }
  falcon_core::generic::ListSP<LabelledDomain> list =
      *static_cast<falcon_core::generic::ListSP<LabelledDomain>*>(items);
  return new CoupledLabelledDomainSP(
      std::make_shared<CoupledLabelledDomain>(list->items()));
  FALCON_C_API_END(nullptr)
}

ListLabelledDomainHandle CoupledLabelledDomain_domains(
    CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_domains: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  auto list = std::make_shared<falcon_core::generic::List<LabelledDomain>>(
      self->domains());
  return new falcon_core::generic::ListSP<LabelledDomain>(
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          list->items()));
  FALCON_C_API_END(nullptr)
}

PortsHandle CoupledLabelledDomain_labels(CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_labels: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  falcon_core::generic::ListSP<
      falcon_core::instrument_interfaces::names::InstrumentPort>
      list = (self->labels());
  return new falcon_core::generic::ListSP<
      falcon_core::instrument_interfaces::names::InstrumentPort>(
      std::make_shared<falcon_core::generic::List<
          falcon_core::instrument_interfaces::names::InstrumentPort>>(
          list->items()));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle CoupledLabelledDomain_get_domain(
    CoupledLabelledDomainHandle handle, InstrumentPortHandle search) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_get_domain: handle cannot be null");
  }
  if (!search) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_get_domain: search cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  falcon_core::instrument_interfaces::names::InstrumentPortSP real_search =
      *static_cast<
          falcon_core::instrument_interfaces::names::InstrumentPortSP*>(search);
  LabelledDomainSP result = self->get_domain(real_search);
  return new LabelledDomainSP(result);
  FALCON_C_API_END(nullptr)
}

CoupledLabelledDomainHandle CoupledLabelledDomain_intersection(
    CoupledLabelledDomainHandle handle, CoupledLabelledDomainHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_intersection: other cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  CoupledLabelledDomainSP real_other =
      *static_cast<CoupledLabelledDomainSP*>(other);
  return new CoupledLabelledDomainSP(std::make_shared<CoupledLabelledDomain>(
      self->intersection(real_other)->items()));
  FALCON_C_API_END(nullptr)
}

void CoupledLabelledDomain_push_back(CoupledLabelledDomainHandle handle,
                                     LabelledDomainHandle        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_push_back: value cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  LabelledDomainSP        real_value = *static_cast<LabelledDomainSP*>(value);
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t CoupledLabelledDomain_size(CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_size: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  return self->size();
  FALCON_C_API_END(0)
}

bool CoupledLabelledDomain_empty(CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_empty: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  return self->empty();
  FALCON_C_API_END(false)
}

void CoupledLabelledDomain_erase_at(CoupledLabelledDomainHandle handle,
                                    size_t                      idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_erase_at: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void CoupledLabelledDomain_clear(CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_clear: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  self->clear();
  FALCON_C_API_END()
}

LabelledDomainHandle CoupledLabelledDomain_const_at(
    CoupledLabelledDomainHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_const_at: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  return new LabelledDomainSP(self->at(idx));
  FALCON_C_API_END(nullptr)
}

LabelledDomainHandle CoupledLabelledDomain_at(
    CoupledLabelledDomainHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_at: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  return new LabelledDomainSP(self->at(idx));
  FALCON_C_API_END(nullptr)
}

ListLabelledDomainHandle CoupledLabelledDomain_items(
    CoupledLabelledDomainHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_items: handle cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  auto list = std::make_shared<falcon_core::generic::List<LabelledDomain>>(
      self->items());
  return new falcon_core::generic::ListSP<LabelledDomain>(
      std::make_shared<falcon_core::generic::List<LabelledDomain>>(
          list->items()));
  FALCON_C_API_END(nullptr)
}

bool CoupledLabelledDomain_contains(CoupledLabelledDomainHandle handle,
                                    LabelledDomainHandle        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_contains: value cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  LabelledDomainSP        real_value = *static_cast<LabelledDomainSP*>(value);
  return self->contains(real_value);
  FALCON_C_API_END(false)
}

size_t CoupledLabelledDomain_index(CoupledLabelledDomainHandle handle,
                                   LabelledDomainHandle        value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "CoupledLabelledDomain_index: value cannot be null");
  }
  CoupledLabelledDomainSP self = *static_cast<CoupledLabelledDomainSP*>(handle);
  LabelledDomainSP        real_value = *static_cast<LabelledDomainSP*>(value);
  return self->index(real_value);
  FALCON_C_API_END(0)
}
}
