#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

vector<int> twoSum(vector<int>& nums, int target) {
  // Two pointer approach.
  int i = 0, j = nums.size() - 1;
  while (i < j) {
    int sum = nums[i] + nums[j];
    if (sum == target) {
      return {i + 1, j + 1};
    } else if (sum > target) {
      j--;
    } else {
      i++;
    }
  }
  return {-1, -1};
}

TEST(TwoSum, TestCase1) {
  vector<int> nums = {2, 7, 11, 15};
  ASSERT_THAT(twoSum(nums, 9), ElementsAreArray({1, 2}));
}

TEST(TwoSum, TestCase2) {
  vector<int> nums = {2, 3, 4};
  ASSERT_THAT(twoSum(nums, 6), ElementsAreArray({1, 3}));
}

TEST(TwoSum, TestCase3) {
  vector<int> nums = {-1, 0};
  ASSERT_THAT(twoSum(nums, -1), ElementsAreArray({1, 2}));
}
