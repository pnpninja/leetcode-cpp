#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

string reverseWords(string s) {
  vector<string> words;
  int start_index = 0, end_index = s.size() - 1;

  // Skip starting spaces.
  while (start_index < s.size() && s.at(start_index) == ' ') {
    start_index++;
  }

  // Skip ending spaces
  while (end_index >= 0 && s.at(end_index) == ' ') {
    end_index--;
  }
  vector<string> ans;

  while (start_index <= end_index) {
    if (s.at(start_index) == ' ') {
      start_index++;
      continue;
    } else {
      // Extract word
      int len = 0, start_index_temp = start_index;
      while (start_index_temp <= end_index && s.at(start_index_temp) != ' ') {
        len++;
        start_index_temp++;
      }
      ans.push_back(s.substr(start_index, len));
      start_index = start_index_temp;
    }
  }

  string anss;
  for(int i = ans.size()-1; i >= 1; --i){
    anss+=ans.at(i) + " ";
  }
  anss+=(ans.at(0));
  return anss;
}

TEST(ReverseWordsInAString, TestCase1) {
  ASSERT_EQ(reverseWords("the sky is blue"), "blue is sky the");
}

TEST(ReverseWordsInAString, TestCase2){
  ASSERT_EQ(reverseWords("a good   example"), "example good a");
}