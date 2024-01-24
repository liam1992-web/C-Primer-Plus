// flawed string class definition

#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
    private:
        char * str;	// pointer to string ,使用指针意味着没有为字符串本身分配存储空间，使用构造函数中new来为字符串分配空间,这避免了在类声明中预先定义字符串的长度
        int len;	// length of string
        static int num_strings;		// number of objects  使用静态类成员，类的所有对象共享这一个静态成员
    public:
        StringBad(const char * s);	// constructor
        StringBad();			// default constructor
        ~StringBad();			// destructor

	// friend function
        friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif
