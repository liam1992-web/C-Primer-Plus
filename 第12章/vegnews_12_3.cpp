// using new and delete with classes
#include <iostream>
using std::cout;
#include "strngbad_12_1.h"

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;

    {
        cout << "Starting an inner block.\n";

        StringBad headline1("Celery Staiks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
	
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
	
        callme2(headline2);     
        /*将headline2作为函数参数来传递，因为值传递，会先调用类的构造函数来创建对象的副本，在函数结束时由于弹栈而被销毁，导致析构函数被调用*/
        cout << "headline2: " << headline2 << endl;

        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        //等效于StringBad sailor = StringBad(sports);
        //等号右边的构造函数不同于类声明中的构造函数，它的原型是StringBad(const StringBad &)
        //当使用一个对象来初始化另一个对象时，编译器会自动生成上述构造函数，成为复制构造函数，因为它创建对象的一个副本
        /*   C++自动为类重载赋值运算符
	
        原型 Class_name & Class_name::operator=(const Class_name &);
        它接受并返回一个指向类对象的引用
        当将已有的对象赋值给另一个对象时，将使用重载的赋值运算符
        当初始化对象时，可以调用复制构造函数进行来进行初始化，也可以通过复制构造函数生成临时对象，再调用赋值运算符
        如果类成员中有指针，当成员复制导致指向同一个数据，而当一个对象调用了析构函数后，其它对象对同一个数据进行析构造成异常*/
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
