#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

int sum(vector<int>& vec){
  int res = 0;
  for(const auto& num : vec){
    res+= num;
  }
  return res;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  if(sum(gas) - sum(cost) < 0){
    return -1;
  }
  int ans = 0, runningTotal = 0;
  for(int i; i < gas.size(); ++i){
    runningTotal+= gas[i] - cost[i];
    if(runningTotal < 0){
      runningTotal = 0;
      ans = i + 1;
    }
  }
  return ans;
}

TEST(GasStation, TestCase1){
  vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
  ASSERT_EQ(canCompleteCircuit(gas, cost), 3);
}

TEST(GasStation, TestCase2){
  vector<int> gas = {2,3,4}, cost = {3,4,3};
  ASSERT_EQ(canCompleteCircuit(gas, cost), -1);
}