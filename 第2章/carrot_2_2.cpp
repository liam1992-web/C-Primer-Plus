//food processing program
//uses and displays a variable
#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    carrots = 25;
    cout << "I have ";
    cout << carrots;        //cout可用于数字和字符串，<< output运算符将根据其后的数据类型相应地调整其行为，这是一个运算符重载的例子
    cout << " carrots.";
    cout << endl;
    carrots = carrots - 1;
    cout << "Crunch, crunch.Now I have " << carrots << " carrots." << endl;
    return 0;
}