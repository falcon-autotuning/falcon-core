#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#define PAIR_T1 int
#define PAIR_T2 int
#include "falcon_core/generic/PairIntInt_c_api.h"

TEST(Pairintint, Construction) {
  PairIntIntHandle pair = PairIntInt_create(42, 7);
  EXPECT_EQ(PairIntInt_first(pair), 42);
  EXPECT_EQ(PairIntInt_second(pair), 7);
  PairIntInt_destroy(pair);  // Clean up
}
