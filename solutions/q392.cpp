#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

bool isSubsequence(string s, string t) {
  if (s == "") {
    return true;
  }

  int s_pointer = 0;
  int t_pointer = 0;
  while (t_pointer < t.size()) {
    if (s.at(s_pointer) == t.at(t_pointer)) {
      s_pointer++;
      if (s_pointer == s.size()) {
        break;
      }
    }
    t_pointer++;
  }
  if (s_pointer == s.size()) {
    return true;
  }
  return false;
}

bool isSubsequenceMemo(string s, string t) {
  if (s == "") {
    return true;
  }
  bool mem[s.size() + 1][t.size() + 1];
  // Row 0 is all true
  for (int i = 0; i <= t.size(); ++i) {
    mem[0][i] = true;
  }
  // Col 1 is false;
  for (int j = 1; j <= s.size(); ++j) {
    mem[j][0] = false;
  }

  // Fill the rest
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 1; j <= t.size(); ++j) {
      mem[i][j] = mem[i][j - 1];
      if (s.at(i - 1) == t.at(j - 1)) {
        mem[i][j] = mem[i][j] || mem[i - 1][j - 1];
      }
    }
  }
  return mem[s.size()][t.size()];
}

TEST(IsSubsequence, TestCase1) { ASSERT_TRUE(isSubsequence("abc", "ahbgdc")); }

TEST(IsSubsequence, TestCase2) { ASSERT_FALSE(isSubsequence("axc", "ahbgdc")); }

TEST(IsSubsequenceMemo, TestCase1) {
  ASSERT_TRUE(isSubsequenceMemo("abc", "ahbgdc"));
}

TEST(IsSubsequenceMemo, TestCase2) {
  ASSERT_FALSE(isSubsequenceMemo("axc", "ahbgdc"));
}