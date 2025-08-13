#pragma once

#include "falcon_core/math/domains/LabelledDomain.hpp"

#include <vector>

namespace falcon_core
{

template <typename T> class CoupledLabelledDomain : public LabelledDomain<T>
{
public:
  CoupledLabelledDomain (
      double                                          min_val,
      double                                          max_val,
      std::shared_ptr<T>                              label,
      std::vector<std::shared_ptr<LabelledDomain<T>>> coupled_domains)
      : LabelledDomain<T> (min_val, max_val, label),
        _coupled_domains (std::move (coupled_domains))
  {
  }

  const std::vector<std::shared_ptr<LabelledDomain<T>>> &
  coupled_domains () const
  {
    return _coupled_domains;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = LabelledDomain<T>::to_json ();
    this->add_metadata (j,
                        "falcon_core.math.domains.coupled_labelled_domain",
                        "CoupledLabelledDomain");
    nlohmann::json coupled_json = nlohmann::json::array ();
    for (const auto &cd : _coupled_domains)
      {
        coupled_json.push_back (cd->to_json ());
      }
    j["_coupled_domains"] = coupled_json;
    return j;
  }

  size_t
  hash () const override
  {
    size_t h1   = LabelledDomain<T>::hash ();
    size_t seed = _coupled_domains.size ();
    for (const auto &cd : _coupled_domains)
      {
        seed ^= cd->hash () + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
    return h1 ^ (seed << 1);
  }

private:
  std::vector<std::shared_ptr<LabelledDomain<T>>> _coupled_domains;
};

} // namespace falcon_core
