%{
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::generic::Song);

%rename(Song, pyname="generic.Song") falcon_core::generic::Song;
%feature("director") falcon_core::generic::Song;

%include "falcon_core/generic/Song.hpp"
%ignore falcon_core::generic::Song::from_json_string;                                  
%ignore falcon_core::generic::Song::from_json_stream;

%define %add_song_deserializers(ClassName)
%extend ClassName {
    static std::shared_ptr<ClassName> from_json_string(const std::string& json) {
        return falcon_core::generic::Song::from_json_string<ClassName>(json);
    }
    static std::shared_ptr<ClassName> from_json_stream(std::istream& is) {
        return falcon_core::generic::Song::from_json_stream<ClassName>(is);
    }
}
%enddef


