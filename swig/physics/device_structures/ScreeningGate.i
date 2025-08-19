%{
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
%}


%include "falcon_core/physics/device_structures/ScreeningGate.hpp"
%include "add_song_deserializers.i"
%add_song_deserializers(falcon_core::physics::device_structures::ScreeningGate);
%module(package="falcon_core.physics.device_structures") ScreeningGate
