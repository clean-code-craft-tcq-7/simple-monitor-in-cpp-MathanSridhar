#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsAreNormal(99, 102, 70));
  ASSERT_TRUE(vitalsAreNormal(98.1, 70, 98));
}
