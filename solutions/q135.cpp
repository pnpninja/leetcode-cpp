#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

int candy(vector<int> ratings) {
  if (ratings.size() <= 1) {
    return ratings.size();
  }
  int i = 1, candy = ratings.size(), n = ratings.size();
  while (i < n) {
    if (ratings[i] == ratings[i - 1]) {
      i++;
      continue;
    }
    int up = 0;
    while (ratings[i] > ratings[i - 1]) {
      up++;
      candy += up;
      i++;
      if (i == n) {
        return candy;
      }
    }
    int down = 0;
    while (i < n && ratings[i] < ratings[i - 1]) {
      down++;
      candy += down;
      i++;
    }
    candy -= min(up, down);
  }
  return candy;
}

TEST(Candy, TestCase1) { ASSERT_EQ(candy({1, 0, 2}), 5); }
TEST(Candy, TestCase2) { ASSERT_EQ(candy({1, 2, 2}), 4); }