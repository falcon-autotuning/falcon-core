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

