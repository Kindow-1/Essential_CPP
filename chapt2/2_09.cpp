#include <iostream>
#include <vector>
using namespace std;

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec);

int main()
{
    string msg = "Hello ";
    vector<int> ivec;
    vector<string> svec;

    ivec.push_back(1);
    ivec.push_back(2);
    svec.push_back("hty");
    svec.push_back("ph");

    display_message(msg, ivec);
    display_message(msg, svec);
    return 0;
}

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec)
{
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        elemType t = vec[ix];
        cout << t << ' ';
    }
    cout << endl;
}