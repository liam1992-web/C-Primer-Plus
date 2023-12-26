// the char type

#include <iostream>
int main()
{
    using namespace std;
    char ch;

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;    //存储在ch中的是数值/字符编码，输出时cout根据变量类型将其转换为字符
    return 0;
}
