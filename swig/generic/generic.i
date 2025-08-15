%{
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::generic::Song);

%rename(Jsonable, pyname="generic.Jsonable") falcon_core::generic::Song;
%feature("director") falcon_core::generic::Song;

%include "falcon_core/generic/Song.hpp"


