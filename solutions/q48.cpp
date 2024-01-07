#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for (int i = 0; i < (n + 1) / 2; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      int temp = matrix[n - 1 - j][i];
      matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
      matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
      matrix[j][n - 1 - i] = matrix[i][j];
      matrix[i][j] = temp;
    }
  }
}

TEST(RotateMatrix, TestCase1) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  ASSERT_THAT(matrix, ElementsAreArray({ElementsAreArray({7, 4, 1}),
                                              ElementsAreArray({8, 5, 2}),
                                              ElementsAreArray({9, 6, 3})}));
}