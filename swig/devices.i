%{
#include "falcon_core/NameBase.hpp"
#include "falcon_core/Channel.hpp"
#include "falcon_core/BaseConnection.hpp"
#include "falcon_core/Gate.hpp"
#include "falcon_core/Ohmic.hpp"
%}

%include "falcon_core/NameBase.hpp"
%include "falcon_core/Channel.hpp"
%include "falcon_core/BaseConnection.hpp"
%include "falcon_core/Gate.hpp"
%include "falcon_core/Ohmic.hpp"

// Instantiate NameBase for int and string
%template(NameBaseInt) falcon_core::NameBase<int>;
%template(NameBaseString) falcon_core::NameBase<std::string>;

// Enable directors for BaseConnection if it's meant to be subclassed in Python
%feature("director") falcon_core::BaseConnection;
