// using the new operator for arrays

#include <iostream>

int main()
{
    using namespace std;
    double * p3 = new double [3];   // 动态数组
    p3[0] = 0.2;        // 将指针p3当做数组名使用
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 + 1;        // 数组名不能修改，指针p3在+1后指向数组的下一个元素
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1]<< ".\n";
    p3 = p3 - 1;
    delete [] p3;
    return 0;
}