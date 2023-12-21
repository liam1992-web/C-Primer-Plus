#include <iostream>
const int Max = 5;
int main()
{
    using namespace std;

    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for(i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
        while(!(cin >> golf[i]))    //在输入非数字的情况下，表达式返回false
        {
            cin.clear();            //使用clear方法重置输入，如果省略这条语句，程序将拒绝继续读取输入
            while(cin.get() != '\n')        //使用cin.get()来读取行尾之前的所有输入，从而删除这一行中的错误输入
                continue;
            cout << "Pleaase enter a number: ";     //最后告诉用户输入一个数字
        }
    }

    double total = 0.0;
    for(int j = 0; j < Max; j++)
        total += golf[j];
    

    cout << total / Max << " = average score "
            << Max << " rounds\n";

    return 0;
}