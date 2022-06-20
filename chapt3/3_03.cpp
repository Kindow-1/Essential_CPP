#include <deque>
#include <iostream>
using namespace std;
int main()
{
    deque<int> a_line;
    int ival;
    while (cin >> ival)
    {
        // 将ival插入a_line末端
        a_line.push_back(ival);
        // 读取a_line最前端元素的值
        int curr_value = a_line.front();

        // ...进行一些操作
        deque<int>::iterator iter;
        for (iter = a_line.begin(); iter != a_line.end(); iter++)
            cout << *iter << ' ';
        cout << endl;
        //删去a_line最前端元素
        a_line.pop_front();
    }
    return 0;
}