%{
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::physics::device_structures::Connection);
%shared_ptr(falcon_core::physics::device_structures::Connections);
%shared_ptr(falcon_core::physics::device_structures::Impedance);
%shared_ptr(falcon_core::physics::device_structures::Impedances);
%shared_ptr(falcon_core::physics::device_structures::GateRelations);

%rename(BaseConnection, pyname="physics.device_structures.Connection") falcon_core::physics::device_structures::Connection;
%rename(Connections, pyname="physics.device_structures.ScreeningGates") falcon_core::physics::device_structures::Connections;
%rename(Impedance, pyname="physics.device_structures.Impedance") falcon_core::physics::device_structures::Impedance;
%rename(Impedances, pyname="physics.device_structures.Impedances") falcon_core::physics::device_structures::Impedances;
%rename(GateRelations, pyname="physics.device_structures.GateRelations") falcon_core::physics::device_structures::GateRelations;

%include "falcon_core/physics/device_structures/Connection.hpp"
%include "falcon_core/physics/device_structures/Connections.hpp"
%include "falcon_core/physics/device_structures/Impedance.hpp"
%include "falcon_core/physics/device_structures/Impedances.hpp"
%include "falcon_core/physics/device_structures/GateRelations.hpp"

%add_song_deserializers(falcon_core::physics::device_structures::Connection);
%add_song_deserializers(falcon_core::physics::device_structures::Connections);
%add_song_deserializers(falcon_core::physics::device_structures::Impedance);
%add_song_deserializers(falcon_core::physics::device_structures::Impedances);
%add_song_deserializers(falcon_core::physics::device_structures::GateRelations);


