#ifndef STRNGBAD1_H_
#define STRNGBAD1_H_
#include <iostream>

using std::ostream;
using std::istream;

class String
{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String(const char * s);     //构造函数
        String();                   //默认构造函数
        String(const String &);     //复制构造函数
        ~String();
        int length() const {return len;}

        //成员函数，操作符重载
        String & operator=(const String &);
        String & operator=(const char *);
        char &operator[](int i);
        const char &operator[](int i) const;

        //友元函数，操作符重载
        friend bool operator<(const String &st, const String & st2);
        friend bool operator>(const String &st, const String & st2);
        friend bool operator==(const String &st, const String & st2);
        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, String & st);

        //静态函数
        static int HowMany();
};

#endif