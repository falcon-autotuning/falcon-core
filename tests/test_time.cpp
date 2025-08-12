#include <gtest/gtest.h>
#include "falcon_core/Time.hpp"
#include "falcon_core/constants.hpp"
#include <thread>
#include <chrono>

using namespace falcon_core;

TEST(TimeTest, TimeIncreases) {
    Time t1;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Time t2;
    ASSERT_GT(t2.time(), t1.time());
}

TEST(TimeTest, Serialization) {
    Time t;
    nlohmann::json j = t.to_json();
    ASSERT_TRUE(j.contains("time"));
    ASSERT_TRUE(j.contains(constants::JSONABLE_CLASS_METADATA));
    ASSERT_EQ(j[constants::JSONABLE_CLASS_METADATA], "Time");
}
