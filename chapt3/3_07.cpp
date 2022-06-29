#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  map<string, int> words;
  words["vermeer"] = 1;
  string tword;
  //   while (cin >> tword) words[tword]++;
  map<string, int>::iterator it = words.begin();
  for (; it != words.end(); ++it)
    cout << "key: " << it->first << ' ' << "value: " << it->second << endl;
  //查询map内是否存在某个key的三种方法

  //第一种
  int count = 0;
  if (!(count = words["vermeer"]))
    cout << "it doesn't exit!" << endl;  // vermeer并不存在于words map内
  cout << count << endl;

  //第二种
  //   int count = 0;
  map<string, int>::iterator iter = words.find("vermeer");
  if (iter != words.end()) count = iter->second;
  cout << count << endl;

  //第三种
  //   int count = 0;
  string search_word("vermeer");
  if (words.count(search_word)) count = words[search_word];
  cout << count << endl;
  return 0;
}