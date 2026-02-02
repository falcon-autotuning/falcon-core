#include <gtest/gtest.h>

#include <vector>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/math/AxesInstrumentPort_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class AxesInstrumentPortTest : public ::testing::Test {
 protected:
  void SetUp() override {
    axes = AxesInstrumentPort_create_empty();

    // Create two tracked items and push them into axes and axes2
    auto item1 = track_instrument_port(
        InstrumentPort_create_port(String_wrap("port1"),
                                   NULL,
                                   InstrumentTypes_voltmeter(),
                                   SymbolUnit_create_volt(),
                                   String_wrap("")));
    auto item2 = track_instrument_port(
        InstrumentPort_create_port(String_wrap("port2"),
                                   NULL,
                                   InstrumentTypes_voltmeter(),
                                   SymbolUnit_create_volt(),
                                   String_wrap("")));
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
  set_last_error(0, nullptr);
  AxesInstrumentPort_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto liph = ListInstrumentPort_create_empty();
  ListInstrumentPort_push_back(liph, InstrumentPort_create_timer());
  ListInstrumentPort_push_back(liph, InstrumentPort_create_timer());
  EXPECT_NO_THROW(AxesInstrumentPort_create(liph));
  ListInstrumentPort_destroy(liph);
}

TEST_F(AxesInstrumentPortTest, AccessorsAndMutators) {
  EXPECT_EQ(AxesInstrumentPort_size(axes), 2u);
  AxesInstrumentPort_push_back(axes,
                               track_instrument_port(InstrumentPort_create_port(
                                   String_wrap("port1"),
                                   NULL,
                                   InstrumentTypes_voltmeter(),
                                   SymbolUnit_create_volt(),
                                   String_wrap(""))));
  InstrumentPortHandle out2[3];
  EXPECT_EQ(AxesInstrumentPort_items(axes, out2, 3), 3u);
  // items(...) writes copies/handles into out2; caller must free them if they
  // are new handles.
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
  set_last_error(0, nullptr);
  AxesInstrumentPort_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesInstrumentPort_to_json_string(axes);
    auto loaded = AxesInstrumentPort_from_json_string(json);
    AxesInstrumentPort_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesInstrumentPortTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesInstrumentPort_equal(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_not_equal(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesInstrumentPort_equal(axes, axes));
  EXPECT_NO_THROW(AxesInstrumentPort_not_equal(axes, axes2));
}

TEST_F(AxesInstrumentPortTest, Intersection) {
  set_last_error(0, nullptr);
  AxesInstrumentPort_intersection(nullptr, axes2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_intersection(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesInstrumentPort_intersection(axes, axes2));
}

TEST_F(AxesInstrumentPortTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesInstrumentPort_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_push_back(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_contains(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_index(axes, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_items(axes, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesInstrumentPort_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
