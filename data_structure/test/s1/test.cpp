#include "../../src/s1/q1_q2.h"
#include <gtest/gtest.h>

TEST(s1, recursive_factorial) {
  EXPECT_EQ(recursive_fac(0), 1);
  EXPECT_EQ(recursive_fac(1), 1);
  EXPECT_EQ(recursive_fac(2), 2);
  EXPECT_EQ(recursive_fac(3), 6);
  EXPECT_EQ(recursive_fac(4), 24);
  EXPECT_EQ(recursive_fac(5), 120);
  EXPECT_EQ(recursive_fac(6), 720);
  EXPECT_EQ(recursive_fac(7), 5040);
  EXPECT_EQ(recursive_fac(8), 40320);
  EXPECT_EQ(recursive_fac(9), 362880);
  EXPECT_EQ(recursive_fac(10), 3628800);
  EXPECT_EQ(recursive_fac(11), 39916800);
  EXPECT_EQ(recursive_fac(12), 479001600);
  EXPECT_EQ(recursive_fac(13), 6227020800);
  EXPECT_EQ(recursive_fac(14), 87178291200);
  EXPECT_EQ(recursive_fac(15), 1307674368000);
  EXPECT_EQ(recursive_fac(16), 20922789888000);
  EXPECT_EQ(recursive_fac(17), 355687428096000);
  EXPECT_EQ(recursive_fac(18), 6402373705728000);
  EXPECT_EQ(recursive_fac(19), 121645100408832000);
  EXPECT_EQ(recursive_fac(20), 2432902008176640000);
}

TEST(s1, iteration_fac) {
  EXPECT_EQ(iteration_fac(0), 1);
  EXPECT_EQ(iteration_fac(1), 1);
  EXPECT_EQ(iteration_fac(2), 2);
  EXPECT_EQ(iteration_fac(3), 6);
  EXPECT_EQ(iteration_fac(4), 24);
  EXPECT_EQ(iteration_fac(5), 120);
  EXPECT_EQ(iteration_fac(6), 720);
  EXPECT_EQ(iteration_fac(7), 5040);
  EXPECT_EQ(iteration_fac(8), 40320);
  EXPECT_EQ(iteration_fac(9), 362880);
  EXPECT_EQ(iteration_fac(10), 3628800);
  EXPECT_EQ(iteration_fac(11), 39916800);
  EXPECT_EQ(iteration_fac(12), 479001600);
  EXPECT_EQ(iteration_fac(13), 6227020800);
  EXPECT_EQ(iteration_fac(14), 87178291200);
  EXPECT_EQ(iteration_fac(15), 1307674368000);
  EXPECT_EQ(iteration_fac(16), 20922789888000);
  EXPECT_EQ(iteration_fac(17), 355687428096000);
  EXPECT_EQ(iteration_fac(18), 6402373705728000);
  EXPECT_EQ(iteration_fac(19), 121645100408832000);
  EXPECT_EQ(iteration_fac(20), 2432902008176640000);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
