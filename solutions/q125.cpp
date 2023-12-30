
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

using namespace std;
using ::testing::ElementsAreArray;

bool isPalindrome(string s){
  if(s.size()==1){
    return true;
  }
  int i = 0, j = s.size()-1;
  while(i < j){
    while(i < j && !isalnum(s.at(i))){
      i++;
    }
    while(i < j && !isalnum(s.at(j))){
      j--;
    }
    if(i < j && tolower(s.at(i)) != tolower(s.at(j))){
      return false;
    }
    i++;
    j--;
  }
  return true;
}

TEST(ValidPalindrome, TestCase1){
  ASSERT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(ValidPalindrome, TestCase2){
  ASSERT_FALSE(isPalindrome("race a car"));
}

TEST(ValidPalindrome, TestCase3){
  ASSERT_TRUE(isPalindrome(" "));
}