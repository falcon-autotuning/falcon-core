#pragma once

#include "falcon_core/Jsonable.hpp"
#include "falcon_core/BaseArray.hpp"
#include <memory>

namespace falcon_core {

template<typename ArrayType, typename LabelType>
class BaseLabelledArray : public Jsonable {
public:
    BaseLabelledArray(std::shared_ptr<ArrayType> array, std::shared_ptr<LabelType> label)
        : _array(std::move(array)), _label(std::move(label)) {}

    const std::shared_ptr<ArrayType>& array() const { return _array; }
    const std::shared_ptr<LabelType>& label() const { return _label; }

    nlohmann::json to_json() const override {
        nlohmann::json j;
        add_metadata(j, "falcon_core.math.labelled_arrays.base_labelled_array", "BaseLabelledArray");
        if (_array) {
            j["_array"] = _array->to_json();
        }
        if (_label) {
            j["_label"] = _label->to_json();
        }
        return j;
    }

    size_t hash() const override {
        size_t h1 = _array ? _array->hash() : 0;
        size_t h2 = _label ? _label->hash() : 0;
        return h1 ^ (h2 << 1);
    }

protected:
    std::shared_ptr<ArrayType> _array;
    std::shared_ptr<LabelType> _label;
};

} // namespace falcon_core
