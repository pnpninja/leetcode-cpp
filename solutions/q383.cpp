#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

bool canConstruct(string ransomNote, string magazine) {
  vector<int> arr(26, 0);
  for (const char c : ransomNote) {
    arr[c - 97]--;
  }
  for (const char c : magazine) {
    arr[c - 97]++;
  }
  for (int i = 0; i < 26; ++i) {
    if (arr[i] < 0) {
      return false;
    }
  }
  return true;
}

TEST(RansomNote, TestCase1){
  string ransomNote = "a", magazine = "b";
  EXPECT_FALSE(canConstruct(ransomNote, magazine));
}

TEST(RansomNote, TestCase2){
  string ransomNote = "aa", magazine = "ab";
  EXPECT_FALSE(canConstruct(ransomNote, magazine));
}

TEST(RansomNote, TestCase3){
  string ransomNote = "aa", magazine = "aab";
  EXPECT_TRUE(canConstruct(ransomNote, magazine));
}