// using an inline function

#include <iostream>

inline double square(double x) { return x * x;}

int main()
{
    using namespace std;
    double a,b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);      //值传递，区别于宏的文本替换，计算的参数是12
                                // can pass expressions
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c suqred = " << square(c++) << "\n";     //递增运算，值传递
    cout << "Now c = " << c << "\n";
    return 0;
}
