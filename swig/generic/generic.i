%{
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::generic::Song);

%rename(Song, pyname="generic.Song") falcon_core::generic::Song;
%feature("director") falcon_core::generic::Song;

%include "falcon_core/generic/Song.hpp"


