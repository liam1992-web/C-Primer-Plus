// using pointers to objects

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1_12_4.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;

    String name;

    cout << "Hi, waht's your name?\n>>";
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short sayings <empyt line to quit>:\n";

    String sayings[ArSize];
    char temp[MaxLen];
    int i;

    for(i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0')
            break;
        else 
            sayings[i] = temp;
    }

    int total = i;
    if(total > 0)
    {
        cout << "Here are your sayings:\n";
        for(i = 0; i < total; i++)
            cout << sayings[i] << endl;
        
	// use pointers to keep track of shortest, first strings
        String * shortest = &sayings[0];	// initialize to first object
        String * first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < shortest->length())	// 指针调用类方法->
                shortest = &sayings[i];
            if(sayings[i] < *first) 	// 使用*解引用 从指针获得对象
                first = &sayings[i];
        } 
        
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total;
	// use new to create, intialize new String object
        String * favourite = new String(sayings[choice]);	
	// 调用复制构造函数，用sayings[choice]来初始化未命名的新对象
        cout << "My favourite saying:\n" << *favourite << endl;
        delete favourite;       //当对象是用new创建的，仅当显式使用delete删除对象时，其析构函数才会被调用
    }
    else 
        cout << "No much to say,eh?\n";
        cout << "Bye.\n";

    return 0;
}

