//forcing type changes

#include <iostream>
int main()
{
    using namespace std;
    int auks,bats,coots;

    // the following statement adds the values as double, then converts the result to int
    auks = 19.99 + 11.99;           //先相加再截断

    // these statements add values as int
    bats = (int)19.99 + (int)11.99;     //old C syntax 先进行强制类型转换再相加，与上式计算结果不同
    coots = int(19.99) + int(11.99);    //new C++ syntax
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // print as char
    cout << int(ch) << endl;                    // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;       // using static_cast
    return 0;
}
