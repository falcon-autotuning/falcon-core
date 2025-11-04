#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"

class InstrumentTypesTest : public ::testing::Test {
 protected:
  void TearDown() override {
    for (auto s : handles) {
      String_destroy(s);
    }
    handles.clear();
  }
  StringHandle track(StringHandle s) {
    handles.push_back(s);
    return s;
  }
  std::vector<StringHandle> handles;
};

TEST_F(InstrumentTypesTest, AllTypesReturnNonNull) {
  handles.push_back(InstrumentTypes_dc_voltage_source());
  handles.push_back(InstrumentTypes_amnmeter());
  handles.push_back(InstrumentTypes_magnet());
  handles.push_back(InstrumentTypes_lockin());
  handles.push_back(InstrumentTypes_voltage_source());
  handles.push_back(InstrumentTypes_current_source());
  handles.push_back(InstrumentTypes_hf_voltage_source());
  handles.push_back(InstrumentTypes_dc_current_source());
  handles.push_back(InstrumentTypes_hf_current_source());
  handles.push_back(InstrumentTypes_thermometer());
  handles.push_back(InstrumentTypes_voltmeter());
  handles.push_back(InstrumentTypes_fpga());
  handles.push_back(InstrumentTypes_clock());
  handles.push_back(InstrumentTypes_discrete());

  for (auto s : handles) {
    ASSERT_NE(s, nullptr);
    ASSERT_NE(s->raw, nullptr);
    ASSERT_GT(s->length, 0u);
  }
}
