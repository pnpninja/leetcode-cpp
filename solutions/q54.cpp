#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  if (rows == 0) {
    return {};
  }
  int cols = matrix[0].size();
  if (cols == 0) {
    return {};
  }
  int left = 0, right = cols - 1;
  int top = 0, bottom = rows - 1;
  vector<int> ans;
  ans.reserve(rows * cols);
  while (left <= right && top <= bottom) {
    // Extract top row
    for (int i = left; i <= right; ++i) {
      ans.push_back(matrix[top][i]);
    }
    top++;
    // Extract right column
    for (int i = top; i <= bottom; ++i) {
      ans.push_back(matrix[i][right]);
    }
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; --i) {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  return ans;
}

TEST(SpiralMatrix, TestCase1) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ASSERT_THAT(spiralOrder(matrix),
              ElementsAreArray({1, 2, 3, 6, 9, 8, 7, 4, 5}));
}

TEST(SpiralMatrix, TestCase2) {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  ASSERT_THAT(spiralOrder(matrix),
              ElementsAreArray({1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
}