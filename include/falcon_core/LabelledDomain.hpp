#pragma once

#include "falcon_core/Domain.hpp"
#include <memory>

namespace falcon_core {

template<typename T>
class LabelledDomain : public Domain {
public:
    LabelledDomain(double min_val, double max_val, std::shared_ptr<T> label)
        : Domain(min_val, max_val), _label(std::move(label)) {}

    const std::shared_ptr<T>& label() const { return _label; }

    nlohmann::json to_json() const override {
        nlohmann::json j = Domain::to_json();
        add_metadata(j, "falcon_core.math.domains.labelled_domain", "LabelledDomain");
        if (_label) {
            j["_label"] = _label->to_json();
        }
        return j;
    }

    size_t hash() const override {
        size_t h1 = Domain::hash();
        size_t h2 = _label ? _label->hash() : 0;
        return h1 ^ (h2 << 1);
    }

private:
    std::shared_ptr<T> _label;
};

} // namespace falcon_core
