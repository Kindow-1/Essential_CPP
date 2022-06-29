#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
  map<string, int> words;
  set<string> word_exclusion;
  string tword;
  while (cin >> tword) {
    if (word_exclusion.count(tword)) {
      //如果tword涵盖于“排除字集”内
      //就跳过此次迭代的剩余部分
      continue;
    }
    // ok:一旦抵达此处，表示tword并不属于“排除字集”
    words[tword]++;
  }
  return 0;
}