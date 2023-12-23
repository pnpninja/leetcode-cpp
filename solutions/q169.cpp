#include <vector>

#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;
using ::testing::ElementsAreArray;

int majorityElement(vector<int> &nums) {
  if(nums.size() == 1){
    return nums[0];
  }
  int majorityElement = nums[0], count = 1;
  for(int i = 1; i < nums.size(); ++i){
    count+= (nums[i] == majorityElement) ? 1 : -1;
    if(count == 0){
      majorityElement = nums[i];
      count = 1;
    }
  }
  return majorityElement;
}

TEST(MajorityElement, TestCase1){
  vector<int> nums = {3,2,3};
  ASSERT_EQ(majorityElement(nums), 3);
}

TEST(MajorityElement, TestCase2){
  vector<int> nums = {2,2,1,1,1,2,2};
  ASSERT_EQ(majorityElement(nums), 2);
}