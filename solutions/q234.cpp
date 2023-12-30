#include <vector>

#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;
using ::testing::ElementsAreArray;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode* next) : val(x), next(next){};
};

ListNode* createLinkedList(vector<int> int_array) {
  ListNode* ptr = nullptr;
  ListNode* head = nullptr;  // Start with an empty list
  for (auto x : int_array) {
    ListNode* new_node = new ListNode(x);
    if (head == nullptr) {
      head = new_node;
    } else {
      ptr->next = new_node;
    }
    ptr = new_node;
  }
  return head;
}

vector<int> createVector(ListNode*& head) {
  vector<int> arr;
  ListNode* iter = head;
  while (iter != nullptr) {
    arr.push_back(iter->val);
    iter = iter->next;
  }
  return arr;
}
bool isPalindromeRecursive(ListNode*& current, ListNode*& front) {
  if (current != nullptr) {
    if (!isPalindromeRecursive(current->next, front)) return false;
    if (current->val != front->val) return false;
    front = front->next;
  }
  return true;
}

bool isPalindrome(ListNode* head) {
  ListNode* front = head;
  return isPalindromeRecursive(head, front);
}

ListNode* findMiddle(ListNode*& head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr != nullptr) {
    ListNode* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

bool isPalindromeNonRecursive(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return true;
  }

  // Find Middle point of linked list
  ListNode* firstHalf = findMiddle(head);
  ListNode* secondHalfReversed = reverseList(firstHalf->next);
  bool res = true;
  ListNode* p1 = head;
  ListNode* p2 = secondHalfReversed;
  while (res && p2 != nullptr) {
    if (p2->val != p1->val) {
      return false;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  firstHalf->next = reverseList(secondHalfReversed);
  return res;
}

TEST(LinkedList, TestCase1) {
  ListNode* head = createLinkedList({1, 2, 5, 4, 3});
  EXPECT_THAT(createVector(head), ElementsAreArray({1, 2, 5, 4, 3}));
}

TEST(PalindromeLinkedList, TestCase1) {
  ListNode* head = createLinkedList({1, 2, 3, 2, 1});
  ASSERT_TRUE(isPalindrome(head));
}

TEST(PalindromeLinkedList, TestCase2) {
  ListNode* head = createLinkedList({1, 2, 3, 4, 1});
  ASSERT_FALSE(isPalindrome(head));
}

TEST(PalindromeLinkedList, TestCase3) {
  ListNode* head = createLinkedList({1, 2, 2, 1});
  ASSERT_TRUE(isPalindrome(head));
}

TEST(PalindromeLinkedList, TestCase4) {
  ListNode* head = createLinkedList({1, 2, 3, 4, 1});
  ASSERT_FALSE(isPalindromeNonRecursive(head));
}

TEST(PalindromeLinkedList, TestCase5) {
  ListNode* head = createLinkedList({1, 2, 2, 1});
  ASSERT_TRUE(isPalindromeNonRecursive(head));
}