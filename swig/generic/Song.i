%{
#include "falcon_core/generic/Song.hpp"
%}

%module(package="falcon_core.generic") Song 
%feature("director") falcon_core::generic::Song;
%include "falcon_core/generic/Song.hpp"

%ignore falcon_core::generic::Song::from_json_string;                                  
%ignore falcon_core::generic::Song::from_json_stream;
%include "add_song_deserializers.i"
%add_song_deserializers(falcon_core::generic::Song);


