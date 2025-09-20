/*
%{
#include "falcon_core/physics/device_structures/NameBase.hpp"
#include "falcon_core/physics/device_structures/Channel.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
#include "falcon_core/physics/device_structures/InstrumentPort.hpp"
#include "falcon_core/physics/device_structures/Ports.hpp"
#include "falcon_core/physics/device_structures/Connections.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"
#include "falcon_core/physics/device_structures/Impedances.hpp"
#include "falcon_core/physics/device_structures/GateRelations.hpp"

#include "falcon_core/physics/device_structures/Channels.hpp"
%}

%shared_ptr(falcon_core::NameBase<int>);
%shared_ptr(falcon_core::NameBase<std::string>);
%shared_ptr(falcon_core::Channel);
%nodefaultctor falcon_core::Channel;
%shared_ptr(falcon_core::Connection);
%nodefaultctor falcon_core::Connection;
%shared_ptr(falcon_core::physics::device_structures::Connections<falcon_core::Channel>);
%shared_ptr(falcon_core::physics::device_structures::Impedance);
%shared_ptr(falcon_core::physics::device_structures::GateRelations);
%shared_ptr(falcon_core::Impedances);

%include "falcon_core/physics/device_structures/NameBase.hpp"
%include "falcon_core/physics/device_structures/Channel.hpp"
%include "falcon_core/physics/device_structures/Connection.hpp"
%include "falcon_core/physics/device_structures/InstrumentPort.hpp"

%include "falcon_core/physics/device_structures/Connections.hpp"
%include "falcon_core/physics/device_structures/Impedance.hpp"
%include "falcon_core/physics/device_structures/Impedances.hpp"
%include "falcon_core/physics/device_structures/GateRelations.hpp"

%include "falcon_core/physics/device_structures/Channels.hpp"


// Instantiate NameBase for int and string
%template(NameBaseInt) falcon_core::NameBase<int>;
%template(NameBaseString) falcon_core::NameBase<std::string>;

// Enable directors for Connection if it's meant to be subclassed in Python
%feature("director") falcon_core::Connection;

// Forward declare Instrument to resolve dependency in InstrumentPort
class Instrument {};

// Instantiate templates for ports
%template(InstrumentPortGate) falcon_core::InstrumentPort<falcon_core::Gate>;
%template(PortsGate) falcon_core::Ports<falcon_core::InstrumentPort<falcon_core::Gate>>;

// Instantiate templates for connections and relations
%template(Gates) falcon_core::Connections<falcon_core::Gate>;

%include "std_complex.i"
%template(QuantityComplexDouble) falcon_core::Quantity<std::complex<double>>;

// Instantiate templates for StandardConfigConnections
%template(Ohmics) falcon_core::Connections<falcon_core::Ohmic>;

// Instantiate Channels
%template(Channels) falcon_core::Connections<falcon_core::Channel>;
*/
