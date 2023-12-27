#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;


vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> answer(nums.size());

  // Compute left side product.
  answer[0] = 1;
  for (int i = 1; i < nums.size(); ++i) {
    answer[i] = answer[i - 1] * nums[i - 1];
  }

  // Compute right side product
  int R = 1;
  for (int i = nums.size() - 1; i >= 0; --i) {
    answer[i] = answer[i] * R;
    R *= nums[i];
  }

  return answer;
}

TEST(ProductOfArrayExceptSelf, TestCase1){
  vector<int> nums = {1,2,3,4};
  ASSERT_THAT(productExceptSelf(nums), ElementsAreArray({24,12,8,6}));
}

TEST(ProductOfArrayExceptSelf, TestCase2){
  vector<int> nums = {-1,1,0,-3,3};
  ASSERT_THAT(productExceptSelf(nums), ElementsAreArray({0,0,9,0,0}));
}