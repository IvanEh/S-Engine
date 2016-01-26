#include <gtest/gtest.h>

#include <iostream>

using namespace std;

TEST(TestTest, AlwaysTrue) {

  EXPECT_EQ(1, 2);
 
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
