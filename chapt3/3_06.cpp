#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// vector<int> filter(const vector<int> &vec, int val, less<int> &lt) {
//   vector<int> nvec;
//   vector<int>::const_iterator iter = vec.begin();
//   // bind2nd( less<int>, val);
//   //会把val绑定于less<int>的第二个参数身上
//   //于是，less<int>会将每个元素拿来和val比较
//   while ((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()) {
//     //每当iter != vec.end()
//     // iter便指向某个小于val的元素
//     nvec.push_back(*iter);
//     iter++;
//   }
// }

template <typename InputIterator, typename OutputIterator, typename ElemType,
          typename Comp>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator at, const ElemType &val, Comp pred) {
  while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
    //观察进行情形
    cout << "found value:" << *first << endl;

    //执行assign操作，然后令两个iterator前进
    *at++ = *first++;
  }
  return at;
}
int main() {
  const int elem_size = 8;
  int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
  vector<int> ivec(ia, ia + elem_size);

  //下面这个容器用来储存过滤结果
  int ia2[elem_size];
  vector<int> ivec2(elem_size);

  cout << "filtering integer array for values less than 8\n";
  filter(ia, ia + elem_size, ia2, elem_size, less<int>());

  cout << "filtering integer vector for values greater than 8\n";
  filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());
}