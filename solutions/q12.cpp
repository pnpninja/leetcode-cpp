#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                     "D", "DC", "DCC", "DCCC", "CM"};
string thousands[] = {"", "M", "MM", "MMM"};
string intToRoman(int num) {
  return thousands[num / 1000] + hundreds[num % 1000 / 100] +
         tens[num % 100 / 10] + ones[num % 10];
}

TEST(IntegerToRoman, TestCase1) { ASSERT_EQ(intToRoman(3), "III"); }

TEST(IntegerToRoman, TestCase2) { ASSERT_EQ(intToRoman(58), "LVIII"); }

TEST(IntegerToRoman, TestCase3) { ASSERT_EQ(intToRoman(1994), "MCMXCIV"); }
