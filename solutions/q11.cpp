#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

int maxArea(vector<int>& height) {
  int l = 0, r = height.size()-1;
  int res = 0;
  while(l < r){
    int area = (r - l)*(min(height[l], height[r]));
    res = max(area, res);

    if(height[l] < height[r]){
      l++;
    }else{
      r--;
    }
  }
  return res;
}

TEST(ContainerWithMostWater, TestCase1){
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  ASSERT_EQ(maxArea(height), 49);
}

TEST(ContainerWithMostWater, TestCase2){
  vector<int> height = {1,1};
  ASSERT_EQ(maxArea(height), 1);
}