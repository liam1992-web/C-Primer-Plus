// reading chars with a while loop

#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while (ch != '#')       //循环前读取第一个输入字符，这样循环可以测试第一个字符，因为第一个字符可能是#
    {
        cout << ch;         //回显
        ++count;
        //cout << '\n';
        cin >> ch;          //cin在读取char值时，与读取其他基本类型一样，cin将忽略空格和换行符，因此输入中的空格没有被回显，也没有被包括在计数内
    }                       //发送给cin的输入被缓冲，这意味着只有在用户按下回车键后，它输入的内容才会被发送给程序；因此在运行程序时仍可以在#后面输入字符的原因；
                            //按下回车键后，整个字符序列被发送给程序，但程序在遇到#字符后将结束对输入的处理
    cout << endl <<count << " characters read\n";
    return 0;
}
