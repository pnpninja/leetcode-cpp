#include <vector>

#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

using namespace std;
using ::testing::ElementsAreArray;

void swap(int &a, int &b){
  a = a + b;
  b = a - b;
  a = a - b;
}

void reverse(vector<int>& nums, int start, int end){
  while(start < end){
    swap(nums[start++], nums[end--]);
  }
}

void rotate(vector<int>& nums, int k){
  k = k % nums.size();
  int pivot = nums.size() - k;
  reverse(nums, pivot, nums.size()-1);
  reverse(nums, 0, pivot - 1);
  reverse(nums, 0 , nums.size() - 1);
}

TEST(RotateArray, TestCase1){
  vector<int> nums = {1,2,3,4,5,6,7};
  rotate(nums, 3);
  ASSERT_THAT(nums, ElementsAreArray({5,6,7,1,2,3,4}));
}

TEST(RotateArray, TestCase2){
  vector<int> nums = {-1,-100,3,99};
  rotate(nums, 2);
  ASSERT_THAT(nums, ElementsAreArray({3,99,-1,-100}));
}