
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

using namespace std;
using ::testing::ElementsAreArray;

int maxProfit(vector<int>& prices) {
  int profit = 0;
  for(int i = 1; i< prices.size(); ++i){
    if(prices[i] > prices[i-1]){
      profit+=prices[i] - prices[i-1];
    }
  }
  return profit;
}

TEST(BestTimeToBuyAndSellStockII, TestCase1){
  vector<int> prices = {7,1,5,3,6,4};
  ASSERT_EQ(maxProfit(prices), 7);
}

TEST(BestTimeToBuyAndSellStockII, TestCase2){
  vector<int> prices = {1,2,3,4,5};
  ASSERT_EQ(maxProfit(prices), 4);
}

TEST(BestTimeToBuyAndSellStockII, TestCase3){
  vector<int> prices = {7,6,4,3,1};
  ASSERT_EQ(maxProfit(prices), 0);
}