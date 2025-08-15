%{
#include "falcon_core/generic/Song.hpp"
%}

%shared_ptr(falcon_core::generic::Song);

%rename(Song, pyname="generic.Song") falcon_core::generic::Song;
%feature("director") falcon_core::generic::Song;

%ignore falcon_core::generic::Song::from_json_string;
%ignore falcon_core::generic::Song::from_json_stream;
%include "falcon_core/generic/Song.hpp"

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


