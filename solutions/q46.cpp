#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAreArray;

void permuteUtil(vector<int>& nums, vector<vector<int>>& answers, int start, int size){
  if(start == size){
    answers.push_back(nums);
  }else{
    for(int i = start; i < nums.size(); ++i){
      swap(nums[i], nums[start]);
      permuteUtil(nums, answers, start + 1, size);
      swap(nums[i], nums[start]);
    }
  }
}

vector<vector<int>> permute(vector<int> nums){
  vector<vector<int>> ans;
  permuteUtil(nums, ans, 0, nums.size());
  return ans;
}

TEST(Permutations, TestCase1){
  vector<int> nums = {1,2,3};
  EXPECT_THAT(permute(nums), UnorderedElementsAreArray({
    ElementsAreArray({1,2,3}),
    ElementsAreArray({1,3,2}),
    ElementsAreArray({2,1,3}),
    ElementsAreArray({2,3,1}),
    ElementsAreArray({3,1,2}),
    ElementsAreArray({3,2,1}),
  }));
}