#include <vector>

#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

bool isIsomorphic(string s, string t) {
  map<char, char> st;
  map<char, char> ts;

  int len = s.length();
  for (int i = 0; i < len; ++i) {
    if ((st.find(s[i]) != st.end() && st[s[i]] != t[i]) ||
        (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])) {
      return false;
    }
    st.insert({s[i], t[i]});
    ts.insert({t[i], s[i]});
  }
  return true;
}

TEST(IsomorphicString, TestCase1){
  string s = "egg";
  string t = "add";
  EXPECT_TRUE(isIsomorphic(s,t));
}

TEST(IsomorphicString, TestCase2){
  string s = "foo";
  string t = "bar";
  EXPECT_FALSE(isIsomorphic(s,t));
}

TEST(IsomorphicString, TestCase3){
  string s = "paper";
  string t = "title";
  EXPECT_TRUE(isIsomorphic(s,t));
}