#include <vector>
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

int removeDuplicates(vector<int> &nums) {
  int nonDupPtr = 0, dupPtr = 0;
  while(dupPtr < nums.size()){
    if(nums[nonDupPtr] != nums[dupPtr]){
      nums[++nonDupPtr] = nums[dupPtr];
    }
    dupPtr++;
  }
  return nonDupPtr+1;
}

MATCHER_P(NoDuplicatesTill, pos, ""){
  vector<int> nums = std::move(arg);
  for (int i = 1; i < pos; i++){
    if(nums[i] == nums[i-1]){
      return false;
    }
  }
  return true;
}

TEST(RemoveDuplicatesFromSortedArray, TestCase1){
  vector<int> nums = {1,1,2};
  int expectedNum = 2;
  ASSERT_THAT(removeDuplicates(nums), expectedNum);
  ASSERT_THAT(nums, NoDuplicatesTill(expectedNum));
}

TEST(RemoveDuplicatesFromSortedArray, TestCase2){
  vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  int expectedNum = 5;
  ASSERT_THAT(removeDuplicates(nums), expectedNum);
  ASSERT_THAT(nums, NoDuplicatesTill(expectedNum));
}