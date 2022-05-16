#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string user_name;
    int next_elem;
    int num_tries = 0; // 初始化,使用=运算符
    int num_cor(0);    // 初始化,构造函数语法
    int seq_index;

    const int max_tries = 3;
    const int seq_size = 18;
    const int max_seq = 6;
    const int seq_cnt = 6;

    double user_score = 0.0;
    bool next_seq = true;  // 显示下一组数列
    bool go_for_it = true; // 用户想再猜一次
    bool got_it = false;   // 用户是否猜对

    int elem_seq[seq_size] = {
        1, 2, 3,  // Fibonacci
        3, 4, 7,  // Lucas
        2, 5, 12, // Pell
        3, 6, 10, // Triangular
        4, 9, 16, // Square
        5, 12, 22 // Pentagonal
    };
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"};

    vector<int> fibonacci(elem_seq, elem_seq + 3);
    vector<int> lucas(elem_seq + 3, elem_seq + 6);
    vector<int> pell(elem_seq + 6, elem_seq + 9);
    vector<int> triangular(elem_seq + 9, elem_seq + 12);
    vector<int> square(elem_seq + 12, elem_seq + 15);
    vector<int> pentagonal(elem_seq + 15, elem_seq + 18);

    vector<int> *seq_addrs[seq_cnt] = {
        &fibonacci, &lucas, &pell,
        &triangular, &square, &pentagonal};
    vector<int> *current_vec = 0;
    srand(time(NULL));

    while (next_seq == true) // 用户想要继续猜某个数列
    {
        seq_index = rand() % seq_cnt;
        current_vec = seq_addrs[seq_index];
        // 显示数列
        cout << "The first two elements of the sequence are:"
             << (*current_vec)[0] << ","
             << (*current_vec)[1]
             << "\nWhat is the next element?";
        got_it = false;
        num_tries = 0;
        while ((got_it == false) && (go_for_it == true)) // 用户所猜不正确 && 用户想要再猜一次
        {
            int user_guess;
            cin >> user_guess;
            num_tries++;
            // 如果答案正确
            if (user_guess == (*current_vec)[2])
            {
                got_it = true;
                ++num_cor;
                cout << "Very god. Yes, "
                     << (*current_vec)[2]
                     << " is the next element in the "
                     << seq_names[seq_index] << " sequence.\n";
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
                else
                    cout << "What is the next element?";
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