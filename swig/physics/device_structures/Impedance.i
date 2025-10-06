%module impedance 
%{
#include "falcon_core/physics/device_structures/Impedance.hpp"
%}
%include <std_shared_ptr.i>
%include "falcon_core/generic/Song.hpp"
%include "falcon_core/physics/device_structures/Impedance.hpp"
%shared_ptr(falcon_core::physics::device_structures::Impedance)
%template(ImpedanceSP) std::shared_ptr<falcon_core::physics::device_structures::Impedance>;
%extend std::shared_ptr<falcon_core::physics::device_structures::Impedance> {
    ConnectionSP connection() { return $self->get()->connection(); }
    double resistance() { return $self->get()->resistance(); }
    double capacitance() { return $self->get()->capacitance(); }
}
