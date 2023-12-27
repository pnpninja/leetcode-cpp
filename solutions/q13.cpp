#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

map<char, int> valueMap = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};
map<char, char> lookbackMap = {
    {'V', 'I'}, {'X', 'I'}, {'L', 'X'}, {'C', 'X'}, {'D', 'C'}, {'M', 'C'},
};

int romanToInt(string s) {
  int val = 0;
  int ptr = s.size();
  while (ptr >= 0) {
    val += valueMap[s[ptr]];
    if (ptr - 1 >= 0) {
      auto iter = lookbackMap.find(s[ptr]);
      if (iter != lookbackMap.end() && iter->second == s[ptr - 1]) {
        val -= valueMap[s[ptr - 1]];
        ptr -= 2;
      } else {
        ptr--;
      }
    } else {
      ptr -= 1;
    }
  }
  return val;
}

TEST(RomanToInteger, TestCase1){
  ASSERT_EQ(romanToInt("III"), 3);
}

TEST(RomanToInteger, TestCase2){
  ASSERT_EQ(romanToInt("LVIII"), 58);
}
TEST(RomanToInteger, TestCase3){
  ASSERT_EQ(romanToInt("MCMXCIV"), 1994);
}