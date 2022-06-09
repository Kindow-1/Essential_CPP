#include <iostream>
#include <vector>
using namespace std;
void display(const vector<int> &vec);
void swap(int &val1, int &val2);
void bubble_sort(vector<int> &vec);

int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);

    cout << "Vector before sort: ";
    display(vec);

    bubble_sort(vec);

    cout << "Vector after sort: ";
    display(vec);
}
void display(const vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ++ix)
        cout << vec[ix] << ' ';
    cout << endl;
}
void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}
void bubble_sort(vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ++ix)
        for (int jx = ix + 1; jx < vec.size(); ++jx)
            if (vec[ix] > vec[jx])
                swap(vec[ix], vec[jx]);
}