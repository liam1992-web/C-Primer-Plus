// values of expressions

#include <iostream>

int main()
{
    using namespace std;
    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;                //显示int值
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;                        //cout在显示bool值之前将它们转换为int
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    cout.setf(ios_base::boolalpha);                 //cout.setf(ios_base::boolalpha)函数调用设置了一个标记，该标记命令cout显示true和false，而不是0和1
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    return 0;
}
