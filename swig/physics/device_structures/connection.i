%module connection


%include "falcon_core/generic/Song.hpp"
%include "falcon_core/physics/device_structures/Connection.hpp"
%include "add_song_deserializers.i"
%shared_ptr(falcon_core::physics::device_structures::Connection)
%extend falcon_core::physics::device_structures::Connection {
    std::string name() {
        return $self->name();
    }
    std::string type() {
        return $self->type();
    }
}
%add_song_deserializers(falcon_core::physics::device_structures::Connection);
