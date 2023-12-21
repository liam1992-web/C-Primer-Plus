//using an exception
#include <iostream>

double hmean(double a, double b);

int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y)
    {
        try {z = hmean(x, y);}  //代码块中表明需要注意这些代码引发的异常，try块后跟catch块/特定的异常可能被激活的代码块
        catch(const char * s)   //catch关键字表示捕获异常，括号中为类型声明，指出了异常处理程序要相应的异常类型
        {
            std::cout << s <<std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
        throw "bad hmean() arguments: a = -b not allowed";//使用throw语句引发异常
    return 2.0 * a * b / (a + b);
}