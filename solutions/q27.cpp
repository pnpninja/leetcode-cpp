#include <vector>
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;
using ::testing::ElementsAreArray;

int removeElement(vector<int> &nums, int val)
{
  int count = 0;
  int ptr1 = 0, ptr2 = 0;
  while (ptr1 != nums.size())
  {
    if (nums[ptr1] != val)
    {
      nums[ptr2++] = nums[ptr1];
      count++;
    }
    ptr1++;
  }
  return count;
}

MATCHER_P(ArrayDoesNotContain, num, ""){
  vector<int> sub_nums = std::move(arg);
  for (const auto& elem : sub_nums){
    if (elem == num){
      return false;
    }
  }
  return true;
}

TEST(RemoveElements, TestCase1)
{
  vector<int> nums = {3, 2, 2, 3};
  int expected_remove_count = 2;
  ASSERT_EQ(removeElement(nums, 3), expected_remove_count);
  vector<int> updated_nums = vector<int>(nums.begin(), nums.begin() + nums.size() - expected_remove_count);
  ASSERT_THAT(updated_nums, ArrayDoesNotContain(3));
}

TEST(RemoveElements, TestCase2)
{
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int expected_remove_count = 5;
  ASSERT_EQ(removeElement(nums, 2), expected_remove_count);
  vector<int> updated_nums = vector<int>(nums.begin(), nums.begin() + nums.size() - expected_remove_count);
  ASSERT_THAT(updated_nums, ArrayDoesNotContain(2));
}