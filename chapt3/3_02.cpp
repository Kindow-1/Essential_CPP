#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template <typename IteratorType, typename elemType>
IteratorType
Find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first)
        if (value == *first)
            return first;
    return last;
}

int main()
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    // 以ia的8个元素作为list和vector的初值
    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia + asize);

    int *pia = Find(ia, ia + asize, 1024);
    if (pia != ia + asize)
        cout << "Found!" << endl;
    else
        cout << "No found!" << endl;
    vector<int>::iterator it;
    it = Find(ivec.begin(), ivec.end(), 1024);
    if (it != ivec.end())
        cout << "Found!" << endl;
    else
        cout << "No found!" << endl;
    list<int>::iterator iter;
    iter = Find(ilist.begin(), ilist.end(), 1024);
    if (iter != ilist.end())
        cout << "Found!" << endl;
    else
        cout << "No found!" << endl;
    return 0;
}