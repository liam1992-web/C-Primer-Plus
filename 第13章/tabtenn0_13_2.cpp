#include "tabtenn0_13_1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht) {}
/*
使用初始化列表语法，将直接使用string的复制构造函数将firstname初始化为fn
下面的常规定义，将首先为firstname调用string的默认构造函数，再调用string的赋值运算符将firstname初始化为fn
相比之下使用初始化列表语法可减少一个步骤
TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) 
{
    firstname = fn;
    lastname = ln;
    hasTable = ht;
}
*/
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " <<firstname;
}

