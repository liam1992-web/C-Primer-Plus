// using the Vector class

#include <iostream>
#include <cstdlib>	// rand(), srand() prototypes
#include <ctime>	// time() prototype
#include "vector_11_13.h"

int main()
{
    using namespace std;
    using  VECTOR::Vector;      //使用using声明导入了Vector，导入类名称
                                //因此可使用Vector::POL,而不必使用VECTOR::Vector::POL
    srand(time(0));		// seed random-number generator

    double direction;
    Vector step;                    //矢量 新的方向，用于与result相加
    Vector result(0.0, 0.0);        //记录行走者的前进情况
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Enter target distance (q to quit): ";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))       
            break;
        
        while(result.magval() < target)     //当result超过指定的距离后，该循环结束
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;     //运算符重载 调用构造函数 默认使用RECT模式
            steps++;
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);

        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;

    return 0;
}
