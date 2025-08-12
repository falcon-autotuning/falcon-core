%{
#include "falcon_core/NameBase.hpp"
#include "falcon_core/Channel.hpp"
#include "falcon_core/BaseConnection.hpp"
#include "falcon_core/Gate.hpp"
#include "falcon_core/Ohmic.hpp"
#include "falcon_core/InstrumentPort.hpp"
#include "falcon_core/Ports.hpp"
#include "falcon_core/BaseConnections.hpp"
#include "falcon_core/Impedance.hpp"
#include "falcon_core/Impedances.hpp"
#include "falcon_core/GateRelations.hpp"
#include "falcon_core/StandardConfigConnections.hpp"
#include "falcon_core/Loader.hpp"
#include "falcon_core/Channels.hpp"
%}

%include "falcon_core/NameBase.hpp"
%include "falcon_core/Channel.hpp"
%include "falcon_core/BaseConnection.hpp"
%include "falcon_core/Gate.hpp"
%include "falcon_core/Ohmic.hpp"
%include "falcon_core/InstrumentPort.hpp"
%include "falcon_core/Ports.hpp"
%include "falcon_core/BaseConnections.hpp"
%include "falcon_core/Impedance.hpp"
%include "falcon_core/Impedances.hpp"
%include "falcon_core/GateRelations.hpp"
%include "falcon_core/StandardConfigConnections.hpp"
%include "falcon_core/Loader.hpp"
%include "falcon_core/Channels.hpp"

// Instantiate NameBase for int and string
%template(NameBaseInt) falcon_core::NameBase<int>;
%template(NameBaseString) falcon_core::NameBase<std::string>;

// Enable directors for BaseConnection if it's meant to be subclassed in Python
%feature("director") falcon_core::BaseConnection;

// Forward declare Instrument to resolve dependency in InstrumentPort
class Instrument {};
%shared_ptr(Instrument)

// Instantiate templates for ports
%template(InstrumentPortGate) falcon_core::InstrumentPort<falcon_core::Gate>;
%shared_ptr(falcon_core::InstrumentPort<falcon_core::Gate>)
%template(PortsGate) falcon_core::Ports<falcon_core::InstrumentPort<falcon_core::Gate>>;

// Instantiate templates for connections and relations
%shared_ptr(falcon_core::Gate)
%template(Gates) falcon_core::BaseConnections<falcon_core::Gate>;
%shared_ptr(falcon_core::BaseConnections<falcon_core::Gate>)

%include "std_complex.i"
%template(QuantityComplexDouble) falcon_core::Quantity<std::complex<double>>;
%shared_ptr(falcon_core::Quantity<std::complex<double>>)
%shared_ptr(falcon_core::Impedance)

%shared_ptr(falcon_core::GateRelations)

// Instantiate templates for StandardConfigConnections
%shared_ptr(falcon_core::Ohmic)
%template(Ohmics) falcon_core::BaseConnections<falcon_core::Ohmic>;
%shared_ptr(falcon_core::BaseConnections<falcon_core::Ohmic>)
%shared_ptr(falcon_core::StandardConfigConnections)
%shared_ptr(falcon_core::Loader)

// Instantiate Channels
%shared_ptr(falcon_core::Channel)
%template(Channels) falcon_core::BaseConnections<falcon_core::Channel>;
%shared_ptr(falcon_core::BaseConnections<falcon_core::Channel>)
