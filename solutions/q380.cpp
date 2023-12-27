#include <cstdlib>

#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;

class RandomizedSet {
 private:
  map<int, int> dict;
  vector<int> list;

 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (dict.find(val) != dict.end()) {
      return false;
    }
    list.push_back(val);
    dict[val] = list.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (dict.find(val) == dict.end()) {
      return false;
    }
    int lastElem = list.back();
    int index = dict[val];
    list[index] = lastElem;
    dict[lastElem] = index;
    list.pop_back();
    dict.erase(val);
    return true;
  }

  int getRandom() { return list[rand() % list.size()]; }
};