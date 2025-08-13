%{
#include "falcon_core/BaseDiscretizer.hpp"
#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/Spaces.hpp"
#include "falcon_core/Waveform.hpp"
%}

%shared_ptr(falcon_core::BaseDiscretizer);
%shared_ptr(falcon_core::CartesianDiscretizer);
%shared_ptr(falcon_core::Spaces);
%shared_ptr(falcon_core::Waveform);
%include "falcon_core/BaseDiscretizer.hpp"
%include "falcon_core/CartesianDiscretizer.hpp"
%include "falcon_core/Spaces.hpp"
%include "falcon_core/Waveform.hpp"

%feature("director") falcon_core::BaseDiscretizer;
