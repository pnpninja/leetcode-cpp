#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::UnorderedElementsAreArray;

vector<int> twoSum(vector<int>& nums, int target) {
  struct Info {
    int val;
    int index;
  };

  vector<Info> infos;
  infos.reserve(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    Info info;
    info.val = nums[i];
    info.index = i;
    infos.push_back(move(info));
  }
  sort(infos.begin(), infos.end(),
       [](const Info& lhs, const Info& rhs) { return lhs.val < rhs.val; });
  // Two pointer approach.
  int i = 0, j = infos.size() - 1;
  while (i < j) {
    if (infos[i].val + infos[j].val == target) {
      return {infos[i].index, infos[j].index};
    } else if (infos[i].val + infos[j].val > target) {
      j--;
    } else {
      i++;
    }
  }
  return {-1, -1};
}

TEST(TwoSum, TestCase1) {
  vector<int> nums = {2, 7, 11, 15};
  ASSERT_THAT(twoSum(nums, 9), UnorderedElementsAreArray({0, 1}));
}

TEST(TwoSum, TestCase2) {
  vector<int> nums = {3, 2, 4};
  ASSERT_THAT(twoSum(nums, 6), UnorderedElementsAreArray({2, 1}));
}

TEST(TwoSum, TestCase3) {
  vector<int> nums = {3, 3};
  ASSERT_THAT(twoSum(nums, 6), UnorderedElementsAreArray({1, 0}));
}
