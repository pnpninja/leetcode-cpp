
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"
#include "glog/logging.h"
#include "glog/stl_logging.h"

using namespace std;
using ::testing::ElementsAreArray;

vector<vector<vector<int>>> mem;

int recursion(vector<int>& prices, int index, int nos_transactions, bool bought){
  if(nos_transactions <= 0 || index>= prices.size()){
    return 0;
  }
  if(mem[bought][nos_transactions][index] != -1){
    return mem[bought][nos_transactions][index];
  }

  int result = recursion(prices, index+1, nos_transactions, bought);
  if(bought){
    result = max(result, recursion(prices, index+1, nos_transactions-1, false)+prices[index]);
  }else{
    result = max(result, recursion(prices, index+1, nos_transactions, true)-prices[index]);
  }
  return result;
}

int maxProfit(vector<int>& prices) {
  // Using recursion and memoization.
  // mem.resize(2,vector<vector<int>>(3, vector<int>(prices.size(), -1)));
  // return recursion(prices, 0, 2, false);

  // Using optimized approach;
  int minLeft = prices[0], maxRight = prices[prices.size() - 1];
  vector<int> leftProfit(prices.size()), rightProfit(prices.size());

  // Fill 1st transaction.
  for(int i = 1; i < prices.size(); ++i){
    leftProfit[i] = max(leftProfit[i-1], prices[i] - minLeft);
    minLeft = min(minLeft, prices[i]);
  }

  // Fill 2nd transaction.
  for(int i = prices.size()-2; i >=0 ; --i){
    rightProfit[i] = max(rightProfit[i+1], maxRight - prices[i]);
    maxRight = max(maxRight, prices[i]);
  }

  int profit = rightProfit[0];
  for(int i = 1; i < prices.size(); ++i){
    profit = max(profit, leftProfit[i-1]+ rightProfit[i]);
  }
  return profit;
  
}

TEST(BestTimeToBuyAndSellStockIII, TestCase1){
  vector<int> prices = {3,3,5,0,0,3,1,4};
  ASSERT_EQ(maxProfit(prices), 6);
}

TEST(BestTimeToBuyAndSellStockIII, TestCase2){
  vector<int> prices = {1,2,3,4,5};
  ASSERT_EQ(maxProfit(prices), 4);
}

TEST(BestTimeToBuyAndSellStockIII, TestCase3){
  vector<int> prices = {7,6,4,3,1};
  ASSERT_EQ(maxProfit(prices), 0);
}