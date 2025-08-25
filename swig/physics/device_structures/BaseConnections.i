%module(package="physics.units.BaseConnections") physics::device_structures::BaseConnections

%extend physics::device_structures::BaseConnections {
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
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
%}
%include "falcon_core/physics/device_structures/BaseConnection.hpp"
%include "falcon_core/physics/device_structures/BaseConnections.hpp"
%include "add_song_deserializers.i"
%shared_ptr(physics::device_structures::BaseConnection)
%add_song_deserializers(BaseConnection)
