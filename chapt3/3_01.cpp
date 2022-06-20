#include <iostream>
#include <vector>
#include <string>
using namespace std;

// int *find(const vector<int> &vec, int value)
// {
//     for (int ix = 0; ix < vec.size(); ++ix)
//         if (vec[ix] == value)
//             // return &vec[ix]; //出错
//             return 0;
// }

// template <typename elemType>
// elemType *find(const vector<elemType> &vec, const elemType value)
// {
//     for (int ix = 0; ix < vec.size(); ++ix)
//         if (vec[ix] == value)
//             return &vec[ix];
//     return 0;
// }

// template <typename elemType>
// elemType *find(const vector<elemType> *array, int size, const elemType &value)
// {
//     if (!array || size < 1)
//         return 0;
//     for (int ix = 0; ix < size; ++ix)
//         if (array[ix] == value)
//             return &array[ix];
//     return 0;
// }

// template <typename elemType>
// elemType *find(const vector<elemType> *array, int size, const elemType &value)
// {
//     if (!array || size < 1)
//         return 0;
//     for (int ix = 0; ix < size; ++ix, ++array)
//         if (*array == value)
//             return array;
//     return 0;
// }

template <typename elemType, typename ItType>
ItType afind(ItType first, ItType last, const elemType &value)
{
    if (!first || !last)
        return 0;
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return 0;
}

int main()
{
    int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};

    int *pi = afind(ia, ia + 8, ia[3]);
    double *pd = afind(da, da + 6, da[3]);
    string *ps = afind(sa, sa + 4, sa[3]);
    cout << *pi << endl;
    cout << *pd << endl;
    cout << *ps << endl;
    return 0;
}