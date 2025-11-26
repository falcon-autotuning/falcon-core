#include <gtest/gtest.h>

#include <stdexcept>

#include "falcon_core/generic/Song.hpp"
namespace {
class Strsong : public falcon_core::generic::Song {
 public:
  Strsong(std::string value = "") : _value(std::move(value)) {}

  bool operator==(const Strsong& other) const {
    return Song::operator==(other);
  }
  bool operator!=(const Strsong& other) const {
    return Song::operator!=(other);
  }

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
              std::vector<std::shared_ptr<Strsong>> songs   = {},
              MyEnum                                other   = MyEnum::STUFF)
      : _strings(std::move(strings)), _songs(std::move(songs)), _other(other) {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<falcon_core::generic::Song>(this),
       _strings,
       _songs,
       _other);
  }

  std::vector<std::string>              _strings;
  std::vector<std::shared_ptr<Strsong>> _songs;
  MyEnum                                _other;
};

// Custom hash and Equal for using shared_ptr<Strsong> in unordered_map
struct StrsongPtrHash {
  std::size_t operator()(const std::shared_ptr<Strsong>& s) const {
    return std::hash<std::string>{}(s->_value);
  }
};

struct StrsongPtrEqual {
  bool operator()(const std::shared_ptr<Strsong>& a,
                  const std::shared_ptr<Strsong>& b) const {
    return *a == *b;
  }
};

// Mirrors python `the_destroyer`
class TheDestroyerSong : public falcon_core::generic::Song {
 public:
  using StrsongListSongMap = std::unordered_map<std::shared_ptr<Strsong>,
                                                std::shared_ptr<ListSong>,
                                                StrsongPtrHash,
                                                StrsongPtrEqual>;

  StrsongListSongMap                        _value;
  std::shared_ptr<ComplexSong>              _stuff;
  std::vector<std::string>                  _args;
  std::vector<std::shared_ptr<ComplexSong>> _even_more;
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

}  // namespace

// --- Cereal Type Registration ---
CEREAL_REGISTER_TYPE(::Strsong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ::Strsong)
CEREAL_REGISTER_TYPE(::ListSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ::ListSong)
CEREAL_REGISTER_TYPE(::ComplexSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, ::ComplexSong)
CEREAL_REGISTER_TYPE(::TheDestroyerSong)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     ::TheDestroyerSong)

// --- Test Fixture ---
namespace {
template <typename T>
void test_serialization(const T& original) {
  // Test string methods
  std::string json_str = original.to_json_string();
  auto        deserialized_ptr =
      falcon_core::generic::Song::from_json_string<T>(json_str);
  ASSERT_NE(deserialized_ptr, nullptr);
  ASSERT_EQ(original, *deserialized_ptr);

  // Test stream methods
  std::stringstream ss;
  original.to_json_stream(ss);
  auto deserialized_stream_ptr =
      falcon_core::generic::Song::from_json_stream<T>(ss);
  ASSERT_NE(deserialized_stream_ptr, nullptr);
  ASSERT_EQ(original, *deserialized_stream_ptr);
}

// --- Tests ---

TEST(SongTest, SimpleSerialization) {
  test_serialization(Strsong("hello"));
  test_serialization(ListSong({"hello", "world"}));
  auto string = Strsong("hello").to_json_string();
  ASSERT_THROW(TheDestroyerSong::from_json_string<TheDestroyerSong>(string),
               std::runtime_error);
}

TEST(SongTest, InEqual) {
  auto song1 = Strsong("hello");
  auto song2 = Strsong("goodbye");
  ASSERT_TRUE(song1 != song2);
}
TEST(SongTest, NotInEqual) {
  auto song1 = Strsong("hello");
  auto song2 = Strsong("hello");
  ASSERT_FALSE(song1 != song2);
}

TEST(SongTest, Equality) {
  auto song1 = Strsong("hello");
  auto song2 = Strsong("hello");
  ASSERT_TRUE(song1 == song2);
}
TEST(SongTest, NotEquality) {
  auto song1 = Strsong("hello");
  auto song2 = Strsong("goodbye");
  ASSERT_FALSE(song1 == song2);
}

TEST(SongTest, DestroyerSerialization) {
  auto original    = std::make_shared<TheDestroyerSong>();
  original->_value = {
      {std::make_shared<Strsong>("hello"),
       std::make_shared<ListSong>(std::vector<std::string>{"world"})}};
  original->_stuff = std::make_shared<ComplexSong>(
      std::vector<std::string>{"hello"},
      std::vector<std::shared_ptr<Strsong>>{std::make_shared<Strsong>("world")},
      MyEnum::STUFF);
  original->_args      = {"hello", "world"};
  original->_even_more = {original->_stuff};

  // Test string methods
  std::string json_str = original->to_json_string();
  auto        deserialized =
      falcon_core::generic::Song::from_json_string<TheDestroyerSong>(json_str);

  // Manual checks for equivalence
  ASSERT_NE(deserialized, nullptr);
  ASSERT_EQ(original->_args, deserialized->_args);
  ASSERT_EQ(*(original->_stuff), *(deserialized->_stuff));
  ASSERT_EQ(original->_even_more.size(), deserialized->_even_more.size());
  ASSERT_EQ(*(original->_even_more[0]), *(deserialized->_even_more[0]));
  ASSERT_EQ(original->_value.size(), deserialized->_value.size());
  auto orig_it = original->_value.begin();
  auto des_it  = deserialized->_value.begin();
  ASSERT_EQ(*(orig_it->first), *(des_it->first));
  ASSERT_EQ(*(orig_it->second), *(des_it->second));

  // Test stream methods
  std::stringstream ss;
  original->to_json_stream(ss);
  auto deserialized_stream =
      falcon_core::generic::Song::from_json_stream<TheDestroyerSong>(ss);

  ASSERT_NE(deserialized_stream, nullptr);
  ASSERT_EQ(original->_args, deserialized_stream->_args);
  ASSERT_EQ(*(original->_stuff), *(deserialized_stream->_stuff));
  ASSERT_EQ(original->_even_more.size(),
            deserialized_stream->_even_more.size());
  ASSERT_EQ(*(original->_even_more[0]), *(deserialized_stream->_even_more[0]));
  ASSERT_EQ(original->_value.size(), deserialized_stream->_value.size());
  auto stream_orig_it = original->_value.begin();
  auto des_stream_it  = deserialized_stream->_value.begin();
  ASSERT_EQ(*(stream_orig_it->first), *(des_stream_it->first));
  ASSERT_EQ(*(stream_orig_it->second), *(des_stream_it->second));
}
}  // namespace
