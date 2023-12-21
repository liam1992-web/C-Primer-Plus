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
        
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if(sayings[i] < *first) 
                first = &sayings[i];
        } 
        
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total;
        String * favourite = new String(sayings[choice]);
        cout << "My favourite saying:\n" << *favourite << endl;
        delete favourite;       //当对象是用new创建的，仅当显式使用delete删除对象时，其析构函数才会被调用
    }
    else 
        cout << "No much to say,eh?\n";
        cout << "Bye.\n";

    return 0;
}

