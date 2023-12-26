
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

using namespace std;
using ::testing::ElementsAreArray;

int maxProfit(vector<int>& prices) {
  int minPrice = INT_MAX, maxProfit = 0;
  for(const auto& price : prices){
    if(price < minPrice){
      minPrice = price;
    }else if(price - minPrice > maxProfit){
      maxProfit = price - minPrice;
    }
  }
  return maxProfit;
}

TEST(BestTimeToBuyAndSellStock, TestCase1){
  vector<int> prices = {7,1,5,3,6,4};
  ASSERT_EQ(maxProfit(prices), 5);
}

TEST(BestTimeToBuyAndSellStock, TestCase2){
  vector<int> prices = {7,6,4,3,1};
  ASSERT_EQ(maxProfit(prices), 0);
}