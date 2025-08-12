#pragma once

#include "falcon_core/BaseLabelledArray.hpp"
#include "falcon_core/ControlArray.hpp"
#include "falcon_core/IsLabelled1D.hpp"
#include "falcon_core/InstrumentPort.hpp"

namespace falcon_core {

using ControlArray1D = ControlArray<double>; // Assuming 1D is handled by Eigen::VectorXd or similar
using LabelType = InstrumentPort<Gate>;

class LabelledControlArray1D : public BaseLabelledArray<ControlArray1D, LabelType>, public IsLabelled1D<LabelledControlArray1D> {
public:
    using Base = BaseLabelledArray<ControlArray1D, LabelType>;
    using Base::Base;

    const ControlArray1D& get_array() const {
        if (!this->_array) {
            throw std::runtime_error("Array is null");
        }
        return *this->_array;
    }

    nlohmann::json to_json() const override {
        nlohmann::json j = Base::to_json();
        add_metadata(j, "falcon_core.math.labelled_arrays.labelled_control_array_1D", "LabelledControlArray1D");
        return j;
    }
};

} // namespace falcon_core
