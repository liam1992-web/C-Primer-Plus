#include "studenti_14_4.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public methods
double Student::Average() const
{
    if(ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else 
        return 0;
}
//使用包含时使用对象名来调用方法，而是用私有继承时使用类名和作用域解析运算符来调用方法

const string & Student::Name() const
{
    return (const string &) *this;
}
//上述方法返回一个引用，该引用指向调用该方法的Student对象中的继承而来的string对象

double & Student::operator[](int i)
{
    return ArrayDb::operator[](i);  //use ArrayDb::operator[]()
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}


//private method
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if(lim > 0)
    {
        for(i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 5)
                os << endl;
        }
        if(i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

//friends
//use string version of operator>>()
istream & operator>>(istream & is, Student & stu)
{
    is >> (string &)stu;    
    return is;
}

//use string friend getline(ostream &, const string &)
istream & getline(istream & is, Student & stu)
{
    getline(is, (string &)stu);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (const string &) stu << ":\n";
    stu.arr_out(os);    //use private method for scores
    return os;
}
//用类名显式地限定函数名不适合于友元函数，因为友元不属于类。可通过显式地转换为基类来调用正确地函数
//在私有继承中，在不进行显式类型转换的情况下，不能将指向派生类的引用或指针赋给基类引用或指针
