#include <iostream>
#include <string>
using namespace std;

int main()
{
    string user_name;
    int next_elem;
    int num_tries = 0; // 初始化,使用=运算符
    int num_right(0);  // 初始化,构造函数语法
    const int max_tries = 3;
    double user_score = 0.0;
    bool next_seq = true;  // 显示下一组数列
    bool go_for_it = true; // 用户想再猜一次
    bool got_it = false;   // 用户是否猜对

    while (next_seq == true) // 用户想要继续猜某个数列
    {
        // 显示数列
        got_it = false;
        num_tries = 0;
        while ((got_it == false) && (go_for_it == true)) // 用户所猜不正确 && 用户想要再猜一次
        {
            int user_guess;
            cin >> user_guess;
            num_tries++;
            // 如果答案正确
            if (user_guess == next_elem)
            {
                got_it = true;
                num_right++;
            }
            else
            {
                // 如果答案错误
                switch (num_tries)
                {
                case 1:
                    cout << "Oops! Nice guess but not quite it.\n";
                    break;
                case 2:
                    cout << "Hmm. Sorry. Wrong a second time.\n";
                    break;
                case 3:
                    cout << "Ah, this is harder than it looks, isn't it?\n";
                    break;
                default:
                    cout << "It must be getting pretty frustrating by now!\n";
                    break;
                }
                cout << "Want to try again? (Y/N)" << endl;
                char user_rsp;
                cin >> user_rsp;
                if (user_rsp == 'N' || user_rsp == 'n')
                    go_for_it = false;
            }
        } //内层的while循环结束
        cout << "Want to try another sequence? (Y/N)";
        char try_again;
        cin >> try_again;

        if (try_again == 'N' || try_again == 'n')
            next_seq = false;
    }
    return 0;
}