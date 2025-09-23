%module list

%include <std_shared_ptr.i>

%extend falcon_core::generic::List {
    std::shared_ptr<T> __getitem__(size_t idx) {
        if (idx >= $self->size()) throw std::out_of_range("index out of range");
        return (*$self)[idx];
    }
    void __setitem__(size_t idx, std::shared_ptr<T> value) {
        if (idx >= $self->size()) throw std::out_of_range("index out of range");
        $self->set(idx, value);
    }
    size_t __len__() {
        return $self->size();
    }
}

%{
#include "falcon_core/generic/List.hpp"
%}

%include "falcon_core/generic/List.hpp"
%include "add_song_deserializers.i"
%shared_ptr(falcon_core::generic::List)
%add_song_deserializers(falcon_core::generic::List)
