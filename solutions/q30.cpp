#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "limits.h"

using namespace std;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAreArray;

void permuteWordsUtil(vector<string>& words, int index,
                      vector<vector<string>>& combos) {
  if (index == words.size()) {
    combos.push_back(words);
    return;
  }
  for (int i = index; i < words.size(); ++i) {
    swap(words[i], words[index]);
    permuteWordsUtil(words, index + 1, combos);
    swap(words[i], words[index]);
  }
}

vector<vector<string>> permuteWords(vector<string>& words) {
  vector<vector<string>> combos;
  permuteWordsUtil(words, 0, combos);
  return combos;
}

vector<string> permuteWordsConcat(vector<string>& words){
  vector<vector<string>> combos = permuteWords(words);
  vector<string> concatenatedCombos = 
}

TEST(PermuteWords, TestCase1) {
  vector<string> words = {"ab", "cd"};
  EXPECT_THAT(permuteWords(words),
              UnorderedElementsAreArray({ElementsAreArray({"ab", "cd"}),
                                         ElementsAreArray({"cd", "ab"})}));
}