//templates as parameters
#include <iostream>
#include "stacktp_14_13.h"

template <template <typename T> class Thing>    //模板类作为参数 template <typename T> class
class Crab
{
    private:
        Thing<int> s1;
        Thing<double> s2;
    public:
        Crab() {}
        bool push(int a, double x) {return s1.push(a) && s2.push(x);}
        bool pop(int & a, double & x) {return s1.pop(a) && s2.pop(x);}
        //Crab类的声明对Thing代表的模板类做了另外3个假设，即这个类包含一个push()方法，包含一个pop()方法，且这些方法由特定的接口。
        //Crab类可以使用任何与Thing类声明匹配，并包含方法push()和pop()的模板类
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula;     //Stack作为类型 - Thing - Stack<int> s1; Stack<double> s2;
                            //模板参数Thing将被替换为声明Crab对象时用作模板参数的模板类型
    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while(cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if(!nebula.push(ni, nb))
            break;
    }
    while(nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;
    cout << "Done.\n";
    return 0;
}