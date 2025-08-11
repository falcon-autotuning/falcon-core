#include <gtest/gtest.h>
#include "falcon_core/Time.hpp"
#include <chrono>

TEST(TimeTest, GetTime) {
    falcon_core::Time t;
    auto now_manual = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    ASSERT_NEAR(t.time(), now_manual, 1);
}
