#include <gtest/gtest.h>
#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/vector.hpp>
#include <sstream>

#include "falcon_core/generic/Song.hpp"

// --- Helper Classes for Testing ---

// Mirrors python `strjson`
class StrSong : public falcon_core::generic::Song {
 public:
  StrSong(std::string value = "") : _value(std::move(value)) {}
  bool operator==(const StrSong& other) const { return _value == other._value; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _value);
  }

  std::string _value;
};

// Mirrors python `listjson`
class ListSong : public falcon_core::generic::Song {
 public:
  ListSong(std::vector<std::string> value = {}) : _value(std::move(value)) {}
  bool operator==(const ListSong& other) const { return _value == other._value; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this), _value);
  }

  std::vector<std::string> _value;
};

// Mirrors python `enum`
enum class MyEnum { STUFF };

// Mirrors python `complexjson`
class ComplexSong : public falcon_core::generic::Song {
 public:
  ComplexSong(std::vector<std::string>              strings = {},
              std::vector<std::shared_ptr<StrSong>> songs   = {},
              MyEnum                                other   = MyEnum::STUFF)
      : _strings(std::move(strings)),
        _songs(std::move(songs)),
        _other(other) {}

  bool operator==(const ComplexSong& other) const {
    if (_strings != other._strings || _other != other._other ||
        _songs.size() != other._songs.size()) {
      return false;
    }
    for (size_t i = 0; i < _songs.size(); ++i) {
      if (!(*_songs[i] == *other._songs[i])) {
        return false;
      }
    }
    return true;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this),
       _strings,
       _songs,
       _other);
  }

  std::vector<std::string>              _strings;
  std::vector<std::shared_ptr<StrSong>> _songs;
  MyEnum                                _other;
};

// Custom hash and equality for using shared_ptr<StrSong> in unordered_map
struct StrSongPtrHash {
  std::size_t operator()(const std::shared_ptr<StrSong>& s) const {
    return std::hash<std::string>{}(s->_value);
  }
};

struct StrSongPtrEqual {
  bool operator()(const std::shared_ptr<StrSong>& a,
                  const std::shared_ptr<StrSong>& b) const {
    return *a == *b;
  }
};

// Mirrors python `the_destroyer`
class TheDestroyerSong : public falcon_core::generic::Song {
 public:
  using StrSongListSongMap =
      std::unordered_map<std::shared_ptr<StrSong>,
                         std::shared_ptr<ListSong>,
                         StrSongPtrHash,
                         StrSongPtrEqual>;

  StrSongListSongMap                          _value;
  std::shared_ptr<ComplexSong>                _stuff;
  std::vector<std::string>                    _args;
  std::vector<std::shared_ptr<ComplexSong>>   _even_more;
  // Intentionally omitting _others from python test as it's repetitive

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this),
       _value,
       _stuff,
       _args,
       _even_more);
  }
};

// --- Cereal Type Registration ---
CEREAL_REGISTER_TYPE(StrSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, StrSong)
CEREAL_REGISTER_TYPE(ListSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ListSong)
CEREAL_REGISTER_TYPE(ComplexSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ComplexSong)
CEREAL_REGISTER_TYPE(TheDestroyerSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, TheDestroyerSong)

// --- Test Fixture ---

template <typename T>
void test_serialization(const T& original) {
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(cereal::make_nvp("song", original));
  }

  T deserialized;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(cereal::make_nvp("song", deserialized));
  }

  ASSERT_EQ(original, deserialized);
}

// --- Tests ---

TEST(SongTest, SimpleSerialization) {
  test_serialization(StrSong("hello"));
  test_serialization(ListSong({"hello", "world"}));
}

TEST(SongTest, ComplexSerialization) {
  auto original = ComplexSong(
      {"hello"}, {std::make_shared<StrSong>("world")}, MyEnum::STUFF);
  test_serialization(original);
}

TEST(SongTest, DestroyerSerialization) {
  auto original = std::make_shared<TheDestroyerSong>();
  original->_value = {
      {std::make_shared<StrSong>("hello"),
       std::make_shared<ListSong>(std::vector<std::string>{"world"})}};
  original->_stuff = std::make_shared<ComplexSong>(
      std::vector<std::string>{"hello"},
      std::vector<std::shared_ptr<StrSong>>{
          std::make_shared<StrSong>("world")},
      MyEnum::STUFF);
  original->_args      = {"hello", "world"};
  original->_even_more = {original->_stuff};

  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(cereal::make_nvp("destroyer", original));
  }

  std::shared_ptr<TheDestroyerSong> deserialized;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(cereal::make_nvp("destroyer", deserialized));
  }

  // Manual checks for equivalence
  ASSERT_EQ(original->_args, deserialized->_args);
  ASSERT_EQ(*(original->_stuff), *(deserialized->_stuff));
  ASSERT_EQ(original->_even_more.size(), deserialized->_even_more.size());
  ASSERT_EQ(*(original->_even_more[0]), *(deserialized->_even_more[0]));

  ASSERT_EQ(original->_value.size(), deserialized->_value.size());
  auto orig_it = original->_value.begin();
  auto des_it  = deserialized->_value.begin();
  ASSERT_EQ(*(orig_it->first), *(des_it->first));
  ASSERT_EQ(*(orig_it->second), *(des_it->second));
}
