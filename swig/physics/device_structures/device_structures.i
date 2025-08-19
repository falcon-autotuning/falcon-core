%{
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/DotGate.hpp"

#include "falcon_core/physics/device_structures/Ohmic.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"

#include "falcon_core/physics/device_structures/Ohmics.hpp"
#include "falcon_core/physics/device_structures/BarrierGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGates.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::physics::device_structures::BaseConnection);
%shared_ptr(falcon_core::physics::device_structures::Gate);
%shared_ptr(falcon_core::physics::device_structures::DotGate);
%shared_ptr(falcon_core::physics::device_structures::Ohmic);
%shared_ptr(falcon_core::physics::device_structures::BarrierGate);
%shared_ptr(falcon_core::physics::device_structures::PlungerGate);
%shared_ptr(falcon_core::physics::device_structures::ReservoirGate);
%shared_ptr(falcon_core::physics::device_structures::BaseConnections);
%shared_ptr(falcon_core::physics::device_structures::Gates);
%shared_ptr(falcon_core::physics::device_structures::DotGates);
%shared_ptr(falcon_core::physics::device_structures::Ohmics);
%shared_ptr(falcon_core::physics::device_structures::BarrierGates);
%shared_ptr(falcon_core::physics::device_structures::PlungerGates);
%shared_ptr(falcon_core::physics::device_structures::ReservoirGates);
%shared_ptr(falcon_core::physics::device_structures::ScreeningGates);
%shared_ptr(falcon_core::physics::device_structures::Impedance);
%shared_ptr(falcon_core::physics::device_structures::Impedances);
%shared_ptr(falcon_core::physics::device_structures::GateRelations);

%rename(BaseConnection, pyname="physics.device_structures.BaseConnection") falcon_core::physics::device_structures::BaseConnection;
%rename(Gate, pyname="physics.device_structures.Gate") falcon_core::physics::device_structures::Gate;
%rename(DotGate, pyname="physics.device_structures.DotGate") falcon_core::physics::device_structures::DotGate;
%rename(Ohmic, pyname="physics.device_structures.Ohmic") falcon_core::physics::device_structures::Ohmic;
%rename(BarrierGate, pyname="physics.device_structures.BarrierGate") falcon_core::physics::device_structures::BarrierGate;
%rename(PlungerGate, pyname="physics.device_structures.PlungerGate") falcon_core::physics::device_structures::PlungerGate;
%rename(ReservoirGate, pyname="physics.device_structures.ReservoirGate") falcon_core::physics::device_structures::ReservoirGate;
%rename(Gates, pyname="physics.device_structures.Gates") falcon_core::physics::device_structures::Gates;
%rename(DotGates, pyname="physics.device_structures.DotGates") falcon_core::physics::device_structures::DotGates;
%rename(Ohmics, pyname="physics.device_structures.Ohmics") falcon_core::physics::device_structures::Ohmics;
%rename(BarrierGates, pyname="physics.device_structures.BarrierGates") falcon_core::physics::device_structures::BarrierGates;
%rename(PlungerGates, pyname="physics.device_structures.PlungerGates") falcon_core::physics::device_structures::PlungerGates;
%rename(ReservoirGates, pyname="physics.device_structures.ReservoirGates") falcon_core::physics::device_structures::ReservoirGates;
%rename(ScreeningGates, pyname="physics.device_structures.ScreeningGates") falcon_core::physics::device_structures::ScreeningGates;
%rename(Impedance, pyname="physics.device_structures.Impedance") falcon_core::physics::device_structures::Impedance;
%rename(Impedances, pyname="physics.device_structures.Impedances") falcon_core::physics::device_structures::Impedances;
%rename(GateRelations, pyname="physics.device_structures.GateRelations") falcon_core::physics::device_structures::GateRelations;

%include "falcon_core/physics/device_structures/BaseConnection.hpp"
%include "falcon_core/physics/device_structures/Gate.hpp"
%include "falcon_core/physics/device_structures/DotGate.hpp"
%include "falcon_core/physics/device_structures/Ohmic.hpp"
%include "falcon_core/physics/device_structures/BarrierGate.hpp"
%include "falcon_core/physics/device_structures/PlungerGate.hpp"
%include "falcon_core/physics/device_structures/ReservoirGate.hpp"
%include "falcon_core/physics/device_structures/ScreeningGate.hpp"
%include "falcon_core/physics/device_structures/BaseConnection.hpp"
%include "falcon_core/physics/device_structures/Gates.hpp"
%include "falcon_core/physics/device_structures/DotGates.hpp"
%include "falcon_core/physics/device_structures/Ohmics.hpp"
%include "falcon_core/physics/device_structures/BarrierGates.hpp"
%include "falcon_core/physics/device_structures/PlungerGates.hpp"
%include "falcon_core/physics/device_structures/ReservoirGates.hpp"
%include "falcon_core/physics/device_structures/ScreeningGates.hpp"
%include "falcon_core/physics/device_structures/Impedance.hpp"
%include "falcon_core/physics/device_structures/Impedances.hpp"
%include "falcon_core/physics/device_structures/GateRelations.hpp"

%add_song_deserializers(falcon_core::physics::device_structures::BaseConnection);
%add_song_deserializers(falcon_core::physics::device_structures::Gate);
%add_song_deserializers(falcon_core::physics::device_structures::DotGate);
%add_song_deserializers(falcon_core::physics::device_structures::Ohmic);
%add_song_deserializers(falcon_core::physics::device_structures::BarrierGate);
%add_song_deserializers(falcon_core::physics::device_structures::PlungerGate);
%add_song_deserializers(falcon_core::physics::device_structures::ReservoirGate);
%add_song_deserializers(falcon_core::physics::device_structures::Impedance);


