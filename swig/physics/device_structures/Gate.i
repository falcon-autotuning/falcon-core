%{
#include "falcon_core/physics/device_structures/Gate.hpp"
%}

%module(package="falcon_core.physics.device_structures") Gate
%include "falcon_core/physics/device_structures/Gate.hpp"

%include "add_song_deserializers.i"
%add_song_deserializers(falcon_core::physics::device_structures::Gate);
