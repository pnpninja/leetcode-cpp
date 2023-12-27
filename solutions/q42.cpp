#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;

int trap(vector<int> height) {
  int l = 0, r = height.size() - 1;
  int leftMax = height[l], rightMax = height[r];
  int ans = 0;
  while (l < r) {
    if (leftMax < rightMax) {
      l++;
      leftMax = max(leftMax, height[l]);
      ans += leftMax - height[l];
    } else {
      r--;
      rightMax = max(rightMax, height[r]);
      ans += rightMax - height[r];
    }
  }
  return ans;
}

TEST(TrappingRainWater, TestCase1){
  ASSERT_EQ(trap({0,1,0,2,1,0,1,3,2,1,2,1}), 6);
}

TEST(TrappingRainWater, TestCase2){
  ASSERT_EQ(trap({4,2,0,3,2,5}), 9);
}