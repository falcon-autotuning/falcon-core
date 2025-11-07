#include <falcon_core/generic/ListWaveform_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListWaveformTest : public ::testing::Test {
 protected:
  void destroy_string(WaveformHandle sh) { Waveform_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<WaveformHandle> created_strings;
  WaveformHandle              track_quantity(const WaveformHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    StringHandle         msg          = String_wrap("msg");
    StringHandle         name         = String_wrap("measurement");
    DomainHandle         domain       = Domain_create(0, 1.0);
    StringHandle         default_name = String_wrap("A");
    InstrumentPortHandle port         = InstrumentPort_create_knob(
        default_name, Connection_create_barrier_gate(default_name));
    InstrumentPortHandle getter = InstrumentPort_create_meter(
        String_wrap("ohm1"), Connection_create_ohmic(String_wrap("ohm1")));
    ListLabelledDomainHandle domain_list = ListLabelledDomain_create_empty();
    ListLabelledDomain_push_back(
        domain_list, LabelledDomain_create_from_port_and_domain(port, domain));
    CoupledLabelledDomainHandle labelled_domain =
        CoupledLabelledDomain_create(domain_list);
    AxesCoupledLabelledDomainHandle axes =
        AxesCoupledLabelledDomain_create_empty();
    AxesCoupledLabelledDomain_push_back(
        axes, CoupledLabelledDomain_create(labelled_domain));
    AxesMapStringBoolHandle increasing = AxesMapStringBool_create_empty();
    MapStringBoolHandle     map        = MapStringBool_create_empty();
    MapStringBool_insert(map, default_name, true);
    AxesMapStringBool_push_back(increasing, map);
    AxesDiscretizerHandle discretizers = AxesDiscretizer_create_empty();
    AxesDiscretizer_push_back(discretizers,
                              Discretizer_create_cartesian_discretizer(0.1));
    UnitSpaceHandle     unit_space = UnitSpace_create(discretizers, domain);
    DiscreteSpaceHandle space =
        DiscreteSpace_create(unit_space, axes, increasing);
    ListPortTransformHandle transforms = ListPortTransform_create_empty();
    ListStringHandle        labels     = ListString_create_empty();
    ListString_push_back(labels, String_wrap("x"));
    AnalyticFunctionHandle analytic =
        AnalyticFunction_create(labels, String_wrap("2x[0]+1"));
    PortTransformHandle pt = PortTransform_create(port, analytic);
    ListPortTransform_push_back(transforms, pt);

    sh1 = track_quantity(Waveform_create(space, transforms));
    sh2 = track_quantity(Waveform_create(space, transforms));
  }
  WaveformHandle sh1;
  WaveformHandle sh2;
};

TEST_F(ListWaveformTest, CreateEmpty) {
  auto handle = ListWaveform_create_empty();
  EXPECT_TRUE(ListWaveform_empty(handle));
  EXPECT_EQ(ListWaveform_size(handle), 0);
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, FillValue) {
  auto handle = ListWaveform_fill_value(3, sh1);
  EXPECT_EQ(ListWaveform_size(handle), 3);
  ListWaveform_destroy(handle);
}

TEST_F(ListWaveformTest, CreateFromArray) {
  WaveformHandle     arr[2] = {sh1, sh2};
  ListWaveformHandle handle = ListWaveform_create(arr, 2);
  EXPECT_EQ(ListWaveform_size(handle), 2);
  EXPECT_THROW(ListWaveform_create(nullptr, 2), std::invalid_argument);
  ListWaveform_destroy(handle);
}

TEST_F(ListWaveformTest, SizeEmptyInvalid) {
  auto handle = ListWaveform_create_empty();
  EXPECT_EQ(ListWaveform_size(handle), 0);
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_size(nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, EmptyInvalid) {
  auto handle = ListWaveform_create_empty();
  EXPECT_TRUE(ListWaveform_empty(handle));
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_empty(nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, EraseAtClear) {
  auto handle = ListWaveform_fill_value(2, sh1);
  ListWaveform_erase_at(handle, 0);
  EXPECT_EQ(ListWaveform_size(handle), 1);
  ListWaveform_clear(handle);
  EXPECT_TRUE(ListWaveform_empty(handle));
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListWaveform_clear(nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, PushBackContainsIndex) {
  auto handle = ListWaveform_create_empty();
  ListWaveform_push_back(handle, sh1);
  EXPECT_TRUE(ListWaveform_contains(handle, sh1));
  EXPECT_EQ(ListWaveform_index(handle, sh1), 0);
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_push_back(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListWaveform_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListWaveform_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListWaveformTest, ItemsAt) {
  WaveformHandle arr[2] = {sh1, sh2};
  auto           handle = ListWaveform_create(arr, 2);
  WaveformHandle out[2];
  EXPECT_EQ(ListWaveform_items(handle, out, 2), 2);
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListWaveform_items(handle, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ListWaveform_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListWaveformTest, EqualNotEqualIntersection) {
  WaveformHandle arr[2] = {sh1, sh2};
  auto           h1     = ListWaveform_create(arr, 2);
  auto           h2     = ListWaveform_create(arr, 2);
  EXPECT_TRUE(ListWaveform_equal(h1, h2));
  EXPECT_FALSE(ListWaveform_not_equal(h1, h2));
  auto h3 = ListWaveform_intersection(h1, h2);
  EXPECT_EQ(ListWaveform_size(h3), 2);
  ListWaveform_destroy(h1);
  ListWaveform_destroy(h2);
  ListWaveform_destroy(h3);
  EXPECT_THROW(ListWaveform_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListWaveform_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListWaveform_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListWaveform_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListWaveform_intersection(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListWaveform_intersection(h1, nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, ToJsonFromJson) {
  WaveformHandle arr[1]  = {sh1};
  auto           handle  = ListWaveform_create(arr, 1);
  auto           json    = ListWaveform_to_json_string(handle);
  auto           handle2 = ListWaveform_from_json_string(json);
  EXPECT_TRUE(ListWaveform_equal(handle, handle2));
  ListWaveform_destroy(handle);
  ListWaveform_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListWaveform_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ListWaveform_from_json_string(nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, FillValueNull) {
  EXPECT_THROW(ListWaveform_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListWaveformTest, PushBackNull) {
  auto handle = ListWaveform_create_empty();
  EXPECT_THROW(ListWaveform_push_back(handle, nullptr), std::invalid_argument);
  ListWaveform_destroy(handle);
}

TEST_F(ListWaveformTest, ContainsNull) {
  auto handle = ListWaveform_create_empty();
  EXPECT_THROW(ListWaveform_contains(handle, nullptr), std::invalid_argument);
  ListWaveform_destroy(handle);
}

TEST_F(ListWaveformTest, IndexNull) {
  auto handle = ListWaveform_create_empty();
  EXPECT_THROW(ListWaveform_index(handle, nullptr), std::invalid_argument);
  ListWaveform_destroy(handle);
}

TEST_F(ListWaveformTest, CreateNullArray) {
  EXPECT_THROW(ListWaveform_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListWaveformTest, At) {
  WaveformHandle arr[2] = {sh1, sh2};
  auto           handle = ListWaveform_create(arr, 2);
  auto           at0    = ListWaveform_at(handle, 0);
  auto           at1    = ListWaveform_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListWaveform_destroy(handle);
  EXPECT_THROW(ListWaveform_at(nullptr, 0), std::invalid_argument);
}
