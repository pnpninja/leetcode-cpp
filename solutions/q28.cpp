#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

vector<int> computeLPS(string pattern) {
  int patternLength = pattern.size();
  vector<int> lps(pattern.size());
  lps[0] = 0;

  int i = 1, len = 0;
  while (i < patternLength) {
    if (pattern.at(i) == pattern.at(len)) {
      lps[i] = ++len;
      i++;
    } else {
      if (len == 0) {
        lps[i] = 0;
        i++;
      } else {
        len = lps[len - 1];
      }
    }
  }
  return lps;
}

int strStr(string haystack, string needle) {
  int haystack_len = haystack.size(), needle_len = needle.size();
  auto lps = computeLPS(needle);
  int i = 0, j = 0;
  while (i < haystack_len) {
    if (haystack.at(i) == needle.at(j)) {
      i++;
      j++;
    } else {
      if (j == 0) {
        i += 1;
      } else {
        j = lps[j - 1];
      }
    }
    if (j == needle_len) {
      return i - needle_len;
    }
  }
  return -1;
}

TEST(LPSTest, TestCase1) {
  EXPECT_THAT(computeLPS("onions"), ElementsAreArray({0, 0, 0, 1, 2, 0}));
}

TEST(SubstringTest, TestCase1) { ASSERT_EQ(strStr("sadbutsad", "sad"), 0); }

TEST(SubstringTest, TestCase2) { ASSERT_EQ(strStr("leetcode", "leeto"), -1); }