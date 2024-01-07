#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

int minSubArrayLen(int target, vector<int>& nums) {
  int minLength = INT_MAX;
  int i = 0, j = 0, sum = 0;
  while (j < nums.size()) {
    sum += nums[j];
    while (sum >= target) {
      minLength = min(minLength, j - i + 1);
      sum -= nums[i];
      i++;
    }
    j++;
  }
  if (minLength == INT_MAX) {
    return 0;
  } else {
    return minLength;
  }
}

TEST(MinimumSizeSubarraySum, TestCase1) {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  ASSERT_EQ(minSubArrayLen(7, nums), 2);
}

TEST(MinimumSizeSubarraySum, TestCase2) {
  vector<int> nums = {1, 4, 4};
  ASSERT_EQ(minSubArrayLen(4, nums), 1);
}

TEST(MinimumSizeSubarraySum, TestCase3) {
  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(minSubArrayLen(11, nums), 0);
}