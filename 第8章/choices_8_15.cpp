// choising a template

#include <iostream>

template <class T>
T lesser(T a, T b)          //#1
{
    return a < b ? a : b;
}

int lesser(int a, int b)        //#2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;

    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;       //use #2
    cout << lesser(x, y) << endl;       //use #1
    cout << lesser<>(m, n) << endl;     //use #1 with int !! 句子中的<>指出，编译器应该选择模板函数，而不是非模板函数；
    cout << lesser<int>(x, y) << endl;  //use #1 with int !!    显式实例化，在程序中使用函数来创建显式实例化

    return 0;

}
