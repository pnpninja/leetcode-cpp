#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAreArray;

bool rowChecker(const vector<char>& row) {
  set<char> seenNos;
  for (const auto& c : row) {
    if (c == '.') {
      continue;
    }
    if (seenNos.find(c) != seenNos.end()) {
      return false;
    }
    seenNos.insert(c);
  }
  return true;
}

bool colChecker(vector<vector<char>>& board) {
  int nosRows = board.size();
  if (nosRows == 0) {
    return true;
  }
  int nosCols = board[0].size();
  for (int col = 0; col < nosCols; ++col) {
    set<char> seenNosInCol;
    for (int row = 0; row < nosRows; ++row) {
      if (board[row][col] == '.') {
        continue;
      }
      if (seenNosInCol.find(board[row][col]) != seenNosInCol.end()) {
        return false;
      }
      seenNosInCol.insert(board[row][col]);
    }
  }
  return true;
}

bool boxChecker(vector<vector<char>>& board, int startingRow, int startingCol,
                int endingRow, int endingCol) {
  set<char> seen;
  for (int row = startingRow; row <= endingRow; ++row) {
    for (int col = startingCol; col <= endingCol; ++col) {
      if (board[row][col] == '.') {
        continue;
      }

      if (seen.find(board[row][col]) != seen.end()) {
        return false;
      }
      seen.insert(board[row][col]);
    }
  }
  return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
  // Check each row.
  for (const auto& row : board) {
    if (!rowChecker(row)) {
      return false;
    }
  }

  // Check each column
  if (!colChecker(board)) {
    return false;
  }

  // Check each box
  for (int startingRow = 0; startingRow < 9; startingRow += 3) {
    int endingRow = startingRow + 2;
    for (int startingCol = 0; startingCol < 9; startingCol += 3) {
      int endingCol = startingCol + 2;
      if (!boxChecker(board, startingRow, startingCol, endingRow, endingCol)) {
        return false;
      }
    }
  }
  return true;
}

TEST(ValidSudoku, TestCase1) {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  ASSERT_TRUE(isValidSudoku(board));
}

TEST(ValidSudoku, TestCase2) {
  vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  ASSERT_FALSE(isValidSudoku(board));
}