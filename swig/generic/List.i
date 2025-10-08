%module list
%{
#include "falcon_core/generic/List.hpp"
%}
%include <std_shared_ptr.i>
%pythoncode %{
from falcon_core.generic.song import Song
%}
%include "falcon_core/generic/List.hpp"
%template(DoubleListSP) std::shared_ptr<falcon_core::generic::List<double>>;
%template(IntListSP) std::shared_ptr<falcon_core::generic::List<int>>;
%template(BoolListSP) std::shared_ptr<falcon_core::generic::List<bool>>;
%template(StringListSP) std::shared_ptr<falcon_core::generic::List<std::string>>;
%extend std::shared_ptr<falcon_core::physics::device_structures::List> {
    bool is_barrier_gate() { return $self->get()->is_barrier_gate(); }
    bool is_plunger_gate() { return $self->get()->is_plunger_gate(); }
    bool is_reservoir_gate() { return $self->get()->is_reservoir_gate(); }
    bool is_screening_gate() { return $self->get()->is_screening_gate(); }
    bool is_ohmic() { return $self->get()->is_ohmic(); }
    bool is_dot_gate() { return $self->get()->is_dot_gate(); }
    bool is_gate() { return $self->get()->is_gate(); }
    std::string name() { return $self->get()->name(); }
    std::string type() { return $self->get()->type(); }
    std::string to_json_string() { return $self->get()->to_json_string(); }
    bool __eq__(const falcon_core::physics::device_structures::ConnectionSP other) { return *$self->get() == *other; }
    bool __neq__(const falcon_core::physics::device_structures::ConnectionSP other) { return *$self->get() != *other; }
}
%extend falcon_core::physics::device_structures::Connection {
    static falcon_core::physics::device_structures::ConnectionSP from_json_string(const std::string& json) {
        return falcon_core::physics::device_structures::Connection::from_json_string<falcon_core::physics::device_structures::Connection>(json);
    }
}
%extend falcon_core::generic::List {
    std::shared_ptr<T> __getitem__(size_t idx) {
        if (idx >= $self->size()) throw std::out_of_range("index out of range");
        return (*$self)[idx];
    }
    void __setitem__(size_t idx, std::shared_ptr<T> value) {
        if (idx >= $self->size()) throw std::out_of_range("index out of range");
        $self->set(idx, value);
    }
    size_t __len__() {
        return $self->size();
    }
}

%{
#include "falcon_core/generic/List.hpp"
%}

%include "falcon_core/generic/List.hpp"
%include "add_song_deserializers.i"
%shared_ptr(falcon_core::generic::List)
%add_song_deserializers(falcon_core::generic::List)
