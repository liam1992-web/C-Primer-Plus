#include <iostream>
int main()
{
    using namespace std;
    int auks,bats,coots;

    auks = 19.99 + 11.99;           //先相加再截断

    bats = (int)19.99 + (int)11.99;     //先进行强制类型转换再相加，与上式计算结果不同
    coots = int(19.99) + int(11.99);
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";
    cout << int(ch) << endl;
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;
    return 0;
}