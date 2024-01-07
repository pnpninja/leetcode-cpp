#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
  map<char, int> charToLastIndex;
  int i = 0, j = 0;
  int maxLen = INT_MIN;
  if (s.size() <= 1) {
    return s.size();
  }
  while (j < s.size()) {
    // Keep inserting till no duplicates.
    while (j < s.size() &&
           charToLastIndex.find(s.at(j)) == charToLastIndex.end()) {
      charToLastIndex.insert({s.at(j), j});
      maxLen = max(maxLen, j - i + 1);
      j++;
    }

    // Duplicate found. Move i to location past duplicate.
    if (j < s.size()) {
      int lastIndex = charToLastIndex[s.at(j)];
      while (i <= lastIndex) {
        charToLastIndex.erase(s.at(i));
        i++;
      }

      charToLastIndex.insert({s.at(j), j});
      j++;
    }
  }
  if (maxLen == INT_MIN) {
    return 0;
  }
  return maxLen;
}

TEST(LongestSubstringWithoutRepeatingCharacters, TestCase1){
  ASSERT_EQ(lengthOfLongestSubstring("abcabcbb"),3);
}

TEST(LongestSubstringWithoutRepeatingCharacters, TestCase2){
  ASSERT_EQ(lengthOfLongestSubstring("bbbbb"),1);
}

TEST(LongestSubstringWithoutRepeatingCharacters, TestCase3){
  ASSERT_EQ(lengthOfLongestSubstring("pwwkew"),3);
}