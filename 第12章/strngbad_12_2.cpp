#include <cstring>
#include "strngbad_12_1.h"

using std::cout;

int StringBad::num_strings = 0;
/*将静态成员初始化为0，不能再类声明中初始化静态成员变量，因为声明描述了如何分配内存，但并不分配内存
通过这种格式来创建对象，从而分配和初始化内存
对于静态类成员，可在类声明之外使用单独的语句来进行初始化，这是因为静态类成员是单独存储的，而不是对象的组成部分
初始化语句指出了类型，并使用了作用域运算符，但没有使用关键字static*/

/*静态数据成员在类声明中声明，在包含类方法的文件中初始化
初始化时使用作用域运算符来指出静态成员所属的类
如果静态成员是整型或枚举型const，则可在类声明中初始化*/

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);       //strlen()返回字符串长度，但不包含末尾的空字符，因此需要将申请的内存加1
    str = new char[len + 1];        //分配存储空间
    std::strcpy(str, s);
    /*字符串并不保存在对象中，字符串单独保存在堆内存中，对象仅保存了指出到哪里去查找字符串的信息*/
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n"; 
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}
/*删除对象可以释放对象本身占用的内存，但并不能自动释放属于对象成员的指针指向的内存
使用析构函数，调用delete语句确保对象过期时，由构造函数使用new分配的内存释放*/

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}