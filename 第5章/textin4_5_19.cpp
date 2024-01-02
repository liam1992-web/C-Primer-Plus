// reading chars with cin.get()

#include <iostream>

int main(void)
{
    using namespace std;
    int ch;
    int count = 0;
    while ((ch = cin.get()) != EOF)       // cin.get()返回字符编码，接收的变量不能使用char类型，否则无法接受EOF
    {                                 //在Windows系统中，通过<Ctrl+z><ENTER>模拟EOF
        cout.put(char(ch));         //回显，cout.put(char)参数类型为char，故需要进行强制类型转换
        ++count;
    }                       //发送给cin的输入被缓冲，这意味着只有在用户按下回车键后，它输入的内容才会被发送给程序；因此在运行程序时仍可以在#后面输入字符的原因；
                            //按下回车键后，整个字符序列被发送给程序，但程序在遇到#字符后将结束对输入的处理
    cout << endl << count << " characters read\n";
    return 0;
}
