#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0) {
    return "";
  } else if (strs.size() == 1) {
    return strs[0];
  } else {
    // Check if any string is empty;
    int smallestLength = INT_MAX;
    for (int i = 0; i < strs.size(); i++) {
      smallestLength = min(smallestLength, int(strs[i].size()));
    }
    if (smallestLength == 0) {
      return "";
    }
    string ans = "";
    for (int i = 0; i < smallestLength; ++i) {
      char match = strs[0][i];
      bool allSame = true;
      for (int j = 0; j < strs.size(); ++j) {
        allSame = allSame && (strs[j][i] == match);
      }
      if (!allSame) {
        return ans;
      } else {
        ans = ans + match;
      }
    }
    return ans;
  }
}

TEST(LongestCommonPrefix, TestCase1){
  vector<string> strs = {"flower","flow","flight"};
  ASSERT_EQ(longestCommonPrefix(strs), "fl");
}

TEST(LongestCommonPrefix, TestCase2){
  vector<string> strs = {"dog","racecar","car"};
  ASSERT_EQ(longestCommonPrefix(strs), "");
}

