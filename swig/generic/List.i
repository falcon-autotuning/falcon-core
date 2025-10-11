%module list
%{
#include "falcon_core/generic/List.hpp"
%}
%include <std_shared_ptr.i>
%pythoncode %{
from falcon_core.generic.song import Song
%}
%include "falcon_core/generic/List.hpp"
%template(DoubleListSP) std::shared_ptr<falcon_core::generic::List<double>>;
%template(IntListSP) std::shared_ptr<falcon_core::generic::List<int>>;
%template(BoolListSP) std::shared_ptr<falcon_core::generic::List<bool>>;
%template(StringListSP) std::shared_ptr<falcon_core::generic::List<std::string>>;
%extend falcon_core::generic::List<double> {
    static falcon_core::generic::List<double> create_empty() {
        return falcon_core::generic::List<double>::create_empty();
      }
    static falcon_core::generic::List<double> allocate(size_t count) {
        return falcon_core::generic::List<double>::allocate(count);
      }
    static falcon_core::generic::List<double> fill_value(size_t count, const StoredValue& value) {
        return falcon_core::generic::List<double>::fill_value(count, value);
      }
    static falcon_core::generic::List<double> create(const Container& init) {
        return falcon_core::generic::List<double>::create(init);
      }
    static falcon_core::generic::List<double> from_json_string(const std::string& json) {
        return falcon_core::generic::List<double>::from_json_string<falcon_core::generic::List<double>>(json);
    }
%} 
%extend std::shared_ptr<falcon_core::physics::device_structures::List> {  
    void append(const falcon_core::generic::List<double>::StoredValue& item) { return $self->push_back(item); }
    size_t size() { return $self->get()->size(); }
    bool empty() {return $self->get()->empty(); }

    bool __eq__(const std::shared_ptr<falcon_core::generic::List<double>> other) { return *$self->get() == *other; }
    bool __neq__(const std::shared_ptr<falcon_core::generic::List<double>> other) { return *$self->get() != *other; }
    size_t __len__() {
        return $self->get()->size();
    }
    falcon_core::generic::List<double>::StoredValue& __getitem__(const size_t idx) {
        return $self->get()->at(idx);
      }
    falcon_core::generic::List<double>::StoredValue& __setitem__(const size_t idx, const falcon_core::generic::List<double>::StoredValue value) {
        $self->get()->at(idx) = value;
      }
    const falcon_core::generic::List<double>::StoredValue& __getitem__(const size_t idx) {
        return $self->get()->at(idx);
      }
    const falcon_core::generic::List<double>::Container items() {
        return $this->get()->items();
      }
    falcon_core::generic::List<double>::Container items() {
        return $this->get()->items();
      }
    bool contains(const falcon_core::generic::List<double>::StoredValue value) {
        return $this->get()->contains(value);
      }
    size_t index(const falcon_core::generic::List<double>::StoredValue value) {
        return $this->get()->index(value);
      }
    std::shared_ptr<List<double>> intersection(const std::shared_ptr<List<double>> other) {
        return $this->get()->intersection(other);
      }
    void clear() { $this->get()->clear(); }
    void erase_at(size_t idx) { $this->get()->erase_at(); }
    falcon_core::generic::List<double>::StoredValue back() { return $this->get()->back(); }
}
