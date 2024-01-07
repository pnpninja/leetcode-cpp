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

string minWindow(string s, string t) {
  // Size of t
  if(t.length() > s.length()){
    return "";
  }
  int remaining_count = t.size();
  int start_i = 0;
  int min_len = INT_MAX;
  int i = 0, j = 0;
  map<char, int> char_map;
  for (const auto& ch : t) {
    char_map[ch]++;
  }

  while (j < s.length()) {
    char ch = s[j];
    if (char_map[ch] > 0) {
      remaining_count--;
    }
    char_map[ch]--;

    while (remaining_count == 0) {
      int current_window = j - i + 1;
      if (current_window < min_len) {
        min_len = current_window;
        start_i = i;
      }
      char_map[s[i]]++;
      if (char_map[s[i]] > 0) {
        remaining_count++;
      }
      i++;
    }
    j++;
  }
  return min_len == INT_MAX ? "" : s.substr(start_i, min_len);
}

TEST(MinimumWindowSubstring, TestCase1){
  ASSERT_EQ(minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST(MinimumWindowSubstring, TestCase2){
  ASSERT_EQ(minWindow("a", "a"), "a");
}

TEST(MinimumWindowSubstring, TestCase3){
  ASSERT_EQ(minWindow("a", "aa"), "");
}