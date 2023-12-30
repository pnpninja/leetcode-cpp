#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::IsEmpty;
using ::testing::UnorderedElementsAreArray;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end(),
       [](const int& lhs, const int& rhs) { return lhs < rhs; });
  for (int i = 0; i < nums.size(); ++i) {
    if (i != 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int l = i + 1, r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum > 0) {
        r--;
      } else if (sum < 0) {
        l++;
      } else {
        res.push_back({nums[i], nums[l], nums[r]});
        l++;
        while (l < r && nums[l] == nums[l - 1]) {
          l++;
        }
      }
    }
  }
  return res;
}

TEST(ThreeSum, TestCase1) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  EXPECT_THAT(threeSum(nums), UnorderedElementsAreArray(
                                  {UnorderedElementsAreArray({-1, -1, 2}),
                                   UnorderedElementsAreArray({-1, 0, 1})}));
}

TEST(ThreeSum, TestCase2) {
  vector<int> nums = {0, 1, 1};
  EXPECT_THAT(threeSum(nums), IsEmpty());
}

TEST(ThreeSum, TestCase3) {
  vector<int> nums = {0, 0, 0};
  EXPECT_THAT(threeSum(nums), UnorderedElementsAreArray(
                                  {UnorderedElementsAreArray({0, 0, 0})}));
}