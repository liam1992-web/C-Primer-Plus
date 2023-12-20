//unwinding the stack
#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean_15_10.h"

class demo
{
    private:
        std::string  word;
    public:
        demo(const std::string & str)
        {
            word = str;
            std::cout << "demo " << word << " created\n";
        }
        ~demo()
        {
            std::cout << "demo " << word << " destroyed\n";
        }
        void show() const
        {
            std::cout << "demo " << word << " lives!\n";
        }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    {
        demo d1("found in block in main() ");   //调用构造函数
        cout << "Enter two numbers: ";
        while(cin >> x >> y)
        {
            try {
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
                cout << "Enter next pair: ";
                }  //代码块中表明需要注意这些代码引发的异常，try块后跟catch块/特定的异常可能被激活的代码块
            catch(bad_hmean & bg)   //catch关键字表示捕获异常，括号中为类型声明，指出了异常处理程序要相应的异常类型
            {
                bg.mesg();
                cout << "Try again.\n";
                continue;
            }
            catch(bad_gmean & hg)
            {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }
        }
        d1.show();
    }
    cout << "Bye!\n";
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch(bad_hmean & bg)
    {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;  //上述代码显示消息后，重新引发异常，这将向上把异常发送给main()函数
        //一般而言，重新引发的异常将由下一个捕获这种异常的try-catch块组合进行处理，如果没有找到这样的处理程序，默认情况下程序将异常终止。
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}