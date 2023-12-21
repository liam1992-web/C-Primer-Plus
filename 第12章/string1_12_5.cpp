#include <cstring>
#include "string1_12_4.h"

using std::cout;
using std::cin;

int String::num_strings = 0;
/*将静态成员初始化为0，不能再类声明中初始化静态成员变量，因为声明描述了如何分配内存，但并不分配内存
通过这种格式来创建对象，从而分配和初始化内存
对于静态类成员，可在类声明之外使用单独的语句来进行初始化，这是因为静态类成员是单独存储的，而不是对象的组成部分
初始化语句指出了类型，并使用了作用域运算符，但没有使用关键字static*/

/*静态数据成员在类声明中声明，在包含类方法的文件中初始化
初始化时使用作用域运算符来指出静态成员所属的类
如果静态成员是整型或枚举型const，则可在类声明中初始化*/

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len = std::strlen(s);       //strlen()返回字符串长度，但不包含末尾的空字符，因此需要将申请的内存加1
    str = new char[len + 1];        //分配存储空间
    std::strcpy(str, s);
    /*字符串并不保存在对象中，字符串单独保存在堆内存中，对象仅保存了指出到哪里去查找字符串的信息*/
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
/*对于使用new[]运算符分配的数组内存，必须使用delete[]运算符进行释放。
这是因为new[]运算符在分配内存时会在内存块的首尾添加一些额外的信息，例如数组的大小等。
因此，只有使用delete[]运算符才能正确地释放这些额外的信息并回收整个内存块。
而使用new运算符分配的单个对象的内存，可以使用delete运算符进行释放。
但是需要注意的是，如果使用delete运算符来释放使用new[]运算符分配的数组内存，或者反过来使用delete[]运算符来释放单个对象的内存，都会导致未定义的行为。
这是因为这两种运算符的实现方式不同，可能会导致内存泄漏或程序崩溃等问题。*/

String::String(const String & st)
{
    num_strings;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}
/*删除对象可以释放对象本身占用的内存，但并不能自动释放属于对象成员的指针指向的内存
使用析构函数，调用delete语句确保对象过期时，由构造函数使用new分配的内存释放*/

//分配一个String给另一个String
String & String::operator=(const String & st)
{
    if(this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

//分配C string给到String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

//String的读写访问
char & String::operator[](int i)
{
    return str[i];
}

//const String的只读字符访问
const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);       //假定输入的字符数不多于String::CINLIM
    if(is)              //如果由于某种原因（如到达文件尾或get(char*,int)读取的是一个空行）导致输入失败，istream对象的值将设为false
        st = temp;      //使用构造函数String(const char * s);
                        //再使用赋值符号操作符重载 String & String::operator=(const char * s)
    while(is && is.get() != '\n')          //丢弃多余字符
        continue;

    return is;
}
