%module connection
%{
#include "falcon_core/physics/device_structures/Connection.hpp"
%}
%include <std_shared_ptr.i>
%include <std_string.i>
%include "falcon_core/generic/Song.hpp"
%include "falcon_core/physics/device_structures/Connection.hpp"
%shared_ptr(falcon_core::physics::device_structures::Connection)
%template(ConnectionSP) std::shared_ptr<falcon_core::physics::device_structures::Connection>;
%extend std::shared_ptr<falcon_core::physics::device_structures::Connection> {
    bool is_barrier_gate() { return $self->get()->is_barrier_gate(); }
    bool is_plunger_gate() { return $self->get()->is_plunger_gate(); }
    bool is_reservoir_gate() { return $self->get()->is_reservoir_gate(); }
    bool is_screening_gate() { return $self->get()->is_screening_gate(); }
    bool is_ohmic() { return $self->get()->is_ohmic(); }
    bool is_dot_gate() { return $self->get()->is_dot_gate(); }
    bool is_gate() { return $self->get()->is_gate(); }
    std::string name() { return $self->get()->name(); }
    std::string type() { return $self->get()->type(); }
}
