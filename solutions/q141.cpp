#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
  if (head == nullptr) {
    return false;
  }
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}
