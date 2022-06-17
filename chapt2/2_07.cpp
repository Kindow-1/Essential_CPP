#include <iostream>
#include <vector>
using namespace std;

const vector<int> *fibon_seq(int size);

int main()
{
    cout << fibon_seq(12) << endl;
    cout << fibon_seq(21) << endl;
    return 0;
}
const vector<int> *
fibon_seq(int size)
{
    const int max_size = 1024;
    static vector<int> elems;

    if (size <= 0 || size > max_size)
    {
        cerr << "fibon_seq():oops:invalid size:"
             << size << " --can't fulfill request.\n";
        return 0;
    }
    //如果size等于或小于elem.size(),
    //就不必重新计算了... ...
    if (size <= elems.size())
        return &elems;
    else
    {
        for (int ix = elems.size(); ix < size; ++ix)
        {
            if (ix == 0 || ix == 1)
                elems.push_back(1);
            else
                elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
        return &elems;
    }
}