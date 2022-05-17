//读文件
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("seq_data.txt");

    int num_tries = 0;
    int num_cor = 0;
    string user_name;
    cout << "Enter your name:";
    cin >> user_name;

    if (!infile)
    {
        cerr << "Oops, unable to save session data!" << endl;
    }
    else
    {
        string name;
        int nt;
        int nc;

        while (infile >> name)
        {
            infile >> nt >> nc;
            if (name == user_name)
            {
                cout << "Welcome back, " << user_name
                     << "\nYour current sore is " << nc
                     << " out of " << nt << "\nGood Luck!\n";

                num_tries = nt;
                num_cor = nc;
            }
        }
    }
    return 0;
}