// reading chars to end of file

#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);            //C++中新增了一种引用类型，可使得调用函数参数ch，改变其值；C语言中无法通过传递参数（而不是地址）修改原参数值
    while (cin.fail() == false)       //检测到EOF后，cin将eofbit和failbit都设置为1
    {                                 //在Windows系统中，通过<Ctrl+z><ENTER>模拟EOF
        cout << ch;         //回显
        ++count;
        cin.get(ch);          //可读取输入中的空格、制表符、换行符等
    }                       //发送给cin的输入被缓冲，这意味着只有在用户按下回车键后，它输入的内容才会被发送给程序；因此在运行程序时仍可以在#后面输入字符的原因；
                            //按下回车键后，整个字符序列被发送给程序，但程序在遇到#字符后将结束对输入的处理
    cout << endl <<count << " characters read\n";
    return 0;
}
