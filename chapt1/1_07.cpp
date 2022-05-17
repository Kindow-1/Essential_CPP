//读写文件
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream iofile("seq_data.txt", ios_base::in | ios_base::app);

    int num_tries = 0;
    int num_cor = 0;
    string user_name;
    cout << "Enter your name:";
    cin >> user_name;

    if (!iofile)
    {
        cerr << "Oops, unable to open session data!" << endl;
    }
    else
    {
        iofile.seekg(0);
        string name;
        int nt;
        int nc;
        iofile << "andy" << ' '
               << 11 << ' '
               << 11 << endl;

        while (iofile >> name)
        {
            iofile >> nt >> nc;
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