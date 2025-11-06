#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/AxesInstrumentPort_c_api.h"

class AxesInstrumentPortTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesInstrumentPort_create_empty();

    // Create two tracked items and push them into axes and axes2
    auto item1 = track_instrument_port(InstrumentPort_create_port(String_wrap("port1")));
    auto item2 = track_instrument_port(InstrumentPort_create_port(String_wrap("port2")));
    AxesInstrumentPort_push_back(axes, item1);
    AxesInstrumentPort_push_back(axes, item2);

    axes2 = AxesInstrumentPort_create_empty();
    AxesInstrumentPort_push_back(axes2, item1);
    AxesInstrumentPort_push_back(axes2, item2);
  }

  void TearDown() override {
    // Destroy axes handles and tracked items
    if (axes) {
      AxesInstrumentPort_destroy(axes);
      axes = nullptr;
    }
    if (axes2) {
      AxesInstrumentPort_destroy(axes2);
      axes2 = nullptr;
    }
    for (auto h : created_items) {
      InstrumentPort_destroy(h);
    }
    created_items.clear();
  }

  // Helper that records created InstrumentPortHandle for proper cleanup.
  InstrumentPortHandle track_instrument_port(InstrumentPortHandle h) {
    created_items.push_back(h);
    return h;
  }

  AxesInstrumentPortHandle axes  = nullptr;
  AxesInstrumentPortHandle axes2 = nullptr;

  // All InstrumentPort handles created during the fixture are tracked here.
  std::vector<InstrumentPortHandle> created_items;
  InstrumentPortHandle              rawbuffer[2];
};

TEST_F(AxesInstrumentPortTest, CreateDestroy) {
  auto h = AxesInstrumentPort_create_empty();
  AxesInstrumentPort_destroy(h);
  EXPECT_THROW(AxesInstrumentPort_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_destroy(nullptr), std::invalid_argument);

  auto liph = ListInstrumentPort_create_empty();
  ListInstrumentPort_push_back(liph, InstrumentPort_create_timer());
  ListInstrumentPort_push_back(liph, InstrumentPort_create_timer());
  EXPECT_NO_THROW(AxesInstrumentPort_create(liph));
  ListInstrumentPort_destroy(liph);
}

TEST_F(AxesInstrumentPortTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesInstrumentPort_size(axes), 2u);

  InstrumentPortHandle out[1] = {
      track_instrument_port(InstrumentPort_create_port(String_wrap("port1")))};
  auto h2 = AxesInstrumentPort_create_raw(out, 1);
  if (h2) AxesInstrumentPort_destroy(h2);

  AxesInstrumentPort_push_back(
      axes, track_instrument_port(InstrumentPort_create_port(String_wrap("port1"))));
  InstrumentPortHandle out2[3];
  EXPECT_EQ(AxesInstrumentPort_items(axes, out2, 3), 3u);
  // items(...) writes copies/handles into out2; caller must free them if they are new handles.
  for (size_t i = 0; i < 3; ++i) {
    InstrumentPort_destroy(out2[i]);
  }

  AxesInstrumentPort_erase_at(axes, 2);
  AxesInstrumentPort_clear(axes);
  EXPECT_TRUE(AxesInstrumentPort_empty(axes));
}

TEST_F(AxesInstrumentPortTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(
      AxesInstrumentPort_contains(axes, AxesInstrumentPort_at(axes, 0)));
  EXPECT_NO_THROW(
      AxesInstrumentPort_index(axes, AxesInstrumentPort_at(axes, 0)));
  EXPECT_NO_THROW(AxesInstrumentPort_equal(axes, axes2));
}

TEST_F(AxesInstrumentPortTest, SerializationRoundTrip) {
  EXPECT_THROW(AxesInstrumentPort_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesInstrumentPort_to_json_string(axes);
    auto loaded = AxesInstrumentPort_from_json_string(json);
    AxesInstrumentPort_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesInstrumentPortTest, EqualityWorks) {
  EXPECT_THROW(AxesInstrumentPort_equal(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_not_equal(nullptr, axes2),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesInstrumentPort_equal(axes, axes));
  EXPECT_NO_THROW(AxesInstrumentPort_not_equal(axes, axes2));
}

TEST_F(AxesInstrumentPortTest, Intersection) {
  EXPECT_THROW(AxesInstrumentPort_intersection(nullptr, axes2),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_intersection(axes, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesInstrumentPort_intersection(axes, axes2));
}

TEST_F(AxesInstrumentPortTest, MiscNullChecks) {
  EXPECT_THROW(AxesInstrumentPort_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_push_back(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_contains(axes, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_index(axes, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_items(axes, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesInstrumentPort_create_raw(nullptr, 2),
               std::invalid_argument);
}
