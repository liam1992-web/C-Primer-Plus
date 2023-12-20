//defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::string name;
        ArrayDb scores;
        std::ostream & arr_out(std::ostream & os) const;
    public:
        Student() :name("Null Student"), scores() {}
        explicit Student(const std::string & s) :name(s), scores() {}
        explicit Student(int n) :name("Nully"), scores(n) {}
        Student(const std::string & s, int n) :name(s), scores(n) {}
        Student(const std::string & s, const ArrayDb & a) :name(s), scores(a) {}
        Student(const char * str, const double * pd, int n) :name(str), scores(pd, n) {}
        //对于继承的的对象，构造函数在成员初始化列表中使用类名来调用特定的基类构造函数
        //对于成员对象，构造函数则使用成员名
        //若不使用初始化列表语法，C++要求在构建对象的其它部分之前，先构建继承对象的所有成员对象。因此如果省略初始化列表，C++将使用成员对象所属类的默认构造函数
        ~Student() {}
        double Average() const;
        const std::string & Name() const;
        double & operator[] (int i);
        double operator[] (int i) const;
        friend std::istream & operator>>(std::istream & is, Student & stu);
        friend std::istream & getline(std::istream & is, Student & stu);
        friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif