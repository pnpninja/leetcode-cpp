#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

string helper(string s, int start_pos, int skip1, int skip2){
  string ans;
  int index = start_pos;
  ans+=s.at(start_pos);
  while(index < s.size()){
    if(skip1 != 0){
      index+=skip1;
      if(index >= s.size()){
        return ans;
      }
      ans+=s.at(index);
    }
    if(skip2 != 0){
      index+=skip2;
      if(index >= s.size()){
        return ans;
      }
      ans+=s.at(index);
    }
  }
  return ans;
}

string convert(string s, int numRows) {
  if(numRows == 1 || s.size()==1){
    return s;
  }

  int leftGap = 2*(numRows - 1), rightGap = 0;
  int index = 0;
  string ans;
  while(leftGap >=0 && rightGap >= 0 && index < s.size()){
    ans+=helper(s, index, leftGap, rightGap);
    leftGap-=2;
    rightGap+=2;
    index++;
  }
  return ans;
  
}

TEST(ZigzagConversion, TestCase1){
  ASSERT_EQ(convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(ZigzagConversion, TestCase2){
  ASSERT_EQ(convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(ZigzagConversion, TestCase3){
  ASSERT_EQ(convert("AB", 3), "AB");
}