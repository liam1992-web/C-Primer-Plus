// using the Stock calss

#include <iostream>
#include "stock10_10_4.h"

int main()
{
    {
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 20, 12.50);       //创建类对象 使用构造函数初始化 隐式
    stock1.show();      //使用类方法
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);      //显式初始化
    /*显式初始化的两种实现方式，一种与隐式方式相同，一种通过调用构造函数创建一个临时对象，然后将临时对象复制到stock2中，并丢弃它（使用析构函数）*/
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;            //对象赋值
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";     
    stock1 = Stock("Nifty Foods", 10, 50.0);        
    //对stock1进行赋值，不是初始化，实现方式是调用构造函数创建一个新的、临时的对象，将其内容赋值给stock1，然后再调用析构函数删除临时对象
    cout << "Revised stock1:\n";        //所以打打印此句之前会有析构函数的打印信息
    stock1.show();
    cout << "Done\n";
    }       //增加大括号，使得程序结束时调用析构函数在return之前，如果没有，将会在return后执行，方框限定了范围
            //最后将调用析构函数，对象存储在栈中，stock1先入栈，后打印，stock2后入栈，先打印
    return 0;
}
