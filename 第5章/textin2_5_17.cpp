#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);            //C++中新增了一种引用类型，可使得调用函数参数ch，改变其值；C语言中无法通过传递参数（而不是地址）修改原参数值
    while (ch != '#')       //循环前读取第一个输入字符，这样循环可以测试第一个字符，因为第一个字符可能是#
    {
        cout << ch;         //回显
        ++count;
        cin.get(ch);          //可读取输入中的空格、制表符、换行符等
    }                       //发送给cin的输入被缓冲，这意味着只有在用户按下回车键后，它输入的内容才会被发送给程序；因此在运行程序时仍可以在#后面输入字符的原因；
                            //按下回车键后，整个字符序列被发送给程序，但程序在遇到#字符后将结束对输入的处理
    cout << endl <<count << " characters read\n";
    return 0;
}