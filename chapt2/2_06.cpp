#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void display(const vector<int> &vec, ostream &os = cout);
void swap(int *val1, int *val2);
void bubble_sort(vector<int> &vec, ofstream *ofil = 0);

int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);

    ofstream ofil("data.txt");
    cout << "vector before sort: ";
    display(vec);

    cout << "vector after sort: ";
    bubble_sort(vec, &ofil);
    display(vec);
    return 0;
}

void display(const vector<int> &vec, ostream &os)
{
    for (int ix = 0; ix < vec.size(); ++ix)
        os << vec[ix] << ' ';
    os << endl;
}

void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void bubble_sort(vector<int> &vec, ofstream *ofil)
{
    for (int ix = 0; ix < vec.size(); ++ix)
        for (int jx = ix + 1; jx < vec.size(); ++jx)
            if (vec[ix] > vec[jx])
            {
                if (ofil != 0)
                    (*ofil) << "about to call swap! ix: " << ix
                            << " jx: " << jx << "\tswapping: "
                            << vec[ix] << " with " << vec[jx] << endl;

                swap(vec[ix], vec[jx]);
            }
}