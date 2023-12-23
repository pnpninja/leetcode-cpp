#include <vector>
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;
using ::testing::ElementsAreArray;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int nums2_ptr = n - 1, nums1_ptr = m - 1, combined_ptr = m + n -1;
  while (nums2_ptr >= 0 && nums1_ptr >= 0){
    if (nums1[nums1_ptr] >= nums2[nums2_ptr]){
      nums1[combined_ptr--] = nums1[nums1_ptr--];
    }else {
      nums1[combined_ptr--] = nums2[nums2_ptr--];
    }
  }

  while(nums1_ptr >= 0){
    nums1[combined_ptr--] = nums1[nums1_ptr--];
  }
  while(nums2_ptr >= 0){
    nums1[combined_ptr--] = nums2[nums2_ptr--];
  }

}

TEST(MergeSortedArray, TestCase1){
  vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
  merge(nums1, 3, nums2, 3);
  ASSERT_THAT(nums1, ElementsAreArray({1,2,2,3,5,6}));
}

TEST(MergeSortedArray, TestCase2){
  vector<int> nums1 = {1}, nums2 = {};
  merge(nums1, 1, nums2, 0);
  ASSERT_THAT(nums1, ElementsAreArray({1}));
}

TEST(MergeSortedArray, TestCase3){
  vector<int> nums1 = {0}, nums2 = {1};
  merge(nums1, 0, nums2, 1);
  ASSERT_THAT(nums1, ElementsAreArray({1}));
}