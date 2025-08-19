%{
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
%}

%module(package="falcon_core.physics.device_structures") BaseConnection
%include "falcon_core/physics/device_structures/BaseConnection.hpp"

%include "add_song_deserializers.i"
%add_song_deserializers(falcon_core::physics::device_structures::BaseConnection);
