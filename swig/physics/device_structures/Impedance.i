%module impedance 
%{
#include "falcon_core/physics/device_structures/Impedance.hpp"
%}
%include <std_shared_ptr.i>
%pythoncode %{
from falcon_core.generic.song import Song
from falcon_core.physics.device_structures.connection import Connection
%}
%include "falcon_core/generic/Song.hpp"
%include "falcon_core/physics/device_structures/Connection.hpp"
%include "falcon_core/physics/device_structures/Impedance.hpp"
%shared_ptr(falcon_core::physics::device_structures::Impedance)
%template(ImpedanceSP) std::shared_ptr<falcon_core::physics::device_structures::Impedance>;
%extend std::shared_ptr<falcon_core::physics::device_structures::Impedance> {
    falcon_core::physics::device_structures::ConnectionSP connection() { return $self->get()->connection(); }
    double resistance() { return $self->get()->resistance(); }
    double capacitance() { return $self->get()->capacitance(); }
    std::string to_json_string() { return $self->get()->to_json_string(); }
    bool __eq__(const falcon_core::physics::device_structures::ImpedanceSP other) { return *$self->get() == *other; }
    bool __neq__(const falcon_core::physics::device_structures::ImpedanceSP other) { return *$self->get() != *other; }
}
%extend falcon_core::physics::device_structures::Impedance {
    static falcon_core::physics::device_structures::ImpedanceSP from_json_string(const std::string& json) {
        return falcon_core::physics::device_structures::Impedance::from_json_string<falcon_core::physics::device_structures::Impedance>(json);
    }
}
