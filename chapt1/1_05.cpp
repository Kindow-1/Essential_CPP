//写文件
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int num_tries = 0;
    int num_cor = 0;
    ofstream outfile("seq_data.txt", ios_base::app);

    cout << "Enter your name:";
    cin >> name;
    cout << "Enter your num_tries,num_cor:";
    cin >> num_tries >> num_cor;
    if (!outfile)
    {
        cerr << "Oops, unable to save session data!" << endl;
    }
    else
    {
        outfile << name << ' '
                << num_tries << ' '
                << num_cor << endl;
    }
    return 0;
}