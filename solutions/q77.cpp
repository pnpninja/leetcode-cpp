#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAreArray;

void generateAllCombinationsUtil(vector<int>& nums, vector<int>& current,
                                 int index, vector<vector<int>>& results) {
  if (index == nums.size()) {
    results.push_back(current);
    return;
  }

  generateAllCombinationsUtil(nums, current, index + 1, results);
  current.push_back(nums[index]);
  generateAllCombinationsUtil(nums, current, index + 1, results);
  current.pop_back();
}

void generateAllCombinationsOfSizeUtil(vector<int>& nums, vector<int>& current,
                                       int index, vector<vector<int>>& results,
                                       int combo_size) {
  if (index == nums.size()) {
    if (current.size() == combo_size) {
      results.push_back(current);
    }
    return;
  }

  generateAllCombinationsOfSizeUtil(nums, current, index + 1, results,
                                    combo_size);
  current.push_back(nums[index]);
  generateAllCombinationsOfSizeUtil(nums, current, index + 1, results,
                                    combo_size);
  current.pop_back();
}

vector<vector<int>> generateAllCombinations(vector<int>& numbers) {
  vector<vector<int>> results;
  vector<int> current;
  generateAllCombinationsUtil(numbers, current, 0, results);
  return results;
}

vector<vector<int>> generateAllCombinationsOfSize(vector<int>& numbers, int k) {
  vector<vector<int>> results;
  vector<int> current;
  generateAllCombinationsOfSizeUtil(numbers, current, 0, results, k);
  return results;
}

vector<vector<int>> combine(int n, int k) {
  vector<int> numbers(n, 0);
  for (int i = 0; i < n; ++i) {
    numbers[i] = i + 1;
  }
  return generateAllCombinationsOfSize(numbers, k);
}

TEST(GenerateAllCombinations, TestCase1) {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> expectedCombinations = {
      {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}};
  EXPECT_THAT(generateAllCombinations(nums),
              UnorderedElementsAreArray(expectedCombinations));
}

TEST(GenerateAllCombinationsOfSize, TestCase1) {
  vector<int> nums = {1, 2, 3, 4};
  vector<vector<int>> expectedCombinations = {{1, 2}, {1, 3}, {1, 4},
                                              {2, 3}, {2, 4}, {3, 4}};
  EXPECT_THAT(generateAllCombinationsOfSize(nums, 2),
              UnorderedElementsAreArray(expectedCombinations));
}

TEST(GenerateAllCombinationsOfSize, TestCase2) {
  vector<vector<int>> expectedCombinations = {{1, 2}, {1, 3}, {1, 4},
                                              {2, 3}, {2, 4}, {3, 4}};
  EXPECT_THAT(combine(4, 2),
              UnorderedElementsAreArray(expectedCombinations));
}