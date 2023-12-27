#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;

int jump(vector<int>& nums) {
  vector<int> minNosJumps;
  minNosJumps.resize(nums.size(), INT_MAX);
  minNosJumps[nums.size() - 1] = 0;
  for (int i = nums.size() - 2; i >= 0; --i) {
    if (nums[i] == 0) {
      continue;
    }
    for (int j = min(i + nums[i], int(nums.size() - 1)) ; j >= i + 1; --j) {
      if (minNosJumps[j] == INT_MAX) {
        continue;
      }
      minNosJumps[i] = min(minNosJumps[i], 1 + minNosJumps[j]);
    }
  }
  return minNosJumps[0];
}

int jumpOptimized(vector<int>& nums){
  int answer = 0, n = nums.size();
  int curEnd = 0, curFar = 0;
  for(int i =0; i < n - 1; i++){
    //Update current farthest reachable index.
    curFar = max(curFar, i + nums[i]);
    if(i == curEnd){
      answer++;
      curEnd = curFar;
    }
  }
  return answer;
}

TEST(JumpGameII, TestCase1) {
  vector<int> nums = {2, 3, 1, 1, 4};
  ASSERT_EQ(jump(nums), 2);
}

TEST(JumpGameII, TestCase2) {
  vector<int> nums = {2, 3, 0, 1, 4};
  ASSERT_EQ(jump(nums), 2);
}

TEST(JumpGameIIOptimized, TestCase1) {
  vector<int> nums = {2, 3, 1, 1, 4};
  ASSERT_EQ(jump(nums), 2);
}

TEST(JumpGameIIOptimized, TestCase2) {
  vector<int> nums = {2, 3, 0, 1, 4};
  ASSERT_EQ(jump(nums), 2);
}