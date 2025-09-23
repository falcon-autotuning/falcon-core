%module song

%include <std_shared_ptr.i>


%{
#include "falcon_core/generic/Song.hpp"
%}

//%feature("director") falcon_core::generic::Song;
%include "falcon_core/generic/Song.hpp"

%ignore falcon_core::generic::Song::from_json_string;                                  
%ignore falcon_core::generic::Song::from_json_stream;
%include "add_song_deserializers.i"
%shared_ptr(falcon_core::generic::Song)
%add_song_deserializers(falcon_core::generic::Song);


