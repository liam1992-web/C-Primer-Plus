#include <iostream>

void swapr(int & a, int & b);
void swapp(int * p, int * q);
void swapv(int a, int b);

int main()
{
    using namespace std;

    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);                        //在函数声明中，可以看到参数是引用，在函数内a b称为实参的别名
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    return 0;
}

void swapr(int & a, int & b)        //函数调用时使用实参初始化引用变量（形参）
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swapv(int * p, int * q)    
{
    int temp;

    temp = *p;       //使用指针传递参数是，在交换时需要解引用（相对于引用的方式）
    *p = *q;        //右值-间接访问-内容，左值-间接访问-变量本身
    *q = temp;
}

void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}