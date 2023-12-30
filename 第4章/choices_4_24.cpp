// array variations

#include <iostream>
#include <vector>
#include <array>

int main()
{
    using namespace std;

    double a1[4] = {1.2, 2.4, 3.6, 4.8};            //数组存储在栈中

    vector<double> a2(4);           //vector对象定义方式 使用()
    a2[0] = 1.0/3.0;                //存储在自由存储区
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3]= 1.0/9.0;

    array<double,4> a3 = {3.14, 2.72, 1.62, 1.41};      //存储在栈中
    array<double,4> a4;
    a4 = a3;                    //可以将一个array对象赋值给另一个array对象
                                //数组无法这样赋值
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;     //无论是数组、array对象、vector对象，都可以使用标准数组表示法来访问各个元素
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}

//C++ 不检查数组的越界，vector和array对象都是如此，但是可以在array和vector对象使用成员函数at()，它可以在运行期间捕获非法索引，程序默认将中断。可以使用成员函数begin()和end()来确定边界。
