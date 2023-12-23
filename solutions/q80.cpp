#include <vector>
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

enum State {SEEN_ONCE, SEEN_TWICE};

int removeDuplicates(vector<int> &nums) {
  int nonDupPtr = 0, dupPtr = 1;
  State state = SEEN_ONCE;
  while(dupPtr < nums.size()){
    if(nums[nonDupPtr] == nums[dupPtr]){
      if(state == SEEN_ONCE){
        nums[++nonDupPtr] = nums[dupPtr];
        state = SEEN_TWICE;
      }
    }else{
      nums[++nonDupPtr] = nums[dupPtr];
      state = SEEN_ONCE;
    }
    dupPtr++;
  }
  return nonDupPtr+1;
}

MATCHER_P(NoMoreThanOneDuplicateTill, pos, ""){
  vector<int> nums = std::move(arg);
  State state = SEEN_ONCE;
  for (int i = 1; i < pos; i++){
    if(nums[i] == nums[i-1]){
      if(state == SEEN_ONCE){
        state = SEEN_TWICE;
      }else {
        return false;
      }
    }else{
      state = SEEN_ONCE;
    }
  }
  return true;
}

TEST(RemoveDuplicatesFromSortedArrayII, TestCase1){
  vector<int> nums = {1,1,1,2,2,3};
  int expectedNum = 5;
  ASSERT_THAT(removeDuplicates(nums), expectedNum);
  ASSERT_THAT(nums, NoMoreThanOneDuplicateTill(expectedNum));
}

TEST(RemoveDuplicatesFromSortedArrayII, TestCase2){
  vector<int> nums = {0,0,1,1,1,1,2,3,3};
  int expectedNum = 7;
  ASSERT_THAT(removeDuplicates(nums), expectedNum);
  ASSERT_THAT(nums, NoMoreThanOneDuplicateTill(expectedNum));
}