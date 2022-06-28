#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> filter_ver1(const vector<int> &vec, int filter_value,
                        bool (*pred)(int, int)) {
  vector<int> nvec;

  for (int ix = 0; ix < vec.size(); ++ix)
    //调用pred所指函数
    //比较vec[ix]和filter_value
    if (pred(vec[ix], filter_value)) nvec.push_back(vec[ix]);
  return nvec;
}

bool less_than(int v1, int v2) { return v1 < v2 ? true : false; }
bool greater_than(int v1, int v2) { return v1 > v2 ? true : false; }

int count_occurs(const vector<int> &vec, int val) {
  vector<int>::const_iterator iter = vec.begin();
  int occurs_count = 0;
  while ((iter = find(iter, vec.end(), val)) != vec.end()) {
    ++occurs_count;
    ++iter;  //指向下一个元素
  }
  return occurs_count;
}

int main() {
  vector<int> big_vec;
  int value;
  //...填充big_vec和value
  cout << "输入value的值:";
  cin >> value;
  int num;
  cout << "输入数组数据(输入任意字母停止):" << endl;
  while (cin >> num) {
    big_vec.push_back(num);
  }
  vector<int> lt_10 = filter_ver1(big_vec, value, less_than);
  cout << "小于" << value << "的值有:";
  vector<int>::iterator iter;
  for (iter = lt_10.begin(); iter != lt_10.end(); iter++) cout << *iter << ' ';
  cout << endl;
  return 0;
}