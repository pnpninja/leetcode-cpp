#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;

bool canJump(vector<int>& nums) {
  vector<bool> jumpMemo(nums.size());
  jumpMemo[nums.size() - 1] = true;
  int siz = nums.size();
  for (int i = nums.size() - 1; i >= 0; --i) {
    if (i + nums[i] >= nums.size() - 1) {
      jumpMemo[i] = true;
    } else {
      bool canJumpToEnd = false;
      for (int j = std::min(i + nums[i], siz); j >= i; --j) {
        if (canJumpToEnd) {
          break;
        } else {
          canJumpToEnd = canJumpToEnd || jumpMemo[j];
        }
      }
      jumpMemo[i] = canJumpToEnd;
    }
  }
  return jumpMemo[0];
}

bool canJumpOptimized(vector<int>& nums){
  int lastGoodIndex = nums.size()-1;
  for(int i = nums.size()-2; i>=0 ; --i){
    if(i + nums[i] >= lastGoodIndex){
      lastGoodIndex = i;
    }
  }
  return lastGoodIndex == 0;
}

TEST(JumpGame, TestCase1) {
  vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_TRUE(canJump(nums));
}

TEST(JumpGame, TestCase2) {
  vector<int> nums = {3, 2, 1, 0, 4};
  EXPECT_FALSE(canJump(nums));
}

TEST(JumpGame, TestCase3) {
  vector<int> nums = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6,
                      3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0,
                      0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9,
                      3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4,
                      3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5,
                      8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
  EXPECT_FALSE(canJump(nums));
}

TEST(JumpGameOptimized, TestCase1) {
  vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_TRUE(canJumpOptimized(nums));
}

TEST(JumpGameOptimized, TestCase2) {
  vector<int> nums = {3, 2, 1, 0, 4};
  EXPECT_FALSE(canJumpOptimized(nums));
}

TEST(JumpGameOptimized, TestCase3) {
  vector<int> nums = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6,
                      3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0,
                      0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9,
                      3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4,
                      3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5,
                      8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
  EXPECT_FALSE(canJumpOptimized(nums));
}